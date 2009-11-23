#include "LOLCODE/1.2/AST/Variable/Define.h"
#include "LOLCODE/1.2/AST/Types.h"

namespace LOLCODE {

namespace _1_2 {

namespace AST {

namespace Variable {

Define::Define (void) : Core::AST::Base (Types::Define)
{
}

Define::Define (std::string name) : Core::AST::Base (Types::Define)
{
    _name  = name;
}

Define::~Define (void)
{
}

std::string
Define::name (void)
{
    return _name;
}

}

}

}

}
