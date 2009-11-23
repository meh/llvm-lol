#include "LOLCODE/1.2/AST/Variable/Assignment.h"
#include "LOLCODE/1.2/AST/Types.h"

namespace LOLCODE {

namespace _1_2 {

namespace AST {

namespace Variable {

Assignment::Assignment (void) : Core::AST::Base (Types::Assignment)
{
}

Assignment::Assignment (std::string name, Core::AST::Base* value) : Core::AST::Base (Types::Assignment)
{
    _name  = name;
    _value = value;
}

Assignment::~Assignment (void)
{
}

std::string
Assignment::name (void)
{
    return _name;
}

Core::AST::Base*
Assignment::value (void)
{
    return _value;
}

}

}

}

}
