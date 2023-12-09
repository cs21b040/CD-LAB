lexer: lex.yy.c 
	gcc lex.yy.c -o lexer

lex.yy.c: $(fname)
	lex $(fname)
clean:
	rm -f lex.yy.c lexer  symbol_table.txt