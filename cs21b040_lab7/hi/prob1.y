%{
#include<stdio.h>
#include<stdlib.h>
int yylex();
int yyerror(char *);
int eflag=1;
extern FILE * yyin;
%}
%union{
	char lexeme[20];
	int val;
	float fval;
	struct Node *node;
}
%token <lexeme> ZERO ONE
%%
E:ZERO ZERO E |;
%%
int yyerror(char *s){
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
