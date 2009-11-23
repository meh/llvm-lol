#ifndef _LOL_LOLCODE_1_2_AST_TYPES_H
#define _LOL_LOLCODE_1_2_AST_TYPES_H

namespace LOLCODE {

namespace _1_2 {

namespace AST {

class Types
{
  public:
    enum Type {
        // Data
        Integer = 50,
        Floating,
        String,
        Boolean,
        
        // Variable
        Variable = 100,
        Assignment,
        Define,

        // Operator
        Binary = 200,

        // Function
        Call = 300,
        Prototype,
        Function
    };
};

}

}

}

#endif
