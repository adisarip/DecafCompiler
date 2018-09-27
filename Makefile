# Makefile to build the decaf parser

decaf_parser:	decaf_scanner.l decaf_parser.y
		bison -d decaf_parser.y
		flex decaf_scanner.l
		gcc-8 -o $@ decaf_parser.tab.c lex.yy.c -ll

clean:
	rm *.tab.h *.tab.c lex.yy.c decaf_parser
