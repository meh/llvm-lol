#ifndef _LOL_LOLCODE_1_2_PARSER_H
#define _LOL_LOLCODE_1_2_PARSER_H

#include "Core/Parser/api.h"

namespace LOLCODE {

namespace _1_2 {

class Parser : public Core::Parser
{
  public:
    #include "Token.h"

  public:
    Parser (void);
    Parser (FILE* file);
    Parser (const char* source);

    virtual ~Parser (void);

    virtual Core::AST::Tree* parse (void);
    virtual void             parse (Core::Parser::Function function);

  private:
    Token* _nextToken (void);
    Token* _parseToken (void);
};

}

}

#endif
