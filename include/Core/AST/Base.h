#ifndef _LOL_CORE_AST_H
#define _LOL_CORE_AST_H

#include <LLVM.h>

namespace Core {

namespace AST {

typedef int Type;

class Base
{
  protected:
    Type _type;

  public:
    Base (Type type);

    virtual ~Base (void);

    Type type (void);
    void type (Type value);

    virtual llvm::Value* code (void) = 0;
};

}

}

#endif
