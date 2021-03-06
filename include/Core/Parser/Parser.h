#ifndef _LOL_CORE_PARSER_H
#define _LOL_CORE_PARSER_H

#include <string>

#include "Core/AST/api.h"

namespace Core {

class Parser
{
  public:
    #include "Token.h"

  public:
    typedef int (*Function)(AST::Base*);

  protected:
    FILE*       _file;
    const char* _source;

    Token* _current;

  public:
    Parser (void);
    Parser (FILE* file);
    Parser (const char* source);

    virtual ~Parser (void);

    virtual AST::Tree* parse (void);
    virtual void       parse (Function function);

  protected:
    char _nextChar (void);

    Token* _currentToken (void);

  private: 
    Token* _nextToken (void); 
    Token* _parseToken (void);
};

}

#endif
