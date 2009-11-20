#include "Parser.h"

Parser::Token::Token (void)
{
}

Parser::Token::Token (int type, void* data)
{
    _type = type;
    _data = data;
}

int
Parser::Token::type (void)
{
    return _type;
}

void
Parser::Token::type (int type)
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
