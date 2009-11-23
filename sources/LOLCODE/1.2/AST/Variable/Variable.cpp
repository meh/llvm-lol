#include "LOLCODE/1.2/AST/Variable/Variable.h"
#include "LOLCODE/1.2/AST/Types.h"

#include <cstdlib>

namespace LOLCODE {

namespace _1_2 {

namespace AST {

namespace Variable {

Variable::Variable (void) : Core::AST::Base(Types::Variable)
{
    _cast  = Cast::NOOB;
    _value.clear();
}

Variable::Variable (std::string value, int cast) : Core::AST::Base(Types::Variable)
{
    _cast  = cast;
    _value = value;
}

Variable::~Variable (void)
{
}

std::string
Variable::value (void)
{
    return _value;
}

void
Variable::value (std::string value)
{
    _value = value;
}

int
Variable::cast (bool assume)
{
    if (!assume) {
        return _cast;
    }
    else {
        return Cast::NOOB;
    }
}

void
Variable::cast (int cast)
{
    _cast = cast;
}

std::string
Variable::toYARN (void)
{
    return _value;
}

long
Variable::toNUMBR (void)
{
    switch (this->cast()) {
        case Cast::YARN:
        case Cast::NUMBR:
        case Cast::NUMBAR:
        return std::atol(_value.c_str());

        case Cast::TROOF:
        return (_value == "WIN") ? 1 : 0;

        default: // NOOB
        return 0;
    }
}

double
Variable::toNUMBAR (void)
{
     switch (this->cast()) {
        case Cast::YARN:
        case Cast::NUMBR:
        case Cast::NUMBAR:
        return std::atof(_value.c_str());

        case Cast::TROOF:
        return (_value == "WIN") ? 1 : 0;

        default: // NOOB
        return 0;
    }
}

bool
Variable::toTROOF (void)
{
     switch (this->cast()) {
        case Cast::YARN:
        return _value.length();

        case Cast::NUMBR:
        return std::atol(_value.c_str());

        case Cast::NUMBAR:
        return std::atof(_value.c_str());

        case Cast::TROOF:
        return (_value == "WIN");

        default: // NOOB
        return false;
    }
}

}

}

}

}
