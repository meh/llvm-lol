#ifndef _LOL_CORE_AST_ERROR_H
#define _LOL_CORE_AST_ERROR_H

#include "Core/AST/Base.h"

#include <string>

namespace Core {

namespace AST {

class Error : public Base
{
  private:
    std::string _message;

  public:
    Error (const char* message);

    std::string message (void);
};

}

}

#endif
