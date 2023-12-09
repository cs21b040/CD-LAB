%option noyywrap
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "y.tab.h"
%}
%%
[a-zA-Z]([a-zA-Z0-9_])* {printf("%s",yytext); return VAR;}
[0-9]+ {printf("%s",yytext); return INT;}
[0-9]+\.[0-9]+ {printf("%s",yytext); return FLOAT;}
"="|"-="|"+="|"*="|"/=" {printf("%s",yytext);return ASSIGN;}
"--" {printf("%s",yytext);return DECR;}
"++" {printf("%s",yytext);return INCR;}
"+"  {printf("%s",yytext);return PLUS;}
"-"  {printf("%s",yytext);return MINUS;}
"*"  {printf("%s",yytext);return STAR;}
"/"  {printf("%s",yytext);return DIV;}
"("  {printf("%s",yytext);return LPAREN;}
")"  {printf("%s",yytext);return RPAREN;}
[ ]  {printf("%s",yytext);};
[\t\n] {;}
";" {printf("%s",yytext);return SEMI;}
. {printf("%s",yytext);return yytext[0];}
%%