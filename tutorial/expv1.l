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
"+"      							return '+';
"-"      							return '-';
"*"	 								return '*';
"/"     								return '/';
"=" 									return '=';
"("									return '(';
")"									return ')';
";"									return ';';

[ \t] ;      /* ignore white space */

"$"		{ return 0; }

.  		{ return yytext[0]; }
%%
