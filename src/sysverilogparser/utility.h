#ifndef UTILITY_H
#define UTILITY_H

#include <vector>
#include <string>
#include "SysVerilogParser.h"
#include "sharedstate.h"

antlr4::RuleContext* getRule(antlr4::tree::ParseTree* p,int rule );

bool checkRule(antlr4::tree::ParseTree* pt,int rule );

//void xPath( antlr4::tree::ParseTree* pt,std::string & path,std::vector<antlr4::tree::ParseTree *> & res,SysVerilogParser *exe);

bool checkParentToken(size_t index,size_t kind,antlr4::CommonTokenStream *com);

void printRules(std::vector<antlr4::tree::ParseTree*> & vec);

void getMethodQualifier(antlr4::tree::ParseTree* t,std::string & res,bool & virt);

std::string vec2string(int start,int stop,antlr4::CommonTokenStream *com);
std::string vec2string(std::vector<antlr4::Token*>& vec);

void treeVec2String(antlr4::tree::ParseTree *pt, std::string &res);

void deleteAllChars(std::string &s, const char *c);

antlr4::tree::ParseTree* getRuleNode(std::vector<antlr4::tree::ParseTree*> & vec,int rule);
std::string getStructUnionName(antlr4::tree::ParseTree *t);
bool checkStructUnion(SysVerilogParser::Data_typeContext *dc,std::string &);

bool parseDataType(SysVerilogParser::Data_typeContext *dc,std::string & s);
bool parseDataTypeImpl(SysVerilogParser::Data_type_or_implicitContext *dc,std::string & s);
bool parseDataOrVoid(SysVerilogParser::Data_type_or_voidContext *dc,std::string & s);
void parseNet_Port_Header(SysVerilogParser::Net_port_headerContext* np,QCString & v,QCString & w,QCString & type,bool & id);
void parseInterfaceHeader(SysVerilogParser::Interface_port_headerContext* ip,QCString & w);
void parseVariablePortHeader(SysVerilogParser::Variable_port_headerContext* vc,QCString & v,QCString & w);

void parseVariableDeclAssignment(bool &b,std::string & id,std::string & args,SysVerilogParser::Variable_decl_assignmentContext *vc,int & li);
QCString parse_tf_port_item1(SysVerilogParser::Tf_port_listContext *tpl, struct SharedState *sh);
void parse_tf_port_item(SysVerilogParser::Tf_port_listContext *tpl, struct SharedState *sh);
void parseListofVariableIdentifiers(int l, bool ss, const char *r, const char *t, SysVerilogParser::List_of_variable_identifiersContext *liof,const char* dir,VerilogOutlineParser *ol);
void parseListofPortIdentifiers(int l, bool ss, const char *r, const char *t, SysVerilogParser::List_of_port_identifiersContext *liof,const char* dir,VerilogOutlineParser *ol);
void parseListOfParamAssign(SysVerilogParser::List_of_param_assignmentsContext *ctx, VerilogOutlineParser *ol,std::string  type,std::string name);
void parseListOfTypeAssign(SysVerilogParser::List_of_type_assignmentsContext *ctx,VerilogOutlineParser *ol,std::string  type,std::string name);
void parseListOfSpecparamAssign(SysVerilogParser::List_of_specparam_assignmentsContext *ctx,const VerilogOutlineParser *ol,std::string  type,std::string name);
void parseEnumberation(SysVerilogParser::Data_typeContext *dc,VerilogOutlineParser *ol,struct SharedState *sh,std::string & idd,int line);
void eventExpression(std::vector<SysVerilogParser::Event_expressionContext *>& event,struct SharedState *sh);
void printPP(std::vector<antlr4::RuleContext *> & v );
#endif