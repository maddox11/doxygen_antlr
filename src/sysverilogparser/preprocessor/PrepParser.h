

#ifndef PREPARSER_H
#define PREPARSER_H
#include "Token.h"
#include <string>
#include <iostream>
#include <list>
#include <map>
#include <fstream>
#include "BitS.h"
#include "filedef.h"
#include "mutex"
#include <regex>
using namespace std;

namespace prepc
{

   class DefMacro
   {
   public:
      int beginLine;
      int endLine;
      int column;
      int arg;
      string mName;
      string mDefinition;
      string fi;
      // defined macro (..,...,)
      list<string> li;
      // macros
      vector<string> lm;
      map<string, string> hm;

      ~DefMacro() { /* std::cout << "\ndelete:" << mName << "\n"; */ }
      DefMacro() {}
      DefMacro(string s) : mName(s) {}
      DefMacro(string mDef, list<string> l, map<string, string> &mm);
      DefMacro(string mDef, list<string> l);

      void setFileName(string f);
      void setMacroList(list<string> &li);
      int getNumArg();
      bool isLmEmpty();
      string getMacro(int i);
      string getSelfDefiniton(string &s);
      int findParam(string key);
      string getMacroParam(string &p);
      void debug();
   };

   class ConcurrentMap
   {
   public:
      prepc::DefMacro *get(const std::string &key)
      {
         std::lock_guard<std::mutex> lock(m_mutex);
         auto it = ml.find(key);
         if (it != ml.end())
         {
            return it->second;
         }
         return NULL;
      }

      void write(const std::string &key, prepc::DefMacro *df)
      {
         std::unique_lock<std::mutex> lock(m_mutex);
         ml.insert({key, df});
         // ml[key] = df;
      }

      size_t size()
      {
         std::lock_guard<std::mutex> lock(m_mutex);
         return ml.size();
      }

      void clear()
      {
         std::lock_guard<std::mutex> lock(m_mutex);
         ml.clear();
      }

   private:
      // DefMacro *
      std::map<std::string, prepc::DefMacro *> ml;
      std::mutex m_mutex;
   };

   class PrepParser
   {
   public:
      static ConcurrentMap cmp;
      static void clearConcMap() { cmp.clear(); }
      struct DefCont
      {
         string image;
         string ifdef;
         int line;
         bool parse;
         int level;

         ~DefCont() { /* std::cout<<"\n deleting: "<<ifdef<<" "<<image<<"\n";*/ }
         DefCont(const string &im, const string &s, int l, bool b, int lev);
         void debug();
      };

      class InsertDefinition
      {

      public:
         vector<string> al;
         DefMacro *d;

         InsertDefinition(list<string> &all, DefMacro *dd)
         {
            this->al.insert(al.begin(), all.begin(), all.end());
            this->d = dd;
         }

         string parseValue(string s);
         string getValue(string s);
      };

   public:
      int line = 0;
      int level = 0;
      string buf;
      int z_old = 0;
      bool pMM = false;
      bool parserOn = false;
      string sbb;

      list<DefCont *> ifMap;
      BitS bit;

      void setBitField(const string &s);
      string hasParams(string s);
      string parseData(string &file);

      void readFile(const string &fi, string &buffer);
      list<string> lAlg(string &s);

      map<string, DefMacro *> getMacros();
      void writeOutput(string &file, string &text);
      int find(list<string> arr, string key);
      // int find(string arr[], string key);
      void parseM(Token *t);
      list<string> getArguments(string &t);
      bool getParserState(int l, bool el);
      // bool getParserStateElif(int l);
      void adjust(int l);
      bool valIfdef(string &ifc, string &image, int line, bool flag, int l);
      int countLines(Token *tok, bool in);
      int countLines(string &tok, bool in, int s, int e);
      int countChar(const string &s, char c);
      // void checkString(Token *t);
      void appNewLines(int n);
      void appStringSpecial(const std::string &str);
      void appString0(Token *tok, bool ins);
      void appString(Token *tok);
      void appString(string str);
      void appStringSkip(Token *t);
      void appStringSkip(const char *c);
      void appSysMacros(Token *t);

      //----------------------------
      void endif(Token *tok);
      void ifdef(Token *tok);
      void ifndef(Token *tok);
      void _else(Token *tok);
      void elsif(Token *tok);
      void define(Token *tok);
      void undef(Token *tok);

      void macro(Token *tok, bool b);
      void include(Token *tok);
      void parseComment(Token *tok);
      string _parseComment(string s);
      void printStack();
      bool checkFile(string file);
      string insertDelLines(string sb, PrepParser *p);
      //----------------------------
      string getMName(string s);
      bool checkM(string reg, string m);
      // string getD(Token *p);
      int getDM(const string &m, int x);
      string evalMacro(string s1, bool ins, int beginLine);
      string match(string mac, const std::regex &r, InsertDefinition *gn);
      string parseT(string m);
      // string prepDef(string s);
      bool checkQ3(prepc::Token *tok);
      void includeDir();
      string insertMacroName(string s, PrepParser *p);
      void replaceString(string &s, InsertDefinition *gn);
      PrepParser(bool b);
      PrepParser() {};
      PrepParser(const std::string &f);
      void _clearAll();
      ~PrepParser()
      {
         for (auto it = ifMap.begin(); it != ifMap.end(); it++)
            delete *it;
      }

   private:
      std::string m_file;
      bool m_psource;
      std::map<std::string, DefMacro *> dma;

   }; // Prepparser
   void replace(string &str, const char *suf, const char *ref);
   void printMacros(bool b);
   void writeMacros();
   // void searchDirectories(const string &p);
   void searchDirectories();

   // sentinal for outline source code `ifdef .... `endif
   const std::string OUTL = "<<!";

}

std::string cutComment(std::string &line);
std::string getFileFromPath(const std::string &f);
typedef std::map<string, prepc::DefMacro *> DefVec;
#endif
