/* VerilogPreProcessor.cc */
#include "VerilogPreProcessor.h"
#include "TokenMgrError.h"
namespace prepc {
  unsigned int jj_la1_0[] = {
0xc1ffe,0x100,0xc1ffe,0x4,0x4,0xc1988,0x100,0x100,0x41986,0x41986,0x41986,0x41986,0x41180,0x41180,0x41980,0x4111e,0x80000,0x60,0x410c6,0xc1fee,0x411c6,0x80028,};
  unsigned int jj_la1_1[] = {
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,};
  unsigned int jj_la1_2[] = {
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,};

  /** Constructor with user supplied TokenManager. */




void VerilogPreProcessor::source_text() {Token *tok;
    if (!hasError) {
    while (!hasError) {
      switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
      case EQU:
      case COMMA:
      case LP:
      case RP:
      case TIC:
      case DQ:
      case COM:
      case STRING:
      case QSTRING:
      case QSTRING2:
      case QSTRING3:
      case DIGIT:
      case ALL:
      case DEFF:{
        ;
        break;
        }
      default:
        jj_la1[0] = jj_gen;
        goto end_label_1;
      }
      if (!hasError) {
      tok = item_filter();
      }
      if (!hasError) {
outlineParser()->appString0(tok,false);
      }
    }
    end_label_1: ;
    }
    if (!hasError) {
    jj_consume_token(0);
    }
}


bool VerilogPreProcessor::parse_macro(DefMacro *df) {Token *tok;
    if (!hasError) {
    tok = jj_consume_token(STRING);
    }
    if (!hasError) {
df->mName=tok->image;
         if(checkMacroDef(tok))
             return true;
    }
    if (!hasError) {
    if (jj_2_1(2)) {
      if (!hasError) {

      }
      if (!hasError) {
      jj_consume_token(LP);
      }
      if (!hasError) {
      switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
      case STRING:{
        if (!hasError) {
        list_of_items(df);
        }
        break;
        }
      default:
        jj_la1[1] = jj_gen;
        ;
      }
      }
      if (!hasError) {
      jj_consume_token(RP);
      }
    } else {
      ;
    }
    }
    if (!hasError) {
    while (!hasError) {
      switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
      case EQU:
      case COMMA:
      case LP:
      case RP:
      case TIC:
      case DQ:
      case COM:
      case STRING:
      case QSTRING:
      case QSTRING2:
      case QSTRING3:
      case DIGIT:
      case ALL:
      case DEFF:{
        ;
        break;
        }
      default:
        jj_la1[2] = jj_gen;
        goto end_label_2;
      }
      if (!hasError) {
      tok = item_filter();
      }
      if (!hasError) {
outlineParser()->appString(tok->image);
      }
    }
    end_label_2: ;
    }
return false;
assert(false);
}


void VerilogPreProcessor::list_of_items(DefMacro *df) {
    if (!hasError) {
    item(df);
    }
    if (!hasError) {
    while (!hasError) {
      switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
      case COMMA:{
        ;
        break;
        }
      default:
        jj_la1[3] = jj_gen;
        goto end_label_3;
      }
      if (!hasError) {
      jj_consume_token(COMMA);
      }
      if (!hasError) {
      item(df);
      }
    }
    end_label_3: ;
    }

}


std   ::string VerilogPreProcessor::list_of_params() {Token *t;std::string s;
    if (!hasError) {
    t = jj_consume_token(STRING);
    }
    if (!hasError) {
s=t->image;
    }
    if (!hasError) {
    while (!hasError) {
      switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
      case COMMA:{
        ;
        break;
        }
      default:
        jj_la1[4] = jj_gen;
        goto end_label_4;
      }
      if (!hasError) {
      jj_consume_token(COMMA);
      }
      if (!hasError) {
      t = jj_consume_token(STRING);
      }
      if (!hasError) {
s+=',';s+=t->image;
      }
    }
    end_label_4: ;
    }
return s;
assert(false);
}


void VerilogPreProcessor::item(DefMacro *df) {Token *t,*t1;std::string s="";std::string s1;
    if (jj_2_2(5)) {
      if (!hasError) {
      t = jj_consume_token(STRING);
      }
      if (!hasError) {
      jj_consume_token(LP);
      }
      if (!hasError) {
      s1 = list_of_params();
      }
      if (!hasError) {
      jj_consume_token(RP);
      }
      if (!hasError) {
df->li.emplace_back(s+s1);
      }
    } else if (jj_2_3(2)) {
      if (!hasError) {
      t = jj_consume_token(STRING);
      }
      if (!hasError) {
      jj_consume_token(EQU);
      }
      if (!hasError) {
      switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
      case LP:
      case COM:
      case STRING:
      case QSTRING3:
      case DIGIT:
      case ALL:
      case DEFF:{
        if (!hasError) {
        s = equ_item();
        }
        break;
        }
      default:
        jj_la1[5] = jj_gen;
        ;
      }
      }
      if (!hasError) {
if(s.empty())
      s.append("=");
    df->li.emplace_back(t->image);
    std::pair<std::string,std::string> p(t->image,s);
    df->hm.insert(p);
      }
    } else {
      switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
      case STRING:{
        if (!hasError) {
        t1 = jj_consume_token(STRING);
        }
        if (!hasError) {
df->li.emplace_back(t1->image);
        }
        break;
        }
      default:
        jj_la1[6] = jj_gen;
        jj_consume_token(-1);
        errorHandler->handleParseError(token, getToken(1), __FUNCTION__, this), hasError = true;
      }
    }
}


std   ::string VerilogPreProcessor::equ_item() {Token *t=null;Token *ts=null;std::string s1="";std::string s2="";
    if (jj_2_4(5)) {
      if (!hasError) {
      switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
      case STRING:{
        if (!hasError) {
        t = jj_consume_token(STRING);
        }
        break;
        }
      default:
        jj_la1[7] = jj_gen;
        ;
      }
      }
      if (!hasError) {
      jj_consume_token(LP);
      }
      if (!hasError) {
      while (!hasError) {
        switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
        case EQU:
        case COMMA:
        case COM:
        case STRING:
        case QSTRING3:
        case DIGIT:
        case ALL:{
          ;
          break;
          }
        default:
          jj_la1[8] = jj_gen;
          goto end_label_5;
        }
        switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
        case COM:{
          if (!hasError) {
          ts = jj_consume_token(COM);
          }
          if (!hasError) {
s2.append(ts->image);
          }
          break;
          }
        case ALL:{
          if (!hasError) {
          ts = jj_consume_token(ALL);
          }
          if (!hasError) {
s2.append(ts->image);
          }
          break;
          }
        case DIGIT:{
          if (!hasError) {
          ts = jj_consume_token(DIGIT);
          }
          if (!hasError) {
s2.append(ts->image);
          }
          break;
          }
        case STRING:{
          if (!hasError) {
          ts = jj_consume_token(STRING);
          }
          if (!hasError) {
s2.append(ts->image);
          }
          break;
          }
        case COMMA:{
          if (!hasError) {
          ts = jj_consume_token(COMMA);
          }
          if (!hasError) {
s2.append(ts->image);
          }
          break;
          }
        case EQU:{
          if (!hasError) {
          ts = jj_consume_token(EQU);
          }
          if (!hasError) {
s2.append(ts->image);
          }
          break;
          }
        case QSTRING3:{
          if (!hasError) {
          ts = jj_consume_token(QSTRING3);
          }
          if (!hasError) {
s2.append(ts->image);
          }
          break;
          }
        default:
          jj_la1[9] = jj_gen;
          jj_consume_token(-1);
          errorHandler->handleParseError(token, getToken(1), __FUNCTION__, this), hasError = true;
        }
      }
      end_label_5: ;
      }
      if (!hasError) {
      jj_consume_token(RP);
      }
      if (!hasError) {
std::string res;
      if(t)
        res=t->image;

      res.append("(");
      res.append(s2);
      res.append(")");
      return res;
      }
    } else if (jj_2_5(3)) {
      if (!hasError) {
      t = jj_consume_token(DEFF);
      }
      if (!hasError) {
      while (!hasError) {
        switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
        case COM:{
          if (!hasError) {
          ts = jj_consume_token(COM);
          }
          if (!hasError) {
s2.append(ts->image);
          }
          break;
          }
        case ALL:{
          if (!hasError) {
          ts = jj_consume_token(ALL);
          }
          if (!hasError) {
s2.append(ts->image);
          }
          break;
          }
        case DIGIT:{
          if (!hasError) {
          ts = jj_consume_token(DIGIT);
          }
          if (!hasError) {
s2.append(ts->image);
          }
          break;
          }
        case STRING:{
          if (!hasError) {
          ts = jj_consume_token(STRING);
          }
          if (!hasError) {
s2.append(ts->image);
          }
          break;
          }
        case COMMA:{
          if (!hasError) {
          ts = jj_consume_token(COMMA);
          }
          if (!hasError) {
s2.append(ts->image);
          }
          break;
          }
        case EQU:{
          if (!hasError) {
          ts = jj_consume_token(EQU);
          }
          if (!hasError) {
s2.append(ts->image);
          }
          break;
          }
        case QSTRING3:{
          if (!hasError) {
          ts = jj_consume_token(QSTRING3);
          }
          if (!hasError) {
s2.append(ts->image);
          }
          break;
          }
        default:
          jj_la1[10] = jj_gen;
          jj_consume_token(-1);
          errorHandler->handleParseError(token, getToken(1), __FUNCTION__, this), hasError = true;
        }
        switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
        case EQU:
        case COMMA:
        case COM:
        case STRING:
        case QSTRING3:
        case DIGIT:
        case ALL:{
          ;
          break;
          }
        default:
          jj_la1[11] = jj_gen;
          goto end_label_6;
        }
      }
      end_label_6: ;
      }
      if (!hasError) {
      jj_consume_token(RP);
      }
      if (!hasError) {
std::string res=t->image;
      res.append("(");
      res.append(s2);
      res.append(")");
      return res;
      }
    } else if (jj_2_6(2)) {
      if (!hasError) {
      jj_consume_token(LP);
      }
      if (!hasError) {
      jj_consume_token(RP);
      }
      if (!hasError) {
return "()";
      }
    } else {
      switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
      case COM:
      case STRING:
      case DIGIT:
      case ALL:{
        if (!hasError) {
        while (!hasError) {
          switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
          case DIGIT:{
            if (!hasError) {
            t = jj_consume_token(DIGIT);
            }
            if (!hasError) {
s1.append(t->image);
            }
            break;
            }
          case ALL:{
            if (!hasError) {
            t = jj_consume_token(ALL);
            }
            if (!hasError) {
s1.append(t->image);
            }
            break;
            }
          case STRING:{
            if (!hasError) {
            t = jj_consume_token(STRING);
            }
            if (!hasError) {
s1.append(t->image);
            }
            break;
            }
          case COM:{
            if (!hasError) {
            t = jj_consume_token(COM);
            }
            if (!hasError) {
s1.append(t->image);
            }
            break;
            }
          default:
            jj_la1[12] = jj_gen;
            jj_consume_token(-1);
            errorHandler->handleParseError(token, getToken(1), __FUNCTION__, this), hasError = true;
          }
          switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
          case COM:
          case STRING:
          case DIGIT:
          case ALL:{
            ;
            break;
            }
          default:
            jj_la1[13] = jj_gen;
            goto end_label_7;
          }
        }
        end_label_7: ;
        }
        if (!hasError) {
return s1;
        }
        break;
        }
      case QSTRING3:{
        if (!hasError) {
        t = jj_consume_token(QSTRING3);
        }
        if (!hasError) {
return t->image;
        }
        break;
        }
      default:
        jj_la1[14] = jj_gen;
        jj_consume_token(-1);
        errorHandler->handleParseError(token, getToken(1), __FUNCTION__, this), hasError = true;
      }
    }
assert(false);
}


Token     * VerilogPreProcessor::item_filter() {Token *tok;std::string s="";std::string s1="";Token* t=null;std::string vv;
    switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
    case STRING:{
      if (!hasError) {
      tok = jj_consume_token(STRING);
      }
      if (!hasError) {
return tok;
      }
      break;
      }
    case DIGIT:{
      if (!hasError) {
      tok = jj_consume_token(DIGIT);
      }
      if (!hasError) {
return tok;
      }
      break;
      }
    case EQU:{
      if (!hasError) {
      tok = jj_consume_token(EQU);
      }
      if (!hasError) {
return tok;
      }
      break;
      }
    case ALL:{
      if (!hasError) {
      tok = jj_consume_token(ALL);
      }
      if (!hasError) {
return tok;
      }
      break;
      }
    case COMMA:{
      if (!hasError) {
      tok = jj_consume_token(COMMA);
      }
      if (!hasError) {
return tok;
      }
      break;
      }
    case LP:{
      if (!hasError) {
      tok = jj_consume_token(LP);
      }
      if (!hasError) {
return tok;
      }
      break;
      }
    case RP:{
      if (!hasError) {
      tok = jj_consume_token(RP);
      }
      if (!hasError) {
return tok;
      }
      break;
      }
    default:
      jj_la1[15] = jj_gen;
      if (jj_2_8(2)) {
        if (!hasError) {
        tok = jj_consume_token(COM);
        }
        if (!hasError) {
return tok;
        }
      } else if (jj_2_9(5)) {
        if (!hasError) {
        tok = jj_consume_token(QSTRING);
        }
        if (!hasError) {
return tok;
        }
      } else if (jj_2_10(3)) {
        if (!hasError) {
        tok = jj_consume_token(QSTRING2);
        }
        if (!hasError) {
return tok;
        }
      } else if (jj_2_11(4)) {
        if (!hasError) {
        tok = jj_consume_token(QSTRING3);
        }
        if (!hasError) {
bool b=outlineParser()->checkQ3(tok);
     if(b){tok->image=""; return tok;}

     if(!outlineParser()->pMM && !outlineParser()->parserOn){
         outlineParser()->evalMacro(tok->image,true,tok->beginLine);
         tok->image="";
     }
     return tok;
        }
      } else {
        switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
        case DEFF:{
          if (!hasError) {
bParse=true;outlineParser()->sbb.resize(0);
          }
          if (!hasError) {
          tok = jj_consume_token(DEFF);
          }
          if (!hasError) {
outlineParser()->appStringSkip(tok);
          }
          if (!hasError) {
          while (!hasError) {
            if (jj_2_7(3)) {
              ;
            } else {
              goto end_label_8;
            }
            if (!hasError) {
            macro_extension();
            }
          }
          end_label_8: ;
          }
          if (!hasError) {
          t = jj_consume_token(RP);
          }
          if (!hasError) {
bParse=false;
      checkMacro(tok);
      return tok;
          }
          break;
          }
        default:
          jj_la1[16] = jj_gen;
          if (jj_2_12(2)) {
            if (!hasError) {
            tok = jj_consume_token(TIC);
            }
            if (!hasError) {
            jj_consume_token(DQ);
            }
            if (!hasError) {
tok->image="`\""; return tok;
            }
          } else {
            switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
            case TIC:{
              if (!hasError) {
              tok = jj_consume_token(TIC);
              }
              if (!hasError) {
return tok;
              }
              break;
              }
            case DQ:{
              if (!hasError) {
              tok = jj_consume_token(DQ);
              }
              if (!hasError) {
return tok;
              }
              break;
              }
            default:
              jj_la1[17] = jj_gen;
              jj_consume_token(-1);
              errorHandler->handleParseError(token, getToken(1), __FUNCTION__, this), hasError = true;
            }
          }
        }
      }
    }
assert(false);
}


void VerilogPreProcessor::macro_extension() {Token *t=null;std::string s="";
    switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
    case EQU:
    case COMMA:
    case DQ:
    case COM:
    case DIGIT:
    case ALL:{
      if (!hasError) {
      switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
      case COM:{
        if (!hasError) {
        t = jj_consume_token(COM);
        }
        break;
        }
      case ALL:{
        if (!hasError) {
        t = jj_consume_token(ALL);
        }
        break;
        }
      case DIGIT:{
        if (!hasError) {
        t = jj_consume_token(DIGIT);
        }
        break;
        }
      case COMMA:{
        if (!hasError) {
        t = jj_consume_token(COMMA);
        }
        break;
        }
      case EQU:{
        if (!hasError) {
        t = jj_consume_token(EQU);
        }
        break;
        }
      case DQ:{
        if (!hasError) {
        t = jj_consume_token(DQ);
        }
        break;
        }
      default:
        jj_la1[18] = jj_gen;
        jj_consume_token(-1);
        errorHandler->handleParseError(token, getToken(1), __FUNCTION__, this), hasError = true;
      }
      }
      if (!hasError) {
outlineParser()->appStringSkip(t);
      }
      break;
      }
    case STRING:{
      if (!hasError) {
      t = jj_consume_token(STRING);
      }
      if (!hasError) {
outlineParser()->appStringSkip(t);
                if(checkTok(t))
                   outlineParser()->appStringSkip(" ");
      }
      break;
      }
    default:
      jj_la1[20] = jj_gen;
      if (jj_2_14(2)) {
        if (!hasError) {
        t = jj_consume_token(QSTRING3);
        }
        if (!hasError) {
outlineParser()->appStringSkip(t);
        }
      } else if (jj_2_15(5)) {
        if (!hasError) {
        t = jj_consume_token(QSTRING);
        }
        if (!hasError) {
outlineParser()->appStringSkip(t);
        }
      } else if (jj_2_16(3)) {
        if (!hasError) {
        t = jj_consume_token(QSTRING2);
        }
        if (!hasError) {
outlineParser()->appStringSkip(t);
        }
      } else {
        switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
        case DEFF:{
          if (!hasError) {
          t = jj_consume_token(DEFF);
          }
          if (!hasError) {
outlineParser()->appStringSkip(t);
          }
          if (!hasError) {
          while (!hasError) {
            if (jj_2_13(4)) {
              ;
            } else {
              goto end_label_9;
            }
            if (!hasError) {
            macro_extension();
            }
          }
          end_label_9: ;
          }
          if (!hasError) {
          t = jj_consume_token(RP);
          }
          if (!hasError) {
outlineParser()->appStringSkip(t);
          }
          break;
          }
        case TIC:{
          if (!hasError) {
          t = jj_consume_token(TIC);
          }
          if (!hasError) {
outlineParser()->appStringSkip(t);
          }
          break;
          }
        case LP:{
          if (!hasError) {
          t = jj_consume_token(LP);
          }
          if (!hasError) {
;outlineParser()->appStringSkip(t);
          }
          if (!hasError) {
          while (!hasError) {
            switch ((jj_ntk==-1)?jj_ntk_f():jj_ntk) {
            case EQU:
            case COMMA:
            case LP:
            case TIC:
            case DQ:
            case COM:
            case STRING:
            case QSTRING:
            case QSTRING2:
            case QSTRING3:
            case DIGIT:
            case ALL:
            case DEFF:{
              ;
              break;
              }
            default:
              jj_la1[19] = jj_gen;
              goto end_label_10;
            }
            if (!hasError) {
            macro_extension();
            }
          }
          end_label_10: ;
          }
          if (!hasError) {
          t = jj_consume_token(RP);
          }
          if (!hasError) {
outlineParser()->appStringSkip(t);
          }
          break;
          }
        default:
          jj_la1[21] = jj_gen;
          jj_consume_token(-1);
          errorHandler->handleParseError(token, getToken(1), __FUNCTION__, this), hasError = true;
        }
      }
    }
}


  VerilogPreProcessor::VerilogPreProcessor(TokenManager *tokenManager){
    head = nullptr;
    ReInit(tokenManager);
}
VerilogPreProcessor::~VerilogPreProcessor()
{
  clear();
}

void VerilogPreProcessor::ReInit(TokenManager* tokenManager){
    clear();
    errorHandler = new ErrorHandler();
    hasError = false;
    token_source = tokenManager;
    head = token = new Token();
    token->kind = 0;
    token->next = nullptr;
    jj_lookingAhead = false;
    jj_rescan = false;
    jj_done = false;
    jj_scanpos = jj_lastpos = nullptr;
    jj_gc = 0;
    jj_kind = -1;
    indent = 0;
    trace = false;
    jj_ntk = -1;
    jj_gen = 0;
    for (int i = 0; i < 22; i++) jj_la1[i] = -1;
  }


void VerilogPreProcessor::clear(){
  //Since token manager was generate from outside,
  //parser should not take care of deleting
  //if (token_source) delete token_source;
  if (head) {
    Token *next, *t = head;
    while (t) {
      next = t->next;
      delete t;
      t = next;
    }
  }
  if (errorHandler) {
    delete errorHandler, errorHandler = nullptr;
  }
}


Token * VerilogPreProcessor::jj_consume_token(int kind)  {
    Token *oldToken;
    if ((oldToken = token)->next != nullptr) token = token->next;
    else token = token->next = token_source->getNextToken();
    jj_ntk = -1;
    if (token->kind == kind) {
      jj_gen++;
      if (++jj_gc > 100) {
        jj_gc = 0;
        for (int i = 0; i < 16; i++) {
          JJCalls *c = &jj_2_rtns[i];
          while (c != nullptr) {
            if (c->gen < jj_gen) c->first = nullptr;
            c = c->next;
          }
        }
      }
      return token;
    }
    token = oldToken;
    jj_kind = kind;
    JJString image = kind >= 0 ? tokenImage[kind] : tokenImage[0];
    errorHandler->handleUnexpectedToken(kind, image.substr(1, image.size() - 2), getToken(1), this);
    hasError = true;
    return token;
  }


bool  VerilogPreProcessor::jj_scan_token(int kind){
    if (jj_scanpos == jj_lastpos) {
      jj_la--;
      if (jj_scanpos->next == nullptr) {
        jj_lastpos = jj_scanpos = jj_scanpos->next = token_source->getNextToken();
      } else {
        jj_lastpos = jj_scanpos = jj_scanpos->next;
      }
    } else {
      jj_scanpos = jj_scanpos->next;
    }
    if (jj_rescan) {
      int i = 0; Token *tok = token;
      while (tok != nullptr && tok != jj_scanpos) { i++; tok = tok->next; }
      if (tok != nullptr) jj_add_error_token(kind, i);
    }
    if (jj_scanpos->kind != kind) return true;
    if (jj_la == 0 && jj_scanpos == jj_lastpos) { return jj_done = true; }
    return false;
  }


/** Get the next Token. */

Token * VerilogPreProcessor::getNextToken(){
    if (token->next != nullptr) token = token->next;
    else token = token->next = token_source->getNextToken();
    jj_ntk = -1;
    jj_gen++;
    return token;
  }

/** Get the specific Token. */

Token * VerilogPreProcessor::getToken(int index){
    Token *t = token;
    for (int i = 0; i < index; i++) {
      if (t->next != nullptr) t = t->next;
      else t = t->next = token_source->getNextToken();
    }
    return t;
  }


int VerilogPreProcessor::jj_ntk_f(){
    if ((jj_nt=token->next) == nullptr)
      return (jj_ntk = (token->next=token_source->getNextToken())->kind);
    else
      return (jj_ntk = jj_nt->kind);
  }


  void VerilogPreProcessor::jj_add_error_token(int kind, int pos)  {
  }


 void  VerilogPreProcessor::parseError()   {
      fprintf(stderr, "Parse error at: %d:%d, after token: %s encountered: %s\n", token->beginLine, token->beginColumn, addUnicodeEscapes(token->image).c_str(), addUnicodeEscapes(getToken(1)->image).c_str());
   }


  bool VerilogPreProcessor::trace_enabled()  {
    return trace;
  }


  void VerilogPreProcessor::enable_tracing()  {
  }

  void VerilogPreProcessor::disable_tracing()  {
  }


  void VerilogPreProcessor::jj_rescan_token(){
    jj_rescan = true;
    for (int i = 0; i < 16; i++) {
      JJCalls *p = &jj_2_rtns[i];
      do {
        if (p->gen > jj_gen) {
          jj_la = p->arg; jj_lastpos = jj_scanpos = p->first;
          switch (i) {
            case 0: jj_3_1(); break;
            case 1: jj_3_2(); break;
            case 2: jj_3_3(); break;
            case 3: jj_3_4(); break;
            case 4: jj_3_5(); break;
            case 5: jj_3_6(); break;
            case 6: jj_3_7(); break;
            case 7: jj_3_8(); break;
            case 8: jj_3_9(); break;
            case 9: jj_3_10(); break;
            case 10: jj_3_11(); break;
            case 11: jj_3_12(); break;
            case 12: jj_3_13(); break;
            case 13: jj_3_14(); break;
            case 14: jj_3_15(); break;
            case 15: jj_3_16(); break;
          }
        }
        p = p->next;
      } while (p != nullptr);
    }
    jj_rescan = false;
  }


  void VerilogPreProcessor::jj_save(int index, int xla){
    JJCalls *p = &jj_2_rtns[index];
    while (p->gen > jj_gen) {
      if (p->next == nullptr) { p = p->next = new JJCalls(); break; }
      p = p->next;
    }
    p->gen = jj_gen + xla - jj_la; p->first = token; p->arg = xla;
  }


}
