#include "LOLCODE/1.2/AST/Function/Function.h"
#include "LOLCODE/1.2/AST/Types.h"

namespace LOLCODE {

namespace _1_2 {

namespace AST {

namespace Function {

Function::Function (void) : Core::AST::Base (Types::Function)
{
}

Function::Function (Prototype prototype, Core::AST::Tree* body) : Core::AST::Base (Types::Function)
{
    _prototype = prototype;
    _body      = body;
}

Function::~Function (void)
{
}

Prototype
Function::prototype(void)
{
    return _prototype;
}

Core::AST::Tree*
Function::body (void)
{
    return _body;
}

}

}

}

}
