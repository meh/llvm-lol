#include "LOLCODE/1.2/CodeGenerator.h"

namespace LOLCODE {

namespace _1_2 {

CodeGenerator::CodeGenerator (void)
{
    _module  = new llvm::Module("LULZ", llvm::getGlobalContext());
    _builder = new llvm::IRBuilder<>(llvm::getGlobalContext());
}

CodeGenerator::CodeGenerator (Core::AST::Tree* tree)
{
    _module = new llvm::Module("LULZ", llvm::getGlobalContext());
    _builder = new llvm::IRBuilder<>(llvm::getGlobalContext());
    _tree   = tree;
}

CodeGenerator::~CodeGenerator (void)
{
    delete _module;
    delete _builder;
}

void
CodeGenerator::generate (Core::AST::Tree* tree)
{
    Core::AST::Tree::iterator it;

    for (it = tree->begin(); it != tree->end(); it++) {
        void* code = this->generate(*it);
    }
}

void*
CodeGenerator::generate (Core::AST::Base* element)
{
    return NULL;
}

void
CodeGenerator::dump (void)
{
    _module->dump();
}

}

}
