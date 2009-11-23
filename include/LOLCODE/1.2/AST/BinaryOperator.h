#ifndef _LOL_LOLCODE_1_2_AST_BINARYOPERATOR_H
#define _LOL_LOLCODE_1_2_AST_BINARYOPERATOR_H

#include "Core/AST/api.h"

namespace LOLCODE {

namespace _1_2 {

namespace AST {

class BinaryOperator : public Core::AST::Base
{
  public:
    class Operator {
      public:
        static const int SUM      = 0;
        static const int DIFF     = 1;
        static const int PRODUKT  = 2;
        static const int QUOSHUNT = 3;
        static const int MOD      = 4;
        static const int BIGGR    = 5;
        static const int SMALLR   = 6;
    };

  private:
    int              _operator;
    Core::AST::Base* _LHS;
    Core::AST::Base* _RHS;

  public:
    BinaryOperator (void);
    BinaryOperator (int type, Core::AST::Base* LHS, Core::AST::Base* RHS);

    virtual ~BinaryOperator (void);

    Core::AST::Base* LHS (void);
    Core::AST::Base* RHS (void);
};

}

}

}

#endif
