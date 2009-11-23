#ifndef _LOL_LOLCODE_1_2_AST_CALL_H
#define _LOL_LOLCODE_1_2_AST_CALL_H

#include <vector>

#include "Core/AST/api.h"

namespace LOLCODE {

namespace _1_2 {

namespace AST {

class Call : public Core::AST::Base
{
  private:
    std::string _function;
    std::vector<Core::AST::Base*> _arguments;

  public:
    Call (void);
    Call (std::string function, std::vector<Core::AST::Base*>& arguments);

    virtual ~Call (void);

    std::string function (void);

    std::vector<Core::AST::Base*> arguments (void);

};

}

}

}

#endif
