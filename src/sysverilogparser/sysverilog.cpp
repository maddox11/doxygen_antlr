
#include <iostream>
#include <list>
#include "antlr4-runtime.h"
#include "SysVerilogLexer.h"
#include "SysVerilogParser.h"
#include "sysverilog.h"
#include "verilogcode.h"
#include "PrepParser.h"
#include "utility.h"
#include "MacroLexer.h"


using namespace antlr4;
using namespace antlr4::tree;
using namespace std;
using SVP = SysVerilogParser;
using TVec = std::vector<antlr4::Token *>;
using TreeVec = std::vector<antlr4::tree::ParseTree *>;

bool inSide = false;
size_t newT, oldT = 0;
QCString className;

void writeMacroID(int l, const char *text,VerilogCodeParser *vc)
{
  CodeExpression e;
  e.setCodeParser(vc);
  antlr4::CommonToken t(54);
  e.writeText(nullptr,text,true);
}


void CodeExpression::writeText(antlr4::Token *tt, const char *text, bool isHidden)
{
  antlr4::ANTLRInputStream input(text);
  MacroLexer lexer(&input);
  std::string tep(text);
  CommonTokenStream tokens(&lexer);
  tokens.fill();
  TVec v = tokens.getTokens();
  int i = v.size();
  bool bf = FALSE;

  for (int j = 0; j < i; j++)
  {
    Token *token = v.at(j);
    // size_t u = token->getChannel();
    size_t u = token->getType();
  
    std::string str = token->getText();

    // new line token '\n'
    if (u == -1)
      continue;

    if (u == MacroLexer::T_DEFINE || u == MacroLexer::T_INCLUDE || u == MacroLexer::System_identifier)
    {
      m_Code->writeVerilogFont("preprocessor", str.c_str());
    }
    else if (u == MacroLexer::MacroId )
    {
      m_Code->codifyMacroString(str);
    }
    else if (u == MacroLexer::NEWLINE)
    {
      m_Code->codifyLines(str.data(), 0, false, false, false);
    }
    else if (u == MacroLexer::Block_comment || u == MacroLexer::One_line_comment)
    {
      m_Code->codifyLines(str.data(), 0, false, true, false);
    }
    else if (u == MacroLexer::Integer || u == MacroLexer::Hex_number || u == MacroLexer::Decimal_number || u == MacroLexer::Binary_number || u == MacroLexer::UNLIT)
    {
      m_Code->writeVerilogFont("vhdllogic", str.c_str());
    }
    else if (u == MacroLexer::String_literal)
    {
      m_Code->writeVerilogFont("keyword", str.c_str());
    }
     else if (u == MacroLexer::Simple_identifier)
    {
     // vc->writeVerilogFont("keyword", str.c_str());
      QCString clScope = checkScope(tt);
      m_Code->codifyWord(str.data(), clScope);
    }
    else
    {
      switch (u)
      {
      case MacroLexer::RC:
      case MacroLexer::LC:
      case MacroLexer::RB:
      case MacroLexer::LB:
      case MacroLexer::RP:
      case MacroLexer::LP:
        m_Code->writeVerilogFont("stringliteral", str.c_str());
        //  vc->codifyWord(str.data(), className);
        break;
      default:
        m_Code->codifyWord(str.data(), className);
      }
    }
  }
}

void writeSysFile(int l, const char *text, VerilogCodeParser *vc)
{

  antlr4::ANTLRInputStream input(text);
  SysVerilogLexer lexer(&input);

  CommonTokenStream tokens(&lexer);
  tokens.fill();
  size_t sl = tokens.size() - 1;

  SysVerilogParser parser(&tokens);

  tree::ParseTree *tree = parser.source_code();

  CodeExpression e = CodeExpression(&tokens, &parser, vc->getFileName());
  e.setCodeParser(vc);
  

  tree::ParseTreeWalker twalk = tree::ParseTreeWalker();

  twalk.walk(&e, tree);
}

std::vector<Token *> CodeExpression::getComments(Token *tok)
{
  return com->getHiddenTokensToLeft(tok->getTokenIndex(),2);
}

void CodeExpression::visitTerminal(antlr4::tree::TerminalNode *node)
{

  QCString clazzScope;
  std::string s = node->getText();
  Token *tok = node->getSymbol();

  std::string n1 = node->parent->getText();
  TreeVec tv = node->parent->children;
  // printRules(tv);
  size_t u = tok->getType();
  size_t l = tok->getTokenIndex();

  if (l == INVALID_INDEX)
    return;

  // print all hidden tokens(comments/definition/ws  etc before token)  
  TVec vec = com->getHiddenTokensToLeft(l, 2);
  printVecToOutput(vec, codeParser());
  if (u == SVP::EOF)
    return;

  writeText(tok, s.data(), false);

}

QCString CodeExpression::checkScope(const antlr4::Token *t)
{
  QCString res;
  if(t==nullptr)
   return "";

  int id = t->getTokenIndex();

  if (id - 4 < 0)
    return res;

  if (com->get(id - 3)->getType() == SVP::COLONCOLON)
  {
    res = com->get(id - 4)->getText().data();
    res.append("::");
  }
  if (com->get(id - 1)->getType() == SVP::COLONCOLON)
  {
    res.append(com->get(id - 2)->getText().data());
  }
  return res;
}

void CodeExpression::enterEveryRule(ParserRuleContext *ctx)
{
  std::string stf = ctx->getText();
  Token *tok = ctx->getStart();
  int id = tok->getTokenIndex();
  int index = ctx->getRuleIndex();
  if (tok->getType() == Token::EOF)
    id--;

  Token *tik = com->get(id + 1);
  size_t u = tok->getType();
  // std::cout << "enter every rule:" << tok->getText() << " -- " << tik->getText() << "\n";
  int zz = tok->getStartIndex();
  //int val = ctx->getStop()->getStopIndex();
  //int valq = ctx->getStop()->getTokenIndex();

  std::string clazz, name, value;

  if (index == SVP::RuleModule_nonansi_header)
  {
    SVP::Module_nonansi_headerContext *mc = (SVP::Module_nonansi_headerContext *)ctx;
   // std::cout << "module name:________" << mc->ss()->getText();
    std::string cl = mc->ss()->getText();
    codeParser()->addClass(cl);
  }

  if (index == SVP::RuleClass_declaration)
  {
    SVP::Class_declarationContext *mc = (SVP::Class_declarationContext *)ctx;
    //std::cout << "enter class name:________" << mc->ss(0)->getText() << " " << tok->getLine() << "\n";
    std::string cl = mc->ss(0)->getText().data();
    codeParser()->addClass(cl);
    if (mc->class_type())
    {
      SVP::Class_typeContext *cp = mc->class_type();
      if (cp->psid())
      {
        clazz = cp->psid()->ss()->getText();
        codeParser()->addBaseClass(clazz);
      }
    }

    if (mc->interface_class_type().size() > 0)
    {
      std::vector<SVP::Interface_class_typeContext *> ic = mc->interface_class_type();
      for (SVP::Interface_class_typeContext *vp : ic)
      {
        clazz = vp->psid()->ss()->getText();
        codeParser()->addBaseClass(clazz);
      }
    }
  }

  if (index == SVP::RulePackage_declaration)
  {
    SVP::Package_declarationContext *mc = (SVP::Package_declarationContext *)ctx;
   // std::cout << "enter package name:________" << mc->ss(0)->getText() << " " << tok->getLine() << "\n";
    std::string cl = mc->ss(0)->getText().data();
    codeParser()->addClass(cl);
  }

  if (index == SVP::RuleStruct_union)
  {
    std::string su = getStructUnionName(ctx->parent);
    codeParser()->addClass(su);
   // std::cout << "found struct union:" << su << "\n";
  }

} // enterEveryRule

void CodeExpression::exitEveryRule(antlr4::ParserRuleContext *ctx)
{
  Token *tok = ctx->getStop();
  int index = ctx->getRuleIndex();
  if (index == SVP::RuleModule_declaration)
  {
    // assert(index==-1);

    SVP::Module_declarationContext *mc = (SVP::Module_declarationContext *)ctx;

   // if (mc->module_nonansi_header())
   //   std::cout << "extit module: " << mc->module_nonansi_header()->ss()->getText() << " " << tok->getLine() << "\n";
    codeParser()->removeClass();
  }

  if (index == SVP::RuleClass_declaration)
  {
    SVP::Class_declarationContext *mc = (SVP::Class_declarationContext *)ctx;
 //   std::cout << "exit class :" << mc->ss(0)->getText() << " " << tok->getLine() << "\n";
    codeParser()->removeClass();
  }

  if (index == SVP::RulePackage_declaration)
  {
    SVP::Package_declarationContext *mc = (SVP::Package_declarationContext *)ctx;
 //   std::cout << "exit package :" << mc->ss(0)->getText() << " " << tok->getLine() << "\n";
    codeParser()->removeClass();
  }

  if (index == SVP::RuleData_type)
  {
    SVP::Data_typeContext *mc = (SVP::Data_typeContext *)ctx;
    if (mc->struct_union())
    {
       codeParser()->removeClass();
    }
  }
}

void CodeExpression::printVecToOutput(std::vector<antlr4::Token *> &v, VerilogCodeParser *code)
{
  for (antlr4::Token *tok : v)
  {
    std::string str = tok->getText();
    size_t u = tok->getType();
    if (u == SVP::NEWLINE)
    {
      code->codifyLines(str.data(), 0, false, false, false);
    }
    else if (u == SVP::T_INCLUDEDIR)
    {
      code->codifyLines(str.data(), 0, true, true, false);
    }
    else if (u == SVP::Out_line_comment)
    {
      prepc::replace(str,prepc::OUTL.data(),"");
      code->codifyLines(str.data(), 0, true, true, false);
    }
    else if (u == SVP::Block_comment || u == SVP::One_line_comment || u == SVP::Out_line_comment)
    {
      prepc::replace(str,prepc::OUTL.data(),"");
      code->codifyLines(str.data(), 0, false, true, false);
    }
    else if (u == SVP::Macro)
    {
       writeText(tok, str.data(), true);
    }
    else if (u == SVP::Define)
    {
      writeText(tok, str.data(), true);
      // code->codifyLines(str.data(), 0, false, true, false);
    }
    else if (u == SVP::MacroId)
    {
      size_t k = str.length() - 6;
      std::string s = str.substr(3, k);
      writeText(tok, s.data(), true);
     }
    else
    {
      code->writeWord(QCString(str.data()));
    }
  }
}

void CodeExpression::enterModule_nonansi_header(SVP::Module_nonansi_headerContext *ctx)
{
  // std::cout<<"module name:"<<ctx->ss()->getText()<<"\n";
}

void CodeExpression::visitErrorNode(antlr4::tree::ErrorNode *node)
{
  Token *tok = node->getSymbol();
  std::string s = node->toStringTree();
  size_t l = tok->getTokenIndex();
  if (l == INVALID_INDEX)
    return;
  TVec vec = com->getHiddenTokensToLeft(l, 2);
  printVecToOutput(vec, codeParser());
  size_t i = node->getSymbol()->getLine();
 // std::cerr << "\n\n error while parsing file:" << fileName << " at line:" << i << " [" << node->getText() << "] \n";
  codeParser()->codifyLines(s.data(), 0, false, true, false);
  // codeParser()->writeWord(QCString(s.data()));
}

#if 0
--code-keyword-color: #008000;
--code-type-keyword-color: #604020;
--code-flow-keyword-color: #E08000;
--code-comment-color: #800000;
--code-preprocessor-color: #806020;
--code-string-literal-color: #000680ff;
--code-char-literal-color: #008080;
--code-xml-cdata-color: black;
--code-vhdl-digit-color: #FF00FF;
--code-vhdl-char-color: #000000;
--code-vhdl-keyword-color: #700070;
--code-vhdl-logic-color: #ff00d4ff;
#endif