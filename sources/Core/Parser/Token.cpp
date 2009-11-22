#include "Core/Parser/Parser.h"

namespace Core {

Parser::Token::Token (void)
{
    _type = Unknown;
    _data = NULL;
}

Parser::Token::Token (Parser::Token::Type type, void* data)
{
    _type = type;
    _data = data;
}

Parser::Token::~Token (void)
{
    if (_type == Beginning) {
        delete (std::string*) _data;
    }
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

}
