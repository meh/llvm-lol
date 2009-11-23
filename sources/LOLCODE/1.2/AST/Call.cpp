#include "LOLCODE/1.2/AST/Call.h"
#include "LOLCODE/1.2/AST/Types.h"

namespace LOLCODE {

namespace _1_2 {

namespace AST {

Call::Call (void) : Core::AST::Base (Types::Call)
{
}

Call::Call (std::string function, std::vector<Core::AST::Base*>& arguments) : Core::AST::Base (Types::Call)
{
    _function  = function;
    _arguments = arguments;
}

Call::~Call (void)
{
}

std::string
Call::function (void)
{
    return _function;
}

std::vector<Core::AST::Base*>
Call::arguments (void)
{
    return _arguments;
}

}

}

}
