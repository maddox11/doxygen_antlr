

#include "qcstring.h"
#include "containers.h"

// #include "message.h"

#include "searchindex.h"
#include "CharStream.h"
#include "tooltip.h"
#include "linkedmap.h"
#include "classlist.h"
#include "sysverilog.h"
#include "verilogjjparser.h"
#include "doxygen.h"
#include "util.h"
#include "config.h"
#include "verilogcode.h"
#include "PrepParser.h"
#include "portable.h"
#include "membername.h"
#include "namespacedef.h"
#include "pagedef.h"
using KeyDict = std::map<std::string, std::string>;

static KeyDict verilogKeyDict;
static KeyDict verilogGlobalDict;
static KeyDict verilogDefineDict;
static KeyDict dirList;

static const std::string g_verilogkeyword("vhdlkeyword");
static const std::string g_verilogDefinition("preprocessor");
static const MemberDef *findMemberDef(ClassDef *cd, const QCString &key);
const MemberDef *findMemberDef(ClassDef *cd, const QCString &key, MemberListType type);

static const std::set<std::string> keywordSet = {
    "accept_on", "nettype", "interconnect", "export", "ref", "alias", "extends",
    "restrict", "always_comb", "extern", "return", "always_ff", "final", "s_always", "always_latch", "first_match", "s_eventually", "assert",
    "foreach", "s_nexttime", "assume", "forkjoin", "s_until", "before", "global", "s_until_with", "bind", "iff", "sequence",
    "bins", "ignore_bins", "shortint", "binsof", "illegal_bins", "shortreal", "bit", "implies", "implements", "solve", "break",
    "import", "static", "byte", "inside", "string", "chandle", "int", "strong", "checker", "interface", "struct",
    "class", "intersect", "super", "clocking", "join_any", "sync_accept_on", "const", "join_none", "sync_reject_on", "constraint", "let",
    "tagged", "context", "local", "this", "continue", "logic", "throughout", "cover", "longint", "timeprecision", "covergroup",
    "matches", "timeunit", "coverpoint", "modport", "type", "cross", "new", "typedef", "dist", "nexttime", "do",
    "null", "unique", "endchecker", "package", "unique0", "endclass", "packed", "until", "endclocking", "priority",
    "until_with", "endgroup", "program", "untypted", "endinterface", "property", "var", "endpackage", "protected", "virtual", "endprogram", "pure", "void", "endproperty", "rand",
    "wait_order", "endsequence", "randc", "weak", "enum", "randcase", "wildcard", "eventually",
    "randsequence", "with", "expect", "reject_on", "within", "output", "input", "module", "endmodule", "input", "output", "inout", "reg", "parameter", "always",
    "case", "endcase", "if", "begin", "posedge", "negedge", "or", "wire", "tri", "tri0", "instance", "use", "design", "config", "endconfig", "include", "library", "liblist",
    "function", "endfunction", "assign", "end", "for", "else", "initial", "integer", "real", "task",
    "and", "buf", "bufif0", "bufif1", "casex", "casez", "cmos", "deassign", "default", "defparam", "disable",
    "edge", "endattribute", "endprimitive", "endspecify", "endtable", "endtask", "event",
    "force", "forever", "fork", "force", "forever", "ifnone", "join", "large", "macromodule", "medium", "Input", "Output", "Inout",
    "nand", "nmos", "nor", "not", "notif0", "notif1", "localparam", "cell",
    "pmos", "primitive", "pull0", "pull1", "pullup", "pulldown", "automatic", "union",
    "rcmos", "real", "time", "realtime", "release", "repeat", "rnmos", "rpmos", "rtran", "rtranif0", "rtranif1",
    "scalared", "signed", "small", "soft", "specify", "specparam", "strength", "strong0", "strong1", "supply0", "supply1",
    "table", "tran", "tranif0", "tranif1", "tri1", "triand", "trior", "trireg", "pulsestyle_ondetect", "showcancelled", "noshowcancelled", "pulsestyle_onevent",
    "generate", "endgenerate", "genvar", "unsigned", "xor", "xnor", "wait", "wand", "weak0", "weak1", "while", "wire", "wor", "vectored"

};
//------------------------------------------------------------------------------------------------------------------------------
// some but not all system words
static const std::set<std::string> systemSet = {"$async$and$array", "$async$and$plane", "$async$nand$array", "$async$nand$plane", "$async$or$array", "$async$or$plane",
                                                "$async$nor$array", "$async$nor$plane", "$sync$and$array", "$sync$and$plane", "$sync$nand$array", "$sync$nand$plane",
                                                "$sync$or$array", "$sync$or$plane", "$sync$nor$array", "$sync$nor$plane", "$display", "$strobe",
                                                "$displayb", "$strobeb", "$displayh", "$strobeh", "$displayo", "$strobeo", "$monitor", "$write", "$monitorb", "$writeb",
                                                "$monitorh", "$writeh", "$monitoro", "$writeo", "$monitoroff", "$monitoron", "$fclose", "$fopen", "$fdisplay", "$fstrobe",
                                                "$fdisplayb", "$fstrobeb", "$fdisplayh", "$fstrobeh", "$fdisplayo", "$fstrobeo", "$fgetc", "$ungetc", "$fflush", "$ferror",
                                                "$fgets", "$rewind", "$fmonitor", "$fwrite", "$fmonitorb", "$fwriteb", "$fmonitorh", "$fwriteh", "$clog2",
                                                "$fmonitoro", "$fwriteo", "$readmemb", "$readmemh", "$swrite", "$swriteb", "$swriteo", "$swriteh",
                                                "$sformat", "$sdf_annotate", "$fscanf", "$sscanf", "$fread", "$ftell", "$fseek", "$printtimescale",
                                                "$timeformat", "$finish", "$stop", "$realtime", "$stime", "$time", "$bitstoreal", "$realtobits",
                                                "$itor", "$rtoi", "$signed", "$unsigned", "$test$plusargs", "$value$plusargs", "$q_initialize", "$q_add",
                                                "$q_remove", "$q_full", "$q_exam", "$period", "$hold", "$setup", "$width", "$skew", "$reovery", "$nochange", "$timeskew", "$setuphold", "$fullskew"};
//------------------------------------------------------------------------------------------------------------------------------

static const std::set<std::string> defSet = {
    "`accelerate", "`autoexpand_vectornets", "`celldefine", "`default_decay_time,"
                                                            "`default_nettype",
    "`define",
    "`default_trireg_strength", "`delay_mode_distributed", "`delay_mode_zero", "`disable_portfaults", "`enable_portfaults", "`endcelldefine", "`endprotect", "`expand_vectornets", "`inline", "`line",
    "`noaccelerate", "`noexpand_vectornets", "`noremove_gatenames", "`noremove_netnames", "`nosuppress_faults", "`nounconnected_drive", "`portcoerce", "`pragma",
    "`protect", "`protected", "`remove_gatenames", "`remove_netnames", "`resetall", "`suppress_faults", "`timescale"};
//------------------------------------------------------------------------------------------------------------------------------

std::map<std::string, const MemberDef *> g_varMap;
std::vector<ClassDef *> g_classList;
std::map<ClassDef *, std::vector<ClassDef *>> g_packages;

static bool _init = TRUE;
const MemberDef *findAllGlobalMemberDef(QCString &key);
const MemberDef *findGlobalMemberDef(QCString &key, QCString &fi);

struct VerilogCodeParser::Private
{
  OutputCodeList *g_code;
  TooltipManager tooltipManager;
  const char *g_inputString; //!< the code fragment as text
  int g_inputPosition;       //!< read offset during parsing
  int g_inputLines;          //!< number of line in the code fragment
  int g_yyLineNr;            //!< current line number
  bool g_needsTermination;
  Definition *g_searchCtx;
  ClassDef *g_currClass;
  const ClassDef *g_innerClass;
  QCString g_exampleName;
  QCString g_exampleFile;
  QCString g_classScope;
  QCString g_CurrScope;
  const FileDef *g_sourceFileDef;
  const Definition *g_currentDefinition;
  const MemberDef *g_currentMemberDef;
  bool g_includeCodeFragment;
  const char *g_currentFontClass;
  bool g_lexInit = FALSE;
  int g_braceCount = 0;
  bool insideCodeLine = false;
  std::list<ClassDef *> scl;
  std::vector<const Definition *> foldStack;
};

static void dumpSymbol(TextStream &t, Definition *d)
{
  QCString anchor;
  if (d->definitionType() == Definition::TypeMember)
  {
    MemberDef *md = toMemberDef(d);
    anchor = ":" + md->anchor();
  }
  QCString scope;
  QCString fn = d->getOutputFileBase();

  scope = fn;

  t << "('"
    // << fn + anchor << "','"
    // << scope << "','"
    << d->name() << "','"
    // << d->getDefFileName() << "','"
    << d->getDefLine() << "','"
    << "');\n";
}

static void dumpClassMembers(ClassDef *baseC)
{
  std::ofstream f = Portable::openOutputStream("symbols.sql", true);
  if (!f.is_open())
    return;

  if (baseC == nullptr)
    return;

  TextStream t(&f);
  t << "\n---------- add members for class:" << baseC->name() << "\n";

  for (const auto &ml : baseC->getMemberLists())
  {
    if (ml == 0)
      break;
    for (const auto &md : *ml)
    {
      t << md->name() << " [ " << md->isTypedef() << " ] [" << md->isEnumerate() << " ][ " << md->isEnumValue() << " ] " << md->typeString() << " | " << md->memberType() << " | " << md->getDefLine() << "\n";
    }
  }
}

static void dumpMember()
{
  std::ofstream f = Portable::openOutputStream("symbols.sql", true);
  if (!f.is_open())
    return;

  TextStream t(&f);
  t << "\n---------- added members -------\n";

  for (const auto &mn : *Doxygen::memberNameLinkedMap)
  {
    for (const auto &md : *mn)
    {
      t << md->name() << " " << md->getStartBodyLine() << "{" << md->typeString() << "}\n";
    }
  }

  t << "\n---------- added funcion members -------\n";

  for (const auto &mn : *Doxygen::functionNameLinkedMap)
  {
    // for each member definition
    for (const auto &md : *mn)
    {
      t << md->name() << " " << md->getStartBodyLine() << " " << md->typeString() << " | " << md->memberType() << " | " << "\n";
    }
  }
}

static void dumpSymbolMap()
{
  std::ofstream f = Portable::openOutputStream("symbols.sql");
  if (f.is_open())
  {
    TextStream t(&f);
    for (const auto &[name, symList] : *Doxygen::symbolMap)
    {
      for (const auto &def : symList)
      {
        dumpSymbol(t, def);
      }
    }
  }
}

/*! counts the number of lines in the input */

int countLines(const char *p1)
{
  char c;
  int count = 0;
  while ((c = *p1))
  {
    p1++;
    if (c == '\n')
      count++;
  }
  return count;
}

std::string getLeftScope(const std::string &s)
{
  size_t i = s.find("::");
  if (i == std::string::npos)
    return s;
  return s.substr(i + 2);
}

bool VerilogCodeParser::writeDefinitionFromClassScope(const QCString &clazzScope, const QCString &w)
{
  ClassDef *cd = Doxygen::classLinkedMap->find(clazzScope);
  if (cd)
  {
    const MemberDef *md = findMemberDef(cd, w);
    if (md)
    {
      writeCodeLink(md, QCString(""));
      return true;
    }
  }

  return false;
}

std::string VerilogCodeParser::getScope(const std::string &cn)
{
  std::string clazz;
  size_t i = p->scl.size();

  if (i == 0)
    return cn;

  for (const auto &cl : p->scl)
  {
    clazz.append(cl->name().data());
    clazz.append("::");
  }
  clazz.append(cn);
  return clazz;
}

bool VerilogCodeParser::removeClass()
{
  if (p->scl.empty())
  {
    p->g_currClass = 0;
    return false;
  }
  else
  {
    p->scl.pop_back();
    p->g_currClass = p->scl.back();
  }
  return true;
}

bool VerilogCodeParser::addClass(const std::string &cl)
{
  std::string vv = getScope(cl);
  ClassDef *cd = Doxygen::classLinkedMap->find(vv);

  if (cd)
  {
    p->scl.emplace_back(cd);
    p->g_currClass = cd;

    return true;
  }
  return false;
}

void VerilogCodeParser::addBaseClass(const std::string &baseClass)
{
  std::vector<ClassDef *> vec;
  std::string clazz = getLeftScope(baseClass);
  ClassDef *baseC = Doxygen::classLinkedMap->find(clazz);

  // std::cout << "add base class:" << baseClass << "\n";
  if (!p->g_currClass)
    return;
  if (baseC == 0)
    return;

  auto cList = g_packages.find(p->g_currClass);
  if (cList == g_packages.end())
  {
    vec.emplace_back(baseC);
    g_packages.insert({p->g_currClass, vec});
  }
  else
    cList->second.emplace_back(baseC);
}

bool VerilogCodeParser::findSystemKey(const std::string &s)
{
  std::set<std::string>::iterator it = systemSet.find(s);
  return it != systemSet.end();
}

bool VerilogCodeParser::findKey(const std::string &s)
{
  std::set<std::string>::iterator it = keywordSet.find(s);
  return it != keywordSet.end();
}

bool VerilogCodeParser::findDefSet(const std::string &s)
{
  std::set<std::string>::iterator it = defSet.find(s);
  return it != defSet.end();
}

VerilogCodeParser::~VerilogCodeParser()
{
}

VerilogCodeParser::VerilogCodeParser() : p(std::make_unique<Private>())
{
}

QCString &VerilogCodeParser::getFileName()
{
  return p->g_exampleFile;
}

void VerilogCodeParser::parseCode(OutputCodeList &od,
                                  const QCString &className,
                                  const QCString &s,
                                  SrcLangExt,
                                  bool exBlock,
                                  const QCString &exName,
                                  const FileDef *fd,
                                  int startLine,
                                  int endLine,
                                  bool inlineFragment,
                                  const MemberDef *memberDef,
                                  bool,
                                  const Definition *searchCtx,
                                  bool /* collectXRefs */)
{
  if (s.isEmpty())
    return;

  bool source = Config_getBool(SOURCE_BROWSER);

  if (_init && source)
  {
    //   std::cerr << "\ngenerating source file.............................!!!!" << className.data() << std::endl;
    // missing preprocessor
    _init = FALSE;
    assert(Doxygen::hiddenClassLinkedMap->size() == 0);
    assert(Doxygen::namespaceLinkedMap->size() == 0);
    assert(Doxygen::pageLinkedMap->size() == 0);
    assert(Doxygen::conceptLinkedMap->size() == 0);

    prepc::PrepParser::clearConcMap();
    dumpSymbolMap();
    dumpMember();
  }

  prepc::PrepParser pre(true);

  std::string val = s.data();
  // pre.cmp.ml.clear();

  std::string str = pre.parseData(val);

  // pre.bit.out();

  p->g_code = &od;
  p->g_yyLineNr = 1;
  p->g_sourceFileDef = fd;
  p->g_currClass = 0;
  if (fd)
  {
    p->g_exampleFile = fd->getDefFileName();
    if (!inlineFragment)
      std::cerr << "\ngenerating source file.............................!!!!" << p->g_exampleFile.data() << std::endl;
  }

  p->g_currentMemberDef = memberDef;
  p->g_currentDefinition = searchCtx;
  if (startLine != -1)
    p->g_yyLineNr = startLine;
  else
    p->g_yyLineNr = 1;

  p->g_inputLines = countLines(str.data()) + 1 + p->g_yyLineNr;
  this->startCodeLine();

  if (memberDef != 0)
  {
    writeMacroID(p->g_yyLineNr, str.data(), this);
  }
  else
    writeSysFile(p->g_yyLineNr, str.data(), this);

  if (Config_getBool(HTML_CODE_FOLDING))
  {
    while (!p->foldStack.empty())
    {
      p->g_code->endFold();
      p->foldStack.pop_back();
    }
  }
}

void VerilogCodeParser::writeVerilogFont(const char *s, const char *text)
{
  if (s == NULL)
    return;

  p->g_code->startFontClass(s);
  p->g_code->codify(text);
  p->g_code->endFontClass();
}

void VerilogCodeParser::writeVerilogKeyWord(const char *c)
{
  writeVerilogFont(g_verilogkeyword.c_str(), c);
}

void VerilogCodeParser::startCodeLine()
{
  bool bClass = false;

  if (p->g_sourceFileDef)
  {
    const Definition *d = p->g_sourceFileDef->getSourceDefinition(p->g_yyLineNr);
    // if (!d)
    //  d = findMacroMember(p->g_yyLineNr);
    //  printf("startCodeLine %d d=%s\n", yyextra->yyLineNr,qPrint(d ? d->name()) : "<null>");
    if (d)
    {
      bClass = d->definitionType() == Definition::TypeClass;
      //  printf("startCodeLine %d d=%s\n", p->g_yyLineNr, d->name().data());
      // if (bClass)
      //  printf("found class definition %s [%d %d %d]\n", d->name().data(), d->getDefLine(), d->getEndBodyLine(), d->inbodyLine());
    }

    if (!p->g_includeCodeFragment && d)
    {
      p->g_currentDefinition = d;
      p->g_currentMemberDef = p->g_sourceFileDef->getSourceMember(p->g_yyLineNr);

      QCString lineAnchor;
      lineAnchor.sprintf("l%05d", p->g_yyLineNr);
      // std::cout<<tree->toString();printf("l%05d", p->g_yyLineNr);
      if (p->g_currentMemberDef)
      {

        if (bClass && p->foldStack.empty())
          codeFolding(d);
        else
          codeFolding(p->g_currentMemberDef);

        p->g_code->writeLineNumber(p->g_currentMemberDef->getReference(),
                                   p->g_currentMemberDef->getOutputFileBase(),
                                   p->g_currentMemberDef->anchor(), p->g_yyLineNr,
                                   true);
        VerilogCodeParser::setCurrentDoc1(lineAnchor);
      }
      else if (d->isLinkableInProject())
      {
        codeFolding(d);
        p->g_code->writeLineNumber(d->getReference(),
                                   d->getOutputFileBase(),
                                   QCString(), p->g_yyLineNr,
                                   true);
        setCurrentDoc1(lineAnchor);
      }
    }
    else
    {
      codeFolding(d);
      p->g_code->writeLineNumber(QCString(), QCString(), QCString(), p->g_yyLineNr,
                                 !p->g_includeCodeFragment);
    }
  }
  // p->g_code->startCodeLine(p->g_sourceFileDef);
  p->insideCodeLine = true;
  if (p->g_currentFontClass)
  {
    p->g_code->startFontClass(p->g_currentFontClass);
  }
}

void VerilogCodeParser::setCurrentDoc1(QCString &anchor)
{
  if (Doxygen::searchIndex)
  {
    if (p->g_searchCtx)
    {
      Doxygen::searchIndex->setCurrentDoc(p->g_searchCtx, p->g_searchCtx->anchor(), FALSE);
    }
    else
    {
      Doxygen::searchIndex->setCurrentDoc(p->g_sourceFileDef, anchor, TRUE);
    }
  }
}

void VerilogCodeParser::nextCodeLine()
{
  if (p->insideCodeLine)
  {
    endCodeLine(); // </div>
  }
  const char *fc = p->g_currentFontClass;
  if (p->g_yyLineNr < p->g_inputLines)
  {
    p->g_currentFontClass = fc;
    startCodeLine(); //<div>
  }
}

void VerilogCodeParser::writeWord(const QCString &c)
{
  p->g_code->codify(c);
}

/*! writes a code fragment `text' that may span multiple lines, inserting
 * line numbers for each line.
 */
//QCString & text,QCString & cl,bool undoc,bool comment,bool classLink
void VerilogCodeParser::codifyLines(const char *text, const char *cll, bool undoc, bool comment, bool classLink)
{

  if (text == NULL)
    return;
  // printf("codifyLines([%d %s])\n",p->g_yyLineNr,text);
  QCString cl = cll;
  const char *p1 = text, *sp = p1;
  char c;
  bool done = false;
  while (!done)
  {
    sp = p1;
    while ((c = *p1++) && c != '\n')
    {
    }
    if (c == '\n')
    {
      p->g_yyLineNr++;
      QCString line = sp;
      line = line.left((int)(p1 - sp) - 1);
      if (comment && !undoc)
      {
        writeVerilogFont("comment", line.data());
      }
      else if (undoc)
      {
        writeVerilogFont("greyout", line.data());
      }
      else
      {
        writeWord(line);
      }
      nextCodeLine();
    }
    else
    {
      if (comment)
      {
        writeVerilogFont("comment", sp);
      }
      else if (undoc)
      {
        writeVerilogFont("greyout", sp);
      }
      else
      {
        writeWord(QCString(sp));
      }
      done = true;
    }
  }
} // codifyLines

void VerilogCodeParser::endCodeLine()
{
  if (p->g_currentFontClass)
  {
    p->g_code->endFontClass();
  }
  p->g_code->endCodeLine();
}

void VerilogCodeParser::writeDigit(const char *s)
{
  writeVerilogFont("vhdllogic", s);
}

const MemberDef *findGlobalMemberDef(QCString &key, QCString &fi)
{
  for (const auto &mn : *Doxygen::functionNameLinkedMap)
  {
    // for each member definition
    for (const auto &md : *mn)
    {
      QCString f = md->getDefFileName();
      if (md->name() == key && f == fi)
      {
        return md.get();
      }
      // t << md->name() << " " << md->getStartBodyLine() << " " << md->typeString()<<" | "<<md->memberType()<<" | " << "\n";
    }
  }
  return nullptr;
}

const MemberDef *findAllGlobalMemberDef(QCString &key)
{
  for (const auto &mn : *Doxygen::functionNameLinkedMap)
  {
    // for each member definition
    for (const auto &md : *mn)
    {
      if (md->name() == key)
      {

        return md.get();
      }
      // t << md->name() << " " << md->getStartBodyLine() << " " << md->typeString()<<" | "<<md->memberType()<<" | " << "\n";
    }
  }
  return nullptr;
}

const MemberDef *findMemberDef(ClassDef *cd, const QCString &key)
{

  if (cd == NULL || key.isEmpty())
    return NULL;

  if (std::find(g_classList.begin(), g_classList.end(), cd) == g_classList.end())
  {
    // std::cout << "add Class to list:" << cd->name().data() << "\n";
    g_classList.push_back(cd);
    for (const auto &ml : cd->getMemberLists())
    {
      //   std::cout << "memlisttype:" << ml->listType() << "\n";
      for (const auto &md : *ml)
      {
        QCString tkey = cd->symbolName() + "@" + md->name();
        //      std::cout << "insert: " << tkey << "\n";
        g_varMap.insert({tkey.str(), md});
      }
    }
  }

  auto itt = g_packages.find(cd);
  if (itt != g_packages.end())
  {
    for (ClassDef *cf : itt->second)
    {
      //     std::cout << cf->name() << "\n";
      if (std::find(g_classList.begin(), g_classList.end(), cf) != g_classList.end())
        continue;
      g_classList.push_back(cf);
      //    std::cout << "search: " << cf->name() << "\n";

      for (const auto &ml : cf->getMemberLists())
      {
        for (const auto &md : *ml)
        {
          QCString tkey = cf->symbolName() + "@" + md->name();
          //         std::cout << "insert extended: " << tkey << "\n";
          g_varMap.insert({tkey.str(), md});
        }
      }
    }
  }

  // search key in module/package/class etc..
  QCString keyType = cd->symbolName() + "@" + key;
  auto it = g_varMap.find(keyType.str());
  if (it != g_varMap.end())
  {
    return it->second;
  }

  // search key in inherit classes packages etc...
  auto ito = g_packages.find(cd);
  if (ito != g_packages.end())
  {
    for (ClassDef *cf : ito->second)
    {
      QCString keyT = cf->symbolName() + "@" + key;
      // std::cout<<"search: "<<keyType<<"\n";
      auto itq = g_varMap.find(keyT.str());
      if (itq != g_varMap.end())
      {
        //   std::cout<<"found: "<<keyType<<"\n";
        return itq->second;
      }
    }
  }

  return 0;
}

QCString clazzScope;
bool sourceTooltips = Config_getBool(SOURCE_TOOLTIPS);

void VerilogCodeParser::codifyWord(const char *s, const QCString &clScope)
{
  QCString qcs = s;
  QCString tooltip = "";

  //const Definition *d = p->g_sourceFileDef->getSourceDefinition(p->g_yyLineNr);

  // std::cout << "codify word:" << s << " -- " << clScope.data() << "\n";

  if (findKey(s))
  {
    writeVerilogFont("vhdlkeyword", s);
    return;
  }

  if (findSystemKey(s))
  {
    writeVerilogFont("vhdlkeyword", s);
    return;
  }

  if (!clScope.isEmpty())
  {
    // writes AA::ss or AA::BB::cc
    if (writeDefinitionFromClassScope(clScope, qcs))
      return;
  }

  ClassDef *baseC = Doxygen::classLinkedMap->find(s);
  if (baseC)
  {
    dumpClassMembers(baseC);
    writeClassLink(baseC, true);
    return;
  }

  if (p->g_currClass != NULL)
  {
    // assert(p->g_currClass!=NULL);

    const Definition *ddef = p->g_currClass->findInnerCompound(s);
    if (ddef && ddef->definitionType() == Definition::TypeClass)
    {
      const ClassDef *cc = toClassDef(ddef);
      writeClassLink(cc, false);
      return;
    }
  }

  const MemberDef *md = NULL;
  if (p->g_currClass)
  {
    md = findMemberDef(p->g_currClass, qcs);
    if (md)
    {
      writeCodeLink(md, tooltip);
      return;
    }
  }

  QCString ff = p->g_sourceFileDef->getDefFileName();
  md = findAllGlobalMemberDef(qcs);
  if (md)
  {
    writeCodeLink(md, tooltip);
    return;
  }

  p->g_code->codify(qcs);
}

// write isalpha signs  !"§$%&//()=?"
void VerilogCodeParser::codifyWord(const char *s)
{
  p->g_code->codify(s);
}

void VerilogCodeParser::generateClassOrGlobalLink(const QCString &clName, const QCString &curr_class, bool typeOnly)
{
  QCString className = clName;

  if (className.isEmpty())
    return;

  ClassDef *cd = 0;
  className.stripPrefix("_");
  cd = getClass(className);
  if (!cd && !curr_class.isEmpty())
  {
    QCString cls = curr_class;
    QCString suffix = "::";
    suffix += clName;
    if (cls.right(suffix.length()) == suffix)
    {
      cd = getClass(curr_class);
    }
  }

  while (cd)
  {
    // className.stripPrefix("_");
    QCString temp(clName);
    temp.stripPrefix("_");
    if (cd && cd->isLinkable()) // is it a linkable class
    {

      // writeMultiLineCodeLink(cd,temp);
      addToSearchIndex(className);
      return;
    }
    Definition *d = cd->getOuterScope();
    if (d && d->definitionType() == Definition::TypeClass)
    {
      cd = toClassDef(d);
    }
    else
    {
      cd = 0;
    }
  }
} // classorgloballinks

void VerilogCodeParser::writeMultiLineCodeLink(
    const char *ref, const char *file,
    const char *anchor, const char *text, Definition *d)
{
}

void VerilogCodeParser::addToSearchIndex(const QCString &text)
{
  if (Doxygen::searchIndex)
  {
    //  p->g_code->addWord(text,false);
  }
}

void VerilogCodeParser::generateFuncLink(const MemberDef *mdef)
{
 // printf("generateFuncLink(FuncName=%s)\n", mdef->name().data());
  QCString memberName = mdef->name();

  if (mdef->isLinkable()) // is it a linkable class
  {
    // writeMultiLineCodeLink(mdef,mdef->name());
    addToSearchIndex(memberName);
    return;
  }
  codifyLines(memberName.data(), NULL, false, false, false);
  addToSearchIndex(memberName);
}

void VerilogCodeParser::codeFolding(const Definition *d)
{

  if (Config_getBool(HTML_CODE_FOLDING))
  {
    int yyLineNr = p->g_yyLineNr;

    while (!p->foldStack.empty())
    {
      const Definition *dd = p->foldStack.back();
      if (dd->getEndBodyLine() + 1 == yyLineNr) // +1 to close the section after the end of the body
      {
        p->g_code->endFold();
        p->foldStack.pop_back();
      }
      else
      {
        break;
      }
    }

    bool bClass = false;
    bool func = false;

    if (d)
    {
      bClass = d->definitionType() == Definition::TypeClass;
      if (!bClass)
      {
        const MemberDef *iii = toMemberDef(d);

        if (iii && !iii->getQualifiers().empty())
        {
          std::string qc = iii->getQualifiers().at(0);
          if (qc == "function" || qc == "task" || qc == "covergroup" || qc == "sequence" || qc == "property")
          {
            func = true;
          }
        }
      }
    }

    if (d && (bClass || func))
    {
      // printf("insert name %s \n", d->name().data());
      int startLine = d->getStartDefLine();
      int endLine = d->getEndBodyLine();
      if (endLine != -1 && startLine != endLine && (p->foldStack.empty() || p->foldStack.back()->getEndBodyLine() != startLine))
      {
        //  printf("%d: start codeFolding for %s [%d..%d]\n", yyLineNr, qPrint(d->name()), d->getStartDefLine(), d->getEndBodyLine());
        p->g_code->startFold(yyLineNr, "", "");
        p->foldStack.push_back(d);
      }
    }
  }
}

void VerilogCodeParser::generateMemLink(QCString &clName, QCString &memberName)
{
  if (memberName.isEmpty())
    return;
  // printf("generate memberName %s...\n", memberName.data());
  if (clName.isEmpty())
  {
    codifyLines(memberName.data(), NULL, false, false, false);
    return;
  }
}

void VerilogCodeParser::codifyMacroString(std::string &s)
{
  const MemberDef *md = 0;
  QCString tool = "";

#if 0
  if (findSystemKey(s))
  {
    writeVerilogFont("preprocessor", s.c_str());
    return;
  }
#endif

  if (findKey(s))
  {
    writeVerilogFont("vhdlkeyword", s.c_str());
    return;
  }

  if (findDefSet(s))
  {
    writeVerilogFont("vhdlkeyword", s.c_str());
    return;
  }

  if (s.front() == '`')
  {
    std::string w = s.substr(1);
    md = findMacroMember(w.data());
    if (md != NULL)
    {
      p->g_code->codify("`");
      writeCodeLink(md, tool);
    }
    else
      p->g_code->codify(s.data());

    return;
  }
  md = findMacroMember(s.data());
  if (md != NULL)
  {
    writeCodeLink(md, tool);
    return;
  }

  p->g_code->codify(s.data());
}

const MemberDef *VerilogCodeParser::findMacroMember(const char *m)
{
  for (const auto &[file, defL] : Doxygen::macroDefinitions)
  {
    bool am = false;
    FileDef *fdd = findFileDef(Doxygen::inputNameLinkedMap, QCString(file.data()), am);
    for (const auto &mll : fdd->getMemberLists())
    {
      QCString qc(m);
      MemberDef *mdef = mll->find(qc);
      if (mdef)
      {
        return mdef;
      }
    }
    return NULL;
  }
  return NULL;
}

void VerilogCodeParser::writeCodeLink(const Definition *md, QCString tooltip)
{
  if (md == NULL)
    return;
  p->g_code->writeCodeLink(
      md->codeSymbolType(),
      md->getReference(),
      md->getOutputFileBase(),
      md->anchor(),
      md->name(),
      tooltip);
}

void VerilogCodeParser::writeIncludeLink(std::string s)
{
  bool am;
  prepc::replace(s, "\"", "");
  std::string res = stripPath(QCString(s)).data();
  FileDef *fd = findFileDef(Doxygen::inputNameLinkedMap, QCString(res.data()), am);

  p->g_code->codify("\"");
  if (fd)
  {
    writeCodeLink(fd, "");
  }
  else
    p->g_code->codify(s.data());

  p->g_code->codify("\"");
}

void VerilogCodeParser::writeClassLink(const ClassDef *cd, bool scope)
{
  QCString tooltip = "";
  if (cd == NULL)
    return;

  p->g_code->writeCodeLink(
      cd->codeSymbolType(),
      cd->getReference(),
      cd->getOutputFileBase(),
      cd->anchor(),
      cd->displayName(scope),
      tooltip);
}

const MemberDef *findMemberDef(ClassDef *cd, const QCString &key, MemberListType type)
{
  QCString keyType = cd->symbolName() + "@" + key;
  // printf("\n %s | %s | %s",qPrint(cd->symbolName()),key.data(,),qPrint(keyType));

  auto it = g_varMap.find(keyType.str());
  if (it != g_varMap.end())
  {
    return it->second;
  }
  if (std::find(g_classList.begin(), g_classList.end(), cd) != g_classList.end())
  {
    return 0;
  }
  const MemberList *ml = cd->getMemberList(type);
  g_classList.push_back(cd);
  if (!ml)
  {
    return 0;
  }
 
  for (const auto &md : *ml)
  {
    QCString tkey = cd->symbolName() + "@" + md->name();
    if (g_varMap.find(tkey.str()) == g_varMap.end())
    {
      exit(9);
      g_varMap.insert({tkey.str(), md});
    }
  }
  it = g_varMap.find(keyType.str());
  if (it != g_varMap.end())
  {
    return it->second;
  }
  return 0;
} // findMemberDef
