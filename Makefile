NAME    = llvm-lol
VERSION = 0.1

CXX = llvm-g++

CFLAGS   = -Wall -pedantic -g3 -I./include/ -I./sources/ $(shell llvm-config --cxxflags core)
CXXFLAGS = ${CFLAGS}
LDFLAGS  = $(shell llvm-config --ldflags --libs core)

DIR   = sources
FILES = ${DIR}/main.o \
	    ${DIR}/Core/Parser/Parser.o ${DIR}/Core/Parser/Token.o \
		${DIR}/Core/AST/Base.o ${DIR}/Core/AST/Error.o ${DIR}/Core/AST/Version.o \
			\
		${DIR}/LOLCODE/1.2/Parser/Parser.o ${DIR}/LOLCODE/1.2/Parser/Token.o \
		${DIR}/LOLCODE/1.2/AST/Variable/Variable.o ${DIR}/LOLCODE/1.2/AST/Variable/Assignment.o \
		${DIR}/LOLCODE/1.2/AST/Operator/Binary.o \
		${DIR}/LOLCODE/1.2/AST/Function/Call.o ${DIR}/LOLCODE/1.2/AST/Function/Prototype.o ${DIR}/LOLCODE/1.2/AST/Function/Function.o \
		${DIR}/LOLCODE/1.2/CodeGenerator.o

all: $(FILES)
	${CXX} ${CFLAGS} -o ${NAME} $(FILES) ${LDFLAGS}

clean:
	find sources | egrep "\.o" | xargs rm -f
