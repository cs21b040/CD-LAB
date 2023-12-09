%{
#include<stdio.h>
int yylex();
int yyerror(char *);
int eflag=0;
extern FILE * yyin;
%}
%token REAL CPX SEMI SGN

%%
S : E SEMI {printf("\t\tVALID\n");} S | {printf("Completed\n");} ; 
E : F REAL SGN CPX | F CPX SGN REAL | F REAL  | F CPX ;
F : SGN | ;
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