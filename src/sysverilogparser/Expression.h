#include "SysVerilogBaseListener.h"
#include <iostream>
#include "SysVerilogLexer.h"
#include "SysVerilogParser.h"
#include "antlr4-runtime.h"
#include "entry.h"
#include "verilogcode.h"
#include "sharedstate.h"
#include "PrepParser.h"

using SVP = SysVerilogParser;

class Expression : public SysVerilogBaseListener
{
public:
  antlr4::CommonTokenStream *com;
  SysVerilogParser *exe;
  QCString fileName;
  bool hasError;

  struct dataT
  {
    std::string arg;
    bool b;
  };

  struct dataT datType;

  Expression(antlr4::CommonTokenStream *cs, SysVerilogParser *ex, const QCString &fi) : com(cs), exe(ex), fileName(fi) {};

  VerilogCodeParser *m_Code = nullptr;
  void setCodeParser(VerilogCodeParser *p) { m_Code = p; }
  VerilogCodeParser *codeParser() const { return m_Code; }

  VerilogOutlineParser *m_outlineParser;
  SharedState *m_sharedState;

  void setOutlineParser(VerilogOutlineParser *p) { m_outlineParser = p; }
  VerilogOutlineParser *outlineParser() const { return m_outlineParser; }

  void setSharedState(SharedState *s) { m_sharedState = s; }

  void clearError() { hasError = false; }

  std::string parseHiddenTokens(const antlr4::Token *tok);

  std::vector<antlr4::Token *> getHiddenTokens(antlr4::Token *tok, int c);

  void printTree(antlr4::Token *s, antlr4::Token *t);
  //----------------------------------------------------

  void enterParameter_port_declaration(SVP::Parameter_port_declarationContext *ctx);
  void enterParameter_declaration(SVP::Parameter_declarationContext *ctx);
  void enterLocal_parameter_declaration(SVP::Local_parameter_declarationContext *ctx);
  void enterNet_declaration(SVP::Net_declarationContext *ctx);

  void enterClass_declaration(SVP::Class_declarationContext *ctx);
  void exitClass_declaration(SVP::Class_declarationContext *ctx);
  void enterClass_property(SVP::Class_propertyContext *ctx);
  void enterClass_constraint(SVP::Class_constraintContext *ctx);
  // void enterCovergroup_declaration(SVP::Covergroup_declarationContext *ctx);

  void enterModule_declaration(SVP::Module_declarationContext *ctx);
  void exitModule_declaration(SVP::Module_declarationContext *ctx);

  void enterFunction_declaration(SVP::Function_declarationContext *ctx);
  void enterMethod_prototype(SVP::Method_prototypeContext *ctx);
  void enterTask_declaration(SVP::Task_declarationContext *ctx);

  void enterPort_declaration(SVP::Port_declarationContext *ctx);
  void enterAnsi_port_declaration(SVP::Ansi_port_declarationContext *ctx);

  void enterProgram_declaration(SVP::Program_declarationContext *ctx);
  void exitProgram_declaration(SVP::Program_declarationContext *ctx);

  void enterPackage_declaration(SVP::Package_declarationContext *ctx);
  void exitPackage_declaration(SVP::Package_declarationContext *ctx);

  void enterInterface_class_declaration(SVP::Interface_class_declarationContext *ctx);
  void exitInterface_class_declaration(SVP::Interface_class_declarationContext *ctx);

  void enterChecker_declaration(SVP::Checker_declarationContext *ctx);
  void exitChecker_declaration(SVP::Checker_declarationContext *ctx);

  void enterRef_declaration(SVP::Ref_declarationContext *ctx);

  void enterPackage_or_generate_item_declaration(SVP::Package_or_generate_item_declarationContext *ctx);

  void parseTypeDeclaration(SVP::Type_declarationContext *tdc, int l, int m);

  void enterData_type(SVP::Data_typeContext *ctx);
  void exitData_type(SVP::Data_typeContext *ctx);

  void enterData_declaration(SVP::Data_declarationContext *ctx);

  void enterStruct_union_member(SVP::Struct_union_memberContext *ctx);

  void enterStruct_union(SVP::Struct_unionContext *ctx);

  void enterAlways_construct(SVP::Always_constructContext *ctx);
  void enterEvent_expression(SVP::Event_expressionContext *ctx);

  void enterInclude_path(SVP::Include_pathContext *ctx);

  // void enterNet_declaration(SVP::Net_declarationContext * ctx);

  void enterCovergroup_declaration(SVP::Covergroup_declarationContext *ctx);
  const std::shared_ptr<Entry> getLastEntry();

  void enterLibrary_description(SVP::Library_descriptionContext *ctx);

  void visitErrorNode(antlr4::tree::ErrorNode *node);
  void enterModule_instantiation(SVP::Module_instantiationContext *ctx);
  void enterInterface_declaration(SVP::Interface_declarationContext *ctx);
  void exitInterface_declaration(SVP::Interface_declarationContext *ctx);
  void enterNamed_port_connection(SVP::Named_port_connectionContext *ctx);

  void enterEveryRule(antlr4::ParserRuleContext *ctx);
  void visitTerminal(antlr4::tree::TerminalNode *node);
};
