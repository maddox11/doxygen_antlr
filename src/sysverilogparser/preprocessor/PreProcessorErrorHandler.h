#ifndef VERILOGPARSERERRORHANDLER_H
#define VERILOGPARSERERRORHANDLER_H

#include <stdio.h>
#include <stdlib.h>
#include <exception>
#include "VerilogPreProcessor.h"
#include "ErrorHandler.h"
//#include "vhdlstring.h"
#include "message.h"


namespace prepc{
class PreProcessorErrorHandler: public ErrorHandler
{
  public:
    PreProcessorErrorHandler(const char *fileName)  {m_fileName=fileName;}

    virtual void handleUnexpectedToken(int expectedKind, const JJString& expectedToken, Token *actual, VerilogPreProcessor *parser)
    {
      printf("syntax error '%s' %d expected token %s\n",actual->image.data(),actual->beginLine,expectedToken.data());
       exit(0);
      error_count++;
      throw std::exception();
    }

    virtual void handleParseError(Token *last, Token *unexpected, const JJSimpleString& production, VerilogPreProcessor *parser)
    {
       printf("unexpected token: '%s' %d \n", unexpected->image.data(),last->beginLine);
       exit(0);
      error_count++;
      throw std::exception();
    }

    virtual void handleOtherError(const JJString& message, VerilogPreProcessor *parser)
    {
       printf( "othter error: '%s'", (char*)message.c_str());
       exit(0);
      error_count++;
      throw std::exception();
    }

  private:
    std::string m_fileName;
};

class PreProcessorTokenManagerErrorHandler: public TokenManagerErrorHandler
{
  public:
    PreProcessorTokenManagerErrorHandler(const char *fileName) {m_fileName=fileName;}

    virtual void lexicalError(bool EOFSeen, int lexState, int errorLine, int errorColumn, const JJString& errorAfter, JJChar curChar, VerilogPreProcessorTokenManager* token_manager)
    {
      printf("Lexical error, Encountered: '%c' after: \n",curChar);
        exit(0);
    }

    virtual void lexicalError(const JJString& errorMessage, VerilogPreProcessorTokenManager* token_manager)
    {
     
      printf("Unknown error: '%s'", (char*)errorMessage.c_str());
    exit(0);
     }

  private:
    std::string m_fileName;
};

}


#endif

