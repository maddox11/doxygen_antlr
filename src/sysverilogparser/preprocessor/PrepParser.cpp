
#include "stdlib.h"
#include "cstring"
#include "VerilogPreProcessor.h"
#include "VerilogPreProcessorTokenManager.h"
#include "CharStream.h"
#include "ErrorHandler.h"
#include "PreProcessorErrorHandler.h"
#include "math.h"
#include <regex>
#include <iterator>
#include <sstream>
#include <algorithm>
#include <filesystem>
#include "Token.h"
#include "BitS.h"
#include "filename.h"
#include "doxygen.h"
#include "config.h"
#include "PrepParser.h"

static const string ANSI_RESET = "\u001B[0m";
static const string ANSI_RED = "\u001B[31m";
static const string ANSI_GREEN = "\u001B[32m";
static const string ANSI_YELLOW = "\u001B[33m";
static const string ANSI_CYAN = "\u001B[36m";
static const string ANSI_WHITE = "\u001B[37m";

namespace fs = std::filesystem;
using namespace std;

namespace prepc
{
    static bool lock1 = false;
    template <typename Base, typename T>
   
    inline bool instanceof(const T *ptr)
    {
        return dynamic_cast<const Base *>(ptr) != nullptr;
    }

    const std::string reg_word = "[a-zA-Z_$][a-zA-Z_0-9]*|[\"][^\n\r]+[\"]";
    const std::string mword = "[`][a-zA-Z_$][a-zA-Z_0-9]*";
    const std::string reg_key = "[`][\"]";
    const std::string regex2 = "[`][`][a-zA-Z_0-9$]*";
    const std::string regMacro = "[`][\\w]+[(][^\n\r]*";
    const std::string remCom = "[/][/][^\n\r\\\\]*[\n\r]|[/][*][^*/]*[*][/]";
    const std::string remSen = "[@][@][^\n\r\t]*[\n]";
    const std::regex mp(mword);
    // stores all parsed macros

    static map<string, DefMacro *> ml;
    ConcurrentMap PrepParser::cmp;

    static list<string> pathArr;

    std::map<std::string, std::string> hss;

   
    void trim(std::string &s);
    std::string getPath(const std::string &p);

    void writeMacroWarning(const std::string &name, int i);
    void writeFileWarning(const std::string &name, int i);

    void PrepParser::_clearAll()
    {
        for (const auto &[key, macro] : ml)
        {
            delete macro;
        }
       
    }

    void replace(string &str, const char *suf, const char *ref)
    {
        std::regex regg(suf);
        std::string x1 = std::regex_replace(str, regg, ref);
        str = x1;
    }

     void ltrim(std::string &s)
    {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch)
                                        { return !std::isspace(ch); }));
    }

       void rtrim(std::string &s)
    {
        s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch)
                             { return !std::isspace(ch); })
                    .base(),
                s.end());
    }

    // trim from both ends (in place)
    void trim(std::string &s)
    {
        rtrim(s);
        ltrim(s);
    }

    static bool endsWith(const std::string &str, const std::string &suffix)
    {
        return str.size() >= suffix.size() && 0 == str.compare(str.size() - suffix.size(), suffix.size(), suffix);
    }

    PrepParser::PrepParser(bool b) : m_psource(b) {}

    PrepParser::PrepParser(const std::string &s) : m_file(s) {}

    std::string PrepParser::parseData(string &str)
    {
        setBitField(str);
        //  std::cout << str << "\n";
        CharStream *sc = new CharStream(str.data(), str.size(), 1, 1);
        VerilogPreProcessorTokenManager *tokenManager = new VerilogPreProcessorTokenManager(sc);
        VerilogPreProcessor *parser = new VerilogPreProcessor(tokenManager);
        parser->setOutlineParser(this);
        PreProcessorErrorHandler *parserErrHandler = new PreProcessorErrorHandler("xxxx");
        parser->setErrorHandler(parserErrHandler);
        tokenManager->setLexParser(parser);

        try
        {
            parser->source_text();
        }
        catch (std::exception &e)
        {
            fprintf(stderr, "\n[%s]\n", e.what());
        }
           std::string r = insertDelLines(buf, this);
        // printStack();
        // printMacros(true);

        delete parser;
        delete tokenManager;
        delete sc;

        return r;
    }

    int PrepParser::countChar(const string &s, char c)
    {
        int count = 0;
        for (size_t j = 0; j < s.length(); j++)
        {
            if (s.at(j) == c)
                count++;
        }
        return count;
    }

    void PrepParser::includeDir()
    {
        // searchDirectories(inc);
        // for (auto it = Doxygen::includeNameLinkedMap->begin(); it != Doxygen::includeNameLinkedMap->end(); it++)
        if (prepc::lock1)
            return;

        prepc::lock1 = true;
        FileNameLinkedMap *pf = Doxygen::includeNameLinkedMap;
        // auto it =
        for (auto it = pf->begin(); it != pf->end(); it++)
        {
            const FileName *fnn = it->get();
            std::string fi = fnn->fullName().data();
            prepc::PrepParser p;
            std::string str;
            std::cout << "\npreprocessing file:" << fi << endl;
            p.readFile(fi, str);
            p.parseData(str);
        }
    }

    void PrepParser::readFile(const string &fi, string &buffer)
    {
        buffer = fileToString(QCString(fi), true).data();
    }

    void PrepParser::setBitField(const string &s)
    {
        int l = countChar(s, '\n');
        bit.setSize(l + l + 1000);
    }

    map<string, DefMacro *> PrepParser::getMacros()
    {
        return dma;
    }

    void writeMacros()
    {
        std::ofstream outf("prepmacros.txt", std::ofstream::out | std::ofstream::binary);

        TextStream t(&outf);

        for (const auto &[name, df] : ml)
        {
            t << "-----------###########-----------------";
            t << "\n";
            t << df->mName;
            t << " at line: ";
            t << df->beginLine;
            t << "\n";
            t << "map contains:\n";
            for (auto it = df->hm.begin(); it != df->hm.end(); ++it)
            {
                t << it->first;
                t << " => ";
                t << it->second;
                t << '\n';
            }

            for (std::string s : df->li)
            {
                t << "<";
                t << s;
                t << ">\n";
            }

            t << "-----------###########-----------------\n";
            t << df->mDefinition;
            t << "\n";
            t << "-----------##### end ######-----------------\n";
        }
        t << "\n\n\nfound: ";
        t << PrepParser::cmp.size();
        t << " macros\n";
    }

    void printMacros(bool b)
    {
        std::cout << ANSI_CYAN;
        for (const auto &[name, df] : ml)
        {
            df->debug();
        }
        std::cout << ANSI_RESET;
    } // printMacros

    void PrepParser::printStack()
    {
    }

    void PrepParser::writeOutput(string &file, string &text)
    {
        std::ofstream outfile(file.c_str(), std::ofstream::out | std::ofstream::binary);

        if (!outfile.is_open())
        {
            std::cerr << ANSI_RED;
            std::cerr << "could not open file:" << file << endl;
            std::cerr << ANSI_RESET;
            return;
        }
        outfile.write(text.c_str(), text.size());
        outfile.close();
    }

    int PrepParser::find(list<string> arr, string key)
    {
        int j = 0;
        for (string str : arr)
        {
            if (key.compare(str) == 0)
                return j;
            j++;
        }
        return -1;
    }

    void PrepParser::parseM(Token *t)
    {
        //   std::cout << t->image << "\n\n";
        bool bb = false;
        replace(t->image, "`define", "");
        PrepParser prep(m_file);
        prep.setBitField(t->image);
        CharStream *sc = new CharStream(t->image.data(), t->image.size(), 1, 1);
        VerilogPreProcessorTokenManager *tokenManager = new VerilogPreProcessorTokenManager(sc);
        VerilogPreProcessor *parser = new VerilogPreProcessor(tokenManager);
        PreProcessorErrorHandler *parserErrHandler = new PreProcessorErrorHandler("macro");
        parser->setErrorHandler(parserErrHandler);
        parser->setOutlineParser(&prep);
        tokenManager->setLexParser(parser);
        prep.pMM = true;
        DefMacro *df = new DefMacro();
        df->beginLine = t->beginLine;
        df->endLine = t->endLine;
        df->column = t->beginColumn;
        try
        {
            bb = parser->parse_macro(df);
        }
        catch (exception &e)
        {
            cout << e.what();
        }

        delete parser;
        delete tokenManager;
        delete sc;

        if (bb)
        {
            trim(t->image);
            prep.buf = t->image.substr(df->mName.length());
        }

        replace(prep.buf, "\\\\\n", "\n");

        std::size_t i = prep.buf.length() - 1;
        std::size_t l = prep.buf.find_last_of("\\");

        if (l == i && l != std::string::npos)
        {
            df->mDefinition = prep.buf.substr(0, i);
        }
        else
            df->mDefinition = prep.buf;

        PrepParser::cmp.write(df->mName, df);
        dma.insert(std::make_pair(df->mName, df));
        prep.pMM = false;
    }

    list<string> PrepParser::getArguments(string &t)
    {
        trim(t);
        list<string> tl, lis;
        // std::cout << t << endl;
        size_t e = t.find_first_of('(');
        size_t e1 = t.find_last_of(')');

        if (e == std::string::npos || e1 == std::string::npos)
        {
            lis.emplace_back(t);
            return lis;
        }
        e++;
        size_t f = t.find_last_of(')');

        std::string sc = t.substr(e, f - e);
        string name = t.substr(0, e - 1);
        trim(name);
        lis = lAlg(sc);
        string reg = OUTL;

        for (string sv : lis)
        {
            trim(sv);
            replace(sv, reg.c_str(), ",");
            replace(sv, "\\\\\n", "\n");
            tl.emplace_back(sv);
        }

        tl.emplace_back(name);

        return tl;
    }

    string PrepParser::_parseComment(string s)
    {
        string reg = "[\"][^\"]*[\"]";
        std::regex word_regex(reg.data());

        auto words_begin = std::sregex_iterator(s.begin(), s.end(), word_regex);
        auto words_end = std::sregex_iterator();

        string sb;
        std::string suff_str = s;
        for (std::sregex_iterator i = words_begin; i != words_end; ++i)
        {
            std::smatch match = *i;
            std::string match_str = match.str();
            std::string pre_str = match.prefix();
            suff_str = match.suffix();
            replace(match_str, ",", ".");
            sb.append(pre_str);
            sb.append(match_str);
        }
        sb = sb.append(suff_str);

        return sb;
    }

    list<string> PrepParser::lAlg(string &s)
    {
        int count = 0;
        string sb;
        bool found = false;

        for (size_t j = 0; j < s.length(); j++)
        {
            if (s.at(j) == '(')
            {
                found = true;
                count++;
            }

            if (s.at(j) == ')')
            {
                count--;
                if (found && count == 0)
                {
                    found = false;
                }
            }

            if (found && s.at(j) == ',')
            {
                //  sb[j] = '@';
                sb.append(OUTL);
                continue;
            }
            sb.append(1, s[j]);
        }

        found = false;
        s = sb;
        sb.clear();
        for (size_t j = 0; j < s.length(); j++)
        {

            if (s.at(j) == '"' && found)
            {
                found = false;
                sb.append(1, s[j]);
                continue;
            }

            if (s.at(j) == '"')
            {
                found = true;
            }

            if (found && s.at(j) == ',')
            {
                //   sb[j] = '@';
                sb.append(OUTL);
                continue;
            }
            sb.append(1, s[j]);
        }

        list<string> lii;
        bool lb = false;
        count = 0;
        string buf;

        for (size_t j = 0; j < sb.length(); j++)
        {
            char val = sb.at(j);
            if (val == ',' && !lb)
            {
                lii.emplace_back(buf);
                buf.clear();
                continue;
            }

            buf += val;
            if (val == '{')
            {
                count++;
                lb = true;
            }

            if (val == '}')
            {
                count--;
                if (count == 0)
                {
                    lb = false;
                }
            }
        }
        if (buf.length() > 0)
        {
            replace(buf, "\n", "");
            lii.emplace_back(buf);
        }

        return lii;
    }

    string PrepParser::insertDelLines(string sb, PrepParser *p)
    {

        string buff;
        int line = 1;

        // std::cout << sb << "\n";
        string::iterator it;
        for (it = sb.begin(); it != sb.end(); it++)
        {
            auto c = *it;
            if (c == '\n')
            {
                buff += c;
                if (p->bit.test(line + 1))
                {
                    auto v = *(it + 1);
                    if (v != '@')
                        buff.append(OUTL);
                }
                line++;
            }
            else
                buff += c;
        } // for
        return buff;
    } // insert

    bool PrepParser::checkFile(string file)
    {
        std::map<string, string>::iterator it = hss.find(file);
        if (it == hss.end())
        {
            std::pair<string, string> p(file, file);
            hss.emplace(p);
            return false;
        }
        std::cout << "File:" << file << "  already included " << "\n";
        return true;
    }

    bool PrepParser::getParserState(int l, bool els)
    {
        int len = ifMap.size();
        if (len == 0)
            return false;

        if (len == 1)
            return ifMap.front()->parse;

        for (auto it = ifMap.rbegin(); it != ifMap.rend(); it++)
        {
            DefCont *c = *it;
            if (c->level < l)
            {
                if (els)
                    return !c->parse;

                return c->parse;
            }
            else
            {
                if (c->level == l && !c->parse)
                    return true;
            }
        }
        return false;
    }

    void PrepParser::adjust(int l)
    {
        DefCont *c = ifMap.back();
        if (c == null)
            return;
        while (c->level == l)
        {
            delete c;
            ifMap.pop_back();
            if (ifMap.empty())
                break;
            c = ifMap.back();
        }
    }

    bool PrepParser::valIfdef(string &ifc, string &image, int line, bool flag, int l)
    {
        trim(image);
        string arg = image;
        DefCont *def = 0;
        bool els = (ifc.find("`elsif") != string::npos);
        if (els)
        {
            bool z = getParserState(l, true);
            bool c = (PrepParser::cmp.get(arg) != NULL);

            if (c == false)
            {
                ifMap.emplace_back(def = new DefCont(arg, ifc, line, true, l));
                return true;
            }

            if (z == true)
            {
                ifMap.emplace_back(def = new DefCont(arg, ifc, line, false, l));
                return false;
            }

            ifMap.emplace_back(def = new DefCont(arg, ifc, line, true, l));
            return true;
        }

        bool state = getParserState(l, false);
        if (state)
        { // parserON //!
            ifMap.emplace_back(def = new DefCont(arg, ifc, line, true, l));
            //  valMap.emplace_back(def);
            return true;
        }
        else if ((PrepParser::cmp.get(arg) != NULL) == flag)
        {
            ifMap.emplace_back(def = new DefCont(arg, ifc, line, false, l));
            // valMap.emplace_back(def);
            return false;
        }
        else
        {
            ifMap.emplace_back(def = new DefCont(arg, ifc, line, true, l));
            //  valMap.emplace_back(def);
            return true;
        }
    }

    int PrepParser::countLines(string &tok, bool in, int bl, int el)
    {
        bool b = tok.compare("\n") == 0;
        if (b)
        {
            line++;
            z_old++;
            return 1;
        }
        int l = countChar(tok, '\n') + 1;
        int z_new = 0;

        if (in)
        {
            z_old = z_old - l + 1 + 1;
            z_new = z_old + l - 2;
        }
        else
            z_new = z_old + l - 1;

        line += l;

        int v = z_new + 2;
        int w = z_old + 1;

        int i = bl;
        int j = el;

        if (i == j)
        {
            bit.set((w), parserOn);
            //    std::cout << "bit:" << w << " [ " << parserOn << " ]\n";
        }
        else
        {
            // from ->tocountLines
            for (int i = w; i < v; i++)
            {
                bit.set(i, parserOn);
                //     std::cout << "bits:" << i << " [ " << parserOn << " ]\n";
            }
        }

        z_old = z_new;
        return l;
    }

    int PrepParser::countLines(Token *tok, bool in)
    {
        return countLines(tok->image, in, tok->beginLine, tok->endLine);
    }

    void PrepParser::appNewLines(int n)
    {
        for (int j = 0; j < n; j++)
            buf.append("\n");
    }

    void PrepParser::appStringSpecial(const std::string &str)
    {
        int num = countChar(str, '\n');
        // std::cout << this->line << " " << num << " " << z_old << "\n\n " << str << "---\n\n"
        //           << this->buf;
        // bit.out();
        bit.setSize(num + 1 + bit.getSize());
        // std::cout << "\n\n\n";
        // bit.out();
        z_old += num;
        appString(str);
    }

    void PrepParser::appString0(Token *tok, bool ins)
    {
        //  cout << "adding token0:" << tok->image << "\n";
        if (tok == null || tok->image.size() == 0)
            return;

        countLines(tok, ins);
        appString(tok->image);
    }

    void PrepParser::appString(Token *tok)
    {
        // cout << "adding token:" << tok->image << "\n";
        int l = countLines(tok, false);
        appNewLines(l);
    }

    void PrepParser::appString(string str)
    {
        buf.append(str);
    }

    void PrepParser::appStringSkip(const char *c)
    {
        //  std::cout<<"app sbb: "<<c<<"\n";
        sbb.append(c);
    }

    void PrepParser::appStringSkip(Token *t)
    {
        // std::cout<<"app sbb: "<<t->image<<"\n";
        sbb.append(t->image);
    }

    void PrepParser::appSysMacros(Token *t)
    {
        buf.append(OUTL);
        countLines(t, false);
        replace(t->image, "\n", "");
        appString(t->image);
        appNewLines(1);
    }

    void PrepParser::endif(Token *tok)
    {
        appString(OUTL);
        appString0(tok, false);

        adjust(level);
        level--;
        if (ifMap.size() == 0)
        {
            parserOn = false;
            return;
        }
        DefCont *d = ifMap.back();
        parserOn = d->parse;
    }

    void PrepParser::ifdef(Token *tok)
    {
        string s = tok->image;
        string sf = "`ifdef";
        replace(s, sf.c_str(), "");
        trim(s);
        parserOn = valIfdef(sf, s, tok->beginLine, true, ++level);
        appString(OUTL);
        appString0(tok, false);
    }

    void PrepParser::ifndef(Token *tok)
    {
        string s = tok->image;
        string sf = "`ifndef";
        replace(s, sf.c_str(), "");
        trim(s);
        parserOn = valIfdef(sf, s, tok->beginLine, false, ++level);
        appString(OUTL);
        appString0(tok, false);
    }

    void PrepParser::_else(Token *tok)

    {
        // DefCont *def = 0;
        bool state = getParserState(level, true);

        appString(OUTL);
        appString0(tok, false);
        if (level > 0)
            parserOn = !state;
        //  std::cout << buf << "\n";
        ifMap.emplace_back(new DefCont(" "s, "`else"s, tok->beginLine, parserOn, level));
        //  valMap.emplace_back(def);
    }

    void PrepParser::elsif(Token *tok)
    {
        string s = tok->image;
        string sf = "`elsif";
        replace(s, sf.c_str(), "");
        appString(OUTL);
        appString0(tok, false);
        parserOn = valIfdef(sf, s, tok->beginLine, true, level);
    }

    void PrepParser::define(Token *tok)
    {
        appString0(tok, false);
        replace(tok->image, "\n", "");
        macro(tok, true);
    }

    void PrepParser::macro(Token *tok, bool b)
    {
        if (!b)
        {
            appString0(tok, false);
        }

        bool isDef = (tok->image.find("`define") != std::string::npos);
        if (isDef && parserOn && !m_psource)
            return;

        if (isDef)
        {
            //   std::cout << "found macro definition: " << tok->image << "\n";
            parseM(tok);
        }
    }

    string PrepParser::hasParams(string s)
    {
        int x = 0;
        int y = 0;
        replace(s, "`define", " ");
        trim(s);
        string s1 = s;
        int l = s1.length();
        const std::regex mp(reg_word);

        auto words_begin = std::sregex_iterator(s1.begin(), s1.end(), mp);
        auto words_end = std::sregex_iterator();

        auto i = words_begin;

        if (!i->empty())
        {
            std::smatch match = *i;
            std::string match_str = match.str();
            std::string suf = match.suffix();
            std::string pref = match.prefix();
            x = match.position();
            y = match.str().size() + x;
            if (y == l)
                return s1;

            if (s1.at(y) != '(')
            {
                s1.insert(y, "()");
            }
        }
        size_t j = s1.find_last_of("\\");
        if (j != string::npos)
        {
            size_t f = s1.find_last_of("//");
            if (f != string::npos && f > j)
            {
                s1 = s1.erase(f, s1.length());
            }
        }
        return s1;
    }

    void PrepParser::include(Token *tok)
    {

        if (parserOn)
        {
            appString(OUTL);
        }
        appString0(tok, false);

#if 0
        replace(tok->image, "`include", "");

        std::string v = getFileFromPath(tok->image);
        std::string path = getPath(v);

        if (!path.empty())
        {
            // writeFileWarning(inc,l);
            std::cout << "file: " << path << "already included!\n";
            return;
        }

        pathArr.emplace_back(path);
        std::cout << ANSI_GREEN;
        std::cout << "parse file:" << v << endl;
        std::cout << ANSI_RESET;

        std::string str;
        PrepParser p(m_file);
        p.readFile(v, str);
        string res = p.parseData(str);
        //  std::cout << res;
        appStringSpecial(res);
#endif
    }

    void PrepParser::parseComment(Token *tok)
    {
        //  appString0("@@");
        appString0(tok, false);
        // appString(tok);
        //  this->line++;
    }

    void PrepParser::undef(Token *tok)
    {
        buf.append(OUTL);
        appString0(tok, false);
        string str = tok->image;
        replace(str, "`undef", "");
        // size_t er = ml.erase(str);
        int er = 0;
        if (er == 0)
        {
            cerr << "Could not undef:" << str << endl;
        }
    }

    string PrepParser::getMName(string s)
    {
        size_t i = s.find('(');
        string name = s.substr(0, i);
        replace(name, "`", "");
        return name;
    }

    bool PrepParser::checkM(string reg, string m)
    {
        std::regex word_regex(reg.data());
        auto words_begin = std::sregex_iterator(m.begin(), m.end(), word_regex);
        auto words_end = std::sregex_iterator();

        for (std::sregex_iterator i = words_begin; i != words_end; ++i)
        {
            std::smatch match = *i;
            std::string match_str = match.str();
            if (match_str.size() > 0)
            {
                return true;
            }
        }
        return false;
    }

#if 0
    string PrepParser::getD(Token *p)
    {
        int lp = countChar(p->image, '(');
        int rp = countChar(p->image, ')');

        string sb(p->image);

        if (lp == rp || rp > lp)
            return p->image;

        for (int j = 1; j < 200; j++)
        {
            Token *t = null; // parser->getToken(j);
            sb.append(t->image);
            lp += countChar(t->image, '(');
            rp += countChar(t->image, ')');
            if (lp == rp)
                break;
            if (t->kind == EOF)
                return sb;
        }
        return sb;
    }
#endif

    auto const regexbb = std::regex("[\"]([\\\\][^\r]|[^\r\n\"\\\\])*[\"]");
    auto const regexpr = std::regex("[`][\"\\\\]|[\"]([\\\\][^\r]|[^\r\n\"\\\\])*[\"]|[a-zA-Z_$][a-zA-Z_0-9]*|([`][`])");
    auto const regexprMacro = std::regex("[`][\\w]+[\\s]*[(]|[`][a-zA-Z_$][a-zA-Z_0-9]*");

    string PrepParser::evalMacro(string s1, bool ins, int beginLine)
    {
        std::string macroName;
        // std::cout << "eval macro:" << s1 << " : " << beginLine << "\n";
        list<string> hh = getArguments(s1);
        macroName = hh.back();
        replace(macroName, "`", "");
        DefMacro *def = null;

        def = PrepParser::cmp.get(macroName);
        if (def == null)
        {
            std::string val;
            bool b = (s1.find('\n') != std::string::npos);
#if 0
            if (b)
            {
                val = "<@>";
                val.append(s1);
                val.append("<@>");
            }
            else
#endif
            val = "||>";
            val.append(s1);
            val.append("<||");

            //      replace(s1, "`", "");
            writeMacroWarning(s1, beginLine);
            //     val.append(s1);
            // std::cout << val << "\n";
            std::cout << "\nmacro not found:" << macroName << " in file:" << m_file << " at line:" << beginLine << "\n";
            Token *t = Token::newToken(11, val);
            t->endLine = countLines(t, false);
            appString0(t, true);
            delete t;
            //   exit(0);
            return "";
        }

        //  std::cout << " : " << macroName << " : " << def->beginLine << "\n";

        if (def->mDefinition.empty())
            return "";

        def->setMacroList(hh);
        int bl = countChar(def->mDefinition, '\n');
        this->bit.setSize(bit.getSize() + bl);
        replace(def->mDefinition, "\\\\\n", "\n");
        // std::cout << "bit size" << this->bit.getSize() <<" : "<<macroName<<" : "<<def->beginLine<< "\n";

        string ww = parseT(def->mDefinition);
        ww.append("\n");
        replace(ww, remCom.c_str(), "");
        trim(ww);
        InsertDefinition id(hh, def);
        std::string res = match(ww, regexpr, &id);
        //  std::cout << "\n\n [ " << res << " ]\n  \n";
        res = match(res, regexprMacro, &id);
        //  std::cout << "\nafter eval:\n [ " << res << " ]\n  \n";
        if (ins)
        {
            Token t(11, res);
            t.endLine = countLines(&t, false);
            appString0(&t, true);
        }

        return res;
    }

    string PrepParser::match(string mac, const std::regex &r, InsertDefinition *gn)
    {
        auto words_begin = std::sregex_iterator(mac.begin(), mac.end(), r);
        auto words_end = std::sregex_iterator();
        int x = 0, y = 0, z = 0, k = 0;
        int len = mac.length();
        string sb;
        std::smatch match;
        std::string suff_str = mac;
        for (std::sregex_iterator i = words_begin; i != words_end; ++i)
        {
            std::string name;
            match = *i;
            std::string str = match.str();

            suff_str = match.suffix();
            x = match.position();
            if (x < k)
                continue;
            y = match.length() + x;
            //   std::cout << "[ match: " << str << "]\n";
            int len = str.size();

            if (str[0] == '`' && len >= 2)
            {
                if (str[1] == '"')
                    name += '"';
                else if (str[1] == '\\')
                    name = "\\";
                else if (str.find('(') != std::string::npos)
                {
                    y = getDM(mac, x);
                    k = y;
                    name = mac.substr(x, (y - x));
                    name = evalMacro(name, false, 0);
                    //    std::cout << "eval macro :\n"
                    //            << str << "\n[" << name << "]\n";
                }
                else if (str[1] == '`')
                {
                    name = "";
                }
                else
                {
                    // name = mac.substr(x, match.length());
                    name = evalMacro(str, false, 1);
                    //      std::cout << "found macro: [" << str << "]\n";
                }
            }
            else if (str[0] == '"')
            {
                name = str;
                //      std::cout << "found string:" << str << "\n";
            }
            else
            {
                name = mac.substr(x, match.length());
                name = gn->parseValue(str);
                //       std::cout << "found word:" << str << "\n";
            }

            int l = abs(z - x);
            std::string op = mac.substr(z, l);
            sb.append(op);
            sb.append(name);
            //   std::cout << "{ added sb:" << sb.c_str() << "}\n\n";
            z = y;
        } // regex

        if (len > z)
            sb.append(mac.substr(y));

        return sb;
    }

    string PrepParser::insertMacroName(string s, PrepParser *p)
    {

        string name = p->getMName(s);
        DefMacro *def = null;
        def = PrepParser::cmp.get(name);

        if (def == null)
        {
            replace(s, "`", "");
            return s;
        }
        name = p->evalMacro(s, false, 0);
        return name;
    }

    string PrepParser::InsertDefinition::getValue(string s)
    {
        // found "abc"
        if (s[0] == '"')
            return s;
        return d->getMacroParam(s);
    }

    string PrepParser::InsertDefinition::parseValue(string s)
    {
        trim(s);
        if (s.at(0) == '`' && s.at(1) == '`')
        {
            replace(s, "`", "");
            return getValue(s);
        }

        if (s.at(0) == '`')
        {
            replace(s, "`", "");
            auto itt = PrepParser::cmp.get(s);
            if (itt != NULL)
            {
                return itt->mDefinition;
            }
            return ""s;
        }

        return getValue(s);
    }

    DefMacro::DefMacro(string mDef, list<string> l, map<string, string> &mm)
    {

        li.insert(li.begin(), l.begin(), l.end());
        mName = li.back();
        li.pop_back();
        trim(mDef);
        mDefinition = mDef;
        hm.insert(mm.begin(), mm.end());
        PrepParser::cmp.write(mName, this);
    }

    DefMacro::DefMacro(string mDef, list<string> l)
    {
        li.insert(li.begin(), l.begin(), l.end());
        mName = li.back();
        trim(mDef);
        li.pop_back();
        // replace(mDef, "\\", "");
        mDefinition = mDef;
        PrepParser::cmp.write(mName, this);
    }

    void DefMacro::setFileName(string f) { fi = f; }

    void DefMacro::setMacroList(list<string> &li)
    {
        lm.clear();

        for (string str : li)
            lm.emplace_back(str);
    }

    int DefMacro::getNumArg()
    {
        return li.size();
    }

    bool DefMacro::isLmEmpty()
    {
        return lm.size() == 1;
    }

    string DefMacro::getMacro(int i)
    {
        if (i < (int)lm.size() - 1)
            return lm.at(i);

        return "";
    }

    string DefMacro::getSelfDefiniton(string &s)
    {
        auto it = hm.find(s);
        if (it != hm.end())
            return it->second;
        return ""s;
    }

    int DefMacro::findParam(string key)
    {
        int i = 0;
        for (string str : li)
        {
            if (key.compare(str) == 0)
            {
                return i;
            }
            i++;
        }
        return -1;
    }

    string DefMacro::getMacroParam(string &p)
    {
        string s;
        int i = findParam(p);
        // nothing to be done
        if (i == -1)
            return p;

        string s1 = getMacro(i);
        if (s1.length() > 0)
            return s1;

        map<string, string>::iterator it = hm.find(p);
        bool bb = it != hm.end();
        if (bb)
            s = it->second;

        if (s1.empty() && bb)
            return s;

        return "";
    }

    void DefMacro::debug()
    {
        cout << "-----------###########-----------------" << endl;
        cout << mName << " at line: " << beginLine << endl;

        std::cout << "map contains:\n";
        for (auto it = hm.begin(); it != hm.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';

        for (std::string s : li)
        {
            std::cout << "<" << s << ">\n";
        }
        cout << "-----------###########-----------------" << endl;
        cout << mDefinition << endl;
        cout << "-----------##### end ######-----------------" << endl;
    }

    PrepParser::DefCont::DefCont(const string &im, const string &s, int l, bool b, int lev)
        : image(im), ifdef(s), line(l), parse(b), level(lev) {}

    void PrepParser::DefCont::debug()
    {
        string tab = ("\t\t\t\t\t\t\t\t\t\t");
        string tl = tab.substr(0, level);
        string ok = parse ? "ON" : "OFF";
        ostringstream os;
        os << " " << tl << " " << ifdef << " " << " [" << ANSI_GREEN << " " << image << " " << ANSI_WHITE << "]  at line:" << line << " at level:" << level << " " + ok;
        cout << os.str() << endl;
    }

    string PrepParser::parseT(string m)
    {
        size_t i = m.find("`ifdef");
        size_t i1 = m.find("`ifndef");

        if (!(i != std::string::npos || i1 != std::string::npos))
            return m;
        // std::cout << m << "\n";
        replace(m, OUTL.data(), "");

        PrepParser prep(m_file);
        prep.setBitField(m);

        CharStream *sc = new CharStream(m.c_str(), m.size(), 1, 1);
        VerilogPreProcessorTokenManager *tokenManager = new VerilogPreProcessorTokenManager(sc);
        VerilogPreProcessor *parser = new VerilogPreProcessor(tokenManager);
        parser->setOutlineParser(&prep);
        tokenManager->setLexParser(parser);
        tokenManager->setParser(parser);
        try
        {
            parser->source_text();
        }
        catch (std::exception &e)
        {
            fprintf(stderr, "\n[%s shit happens]", e.what());
        }
        delete parser;
        delete tokenManager;
        delete sc;
        std::string si = prep.insertDelLines(prep.buf, &prep);
        replace(si, remSen.c_str(), "");
        return si;
    }

    int PrepParser::getDM(const string &m, int x)
    {
        //  std::cout << "get_dm\n";
        //  std::cout << m << "\n\n\n";
        int lp = 0;
        int rp = 0;

        for (size_t j = x; j < m.length(); j++)
        {
            char c = m.at(j);
            if (c == '(')
                lp++;

            if (c == ')')
                rp++;

            if (rp == lp && lp > 0)
            {
                return j + 1;
            }
        }

        return m.length() - 1;
    }

    bool PrepParser::checkQ3(Token *tok)
    {
        std::string s = tok->image;
        if (s.find("`__FILE__") != string::npos)
        {
            appString("\"" + m_file + "\"");
            return true;
        }
        if (s.find("`__LINE__") != string::npos)
        {
            auto s = std::to_string(tok->beginLine);
            appString(s);
            return true;
        }
        if (s.find("`endif") != string::npos)
        {
            endif(tok);
            return true;
        }
        else if (s.find("`else") != string::npos)
        {
            _else(tok);
            return true;
        }

        return false;
    }
    //--------------------------------------------------------------

    void read_directory(const std::string &name)
    {
        std::filesystem::path p(name);
        std::filesystem::directory_iterator start(p);
        std::filesystem::directory_iterator end;

        for (auto i = start; i != end; i++)
        {
            i->is_directory();
        }
    }

    void searchDirectories()
    {
        if (prepc::lock1)
            return;

        prepc::lock1 = true;

        const StringVector &includePathList = Config_getList(INCLUDE_PATH);
        for (const auto &s : includePathList)
        {

            fs::path pt = s;

            for (auto const &dir_entry : std::filesystem::recursive_directory_iterator{pt})
            {
                ostringstream os;
                os << dir_entry;
                std::string fi = os.str();
                replace(fi, "\"", "");

                if (!dir_entry.is_directory())
                {
                    if (endsWith(fi, ".v") || endsWith(fi, ".sv") || endsWith(fi, ".vh"))
                    {
                        //  FileName *fn = fnMap->add(QCString(name), QCString(filePath));
                        // QCString stripPath(const QCString &s)
                        // pathArr.emplace_back(fi);
                        std::cout << "import file: " << fi << "\n";
                    }
                }
            }
        }

        const StringVector &pre = Config_getList(INCLUDE_PREP);
        for (const auto &s : pre)
        {
            fs::path pt = s;
            bool b = pt.has_extension();
            if (b)
            {
                auto zz = pt.filename();
                auto fi = zz.string();
                prepc::PrepParser p;
                std::string str;
                std::cout << "preprocessing file!:" << fi << endl;
                p.readFile(s, str);
                p.parseData(str);
                std::map<std::string, prepc::DefMacro *> mdf = p.getMacros();
                continue;
            }

            for (auto const &dir_entry : std::filesystem::recursive_directory_iterator{pt})
            {
                ostringstream os;
                os << dir_entry;

                std::string fi = os.str();
                replace(fi, "\"", "");

                if (!dir_entry.is_directory())
                {
                    if (endsWith(fi, ".v") || endsWith(fi, ".sv") || endsWith(fi, ".vh") || endsWith(fi, ".svh"))
                    {
                        //  FileName *fn = fnMap->add(QCString(name), QCString(filePath));
                        // QCString stripPath(const QCString &s)
                        // pathArr.emplace_back(fi);
                        std::cout << "preprocess file: " << fi << "\n";
                        prepc::PrepParser p;
                        std::string str;
                        p.readFile(fi, str);
                        p.parseData(str);
                        std::map<std::string, prepc::DefMacro *> mdf = p.getMacros();

                        //  printMacros(true);
                    }
                }
            }
        }
        // printMacros(true);
        //    exit(0);
    }

    std::string getPath(const std::string &p)
    {
        for (std::string path : pathArr)
        {
            if (endsWith(path, p))
                return path;
        }
        return "";
    }

    void writeMacroWarning(const std::string &name, int i)
    {
        std::cout << ANSI_CYAN;
        std::cout << "warning:  macro [" << name << " ] is undefined";
        std::cout << "(and assumed null )" << ANSI_RESET;
        std::cout << " at line:" << i << endl;
    }

    void writeFileWarning(const std::string &name, int i)
    {
        std::cout << ANSI_YELLOW;
        cout << " file: [" << name << " ]";
        std::cout << ANSI_RESET;
        std::cout << " not found at line:" << i << endl;
    }
};

std::string cutComment(string &line)
{
    std::string res, str;
    QCString qc(line);
    int op = qc.find("//");

    if (op > 1)
    {
        res = line.substr(op);
        str = line.substr(0, op);
        line = str;
    }
    return res;
}

std::string getFileFromPath(const std::string &f)
{
    std::string ff=f;
    std::string result = cutComment(ff);
    prepc::replace(result, "\"", "");
    size_t i = result.find_last_of("/");
    if (i != string::npos)
        result = result.substr(i + 1);

    bool am = false;
    FileDef *fd = findFileDef(Doxygen::includeNameLinkedMap, QCString(result.data()), am);

    if (fd)
        return fd->getDefFileName().data();
    std::cout << "include file not found:" << f;
    // exit(0);
    prepc::writeFileWarning(f, 1);
    return ""s;
}
