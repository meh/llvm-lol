#ifndef _LOL_LOLCODE_1_2_AST_FUNCTION_PROTOTYPE_H
#define _LOL_LOLCODE_1_2_AST_FUNCTION_PROTOTYPE_H

#include <vector>

#include "Core/AST/api.h"

namespace LOLCODE {

namespace _1_2 {

namespace AST {

namespace Function {

class Prototype : public Core::AST::Base
{
  private:
    std::string              _name;
    std::vector<std::string> _arguments;

  public:
    Prototype (void);
    Prototype (std::string name, std::vector<std::string>& arguments);

    virtual ~Prototype (void);

    std::string name (void);

    std::vector<std::string> arguments (void);

};

}

}

}

}

#endif
