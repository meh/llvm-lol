#include "LOLCODE/1.2/AST/Operator/Binary.h"
#include "LOLCODE/1.2/AST/Types.h"

namespace LOLCODE {

namespace _1_2 {

namespace AST {

namespace Operator {

Binary::Binary (void) : Core::AST::Base (Types::Binary)
{
    _operator = -1;
    _LHS      = NULL;
    _RHS      = NULL;
}

Binary::Binary (int type, Core::AST::Base* LHS, Core::AST::Base* RHS) : Core::AST::Base (Types::Binary)
{
    _operator = type;
    _LHS      = LHS;
    _RHS      = RHS;
}

Binary::~Binary (void)
{
}

Core::AST::Base*
Binary::LHS (void)
{
    return _LHS;
}

Core::AST::Base*
Binary::RHS (void)
{
    return _RHS;
}

}

}

}

}
