/* VerilogPreProcessorTokenManager.cc */
#include "VerilogPreProcessorTokenManager.h"
#include "TokenMgrError.h"
namespace prepc {
static const unsigned long long jjbitVec0[] = {
   0x0ULL, 0x0ULL, 0xffffffffffffffffULL, 0xffffffffffffffffULL
};
static const int jjnextStates[] = {
   1, 2, 4, 24, 25, 26, 40, 49, 50, 60, 61, 70, 71, 80, 81, 86, 
   87, 93, 94, 104, 105, 114, 115, 576, 592, 116, 28, 33, 1, 2, 6, 4, 
   15, 16, 17, 29, 30, 32, 35, 36, 38, 96, 97, 107, 108, 118, 119, 585, 
   583, 586, 3, 5, 7, 127, 132, 139, 148, 160, 163, 169, 172, 186, 197, 215, 
   220, 229, 240, 246, 260, 277, 300, 314, 336, 350, 365, 382, 398, 414, 423, 434, 
   450, 468, 476, 496, 510, 526, 539, 544, 551, 564, 575, 48, 59, 69, 79, 85, 
   92, 103, 113, 127, 132, 139, 148, 160, 163, 169, 172, 186, 197, 215, 220, 229, 
   240, 246, 260, 277, 300, 314, 336, 350, 365, 382, 398, 414, 423, 434, 450, 468, 
   476, 496, 510, 526, 539, 544, 551, 564, 575, 591, 14, 19, 22, 24, 43, 44, 
   53, 54, 64, 65, 74, 75, 580, 581, 
};
static JJChar jjstrLiteralChars_0[] = {0};

static JJChar jjstrLiteralChars_1[] = {0x3d, 0};
static JJChar jjstrLiteralChars_2[] = {0x2c, 0};

static JJChar jjstrLiteralChars_3[] = {0x28, 0};
static JJChar jjstrLiteralChars_4[] = {0x29, 0};

static JJChar jjstrLiteralChars_5[] = {0x60, 0};
static JJChar jjstrLiteralChars_6[] = {0x22, 0};
static JJChar jjstrLiteralChars_7[] = {0};
static JJChar jjstrLiteralChars_8[] = {0};
static JJChar jjstrLiteralChars_9[] = {0};
static JJChar jjstrLiteralChars_10[] = {0};
static JJChar jjstrLiteralChars_11[] = {0};

static JJChar jjstrLiteralChars_12[] = {0};
static JJChar jjstrLiteralChars_13[] = {0};
static JJChar jjstrLiteralChars_14[] = {0};
static JJChar jjstrLiteralChars_15[] = {0};
static JJChar jjstrLiteralChars_16[] = {0};
static JJChar jjstrLiteralChars_17[] = {0};
static JJChar jjstrLiteralChars_18[] = {0};
static JJChar jjstrLiteralChars_19[] = {0};
static JJChar jjstrLiteralChars_20[] = {0};
static JJChar jjstrLiteralChars_21[] = {0};
static JJChar jjstrLiteralChars_22[] = {0};
static JJChar jjstrLiteralChars_23[] = {0};
static JJChar jjstrLiteralChars_24[] = {0};
static JJChar jjstrLiteralChars_25[] = {0};

static JJChar jjstrLiteralChars_26[] = {0};
static JJChar jjstrLiteralChars_27[] = {0};
static JJChar jjstrLiteralChars_28[] = {0};
static JJChar jjstrLiteralChars_29[] = {0};
static JJChar jjstrLiteralChars_30[] = {0};
static JJChar jjstrLiteralChars_31[] = {0};
static JJChar jjstrLiteralChars_32[] = {0};
static JJChar jjstrLiteralChars_33[] = {0};
static JJChar jjstrLiteralChars_34[] = {0};
static JJChar jjstrLiteralChars_35[] = {0};
static JJChar jjstrLiteralChars_36[] = {0};
static JJChar jjstrLiteralChars_37[] = {0};
static JJChar jjstrLiteralChars_38[] = {0};
static JJChar jjstrLiteralChars_39[] = {0};

static JJChar jjstrLiteralChars_40[] = {0};
static JJChar jjstrLiteralChars_41[] = {0};
static JJChar jjstrLiteralChars_42[] = {0};
static JJChar jjstrLiteralChars_43[] = {0};
static JJChar jjstrLiteralChars_44[] = {0};
static JJChar jjstrLiteralChars_45[] = {0};
static JJChar jjstrLiteralChars_46[] = {0};
static JJChar jjstrLiteralChars_47[] = {0};
static JJChar jjstrLiteralChars_48[] = {0};
static JJChar jjstrLiteralChars_49[] = {0};
static JJChar jjstrLiteralChars_50[] = {0};
static JJChar jjstrLiteralChars_51[] = {0};
static JJChar jjstrLiteralChars_52[] = {0};
static JJChar jjstrLiteralChars_53[] = {0};

static JJChar jjstrLiteralChars_54[] = {0};
static JJChar jjstrLiteralChars_55[] = {0};
static JJChar jjstrLiteralChars_56[] = {0};
static JJChar jjstrLiteralChars_57[] = {0};
static JJChar jjstrLiteralChars_58[] = {0};
static JJChar jjstrLiteralChars_59[] = {0};
static JJChar jjstrLiteralChars_60[] = {0};
static JJChar jjstrLiteralChars_61[] = {0};
static JJChar jjstrLiteralChars_62[] = {0};
static JJChar jjstrLiteralChars_63[] = {0};
static JJChar jjstrLiteralChars_64[] = {0};
static JJChar jjstrLiteralChars_65[] = {0};
static JJChar jjstrLiteralChars_66[] = {0};
static JJChar jjstrLiteralChars_67[] = {0};

static JJChar jjstrLiteralChars_68[] = {0};
static JJChar jjstrLiteralChars_69[] = {0};
static JJChar jjstrLiteralChars_70[] = {0};
static const JJString jjstrLiteralImages[] = {
jjstrLiteralChars_0, 
jjstrLiteralChars_1, 
jjstrLiteralChars_2, 
jjstrLiteralChars_3, 
jjstrLiteralChars_4, 
jjstrLiteralChars_5, 
jjstrLiteralChars_6, 
jjstrLiteralChars_7, 
jjstrLiteralChars_8, 
jjstrLiteralChars_9, 
jjstrLiteralChars_10, 
jjstrLiteralChars_11, 
jjstrLiteralChars_12, 
jjstrLiteralChars_13, 
jjstrLiteralChars_14, 
jjstrLiteralChars_15, 
jjstrLiteralChars_16, 
jjstrLiteralChars_17, 
jjstrLiteralChars_18, 
jjstrLiteralChars_19, 
jjstrLiteralChars_20, 
jjstrLiteralChars_21, 
jjstrLiteralChars_22, 
jjstrLiteralChars_23, 
jjstrLiteralChars_24, 
jjstrLiteralChars_25, 
jjstrLiteralChars_26, 
jjstrLiteralChars_27, 
jjstrLiteralChars_28, 
jjstrLiteralChars_29, 
jjstrLiteralChars_30, 
jjstrLiteralChars_31, 
jjstrLiteralChars_32, 
jjstrLiteralChars_33, 
jjstrLiteralChars_34, 
jjstrLiteralChars_35, 
jjstrLiteralChars_36, 
jjstrLiteralChars_37, 
jjstrLiteralChars_38, 
jjstrLiteralChars_39, 
jjstrLiteralChars_40, 
jjstrLiteralChars_41, 
jjstrLiteralChars_42, 
jjstrLiteralChars_43, 
jjstrLiteralChars_44, 
jjstrLiteralChars_45, 
jjstrLiteralChars_46, 
jjstrLiteralChars_47, 
jjstrLiteralChars_48, 
jjstrLiteralChars_49, 
jjstrLiteralChars_50, 
jjstrLiteralChars_51, 
jjstrLiteralChars_52, 
jjstrLiteralChars_53, 
jjstrLiteralChars_54, 
jjstrLiteralChars_55, 
jjstrLiteralChars_56, 
jjstrLiteralChars_57, 
jjstrLiteralChars_58, 
jjstrLiteralChars_59, 
jjstrLiteralChars_60, 
jjstrLiteralChars_61, 
jjstrLiteralChars_62, 
jjstrLiteralChars_63, 
jjstrLiteralChars_64, 
jjstrLiteralChars_65, 
jjstrLiteralChars_66, 
jjstrLiteralChars_67, 
jjstrLiteralChars_68, 
jjstrLiteralChars_69, 
jjstrLiteralChars_70, 
};

/** Lexer state names. */
static const JJChar lexStateNames_arr_0[] = 
{0x44, 0x45, 0x46, 0x41, 0x55, 0x4c, 0x54, 0};
static const JJString lexStateNames[] = {
lexStateNames_arr_0, 
};
static const unsigned long long jjtoToken[] = {
   0xc1fffULL, 0x0ULL, 
};
static const unsigned long long jjtoSkip[] = {
   0xff80000000000000ULL, 0x7fULL, 
};

  void  VerilogPreProcessorTokenManager::setDebugStream(FILE *ds){ debugStream = ds; }

 int VerilogPreProcessorTokenManager::jjStopStringLiteralDfa_0(int pos, unsigned long long active0){
   switch (pos)
   {
      default :
         return -1;
   }
}

int  VerilogPreProcessorTokenManager::jjStartNfa_0(int pos, unsigned long long active0){
   return jjMoveNfa_0(jjStopStringLiteralDfa_0(pos, active0), pos + 1);
}

 int  VerilogPreProcessorTokenManager::jjStopAtPos(int pos, int kind){
   jjmatchedKind = kind;
   jjmatchedPos = pos;
   return pos + 1;
}

 int  VerilogPreProcessorTokenManager::jjMoveStringLiteralDfa0_0(){
   switch(curChar)
   {
      case 9:
         return jjStartNfaWithStates_0(0, 57, 594);
      case 10:
         return jjStopAtPos(0, 55);
      case 13:
         return jjStopAtPos(0, 56);
      case 32:
         return jjStartNfaWithStates_0(0, 58, 594);
      case 34:
         return jjStartNfaWithStates_0(0, 6, 595);
      case 40:
         return jjStopAtPos(0, 3);
      case 41:
         return jjStopAtPos(0, 4);
      case 44:
         return jjStopAtPos(0, 2);
      case 61:
         return jjStopAtPos(0, 1);
      case 96:
         return jjStartNfaWithStates_0(0, 5, 14);
      default :
         return jjMoveNfa_0(0, 0);
   }
}

int VerilogPreProcessorTokenManager::jjStartNfaWithStates_0(int pos, int kind, int state){
   jjmatchedKind = kind;
   jjmatchedPos = pos;
   if (input_stream->endOfInput()) { return pos + 1; }
   curChar = input_stream->readChar();
   return jjMoveNfa_0(state, pos + 1);
}

int VerilogPreProcessorTokenManager::jjMoveNfa_0(int startState, int curPos){
   int startsAt = 0;
   jjnewStateCnt = 594;
   int i = 1;
   jjstateSet[0] = startState;
   int kind = 0x7fffffff;
   for (;;)
   {
      if (++jjround == 0x7fffffff)
         ReInitRounds();
      if (curChar < 64)
      {
         unsigned long long l = 1ULL << curChar;
         (void)l;
         do
         {
            switch(jjstateSet[--i])
            {
               case 595:
                  if ((0xfffffffbffffdbffULL & l) != 0L)
                     { jjCheckNAddStates(0, 2); }
                  else if (curChar == 34)
                  {
                     if (kind > 7)
                        kind = 7;
                  }
                  break;
               case 14:
                  if ((0x3ff001000000000ULL & l) != 0L)
                     { jjCheckNAddStates(3, 5); }
                  if (curChar == 36)
                  {
                     if (kind > 11)
                        kind = 11;
                     { jjCheckNAddTwoStates(22, 23); }
                  }
                  break;
               case 594:
                  if ((0x100000200ULL & l) != 0L)
                     { jjCheckNAddTwoStates(576, 592); }
                  if ((0x100000200ULL & l) != 0L)
                     { jjCheckNAddTwoStates(115, 116); }
                  if ((0x100000200ULL & l) != 0L)
                     { jjCheckNAddTwoStates(105, 114); }
                  if ((0x100000200ULL & l) != 0L)
                     { jjCheckNAddTwoStates(94, 104); }
                  if ((0x100000200ULL & l) != 0L)
                     { jjCheckNAddTwoStates(87, 93); }
                  if ((0x100000200ULL & l) != 0L)
                     { jjCheckNAddTwoStates(81, 86); }
                  if ((0x100000200ULL & l) != 0L)
                     { jjCheckNAddTwoStates(71, 80); }
                  if ((0x100000200ULL & l) != 0L)
                     { jjCheckNAddTwoStates(61, 70); }
                  if ((0x100000200ULL & l) != 0L)
                     { jjCheckNAddTwoStates(50, 60); }
                  if ((0x100000200ULL & l) != 0L)
                     { jjCheckNAddTwoStates(40, 49); }
                  break;
               case 0:
                  if ((0xdc00ecfa00000000ULL & l) != 0L)
                  {
                     if (kind > 18)
                        kind = 18;
                  }
                  else if ((0x3ff000000000000ULL & l) != 0L)
                  {
                     if (kind > 12)
                        kind = 12;
                     { jjCheckNAdd(11); }
                  }
                  else if ((0x100000200ULL & l) != 0L)
                     { jjCheckNAddStates(6, 25); }
                  else if (curChar == 34)
                     { jjCheckNAddStates(0, 2); }
                  if (curChar == 47)
                     { jjAddStates(26, 27); }
                  else if (curChar == 36)
                  {
                     if (kind > 8)
                        kind = 8;
                     { jjCheckNAddTwoStates(9, 10); }
                  }
                  break;
               case 1:
                  if ((0xfffffffbffffdbffULL & l) != 0L)
                     { jjCheckNAddStates(0, 2); }
                  break;
               case 3:
                  if ((0x8400000000ULL & l) != 0L)
                     { jjCheckNAddStates(0, 2); }
                  break;
               case 4:
                  if (curChar == 34 && kind > 7)
                     kind = 7;
                  break;
               case 5:
                  if ((0xff000000000000ULL & l) != 0L)
                     { jjCheckNAddStates(28, 31); }
                  break;
               case 6:
                  if ((0xff000000000000ULL & l) != 0L)
                     { jjCheckNAddStates(0, 2); }
                  break;
               case 7:
                  if ((0xf000000000000ULL & l) != 0L)
                     jjstateSet[jjnewStateCnt++] = 8;
                  break;
               case 8:
                  if ((0xff000000000000ULL & l) != 0L)
                     { jjCheckNAdd(6); }
                  break;
               case 9:
                  if (curChar != 36)
                     break;
                  if (kind > 8)
                     kind = 8;
                  { jjCheckNAddTwoStates(9, 10); }
                  break;
               case 10:
                  if ((0x3ff000000000000ULL & l) == 0L)
                     break;
                  if (kind > 8)
                     kind = 8;
                  { jjCheckNAddTwoStates(9, 10); }
                  break;
               case 11:
                  if ((0x3ff000000000000ULL & l) == 0L)
                     break;
                  if (kind > 12)
                     kind = 12;
                  { jjCheckNAdd(11); }
                  break;
               case 12:
                  if ((0xdc00ecfa00000000ULL & l) != 0L && kind > 18)
                     kind = 18;
                  break;
               case 15:
                  if (curChar == 36)
                     { jjCheckNAddStates(32, 34); }
                  break;
               case 16:
                  if ((0x3ff000000000000ULL & l) != 0L)
                     { jjCheckNAddStates(32, 34); }
                  break;
               case 20:
                  if (curChar != 36)
                     break;
                  if (kind > 10)
                     kind = 10;
                  { jjCheckNAddTwoStates(20, 21); }
                  break;
               case 21:
                  if ((0x3ff000000000000ULL & l) == 0L)
                     break;
                  if (kind > 10)
                     kind = 10;
                  { jjCheckNAddTwoStates(20, 21); }
                  break;
               case 22:
                  if (curChar != 36)
                     break;
                  if (kind > 11)
                     kind = 11;
                  { jjCheckNAddTwoStates(22, 23); }
                  break;
               case 23:
                  if ((0x3ff000000000000ULL & l) == 0L)
                     break;
                  if (kind > 11)
                     kind = 11;
                  { jjCheckNAddTwoStates(22, 23); }
                  break;
               case 24:
                  if ((0x3ff001000000000ULL & l) != 0L)
                     { jjCheckNAddStates(3, 5); }
                  break;
               case 25:
                  if ((0x100000600ULL & l) != 0L)
                     { jjCheckNAddTwoStates(25, 26); }
                  break;
               case 26:
                  if (curChar == 40 && kind > 19)
                     kind = 19;
                  break;
               case 27:
                  if (curChar == 47)
                     { jjAddStates(26, 27); }
                  break;
               case 28:
                  if (curChar != 47)
                     break;
                  if (kind > 59)
                     kind = 59;
                  { jjCheckNAddStates(35, 37); }
                  break;
               case 29:
                  if ((0xffffffffffffdbffULL & l) == 0L)
                     break;
                  if (kind > 59)
                     kind = 59;
                  { jjCheckNAddStates(35, 37); }
                  break;
               case 30:
                  if ((0x2400ULL & l) != 0L && kind > 59)
                     kind = 59;
                  break;
               case 31:
                  if (curChar == 10 && kind > 59)
                     kind = 59;
                  break;
               case 32:
                  if (curChar == 13)
                     jjstateSet[jjnewStateCnt++] = 31;
                  break;
               case 33:
                  if (curChar == 42)
                     { jjCheckNAddTwoStates(34, 35); }
                  break;
               case 34:
                  if ((0xfffffbffffffffffULL & l) != 0L)
                     { jjCheckNAddTwoStates(34, 35); }
                  break;
               case 35:
                  if (curChar == 42)
                     { jjCheckNAddStates(38, 40); }
                  break;
               case 36:
                  if ((0xffff7bffffffffffULL & l) != 0L)
                     { jjCheckNAddTwoStates(37, 35); }
                  break;
               case 37:
                  if ((0xfffffbffffffffffULL & l) != 0L)
                     { jjCheckNAddTwoStates(37, 35); }
                  break;
               case 38:
                  if (curChar == 47 && kind > 60)
                     kind = 60;
                  break;
               case 39:
                  if ((0x100000200ULL & l) != 0L)
                     { jjCheckNAddStates(6, 25); }
                  break;
               case 40:
                  if ((0x100000200ULL & l) != 0L)
                     { jjCheckNAddTwoStates(40, 49); }
                  break;
               case 42:
                  if ((0x100000200ULL & l) != 0L)
                     { jjCheckNAddTwoStates(42, 43); }
                  break;
               case 43:
                  if (curChar != 36)
                     break;
                  if (kind > 61)
                     kind = 61;
                  { jjCheckNAddTwoStates(43, 44); }
                  break;
               case 44:
                  if ((0x3ff000000000000ULL & l) == 0L)
                     break;
                  if (kind > 61)
                     kind = 61;
                  { jjCheckNAddTwoStates(43, 44); }
                  break;
               case 50:
                  if ((0x100000200ULL & l) != 0L)
                     { jjCheckNAddTwoStates(50, 60); }
                  break;
               case 52:
                  if ((0x100000200ULL & l) != 0L)
                     { jjCheckNAddTwoStates(52, 53); }
                  break;
               case 53:
                  if (curChar != 36)
                     break;
                  if (kind > 62)
                     kind = 62;
                  { jjCheckNAddTwoStates(53, 54); }
                  break;
               case 54:
                  if ((0x3ff000000000000ULL & l) == 0L)
                     break;
                  if (kind > 62)
                     kind = 62;
                  { jjCheckNAddTwoStates(53, 54); }
                  break;
               case 61:
                  if ((0x100000200ULL & l) != 0L)
                     { jjCheckNAddTwoStates(61, 70); }
                  break;
               case 63:
                  if ((0x100000200ULL & l) != 0L)
                     { jjCheckNAddTwoStates(63, 64); }
                  break;
               case 64:
                  if (curChar != 36)
                     break;
                  if (kind > 63)
                     kind = 63;
                  { jjCheckNAddTwoStates(64, 65); }
                  break;
               case 65:
                  if ((0x3ff000000000000ULL & l) == 0L)
                     break;
                  if (kind > 63)
                     kind = 63;
                  { jjCheckNAddTwoStates(64, 65); }
                  break;
               case 71:
                  if ((0x100000200ULL & l) != 0L)
                     { jjCheckNAddTwoStates(71, 80); }
                  break;
               case 73:
                  if ((0x100000200ULL & l) != 0L)
                     { jjCheckNAddTwoStates(73, 74); }
                  break;
               case 74:
                  if (curChar != 36)
                     break;
                  if (kind > 64)
                     kind = 64;
                  { jjCheckNAddTwoStates(74, 75); }
                  break;
               case 75:
                  if ((0x3ff000000000000ULL & l) == 0L)
                     break;
                  if (kind > 64)
                     kind = 64;
                  { jjCheckNAddTwoStates(74, 75); }
                  break;
               case 81:
                  if ((0x100000200ULL & l) != 0L)
                     { jjCheckNAddTwoStates(81, 86); }
                  break;
               case 87:
                  if ((0x100000200ULL & l) != 0L)
                     { jjCheckNAddTwoStates(87, 93); }
                  break;
               case 94:
                  if ((0x100000200ULL & l) != 0L)
                     { jjCheckNAddTwoStates(94, 104); }
                  break;
               case 96:
                  if ((0xfffffffffffffbffULL & l) != 0L)
                     { jjAddStates(41, 42); }
                  break;
               case 97:
                  if (curChar == 10 && kind > 67)
                     kind = 67;
                  break;
               case 105:
                  if ((0x100000200ULL & l) != 0L)
                     { jjCheckNAddTwoStates(105, 114); }
                  break;
               case 107:
                  if ((0xfffffffffffffbffULL & l) != 0L)
                     { jjAddStates(43, 44); }
                  break;
               case 108:
                  if (curChar == 10 && kind > 68)
                     kind = 68;
                  break;
               case 115:
                  if ((0x100000200ULL & l) != 0L)
                     { jjCheckNAddTwoStates(115, 116); }
                  break;
               case 118:
                  if ((0xfffffffffffffbffULL & l) != 0L)
                     { jjAddStates(45, 46); }
                  break;
               case 119:
                  if (curChar == 10 && kind > 69)
                     kind = 69;
                  break;
               case 576:
                  if ((0x100000200ULL & l) != 0L)
                     { jjCheckNAddTwoStates(576, 592); }
                  break;
               case 578:
                  if ((0x100000200ULL & l) != 0L)
                     { jjCheckNAddTwoStates(578, 579); }
                  break;
               case 579:
                  if ((0x3ff001000000000ULL & l) != 0L)
                     { jjCheckNAddTwoStates(579, 580); }
                  break;
               case 580:
                  if ((0xffffffffffffdbffULL & l) != 0L)
                     { jjCheckNAddTwoStates(580, 581); }
                  break;
               case 582:
                  if (curChar != 10)
                     break;
                  if (kind > 70)
                     kind = 70;
                  { jjCheckNAddTwoStates(583, 584); }
                  break;
               case 584:
                  if ((0xffffffffffffdbffULL & l) == 0L)
                     break;
                  if (kind > 70)
                     kind = 70;
                  { jjCheckNAddStates(47, 49); }
                  break;
               case 585:
                  if ((0xffffffffffffdbffULL & l) != 0L)
                     { jjCheckNAddTwoStates(585, 583); }
                  break;
               case 586:
                  if ((0xffffffffffffdbffULL & l) == 0L)
                     break;
                  if (kind > 70)
                     kind = 70;
                  { jjCheckNAdd(586); }
                  break;
               default : break;
            }
         } while(i != startsAt);
      }
      else if (curChar < 128)
      {
         unsigned long long l = 1ULL << (curChar & 077);
         (void)l;
         do
         {
            switch(jjstateSet[--i])
            {
               case 595:
                  if ((0xffffffffefffffffULL & l) != 0L)
                     { jjCheckNAddStates(0, 2); }
                  else if (curChar == 92)
                     { jjAddStates(50, 52); }
                  break;
               case 14:
                  if ((0x7fffffe87fffffeULL & l) != 0L)
                     { jjCheckNAddStates(3, 5); }
                  else if (curChar == 96)
                     { jjCheckNAdd(20); }
                  if ((0x7fffffe87fffffeULL & l) != 0L)
                  {
                     if (kind > 11)
                        kind = 11;
                     { jjCheckNAddTwoStates(22, 23); }
                  }
                  else if (curChar == 96)
                     { jjCheckNAdd(15); }
                  if (curChar == 100)
                     jjstateSet[jjnewStateCnt++] = 590;
                  else if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 574;
                  else if (curChar == 98)
                     jjstateSet[jjnewStateCnt++] = 563;
                  else if (curChar == 117)
                     jjstateSet[jjnewStateCnt++] = 550;
                  else if (curChar == 115)
                     jjstateSet[jjnewStateCnt++] = 543;
                  else if (curChar == 114)
                     jjstateSet[jjnewStateCnt++] = 538;
                  else if (curChar == 110)
                     jjstateSet[jjnewStateCnt++] = 525;
                  else if (curChar == 97)
                     jjstateSet[jjnewStateCnt++] = 495;
                  else if (curChar == 112)
                     jjstateSet[jjnewStateCnt++] = 475;
                  else if (curChar == 108)
                     jjstateSet[jjnewStateCnt++] = 171;
                  else if (curChar == 99)
                     jjstateSet[jjnewStateCnt++] = 147;
                  else if (curChar == 116)
                     jjstateSet[jjnewStateCnt++] = 126;
                  else if (curChar == 105)
                     jjstateSet[jjnewStateCnt++] = 102;
                  if (curChar == 114)
                     jjstateSet[jjnewStateCnt++] = 509;
                  else if (curChar == 110)
                     jjstateSet[jjnewStateCnt++] = 467;
                  else if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 449;
                  else if (curChar == 100)
                     jjstateSet[jjnewStateCnt++] = 381;
                  else if (curChar == 117)
                     jjstateSet[jjnewStateCnt++] = 245;
                  else if (curChar == 97)
                     jjstateSet[jjnewStateCnt++] = 228;
                  else if (curChar == 112)
                     jjstateSet[jjnewStateCnt++] = 219;
                  else if (curChar == 98)
                     jjstateSet[jjnewStateCnt++] = 185;
                  else if (curChar == 108)
                     jjstateSet[jjnewStateCnt++] = 162;
                  else if (curChar == 105)
                     jjstateSet[jjnewStateCnt++] = 58;
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 433;
                  else if (curChar == 110)
                     jjstateSet[jjnewStateCnt++] = 413;
                  else if (curChar == 100)
                     jjstateSet[jjnewStateCnt++] = 364;
                  else if (curChar == 112)
                     jjstateSet[jjnewStateCnt++] = 168;
                  else if (curChar == 117)
                     jjstateSet[jjnewStateCnt++] = 68;
                  else if (curChar == 105)
                     jjstateSet[jjnewStateCnt++] = 47;
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 422;
                  else if (curChar == 100)
                     jjstateSet[jjnewStateCnt++] = 349;
                  else if (curChar == 110)
                     jjstateSet[jjnewStateCnt++] = 239;
                  else if (curChar == 112)
                     jjstateSet[jjnewStateCnt++] = 138;
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 397;
                  else if (curChar == 100)
                     jjstateSet[jjnewStateCnt++] = 335;
                  else if (curChar == 110)
                     jjstateSet[jjnewStateCnt++] = 214;
                  if (curChar == 100)
                     jjstateSet[jjnewStateCnt++] = 313;
                  else if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 196;
                  if (curChar == 100)
                     jjstateSet[jjnewStateCnt++] = 299;
                  else if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 159;
                  if (curChar == 100)
                     jjstateSet[jjnewStateCnt++] = 276;
                  else if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 131;
                  if (curChar == 100)
                     jjstateSet[jjnewStateCnt++] = 259;
                  else if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 91;
                  if (curChar == 100)
                     jjstateSet[jjnewStateCnt++] = 112;
                  else if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 84;
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 78;
                  break;
               case 594:
                  if (curChar == 96)
                     { jjCheckNAddStates(53, 90); }
                  if (curChar == 96)
                     { jjCheckNAdd(591); }
                  if (curChar == 96)
                     { jjCheckNAdd(113); }
                  if (curChar == 96)
                     { jjCheckNAdd(103); }
                  if (curChar == 96)
                     { jjCheckNAdd(92); }
                  if (curChar == 96)
                     { jjCheckNAdd(85); }
                  if (curChar == 96)
                     { jjCheckNAdd(79); }
                  if (curChar == 96)
                     { jjCheckNAdd(69); }
                  if (curChar == 96)
                     { jjCheckNAdd(59); }
                  if (curChar == 96)
                     { jjCheckNAdd(48); }
                  break;
               case 0:
                  if ((0x7fffffe87fffffeULL & l) != 0L)
                  {
                     if (kind > 8)
                        kind = 8;
                     { jjCheckNAddTwoStates(9, 10); }
                  }
                  else if (curChar == 96)
                     { jjCheckNAddStates(91, 137); }
                  if ((0xf8000001f8000001ULL & l) != 0L)
                  {
                     if (kind > 18)
                        kind = 18;
                  }
                  if (curChar == 96)
                     { jjCheckNAddStates(138, 141); }
                  break;
               case 1:
                  if ((0xffffffffefffffffULL & l) != 0L)
                     { jjCheckNAddStates(0, 2); }
                  break;
               case 2:
                  if (curChar == 92)
                     { jjAddStates(50, 52); }
                  break;
               case 3:
                  if ((0x1c404410000000ULL & l) != 0L)
                     { jjCheckNAddStates(0, 2); }
                  break;
               case 9:
                  if ((0x7fffffe87fffffeULL & l) == 0L)
                     break;
                  if (kind > 8)
                     kind = 8;
                  { jjCheckNAddTwoStates(9, 10); }
                  break;
               case 12:
                  if ((0xf8000001f8000001ULL & l) != 0L && kind > 18)
                     kind = 18;
                  break;
               case 13:
                  if (curChar == 96)
                     { jjCheckNAddStates(138, 141); }
                  break;
               case 15:
                  if ((0x7fffffe87fffffeULL & l) != 0L)
                     { jjCheckNAddStates(32, 34); }
                  break;
               case 17:
                  if (curChar == 96)
                     jjstateSet[jjnewStateCnt++] = 18;
                  break;
               case 18:
                  if (curChar == 96 && kind > 9)
                     kind = 9;
                  break;
               case 19:
                  if (curChar == 96)
                     { jjCheckNAdd(20); }
                  break;
               case 20:
                  if ((0x7fffffe87fffffeULL & l) == 0L)
                     break;
                  if (kind > 10)
                     kind = 10;
                  { jjCheckNAddTwoStates(20, 21); }
                  break;
               case 22:
                  if ((0x7fffffe87fffffeULL & l) == 0L)
                     break;
                  if (kind > 11)
                     kind = 11;
                  { jjCheckNAddTwoStates(22, 23); }
                  break;
               case 24:
                  if ((0x7fffffe87fffffeULL & l) != 0L)
                     { jjCheckNAddStates(3, 5); }
                  break;
               case 29:
                  if (kind > 59)
                     kind = 59;
                  { jjAddStates(35, 37); }
                  break;
               case 34:
                  { jjCheckNAddTwoStates(34, 35); }
                  break;
               case 36:
               case 37:
                  { jjCheckNAddTwoStates(37, 35); }
                  break;
               case 41:
                  if (curChar == 102)
                     jjstateSet[jjnewStateCnt++] = 42;
                  break;
               case 43:
                  if ((0x7fffffe87fffffeULL & l) == 0L)
                     break;
                  if (kind > 61)
                     kind = 61;
                  { jjAddStates(142, 143); }
                  break;
               case 45:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 41;
                  break;
               case 46:
                  if (curChar == 100)
                     jjstateSet[jjnewStateCnt++] = 45;
                  break;
               case 47:
                  if (curChar == 102)
                     jjstateSet[jjnewStateCnt++] = 46;
                  break;
               case 48:
                  if (curChar == 105)
                     jjstateSet[jjnewStateCnt++] = 47;
                  break;
               case 49:
                  if (curChar == 96)
                     { jjCheckNAdd(48); }
                  break;
               case 51:
                  if (curChar == 102)
                     jjstateSet[jjnewStateCnt++] = 52;
                  break;
               case 53:
                  if ((0x7fffffe87fffffeULL & l) == 0L)
                     break;
                  if (kind > 62)
                     kind = 62;
                  { jjAddStates(144, 145); }
                  break;
               case 55:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 51;
                  break;
               case 56:
                  if (curChar == 100)
                     jjstateSet[jjnewStateCnt++] = 55;
                  break;
               case 57:
                  if (curChar == 110)
                     jjstateSet[jjnewStateCnt++] = 56;
                  break;
               case 58:
                  if (curChar == 102)
                     jjstateSet[jjnewStateCnt++] = 57;
                  break;
               case 59:
                  if (curChar == 105)
                     jjstateSet[jjnewStateCnt++] = 58;
                  break;
               case 60:
                  if (curChar == 96)
                     { jjCheckNAdd(59); }
                  break;
               case 62:
                  if (curChar == 102)
                     jjstateSet[jjnewStateCnt++] = 63;
                  break;
               case 64:
                  if ((0x7fffffe87fffffeULL & l) == 0L)
                     break;
                  if (kind > 63)
                     kind = 63;
                  { jjAddStates(146, 147); }
                  break;
               case 66:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 62;
                  break;
               case 67:
                  if (curChar == 100)
                     jjstateSet[jjnewStateCnt++] = 66;
                  break;
               case 68:
                  if (curChar == 110)
                     jjstateSet[jjnewStateCnt++] = 67;
                  break;
               case 69:
                  if (curChar == 117)
                     jjstateSet[jjnewStateCnt++] = 68;
                  break;
               case 70:
                  if (curChar == 96)
                     { jjCheckNAdd(69); }
                  break;
               case 72:
                  if (curChar == 102)
                     jjstateSet[jjnewStateCnt++] = 73;
                  break;
               case 74:
                  if ((0x7fffffe87fffffeULL & l) == 0L)
                     break;
                  if (kind > 64)
                     kind = 64;
                  { jjAddStates(148, 149); }
                  break;
               case 76:
                  if (curChar == 105)
                     jjstateSet[jjnewStateCnt++] = 72;
                  break;
               case 77:
                  if (curChar == 115)
                     jjstateSet[jjnewStateCnt++] = 76;
                  break;
               case 78:
                  if (curChar == 108)
                     jjstateSet[jjnewStateCnt++] = 77;
                  break;
               case 79:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 78;
                  break;
               case 80:
                  if (curChar == 96)
                     { jjCheckNAdd(79); }
                  break;
               case 82:
                  if (curChar == 101 && kind > 65)
                     kind = 65;
                  break;
               case 83:
                  if (curChar == 115)
                     jjstateSet[jjnewStateCnt++] = 82;
                  break;
               case 84:
                  if (curChar == 108)
                     jjstateSet[jjnewStateCnt++] = 83;
                  break;
               case 85:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 84;
                  break;
               case 86:
                  if (curChar == 96)
                     { jjCheckNAdd(85); }
                  break;
               case 88:
                  if (curChar == 102 && kind > 66)
                     kind = 66;
                  break;
               case 89:
                  if (curChar == 105)
                     jjstateSet[jjnewStateCnt++] = 88;
                  break;
               case 90:
                  if (curChar == 100)
                     jjstateSet[jjnewStateCnt++] = 89;
                  break;
               case 91:
                  if (curChar == 110)
                     jjstateSet[jjnewStateCnt++] = 90;
                  break;
               case 92:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 91;
                  break;
               case 93:
                  if (curChar == 96)
                     { jjCheckNAdd(92); }
                  break;
               case 95:
                  if (curChar == 101)
                     { jjCheckNAddTwoStates(96, 97); }
                  break;
               case 96:
                  { jjCheckNAddTwoStates(96, 97); }
                  break;
               case 98:
                  if (curChar == 100)
                     jjstateSet[jjnewStateCnt++] = 95;
                  break;
               case 99:
                  if (curChar == 117)
                     jjstateSet[jjnewStateCnt++] = 98;
                  break;
               case 100:
                  if (curChar == 108)
                     jjstateSet[jjnewStateCnt++] = 99;
                  break;
               case 101:
                  if (curChar == 99)
                     jjstateSet[jjnewStateCnt++] = 100;
                  break;
               case 102:
                  if (curChar == 110)
                     jjstateSet[jjnewStateCnt++] = 101;
                  break;
               case 103:
                  if (curChar == 105)
                     jjstateSet[jjnewStateCnt++] = 102;
                  break;
               case 104:
                  if (curChar == 96)
                     { jjCheckNAdd(103); }
                  break;
               case 106:
                  if (curChar == 101)
                     { jjCheckNAddTwoStates(107, 108); }
                  break;
               case 107:
                  { jjCheckNAddTwoStates(107, 108); }
                  break;
               case 109:
                  if (curChar == 110)
                     jjstateSet[jjnewStateCnt++] = 106;
                  break;
               case 110:
                  if (curChar == 105)
                     jjstateSet[jjnewStateCnt++] = 109;
                  break;
               case 111:
                  if (curChar == 102)
                     jjstateSet[jjnewStateCnt++] = 110;
                  break;
               case 112:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 111;
                  break;
               case 113:
                  if (curChar == 100)
                     jjstateSet[jjnewStateCnt++] = 112;
                  break;
               case 114:
                  if (curChar == 96)
                     { jjCheckNAdd(113); }
                  break;
               case 116:
                  if (curChar == 96)
                     { jjCheckNAddStates(53, 90); }
                  break;
               case 117:
                  if (curChar == 101)
                     { jjCheckNAddTwoStates(118, 119); }
                  break;
               case 118:
                  { jjCheckNAddTwoStates(118, 119); }
                  break;
               case 120:
                  if (curChar == 108)
                     { jjCheckNAdd(117); }
                  break;
               case 121:
                  if (curChar == 97)
                     jjstateSet[jjnewStateCnt++] = 120;
                  break;
               case 122:
                  if (curChar == 99)
                     jjstateSet[jjnewStateCnt++] = 121;
                  break;
               case 123:
                  if (curChar == 115)
                     jjstateSet[jjnewStateCnt++] = 122;
                  break;
               case 124:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 123;
                  break;
               case 125:
                  if (curChar == 109)
                     jjstateSet[jjnewStateCnt++] = 124;
                  break;
               case 126:
                  if (curChar == 105)
                     jjstateSet[jjnewStateCnt++] = 125;
                  break;
               case 127:
                  if (curChar == 116)
                     jjstateSet[jjnewStateCnt++] = 126;
                  break;
               case 128:
                  if (curChar == 114)
                     { jjCheckNAddTwoStates(118, 119); }
                  break;
               case 129:
                  if (curChar == 111)
                     jjstateSet[jjnewStateCnt++] = 128;
                  break;
               case 130:
                  if (curChar == 114)
                     jjstateSet[jjnewStateCnt++] = 129;
                  break;
               case 131:
                  if (curChar == 114)
                     jjstateSet[jjnewStateCnt++] = 130;
                  break;
               case 132:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 131;
                  break;
               case 133:
                  if (curChar == 116)
                     { jjCheckNAddTwoStates(118, 119); }
                  break;
               case 134:
               case 415:
                  if (curChar == 99)
                     { jjCheckNAdd(133); }
                  break;
               case 135:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 134;
                  break;
               case 136:
                  if (curChar == 116)
                     jjstateSet[jjnewStateCnt++] = 135;
                  break;
               case 137:
                  if (curChar == 111)
                     jjstateSet[jjnewStateCnt++] = 136;
                  break;
               case 138:
                  if (curChar == 114)
                     jjstateSet[jjnewStateCnt++] = 137;
                  break;
               case 139:
                  if (curChar == 112)
                     jjstateSet[jjnewStateCnt++] = 138;
                  break;
               case 140:
               case 149:
               case 161:
               case 170:
                  if (curChar == 110)
                     { jjCheckNAdd(117); }
                  break;
               case 141:
                  if (curChar == 105)
                     jjstateSet[jjnewStateCnt++] = 140;
                  break;
               case 142:
                  if (curChar == 102)
                     jjstateSet[jjnewStateCnt++] = 141;
                  break;
               case 143:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 142;
                  break;
               case 144:
                  if (curChar == 100)
                     jjstateSet[jjnewStateCnt++] = 143;
                  break;
               case 145:
                  if (curChar == 108)
                     jjstateSet[jjnewStateCnt++] = 144;
                  break;
               case 146:
                  if (curChar == 108)
                     jjstateSet[jjnewStateCnt++] = 145;
                  break;
               case 147:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 146;
                  break;
               case 148:
                  if (curChar == 99)
                     jjstateSet[jjnewStateCnt++] = 147;
                  break;
               case 150:
                  if (curChar == 105)
                     jjstateSet[jjnewStateCnt++] = 149;
                  break;
               case 151:
                  if (curChar == 102)
                     jjstateSet[jjnewStateCnt++] = 150;
                  break;
               case 152:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 151;
                  break;
               case 153:
                  if (curChar == 100)
                     jjstateSet[jjnewStateCnt++] = 152;
                  break;
               case 154:
                  if (curChar == 108)
                     jjstateSet[jjnewStateCnt++] = 153;
                  break;
               case 155:
                  if (curChar == 108)
                     jjstateSet[jjnewStateCnt++] = 154;
                  break;
               case 156:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 155;
                  break;
               case 157:
                  if (curChar == 99)
                     jjstateSet[jjnewStateCnt++] = 156;
                  break;
               case 158:
                  if (curChar == 100)
                     jjstateSet[jjnewStateCnt++] = 157;
                  break;
               case 159:
                  if (curChar == 110)
                     jjstateSet[jjnewStateCnt++] = 158;
                  break;
               case 160:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 159;
                  break;
               case 162:
                  if (curChar == 105)
                     jjstateSet[jjnewStateCnt++] = 161;
                  break;
               case 163:
                  if (curChar == 108)
                     jjstateSet[jjnewStateCnt++] = 162;
                  break;
               case 164:
                  if (curChar == 97)
                     { jjCheckNAddTwoStates(118, 119); }
                  break;
               case 165:
               case 216:
                  if (curChar == 109)
                     { jjCheckNAdd(164); }
                  break;
               case 166:
                  if (curChar == 103)
                     jjstateSet[jjnewStateCnt++] = 165;
                  break;
               case 167:
                  if (curChar == 97)
                     jjstateSet[jjnewStateCnt++] = 166;
                  break;
               case 168:
                  if (curChar == 114)
                     jjstateSet[jjnewStateCnt++] = 167;
                  break;
               case 169:
                  if (curChar == 112)
                     jjstateSet[jjnewStateCnt++] = 168;
                  break;
               case 171:
                  if (curChar == 105)
                     jjstateSet[jjnewStateCnt++] = 170;
                  break;
               case 172:
                  if (curChar == 108)
                     jjstateSet[jjnewStateCnt++] = 171;
                  break;
               case 173:
                  if (curChar == 115)
                     { jjCheckNAddTwoStates(118, 119); }
                  break;
               case 174:
               case 187:
               case 552:
               case 565:
                  if (curChar == 100)
                     { jjCheckNAdd(173); }
                  break;
               case 175:
                  if (curChar == 114)
                     jjstateSet[jjnewStateCnt++] = 174;
                  break;
               case 176:
                  if (curChar == 111)
                     jjstateSet[jjnewStateCnt++] = 175;
                  break;
               case 177:
                  if (curChar == 119)
                     jjstateSet[jjnewStateCnt++] = 176;
                  break;
               case 178:
                  if (curChar == 121)
                     jjstateSet[jjnewStateCnt++] = 177;
                  break;
               case 179:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 178;
                  break;
               case 180:
                  if (curChar == 107)
                     jjstateSet[jjnewStateCnt++] = 179;
                  break;
               case 181:
                  if (curChar == 95)
                     jjstateSet[jjnewStateCnt++] = 180;
                  break;
               case 182:
                  if (curChar == 110)
                     jjstateSet[jjnewStateCnt++] = 181;
                  break;
               case 183:
                  if (curChar == 105)
                     jjstateSet[jjnewStateCnt++] = 182;
                  break;
               case 184:
                  if (curChar == 103)
                     jjstateSet[jjnewStateCnt++] = 183;
                  break;
               case 185:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 184;
                  break;
               case 186:
                  if (curChar == 98)
                     jjstateSet[jjnewStateCnt++] = 185;
                  break;
               case 188:
                  if (curChar == 114)
                     jjstateSet[jjnewStateCnt++] = 187;
                  break;
               case 189:
                  if (curChar == 111)
                     jjstateSet[jjnewStateCnt++] = 188;
                  break;
               case 190:
                  if (curChar == 119)
                     jjstateSet[jjnewStateCnt++] = 189;
                  break;
               case 191:
                  if (curChar == 121)
                     jjstateSet[jjnewStateCnt++] = 190;
                  break;
               case 192:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 191;
                  break;
               case 193:
                  if (curChar == 107)
                     jjstateSet[jjnewStateCnt++] = 192;
                  break;
               case 194:
                  if (curChar == 95)
                     jjstateSet[jjnewStateCnt++] = 193;
                  break;
               case 195:
                  if (curChar == 100)
                     jjstateSet[jjnewStateCnt++] = 194;
                  break;
               case 196:
                  if (curChar == 110)
                     jjstateSet[jjnewStateCnt++] = 195;
                  break;
               case 197:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 196;
                  break;
               case 198:
                  if (curChar == 118)
                     { jjCheckNAdd(117); }
                  break;
               case 199:
                  if (curChar == 105)
                     jjstateSet[jjnewStateCnt++] = 198;
                  break;
               case 200:
                  if (curChar == 114)
                     jjstateSet[jjnewStateCnt++] = 199;
                  break;
               case 201:
                  if (curChar == 100)
                     jjstateSet[jjnewStateCnt++] = 200;
                  break;
               case 202:
                  if (curChar == 95)
                     jjstateSet[jjnewStateCnt++] = 201;
                  break;
               case 203:
                  if (curChar == 100)
                     jjstateSet[jjnewStateCnt++] = 202;
                  break;
               case 204:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 203;
                  break;
               case 205:
                  if (curChar == 116)
                     jjstateSet[jjnewStateCnt++] = 204;
                  break;
               case 206:
                  if (curChar == 99)
                     jjstateSet[jjnewStateCnt++] = 205;
                  break;
               case 207:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 206;
                  break;
               case 208:
                  if (curChar == 110)
                     jjstateSet[jjnewStateCnt++] = 207;
                  break;
               case 209:
                  if (curChar == 110)
                     jjstateSet[jjnewStateCnt++] = 208;
                  break;
               case 210:
                  if (curChar == 111)
                     jjstateSet[jjnewStateCnt++] = 209;
                  break;
               case 211:
                  if (curChar == 99)
                     jjstateSet[jjnewStateCnt++] = 210;
                  break;
               case 212:
                  if (curChar == 110)
                     jjstateSet[jjnewStateCnt++] = 211;
                  break;
               case 213:
                  if (curChar == 117)
                     jjstateSet[jjnewStateCnt++] = 212;
                  break;
               case 214:
                  if (curChar == 111)
                     jjstateSet[jjnewStateCnt++] = 213;
                  break;
               case 215:
                  if (curChar == 110)
                     jjstateSet[jjnewStateCnt++] = 214;
                  break;
               case 217:
                  if (curChar == 103)
                     jjstateSet[jjnewStateCnt++] = 216;
                  break;
               case 218:
                  if (curChar == 97)
                     jjstateSet[jjnewStateCnt++] = 217;
                  break;
               case 219:
                  if (curChar == 114)
                     jjstateSet[jjnewStateCnt++] = 218;
                  break;
               case 220:
                  if (curChar == 112)
                     jjstateSet[jjnewStateCnt++] = 219;
                  break;
               case 221:
               case 230:
                  if (curChar == 116)
                     { jjCheckNAdd(117); }
                  break;
               case 222:
                  if (curChar == 97)
                     jjstateSet[jjnewStateCnt++] = 221;
                  break;
               case 223:
                  if (curChar == 114)
                     jjstateSet[jjnewStateCnt++] = 222;
                  break;
               case 224:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 223;
                  break;
               case 225:
                  if (curChar == 108)
                     jjstateSet[jjnewStateCnt++] = 224;
                  break;
               case 226:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 225;
                  break;
               case 227:
                  if (curChar == 99)
                     jjstateSet[jjnewStateCnt++] = 226;
                  break;
               case 228:
                  if (curChar == 99)
                     jjstateSet[jjnewStateCnt++] = 227;
                  break;
               case 229:
                  if (curChar == 97)
                     jjstateSet[jjnewStateCnt++] = 228;
                  break;
               case 231:
                  if (curChar == 97)
                     jjstateSet[jjnewStateCnt++] = 230;
                  break;
               case 232:
                  if (curChar == 114)
                     jjstateSet[jjnewStateCnt++] = 231;
                  break;
               case 233:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 232;
                  break;
               case 234:
                  if (curChar == 108)
                     jjstateSet[jjnewStateCnt++] = 233;
                  break;
               case 235:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 234;
                  break;
               case 236:
                  if (curChar == 99)
                     jjstateSet[jjnewStateCnt++] = 235;
                  break;
               case 237:
                  if (curChar == 99)
                     jjstateSet[jjnewStateCnt++] = 236;
                  break;
               case 238:
                  if (curChar == 97)
                     jjstateSet[jjnewStateCnt++] = 237;
                  break;
               case 239:
                  if (curChar == 111)
                     jjstateSet[jjnewStateCnt++] = 238;
                  break;
               case 240:
                  if (curChar == 110)
                     jjstateSet[jjnewStateCnt++] = 239;
                  break;
               case 241:
                  if (curChar == 98)
                     { jjCheckNAddTwoStates(118, 119); }
                  break;
               case 242:
                  if (curChar == 105)
                     jjstateSet[jjnewStateCnt++] = 241;
                  break;
               case 243:
                  if (curChar == 108)
                     jjstateSet[jjnewStateCnt++] = 242;
                  break;
               case 244:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 243;
                  break;
               case 245:
                  if (curChar == 115)
                     jjstateSet[jjnewStateCnt++] = 244;
                  break;
               case 246:
                  if (curChar == 117)
                     jjstateSet[jjnewStateCnt++] = 245;
                  break;
               case 247:
                  if (curChar == 112)
                     { jjCheckNAdd(117); }
                  break;
               case 248:
                  if (curChar == 121)
                     jjstateSet[jjnewStateCnt++] = 247;
                  break;
               case 249:
                  if (curChar == 116)
                     jjstateSet[jjnewStateCnt++] = 248;
                  break;
               case 250:
                  if (curChar == 116)
                     jjstateSet[jjnewStateCnt++] = 249;
                  break;
               case 251:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 250;
                  break;
               case 252:
                  if (curChar == 110)
                     jjstateSet[jjnewStateCnt++] = 251;
                  break;
               case 253:
                  if (curChar == 95)
                     jjstateSet[jjnewStateCnt++] = 252;
                  break;
               case 254:
                  if (curChar == 116)
                     jjstateSet[jjnewStateCnt++] = 253;
                  break;
               case 255:
                  if (curChar == 108)
                     jjstateSet[jjnewStateCnt++] = 254;
                  break;
               case 256:
                  if (curChar == 117)
                     jjstateSet[jjnewStateCnt++] = 255;
                  break;
               case 257:
                  if (curChar == 97)
                     jjstateSet[jjnewStateCnt++] = 256;
                  break;
               case 258:
                  if (curChar == 102)
                     jjstateSet[jjnewStateCnt++] = 257;
                  break;
               case 259:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 258;
                  break;
               case 260:
                  if (curChar == 100)
                     jjstateSet[jjnewStateCnt++] = 259;
                  break;
               case 261:
               case 497:
               case 527:
                  if (curChar == 109)
                     { jjCheckNAdd(117); }
                  break;
               case 262:
                  if (curChar == 105)
                     jjstateSet[jjnewStateCnt++] = 261;
                  break;
               case 263:
                  if (curChar == 116)
                     jjstateSet[jjnewStateCnt++] = 262;
                  break;
               case 264:
                  if (curChar == 95)
                     jjstateSet[jjnewStateCnt++] = 263;
                  break;
               case 265:
                  if (curChar == 121)
                     jjstateSet[jjnewStateCnt++] = 264;
                  break;
               case 266:
                  if (curChar == 97)
                     jjstateSet[jjnewStateCnt++] = 265;
                  break;
               case 267:
                  if (curChar == 99)
                     jjstateSet[jjnewStateCnt++] = 266;
                  break;
               case 268:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 267;
                  break;
               case 269:
                  if (curChar == 100)
                     jjstateSet[jjnewStateCnt++] = 268;
                  break;
               case 270:
                  if (curChar == 95)
                     jjstateSet[jjnewStateCnt++] = 269;
                  break;
               case 271:
                  if (curChar == 116)
                     jjstateSet[jjnewStateCnt++] = 270;
                  break;
               case 272:
                  if (curChar == 108)
                     jjstateSet[jjnewStateCnt++] = 271;
                  break;
               case 273:
                  if (curChar == 117)
                     jjstateSet[jjnewStateCnt++] = 272;
                  break;
               case 274:
                  if (curChar == 97)
                     jjstateSet[jjnewStateCnt++] = 273;
                  break;
               case 275:
                  if (curChar == 102)
                     jjstateSet[jjnewStateCnt++] = 274;
                  break;
               case 276:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 275;
                  break;
               case 277:
                  if (curChar == 100)
                     jjstateSet[jjnewStateCnt++] = 276;
                  break;
               case 278:
                  if (curChar == 104)
                     { jjCheckNAddTwoStates(118, 119); }
                  break;
               case 279:
               case 301:
                  if (curChar == 116)
                     { jjCheckNAdd(278); }
                  break;
               case 280:
                  if (curChar == 103)
                     jjstateSet[jjnewStateCnt++] = 279;
                  break;
               case 281:
                  if (curChar == 110)
                     jjstateSet[jjnewStateCnt++] = 280;
                  break;
               case 282:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 281;
                  break;
               case 283:
                  if (curChar == 114)
                     jjstateSet[jjnewStateCnt++] = 282;
                  break;
               case 284:
                  if (curChar == 116)
                     jjstateSet[jjnewStateCnt++] = 283;
                  break;
               case 285:
                  if (curChar == 115)
                     jjstateSet[jjnewStateCnt++] = 284;
                  break;
               case 286:
                  if (curChar == 95)
                     jjstateSet[jjnewStateCnt++] = 285;
                  break;
               case 287:
                  if (curChar == 103)
                     jjstateSet[jjnewStateCnt++] = 286;
                  break;
               case 288:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 287;
                  break;
               case 289:
                  if (curChar == 114)
                     jjstateSet[jjnewStateCnt++] = 288;
                  break;
               case 290:
                  if (curChar == 105)
                     jjstateSet[jjnewStateCnt++] = 289;
                  break;
               case 291:
                  if (curChar == 114)
                     jjstateSet[jjnewStateCnt++] = 290;
                  break;
               case 292:
                  if (curChar == 116)
                     jjstateSet[jjnewStateCnt++] = 291;
                  break;
               case 293:
                  if (curChar == 95)
                     jjstateSet[jjnewStateCnt++] = 292;
                  break;
               case 294:
                  if (curChar == 116)
                     jjstateSet[jjnewStateCnt++] = 293;
                  break;
               case 295:
                  if (curChar == 108)
                     jjstateSet[jjnewStateCnt++] = 294;
                  break;
               case 296:
                  if (curChar == 117)
                     jjstateSet[jjnewStateCnt++] = 295;
                  break;
               case 297:
                  if (curChar == 97)
                     jjstateSet[jjnewStateCnt++] = 296;
                  break;
               case 298:
                  if (curChar == 102)
                     jjstateSet[jjnewStateCnt++] = 297;
                  break;
               case 299:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 298;
                  break;
               case 300:
                  if (curChar == 100)
                     jjstateSet[jjnewStateCnt++] = 299;
                  break;
               case 302:
                  if (curChar == 97)
                     jjstateSet[jjnewStateCnt++] = 301;
                  break;
               case 303:
                  if (curChar == 112)
                     jjstateSet[jjnewStateCnt++] = 302;
                  break;
               case 304:
                  if (curChar == 95)
                     jjstateSet[jjnewStateCnt++] = 303;
                  break;
               case 305:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 304;
                  break;
               case 306:
                  if (curChar == 100)
                     jjstateSet[jjnewStateCnt++] = 305;
                  break;
               case 307:
                  if (curChar == 111)
                     jjstateSet[jjnewStateCnt++] = 306;
                  break;
               case 308:
                  if (curChar == 109)
                     jjstateSet[jjnewStateCnt++] = 307;
                  break;
               case 309:
                  if (curChar == 95)
                     jjstateSet[jjnewStateCnt++] = 308;
                  break;
               case 310:
                  if (curChar == 121)
                     jjstateSet[jjnewStateCnt++] = 309;
                  break;
               case 311:
                  if (curChar == 97)
                     jjstateSet[jjnewStateCnt++] = 310;
                  break;
               case 312:
                  if (curChar == 108)
                     jjstateSet[jjnewStateCnt++] = 311;
                  break;
               case 313:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 312;
                  break;
               case 314:
                  if (curChar == 100)
                     jjstateSet[jjnewStateCnt++] = 313;
                  break;
               case 315:
                  if (curChar == 100)
                     { jjCheckNAddTwoStates(118, 119); }
                  break;
               case 316:
               case 424:
               case 469:
               case 540:
               case 545:
                  if (curChar == 101)
                     { jjCheckNAdd(315); }
                  break;
               case 317:
                  if (curChar == 116)
                     jjstateSet[jjnewStateCnt++] = 316;
                  break;
               case 318:
                  if (curChar == 117)
                     jjstateSet[jjnewStateCnt++] = 317;
                  break;
               case 319:
                  if (curChar == 98)
                     jjstateSet[jjnewStateCnt++] = 318;
                  break;
               case 320:
                  if (curChar == 105)
                     jjstateSet[jjnewStateCnt++] = 319;
                  break;
               case 321:
                  if (curChar == 114)
                     jjstateSet[jjnewStateCnt++] = 320;
                  break;
               case 322:
                  if (curChar == 116)
                     jjstateSet[jjnewStateCnt++] = 321;
                  break;
               case 323:
                  if (curChar == 115)
                     jjstateSet[jjnewStateCnt++] = 322;
                  break;
               case 324:
                  if (curChar == 105)
                     jjstateSet[jjnewStateCnt++] = 323;
                  break;
               case 325:
                  if (curChar == 100)
                     jjstateSet[jjnewStateCnt++] = 324;
                  break;
               case 326:
                  if (curChar == 95)
                     jjstateSet[jjnewStateCnt++] = 325;
                  break;
               case 327:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 326;
                  break;
               case 328:
                  if (curChar == 100)
                     jjstateSet[jjnewStateCnt++] = 327;
                  break;
               case 329:
                  if (curChar == 111)
                     jjstateSet[jjnewStateCnt++] = 328;
                  break;
               case 330:
                  if (curChar == 109)
                     jjstateSet[jjnewStateCnt++] = 329;
                  break;
               case 331:
                  if (curChar == 95)
                     jjstateSet[jjnewStateCnt++] = 330;
                  break;
               case 332:
                  if (curChar == 121)
                     jjstateSet[jjnewStateCnt++] = 331;
                  break;
               case 333:
                  if (curChar == 97)
                     jjstateSet[jjnewStateCnt++] = 332;
                  break;
               case 334:
                  if (curChar == 108)
                     jjstateSet[jjnewStateCnt++] = 333;
                  break;
               case 335:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 334;
                  break;
               case 336:
                  if (curChar == 100)
                     jjstateSet[jjnewStateCnt++] = 335;
                  break;
               case 337:
                  if (curChar == 105)
                     { jjCheckNAdd(133); }
                  break;
               case 338:
                  if (curChar == 110)
                     jjstateSet[jjnewStateCnt++] = 337;
                  break;
               case 339:
                  if (curChar == 117)
                     jjstateSet[jjnewStateCnt++] = 338;
                  break;
               case 340:
                  if (curChar == 95)
                     jjstateSet[jjnewStateCnt++] = 339;
                  break;
               case 341:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 340;
                  break;
               case 342:
                  if (curChar == 100)
                     jjstateSet[jjnewStateCnt++] = 341;
                  break;
               case 343:
                  if (curChar == 111)
                     jjstateSet[jjnewStateCnt++] = 342;
                  break;
               case 344:
                  if (curChar == 109)
                     jjstateSet[jjnewStateCnt++] = 343;
                  break;
               case 345:
                  if (curChar == 95)
                     jjstateSet[jjnewStateCnt++] = 344;
                  break;
               case 346:
                  if (curChar == 121)
                     jjstateSet[jjnewStateCnt++] = 345;
                  break;
               case 347:
                  if (curChar == 97)
                     jjstateSet[jjnewStateCnt++] = 346;
                  break;
               case 348:
                  if (curChar == 108)
                     jjstateSet[jjnewStateCnt++] = 347;
                  break;
               case 349:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 348;
                  break;
               case 350:
                  if (curChar == 100)
                     jjstateSet[jjnewStateCnt++] = 349;
                  break;
               case 351:
                  if (curChar == 111)
                     { jjCheckNAddTwoStates(118, 119); }
                  break;
               case 352:
                  if (curChar == 114)
                     jjstateSet[jjnewStateCnt++] = 351;
                  break;
               case 353:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 352;
                  break;
               case 354:
                  if (curChar == 122)
                     jjstateSet[jjnewStateCnt++] = 353;
                  break;
               case 355:
                  if (curChar == 95)
                     jjstateSet[jjnewStateCnt++] = 354;
                  break;
               case 356:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 355;
                  break;
               case 357:
                  if (curChar == 100)
                     jjstateSet[jjnewStateCnt++] = 356;
                  break;
               case 358:
                  if (curChar == 111)
                     jjstateSet[jjnewStateCnt++] = 357;
                  break;
               case 359:
                  if (curChar == 109)
                     jjstateSet[jjnewStateCnt++] = 358;
                  break;
               case 360:
                  if (curChar == 95)
                     jjstateSet[jjnewStateCnt++] = 359;
                  break;
               case 361:
                  if (curChar == 121)
                     jjstateSet[jjnewStateCnt++] = 360;
                  break;
               case 362:
                  if (curChar == 97)
                     jjstateSet[jjnewStateCnt++] = 361;
                  break;
               case 363:
                  if (curChar == 108)
                     jjstateSet[jjnewStateCnt++] = 362;
                  break;
               case 364:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 363;
                  break;
               case 365:
                  if (curChar == 100)
                     jjstateSet[jjnewStateCnt++] = 364;
                  break;
               case 366:
               case 383:
               case 399:
               case 435:
               case 451:
               case 477:
                  if (curChar == 116)
                     { jjCheckNAdd(173); }
                  break;
               case 367:
                  if (curChar == 108)
                     jjstateSet[jjnewStateCnt++] = 366;
                  break;
               case 368:
                  if (curChar == 117)
                     jjstateSet[jjnewStateCnt++] = 367;
                  break;
               case 369:
                  if (curChar == 97)
                     jjstateSet[jjnewStateCnt++] = 368;
                  break;
               case 370:
                  if (curChar == 102)
                     jjstateSet[jjnewStateCnt++] = 369;
                  break;
               case 371:
                  if (curChar == 116)
                     jjstateSet[jjnewStateCnt++] = 370;
                  break;
               case 372:
                  if (curChar == 114)
                     jjstateSet[jjnewStateCnt++] = 371;
                  break;
               case 373:
                  if (curChar == 111)
                     jjstateSet[jjnewStateCnt++] = 372;
                  break;
               case 374:
                  if (curChar == 112)
                     jjstateSet[jjnewStateCnt++] = 373;
                  break;
               case 375:
                  if (curChar == 95)
                     jjstateSet[jjnewStateCnt++] = 374;
                  break;
               case 376:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 375;
                  break;
               case 377:
                  if (curChar == 108)
                     jjstateSet[jjnewStateCnt++] = 376;
                  break;
               case 378:
                  if (curChar == 98)
                     jjstateSet[jjnewStateCnt++] = 377;
                  break;
               case 379:
                  if (curChar == 97)
                     jjstateSet[jjnewStateCnt++] = 378;
                  break;
               case 380:
                  if (curChar == 115)
                     jjstateSet[jjnewStateCnt++] = 379;
                  break;
               case 381:
                  if (curChar == 105)
                     jjstateSet[jjnewStateCnt++] = 380;
                  break;
               case 382:
                  if (curChar == 100)
                     jjstateSet[jjnewStateCnt++] = 381;
                  break;
               case 384:
                  if (curChar == 108)
                     jjstateSet[jjnewStateCnt++] = 383;
                  break;
               case 385:
                  if (curChar == 117)
                     jjstateSet[jjnewStateCnt++] = 384;
                  break;
               case 386:
                  if (curChar == 97)
                     jjstateSet[jjnewStateCnt++] = 385;
                  break;
               case 387:
                  if (curChar == 102)
                     jjstateSet[jjnewStateCnt++] = 386;
                  break;
               case 388:
                  if (curChar == 116)
                     jjstateSet[jjnewStateCnt++] = 387;
                  break;
               case 389:
                  if (curChar == 114)
                     jjstateSet[jjnewStateCnt++] = 388;
                  break;
               case 390:
                  if (curChar == 111)
                     jjstateSet[jjnewStateCnt++] = 389;
                  break;
               case 391:
                  if (curChar == 112)
                     jjstateSet[jjnewStateCnt++] = 390;
                  break;
               case 392:
                  if (curChar == 95)
                     jjstateSet[jjnewStateCnt++] = 391;
                  break;
               case 393:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 392;
                  break;
               case 394:
                  if (curChar == 108)
                     jjstateSet[jjnewStateCnt++] = 393;
                  break;
               case 395:
                  if (curChar == 98)
                     jjstateSet[jjnewStateCnt++] = 394;
                  break;
               case 396:
                  if (curChar == 97)
                     jjstateSet[jjnewStateCnt++] = 395;
                  break;
               case 397:
                  if (curChar == 110)
                     jjstateSet[jjnewStateCnt++] = 396;
                  break;
               case 398:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 397;
                  break;
               case 400:
                  if (curChar == 108)
                     jjstateSet[jjnewStateCnt++] = 399;
                  break;
               case 401:
                  if (curChar == 117)
                     jjstateSet[jjnewStateCnt++] = 400;
                  break;
               case 402:
                  if (curChar == 97)
                     jjstateSet[jjnewStateCnt++] = 401;
                  break;
               case 403:
                  if (curChar == 102)
                     jjstateSet[jjnewStateCnt++] = 402;
                  break;
               case 404:
                  if (curChar == 95)
                     jjstateSet[jjnewStateCnt++] = 403;
                  break;
               case 405:
                  if (curChar == 115)
                     jjstateSet[jjnewStateCnt++] = 404;
                  break;
               case 406:
                  if (curChar == 115)
                     jjstateSet[jjnewStateCnt++] = 405;
                  break;
               case 407:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 406;
                  break;
               case 408:
                  if (curChar == 114)
                     jjstateSet[jjnewStateCnt++] = 407;
                  break;
               case 409:
                  if (curChar == 112)
                     jjstateSet[jjnewStateCnt++] = 408;
                  break;
               case 410:
                  if (curChar == 112)
                     jjstateSet[jjnewStateCnt++] = 409;
                  break;
               case 411:
                  if (curChar == 117)
                     jjstateSet[jjnewStateCnt++] = 410;
                  break;
               case 412:
                  if (curChar == 115)
                     jjstateSet[jjnewStateCnt++] = 411;
                  break;
               case 413:
                  if (curChar == 111)
                     jjstateSet[jjnewStateCnt++] = 412;
                  break;
               case 414:
                  if (curChar == 110)
                     jjstateSet[jjnewStateCnt++] = 413;
                  break;
               case 416:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 415;
                  break;
               case 417:
                  if (curChar == 116)
                     jjstateSet[jjnewStateCnt++] = 416;
                  break;
               case 418:
                  if (curChar == 111)
                     jjstateSet[jjnewStateCnt++] = 417;
                  break;
               case 419:
                  if (curChar == 114)
                     jjstateSet[jjnewStateCnt++] = 418;
                  break;
               case 420:
                  if (curChar == 112)
                     jjstateSet[jjnewStateCnt++] = 419;
                  break;
               case 421:
                  if (curChar == 100)
                     jjstateSet[jjnewStateCnt++] = 420;
                  break;
               case 422:
                  if (curChar == 110)
                     jjstateSet[jjnewStateCnt++] = 421;
                  break;
               case 423:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 422;
                  break;
               case 425:
                  if (curChar == 116)
                     jjstateSet[jjnewStateCnt++] = 424;
                  break;
               case 426:
                  if (curChar == 99)
                     jjstateSet[jjnewStateCnt++] = 425;
                  break;
               case 427:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 426;
                  break;
               case 428:
                  if (curChar == 116)
                     jjstateSet[jjnewStateCnt++] = 427;
                  break;
               case 429:
                  if (curChar == 111)
                     jjstateSet[jjnewStateCnt++] = 428;
                  break;
               case 430:
                  if (curChar == 114)
                     jjstateSet[jjnewStateCnt++] = 429;
                  break;
               case 431:
                  if (curChar == 112)
                     jjstateSet[jjnewStateCnt++] = 430;
                  break;
               case 432:
                  if (curChar == 100)
                     jjstateSet[jjnewStateCnt++] = 431;
                  break;
               case 433:
                  if (curChar == 110)
                     jjstateSet[jjnewStateCnt++] = 432;
                  break;
               case 434:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 433;
                  break;
               case 436:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 435;
                  break;
               case 437:
                  if (curChar == 110)
                     jjstateSet[jjnewStateCnt++] = 436;
                  break;
               case 438:
                  if (curChar == 114)
                     jjstateSet[jjnewStateCnt++] = 437;
                  break;
               case 439:
                  if (curChar == 111)
                     jjstateSet[jjnewStateCnt++] = 438;
                  break;
               case 440:
                  if (curChar == 116)
                     jjstateSet[jjnewStateCnt++] = 439;
                  break;
               case 441:
                  if (curChar == 99)
                     jjstateSet[jjnewStateCnt++] = 440;
                  break;
               case 442:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 441;
                  break;
               case 443:
                  if (curChar == 118)
                     jjstateSet[jjnewStateCnt++] = 442;
                  break;
               case 444:
                  if (curChar == 95)
                     jjstateSet[jjnewStateCnt++] = 443;
                  break;
               case 445:
                  if (curChar == 100)
                     jjstateSet[jjnewStateCnt++] = 444;
                  break;
               case 446:
                  if (curChar == 110)
                     jjstateSet[jjnewStateCnt++] = 445;
                  break;
               case 447:
                  if (curChar == 97)
                     jjstateSet[jjnewStateCnt++] = 446;
                  break;
               case 448:
                  if (curChar == 112)
                     jjstateSet[jjnewStateCnt++] = 447;
                  break;
               case 449:
                  if (curChar == 120)
                     jjstateSet[jjnewStateCnt++] = 448;
                  break;
               case 450:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 449;
                  break;
               case 452:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 451;
                  break;
               case 453:
                  if (curChar == 110)
                     jjstateSet[jjnewStateCnt++] = 452;
                  break;
               case 454:
                  if (curChar == 114)
                     jjstateSet[jjnewStateCnt++] = 453;
                  break;
               case 455:
                  if (curChar == 111)
                     jjstateSet[jjnewStateCnt++] = 454;
                  break;
               case 456:
                  if (curChar == 116)
                     jjstateSet[jjnewStateCnt++] = 455;
                  break;
               case 457:
                  if (curChar == 99)
                     jjstateSet[jjnewStateCnt++] = 456;
                  break;
               case 458:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 457;
                  break;
               case 459:
                  if (curChar == 118)
                     jjstateSet[jjnewStateCnt++] = 458;
                  break;
               case 460:
                  if (curChar == 95)
                     jjstateSet[jjnewStateCnt++] = 459;
                  break;
               case 461:
                  if (curChar == 100)
                     jjstateSet[jjnewStateCnt++] = 460;
                  break;
               case 462:
                  if (curChar == 110)
                     jjstateSet[jjnewStateCnt++] = 461;
                  break;
               case 463:
                  if (curChar == 97)
                     jjstateSet[jjnewStateCnt++] = 462;
                  break;
               case 464:
                  if (curChar == 112)
                     jjstateSet[jjnewStateCnt++] = 463;
                  break;
               case 465:
                  if (curChar == 120)
                     jjstateSet[jjnewStateCnt++] = 464;
                  break;
               case 466:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 465;
                  break;
               case 467:
                  if (curChar == 111)
                     jjstateSet[jjnewStateCnt++] = 466;
                  break;
               case 468:
                  if (curChar == 110)
                     jjstateSet[jjnewStateCnt++] = 467;
                  break;
               case 470:
                  if (curChar == 116)
                     jjstateSet[jjnewStateCnt++] = 469;
                  break;
               case 471:
                  if (curChar == 99)
                     jjstateSet[jjnewStateCnt++] = 470;
                  break;
               case 472:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 471;
                  break;
               case 473:
                  if (curChar == 116)
                     jjstateSet[jjnewStateCnt++] = 472;
                  break;
               case 474:
                  if (curChar == 111)
                     jjstateSet[jjnewStateCnt++] = 473;
                  break;
               case 475:
                  if (curChar == 114)
                     jjstateSet[jjnewStateCnt++] = 474;
                  break;
               case 476:
                  if (curChar == 112)
                     jjstateSet[jjnewStateCnt++] = 475;
                  break;
               case 478:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 477;
                  break;
               case 479:
                  if (curChar == 110)
                     jjstateSet[jjnewStateCnt++] = 478;
                  break;
               case 480:
                  if (curChar == 114)
                     jjstateSet[jjnewStateCnt++] = 479;
                  break;
               case 481:
                  if (curChar == 111)
                     jjstateSet[jjnewStateCnt++] = 480;
                  break;
               case 482:
                  if (curChar == 116)
                     jjstateSet[jjnewStateCnt++] = 481;
                  break;
               case 483:
                  if (curChar == 99)
                     jjstateSet[jjnewStateCnt++] = 482;
                  break;
               case 484:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 483;
                  break;
               case 485:
                  if (curChar == 118)
                     jjstateSet[jjnewStateCnt++] = 484;
                  break;
               case 486:
                  if (curChar == 95)
                     jjstateSet[jjnewStateCnt++] = 485;
                  break;
               case 487:
                  if (curChar == 100)
                     jjstateSet[jjnewStateCnt++] = 486;
                  break;
               case 488:
                  if (curChar == 110)
                     jjstateSet[jjnewStateCnt++] = 487;
                  break;
               case 489:
                  if (curChar == 97)
                     jjstateSet[jjnewStateCnt++] = 488;
                  break;
               case 490:
                  if (curChar == 112)
                     jjstateSet[jjnewStateCnt++] = 489;
                  break;
               case 491:
                  if (curChar == 120)
                     jjstateSet[jjnewStateCnt++] = 490;
                  break;
               case 492:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 491;
                  break;
               case 493:
                  if (curChar == 111)
                     jjstateSet[jjnewStateCnt++] = 492;
                  break;
               case 494:
                  if (curChar == 116)
                     jjstateSet[jjnewStateCnt++] = 493;
                  break;
               case 495:
                  if (curChar == 117)
                     jjstateSet[jjnewStateCnt++] = 494;
                  break;
               case 496:
                  if (curChar == 97)
                     jjstateSet[jjnewStateCnt++] = 495;
                  break;
               case 498:
                  if (curChar == 97)
                     jjstateSet[jjnewStateCnt++] = 497;
                  break;
               case 499:
                  if (curChar == 110)
                     jjstateSet[jjnewStateCnt++] = 498;
                  break;
               case 500:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 499;
                  break;
               case 501:
                  if (curChar == 116)
                     jjstateSet[jjnewStateCnt++] = 500;
                  break;
               case 502:
                  if (curChar == 97)
                     jjstateSet[jjnewStateCnt++] = 501;
                  break;
               case 503:
                  if (curChar == 103)
                     jjstateSet[jjnewStateCnt++] = 502;
                  break;
               case 504:
                  if (curChar == 95)
                     jjstateSet[jjnewStateCnt++] = 503;
                  break;
               case 505:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 504;
                  break;
               case 506:
                  if (curChar == 118)
                     jjstateSet[jjnewStateCnt++] = 505;
                  break;
               case 507:
                  if (curChar == 111)
                     jjstateSet[jjnewStateCnt++] = 506;
                  break;
               case 508:
                  if (curChar == 109)
                     jjstateSet[jjnewStateCnt++] = 507;
                  break;
               case 509:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 508;
                  break;
               case 510:
                  if (curChar == 114)
                     jjstateSet[jjnewStateCnt++] = 509;
                  break;
               case 511:
                  if (curChar == 101)
                     { jjCheckNAdd(173); }
                  break;
               case 512:
                  if (curChar == 109)
                     jjstateSet[jjnewStateCnt++] = 511;
                  break;
               case 513:
                  if (curChar == 97)
                     jjstateSet[jjnewStateCnt++] = 512;
                  break;
               case 514:
                  if (curChar == 110)
                     jjstateSet[jjnewStateCnt++] = 513;
                  break;
               case 515:
                  if (curChar == 116)
                     jjstateSet[jjnewStateCnt++] = 514;
                  break;
               case 516:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 515;
                  break;
               case 517:
                  if (curChar == 110)
                     jjstateSet[jjnewStateCnt++] = 516;
                  break;
               case 518:
                  if (curChar == 95)
                     jjstateSet[jjnewStateCnt++] = 517;
                  break;
               case 519:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 518;
                  break;
               case 520:
                  if (curChar == 118)
                     jjstateSet[jjnewStateCnt++] = 519;
                  break;
               case 521:
                  if (curChar == 111)
                     jjstateSet[jjnewStateCnt++] = 520;
                  break;
               case 522:
                  if (curChar == 109)
                     jjstateSet[jjnewStateCnt++] = 521;
                  break;
               case 523:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 522;
                  break;
               case 524:
                  if (curChar == 114)
                     jjstateSet[jjnewStateCnt++] = 523;
                  break;
               case 525:
                  if (curChar == 111)
                     jjstateSet[jjnewStateCnt++] = 524;
                  break;
               case 526:
                  if (curChar == 110)
                     jjstateSet[jjnewStateCnt++] = 525;
                  break;
               case 528:
                  if (curChar == 97)
                     jjstateSet[jjnewStateCnt++] = 527;
                  break;
               case 529:
                  if (curChar == 110)
                     jjstateSet[jjnewStateCnt++] = 528;
                  break;
               case 530:
                  if (curChar == 116)
                     jjstateSet[jjnewStateCnt++] = 529;
                  break;
               case 531:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 530;
                  break;
               case 532:
                  if (curChar == 110)
                     jjstateSet[jjnewStateCnt++] = 531;
                  break;
               case 533:
                  if (curChar == 95)
                     jjstateSet[jjnewStateCnt++] = 532;
                  break;
               case 534:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 533;
                  break;
               case 535:
                  if (curChar == 118)
                     jjstateSet[jjnewStateCnt++] = 534;
                  break;
               case 536:
                  if (curChar == 111)
                     jjstateSet[jjnewStateCnt++] = 535;
                  break;
               case 537:
                  if (curChar == 109)
                     jjstateSet[jjnewStateCnt++] = 536;
                  break;
               case 538:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 537;
                  break;
               case 539:
                  if (curChar == 114)
                     jjstateSet[jjnewStateCnt++] = 538;
                  break;
               case 541:
                  if (curChar == 110)
                     jjstateSet[jjnewStateCnt++] = 540;
                  break;
               case 542:
                  if (curChar == 103)
                     jjstateSet[jjnewStateCnt++] = 541;
                  break;
               case 543:
                  if (curChar == 105)
                     jjstateSet[jjnewStateCnt++] = 542;
                  break;
               case 544:
                  if (curChar == 115)
                     jjstateSet[jjnewStateCnt++] = 543;
                  break;
               case 546:
                  if (curChar == 110)
                     jjstateSet[jjnewStateCnt++] = 545;
                  break;
               case 547:
                  if (curChar == 103)
                     jjstateSet[jjnewStateCnt++] = 546;
                  break;
               case 548:
                  if (curChar == 105)
                     jjstateSet[jjnewStateCnt++] = 547;
                  break;
               case 549:
                  if (curChar == 115)
                     jjstateSet[jjnewStateCnt++] = 548;
                  break;
               case 550:
                  if (curChar == 110)
                     jjstateSet[jjnewStateCnt++] = 549;
                  break;
               case 551:
                  if (curChar == 117)
                     jjstateSet[jjnewStateCnt++] = 550;
                  break;
               case 553:
                  if (curChar == 114)
                     jjstateSet[jjnewStateCnt++] = 552;
                  break;
               case 554:
                  if (curChar == 111)
                     jjstateSet[jjnewStateCnt++] = 553;
                  break;
               case 555:
                  if (curChar == 119)
                     jjstateSet[jjnewStateCnt++] = 554;
                  break;
               case 556:
                  if (curChar == 121)
                     jjstateSet[jjnewStateCnt++] = 555;
                  break;
               case 557:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 556;
                  break;
               case 558:
                  if (curChar == 107)
                     jjstateSet[jjnewStateCnt++] = 557;
                  break;
               case 559:
                  if (curChar == 95)
                     jjstateSet[jjnewStateCnt++] = 558;
                  break;
               case 560:
                  if (curChar == 110)
                     jjstateSet[jjnewStateCnt++] = 559;
                  break;
               case 561:
                  if (curChar == 105)
                     jjstateSet[jjnewStateCnt++] = 560;
                  break;
               case 562:
                  if (curChar == 103)
                     jjstateSet[jjnewStateCnt++] = 561;
                  break;
               case 563:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 562;
                  break;
               case 564:
                  if (curChar == 98)
                     jjstateSet[jjnewStateCnt++] = 563;
                  break;
               case 566:
                  if (curChar == 114)
                     jjstateSet[jjnewStateCnt++] = 565;
                  break;
               case 567:
                  if (curChar == 111)
                     jjstateSet[jjnewStateCnt++] = 566;
                  break;
               case 568:
                  if (curChar == 119)
                     jjstateSet[jjnewStateCnt++] = 567;
                  break;
               case 569:
                  if (curChar == 121)
                     jjstateSet[jjnewStateCnt++] = 568;
                  break;
               case 570:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 569;
                  break;
               case 571:
                  if (curChar == 107)
                     jjstateSet[jjnewStateCnt++] = 570;
                  break;
               case 572:
                  if (curChar == 95)
                     jjstateSet[jjnewStateCnt++] = 571;
                  break;
               case 573:
                  if (curChar == 100)
                     jjstateSet[jjnewStateCnt++] = 572;
                  break;
               case 574:
                  if (curChar == 110)
                     jjstateSet[jjnewStateCnt++] = 573;
                  break;
               case 575:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 574;
                  break;
               case 577:
                  if (curChar == 101)
                     { jjCheckNAddTwoStates(578, 579); }
                  break;
               case 579:
                  if ((0x7fffffe87fffffeULL & l) != 0L)
                     { jjCheckNAddTwoStates(579, 580); }
                  break;
               case 580:
                  { jjCheckNAddTwoStates(580, 581); }
                  break;
               case 581:
               case 583:
                  if (curChar == 92)
                     { jjCheckNAdd(582); }
                  break;
               case 584:
                  if (kind > 70)
                     kind = 70;
                  { jjCheckNAddStates(47, 49); }
                  break;
               case 585:
                  { jjCheckNAddTwoStates(585, 583); }
                  break;
               case 586:
                  if (kind > 70)
                     kind = 70;
                  { jjCheckNAdd(586); }
                  break;
               case 587:
                  if (curChar == 110)
                     jjstateSet[jjnewStateCnt++] = 577;
                  break;
               case 588:
                  if (curChar == 105)
                     jjstateSet[jjnewStateCnt++] = 587;
                  break;
               case 589:
                  if (curChar == 102)
                     jjstateSet[jjnewStateCnt++] = 588;
                  break;
               case 590:
                  if (curChar == 101)
                     jjstateSet[jjnewStateCnt++] = 589;
                  break;
               case 591:
                  if (curChar == 100)
                     jjstateSet[jjnewStateCnt++] = 590;
                  break;
               case 592:
                  if (curChar == 96)
                     { jjCheckNAdd(591); }
                  break;
               case 593:
                  if (curChar == 96)
                     { jjCheckNAddStates(91, 137); }
                  break;
               default : break;
            }
         } while(i != startsAt);
      }
      else
      {
         int i2 = (curChar & 0xff) >> 6;
         unsigned long long l2 = 1ULL << (curChar & 077);
         do
         {
            switch(jjstateSet[--i])
            {
               case 595:
               case 1:
                  if ((jjbitVec0[i2] & l2) != 0L)
                     { jjCheckNAddStates(0, 2); }
                  break;
               case 0:
                  if ((jjbitVec0[i2] & l2) != 0L && kind > 18)
                     kind = 18;
                  break;
               case 29:
                  if ((jjbitVec0[i2] & l2) == 0L)
                     break;
                  if (kind > 59)
                     kind = 59;
                  { jjAddStates(35, 37); }
                  break;
               case 34:
                  if ((jjbitVec0[i2] & l2) != 0L)
                     { jjCheckNAddTwoStates(34, 35); }
                  break;
               case 36:
               case 37:
                  if ((jjbitVec0[i2] & l2) != 0L)
                     { jjCheckNAddTwoStates(37, 35); }
                  break;
               case 96:
                  if ((jjbitVec0[i2] & l2) != 0L)
                     { jjAddStates(41, 42); }
                  break;
               case 107:
                  if ((jjbitVec0[i2] & l2) != 0L)
                     { jjAddStates(43, 44); }
                  break;
               case 118:
                  if ((jjbitVec0[i2] & l2) != 0L)
                     { jjAddStates(45, 46); }
                  break;
               case 580:
                  if ((jjbitVec0[i2] & l2) != 0L)
                     { jjAddStates(150, 151); }
                  break;
               case 584:
                  if ((jjbitVec0[i2] & l2) == 0L)
                     break;
                  if (kind > 70)
                     kind = 70;
                  { jjCheckNAddStates(47, 49); }
                  break;
               case 585:
                  if ((jjbitVec0[i2] & l2) != 0L)
                     { jjCheckNAddTwoStates(585, 583); }
                  break;
               case 586:
                  if ((jjbitVec0[i2] & l2) == 0L)
                     break;
                  if (kind > 70)
                     kind = 70;
                  { jjCheckNAdd(586); }
                  break;
               default : break;
            }
         } while(i != startsAt);
      }
      if (kind != 0x7fffffff)
      {
         jjmatchedKind = kind;
         jjmatchedPos = curPos;
         kind = 0x7fffffff;
      }
      ++curPos;
      if ((i = jjnewStateCnt), (jjnewStateCnt = startsAt), (i == (startsAt = 594 - startsAt)))
         return curPos;
      if (input_stream->endOfInput()) { return curPos; }
      curChar = input_stream->readChar();
   }
}

/** Token literal values. */

Token * VerilogPreProcessorTokenManager::jjFillToken(){
   Token *t;
   JJString curTokenImage;
   int beginLine   = -1;
   int endLine     = -1;
   int beginColumn = -1;
   int endColumn   = -1;
   JJString im = jjstrLiteralImages[jjmatchedKind];
   curTokenImage = (im.length() == 0) ? input_stream->GetImage() : im;
   if (input_stream->getTrackLineColumn()) {
     beginLine = input_stream->getBeginLine();
     beginColumn = input_stream->getBeginColumn();
     endLine = input_stream->getEndLine();
     endColumn = input_stream->getEndColumn();
   }
   t = Token::newToken(jjmatchedKind, curTokenImage);
   t->specialToken = nullptr;
   t->next = nullptr;

   if (input_stream->getTrackLineColumn()) {
   t->beginLine = beginLine;
   t->endLine = endLine;
   t->beginColumn = beginColumn;
   t->endColumn = endColumn;
   }

   return t;
}
const int defaultLexState = 0;
/** Get the next Token. */

Token * VerilogPreProcessorTokenManager::getNextToken(){
  Token *matchedToken = nullptr;
  int curPos = 0;

  for (;;)
  {
   EOFLoop: 
   if (input_stream->endOfInput())
   {
      jjmatchedKind = 0;
      jjmatchedPos = -1;
      matchedToken = jjFillToken();
      return matchedToken;
   }
   curChar = input_stream->BeginToken();
   image = jjimage;
   image.clear();
   jjimageLen = 0;

   jjmatchedKind = 0x7fffffff;
   jjmatchedPos = 0;
   curPos = jjMoveStringLiteralDfa0_0();
   if (jjmatchedKind != 0x7fffffff)
   {
      if (jjmatchedPos + 1 < curPos)
         input_stream->backup(curPos - jjmatchedPos - 1);
      if ((jjtoToken[jjmatchedKind >> 6] & (1ULL << (jjmatchedKind & 077))) != 0L)
      {
         matchedToken = jjFillToken();
         return matchedToken;
      }
      else
      {
         SkipLexicalActions(nullptr);
         goto EOFLoop;
      }
   }
   int error_line = input_stream->getEndLine();
   int error_column = input_stream->getEndColumn();
   JJString error_after;
   bool EOFSeen = false;
   if (input_stream->endOfInput()) {
      EOFSeen = true;
      error_after = curPos <= 1 ? EMPTY : input_stream->GetImage();
      if (curChar == '\n' || curChar == '\r') {
         error_line++;
         error_column = 0;
      }
      else
         error_column++;
   }
   if (!EOFSeen) {
      error_after = curPos <= 1 ? EMPTY : input_stream->GetImage();
   }
   errorHandler->lexicalError(EOFSeen, curLexState, error_line, error_column, error_after, curChar, this);
  }
}


void  VerilogPreProcessorTokenManager::SkipLexicalActions(Token *matchedToken){
   switch(jjmatchedKind)
   {
      case 55 : {
         image.append(input_stream->GetSuffix(jjimageLen + (lengthOfMatch = jjmatchedPos + 1)));
           Token *t=jjFillToken();
           if(!parser->bParse)
           parser->outlineParser()->appString(t);
           parser->outlineParser()->sbb.append("\n");
           delete t;
         break;
       }
      case 56 : {
         image.append(input_stream->GetSuffix(jjimageLen + (lengthOfMatch = jjmatchedPos + 1)));
        parser->outlineParser()->appString("\r");parser->outlineParser()->sbb.append("\r");
         break;
       }
      case 57 : {
         image.append(input_stream->GetSuffix(jjimageLen + (lengthOfMatch = jjmatchedPos + 1)));
           if(!parser->bParse)
           parser->outlineParser()->appString("\t");
           parser->outlineParser()->sbb.append("\t");
         break;
       }
      case 58 : {
         image.append(input_stream->GetSuffix(jjimageLen + (lengthOfMatch = jjmatchedPos + 1)));
          if(!parser->bParse)
          parser->outlineParser()->appString(" ");
          parser->outlineParser()->appStringSkip(" ");
         break;
       }
      case 59 : {
         image.append(input_stream->GetSuffix(jjimageLen + (lengthOfMatch = jjmatchedPos + 1)));
                                                                         Token *t=jjFillToken();parser->outlineParser()->parseComment(t);delete t;
         break;
       }
      case 60 : {
         image.append(input_stream->GetSuffix(jjimageLen + (lengthOfMatch = jjmatchedPos + 1)));
                                                                             parser->outlineParser()->parseComment(jjFillToken());
         break;
       }
      case 61 : {
         image.append(input_stream->GetSuffix(jjimageLen + (lengthOfMatch = jjmatchedPos + 1)));
                                                   parser->outlineParser()->ifdef(jjFillToken());
         break;
       }
      case 62 : {
         image.append(input_stream->GetSuffix(jjimageLen + (lengthOfMatch = jjmatchedPos + 1)));
                                                     parser->outlineParser()->ifndef(jjFillToken());
         break;
       }
      case 63 : {
         image.append(input_stream->GetSuffix(jjimageLen + (lengthOfMatch = jjmatchedPos + 1)));
                                                     parser->outlineParser()->undef(jjFillToken());
         break;
       }
      case 64 : {
         image.append(input_stream->GetSuffix(jjimageLen + (lengthOfMatch = jjmatchedPos + 1)));
                                                    parser->outlineParser()->elsif(jjFillToken());
         break;
       }
      case 65 : {
         image.append(input_stream->GetSuffix(jjimageLen + (lengthOfMatch = jjmatchedPos + 1)));
                               parser->outlineParser()->_else(jjFillToken());
         break;
       }
      case 66 : {
         image.append(input_stream->GetSuffix(jjimageLen + (lengthOfMatch = jjmatchedPos + 1)));
                              parser->outlineParser()->endif(jjFillToken());
         break;
       }
      case 67 : {
         image.append(input_stream->GetSuffix(jjimageLen + (lengthOfMatch = jjmatchedPos + 1)));
                                              parser->outlineParser()->include(jjFillToken());
         break;
       }
      case 68 : {
         image.append(input_stream->GetSuffix(jjimageLen + (lengthOfMatch = jjmatchedPos + 1)));
                                              parser->outlineParser()->define(jjFillToken());
         break;
       }
      case 69 : {
         image.append(input_stream->GetSuffix(jjimageLen + (lengthOfMatch = jjmatchedPos + 1)));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                Token *t=jjFillToken();parser->outlineParser()->appSysMacros(t);
         break;
       }
      case 70 : {
         image.append(input_stream->GetSuffix(jjimageLen + (lengthOfMatch = jjmatchedPos + 1)));
     parser->outlineParser()->macro(jjFillToken(),false);
         break;
       }
      default :
         break;
   }
}
  /** Reinitialise parser. */
  void VerilogPreProcessorTokenManager::ReInit(JAVACC_CHARSTREAM *stream, int lexState) {
    clear();
    jjmatchedPos = jjnewStateCnt = 0;
    curLexState = lexState;
    input_stream = stream;
    ReInitRounds();
    debugStream = stdout; // init
    SwitchTo(lexState);
    errorHandler = new TokenManagerErrorHandler();
  }

  void VerilogPreProcessorTokenManager::ReInitRounds() {
    int i;
    jjround = 0x80000001;
    for (i = 594; i-- > 0;)
      jjrounds[i] = 0x80000000;
  }

  /** Switch to specified lex state. */
  void VerilogPreProcessorTokenManager::SwitchTo(int lexState) {
    if (lexState >= 1 || lexState < 0) {
      JJString message;
#ifdef WIDE_CHAR
      message += L"Error: Ignoring invalid lexical state : ";
      message += lexState; message += L". State unchanged.";
#else
      message += "Error: Ignoring invalid lexical state : ";
      message += lexState; message += ". State unchanged.";
#endif
      throw new TokenMgrError(message, INVALID_LEXICAL_STATE);
    } else
      curLexState = lexState;
  }

  /** Constructor. */
  VerilogPreProcessorTokenManager::VerilogPreProcessorTokenManager (JAVACC_CHARSTREAM *stream, int lexState)
  : PreTokenParser()
  {
    input_stream = nullptr;
    ReInit(stream, lexState);
  }

  // Destructor
  VerilogPreProcessorTokenManager::~VerilogPreProcessorTokenManager () {
    clear();
  }

  // clear
  void VerilogPreProcessorTokenManager::clear() {
    //Since input_stream was generated outside of TokenManager
    //TokenManager should not take care of deleting it
    //if (input_stream) delete input_stream;
    if (errorHandler) delete errorHandler, errorHandler = nullptr;    
  }


}
