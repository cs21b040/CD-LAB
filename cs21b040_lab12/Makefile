parser: y.tab.c lex.yy.c y.tab.h
	gcc -w y.tab.c lex.yy.c  -ll -ly  -o parser
lex.yy.c: for.l
	lex for.l
y.tab.c: for.y
	yacc -v -d -t for.y
clean:
	rm -f parser y.tab.c lex.yy.c y.tab.h y.output
