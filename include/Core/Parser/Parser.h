#ifndef _LOL_CORE_PARSER_H
#define _LOL_CORE_PARSER_H

#include <string>

namespace Core {

class Parser
{
  public:
    #include "Parser/Token.h"

  protected:
    FILE*       _file;
    const char* _source;

    Token* _current;

  public:
    Parser (void);
    Parser (FILE* file);
    Parser (const char* source);

    Token* currentToken (void);

    virtual Token* nextToken (void);
};

}

#endif
