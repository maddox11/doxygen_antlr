
// Generated from MacroLexer.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  MacroLexer : public antlr4::Lexer {
public:
  enum {
    LP = 1, RP = 2, LC = 3, RC = 4, LB = 5, RB = 6, SEMI = 7, COMMA = 8, 
    DOT = 9, COLON = 10, MINUS = 11, STAR = 12, NOT = 13, P = 14, DOLLAR = 15, 
    DERROR = 16, DFATAL = 17, DINFO = 18, DROOT = 19, DUNIT = 20, DWARNING = 21, 
    PER = 22, AND = 23, SLASH = 24, QUES = 25, AT = 26, QUOTE = 27, CARET = 28, 
    BAR = 29, SQUIG = 30, PLUS = 31, PLUSCOLON = 32, LT = 33, EQ = 34, GT = 35, 
    T_INCLUDE = 36, T_DEFINE = 37, SSLASH = 38, Decimal_number = 39, Octal_number = 40, 
    Binary_number = 41, Hex_number = 42, Real_number = 43, UNLIT = 44, String_literal = 45, 
    Integer = 46, Time_literal = 47, NEWLINE = 48, WS = 49, Block_comment = 50, 
    Out_line_comment = 51, One_line_comment = 52, Simple_identifier = 53, 
    MacroId = 54, System_identifier = 55, Escape_identifier = 56
  };

  explicit MacroLexer(antlr4::CharStream *input);

  ~MacroLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

