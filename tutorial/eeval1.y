%{
#include<stdio.h>
int yylex();
int yyerror();
%}

%token NUM 

%%
slist	:	E ';' 		{printf("\nResult = %d\n", $1); } slist | ;

E		:	E '+' 	T 	{ printf("\n%d %d", $1, $3); $$ = $1 + $3;}
   		| 	E '-' 	T	{ printf("\n%d %d", $1, $3); $$ = $1 - $3;}
		|	T			{ $$ = $1;}
		;

T		:	T '*' F 		{ printf("\n%d %d", $1, $3); $$ = $1 * $3;}
   	| 	T '/'	F		{ printf("\n%d %d", $1, $3); $$ = $1 / $3;}
		|	F				{ $$ = $1;}
		;

F		:	NUM 			{ $$ = $1;}

%%

int yyerror(){
  printf("\n\nSyntax error\n");
  return 0;
}

extern FILE * yyin;

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