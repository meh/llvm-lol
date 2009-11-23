#include "LOLCODE/1.2/Parser/Parser.h"

#include <cstdio>
#include <cctype>

#include "Constants.h"

namespace LOLCODE {

namespace _1_2 {

Parser::Parser (void) : Core::Parser ()
{
}

Parser::Parser (FILE* file) : Core::Parser (file)
{
}

Parser::Parser (const char* source) : Core::Parser (source)
{
}

Parser::~Parser (void)
{
}

Core::AST::Tree*
Parser::parse (void)
{
    Core::AST::Tree* tree = new Core::AST::Tree();

    return tree;
}

void
Parser::parse (Core::Parser::Function function)
{
}

Parser::Token*
Parser::_nextToken (void)
{
    return _current = _parseToken();
}

Parser::Token*
Parser::_parseToken (void)
{
    static char     lastChar;
    static unsigned line = 0;

    do {
        lastChar = _nextChar();

        if (std::isalpha(lastChar)) {
            std::string identifier;

            identifier += lastChar;
            while (std::isalnum((lastChar = _nextChar()))) {
                identifier += lastChar;
            }

            if (identifier == "VISIBLE") {
                if (lastChar != '\n') {
                    while (std::isspace((lastChar = _nextChar())));
                }

                if (lastChar == '\n') {
                    line++;
                    return _nextToken();
                }
            }

            if (identifier == "I") {
                identifier += " ";
            }
        }
    } while (std::isspace(lastChar));

    return new Token();
}

}

}
