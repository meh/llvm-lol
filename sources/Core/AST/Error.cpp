#include "Core/AST/Error.h"
#include "Core/AST/Types.h"

namespace Core {

namespace AST {

Error::Error (const char* message) : Base ()
{
    _message = message;

    _type = Types::Error;
}

std::string
Error::message (void)
{
    return _message;
}

}

}
