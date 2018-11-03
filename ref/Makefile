
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
DRIVER = ./src/Driver
TARGET = dparser

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

SRC_FILES  = $(DEFINS)/Visitor.cc
SRC_FILES += $(DEFINS)/Program.cc
SRC_FILES += $(DEFINS)/FieldDeclaration.cc
SRC_FILES += $(DEFINS)/FieldDeclarationsList.cc
SRC_FILES += $(DEFINS)/MethodDeclaration.cc
SRC_FILES += $(DEFINS)/MethodDeclarationsList.cc
SRC_FILES += $(DEFINS)/Variable.cc
SRC_FILES += $(DEFINS)/VariablesList.cc
SRC_FILES += $(DEFINS)/VariableLocation.cc
SRC_FILES += $(DEFINS)/Argument.cc
SRC_FILES += $(DEFINS)/ArgumentsList.cc
SRC_FILES += $(DEFINS)/StatementsList.cc
SRC_FILES += $(DEFINS)/BlockStatement.cc
SRC_FILES += $(DEFINS)/IfElseStatement.cc
SRC_FILES += $(DEFINS)/ForStatement.cc
SRC_FILES += $(DEFINS)/AssignmentStatement.cc
SRC_FILES += $(DEFINS)/UserDefinedMethodCall.cc
SRC_FILES += $(DEFINS)/CalloutMethodCall.cc
SRC_FILES += $(DEFINS)/CalloutArgument.cc
SRC_FILES += $(DEFINS)/CalloutArgumentsList.cc
SRC_FILES += $(DEFINS)/ReturnStatement.cc
SRC_FILES += $(DEFINS)/BreakStatement.cc
SRC_FILES += $(DEFINS)/ContinueStatement.cc
SRC_FILES += $(DEFINS)/IntegerLiteral.cc
SRC_FILES += $(DEFINS)/BooleanLiteral.cc
SRC_FILES += $(DEFINS)/CharacterLiteral.cc
SRC_FILES += $(DEFINS)/StringLiteral.cc
SRC_FILES += $(DEFINS)/HexadecimalLiteral.cc
SRC_FILES += $(DEFINS)/ExpressionsList.cc
SRC_FILES += $(DEFINS)/UnaryExpression.cc
SRC_FILES += $(DEFINS)/BinaryExpression.cc
SRC_FILES += $(DEFINS)/EnclosedExpression.cc
SRC_FILES += $(DEFINS)/ExpressionsList.cc
SRC_FILES += $(DEFINS)/IdentifiersList.cc
SRC_FILES += $(DEFINS)/VariableDeclaration.cc
SRC_FILES += $(DEFINS)/VariableDeclarationsList.cc
SRC_FILES += $(DEFINS)/Driver.cc
SRC_FILES += $(DEFINS)/DecafParser.cc

OBJECTS :=  $(OBJDIR)/Parser.o $(OBJDIR)/Scanner.o $(SRC_FILES:$(DEFINS)/%.cc=$(OBJDIR)/%.o)

CXX      = g++
CXXFLAGS = -W -Wall -Wextra -ansi -g
INCLUDE  = -I./ -I$(SRCDIR)/ -I$(DECLRS)/ -I$(DRIVER)/
LDFLAGS  = 


##############################
# Rules building the targets #
##############################

all: $(TARGET)


$(OBJECTS): $(OBJDIR)/%.o : $(DEFINS)/%.cc
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@


$(PARSER): $(PARSER_FILES)
	bison -o $(PARSER) --defines=$(DRIVER)/Parser.hh $(PARSER_FILES)
	@echo "Parser Built Successfully"
	

$(SCANNER): $(SCANNER_FILES)
	flex -o $(SCANNER) $(SCANNER_FILES)
	@echo "Scanner Built Successfully"


$(TARGET): $(PARSER) $(SCANNER) $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@
	mv $(TARGET) $(BINDIR)
	@echo "$(TARGET) Built Successfully."

clean:
	@echo "Cleaning all the object files and binaries."
	rm -f core
	rm -f $(OBJECTS) $(BINDIR)/$(TARGET) $(AUTOGEN_FILES)