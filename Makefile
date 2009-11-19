NAME    = llvm-lol
VERSION = 0.1

CXX = llvm-g++
CFLAGS  = $(shell llvm-config --cxxflags core) -I./include/ -I./sources/
LDFLAGS = $(shell llvm-config --ldflags --libs core)

DIR   = sources
FILES = ${DIR}/main.cpp

all:
	${CXX} ${CFLAGS} -o ${NAME} $(FILES) ${LDFLAGS}
