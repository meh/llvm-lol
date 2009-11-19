#ifndef _V3B_PARSER_H
#define _V3B_PARSER_H

class Parser
{
  public:
    #include "Parser/Token.h"

  public:
    Parser (void);
    Parser (FILE* file);
    Parser (const char* source);
};

#endif
