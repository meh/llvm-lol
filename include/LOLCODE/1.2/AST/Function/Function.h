#ifndef _LOL_LOLCODE_1_2_AST_FUNCTION_H
#define _LOL_LOLCODE_1_2_AST_FUNCTION_H

#include "Core/AST/api.h"

#include "LOLCODE/1.2/AST/Function/Prototype.h"

namespace LOLCODE {

namespace _1_2 {

namespace AST {

namespace Function {

class Function : public Core::AST::Base
{
  private:
    Prototype        _prototype;
    Core::AST::Tree* _body;

  public:
    Function (void);
    Function (Prototype prototype, Core::AST::Tree* body);

    virtual ~Function (void);

    Prototype prototype (void);

    Core::AST::Tree* body (void);

};

}

}

}

}

#endif
