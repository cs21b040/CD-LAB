lexer:lex.yy.c
	gcc lex.yy.c -o lexer
lex.yy.c:$(fname)
	lex $(fname)
clean:
	rm -rf lex.yy.c lexer tokens.txt
