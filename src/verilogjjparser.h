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
	VerilogOutlineParser();
	virtual ~VerilogOutlineParser();
	void parseInput(const QCString &fileName,
					const char *fileBuf,
					const std::shared_ptr<Entry> &root,
					ClangTUParser *clangParser);

	bool needsPreprocessing(const QCString &) const { return TRUE; }
	void handleCommentBlock(const QCString &doc1, int line, bool brief);
	const std::shared_ptr<Entry> getLastEntity();

	void initEntry(Entry *e);
	void newEntry();
	void parsePrototype(const QCString &text);

	void getEntryAtLine(std::shared_ptr<Entry> ce, int line, bool equ);
	void addImport(QCString &fileName, int l, QCString &impName);
	bool checkMultiComment(QCString &qcs, int line);

	void addClass(const char *name, int startLine, int endLine, EntryType section, TypeSpecifier ts, Protection prot, const char *type);
	void addClass(const char *name, int startLine, int bodyLine, int endBodyLine, EntryType section, TypeSpecifier ts, Protection prot, const char *type);
	std::shared_ptr<Entry> getLastEntry();

	void addVerilogType(const char *n, int startLine, int endLine, EntryType section, TypeSpecifier spec, bool isStatic, Protection prot, const char *qual);
	void addMember(const char *n, const char *arg, const char *type, int startLine, int endLine, EntryType section, TypeSpecifier spec, const char *exp, Protection prot, const char *qual);
	void addMacro(const prepc::DefMacro *def, const std::string &co, size_t eline);
	
	void addComment(std::string &str, size_t line, bool brief);
	void insertPendingComments();
	FileDef *getFileDef();
	//void printGreyoutLine(const char *c, int line);

public:
	struct Private;
	std::unique_ptr<Private> p;
};

#endif
	