#include "Core/AST/Error.h"
#include "Core/AST/Types.h"

namespace Core {

namespace AST {

Error::Error (std::string message) : Base (Types::Error)
{
    _message = message;
}

std::string
Error::message (void)
{
    return _message;
}

}

}
