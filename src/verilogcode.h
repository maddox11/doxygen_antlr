#ifndef VERILOGCODE_H
#define VERILOGCODE_H
#include "parserintf.h"
#include "outputlist.h"


class OutputCodeList;
class FileDef;
class MemberDef;
struct Private;
// using namespace verilog::parser;
class VerilogCodeParser : public CodeParserInterface
{
public:
  VerilogCodeParser();
  virtual ~VerilogCodeParser();

  void parseCode(OutputCodeList &codeOutIntf,
                 const QCString &scopeName,
                 const QCString &input,
                 SrcLangExt lang,
                 bool isExampleBlock,
                 const QCString &exampleName = QCString(),
                 const FileDef *fileDef = 0,
                 int startOutputCodeListLine = -1,
                 int endLine = -1,
                 bool inlineFragment = FALSE,
                 const MemberDef *memberDef = 0,
                 bool showLineNumbers = TRUE,
                 const Definition *searchCtx = 0,
                 bool collectXRefs = TRUE);

  QCString &getFileName();
  void resetCodeParserState() {};
  void insertPendingComments();
  void writeVerilogKeyWord(const char *c);
  void writeVerilogFont(const char *s, const char *text);

  void codifyMacroString(std::string &s);
  const MemberDef *findMacroMember(const char *m);
  // const Definition* findMacroMember(int line);
  Define &findMacro(const std::string &f, const QCString &n);

  const QCString *findKeyWord(const char *);
  
  void endCodeLine();

  void startCodeLine();
  void codeFolding(const Definition *d);
 
  void writeIncludeLink(std::string indir);
 
  void writeDigit(const char *);
  void codifyWord(const char *, const QCString &s);
  void codifyWord(const char *s);
  void setCurrentDoc1(QCString &anchor);
  void codifyLines(const char *text, const char *cll, bool undoc, bool comment, bool classLink);
  void nextCodeLine();
  void writeWord(const QCString &word);
  void generateFuncLink(const MemberDef *mdef);
  void generateMemLink(QCString &clName, QCString &memberName);
  // bool writeColoredWord(QCString &word);
  void generateClassOrGlobalLink(const QCString &clName, const QCString &curr_class, bool typeOnly);
  void writeMultiLineCodeLink(
      const char *ref, const char *file,
      const char *anchor, const char *text, Definition *d);
  void addToSearchIndex(const QCString &text);
  bool findKey(const std::string &s);
  bool findSystemKey(const std::string &s);
  bool findDefSet(const std::string &s);
  void writeCodeLink(const Definition *md, QCString tooltip);
  bool addClass(const std::string &cl);
  void addBaseClass(const std::string &cl);
  bool removeClass();
  void writeClassLink(const ClassDef *cd,bool scope);
  std::string getScope(const std::string& cn);
  bool writeDefinitionFromClassScope(const QCString& clazzScope,const QCString& w);
private:
  struct Private;
  std::unique_ptr<Private> p;
};

int countLines(const char *s);


#endif