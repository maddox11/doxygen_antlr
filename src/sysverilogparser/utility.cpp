#include "utility.h"
#include "antlr4-runtime.h"
#include "defargs.h"
#include <regex>
using namespace antlr4;
using namespace antlr4::tree;
using namespace std::regex_constants;
using SVP = SysVerilogParser;
using TVec = std::vector<Token *>;
using Vec = std::vector<ParseTree *>;

struct Sum
{
  void operator()(RuleContext *n)
  {
    sum.append(n->getText().data());
    sum.append(" ");
  }
  QCString sum = "";
};

std::smatch _sm;
const std::regex _reg("[a-zA-Z_$][a-zA-Z_0-9]*");

void treeVec2String(ParseTree *pt, std::string &res)
{
  for (ParseTree *t : pt->children)
  {
    if (t->getTreeType() == ParseTreeType::TERMINAL)
    {
      std::string v = t->getText();
      res.append(t->getText());
      if (std::regex_search(v, _sm, _reg))
        res.append(" ");
    }
    treeVec2String(t, res);
  }
}

void getMethodQualifier(ParseTree *pt, std::string &res, bool &virt)
{
  for (ParseTree *t : pt->children)
  {
    if (t->getTreeType() == ParseTreeType::TERMINAL)
    {
      //  std::cout << t->getText() << " .. ";
      TerminalNode *n = (TerminalNode *)t;
      size_t type = n->getSymbol()->getType();
      switch (type)
      {
      case SVP::T_VIRTUAL:
        res.append("virtual ");
        virt = true;
        break;
      case SVP::T_PURE:
        res.append("pure ");
        break;
      case SVP::T_EXTERN:
        res.append("extern ");
        break;
      case SVP::T_STATIC:
        res.append("static ");
        break;
      case SVP::T_LOCAL:
        res.append("local ");
        break;
      case SVP::T_PROTECTED:
        res.append("protected ");
        break;
      }
    }
    else
      getMethodQualifier(t, res, virt);
  }
}

void printRules(std::vector<ParseTree *> &vec)
{
  std::cout << "\n";
  for (ParseTree *t : vec)
  {
    if (t->getTreeType() == ParseTreeType::RULE)
    {
      RuleContext *rc = (RuleContext *)t;
      std::cout << "rule index: " << rc->getRuleIndex() << " " << rc->getText() << "\n";
      // if (rc->getRuleIndex() == 579)
      //  std::cout << " SS: " << t->getText() << "\n";
    }
    else
    {
      TerminalNode *n = (TerminalNode *)t;
      std::cout << "terminal node: " << n->getText() << "\n";
    }
  } // for
  std::cout << "\n";
}

RuleContext *getRule(antlr4::tree::ParseTree *p, int rule)
{
  // terminal node
  if (p->getTreeType() != ParseTreeType::RULE)
    return nullptr;

  RuleContext *rc = (RuleContext *)p;

  if (rc->getRuleIndex() == rule)
    return rc;

  return nullptr;
}

bool checkParentToken(size_t index, size_t kind, antlr4::CommonTokenStream *com)
{

  while (index >= 0)
  {
    index--;
    size_t sym = com->get(index)->getType();

    // ignore white space/newline
    if (sym == SVP::WS || sym == SVP::NEWLINE)
      continue;

    if (sym == kind)
      return true;

    return false;
  }

  return false;
}

bool checkRule(antlr4::tree::ParseTree *p, int rule)
{
  if (p->getTreeType() != ParseTreeType::RULE)
    return false;

  RuleContext *rc = (RuleContext *)p;
  if (rc->getRuleIndex() == rule)
    return true;

  return false;
}

void xPath(ParseTree *pt, std::string &path, std::vector<ParseTree *> &res, SysVerilogParser *exe)
{
  std::vector<ParseTree *> v = pt->children;
  for (ParseTree *t : v)
  {
    std::vector<ParseTree *> vpp = xpath::XPath::findAll(t, path, exe);
    res.insert(res.begin(), vpp.begin(), vpp.end());
  }
} // children

ParseTree *getRuleNode(std::vector<antlr4::tree::ParseTree *> &vec, int rule)
{
  for (ParseTree *pt : vec)
  {
    if (checkRule(pt, rule))
      return pt;
  }
  return nullptr;
}

bool parseDataOrVoid(SVP::Data_type_or_voidContext *dc, std::string &s)
{
  if (dc->data_type())
    return parseDataType(dc->data_type(), s);

  s = dc->getText();
  return false;
}

bool parseDataTypeImpl(SVP::Data_type_or_implicitContext *dc, std::string &s)
{

  if (!dc)
    return true;

  if (dc->data_type())
    return parseDataType(dc->data_type(), s);

  s = dc->implicit_data_type()->getText();
  return false;
}

bool parseDataType(SVP::Data_typeContext *dc, std::string &s)
{

  for (ParseTree *t : dc->children)
  {
    s.append(t->getText());
    s.append(" ");
  }

  return dc->class_type() != NULL;
}

QCString parse_tf_port_item1(SysVerilogParser::Tf_port_listContext *tpl, struct SharedState *sh)
{
  QCString arg = "(";
  int l = tpl->tf_port_item().size();
  int k = 0;
  for (SVP::Tf_port_itemContext *tp : tpl->tf_port_item())
  {
    if (tp->tf_port_direction())
      arg.append(tp->tf_port_direction()->getText());
    arg.append(" ");
    if (tp->T_VAR())
      arg.append("var ");
    if (tp->data_type_or_implicit())
      arg.append(tp->data_type_or_implicit()->getText());
    arg.append(" ");
    if (tp->ss())
      arg.append(tp->ss()->getText());
    if (tp->variable_dimension(0))
      arg.append(tp->variable_dimension(0)->getText());
    arg.append(" ");
    if (tp->expression())
    {
      arg.append("=");
      arg.append(tp->expression()->getText());
    }
    k++;

    if (k < l)
      arg.append(",");
  }
  arg.append(")");
  sh->current->argList = *stringToArgumentList(SrcLangExt_Cpp, arg);
  return arg;
}

void parse_tf_port_item(SysVerilogParser::Tf_port_listContext *tpl, struct SharedState *sh)
{

  std::vector<SVP::Tf_port_itemContext *> tvec = tpl->tf_port_item();
  sh->current->argList.clear();
  sh->current->args.resize(0);
  QCString qcs = "(";

  for (SVP::Tf_port_itemContext *tp : tvec)
  {
    struct Argument ar;
    if (tp->EQ())
      ar.defval = tp->expression()->getText();

    if (tp->data_type_or_implicit())
      ar.type = tp->data_type_or_implicit()->getText().data();

    if (tp->ss())
      ar.name += tp->ss()->getText();
    else
      ar.name = "ZZZZ";
    if (tp->tf_port_direction())
      ar.attrib = tp->tf_port_direction()->getText();
    sh->current->argList.push_back(ar);
    qcs.append(" ");
    qcs.append(ar.type.data());
    qcs.append(" ");
    qcs.append(ar.name.data());
    qcs.append(" ");
    qcs.append(ar.defval.data());
    qcs.append(",");
    //  std::cout << "port item[" << tp->getText() << "]\n";
  }
  if (qcs.endsWith(","))
    qcs = qcs.remove(qcs.length() - 1, 1);
  qcs.append(")");
  sh->current->args = qcs;
}

void parseListofVariableIdentifiers(int l, bool ss, const char *r, const char *t, SVP::List_of_variable_identifiersContext *liof, const char *dir, VerilogOutlineParser *ol)
{
  int i = 0;
  std::string data(t);
  std::string dim, name;

  if (liof == nullptr)
    return;
  std::vector<SVP::SsContext *> idf = liof->ss();
  int vsize = idf.size();

  std::vector<SVP::Variable_dimensionContext *> un = liof->variable_dimension();

  // case input i
  // case input i[999][00]...

  if (vsize == 0)
  {
    for (SVP::Variable_dimensionContext *vp : un)
    {
      dim.append(vp->getText());
      // std::cout << "dimension:" << vp->getText() << "\n";
    }
    ol->addMember(t, dim.data(), r, l, l, EntryType::makeVariable(), TypeSpecifier().setValue(true), dir, Protection::Public, 0);
    return;
  }

  auto tn = liof->children;
  for (ParseTree *n : tn)
  {
    if (n->getTreeType() == ParseTreeType::RULE)
    {
      RuleContext *rc = (RuleContext *)n;

      if (rc->getRuleIndex() == SVP::RuleSs)
      {
        name.append(rc->getText());
      }

      if (rc->getRuleIndex() == SVP::RuleVariable_dimension)
      {
        dim.append(rc->getText());
      }
    }

    // found ","
    if (n->getTreeType() == ParseTreeType::TERMINAL)
    {
      if (name.empty())
      {
        name.append(data);
        data.clear();
      }
      ol->addMember(name.data(), dim.data(), data.c_str(), l, l, EntryType::makeVariable(), TypeSpecifier().setValue(true), dir, Protection::Public, 0);
      dim.clear();
      name.clear();
    }
  } // for

  if (!name.empty())
  {
    if (ss)
      data.clear();
    ol->addMember(name.data(), dim.data(), data.c_str(), l, l, EntryType::makeVariable(), TypeSpecifier().setValue(true), dir, Protection::Public, 0);
  }
}

void parseListofPortIdentifiers(int l, bool ss, const char *r, const char *t, SVP::List_of_port_identifiersContext *liof, const char *dir, VerilogOutlineParser *ol)
{
  int i = 0;
  std::string data(t);
  std::string dim, name;

  if (liof == nullptr)
    return;
  int vsize = liof->ss().size();

  std::vector<SVP::Unpacked_dimensionContext *> un = liof->unpacked_dimension();

  if (vsize == 0)
  {
    for (SVP::Unpacked_dimensionContext *vp : un)
      dim.append(vp->getText());

    ol->addMember(t, dim.data(), r, l, l, EntryType::makeVariable(), TypeSpecifier().setValue(true), dir, Protection::Public, dir);
    return;
  }

  for (ParseTree *n : liof->children)
  {
    if (n->getTreeType() == ParseTreeType::RULE)
    {
      RuleContext *rc = (RuleContext *)n;

      if (rc->getRuleIndex() == SVP::RuleSs)
      {
        name.append(rc->getText());
      }

      if (rc->getRuleIndex() == SVP::RuleUnpacked_dimension)
      {
        dim.append(rc->getText());
      }
    }

    // found ","
    if (n->getTreeType() == ParseTreeType::TERMINAL)
    {
      if (name.empty())
      {
        name.append(data);
        data.clear();
      }
      ol->addMember(name.data(), dim.data(), data.c_str(), l, l, EntryType::makeVariable(), TypeSpecifier().setValue(true), dir, Protection::Public, 0);
      dim.clear();
      name.clear();
    }
  } // for

  if (!name.empty())
  {
    if (ss)
      data.clear();
    ol->addMember(name.data(), dim.data(), data.c_str(), l, l, EntryType::makeVariable(), TypeSpecifier().setValue(true), dir, Protection::Public, 0);
  }
}
// void parseVariableDeclAssignment(bool &b,std::string & id,std::string & args,ExprParserParser::Variable_decl_assignmentContext *vc,size_t & li);
void parseVariableDeclAssignment(bool &b, std::string &id, std::string &args, SysVerilogParser::Variable_decl_assignmentContext *vc, int &li)
{

  std::string str = vc->getText();

  if (vc->ss() == NULL)
  {
    args = str;
    b = true;
    return;
  }

  li = vc->ss()->getStart()->getLine();
  id = vc->ss()->getText();
  // std::cout << id << "\n";

  if (vc->EQ())
  {
    for (SVP::Variable_dimensionContext *d : vc->variable_dimension())
      args.append(d->getText());

    size_t i = str.find_first_of('=');
    args.append(str.substr(i));
    return;
  }

  std::size_t found = str.find(id);

  if (found != std::string::npos)
  {
    args = str.erase(found, id.size());
  }
}

bool checkStructUnion(SVP::Data_typeContext *dc, std::string &type)
{
  if (dc == NULL)
    return false;

  if (dc->struct_union_member(0))
  {
    // type=dc->struct_union_member(0)->getText();
    return true;
  }

  return false;
}

void parseNet_Port_Header(SysVerilogParser::Net_port_headerContext *np, QCString &v, QCString &w, QCString &type, bool &id)
{

  if (np->port_direction())
    v = np->port_direction()->getText();

  if (np->net_port_type()->net_type())
    type = np->net_port_type()->net_type()->getText();

  std::string val;
  id = parseDataTypeImpl(np->net_port_type()->data_type_or_implicit(), val);
  w = val.data();
  // w = np->net_port_type()->getText();
}
void parseInterfaceHeader(SysVerilogParser::Interface_port_headerContext *ip, QCString &w)
{
  if (ip->T_INTERFACE())
  {
    w.append("interface");
    if (ip->DOT())
    {
      w.append(".");
      w.append(ip->ss(0)->getText());
    }
    return;
  }

  w.append(ip->ss(0)->getText());
  if (ip->DOT())
  {
    w.append(".");
    w.append(ip->ss(1)->getText());
  }
}

void parseVariablePortHeader(SysVerilogParser::Variable_port_headerContext *vc, QCString &v, QCString &w)
{
  if (vc->port_direction())
    v = vc->port_direction()->getText();

  w = vc->variable_port_type()->getText();
}

void printPP(std::vector<antlr4::RuleContext *> &v)
{
  for (RuleContext *r : v)
  {
    // std::cout << r->getText().data();
  }
}

void deleteAllChars(std::string &s, const char *c)
{
  int l = strlen(c);
  size_t i = s.find(c);
  while (i != std::string::npos)
  {
    s = s.erase(i, l);
    i = s.find(c);
  }
}

std::string vec2string(int start, int stop, antlr4::CommonTokenStream *com)
{
  std::vector<antlr4::Token *> vec = com->getTokens(start, stop);
  std::string val;
  for (Token *t : vec)
  {
    val.append(t->getText());
    val.append(" ");
  }
  return val;
}



std::string vec2string(std::vector<antlr4::Token *> &vec)
{
  std::string val;
  for (Token *t : vec)
  {
    val.append(t->getText());
  }
  return val;
}

void parseListOfParamAssign(SysVerilogParser::List_of_param_assignmentsContext *ctx, VerilogOutlineParser *ol, std::string type, std::string n)
{
  std::vector<SVP::Param_assignmentContext *> pc = ctx->param_assignment();
  std::string name, expr, dim;
  int l;
  for (SVP::Param_assignmentContext *ass : pc)
  {
    if (ass->ss())
    {
      name = ass->ss()->getText();
      l = ass->ss()->getStart()->getLine();
    }
    else
    {
      name = n;
      l = ass->getStart()->getLine();
    }

    std::vector<SVP::Unpacked_dimensionContext *> u = ass->unpacked_dimension();

    if (!u.empty())
      dim = std::for_each(u.cbegin(), u.cend(), Sum()).sum.data();

    type.append(dim);

    if (ass->EQ())
    {
      expr = "=";
      expr += ass->constant_param_expression()->getText();
    }

    ol->addMember(name.data(), expr.data(), type.data(), l, l, EntryType::makeVariable(), TypeSpecifier().setValue(true), "", Protection::Public, 0);
  }
}

void parseListOfTypeAssign(SysVerilogParser::List_of_type_assignmentsContext *ctx, VerilogOutlineParser *ol, std::string type, std::string n)
{
  std::vector<SVP::Type_assignmentContext *> pc = ctx->type_assignment();
  std::string name, expr, dim;
  int l;
  for (SVP::Type_assignmentContext *ass : pc)
  {
    if (ass->ss())
    {
      name = ass->ss()->getText();
      l = ass->ss()->getStart()->getLine();
    }
    else
    {
      name = type;
      l = ass->getStart()->getLine();
      type.clear();
    }

    if (ass->EQ())
    {
      expr = "=";
      expr.append(ass->data_type()->getText());
    }

    ol->addMember(name.data(), expr.data(), type.data(), l, l, EntryType::makeVariable(), TypeSpecifier().setValue(false), "", Protection::Public, 0);

  } // for
}

void parseListOfSpecparamAssign(SysVerilogParser::List_of_specparam_assignmentsContext *ctx, const VerilogOutlineParser *ol, std::string type, std::string name)
{
}

void parseEnumberation(SysVerilogParser::Data_typeContext *dc, VerilogOutlineParser *ol, struct SharedState *sh, std::string &idd, int line)
{
  std::vector<SVP::Enum_name_declarationContext *> vs = dc->enum_name_declaration();

  for (SVP::Enum_name_declarationContext *sc : vs)
  {
    std::string id = sc->ss()->getText();
    std::shared_ptr<Entry> e = std::make_shared<Entry>();
    e->name = id;
    sh->current->moveToSubEntryAndKeep(e);
  }
 std::string type;
  if (dc->enum_base_type())
    type.append(dc->enum_base_type()->getText());

  ol->addMember(idd.data(), type.data(), "@", line, line, EntryType::makeEnum(), TypeSpecifier().setValue(true), "", Protection::Protected, type.data());

  
  for (SVP::Enum_name_declarationContext *sc : vs)
  {
    int line = sc->getStart()->getLine();
    std::string s = sc->getText();
   //std::cout << "found enum :" << s << " at line:" << line << "\n";
    if (sc->EQ())
    {
      std::string arg = sc->constant_expression()->getText();
      sh->current->initializer << "=" << arg.data();
    }

    std::string id = sc->ss()->getText();
    ol->addMember(id.data(), "", "@", line, line, EntryType::makeVariable(), TypeSpecifier().setEnum(true).setStrong(true), "oop", Protection::Public, 0);
  }

 
}

void eventExpression(std::vector<SVP::Event_expressionContext *> &event, struct SharedState *sh)
{
  for (SVP::Event_expressionContext *e : event)
  {
    for (SVP::ExpressionContext *ep : e->expression())
    {
      struct Argument ar;
      if (ep->expression(0))
        continue;
      //  std::cout << "ep:" << ep->getText() << "\n";
      ar.name = ep->getText().data();
      sh->current->argList.push_back(ar);
    }
  }
}

std::string getStructUnionName(antlr4::tree::ParseTree *t)
{
  std::string res;
  ParseTree *type_def = t->parent->parent;
  ParseTree *stru = t->parent;
  if (getRuleNode(type_def->children, SVP::RuleType_declaration) != NULL)
  {
    ParseTree *pt = getRuleNode(stru->children, SVP::RuleSs);
    if (pt)
      return pt->getText();

    return res;
  }

  ParseTree *pt = getRuleNode(type_def->children, SVP::RuleList_of_variable_decl_assignments);
  if (pt)
    return pt->getText();

  return res;
}