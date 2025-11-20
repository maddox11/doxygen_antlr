
// Generated from SysVerilogLexer.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  SysVerilogLexer : public antlr4::Lexer {
public:
  enum {
    Macro_directive = 1, LP = 2, RP = 3, LC = 4, RC = 5, LB = 6, RB = 7, 
    SEMI = 8, COMMA = 9, DOT = 10, COLONCOLON = 11, ATSTAR = 12, COLON = 13, 
    MINUS = 14, STAR = 15, MINUSMINS = 16, NOT = 17, NE = 18, NEQ = 19, 
    NEE = 20, DPI = 21, DPIC = 22, P = 23, PP = 24, PMP = 25, PEP = 26, 
    DOLLAR = 27, DERROR = 28, DFATAL = 29, DINFO = 30, DROOT = 31, DUNIT = 32, 
    DWARNING = 33, PER = 34, PE = 35, AND = 36, ANDAND = 37, ANDANDAND = 38, 
    AE = 39, SS = 40, SCCS = 41, SEQ = 42, SGT = 43, DOTSTAR = 44, SLASH = 45, 
    SLASHEQ = 46, MCOLON = 47, COLONSLASH = 48, COLONEQ = 49, QUES = 50, 
    AT = 51, ATAT = 52, QUOTE = 53, CARET = 54, CARETSQUIG = 55, CARETEQ = 56, 
    BAR = 57, BARBAR = 58, BAREQ = 59, BAREQGT = 60, BARARROW = 61, SQUIG = 62, 
    SQUIGAND = 63, SQUIGCARET = 64, SQUIGBAR = 65, PLUS = 66, PLUSCOLON = 67, 
    PLUSPLUS = 68, PLUSEQ = 69, LT = 70, LTLT = 71, LTLTLT = 72, LTLTLTEQ = 73, 
    LTLTEQ = 74, LTEQ = 75, LTMINUSGT = 76, EQ = 77, MINUSEQ = 78, EQEQ = 79, 
    EQEQQUEST = 80, EQEQEQ = 81, EQGT = 82, GT = 83, ARROW = 84, GE = 85, 
    GTGT = 86, MINUSGTGT = 87, GTGTEQ = 88, GTGTGT = 89, GTGTGTEQ = 90, 
    T_ONESTEP = 91, T_ACCEPT_ON = 92, T_ALIAS = 93, T_ALWAYS = 94, T_ALWAYS_COMB = 95, 
    T_ALWAYS_FF = 96, T_ALWAYS_LATCH = 97, T_AND = 98, T_ASSERT = 99, T_ASSIGN = 100, 
    T_ASSUME = 101, T_AUTOMATIC = 102, T_BEFORE = 103, T_BEGIN = 104, T_BIND = 105, 
    T_BINS = 106, T_BINSOF = 107, T_BIT = 108, T_BREAK = 109, T_BUF = 110, 
    T_BUFIF0 = 111, T_BUFIF1 = 112, T_BYTE = 113, T_CASE = 114, T_CASEX = 115, 
    T_CASEZ = 116, T_CELL = 117, T_CHANDLE = 118, T_CHECKER = 119, T_CLASS = 120, 
    T_CLOCKING = 121, T_CMOS = 122, T_CONFIG = 123, T_CONST = 124, T_CONSTRAINT = 125, 
    T_CONTEXT = 126, T_CONTINUE = 127, T_COVER = 128, T_COVERGROUP = 129, 
    T_COVERPOINT = 130, T_CROSS = 131, T_DEASSIGN = 132, T_DEFAULT = 133, 
    T_DEFPARAM = 134, T_DESIGN = 135, T_DISABLE = 136, T_DIST = 137, T_DO = 138, 
    T_EDGE = 139, T_ELSE = 140, T_END = 141, T_ENDCASE = 142, T_ENDCHECKER = 143, 
    T_ENDCLASS = 144, T_ENDCLOCKING = 145, T_ENDCONFIG = 146, T_ENDFUNCTION = 147, 
    T_ENDGENERATE = 148, T_ENDGROUP = 149, T_ENDPROGRAM = 150, T_ENDINTERFACE = 151, 
    T_ENDMODULE = 152, T_ENDPACKAGE = 153, T_ENDSEQUENCE = 154, T_ENDSPECIFY = 155, 
    T_ENDTASK = 156, T_ENDPROPERTY = 157, T_ENUM = 158, T_EVENT = 159, T_EVENTUALLY = 160, 
    T_EXPECT = 161, T_EXPORT = 162, T_EXTENDS = 163, T_EXTERN = 164, T_FINAL = 165, 
    T_FIRST_MATCH = 166, T_FOR = 167, T_FORCE = 168, T_FOREACH = 169, T_FOREVER = 170, 
    T_FORK = 171, T_FORKJOIN = 172, T_FUNCTION = 173, T_GENERATE = 174, 
    T_GENVAR = 175, T_GLOBAL = 176, T_HIGHZ0 = 177, T_HIGHZ1 = 178, T_IF = 179, 
    T_IFF = 180, T_IFNONE = 181, T_IGNORE_BINS = 182, T_ILLEGAL_BINS = 183, 
    T_IMPLEMENTS = 184, T_IMPLIES = 185, T_IMPORT = 186, T_INCDIR = 187, 
    T_INCLUDE = 188, T_INITIAL = 189, T_INOUT = 190, T_INPUT = 191, T_INSIDE = 192, 
    T_INSTANCE = 193, T_INTEGER = 194, T_INT = 195, T_INTERCONNECT = 196, 
    T_INTERFACE = 197, T_INTERSECT = 198, T_JOIN = 199, T_JOIN_ANY = 200, 
    T_JOIN_NONE = 201, T_LARGE = 202, T_LET = 203, T_LIBLIST = 204, T_LIBRARY = 205, 
    T_LOCAL = 206, T_LOCALPARAM = 207, T_LOGIC = 208, T_LONGINT = 209, T_MACROMODULE = 210, 
    T_MATCHES = 211, T_MEDIUM = 212, T_MODPORT = 213, T_MODULE = 214, T_NAND = 215, 
    T_NEGEDGE = 216, T_NETTYPE = 217, T_NEW = 218, T_NEXTTIME = 219, T_NMOS = 220, 
    T_NOR = 221, T_NOSHOWCANCELLED = 222, T_NOT = 223, T_NOTIF0 = 224, T_NOTIF1 = 225, 
    T_NULL = 226, T_OPTION = 227, T_OR = 228, T_OUTPUT = 229, T_PACKAGE = 230, 
    T_PACKED = 231, T_PARAMETER = 232, T_PATHPULSE = 233, T_PMOS = 234, 
    T_POSEDGE = 235, T_PRIORITY = 236, T_PROGRAM = 237, T_PROPERTY = 238, 
    T_PROTECTED = 239, T_PULL0 = 240, T_PULL1 = 241, T_PULLDOWN = 242, T_PULLUP = 243, 
    T_PULSESTYLE_ONDETECT = 244, T_PULSESTYLE_ONEVENT = 245, T_PURE = 246, 
    T_RAND = 247, T_RANDC = 248, T_RANDCASE = 249, T_RANDOMIZE = 250, T_RANDSEQUENCE = 251, 
    T_RCMOS = 252, T_REAL = 253, T_REALTIME = 254, T_REF = 255, T_REG = 256, 
    T_REJECT_ON = 257, T_RELEASE = 258, T_REPEAT = 259, T_RESTRICT = 260, 
    T_RETURN = 261, T_RNMOS = 262, T_RPMOS = 263, T_RTRAN = 264, T_RTRANIF0 = 265, 
    T_RTRANIF1 = 266, T_S_ALWAYS = 267, T_S_EVENTUALLY = 268, T_S_NEXTTIME = 269, 
    T_S_UNTIL = 270, T_S_UNTIL_WITH = 271, T_SCALARED = 272, T_SEQUENCE = 273, 
    T_SHORTINT = 274, T_SHORTREAL = 275, T_SHOWCANCELLED = 276, T_SIGNED = 277, 
    T_SMALL = 278, T_SOFT = 279, T_SOLVE = 280, T_SPECIFY = 281, T_SPECPARAM = 282, 
    T_STATIC = 283, T_STRING = 284, T_STRONG = 285, T_STRONG0 = 286, T_STRONG1 = 287, 
    T_STRUCT = 288, T_SUPER = 289, T_SUPPLY0 = 290, T_SUPPLY1 = 291, T_SYNC_ACCEPT_ON = 292, 
    T_SYNC_REJECT_ON = 293, T_TAGGED = 294, T_TASK = 295, T_THIS = 296, 
    T_THROUGHOUT = 297, T_TIME = 298, T_TIMEPRECISION = 299, T_TIMEUNIT = 300, 
    T_TRAN = 301, T_TRANIF0 = 302, T_TRANIF1 = 303, T_TRI = 304, T_TRI0 = 305, 
    T_TRI1 = 306, T_TRIAND = 307, T_TRIOR = 308, T_TRIREG = 309, T_TYPE = 310, 
    T_TYPE_OPTION = 311, T_TYPEDEF = 312, T_UNION = 313, T_UNIQUE = 314, 
    T_UNIQUE0 = 315, T_UNSIGNED = 316, T_UNTIL = 317, T_UNTIL_WITH = 318, 
    T_UNTYPED = 319, T_USE = 320, T_UWIRE = 321, T_VAR = 322, T_VECTORED = 323, 
    T_VIRTUAL = 324, T_VOID = 325, T_WAIT = 326, T_WAIT_ORDER = 327, T_WAND = 328, 
    T_WEAK = 329, T_WEAK0 = 330, T_WEAK1 = 331, T_WHILE = 332, T_WILDCARD = 333, 
    T_WIRE = 334, T_WITH = 335, T_WITHIN = 336, T_WOR = 337, T_XNOR = 338, 
    T_XOR = 339, T_SETUP = 340, T_HOLD = 341, T_SETUPHOLD = 342, T_RECOVERY = 343, 
    T_RECREM = 344, T_SKEW = 345, T_TIMESKEW = 346, T_FULLSKEW = 347, T_PERIOD = 348, 
    T_WIDTH = 349, T_NOCHANGE = 350, T_REMOVAL = 351, T_TIMESCALE = 352, 
    T_CELLDEF = 353, T_ENDCELL = 354, T_LINE = 355, T_BEGINKEY = 356, T_ENDKEY = 357, 
    T_UNCONN = 358, T_NOUNCON = 359, T_PRAGMA = 360, T_ACCEL = 361, T_NOACC = 362, 
    T_USELIB = 363, T_DEFNET = 364, T_DEFDEC = 365, T_DEFTRI = 366, T_DELMOD = 367, 
    T_DELMODDIS = 368, T_DELMODUNIT = 369, T_DELMODZERO = 370, T_PROT = 371, 
    T_DISPORT = 372, T_ENPORT = 373, T_NOSUPP = 374, T_ENDPROT = 375, T_ENDPROTED = 376, 
    T_EXP = 377, T_NOEXP = 378, T_PROTECTE = 379, T_AUTO = 380, T_REMGATE = 381, 
    T_NONET = 382, T_RENET = 383, T_SIG = 384, T_UNSIG = 385, T_IFDEF = 386, 
    T_IFNDEF = 387, T_ENDIF = 388, T_UNDEF = 389, TT_ELSE = 390, T_ELSIF = 391, 
    T_INCLUDEDIR = 392, T_POUND = 393, Decimal_number = 394, Octal_number = 395, 
    Binary_number = 396, Hex_number = 397, Realnumber = 398, UNLIT = 399, 
    String_literal = 400, Integer = 401, Time_literal = 402, NEWLINE = 403, 
    WS = 404, Attribute_instance = 405, Block_comment = 406, Out_line_comment = 407, 
    One_line_comment = 408, Simple_identifier = 409, System_identifier = 410, 
    Escape_identifier = 411, Define = 412, Macro = 413, MacroId = 414
  };

  explicit SysVerilogLexer(antlr4::CharStream *input);

  ~SysVerilogLexer() override;


    void doLineCount()
    { 
     /* 
      if((ipc%200)==0){
      std::cout<<"parsing line::"<<ipc<<"\n";
       }
      */
      ipc++;
    }
   


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  void action(antlr4::RuleContext *context, size_t ruleIndex, size_t actionIndex) override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
  int ipc=0; 

  // Individual action functions triggered by action() above.
  void NEWLINEAction(antlr4::RuleContext *context, size_t actionIndex);

  // Individual semantic predicate functions triggered by sempred() above.

};

