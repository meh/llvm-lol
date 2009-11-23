#include "Core/AST/Version.h"
#include "Core/AST/Types.h"

namespace Core {

namespace AST {

Version::Version (std::string version) : Base (Types::Version)
{
    _version = version;
}

std::string
Version::version (void)
{
    return _version;
}

}

}
