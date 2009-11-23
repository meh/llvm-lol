#include "LOLCODE/1.2/AST/Function/Prototype.h"
#include "LOLCODE/1.2/AST/Types.h"

namespace LOLCODE {

namespace _1_2 {

namespace AST {

namespace Function {

Prototype::Prototype (void) : Core::AST::Base (Types::Prototype)
{
}

Prototype::Prototype (std::string name, std::vector<std::string>& arguments) : Core::AST::Base (Types::Prototype)
{
    _name      = name;
    _arguments = arguments;
}

Prototype::~Prototype (void)
{
}

std::string
Prototype::name (void)
{
    return _name;
}

std::vector<std::string>
Prototype::arguments (void)
{
    return _arguments;
}

}

}

}

}
