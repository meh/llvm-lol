#ifndef _LOL_CORE_AST
#define _LOL_CORE_AST

#include <list>

#include "Core/AST/Types.h"

#include "Core/AST/Base.h"
#include "Core/AST/Error.h"
#include "Core/AST/Version.h"

namespace Core {

namespace AST {

typedef std::list<Base*> Tree;

}

}

#endif
