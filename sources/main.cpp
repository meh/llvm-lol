#include <iostream>
#include <cstdio>

#include "Core/api.h"

using namespace Core;

void
usage (char* name)
{
    std::cerr << "Usage: " << name << " [options] <file>" << std::endl;
}

int
main (int argc, char *argv[])
{
    if (argc < 2) {
        usage(argv[0]);
        return -1;
    }

    FILE* file;
    if ((file = fopen(argv[1], "r")) == NULL) {
        std::cerr << "Something went wrong while opening the file." << std::endl;
        return -2;
    }

    Parser parser(file);
    AST::Tree*          tree = parser.parse();
    AST::Tree::iterator it;

    for (it = tree->begin(); it != tree->end(); it++) {
        switch ((*it)->type()) {
            case AST::Types::Error:
            std::cerr << ((AST::Error*) (*it))->message() << std::endl;
            return -3;

            case AST::Types::Version:
            std::cout << "Language version: " << ((AST::Version*) (*it))->version() << std::endl;
            break;
        }
    }

    return 0;
}
