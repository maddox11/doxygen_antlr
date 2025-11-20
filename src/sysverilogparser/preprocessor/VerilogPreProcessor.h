#ifndef VERILOGPREPROCESSOR_H
#define VERILOGPREPROCESSOR_H
#include "JavaCC.h"
#include "CharStream.h"
#include "Token.h"
#include "TokenManager.h"
#include "PrepParser.h"
#include "VerilogPreProcessorConstants.h"
#include "ErrorHandler.h"
namespace prepc {
  struct JJCalls {
    int        gen;
    int        arg;
    JJCalls*   next;
    Token*     first;
    ~JJCalls() { if (next) delete next; }
     JJCalls() { next = nullptr; arg = 0; gen = -1; first = nullptr; }
  };

class VerilogPreProcessor {
public:
void source_text();
bool parse_macro(DefMacro *df);
void list_of_items(DefMacro *df);
std   ::string list_of_params();
void item(DefMacro *df);
std   ::string equ_item();
Token     * item_filter();
void macro_extension();
 inline bool jj_2_1(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_1() || jj_done);
 { jj_save(0, xla); }
  }

 inline bool jj_2_2(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_2() || jj_done);
 { jj_save(1, xla); }
  }

 inline bool jj_2_3(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_3() || jj_done);
 { jj_save(2, xla); }
  }

 inline bool jj_2_4(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_4() || jj_done);
 { jj_save(3, xla); }
  }

 inline bool jj_2_5(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_5() || jj_done);
 { jj_save(4, xla); }
  }

 inline bool jj_2_6(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_6() || jj_done);
 { jj_save(5, xla); }
  }

 inline bool jj_2_7(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_7() || jj_done);
 { jj_save(6, xla); }
  }

 inline bool jj_2_8(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_8() || jj_done);
 { jj_save(7, xla); }
  }

 inline bool jj_2_9(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_9() || jj_done);
 { jj_save(8, xla); }
  }

 inline bool jj_2_10(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_10() || jj_done);
 { jj_save(9, xla); }
  }

 inline bool jj_2_11(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_11() || jj_done);
 { jj_save(10, xla); }
  }

 inline bool jj_2_12(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_12() || jj_done);
 { jj_save(11, xla); }
  }

 inline bool jj_2_13(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_13() || jj_done);
 { jj_save(12, xla); }
  }

 inline bool jj_2_14(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_14() || jj_done);
 { jj_save(13, xla); }
  }

 inline bool jj_2_15(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_15() || jj_done);
 { jj_save(14, xla); }
  }

 inline bool jj_2_16(int xla)
 {
    jj_la = xla; jj_lastpos = jj_scanpos = token;
    jj_done = false;
    return (!jj_3_16() || jj_done);
 { jj_save(15, xla); }
  }

 inline bool jj_3R_macro_extension_325_54_38()
 {
    if (jj_done) return true;
    if (jj_3R_macro_extension_309_4_15()) return true;
    return false;
  }

 inline bool jj_3R_equ_item_248_128_28()
 {
    if (jj_done) return true;
    if (jj_scan_token(STRING)) return true;
    return false;
  }

 inline bool jj_3R_equ_item_248_30_14()
 {
    if (jj_done) return true;
    Token * xsp;
    xsp = jj_scanpos;
    if (jj_3R_equ_item_248_30_25()) {
    jj_scanpos = xsp;
    if (jj_3R_equ_item_248_62_26()) {
    jj_scanpos = xsp;
    if (jj_3R_equ_item_248_94_27()) {
    jj_scanpos = xsp;
    if (jj_3R_equ_item_248_128_28()) {
    jj_scanpos = xsp;
    if (jj_3R_equ_item_248_163_29()) {
    jj_scanpos = xsp;
    if (jj_3R_equ_item_248_198_30()) {
    jj_scanpos = xsp;
    if (jj_3R_equ_item_248_230_31()) return true;
    }
    }
    }
    }
    }
    }
    return false;
  }

 inline bool jj_3R_equ_item_248_30_25()
 {
    if (jj_done) return true;
    if (jj_scan_token(COM)) return true;
    return false;
  }

 inline bool jj_3R_equ_item_236_137_21()
 {
    if (jj_done) return true;
    if (jj_scan_token(STRING)) return true;
    return false;
  }

 inline bool jj_3_13()
 {
    if (jj_done) return true;
    if (jj_3R_macro_extension_309_4_15()) return true;
    return false;
  }

 inline bool jj_3R_equ_item_236_39_13()
 {
    if (jj_done) return true;
    Token * xsp;
    xsp = jj_scanpos;
    if (jj_3R_equ_item_236_39_18()) {
    jj_scanpos = xsp;
    if (jj_3R_equ_item_236_71_19()) {
    jj_scanpos = xsp;
    if (jj_3R_equ_item_236_103_20()) {
    jj_scanpos = xsp;
    if (jj_3R_equ_item_236_137_21()) {
    jj_scanpos = xsp;
    if (jj_3R_equ_item_236_172_22()) {
    jj_scanpos = xsp;
    if (jj_3R_equ_item_236_207_23()) {
    jj_scanpos = xsp;
    if (jj_3R_equ_item_236_239_24()) return true;
    }
    }
    }
    }
    }
    }
    return false;
  }

 inline bool jj_3R_equ_item_236_39_18()
 {
    if (jj_done) return true;
    if (jj_scan_token(COM)) return true;
    return false;
  }

 inline bool jj_3_6()
 {
    if (jj_done) return true;
    if (jj_scan_token(LP)) return true;
    if (jj_scan_token(RP)) return true;
    return false;
  }

 inline bool jj_3R_equ_item_248_198_30()
 {
    if (jj_done) return true;
    if (jj_scan_token(EQU)) return true;
    return false;
  }

 inline bool jj_3_5()
 {
    if (jj_done) return true;
    if (jj_scan_token(DEFF)) return true;
    Token * xsp;
    if (jj_3R_equ_item_248_30_14()) return true;
    while (true) {
      xsp = jj_scanpos;
      if (jj_3R_equ_item_248_30_14()) { jj_scanpos = xsp; break; }
    }
    if (jj_scan_token(RP)) return true;
    return false;
  }

 inline bool jj_3R_equ_item_236_207_23()
 {
    if (jj_done) return true;
    if (jj_scan_token(EQU)) return true;
    return false;
  }

 inline bool jj_3R_equ_item_248_94_27()
 {
    if (jj_done) return true;
    if (jj_scan_token(DIGIT)) return true;
    return false;
  }

 inline bool jj_3R_equ_item_236_103_20()
 {
    if (jj_done) return true;
    if (jj_scan_token(DIGIT)) return true;
    return false;
  }

 inline bool jj_3_4()
 {
    if (jj_done) return true;
    Token * xsp;
    xsp = jj_scanpos;
    if (jj_scan_token(8)) jj_scanpos = xsp;
    if (jj_scan_token(LP)) return true;
    while (true) {
      xsp = jj_scanpos;
      if (jj_3R_equ_item_236_39_13()) { jj_scanpos = xsp; break; }
    }
    if (jj_scan_token(RP)) return true;
    return false;
  }

 inline bool jj_3R_list_of_params_212_30_17()
 {
    if (jj_done) return true;
    if (jj_scan_token(COMMA)) return true;
    if (jj_scan_token(STRING)) return true;
    return false;
  }

 inline bool jj_3R_parse_macro_202_35_11()
 {
    if (jj_done) return true;
    if (jj_3R_list_of_items_207_3_16()) return true;
    return false;
  }

 inline bool jj_3R_macro_extension_325_5_36()
 {
    if (jj_done) return true;
    if (jj_scan_token(LP)) return true;
    Token * xsp;
    while (true) {
      xsp = jj_scanpos;
      if (jj_3R_macro_extension_325_54_38()) { jj_scanpos = xsp; break; }
    }
    if (jj_scan_token(RP)) return true;
    return false;
  }

 inline bool jj_3R_macro_extension_324_5_35()
 {
    if (jj_done) return true;
    if (jj_scan_token(TIC)) return true;
    return false;
  }

 inline bool jj_3R_item_228_3_39()
 {
    if (jj_done) return true;
    if (jj_scan_token(STRING)) return true;
    return false;
  }

 inline bool jj_3R_macro_extension_320_5_34()
 {
    if (jj_done) return true;
    if (jj_scan_token(DEFF)) return true;
    Token * xsp;
    while (true) {
      xsp = jj_scanpos;
      if (jj_3_13()) { jj_scanpos = xsp; break; }
    }
    if (jj_scan_token(RP)) return true;
    return false;
  }

 inline bool jj_3_16()
 {
    if (jj_done) return true;
    if (jj_scan_token(QSTRING2)) return true;
    return false;
  }

 inline bool jj_3_15()
 {
    if (jj_done) return true;
    if (jj_scan_token(QSTRING)) return true;
    return false;
  }

 inline bool jj_3_14()
 {
    if (jj_done) return true;
    if (jj_scan_token(QSTRING3)) return true;
    return false;
  }

 inline bool jj_3_3()
 {
    if (jj_done) return true;
    if (jj_scan_token(STRING)) return true;
    if (jj_scan_token(EQU)) return true;
    return false;
  }

 inline bool jj_3R_equ_item_248_163_29()
 {
    if (jj_done) return true;
    if (jj_scan_token(COMMA)) return true;
    return false;
  }

 inline bool jj_3R_item_217_3_37()
 {
    if (jj_done) return true;
    Token * xsp;
    xsp = jj_scanpos;
    if (jj_3_2()) {
    jj_scanpos = xsp;
    if (jj_3_3()) {
    jj_scanpos = xsp;
    if (jj_3R_item_228_3_39()) return true;
    }
    }
    return false;
  }

 inline bool jj_3R_macro_extension_310_5_33()
 {
    if (jj_done) return true;
    if (jj_scan_token(STRING)) return true;
    return false;
  }

 inline bool jj_3_2()
 {
    if (jj_done) return true;
    if (jj_scan_token(STRING)) return true;
    if (jj_scan_token(LP)) return true;
    if (jj_3R_list_of_params_212_3_12()) return true;
    if (jj_scan_token(RP)) return true;
    return false;
  }

 inline bool jj_3R_macro_extension_309_4_32()
 {
    if (jj_done) return true;
    Token * xsp;
    xsp = jj_scanpos;
    if (jj_scan_token(7)) {
    jj_scanpos = xsp;
    if (jj_scan_token(18)) {
    jj_scanpos = xsp;
    if (jj_scan_token(12)) {
    jj_scanpos = xsp;
    if (jj_scan_token(2)) {
    jj_scanpos = xsp;
    if (jj_scan_token(1)) {
    jj_scanpos = xsp;
    if (jj_scan_token(6)) return true;
    }
    }
    }
    }
    }
    return false;
  }

 inline bool jj_3R_macro_extension_309_4_15()
 {
    if (jj_done) return true;
    Token * xsp;
    xsp = jj_scanpos;
    if (jj_3R_macro_extension_309_4_32()) {
    jj_scanpos = xsp;
    if (jj_3R_macro_extension_310_5_33()) {
    jj_scanpos = xsp;
    if (jj_3_14()) {
    jj_scanpos = xsp;
    if (jj_3_15()) {
    jj_scanpos = xsp;
    if (jj_3_16()) {
    jj_scanpos = xsp;
    if (jj_3R_macro_extension_320_5_34()) {
    jj_scanpos = xsp;
    if (jj_3R_macro_extension_324_5_35()) {
    jj_scanpos = xsp;
    if (jj_3R_macro_extension_325_5_36()) return true;
    }
    }
    }
    }
    }
    }
    }
    return false;
  }

 inline bool jj_3R_equ_item_236_172_22()
 {
    if (jj_done) return true;
    if (jj_scan_token(COMMA)) return true;
    return false;
  }

 inline bool jj_3R_list_of_params_212_3_12()
 {
    if (jj_done) return true;
    if (jj_scan_token(STRING)) return true;
    Token * xsp;
    while (true) {
      xsp = jj_scanpos;
      if (jj_3R_list_of_params_212_30_17()) { jj_scanpos = xsp; break; }
    }
    return false;
  }

 inline bool jj_3R_equ_item_248_62_26()
 {
    if (jj_done) return true;
    if (jj_scan_token(ALL)) return true;
    return false;
  }

 inline bool jj_3_1()
 {
    if (jj_done) return true;
    if (jj_scan_token(LP)) return true;
    Token * xsp;
    xsp = jj_scanpos;
    if (jj_3R_parse_macro_202_35_11()) jj_scanpos = xsp;
    if (jj_scan_token(RP)) return true;
    return false;
  }

 inline bool jj_3R_equ_item_236_71_19()
 {
    if (jj_done) return true;
    if (jj_scan_token(ALL)) return true;
    return false;
  }

 inline bool jj_3_12()
 {
    if (jj_done) return true;
    if (jj_scan_token(TIC)) return true;
    if (jj_scan_token(DQ)) return true;
    return false;
  }

 inline bool jj_3R_list_of_items_207_3_16()
 {
    if (jj_done) return true;
    if (jj_3R_item_217_3_37()) return true;
    return false;
  }

 inline bool jj_3_7()
 {
    if (jj_done) return true;
    if (jj_3R_macro_extension_309_4_15()) return true;
    return false;
  }

 inline bool jj_3_11()
 {
    if (jj_done) return true;
    if (jj_scan_token(QSTRING3)) return true;
    return false;
  }

 inline bool jj_3R_equ_item_248_230_31()
 {
    if (jj_done) return true;
    if (jj_scan_token(QSTRING3)) return true;
    return false;
  }

 inline bool jj_3_10()
 {
    if (jj_done) return true;
    if (jj_scan_token(QSTRING2)) return true;
    return false;
  }

 inline bool jj_3_9()
 {
    if (jj_done) return true;
    if (jj_scan_token(QSTRING)) return true;
    return false;
  }

 inline bool jj_3_8()
 {
    if (jj_done) return true;
    if (jj_scan_token(COM)) return true;
    return false;
  }

 inline bool jj_3R_equ_item_236_239_24()
 {
    if (jj_done) return true;
    if (jj_scan_token(QSTRING3)) return true;
    return false;
  }


public: 
  void setErrorHandler(ErrorHandler *eh) {
    if (errorHandler) delete errorHandler;
    errorHandler = eh;
  }

  TokenManager *token_source = nullptr;
  CharStream   *jj_input_stream = nullptr;
  /** Current token. */
  Token        *token = nullptr;
  /** Next token. */
  Token        *jj_nt = nullptr;

private: 
  int           jj_ntk;
  JJCalls       jj_2_rtns[17];
  bool          jj_rescan;
  int           jj_gc;
  Token        *jj_scanpos, *jj_lastpos;
  int           jj_la;
  /** Whether we are looking ahead. */
  bool          jj_lookingAhead;
  bool          jj_semLA;
  int           jj_gen;
  int           jj_la1[23];
  ErrorHandler *errorHandler = nullptr;

protected: 
  bool          hasError;

  Token *head; 
public: 
  VerilogPreProcessor(TokenManager *tokenManager);
  virtual ~VerilogPreProcessor();
void ReInit(TokenManager* tokenManager);
void clear();
Token * jj_consume_token(int kind);
bool  jj_scan_token(int kind);
Token * getNextToken();
Token * getToken(int index);
int jj_ntk_f();
private:
  int jj_kind;
  int **jj_expentries;
  int *jj_expentry;
  void jj_add_error_token(int kind, int pos);
protected:
  /** Generate ParseException. */
  virtual void  parseError();
private:
  int  indent;	// trace indentation
  bool trace = false; // trace enabled if true

public:
  bool trace_enabled();
  void enable_tracing();
  void disable_tracing();
  void jj_rescan_token();
  void jj_save(int index, int xla);
PrepParser *m_outlineParser;
  bool bParse=false;
  void setOutlineParser(PrepParser* p)
   {
     m_outlineParser=p;
   }

  PrepParser *outlineParser() const
  {
    return m_outlineParser;
  }

  std::string checkTok()
  {
      Token *tok=getToken(-1);
               return tok->image;
  }

  bool checkMacroDef(Token* t)
  {
      Token *tok=getToken(1);
      int i=t->beginColumn+t->image.length();
      int j=tok->beginColumn;
      // `macro_name () with space
      if(tok->kind==prepc::LP && i!=j)
      {
              std::cout<<"\ncheck tok :"<<t->image<<" | "<<tok->image<<"\n";
              std::cout<<"\ncheck tok :"<<i<<" | "<<j<<"\n\n";

              return true;
      }
      return false;
  }


  bool checkTok(Token* t)
  {
      Token *tok=getToken(1);
    //  std::cout<<"check tok :"<<t->image<<" | "<<tok->image<<"\n"; 

      if(tok->kind==prepc::STRING)
      {
              return true;
      }
      return false;
  }

  void checkMacro(Token *tok)
  {
        outlineParser()->sbb.append(")");
        tok->image=outlineParser()->sbb;
        tok->endLine=tok->beginLine+outlineParser()->countChar(outlineParser()->sbb,'\n');

        if(!outlineParser()->pMM && !outlineParser()->parserOn)
        {
                 tok->image=outlineParser()->sbb;
                 outlineParser()->evalMacro(tok->image,true,tok->beginLine);
                 tok->image="";
        }
  }

private:
  bool jj_done;
};
}
#endif
