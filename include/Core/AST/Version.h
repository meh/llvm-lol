#ifndef _LOL_CORE_AST_VERSION_H
#define _LOL_CORE_AST_VERSION_H

#include "Core/AST/Base.h"

#include <string>

namespace Core {

namespace AST {

class Version : public Base
{
  private:
    std::string _version;

  public:
    Version (std::string version);

    std::string version (void);
};

}

}

#endif
