#include "Core/AST/AST.h"

namespace Core {

namespace AST {

Base::~Base (void)
{
}

Type
Base::type (void)
{
    return _type;
}

void
Base::type (Type value)
{
    _type = value;
}

}

}
