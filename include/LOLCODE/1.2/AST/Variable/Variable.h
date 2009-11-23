#ifndef _LOL_LOLCODE_1_2_AST_VARIABLE_H
#define _LOL_LOLCODE_1_2_AST_VARIABLE_H

#include "Core/AST/api.h"

namespace LOLCODE {

namespace _1_2 {

namespace AST {

namespace Variable {

class Variable : public Core::AST::Base
{
  public:
    class Cast {
      public:
        static const int NOOB   = 0;
        static const int YARN   = 1;
        static const int NUMBR  = 2;
        static const int NUMBAR = 3;
        static const int TROOF  = 4;
    };

  private:
    int         _cast;
    std::string _value;

  public:
    Variable (void);
    Variable (std::string value, int cast = Cast::NOOB);

    virtual ~Variable (void);

    std::string value (void);
    void        value (std::string value);

    int  cast (bool assume = false);
    void cast (int cast);

    std::string toYARN (void);
    long        toNUMBR (void);
    double      toNUMBAR (void);
    bool        toTROOF (void);
};

}

}

}

}

#endif
