%{
#include<stdio.h>
int yylex();
int yyerror(char *);
int eflag=0;
extern FILE * yyin;
%}

%token NUMBER ID 
%%

slist : 	stmt ';' {printf("\tAccepted\n\n");} slist | {printf("\n\n\tCompleted..!\n");} ;

stmt 	:	ID '='  EXPR   ;
EXPR 	: 	EXPR '+' TERM 	| EXPR '-' TERM 	| 	TERM ;
TERM 	:	TERM '*' FACT 	| TERM '/' FACT 	| 	FACT ;
FACT 	: 	'(' EXPR ')' | ID 	| 	NUMBER ;

%%

int yyerror(char *s){
  printf("\n\nError: %s\n", s);
  return 0;
}

int main(int argc, char* argv[])
{
	if(argc > 1)
	{
		FILE *fp = fopen(argv[1], "r");
		if(fp)
			yyin = fp;
	}
	yyparse();
	return 0;
}

