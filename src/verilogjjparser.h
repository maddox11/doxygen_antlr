#ifndef VERILOGJJPARSER_H
#define VERILOGJJPARSER_H
#include <vector>
#include <memory>
#include <string>

#include "parserintf.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "types.h"
#include "entry.h"
#include "config.h"
#include "util.h"
 #include <list>
 #include <string>
 #include <utility>
 #include <map>
 #include <list>
 #include <cstdarg>
 #include "PrepParser.h"
#include "types.h"
#include "verilogcode.h"

/** \brief Verilog parser using state-based lexical scanning.
 */
class VerilogOutlineParser : public OutlineParserInterface
{
  public:
  enum VerilogKeyWords
	{
	  MODULE=0x1000,

	  PRIMITIVE,
	  COMPONENT, //4100	void addClass(const char *name, int startLine,int endLine, EntryType section,  TypeSpecifier ts, Protection prot,const char *type);

	  PORT,
      PARAMETER, //4102outlineParser()-
	  ALWAYS,          //4103
	  TASK,                //4104
	  OUTPUT,          //4105
	  INPUT,              //4106
	  INOUT,             //4107
	  DEFPARAM,
	  SPECPARAM,
	  GENERATE,
	  INCLUDE,
	  TIME,
	  SIGNAL,
	  LIBRARY,
	  CONFIGURATION

	  };

  public:
    VerilogOutlineParser();
    virtual ~VerilogOutlineParser();
    void parseInput(const QCString &fileName,
                    const char *fileBuf,
                    const std::shared_ptr<Entry> &root,
                    ClangTUParser *clangParser);

    bool needsPreprocessing(const QCString &) const { return TRUE; }
    //std::unique_ptr<Private> getStrunct() { return p.get();}
    void handleCommentBlock(const QCString &doc1, int line,bool brief);
    const std::shared_ptr<Entry>  getLastEntity();
    
	void initEntry(Entry *e);
	void newEntry();
	//void checkCommentBlock(std::shared_ptr<Entry>  &current, const QCString &doc1, int line, bool &needs);
    void parsePrototype(const QCString &text);

	//void addFunc(sVal& s,sVal& s1);
	//void addType(sVal& s, int section,int spec);
	//void addNetType(sVal& s,int spec);
	//void addRegType(sVal& s,int spec);
	//void addParam(sVal& s);
	//void addPort(sVal& s,sVal& dim,int spec);

	//std::string findComment(int l);
	//void checkComment(std::vector<antlr4::Token *> & v,int line);
	

	
   // std::string prepVerilogComment(std::string qcs);
    void getEntryAtLine(std::shared_ptr<Entry> ce,int line,bool equ);
    void addImport(QCString & fileName,int l,QCString & impName);
	bool checkMultiComment(QCString& qcs,int line);

	void addClass(const char *name, int startLine,int endLine, EntryType section,  TypeSpecifier ts, Protection prot,const char *type);
	void addClass(const char *name, int startLine, int bodyLine,int endBodyLine, EntryType section, TypeSpecifier ts, Protection prot, const char *type);
    std::shared_ptr<Entry> getLastEntry();

	void addVerilogType(const char *n, int startLine,int endLine, EntryType section,TypeSpecifier  spec,bool isStatic,Protection prot,const char* qual);
    void addMember(const char *n,const char* arg,const char* type,int startLine,int endLine, EntryType section,TypeSpecifier spec,const char *exp,Protection prot,const char* qual);
    void addMacro(const prepc::DefMacro *def,const std::string & co,size_t eline);
	//void insertMacros(std::map<std::string, prepc::DefMacro *> &, const QCString &file);
    void addComment(std::string & str,size_t line,bool brief);
    void insertPendingComments();
	FileDef* getFileDef();
	void printGreyoutLine(const char* c,int line);
	
   // void addNetType(std::string & type,std::string & pre,std::string & dim,std::string & id,std::string & arr,std::string & expr,int spec,int line);
  public:
    struct Private;
    std::unique_ptr<Private> p;
};

#endif
