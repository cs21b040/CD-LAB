%option noyywrap
%{
#ifdef BISON
#include "expeval_1.tab.h"
#else
#include "y.tab.h"
#endif
extern int yylval;
%}

%%
[0-9]+	{ 	yylval = atoi(yytext); return NUM; }

[ \t\n]	;		/* ignore white space */

"$"	return 0;	/* logical EOF */

.	return yytext[0];
%%
