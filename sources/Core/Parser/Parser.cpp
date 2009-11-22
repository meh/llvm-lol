#include "Core/Parser/Parser.h"

#include <cstdio>
#include <cctype>

#include <iostream>

#include "Constants.h"

namespace Core {

Parser::Parser (void)
{
    _file   = NULL;
    _source = NULL;

    _current = NULL;
}

Parser::Parser (FILE* file)
{
    _file   = file;
    _source = NULL;

    _current = NULL;
}

Parser::Parser (const char* source)
{
    _file   = NULL;
    _source = source;

    _current = NULL;
}

AST::Tree
Parser::parse (void)
{
    AST::Tree tree;
    Token*    token = NULL;

    do {
        if (token) {
            delete token;
        }

        token = _nextToken();

        switch (token->type()) {
            case Token::Beginning:
            std::cout << "Language version: " << *((std::string*) token->data()) << std::endl;
            break;

            case Token::End:
            std::cout << "Program end." << std::endl;
            break;
        }
    } while (token->type() != Token::Unknown);

    return tree;
}

char
Parser::_nextChar (void)
{
    if (_file != NULL) {
        int ch;

        if ((ch = std::fgetc(_file)) == EOF) {
            return 0;
        }

        return (char) ch;
    }
    else if (_source != NULL) {
        if (*(_source) != '\0') {
            _source++;
        }

        return *(_source);
    }
    else {
        return 0;
    }
}

Parser::Token*
Parser::_currentToken (void)
{
    return _current;
}

Parser::Token*
Parser::_nextToken (void)
{
    return _current = _parseToken();
}

Parser::Token*
Parser::_parseToken (void)
{
    static char lastChar;

    do {
        lastChar = _nextChar();

        if (std::isalpha(lastChar)) {
            std::string identifier;

            identifier += lastChar;
            while (std::isalnum((lastChar = _nextChar()))) {
                identifier += lastChar;
            }

            if (identifier == "HAI") {
                if (lastChar != '\n') {
                    while (std::isspace((lastChar = _nextChar())));
                }

                if (lastChar == '\n') {
                    return new Token(Token::Beginning, new std::string(LOL_DEFAULT_VERSION));
                }
                else {
                    std::string* version = new std::string;
                    
                    version += lastChar;
                    while (!std::isspace((lastChar = _nextChar()))) {
                        version += lastChar;
                    }

                    return new Token(Token::Beginning, version);
                }
            }
            else if (identifier == "KTHXBYE") {
                return new Token(Token::End, NULL);
            }
            else {
                if (identifier == "BTW") {
                    while ((lastChar = _nextChar()) != '\n');
                }
                else if (identifier == "OBTW") {
                    std::string comment = "    ";

                    while (comment.substr(comment.length() - 4, 4) != "TLDR") {
                        comment += (lastChar = _nextChar());
                    }
                }

                return _parseToken();
            }
        }
    } while (std::isspace(lastChar));

    return new Token();
}

}
