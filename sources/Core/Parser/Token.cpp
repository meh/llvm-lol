#include "Core/Parser/Parser.h"

namespace Core {

Parser::Token::Token (void)
{
    _line = 0;
    _type = Unknown;
    _data = NULL;
}

Parser::Token::Token (Parser::Token::Type type, void* data, unsigned line)
{
    _line = line;
    _type = type;
    _data = data;
}

Parser::Token::~Token (void)
{
    if (_type == Version) {
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
