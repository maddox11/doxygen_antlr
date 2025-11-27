#include <string>
#include <chrono>
#include "qcstring.h"
#include "containers.h"
#include "verilogjjparser.h"
#include "message.h"
#include "config.h"
#include "doxygen.h"
#include "util.h"
#include "language.h"
#include "commentscan.h"
#include "index.h"
#include "definition.h"
#include "searchindex.h"
#include "outputlist.h"
#include "arguments.h"
#include "types.h"
#include "growbuf.h"
#include "markdown.h"
#include "Expression.h"
#include <regex>
#include "vhdldocgen.h"
#include "qcstring.h"
#include "moduledef.h"
#include "PrepParser.h"
#include "verilogcode.h"
#include <cassert>
#include <mutex>
#include "antlr4-runtime.h"

using namespace prepc;

struct VerilogDocInfo
{

  VerilogDocInfo() {}
  VerilogDocInfo(QCString &q, int i, bool b) : doc(q), iDocLine(i), brief(b) {}

  ~VerilogDocInfo()
  {
  }

  void addDocInfo(QCString q, int l, bool b)
  {
    auto inf = std::make_shared<VerilogDocInfo>(q, l, b);
    docList.emplace_back(inf);
  }

  void clear() { docList.clear(); }

  QCString doc;
  int iDocLine = 1;
  bool brief;
  bool pending = false;
  std::vector<std::shared_ptr<VerilogDocInfo>> docList;
};

struct VerilogOutlineParser::Private
{
  void parseVerilogfile(const char *inputBuffer, bool inLine);
  VerilogOutlineParser *thisParser = 0;
  SysVerilogParser *verilogParser = 0;
  VerilogCodeParser *vCode = 0;
  CommentScanner commentScanner;
  QCString yyFileName;
  int yyLineNr = 1;
  int iDocLine = -1;
  QCString inputString;
  Entry *previous = 0;
  Entry *oldEntry = 0;
  EntryList lineEntry;
  VerilogDocInfo str_doc;
  int iCodeLen;
  SharedState shared;
  int code = 0;
};

QCString filterVerilogComment(const QCString &s);

void printEntries(std::shared_ptr<Entry> ce);

QCString stripStar(std::string q);

void VerilogOutlineParser::parsePrototype(const QCString &text)
{
}

void copyDoc(std::shared_ptr<Entry> &dst, std::shared_ptr<Entry> &src)
{
  if (!src->brief.isEmpty())
  {
    dst->brief = src->brief;
    dst->briefLine = src->briefLine;
    dst->briefFile = src->briefFile;
  }
  else
  {
    dst->doc = src->doc;
    dst->docLine = src->docLine;
    dst->docFile = src->docFile;
  }
}

void VerilogOutlineParser::Private::parseVerilogfile(const char *inputBuffer, bool inLine)
{
  searchDirectories();
  // std::cout<<"parse file:"<<yyFileName<<"\n";
  std::map<std::string, prepc::DefMacro *> mdf;
  std::string s = inputBuffer;
  std::string ffh = stripPath(yyFileName).data();
  PrepParser pre(ffh);
  std::string cs = pre.parseData(s);
  pre._clearAll();

  antlr4::ANTLRInputStream input(cs.c_str());
  SysVerilogLexer lexer(&input);

  antlr4::CommonTokenStream tokens(&lexer);
  tokens.fill();

#if 0
  for (auto token : tokens.getTokens())
  {
    if (token->getType() != SysVerilogLexer::WS)
      std::cout << " [" << token->getType() << token->getText() << " || " << token->getLine() << " || " << token->getTokenIndex() << "]\n";
  }
#endif
  SysVerilogParser parser(&tokens);
  antlr4::tree::ParseTree *tree = parser.source_code();

  Expression *e = new Expression(&tokens, &parser, yyFileName);
  e->setOutlineParser(thisParser);
  e->setSharedState(&shared);

  // std::cout << "=========  walking source tree:  =============\n";

  antlr4::tree::ParseTreeWalker *twalk = new antlr4::tree::ParseTreeWalker();
  try
  {
    std::string pt = antlr4::tree::Trees::toStringTree(tree, parser.getRuleNames(), TRUE);
    twalk->walk(e, tree);
  }
  catch (exception &ex)
  {
    std::cout << ex.what();
    // exit(0);
  }
  delete twalk;
  delete e;
}

VerilogOutlineParser::VerilogOutlineParser() : p(std::make_unique<Private>())
{
}

VerilogOutlineParser::~VerilogOutlineParser()
{
}

void VerilogOutlineParser::parseInput(const QCString &fileName, const char *fileBuf,
                                      const std::shared_ptr<Entry> &root, ClangTUParser *)
{
  // std::cout << "parsing  verilog file..." << fileName.data() << std::endl;
  SharedState *s = &p->shared;
  p->thisParser = this;
  p->inputString = fileBuf;
  p->yyFileName = fileName;
  s->fileName = fileName.data();
  p->yyLineNr = 1;
  s->current_root = root;
  s->lastCompound = 0;
  s->lastEntity = 0;
  s->current = std::make_shared<Entry>();
  initEntry(s->current.get());
  p->parseVerilogfile(fileBuf, false);

  insertPendingComments();
  Doxygen::macroDefinitions.emplace(std::make_pair(s->fileName.c_str(), std::move(s->defList)));

  s->defList.clear();
  s->current.reset();
  p->yyFileName.resize(0);
}

void VerilogOutlineParser::newEntry()
{
  SharedState *s = &p->shared;
  s->tempEntry = s->current;
  // std::cout << "add to current_root:[  " << s->current->name << "]  1brief:[ " << s->current->brief << " ] 2line:[ " << s->current->briefLine << " ] [ " << s->current->startLine << " ]\n";

  if (s->current->section.isClass())
  {

    if (s->shvec.empty())
    {
      std::cerr << "class vec is empty!!";
      exit(0);
    }

    if (s->shvec.size() == 1)
    {
      s->current_root->moveToSubEntryAndRefresh(s->current);
    }
    else
    {
      int l = s->shvec.size();
      std::shared_ptr<Entry> temp = s->shvec.at(l - 2);
      // std::cout << temp->name << " adding class : -> " << s->current->name << "\n";
      temp->moveToSubEntryAndRefresh(s->current);
    }

    return;

  } // ins class

  if (s->lastEntity == NULL)
  {
    s->current_root->moveToSubEntryAndRefresh(s->current);
  }
  else
  {
    // std::cout << "adding last entity: " << s->lastEntity->name << " -> " << s->current->name << "\n";
    s->lastEntity->moveToSubEntryAndRefresh(s->current);
  }

  initEntry(s->current.get());
}

void VerilogOutlineParser::initEntry(Entry *e)
{
  e->fileName = p->yyFileName;
  e->lang = SrcLangExt_Cpp;
  p->commentScanner.initGroupInfo(e);
}

void VerilogOutlineParser::addClass(const char *name, int startLine, int bodyLine, int endBodyLine, EntryType section,
                                    TypeSpecifier ts, Protection prot, const char *type)
{
  SharedState *s = &p->shared;
  s->current->bodyLine = bodyLine;
  addClass(name, startLine, endBodyLine, section, ts, prot, type);
}

// adding module/class/interface/program/checker
void VerilogOutlineParser::addClass(const char *name, int startLine, int endLine, EntryType section,
                                    TypeSpecifier ts, Protection prot, const char *type)
{
  SharedState *s = &p->shared;
  std::string xx = type;
  s->current->name = name;
  s->insertClassEntry(s->current);
  s->current->startLine = startLine;

  s->current->endBodyLine = endLine;
  s->current->qualifiers.push_back(xx);
  s->current->bodyLine = startLine;
  s->current->section = section;
  // name of inner classes AAA::BBB etc.
  s->current->name = s->getClassName();
  s->current->fileName = p->yyFileName;
  s->current->spec = ts;
  s->current->protection = prot;
  s->current->type = type;
  newEntry();
}

// adding function
void VerilogOutlineParser::addVerilogType(const char *n, int startLine, int endLine, EntryType section, TypeSpecifier ts, bool isStatic, Protection prot, const char *qual)
{
  SharedState *s = &p->shared;
  s->current->lang = SrcLangExt_Cpp;
  s->current->startLine = startLine;
  s->current->bodyLine = startLine;
  s->current->endBodyLine = endLine;
  s->current->isStatic = isStatic;
  s->current->section = section;
  s->current->protection = Protection::Public;

  s->current->name = n;
  // s->current->args += "( int a, double c) ";
  // s->current->argList.setConstSpecifier(TRUE);
  // s->current->argList.setTrailingReturnType(QCString("double"));
  // s->current->args += " int a ";
  s->current->type = qual;
  //s->current->type.append(" automatic");
  s->current->fileName = p->yyFileName;
  s->current->spec = ts;

  if (qual)
  {
    std::string sq = qual;
    s->current->qualifiers.push_back(sq);
  }

  newEntry();
}

void VerilogOutlineParser::addMember(const char *n,
                                     const char *arg,
                                     const char *type,
                                     int startLine,
                                     int endLine,
                                     EntryType section,
                                     TypeSpecifier spec,
                                     const char *exp,
                                     Protection prot,
                                     const char *qual)
{
  SharedState *s = &p->shared;
  s->current->name = n;
  s->current->lang = SrcLangExt_Cpp;
  s->current->startLine = startLine;
  s->current->bodyLine = startLine;
  s->current->endBodyLine = endLine;
  s->current->section = section;
  s->current->spec = spec;
  s->current->fileName = p->yyFileName;
  s->current->type = type;
  s->current->args = arg;
  s->current->exception = exp;
  // s->current->bitfields = exp;

  if (qual)
  {
    std::string sq = qual;
    s->current->qualifiers.push_back(sq);
  }

  s->current->protection = Protection::Public;
  newEntry();
}

void VerilogOutlineParser::handleCommentBlock(const QCString &doc1, int line, bool brief)
{
  int position = 0;
  bool needs = FALSE;

  SharedState *s = &p->shared;
  QCString doc = doc1;

  if (doc.isEmpty())
    return;

  Protection protection = Protection::Public;
  doc = filterVerilogComment(doc1);
  doc = stripStar(doc.data());
  if (checkMultiComment(doc, line))
  {
    return;
  }

  std::shared_ptr<Entry> ent = std::make_shared<Entry>();

  p->oldEntry = s->current.get();

  if (brief)
  {
    ent->briefLine = line;
  }
  else
  {
    ent->docLine = line;
  }

  Markdown markdown(p->yyFileName, line);
  QCString processedDoc = Config_getBool(MARKDOWN_SUPPORT) ? markdown.process(doc, line) : doc;
  while (p->commentScanner.parseCommentBlock(
      p->thisParser,
      ent.get(),
      processedDoc,  // text
      p->yyFileName, // file
      line,          // line of block start
      true,
      0,
      FALSE,
      protection,
      position,
      needs,
      Config_getBool(MARKDOWN_SUPPORT)))
  {
    if (needs)
      newEntry();
  }

  if (needs)
  {
    s->current_root->moveToSubEntryAndRefresh(ent);
    // copyDoc(s->current,ent);
    // newEntry();
    return;
  }

  std::shared_ptr<Entry> see = getLastEntry();

  Entry *e = see.get();
  if (e->type == "@")
  {
    p->str_doc.addDocInfo(doc1, line, brief);
    return;
  }

  if (!ent->brief.isEmpty())
  {
    see->brief = ent->brief;
    see->briefLine = ent->briefLine;
    see->briefFile = ent->briefFile;
  }
  else
  {
    see->doc = ent->doc;
    see->docLine = ent->docLine;
    see->docFile = ent->docFile;
  }
  // s->current.reset();
}

QCString stripStar(std::string q)
{
  if (q.find("*") == std::string::npos)
    return q.data();

  prepc::replace(q, "[\\s][*][\\s]", " ");
  return q.data();
}

void VerilogOutlineParser::addImport(QCString &fileName, int l, QCString &impName)
{
  const QCString val;
  ModuleManager::instance().addImport(fileName, l, impName, false, val);
}

const std::shared_ptr<Entry> VerilogOutlineParser::getLastEntity()
{
  // assert(&p->shared!=nullptr_t);
  SharedState *s = &p->shared;
  assert(s);
  assert(s->lastEntity);
  return s->lastEntity;
}

void VerilogOutlineParser::addMacro(const prepc::DefMacro *df, const std::string &co, size_t eline)
{
  SharedState *s = &p->shared;
  FileDef *fdd = getFileDef();

  Define def;
  def.name = df->mName;
  def.definition = QCString(df->mDefinition);
  def.lineNr = df->beginLine;
  def.columnNr = df->column;
  def.fileName = s->fileName;
  def.fileDef = fdd;

  int i = df->li.size() - 1;
  int j = 0;
  std::string arg = "(";
  for (std::string n : df->li)
  {
    arg.append(n);
    if (j < i)
      arg.append(",");
    j++;
  }
  arg.append(")");

  s->defList.push_back(def);

  // std::shared_ptr<Entry> ee = std::make_shared<Entry>();

  s->current->name = df->mName;
  s->current->args = arg;
  s->current->startLine = df->beginLine;
  s->current->bodyLine = df->beginLine;
  s->current->endBodyLine = df->beginLine + countLines(def.definition.data()) + 1;
  s->current->startColumn = df->column;
  s->current->mtype = MethodTypes::Method;
  s->current->section = EntryType::makeDefine();

  if (!co.empty())
  {
    s->current->brief = co.data();
    s->current->briefLine = df->beginLine;
  }
  // initEntry(ee.get());
  // s->current_root->moveToSubEntryAndRefresh(ee);
  newEntry();
}

// returns the vhdl parsed types at line xxx
void printEntries(std::shared_ptr<Entry> ce)
{
  for (const auto &rt : ce->children())
  {
    std::cout << "entry name: " << rt->name.data() << " " << rt->startLine << " " << rt->bodyLine << "\n";
    if (!rt->brief.isEmpty() || !rt->doc.isEmpty())
      std::cout << rt->name.data() << ": doc:" << rt->doc.data() << "[ " << rt->brief << "] at line: " << rt->briefLine << "\n";

    printEntries(rt);
  }
}

FileDef *VerilogOutlineParser::getFileDef()
{

  SharedState *s = &p->shared;
  bool am = true;
  s->fdd = findFileDef(Doxygen::inputNameLinkedMap, QCString(s->fileName), am);
  return s->fdd;
}

void VerilogOutlineParser::getEntryAtLine(std::shared_ptr<Entry> ce, int line, bool equ)
{
  for (const auto &rt : ce->children())
  {
    if (rt->bodyLine >= line && !equ)
    {
      p->lineEntry.push_back(rt);
      return;
    }

    if (rt->bodyLine == line && equ)
    {
      p->lineEntry.push_back(rt);
      return;
    }
    getEntryAtLine(rt, line, equ);
  }
}

// docs from typedef enum\struct
void VerilogOutlineParser::insertPendingComments()
{

  VerilogDocInfo *pinf = &p->str_doc;
  SharedState *s = &p->shared;
  for (std::shared_ptr<VerilogDocInfo> pi : pinf->docList)
  {
    // bool succ = false;
    getEntryAtLine(s->current_root, pi->iDocLine, false);
    if (!p->lineEntry.empty())
    {
      Entry *e = p->lineEntry.front().get();
      // std::cout << "line entry " << e->name << "\n";
      pi->doc = filterVerilogComment(pi->doc);
      if (pi->brief)
      {
        e->brief = pi->doc;
        e->briefLine = pi->iDocLine;
      }
      p->lineEntry.clear();
    }
    // insertCommentAtLine(s->current_root, pi->iDocLine, pi->doc, &succ);
  }
}

bool VerilogOutlineParser::checkMultiComment(QCString &qcs, int line)
{
  SharedState *s = &p->shared;
  getEntryAtLine(s->current_root, line, true);

  if (p->lineEntry.empty())
    return false;

  while (!p->lineEntry.empty())
  {
    std::shared_ptr<Entry> e = p->lineEntry.back();
    e->briefLine = line;
    e->brief += qcs;

    p->lineEntry.pop_back();
  }
  return true;
}

void VerilogOutlineParser::addComment(std::string &str, size_t line, bool brief)
{
  QCString doc(str.data());
  handleCommentBlock(doc, line, brief);
}

std::shared_ptr<Entry> VerilogOutlineParser::getLastEntry()
{
  std::vector<std::shared_ptr<Entry>> zz;
  SharedState *s = &p->shared;

  if (s->current_root == NULL)
    return NULL;

  if (s->lastEntity != nullptr)
  {
    zz = s->lastEntity->children();
    if (zz.empty())
      return s->lastEntity;
  }
  else
    zz = s->current_root->children();

  if (!zz.empty())
  {
    std::string sq = zz.back().get()->name.data();
    return zz.back();
    //  return m_sharedState->current_root;
  }
  else
    std::cout << "class stack is empty";

  return nullptr;
}

QCString filterVerilogComment(const QCString &s)
{
  if (s.length() < 4)
    return s;

  GrowBuf growBuf;
  const char *p = s.data() + 3; // skip /*!
  char c = '\0';
  while (*p == ' ' || *p == '\t')
    p++;
  while ((c = *p++))
  {
    growBuf.addChar(c);
    if (c == '\n')
    {
      // special handling of space followed by * at beginning of line
      while (*p == ' ' || *p == '\t')
        p++;
      while (*p == '*')
        p++;
      // special attention in case character at end is /
      if (*p == '/')
        p++;
    }
  }
  // special attention in case */ at end of last line
  size_t len = growBuf.getPos();
  if (len >= 2 && growBuf.at(len - 1) == '/' && growBuf.at(len - 2) == '*')
  {
    len -= 2;
    while (len > 0 && growBuf.at(len - 1) == '*')
      len--;
    while (len > 0 && ((c = growBuf.at(len - 1)) == ' ' || c == '\t'))
      len--;
    growBuf.setPos(len);
  }
  growBuf.addChar(0);
  return growBuf.get();
}