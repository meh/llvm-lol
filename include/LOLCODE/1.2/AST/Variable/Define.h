#ifndef _LOL_LOLCODE_1_2_AST_DEFINE_CREATION_H
#define _LOL_LOLCODE_1_2_AST_DEFINE_CREATION_H

#include "Core/AST/api.h"

namespace LOLCODE {

namespace _1_2 {

namespace AST {

namespace Variable {

class Define : public Core::AST::Base
{
  private:
    std::string _name;

  public:
    Define (void);
    Define (std::string name);

    virtual ~Define (void);

    std::string name (void);

};

}

}

}

}

#endif
