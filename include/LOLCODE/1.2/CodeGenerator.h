#ifndef _LOL_CORE_CODEGENERATOR_H
#define _LOL_CORE_CODEGENERATOR_H

#include <map>
#include <string>

#include "LLVM.h"
#include "AST/api.h"

namespace LOLCODE {

namespace _1_2 {

class CodeGenerator
{
  private:
    llvm::Module* _module;
    llvm::IRBuilder<>* _builder;
    std::map<std::string, llvm::Value*> _namedValues;

    Core::AST::Tree* _tree;

  public:
    CodeGenerator (void);
    CodeGenerator (Core::AST::Tree* tree);

    ~CodeGenerator (void);

    void  generate (Core::AST::Tree* tree);
    void* generate (Core::AST::Base* element);

    void dump (void);
};

}

}

#endif
