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
    parser.parse();

    return 0;
}
