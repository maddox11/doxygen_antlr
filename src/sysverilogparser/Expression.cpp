
#include <vector>

#include "markdown.h"
#include "config.h"
#include "moduledef.h"
#include "defargs.h"
#include "utility.h"

#include "Expression.h"

using namespace antlr4;
using namespace antlr4::tree;
using String = std::string;
using SVP = SysVerilogParser;
using Vec = std::vector<ParseTree *>;
using TVec = std::vector<Token *>;

struct Sum
{
  void operator()(RuleContext *n)
  {
    sum.append(n->getText().data());
    sum.append(" ");
  }
  QCString sum = "";
};

QCString getProcessNumber()
{
  static int stringCounter;
  QCString qcs("PROCESS1_");
  char buf[8];
  qsnprintf(buf, 8, "%d", stringCounter++);
  qcs.append(&buf[0]);
  return qcs;
}

bool checkPath(antlr4::tree::ParseTree *t)
{

  bool b = false;
  while (t != NULL)
  {
    if (t->getTreeType() == ParseTreeType::RULE)
    {
      RuleContext *rc = (RuleContext *)t;
      size_t bn = rc->getRuleIndex();
      if (bn == SysVerilogParser::RuleAlways_construct || bn == SysVerilogParser::RuleFunction_declaration || bn == 185)
      {
        // std::cout << "rule .. found:" << bn << "\n";
        return true;
      }
    }
    t = t->parent;
  }
  return b;
}

void containsTreeType(ParseTree *pt, size_t rule, std::string &res)
{
  for (ParseTree *t : pt->children)
  {
    if (t->getTreeType() == ParseTreeType::RULE)
    {
      RuleContext *rc = (RuleContext *)t;
      size_t bn = rc->getRuleIndex();
      // std::cout << "rule index: " << rc->toStringTree() <<bn<< "\n";
      if (bn == rule)
      {
        res.append(rc->getText());
        res.append(" ");
      }
    }
    containsTreeType(t, rule, res);
  } // for
}

// parse hidden tokens like comments //! whitespace,macros etc
std::string Expression::parseHiddenTokens(const antlr4::Token *tok)
{
  std::string buf, se;

  TVec vec = com->getHiddenTokensToLeft(tok->getTokenIndex(), 2);

  for (Token *t : vec)
  {
    se = t->getText();
    prepc::replace(se, "\n", "");

    if (t->getType() == SysVerilogLexer::One_line_comment)
    {
      if (se.find("//!", 0, 3) != std::string::npos)
      {
        outlineParser()->addComment(se, t->getLine(), TRUE);
      }
    }

    if (t->getType() == SysVerilogLexer::Block_comment)
    {
      if (se.find("/**", 0, 3) != std::string::npos || se.find("/*!", 0, 3) != std::string::npos)
      {

        if (countLines(se.data()) == 1)
          outlineParser()->addComment(se, t->getLine(), TRUE);
        else
          outlineParser()->addComment(se, t->getLine(), FALSE);
      }
    }

    if (t->getType() == SysVerilogLexer::Macro || t->getType() == SysVerilogLexer::Define)
    {
      std::string res = t->getText();
      if (t->getType() == SysVerilogLexer::Define)
      {
        std::string val = cutComment(res);
        if (val.find("//!") != std::string::npos)
          buf = val.substr(3);
      }

      prepc::PrepParser p("file");
      prepc::Token tt(8, res);

      p.parseM(&tt);

      DefVec d = p.getMacros();
      assert(!d.empty());
      prepc::DefMacro *def = d.begin()->second;
      def->beginLine = t->getLine();
      outlineParser()->addMacro(def, buf, t->getLine());
      if (!buf.empty())
      {
        buf.clear();
      }
    }
  }

  return buf;
}

void Expression::parseTypeDeclaration(SysVerilogParser::Type_declarationContext *tdc, int l, int m)
{

  QCString val = "typedef ";
  int ko = tdc->getStart()->getLine();
  std::string id = tdc->ss(0)->getText();
  int line = tdc->ss(0)->getStart()->getLine();
  std::string qualifier;
  std::string un, dat;

  SVP::Data_typeContext *dtc = tdc->data_type();

  if (checkStructUnion(tdc->data_type(), un))
  {
    id = tdc->ss(0)->getText();

    if (tdc->data_type()->T_PACKED())
      qualifier.append("packed ");
    if (tdc->data_type()->signing())
      qualifier.append(tdc->data_type()->signing()->getText());

    TypeSpecifier tsp;

    if (un.compare("struct") == 0)
      tsp.setStruct(true);
    else
      tsp.setUnion(true);

    outlineParser()->addClass(id.c_str(), l, m, EntryType::makeClass(), tsp, Protection::Private, qualifier.data());
    return;
  }

  if (dtc)
  {
    String args;

    parseDataType(tdc->data_type(), args);
    val.append(args);

    if (tdc->data_type()->T_ENUM())
    {
      parseEnumberation(tdc->data_type(), outlineParser(), m_sharedState, id, m);
    }
    else
      outlineParser()->addMember(id.data(), "", val.data(), l, m, EntryType::makeVariable(), TypeSpecifier().setValue(true), "ahden", Protection::Protected, "typed");

    return;
  }

  if (tdc->DOT())
  {
    QCString v = tdc->constant_bit_select()->getText().data();
    QCString n0 = tdc->ss(0)->getText().data();
    QCString n1 = tdc->ss(1)->getText().data();
    QCString n2 = tdc->ss(2)->getText().data();
    val.append(n0);
    val.append(v);
    val.append(".");
    val.append(n1);
    outlineParser()->addMember(n2.data(), "", val.data(), l, m, EntryType::makeVariable(), TypeSpecifier().setLocal(true), "raute", Protection::Public, 0);
    return;
  }

  if (tdc->T_CLASS())
    val.append("class");
  if (tdc->T_UNION())
    val.append("union");
  if (tdc->T_ENUM())
    val.append("enum");
  if (tdc->T_STRUCT())
    val.append("struct");
  if (tdc->T_INTERFACE())
    val.append("interface");

  if (dtc && dtc->T_ENUM())
    outlineParser()->addMember(id.data(), "", "enum ", l, l, EntryType::makeClass(), TypeSpecifier().setEnum(true), "", Protection::Public, 0);
  else
    outlineParser()->addMember(id.data(), "", val.data(), l, l, EntryType::makeVariable(), TypeSpecifier().setLocal(true), "schalke", Protection::Public, 0);

  if (dtc && dtc->T_ENUM())
  {
    std::vector<SVP::Enum_name_declarationContext *> vs = dtc->enum_name_declaration();

    for (SVP::Enum_name_declarationContext *sc : vs)
    {
      int line = sc->getStart()->getLine();
      std::string s = sc->getText();
      //  std::cout << "found enum :" << s << " at line:" << line << "\n";
      std::string id = sc->ss()->getText();
      outlineParser()->addMember(id.data(), s.data(), "@", l, l, EntryType::makeVariable(), TypeSpecifier().setEnum(true), "", Protection::Public, 0);
    }
  }
}

void parseListofVariablePortIdentifiers(int l, bool ss, const char *r, const char *t, SysVerilogParser::List_of_variable_port_identifiersContext *liof, const char *dir)
{
}

static void parse_tf_port_declaration(std::vector<SysVerilogParser::Tf_item_declarationContext *> &tpi, struct SharedState *sh)
{
  sh->current->argList.clear();
  sh->current->args.resize(0);
  QCString qcs = "(";

  for (SysVerilogParser::Tf_item_declarationContext *s : tpi)
  {
    struct Argument ar;
    SysVerilogParser::Tf_port_declarationContext *tp = s->tf_port_declaration();
    if (tp == nullptr)
      continue;
    ar.attrib = tp->tf_port_direction()->getText();
    ar.type = tp->data_type_or_implicit()->getText();
    SysVerilogParser::List_of_tf_variable_identifiersContext *lp = tp->list_of_tf_variable_identifiers();

    int i = 0;
    for (SysVerilogParser::SsContext *sc : lp->ss())
    {
      ar.name = sc->getText();
      if (lp->expression(i))
        ar.defval = lp->expression(i)->getText();
      i++;
      sh->current->argList.push_back(ar);
    }
  }
}

std::vector<antlr4::Token *> Expression::getHiddenTokens(antlr4::Token *tok, int c)
{
  return com->getHiddenTokensToLeft(tok->getTokenIndex(), c);
}

//-------------------------------------------------------------------------------------------------
void Expression::enterParameter_port_declaration(SysVerilogParser::Parameter_port_declarationContext *ctx)
{
  std::string type;
  //  std::cout << ctx->getText();

  bool y = ctx->list_of_param_assignments() != NULL;
  bool y1 = ctx->data_type() != NULL;
  // bool y2 = ctx->parameter_declaration() != NULL;
  bool y3 = ctx->list_of_type_assignments() != NULL;
  // bool y4 = ctx->local_parameter_declaration() != NULL;

  /*
    if (y4)
    {
      std::string func, n;
      func = "localparam ";
      SVP::Local_parameter_declarationContext *ld = ctx->local_parameter_declaration();
      if (ld->list_of_param_assignments())
      {
        parseDataTypeImpl(ld->data_type_or_implicit(), n);
        parseListOfParamAssign(ld->list_of_param_assignments(), outlineParser(), func, n);
      }
      if (ld->list_of_type_assignments())
      {
        parseListOfTypeAssign(ld->list_of_type_assignments(), outlineParser(), func, n);
        func.append("type ");
      }
    }
  */
  if (y3)
  {
    std::string func, n;
    func = "type ";
    parseListOfTypeAssign(ctx->list_of_type_assignments(), outlineParser(), func, n);
  }

  if (ctx->list_of_param_assignments() && ctx->data_type())
  {
    std::string func, n;
    // std::cout << ctx->getText();
    bool b = parseDataType(ctx->data_type(), n);
    if (!b)
      func = n;
    parseListOfParamAssign(ctx->list_of_param_assignments(), outlineParser(), func, n);
  }

  /*
    if (ctx->parameter_declaration())
    {
      std::string n;
      bool b;
      SVP::Parameter_declarationContext *dec = ctx->parameter_declaration();

      std::string func;
      func = "parameter ";
      if (ctx->T_TYPE())
        func.append("type ");

      b = parseDataTypeImpl(dec->data_type_or_implicit(), n);

      if (!b)
        func.append(n);
      if (dec->list_of_param_assignments())
        parseListOfParamAssign(dec->list_of_param_assignments(), outlineParser(), func, n);
      if (dec->list_of_type_assignments())
        parseListOfTypeAssign(dec->list_of_type_assignments(), outlineParser(), func, n);
    }
    */
}

void Expression::enterLocal_parameter_declaration(SysVerilogParser::Local_parameter_declarationContext *ctx)
{
  std::string func, n;
  func = "localparam ";
  SVP::Local_parameter_declarationContext *ld = ctx;
  if (ld->list_of_param_assignments())
  {
    parseDataTypeImpl(ld->data_type_or_implicit(), n);
    parseListOfParamAssign(ld->list_of_param_assignments(), outlineParser(), func, n);
  }
  if (ld->list_of_type_assignments())
  {
    parseListOfTypeAssign(ld->list_of_type_assignments(), outlineParser(), func, n);
    func.append("type ");
  }
}

void Expression::enterParameter_declaration(SysVerilogParser::Parameter_declarationContext *ctx)
{
  std::string n;
  bool b;
  SVP::Parameter_declarationContext *dec = ctx;

  std::string func;
  func = "parameter ";
  if (ctx->T_TYPE())
    func.append("type ");

  b = parseDataTypeImpl(dec->data_type_or_implicit(), n);

  if (!b)
    func.append(n);
  if (dec->list_of_param_assignments())
    parseListOfParamAssign(dec->list_of_param_assignments(), outlineParser(), func, n);
  if (dec->list_of_type_assignments())
    parseListOfTypeAssign(dec->list_of_type_assignments(), outlineParser(), func, n);
}

void Expression::enterPort_declaration(SVP::Port_declarationContext *ctx)
{
  String s, r, t, dir;
  Token *tok = ctx->getStart();

  int l = tok->getLine();
  SVP::Interface_port_declarationContext *inf = ctx->interface_port_declaration();
  SVP::Output_declarationContext *out = ctx->output_declaration();
  SVP::Inout_declarationContext *io = ctx->inout_declaration();
  SVP::Input_declarationContext *in = ctx->input_declaration();
  SVP::Ref_declarationContext *ref = ctx->ref_declaration();

  bool ss = false;

  if (inf)
  {
    QCString name;

    name = inf->ss(0)->getText();

    if (inf->DOT())
    {
      name.append(".");
      name.append(inf->ss(1)->getText());
    }

    SVP::List_of_interface_identifiersContext *ii = inf->list_of_interface_identifiers();
    int len = ii->ss().size();

    for (int j = 0; j < len; j++)
    {
      QCString arg, dim;
      arg = ii->ss(j)->getText();

      for (SVP::Unpacked_dimensionContext *up : ii->unpacked_dimension())
        dim.append(up->getText());

      dim = dim.prepend(name);
      outlineParser()->addMember(arg.data(), dim.data(), "interface port", l, l, EntryType::makeVariable(), TypeSpecifier().setValue(true), "", Protection::Protected, "Inst");
    }
    return;
  }

  if (in || out || io || ref)
  {
    SVP::List_of_port_identifiersContext *liof = nullptr;
    SVP::List_of_variable_port_identifiersContext *liofv = nullptr;
    SVP::Variable_port_typeContext *vp = nullptr;
    SVP::List_of_variable_identifiersContext *lcx = nullptr;
    SVP::Net_port_typeContext *np = nullptr;

    if (in)
    {
      np = in->net_port_type();
      dir = "input ";
      liof = in->list_of_port_identifiers();
      vp = in->variable_port_type();
      lcx = in->list_of_variable_identifiers();
    }
    else if (out)
    {
      np = out->net_port_type();
      dir = "output ";
      liof = out->list_of_port_identifiers();
      vp = out->variable_port_type();
      liofv = out->list_of_variable_port_identifiers();
    }
    else if (io)
    {
      np = io->net_port_type();
      dir = "inout ";
      liof = io->list_of_port_identifiers();
    }

    if (liof)
    {
      if (np->net_type())
        r = np->net_type()->getText();

      if (np->data_type_or_implicit())
      {
        t.append(np->data_type_or_implicit()->getText());
        SVP::Data_typeContext *dc = np->data_type_or_implicit()->data_type();
        std::string vall;
        if (dc)
          ss = parseDataType(dc, vall);
      }

      if (!ss)
      {
        r.append(" ");
        r.append(t);
        t = r;
      }

      parseListofPortIdentifiers(tok->getLine(), ss, r.c_str(), t.c_str(), liof, dir.c_str(), outlineParser());
    }

    if (vp)
    {
      SVP::Var_data_typeContext *vda = vp->var_data_type();
      SVP::Data_typeContext *vdd = vda->data_type();
      if (vdd == nullptr)
      {
        vdd = vda->data_type_or_implicit()->data_type();
      }
      if (vdd->ss().size() > 0 || vdd->class_type() != nullptr)
        ss = true;

      t.append(vdd->getText());
    }

    parseListofVariableIdentifiers(tok->getLine(), ss, r.c_str(), t.c_str(), lcx, dir.c_str(), outlineParser());
  }
}

void Expression::enterAnsi_port_declaration(SysVerilogParser::Ansi_port_declarationContext *ctx)
{
  QCString s, r, dim, dir, name, arg;
  Token *tok = ctx->getStart();

  int l = tok->getLine();
  if (ctx->ss())
    name = ctx->ss()->getText();
  else
    name = "ZZZ";

  name = ctx->ss() ? ctx->ss()->getText() : "ZZZ";

  if (ctx->constant_expression())
  {
    arg = "=";
    arg.append(ctx->constant_expression()->getText().data());
  }

  if (ctx->expression())
  {
    arg = "(";
    arg.append(ctx->expression()->getText().data());
    arg.append(")");
  }

  std::vector<SVP::Variable_dimensionContext *> vv0 = ctx->variable_dimension();

  if (!ctx->variable_dimension().empty())
    dim = std::for_each(vv0.cbegin(), vv0.cend(), Sum()).sum;

  std::vector<SVP::Unpacked_dimensionContext *> vv1 = ctx->unpacked_dimension();

  if (!ctx->unpacked_dimension().empty())
    dim = std::for_each(vv1.cbegin(), vv1.cend(), Sum()).sum;

  if (ctx->interface_port_header())
  {
    parseInterfaceHeader(ctx->interface_port_header(), r);
    outlineParser()->addMember(name.data(), arg.data(), r.data(), l, l, EntryType::makeVariable(), TypeSpecifier().setValue(true), "", Protection::Protected, 0);
    return;
  }

  if (ctx->net_port_header())
  {
    // std::cout << "net_port: " << ctx->net_port_header()->getText() << "\n";
    bool nn = false;
    QCString type1;
    parseNet_Port_Header(ctx->net_port_header(), dir, r, type1, nn);

    dir.append(" ");
    dir.append(type1);

    if (!nn)
    {
      dir.append(" ");
      dir.append(r);
    }

    if (nn)
      name = r;

    outlineParser()->addMember(name.data(), arg.data(), dir.data(), l, l, EntryType::makeVariable(), TypeSpecifier().setValue(true), "", Protection::Private, 0);
    return;
  }

  if (ctx->variable_port_header())
  {
    parseVariablePortHeader(ctx->variable_port_header(), dir, r);
    dir.append(" ");
    dir.append(r);
    arg = arg.prepend(dim);
    outlineParser()->addMember(name.data(), arg.data(), dir.data(), l, l, EntryType::makeVariable(), TypeSpecifier().setValue(true), "", Protection::Public, 0);
    return;
  }

  if (ctx->LP() && ctx->RP())
  {
    if (ctx->port_direction())
      dir.append(ctx->port_direction()->getText().data());

    outlineParser()->addMember(name.data(), arg.data(), dir.data(), l, l, EntryType::makeVariable(), TypeSpecifier().setValue(true), "", Protection::Public, 0);
    return;
  }

  arg = arg.prepend(dim);
  outlineParser()->addMember(name.data(), arg.data(), dir.data(), l, l, EntryType::makeVariable(), TypeSpecifier().setValue(true), "", Protection::Private, 0);
}

void Expression::enterRef_declaration(SysVerilogParser::Ref_declarationContext *ctx)
{
  Token *tok = ctx->getStart();
  SVP::Variable_port_typeContext *vp = ctx->variable_port_type();
  SVP::Data_typeContext *dc = vp->var_data_type()->data_type();
  SVP::Data_type_or_implicitContext *dic = vp->var_data_type()->data_type_or_implicit();

  String res;
  bool b = false;
  if (dic)
  {
    res.append("var ");
    b = parseDataTypeImpl(dic, res);
  }

  if (dc)
    b = parseDataType(dc, res);

  parseListofVariableIdentifiers(tok->getLine(), b, 0, res.c_str(), ctx->list_of_variable_identifiers(), "| [ ref ]", outlineParser());
}

void Expression::enterPackage_or_generate_item_declaration(SysVerilogParser::Package_or_generate_item_declarationContext *ctx)
{
}

void Expression::enterData_declaration(SVP::Data_declarationContext *ctx)
{
  Token *s = ctx->getStart();
  Token *t = ctx->getStop();
  std::string un, dat;
  int line = s->getLine();
  bool b = checkPath(ctx->parent);
  if (b)
    return;

  SVP::Data_typeContext *dtc = NULL;
  SVP::Net_type_declarationContext *ndc = ctx->net_type_declaration();
  SVP::Data_type_or_implicitContext *doc = ctx->data_type_or_implicit();
  SVP::Net_type_declarationContext *ntc = ctx->net_type_declaration();
  SVP::Package_import_declarationContext *pic = ctx->package_import_declaration();
  SVP::Type_declarationContext *tdc = ctx->type_declaration();
  if (doc)
    dtc = doc->data_type();
  else if (tdc)
    dtc = tdc->data_type();

  if (ndc)
  {
    std::string type, name;

    if (ndc->T_WITH())
    {
      // type = "with ";
      type.append(ndc->ss(1)->getText());
    }

    if (ndc->class_scope())
      type.append(ndc->class_scope()->getText());

    if (ndc->data_type())
      dat = ndc->data_type()->getText();

    std::vector<SVP::SsContext *> vec = ndc->ss();

    if (!vec.empty())
      name.append(ndc->ss(0)->getText());

    outlineParser()->addMember(name.data(), dat.data(), "nettype", line, line, EntryType::makeVariable(), TypeSpecifier().setValue(true), type.data(), Protection::Private, 0);

    return;
  }

  if (pic)
  {
    std::vector<SVP::Package_import_itemContext *> pi = pic->package_import_item();
    for (SVP::Package_import_itemContext *vp : pi)
    {
      std::vector<SVP::SsContext *> n = vp->ss();
      int l = n.size();
      if (l == 0)
        continue;
      QCString id = n.at(0)->getText();

      if (l == 2)
      {
        id.append(".");
        id.append(n.at(1)->getText().data());
      }

      outlineParser()->addMember(id.data(), "", "import", line, line, EntryType::makeVariable(), TypeSpecifier().setValue(true), "import", Protection::Private, 0);
    }
    return;
  }

  if (tdc)
  {
    parseTypeDeclaration(tdc, line, line /*,t->getLine()*/);
    return;
  }

  // checking struct or union
  if (doc && checkStructUnion(dtc, un))
  {
    TypeSpecifier tsp;

    if (un.compare("struct") == 0)
      tsp.setStruct(true);
    else
      tsp.setUnion(true);

    std::string args, qualifier, id;

    if (dtc->T_PACKED())
      qualifier.append("packed ");
    if (dtc->signing())
      qualifier.append(dtc->signing()->getText());

    bool b = parseDataTypeImpl(doc, id);
    SVP::List_of_variable_decl_assignmentsContext *ld = ctx->list_of_variable_decl_assignments();
    std::vector<SVP::Variable_decl_assignmentContext *> lop = ld->variable_decl_assignment();
    SVP::Variable_decl_assignmentContext *c = lop.at(0);
    int ll = 0;
    parseVariableDeclAssignment(b, id, args, c, ll);
    if (ll == 0)
      ll = line;
    outlineParser()->addClass(id.c_str(), line, line, ll, EntryType::makeClass(), tsp, Protection::Public, qualifier.data());
    return;
  }

  if (doc)
  {
    QCString val;

    String id, args, res;
    if (doc->data_type() && dtc->T_ENUM())
    {
      SVP::List_of_variable_decl_assignmentsContext *v1 = ctx->list_of_variable_decl_assignments();
      std::vector<SVP::Variable_decl_assignmentContext *> ju = v1->variable_decl_assignment();
      int line = dtc->getStart()->getLine();

      int i = 1;
      for (SVP::Variable_decl_assignmentContext *c : ju)
      {
        std::string n = c->getText();
        //  std::cout << "enumdecl " << n.data() << "\n";
        if (i == 1)
          parseEnumberation(dtc, outlineParser(), m_sharedState, n, line);
        else
          outlineParser()->addMember(n.data(), "", "@", line, line, EntryType::makeEnum(), TypeSpecifier().setValue(true), "", Protection::Protected, 0);
        i++;
      }
      return;
    }

    std::string re;
    containsTreeType(ctx->parent, SVP::RuleProperty_qualifier, re);

    if (!re.empty())
    {
      val.append(re);
      val.append(" ");
    }

    if (ctx->T_VAR())
      val.append(" var ");

    if (ctx->lifetime())
      val.append(ctx->lifetime()->getText());

    bool b = parseDataTypeImpl(doc, res);
    val.append(res.data());

    SVP::List_of_variable_decl_assignmentsContext *ld = ctx->list_of_variable_decl_assignments();
    std::vector<SVP::Variable_decl_assignmentContext *> lop = ld->variable_decl_assignment();

    for (SVP::Variable_decl_assignmentContext *c : lop)
    {
      b = false;
      int ll = 0;
      parseVariableDeclAssignment(b, id, args, c, ll);
      outlineParser()->addMember(id.data(), args.data(), val.data(), line, line, EntryType::makeVariable(), TypeSpecifier().setValue(true), "", Protection::Public, val.data());
    }
    val.resize(0);

  } //
}

void Expression::enterData_type(SysVerilogParser::Data_typeContext *ctx)
{
}

void Expression::exitData_type(SysVerilogParser::Data_typeContext *ctx)
{
  if (ctx->struct_union())
    m_sharedState->delClassEntry();

  std::string n;
  datType.b = parseDataType(ctx, n);
  datType.arg = n;
}

void Expression::enterStruct_union(SysVerilogParser::Struct_unionContext *ctx)
{
}

// --------------- PROGRAM --------------------

void Expression::enterProgram_declaration(SysVerilogParser::Program_declarationContext *ctx)
{
  Token *s = ctx->getStart();
  Token *t = ctx->getStop();

  std::string lkl = ctx->getText();
  SVP::Program_nonansi_headerContext *pn = ctx->program_nonansi_header();
  std::string cn = pn->ss()->getText();

  outlineParser()->addClass(cn.c_str(), s->getLine(), t->getLine(), EntryType::makeClass(), TypeSpecifier().setProgram(true), Protection::Public, "program");
}
void Expression::exitProgram_declaration(SysVerilogParser::Program_declarationContext *ctx)
{
  m_sharedState->delClassEntry();
}

//  ------ PACKAGE -------------------

void Expression::enterPackage_declaration(SysVerilogParser::Package_declarationContext *ctx)
{
  Token *s = ctx->getStart();
  Token *t = ctx->getStop();

  std::string life;
  std::string cn = ctx->ss(0)->getText();
  std::vector<SVP::SsContext *> ve = ctx->ss();
  if (ctx->lifetime())
    life.append(ctx->lifetime()->getText());
  outlineParser()->addClass(cn.c_str(), s->getLine(), t->getLine(), EntryType::makeClass(), TypeSpecifier().setPackage(true), Protection::Public, "package");
}
void Expression::exitPackage_declaration(SysVerilogParser::Package_declarationContext *ctx)
{
  m_sharedState->delClassEntry();
}

// ---------- INTERFACE CLASS -------------------

void Expression::enterInterface_class_declaration(SysVerilogParser::Interface_class_declarationContext *ctx)
{

  Token *s = ctx->getStart();
  Token *t = ctx->getStop();
  size_t g = s->getLine();

  std::string cn = ctx->ss(0)->getText();
  outlineParser()->addClass(cn.c_str(), s->getLine(), t->getLine(), EntryType::makeClass(), TypeSpecifier().setInterface(true), Protection::Public, "interface");

  for (SVP::Interface_class_itemContext *ici : ctx->interface_class_item())
  {
    if (ici->type_declaration())
    {
      size_t u = ici->getStart()->getLine();
      size_t w = ici->getStop()->getLine();
      parseTypeDeclaration(ici->type_declaration(), u, w);
    }
  }
}

void Expression::exitInterface_class_declaration(SysVerilogParser::Interface_class_declarationContext *ctx)
{
  m_sharedState->delClassEntry();
}

void Expression::enterInterface_declaration(SysVerilogParser::Interface_declarationContext *ctx)
{
  Token *s = ctx->getStart();
  Token *t = ctx->getStop();

  if (ctx->interface_class_declaration())
  {

    // SVP::Interface_class_declarationContext *icd = ctx->interface_class_declaration();
    // std::string cn = icd->ss(0)->getText();
    // outlineParser()->addClass(cn.c_str(), s->getLine(), t->getLine(), EntryType::makeClass(), TypeSpecifier().setInterface(true), Protection::Public, "interface class");
    return;
  }

  SVP::Interface_nonansi_headerContext *in = ctx->interface_nonansi_header();

  std::string cn = in->ss()->getText();

  outlineParser()->addClass(cn.c_str(), s->getLine(), t->getLine(), EntryType::makeClass(), TypeSpecifier().setInterface(true), Protection::Public, "interface");
}

void Expression::exitInterface_declaration(SysVerilogParser::Interface_declarationContext *ctx)
{
  m_sharedState->delClassEntry();
}

// ------------- CHECKER --------------------

void Expression::enterChecker_declaration(SysVerilogParser::Checker_declarationContext *ctx)
{
  Token *s = ctx->getStart();
  Token *t = ctx->getStop();
  std::string cn = ctx->ss(0)->getText();
  std::vector<SVP::SsContext *> ve = ctx->ss();

  outlineParser()->addClass(cn.c_str(), s->getLine(), t->getLine(), EntryType::makeClass(), TypeSpecifier().setChecker(true), Protection::Public, "checker");
}
void Expression::exitChecker_declaration(SysVerilogParser::Checker_declarationContext *ctx)
{
  m_sharedState->delClassEntry();
}

//------------ CLASS -------------------------

void Expression::enterClass_property(SysVerilogParser::Class_propertyContext *ctx)
{
  std::string name, arg, func, n;
  QCString dim;

  if (ctx->data_type())
  {
    func = "const ";
    std::vector<SVP::Class_item_qualifierContext *> vv0 = ctx->class_item_qualifier();
    if (!vv0.empty())
      dim = std::for_each(vv0.cbegin(), vv0.cend(), Sum()).sum;

    func.append(dim.data());

    bool b = parseDataType(ctx->data_type(), n);

    if (ctx->ss())
      name = ctx->ss()->getText();
    else
      name = n;

    if (b)
      func.append(n);

    if (ctx->constant_expression())
    {
      arg = "= ";
      arg += ctx->constant_expression()->getText();
    }
    // std::cout << "record: " << datType.arg.data() << "\n";
    outlineParser()->addMember(name.data(), arg.data(), func.data(), ctx->getStart()->getLine(), ctx->getStart()->getLine(), EntryType::makeVariable(), TypeSpecifier().setDefault(false), "", Protection::Public, 0);
  }
} // class property

void Expression::enterClass_constraint(SysVerilogParser::Class_constraintContext *ctx)
{
  int s = ctx->getStart()->getLine();
  int t = ctx->getStop()->getLine();
  std::string name, type;
  if (ctx->constraint_declaration())
  {
    SVP::Constraint_declarationContext *cd = ctx->constraint_declaration();
    if (cd->T_STATIC())
      type = "static ";
    type.append("constraint");
    name = cd->ss()->getText();
    outlineParser()->addMember(name.data(), "", type.data(), s, t, EntryType::makeVariable(), TypeSpecifier().setDefault(false), "", Protection::Public, 0);
    return;
  }

  SVP::Constraint_prototypeContext *cp = ctx->constraint_prototype();
  if (cp->constraint_prototype_qualifier())
    type = cp->constraint_prototype_qualifier()->getText();

  if (cp->T_STATIC())
    type.append(" static ");

  type.append(" constraint");
  name = cp->ss()->getText();

  outlineParser()->addMember(name.data(), "", type.data(), s, s, EntryType::makeVariable(), TypeSpecifier().setDefault(false), "", Protection::Public, 0);
}

void Expression::enterCovergroup_declaration(SysVerilogParser::Covergroup_declarationContext *ctx)
{
  std::string event, id;
  int s = ctx->getStart()->getLine();
  int t = ctx->getStop()->getLine();

  if (ctx->coverage_event())
  {
    ParseTree *u = ctx->coverage_event()->children.front();
    treeVec2String(u, event);
  }

  id = ctx->ss(0)->getText();
  m_sharedState->current->initializer << "sfsdf";
  outlineParser()->addMember(id.data(), event.data(), "covergroup", s, t, EntryType::makeVariable(), TypeSpecifier().setDefault(false), "", Protection::Public, "covergroup");
}

void Expression::enterClass_declaration(SysVerilogParser::Class_declarationContext *ctx)
{
  Token *s = ctx->getStart();
  Token *t = ctx->getStop();
  int line = s->getLine();
  int eline = t->getLine();

  std::string cn;
  if (ctx->ss(0))
  {
    cn = ctx->ss(0)->getText();
  }

  std::string name;
  std::string life = (ctx->lifetime() != NULL) ? ctx->lifetime()->getText() : "";
  std::string virt = (ctx->T_VIRTUAL() != NULL) ? "virtual" : "";
  bool ex = (ctx->T_EXTENDS() != NULL);
  bool interf = (ctx->T_IMPLEMENTS() != NULL);

  std::vector<SVP::Class_itemContext *> cu = ctx->class_item();

  outlineParser()->addClass(cn.c_str(), line, eline, EntryType::makeClass(), TypeSpecifier().setLocal(true), Protection::Public, "class");

  if (ex)
  {
    QCString exts = ctx->class_type()->psid()->getText();
    std::shared_ptr<Entry> es = outlineParser()->getLastEntity();
    es->extends.push_back(BaseInfo(exts, Protection::Private, Specifier::Pure));
  }

  if (interf)
  {
    std::shared_ptr<Entry> es = outlineParser()->getLastEntity();
    std::vector<SVP::Interface_class_typeContext *> ict = ctx->interface_class_type();
    for (SVP::Interface_class_typeContext *io : ict)
    {
      QCString exts = io->psid()->getText();
      es->extends.push_back(BaseInfo(exts, Protection::Protected, Specifier::Pure));
    }
  }

  for (SVP::Class_itemContext *cc : cu)
  {

    SVP::Class_methodContext *vm = cc->class_method();
    if (vm)
    {
      // SVP::Class_constructor_prototypeContext *cp = vm->class_constructor_prototype();
      SVP::Class_constructor_declarationContext *cp = vm->class_constructor_declaration();
      SVP::Class_constructor_prototypeContext *pr = vm->class_constructor_prototype();

      if (cp)
      {
        if (cp->class_scope())
          name = cp->class_scope()->getText();
        else
          name = cn;

        QCString arg;
        if (cp->tf_port_list())
        {
          SVP::Tf_port_listContext *tpf = cp->tf_port_list();
          arg = parse_tf_port_item1(tpf, m_sharedState);
        }
        // outlineParser()->addVerilogType(name.c_str(), s->getLine(), s->getLine(), EntryType::makeFunction(), TypeSpecifier().setFinal(true), true, Protection::Protected);
        outlineParser()->addMember(name.data(), arg.data(), "[constructor]", cp->getStart()->getLine(), cp->getStop()->getLine(), EntryType::makeFunction(), TypeSpecifier().setDefault(false), "", Protection::Public, "constructor");
      } // if

      if (pr)
      {
        QCString arg, dim;
        std::string func = "[constructor] extern ";
        std::vector<SVP::Method_qualifierContext *> vv0 = vm->method_qualifier();

        name = cn;
        if (!vv0.empty())
          dim = std::for_each(vv0.cbegin(), vv0.cend(), Sum()).sum;

        func.append(dim.data());
        func.append(" function ");
        if (pr->tf_port_list())
        {
          SVP::Tf_port_listContext *tpf = pr->tf_port_list();
          arg = parse_tf_port_item1(tpf, m_sharedState);
        }
        outlineParser()->addMember(name.data(), arg.data(), func.data(), pr->getStart()->getLine(), pr->getStop()->getLine(), EntryType::makeFunction(), TypeSpecifier().setDefault(false), "", Protection::Public, 0);
      }
    } // if class_item
  } // for
}

void Expression::exitClass_declaration(SysVerilogParser::Class_declarationContext *ctx)
{
  m_sharedState->delClassEntry();
}

// --------- MODULE -----------------

void Expression::enterModule_declaration(SysVerilogParser::Module_declarationContext *ctx)
{
  std::vector<ParseTree *> v = ctx->children;
  SysVerilogParser::Module_nonansi_headerContext *mo = ctx->module_nonansi_header();
  std::string modName;

  Token *s = ctx->getStart();
  Token *t = ctx->getStop();

  if (mo == nullptr)
  {
    modName = ctx->ss(0)->getText();
    outlineParser()->addClass(modName.c_str(), s->getLine(), t->getLine(), EntryType::makeClass(), TypeSpecifier().setModule(true), Protection::Public, "module");
    return;
  }

  SysVerilogParser::LifetimeContext *lif = mo->lifetime();

  // if (lif != nullptr && !lif->isEmpty())
  //  std::cout << "module lifetime  " << lif->getText();

  modName = mo->ss()->getText();

  outlineParser()->addClass(modName.c_str(), s->getLine(), t->getLine(), EntryType::makeClass(), TypeSpecifier().setModule(true), Protection::Public, "module");
}

void Expression::exitModule_declaration(SysVerilogParser::Module_declarationContext *ctx)
{
  m_sharedState->delClassEntry();
}

// -------- SUBROUTINES FUNCTION / TASK -  parameter operation_mode                       = "normal";

void Expression::enterEvent_expression(SysVerilogParser::Event_expressionContext *ctx)
{
  antlr4::misc::Interval iv = ctx->getSourceInterval();
  size_t w = iv.length();
  int i = ctx->getStart()->getTokenIndex();
  int j = ctx->getStop()->getTokenIndex();
  std::string res = vec2string(i, j, com);

  std::shared_ptr<Entry> se = outlineParser()->getLastEntry();
  std::vector<SVP::Event_expressionContext *> ev = ctx->event_expression();
  for (SVP::Event_expressionContext *e : ev)
  {
    for (SVP::ExpressionContext *ep : e->expression())
    {
      struct Argument ar;
      if (ep->expression(0))
        continue;
      ar.name = ep->getText().data();
      se->argList.push_back(ar);
    }
    se->type = res;
  }
}

void Expression::enterAlways_construct(SysVerilogParser::Always_constructContext *ctx)
{
  Token *s = ctx->getStart();
  Token *t = ctx->getStop();

  SVP::Procedural_timing_control_statementContext *p = ctx->statement()->statement_item()->procedural_timing_control_statement();
  if (p)
    p->procedural_timing_control()->event_control();

  QCString name = getProcessNumber();

  // outlineParser()->addMember(name.data(), arg.data(), func.data(), s->getLine(), t->getLine(), EntryType::makeFunction(), TypeSpecifier().setAbstract(virt), "", Protection::Public, 0);
  outlineParser()->addMember(name.data(), "process", "vvv", s->getLine(), t->getLine(), EntryType::makeFunction(), TypeSpecifier().setFinal(true), "", Protection::Public, "function");

  // outlineParser()->addVerilogType(name.data(), s->getLine(), t->getLine(), EntryType::makeFunction(), TypeSpecifier().setFinal(true), false, Protection::Private, "always");
}

void Expression::enterMethod_prototype(SysVerilogParser::Method_prototypeContext *ctq)
{
  std::string name, dat, func;
  bool virt;

  Token *s = ctq->getStart();
  Token *t = ctq->getStop();

  SVP::Function_prototypeContext *ctx = ctq->function_prototype();
  SVP::Task_prototypeContext *tcx = ctq->task_prototype();
  if (ctx)
  {
    getMethodQualifier(ctx->parent->parent, func, virt);
    func.append("function ");

    if (ctx->data_type_or_void())
    {
      parseDataOrVoid(ctx->data_type_or_void(), dat);
      func.append(dat);
    }

    name = ctx->ss()->getText();
    QCString arg;
    if (ctx->tf_port_list())
    {
      arg = parse_tf_port_item1(ctx->tf_port_list(), m_sharedState);
    }

    outlineParser()->addMember(name.data(), arg.data(), func.data(), s->getLine(), t->getLine(), EntryType::makeFunction(), TypeSpecifier().setAbstract(virt), "", Protection::Public, 0);
  } // function_proto

  if (tcx)
  {
    getMethodQualifier(tcx->parent->parent, func, virt);
    func.append(" task ");

    name = tcx->ss()->getText();
    QCString arg;
    if (tcx->tf_port_list())
    {
      arg = parse_tf_port_item1(tcx->tf_port_list(), m_sharedState);
    }

    outlineParser()->addMember(name.data(), arg.data(), func.data(), s->getLine(), t->getLine(), EntryType::makeFunction(), TypeSpecifier().setAbstract(virt), "", Protection::Public, 0);
  }
}

void Expression::enterTask_declaration(SysVerilogParser::Task_declarationContext *ctx)
{
  std::string funcName, type;
  QCString arg;
  std::string clscope;
  Token *s = ctx->getStart();
  size_t po = s->getLine();

  Token *t = ctx->getStop();
  size_t ioo = t->getLine();
  SVP::LifetimeContext *ltc = ctx->lifetime();
  SVP::Task_body_declarationContext *tbd = ctx->task_body_declaration();
  SVP::Tf_port_listContext *tpl = tbd->task_decl()->tf_port_list();

  type = "task ";

  if (ltc)
    type.append(ltc->getText());

  if (tbd->class_scope())
  {
    clscope = tbd->class_scope()->getText();
  }

  if (tbd->DOT())
    funcName = tbd->ss(1)->getText();
  else
    funcName = tbd->ss(0)->getText();

  if (tpl)
  {
    // parse_tf_port_item(tpl, m_sharedState);
    arg = parse_tf_port_item1(tpl, m_sharedState);
  }

  outlineParser()->addMember(funcName.data(), arg.data(), type.data(), s->getLine(), t->getLine(), EntryType::makeFunction(), TypeSpecifier().setValue(true), "", Protection::Public, "task");
}

void Expression::enterFunction_declaration(SysVerilogParser::Function_declarationContext *ctx)
{
  std::string funcName;
  std::string clscope;
  Token *s = ctx->getStart();
  size_t lii = s->getLine();
  Token *t = ctx->getStop();
  SysVerilogParser::LifetimeContext *ltc = ctx->lifetime();
  SysVerilogParser::Function_body_declarationContext *fbd = ctx->function_body_declaration();
  SysVerilogParser::Function_decContext *fdc = fbd->function_dec();
  SysVerilogParser::Tf_port_listContext *tpl = fdc->tf_port_list();
  std::vector<SysVerilogParser::Tf_item_declarationContext *> tpi = fdc->tf_item_declaration();
  std::vector<SysVerilogParser::SsContext *> op = fbd->ss();
  SysVerilogParser::Function_data_type_or_implicitContext *fdii = fbd->function_data_type_or_implicit();

  if (tpl)
  {
    parse_tf_port_item(tpl, m_sharedState);
  }
  else
    parse_tf_port_declaration(tpi, m_sharedState);

  if (fbd->class_scope())
  {
    // funcName = fbd->class_scope()->getText();
    // prepc::replace(funcName,"::","");
    funcName.append(fbd->ss(0)->getText());
  }
  else if (fbd->DOT())
  {
    funcName = fbd->ss(0)->getText();
    funcName.append(".");
    funcName.append(fbd->ss(1)->getText());
  }
  else if (fbd->ss(0))
    funcName = fbd->ss(0)->getText();
  else
    funcName = fdii->getText();

  outlineParser()->addVerilogType(funcName.c_str(), s->getLine(), t->getLine(), EntryType::makeFunction(), TypeSpecifier().setFinal(true), false, Protection::Public, "function");
}

// --------------- STRUCT / UNION

void Expression::enterStruct_union_member(SysVerilogParser::Struct_union_memberContext *ctx)
{
  std::string r, s, t, args;
  Token *tok = ctx->getStart();

  if (ctx->random_qualifier())
  {
    s = ctx->random_qualifier()->getText();
    s.append(" ");
  }

  int l = ctx->getStart()->getLine();
  SVP::Data_type_or_voidContext *cc = ctx->data_type_or_void();

  bool b = parseDataOrVoid(cc, r);
  s.append(r);
  SVP::List_of_variable_decl_assignmentsContext *ld = ctx->list_of_variable_decl_assignments();
  std::vector<SVP::Variable_decl_assignmentContext *> lop = ld->variable_decl_assignment();
  for (SVP::Variable_decl_assignmentContext *vp : lop)
  {
    int ll = 0;
    parseVariableDeclAssignment(b, t, args, vp, ll);
    // std::cout << " found struct member:" << s << " " << args << " " << t << "\n";
    outlineParser()->addMember(t.data(), args.data(), s.data(), l, l, EntryType::makeVariable(), TypeSpecifier().setValue(true), "", Protection::Public, "data");
  }
}

void Expression::visitErrorNode(antlr4::tree::ErrorNode *node)
{
  size_t i = node->getSymbol()->getLine();
  std::cerr << "\n\n error while parsing file:" << fileName << " at line:" << i << " [" << node->getText() << "] \n";
  // exit(0);
}

void Expression::enterNet_declaration(SysVerilogParser::Net_declarationContext *ctx)
{
  Token *tok = ctx->getStart();
  int l = tok->getLine();
  SVP::List_of_net_decl_assignmentsContext *la = ctx->list_of_net_decl_assignments();
  std::vector<SVP::Net_decl_assignmentContext *> vec;
  if (la)
    vec = la->net_decl_assignment();
  std::string name, expr, ntype, ooo;
  if (ctx->net_type())
    ntype = ctx->net_type()->getText() + " ";
  // [ drive_strength | charge_strength ] [ vectored | scalared ] data_type_or_implicit
  bool b = ctx->data_type_or_implicit();

  if (ctx->drive_strength())
    ntype += ctx->drive_strength()->getText() + " ";
  if (ctx->charge_strength())
    ntype.append(ctx->charge_strength()->getText() + " ");
  if (ctx->T_SCALARED())
    ntype.append("scalared ");
  if (ctx->T_VECTORED())
    ntype.append("vectored ");

  if (!b)
  {
    if (!ctx->ss().empty())
    {
      ooo = ctx->ss(0)->getText();
      ntype.append(ooo + " ");
    }
  }

  if (b)
    ntype.append(ctx->data_type_or_implicit()->getText());

  for (SVP::Net_decl_assignmentContext *net : vec)
  {
    name = net->ss()->getText();
    if (net->EQ())
      expr = net->expression()->getText();

    outlineParser()->addMember(name.data(), expr.data(), ntype.data(), l, l, EntryType::makeVariable(), TypeSpecifier().setValue(true), "", Protection::Protected, "Net");
  }
}

void Expression::enterModule_instantiation(SVP::Module_instantiationContext *ctx)
{
  Token *tok = ctx->getStart();
  int l = tok->getLine();
  std::string name, hier, temp;
  std::vector<SVP::Hierarchical_instanceContext *> hc = ctx->hierarchical_instance();
  name = ctx->ss()->getText();
  for (SVP::Hierarchical_instanceContext *hi : hc)
  {
    hier = hi->name_of_instance()->ss()->getText();
    outlineParser()->addMember(hier.data(), "module instantition", name.data(), l, l, EntryType::makeVariable(), TypeSpecifier().setValue(true), "", Protection::Protected, "module instantiation");
  }
}

void Expression::enterNamed_port_connection(SysVerilogParser::Named_port_connectionContext *ctx)
{
  Token *tok = ctx->getStart();
  std::string name;
  if (ctx->ss())
    name = ctx->ss()->getText();

  // std::cout << "named port:" << name << "\n";
}

void Expression::enterInclude_path(SysVerilogParser::Include_pathContext *ctx)
{
  Token *tok = ctx->getStart();
  int l = tok->getLine();
  size_t top = tok->getType();
  std::string inc = ctx->String_literal()->getText();
  prepc::replace(inc, "\"", "");
  std::string res = stripPath(QCString(inc)).data();

  bool am;
  FileDef *fd = outlineParser()->getFileDef();
  // FileDef *fdd = findFileDef(Doxygen::, QCString(res.data()), am);
  FileDef *fdd = findFileDef(Doxygen::inputNameLinkedMap, inc.c_str(), am);
  // std::string qc = showFileDefMatches(Doxygen::inputNameLinkedMap, QCString(inc)).data();
  if (fd)
  {
    fd->addIncludeDependency(fdd, inc.c_str(), IncludeKind::ImportModule);
  }
}

void Expression::enterLibrary_description(SysVerilogParser::Library_descriptionContext *ctx)
{
  Token *tok = ctx->getStart();
  int l = tok->getLine();
  std::string name, hier, temp;
  if (ctx->T_INCLUDEDIR())
  {
    temp = ctx->String_literal(0)->getText();
    prepc::replace(temp, "\"", "");
    // res=getFileFromPath(temp);
    std::string res = stripPath(QCString(temp)).data();
    /*
        size_t i = temp.find_last_of("/");
        if (i != string::npos)
          temp=temp.substr(i+1);
    */

    FileDef *fd = outlineParser()->getFileDef();
    std::string vl = fd->getDefFileName().data();
    QCString oo = res.data();
    bool am;
    // FileDef *fdd = findFileDef(Doxygen::, QCString(res.data()), am);
    FileDef *fdd = findFileDef(Doxygen::inputNameLinkedMap, res.c_str(), am);

    std::string qcc = showFileDefMatches(Doxygen::inputNameLinkedMap, oo).data();
    std::string sp = findFilePath(oo, am).data();

    if (fd)
    {
      fd->addIncludeDependency(NULL, QCString(res), IncludeKind::ImportModule);
    }

    //  QCString name = getProcessNumber();
    //  outlineParser()->addMember(res.data(), "include11", res.data(), l, l, EntryType::makeInclude(), TypeSpecifier().setValue(true), "", Protection::Protected, "include");
  }
}

void Expression::enterEveryRule(antlr4::ParserRuleContext *ctx)
{
#if 0
  Token *tok = ctx->getStart();
   std::string s=tok->getText();
  parseHiddenTokens(tok);

  Token *tok = ctx->getStart();
  int l = tok->getLine();
  TVec vv = getHiddenTokens(tok, 2);
  std::string s = ctx->getText();
  std::string res = vec2string(vv);
  std::cout << "---" << s << "---\n";
  if (ctx->getTreeType() == ParseTreeType::RULE)
  {
    RuleContext *rc = (RuleContext *)ctx;
    std::cout << "\n..{" << res << "} ...\n";
    std::cout << "rule index: " << rc->getText() << "{" << tok->getType() << "}\n";
    // if (rc->getRuleIndex() == 579)
    //  std::cout << " SS: " << t->getText() << "\n";
  }
#endif
}

void Expression::visitTerminal(antlr4::tree::TerminalNode *node)
{
  Token *tok = node->getSymbol();
  std::string s = tok->getText();
  // std::cout<<"terminal: "<<s<<" beginline:"<<tok->getLine()<<"\n";
  parseHiddenTokens(tok);
}