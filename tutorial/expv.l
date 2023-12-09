%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
%}
alpha [A-Za-z]
digit [0-9]
%%
{alpha}({alpha}|{digit})*    	return ID;
{digit}+ 							return NUMBER;
"+"      							return ADD;
"-"      							return SUB;
"*"	 								return MUL;
"/"     								return DIV;
"=" 									return ASGN;
"("									return LP;
")"									return RP;
";"									return SCOL;

[ \t] ;      /* ignore white space */

"$"		{ return 0; }

.  		{ return yytext[0]; }
%%
