%option noyywrap
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "y.tab.h"
%}
%%
"i"[0-9]* {printf("%s",yytext);return CPX;}
[0-9]*"i" {printf("%s",yytext);return CPX;}
[0-9]+ {printf("%s",yytext);return REAL;}
";" {printf("%s",yytext);return SEMI;}
[+-] {printf("%s",yytext);return SGN;}
[ \t] ; {printf("%s",yytext);/* ignore white space */ }
"$"		{ return 0; }
.  		{ printf("%s",yytext);return yytext[0]; }
%%