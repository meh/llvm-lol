#ifndef _LOL_LOLCODE_1_2_AST_VARIABLE_ASSIGNMENT_H
#define _LOL_LOLCODE_1_2_AST_VARIABLE_ASSIGNMENT_H

#include "Core/AST/api.h"

namespace LOLCODE {

namespace _1_2 {

namespace AST {

namespace Variable {

class Assignment : public Core::AST::Base
{
  private:
    std::string      _name;
    Core::AST::Base* _value;

  public:
    Assignment (void);
    Assignment (std::string name, Core::AST::Base* value);

    virtual ~Assignment (void);

    std::string name (void);

    Core::AST::Base* value (void);

};

}

}

}

}

#endif
