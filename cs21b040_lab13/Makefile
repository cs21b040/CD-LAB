parser: y.tab.c lex.yy.c y.tab.h
	gcc -w y.tab.c lex.yy.c  -ll -ly  -o parser
lex.yy.c: func.l
	lex func.l
y.tab.c: func.y
	yacc -v -d -t func.y
clean:
	rm -f parser y.tab.c lex.yy.c y.tab.h y.output
