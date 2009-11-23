#include "Core/AST/Base.h"

namespace Core {

namespace AST {

Base::Base (Type type)
{
    _type = type;
}

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
