#ifndef _LOL_CORE_AST_H
#define _LOL_CORE_AST_H

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
};

}

}

#endif
