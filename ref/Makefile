
# debug: for printing any variable
print-%  : ; @echo $* = $($*)


#############
# Variables #
#############

SRCDIR  = ./src
OBJDIR 	= ./obj
BINDIR  = ./bin
TARGET  = dparser

PARSER        = $(SRCDIR)/Parser.cc
PARSER_FILES  = $(SRCDIR)/Parser.yy
SCANNER       = $(SRCDIR)/Scanner.cc
SCANNER_FILES = $(SRCDIR)/Scanner.ll

AUTOGEN_FILES = $(SRCDIR)/Parser.cc     \
                $(SRCDIR)/Parser.hh     \
                $(SRCDIR)/Scanner.cc    \
                $(SRCDIR)/location.hh   \
                $(SRCDIR)/position.hh   \
                $(SRCDIR)/stack.hh

SRC_FILES  = $(SRCDIR)/AstVisitor.cc
SRC_FILES += $(SRCDIR)/Expression.cc
SRC_FILES += $(SRCDIR)/Terminal.cc
SRC_FILES += $(SRCDIR)/Driver.cc
SRC_FILES += $(SRCDIR)/DecafParser.cc

OBJECTS :=  $(OBJDIR)/Parser.o $(OBJDIR)/Scanner.o $(SRC_FILES:$(SRCDIR)/%.cc=$(OBJDIR)/%.o)

CXX      = g++
CXXFLAGS = -W -Wall -Wextra -ansi -g
INCLUDE  = -I$(SRCDIR)/ -I/usr/local/opt/flex/include/
LDFLAGS  = 


##############################
# Rules building the targets #
##############################

all: $(TARGET)


$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cc
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@


$(PARSER): $(PARSER_FILES)
	bison -o $(PARSER) --defines=$(SRCDIR)/Parser.hh $(PARSER_FILES)
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