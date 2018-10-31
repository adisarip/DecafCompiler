

CXX = g++
CXXFLAGS = -W -Wall -Wextra -ansi -g
INCLUDE = -I/usr/local/opt/flex/include/ -I./

all: decaf_parser

# generate parser and scanner
parser.cc: parser.yy
	bison -o parser.cc --defines=parser.h parser.yy

scanner.cc: scanner.ll
	flex -o scanner.cc scanner.ll


# Implicit rule to compile c++ files
%.o: %.cc
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c -o $@ $<


# Link executable
decaf_parser: parser.o scanner.o driver.o ast.o
	$(CXX) $(LDFLAGS) -o $@ parser.o scanner.o driver.o ast.o
	rm *.o

clean: 
	rm -rf parser.cc parser.h scanner.cc location.hh  position.hh stack.hh *.o decaf_parser