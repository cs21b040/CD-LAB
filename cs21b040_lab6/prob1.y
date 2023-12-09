%{
#include<stdio.h>
int yylex();
int yyerror(char *);
int eflag=0;
extern FILE * yyin;
%}
%token VAR FLOAT INT PLUS MINUS STAR DIV LPAREN RPAREN DECR INCR ASSIGN SEMI 
%%
S : U SEMI {printf("\t\tVALID\n");} S | ;
U : VAR ASSIGN E ;
E : E PLUS T | E MINUS T |T;
T : T STAR F | T DIV F | F;
F : DECR VAR | INCR VAR | VAR INCR | VAR DECR  | P;
Q : MINUS P | P ;
P : VAR | LPAREN E RPAREN | INT | FLOAT ;
%%
int yyerror(char *s){
    while(yylex()!=SEMI) {;}
    printf("\t\tINVALID\n");
	yyparse();
}

int main(int argc, char* argv[]){
	if(argc > 1){
		FILE *fp = fopen(argv[1], "r");
		if(fp)
			yyin = fp;
	}
	yyparse();
	return 0;
}
