NAME    = llvm-lol
VERSION = 0.1

CXX = llvm-g++

CFLAGS   = -Wall -pedantic -g3 -I./include/ -I./sources/ $(shell llvm-config --cxxflags core)
CXXFLAGS = ${CFLAGS}
LDFLAGS  = $(shell llvm-config --ldflags --libs core)

DIR   = sources
FILES = ${DIR}/main.o ${DIR}/Core/Parser/Parser.o ${DIR}/Core/Parser/Token.o ${DIR}/Core/AST/AST.o

all: $(FILES)
	${CXX} ${CFLAGS} -o ${NAME} $(FILES) ${LDFLAGS}

clean:
	find sources | egrep "\.o" | xargs rm -f
