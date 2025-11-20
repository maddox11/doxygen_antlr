#ifndef SYSVERILOG_H
#define SYSVERILOG_H

#include <iostream>
#include "SysVerilogBaseListener.h"
#include "SysVerilogLexer.h"
#include "SysVerilogParser.h"
#include "antlr4-runtime.h"
#include "entry.h"
#include "verilogcode.h"

void writeSysFile(int l, const char *text,VerilogCodeParser *vc);
void writeMacroID(int l, const char *text,VerilogCodeParser *vc);

class CodeExpression : public SysVerilogBaseListener
{
public:
  antlr4::CommonTokenStream *com;
  SysVerilogParser *exe;
  bool hasError;
  QCString fileName;
 
  CodeExpression(){};
  CodeExpression(antlr4::CommonTokenStream *cs,SysVerilogParser *ex,const QCString &fi):com(cs),exe(ex),fileName(fi){};

  VerilogCodeParser *m_Code = nullptr;
  void setCodeParser(VerilogCodeParser *p) { m_Code = p; }
  VerilogCodeParser *codeParser() const { return m_Code; }
  void printVecToOutput( std::vector<antlr4::Token*> & v,VerilogCodeParser *code);

  void writeText(antlr4::Token *tt, const char *text,bool inLine);
  QCString checkScope(const antlr4::Token* t);
  void clearError() { hasError = false; }
  std::vector<antlr4::Token*>  getComments(antlr4::Token *tok);
  void enterEveryRule(antlr4::ParserRuleContext* ctx); 
  void enterModule_nonansi_header(SysVerilogParser::Module_nonansi_headerContext *ctx);
  void exitEveryRule(antlr4::ParserRuleContext* ctx); 
  void visitTerminal(antlr4::tree::TerminalNode * node) ;
  void visitErrorNode(antlr4::tree::ErrorNode * /*node*/);


};

#endif
