#include "Parser.h"

Parser::Token::Token (void)
{
}

Parser::Token::Token (Token::Type type, void* data)
{
    _type = type;
    _data = data;
}

Parser::Token::Type
Parser::Token::type (void)
{
    return _type;
}

void
Parser::Token::type (Parser::Token::Type type)
{
    _type = type;
}

void*
Parser::Token::data (void)
{
    return _data;
}

void
Parser::Token::data (void* data)
{
    _data = data;
}
