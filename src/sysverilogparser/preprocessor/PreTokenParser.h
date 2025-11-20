#ifndef PRETOKENPARSER_H
#define PRETOKENPARSER_H

#include <stdio.h>
#include <string>
#include <map>
#include "Token.h"
#include "VerilogPreProcessor.h"

// super class for VerilogParserTokenManager
// is generated in vhdlparser.jj
// -option TOKEN_MANAGER_SUPER_CLASS = "TokenParser"
// sets the Verilogparser in veriogjjparser.cpp
// tokenManager->setLexParser(veriloglParser);

namespace prepc
{
  class PreTokenParser
  {
   public: 
    void setLexParser(VerilogPreProcessor *p)
    {
      parser = p;
    }

  protected:
    const VerilogPreProcessor *parser = nullptr;
  };
}

#endif

