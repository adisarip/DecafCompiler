
# debug: for printing any variable
print-%  : ; @echo $* = $($*)


#############
# Variables #
#############

SRCDIR = ./src
OBJDIR = ./obj
BINDIR = ./bin
DECLRS = ./src/Declarations
DEFINS = ./src/Definitions
VISITR = ./src/Visitors
DRIVER = ./src/Driver
TARGET = decaf

PARSER        = $(DRIVER)/Parser.cc
PARSER_FILES  = $(DRIVER)/Parser.yy
SCANNER       = $(DRIVER)/Scanner.cc
SCANNER_FILES = $(DRIVER)/Scanner.ll

AUTOGEN_FILES = $(DRIVER)/Parser.cc     \
                $(DRIVER)/Parser.hh     \
                $(DRIVER)/Scanner.cc    \
                $(DRIVER)/location.hh   \
                $(DRIVER)/position.hh   \
                $(DRIVER)/stack.hh

DECAF_SRC  = $(DEFINS)/Program.cc
DECAF_SRC += $(DEFINS)/FieldDeclaration.cc
DECAF_SRC += $(DEFINS)/FieldDeclarationsList.cc
DECAF_SRC += $(DEFINS)/MethodDeclaration.cc
DECAF_SRC += $(DEFINS)/MethodDeclarationsList.cc
DECAF_SRC += $(DEFINS)/Variable.cc
DECAF_SRC += $(DEFINS)/VariablesList.cc
DECAF_SRC += $(DEFINS)/VariableLocation.cc
DECAF_SRC += $(DEFINS)/Argument.cc
DECAF_SRC += $(DEFINS)/ArgumentsList.cc
DECAF_SRC += $(DEFINS)/StatementsList.cc
DECAF_SRC += $(DEFINS)/BlockStatement.cc
DECAF_SRC += $(DEFINS)/IfElseStatement.cc
DECAF_SRC += $(DEFINS)/ForStatement.cc
DECAF_SRC += $(DEFINS)/AssignmentStatement.cc
DECAF_SRC += $(DEFINS)/UserDefinedMethodCall.cc
DECAF_SRC += $(DEFINS)/CalloutMethodCall.cc
DECAF_SRC += $(DEFINS)/CalloutArgument.cc
DECAF_SRC += $(DEFINS)/CalloutArgumentsList.cc
DECAF_SRC += $(DEFINS)/ReturnStatement.cc
DECAF_SRC += $(DEFINS)/BreakStatement.cc
DECAF_SRC += $(DEFINS)/ContinueStatement.cc
DECAF_SRC += $(DEFINS)/IntegerLiteral.cc
DECAF_SRC += $(DEFINS)/BooleanLiteral.cc
DECAF_SRC += $(DEFINS)/CharacterLiteral.cc
DECAF_SRC += $(DEFINS)/HexadecimalLiteral.cc
DECAF_SRC += $(DEFINS)/ExpressionsList.cc
DECAF_SRC += $(DEFINS)/UnaryExpression.cc
DECAF_SRC += $(DEFINS)/BinaryExpression.cc
DECAF_SRC += $(DEFINS)/EnclosedExpression.cc
DECAF_SRC += $(DEFINS)/IdentifiersList.cc
DECAF_SRC += $(DEFINS)/VariableDeclaration.cc
DECAF_SRC += $(DEFINS)/VariableDeclarationsList.cc


DRIVER_SRC  = $(DRIVER)/Driver.cc
DRIVER_SRC += $(DRIVER)/DecafParser.cc

FEATURES_SRC = $(VISITR)/AstVisitor.cc

PARSER_OBJ     := $(OBJDIR)/Parser.o
SCANNER_OBJ    := $(OBJDIR)/Scanner.o
DRIVER_OBJECTS := $(DRIVER_SRC:$(DRIVER)/%.cc=$(OBJDIR)/%.o)
SRC_OBJECTS    := $(DECAF_SRC:$(DEFINS)/%.cc=$(OBJDIR)/%.o)
FEATURE_OBJS   := $(OBJDIR)/AstVisitor.o

CXX      = g++
CXXFLAGS = -W -Wall -Wextra -ansi -g -std=c++11
INCLUDE  = -I./ -I$(VISITR)/ -I$(DECLRS)/ -I$(DRIVER)/
LDFLAGS  = 


##############################
# Rules building the targets #
##############################

all: $(PARSER) $(SCANNER) $(TARGET)


$(FEATURE_OBJS):
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $(FEATURES_SRC) -o $@


$(PARSER_OBJ):
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $(PARSER) -o $@


$(SCANNER_OBJ):
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $(SCANNER) -o $@


$(SRC_OBJECTS): $(OBJDIR)/%.o : $(DEFINS)/%.cc
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@


$(DRIVER_OBJECTS): $(OBJDIR)/%.o : $(DRIVER)/%.cc
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@


$(PARSER): $(PARSER_FILES)
	bison -o $(PARSER) --defines=$(DRIVER)/Parser.hh $(PARSER_FILES)
	@echo "Parser Built Successfully"
	

$(SCANNER): $(SCANNER_FILES)
	flex -o $(SCANNER) $(SCANNER_FILES)
	@echo "Scanner Built Successfully"


$(TARGET): $(SRC_OBJECTS) $(DRIVER_OBJECTS) $(FEATURE_OBJS) $(PARSER_OBJ) $(SCANNER_OBJ) 
	$(CXX) $(LDFLAGS) $(SRC_OBJECTS) $(DRIVER_OBJECTS) $(FEATURE_OBJS) $(PARSER_OBJ) $(SCANNER_OBJ)  -o $@
	mv $(TARGET) $(BINDIR)
	@echo "$(TARGET) Built Successfully."

clean:
	@echo "Cleaning all the object files and binaries."
	rm -f core
	rm -f $(OBJDIR)/*.o
