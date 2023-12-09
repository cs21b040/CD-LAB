%{
#include<stdio.h>
int yylex();
int yyerror(char *);
int eflag=0;
extern FILE * yyin;
%}

%token NUMBER ADD SUB MUL DIV	ID ASGN 	LP RP SCOL
%%

slist : 	stmt SCOL {printf("\tAccepted\n\n");} slist | {printf("\n\n\tCompleted..!\n");} ;

stmt 	:	ID ASGN EXPR ;
EXPR 	: 	EXPR ADD TERM 	| EXPR SUB TERM 	| 	TERM ;
TERM 	:	TERM MUL FACT 	| TERM DIV FACT 	| 	FACT ;
FACT 	: 	LP EXPR RP  	| ID 	| 	NUMBER ;

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

