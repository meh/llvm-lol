#include "Core/Parser/Parser.h"

#include <cstdio>
#include <cctype>

#include "Constants.h"

#include "LOLCODE/1.2/api.h"

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

Parser::~Parser (void)
{
    if (_current) {
        delete _current;
    }
}

AST::Tree*
Parser::parse (void)
{
    AST::Tree* tree = new AST::Tree;
    Token*     token;

    token = _nextToken();

    if (token->type() != Token::Version) {
        tree->push_back(new AST::Error("The source must begin with a HAI instruction."));
        return tree;
    }

    std::string version = *((std::string*) token->data());
    tree->push_back(new AST::Version(version));

    if (version == "1.2") {
        AST::Tree* toMerge;

        if (_file) {
            LOLCODE::_1_2::Parser parser(_file);
            toMerge = parser.parse();
        }
        else if (_source) {
            LOLCODE::_1_2::Parser parser(_source);
            toMerge = parser.parse();
        }
        else {
            toMerge = new AST::Tree();
        }

        tree->merge(*toMerge);

        delete toMerge;
    }
    else {
        tree->pop_back();
        tree->push_back(new AST::Error("Unknown language version."));
    }

    return tree;
}

void
Parser::parse (Parser::Function function)
{
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

            if (identifier == "HAI") {
                if (lastChar != '\n') {
                    while (std::isspace((lastChar = _nextChar())));
                }

                if (lastChar == '\n') {
                    line++;
                    return new Token(Token::Version, new std::string(LOL_DEFAULT_VERSION), line);
                }
                else {
                    std::string* version = new std::string;
                    
                    (*version) += lastChar;
                    while (!std::isspace((lastChar = _nextChar()))) {
                        (*version) += lastChar;
                    }

                    return new Token(Token::Version, version, line);
                }
            }
            else {
                if (identifier == "BTW") {
                    while ((lastChar = _nextChar()) != '\n');
                    line++;
                }
                else if (identifier == "OBTW") {
                    std::string comment = "    ";

                    while (comment.substr(comment.length() - 4, 4) != "TLDR") {
                        comment += (lastChar = _nextChar());
                        
                        if (lastChar == '\n') {
                            line++;
                        }
                    }
                }

                return _parseToken();
            }
        }
    } while (std::isspace(lastChar));

    return new Token();
}

}
