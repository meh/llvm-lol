#include "LOLCODE/1.2/AST/BinaryOperator.h"
#include "LOLCODE/1.2/AST/Types.h"

namespace LOLCODE {

namespace _1_2 {

namespace AST {

BinaryOperator::BinaryOperator (void) : Core::AST::Base (Types::BinaryOperator)
{
    _operator = -1;
    _LHS      = NULL;
    _RHS      = NULL;
}

BinaryOperator::BinaryOperator (int type, Core::AST::Base* LHS, Core::AST::Base* RHS) : Core::AST::Base (Types::BinaryOperator)
{
    _operator = type;
    _LHS      = LHS;
    _RHS      = RHS;
}

BinaryOperator::~BinaryOperator (void)
{
}

Core::AST::Base*
BinaryOperator::LHS (void)
{
    return _LHS;
}

Core::AST::Base*
BinaryOperator::RHS (void)
{
    return _RHS;
}

}

}

}
