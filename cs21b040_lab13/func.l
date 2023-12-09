%option noyywrap
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "y.tab.h"
%}
%%
">="|"<="|"=="|"!="|"<"|">" {printf("%s",yytext);strcpy(yylval.lexeme,yytext); return RELOP;} 
"for" {printf("%s",yytext);strcpy(yylval.lexeme,yytext); return FOR;}
[a-zA-Z]+ {printf("%s",yytext);strcpy(yylval.lexeme,yytext); return VAR;} 
[0-9]*"."[0-9]* {printf("%s",yytext);strcpy(yylval.lexeme,yytext); return FLOAT_VAL;} 
[0-9]* {printf("%s",yytext);strcpy(yylval.lexeme,yytext); return INT_VAL;} 
"+" {printf("%s",yytext);strcpy(yylval.lexeme,yytext); return PLUS;} 
"-" {printf("%s",yytext);strcpy(yylval.lexeme,yytext); return MINUS;} 
"*" {printf("%s",yytext);strcpy(yylval.lexeme,yytext); return STAR;} 
"/" {printf("%s",yytext);strcpy(yylval.lexeme,yytext); return DIV;} 
"=" {printf("%s",yytext);strcpy(yylval.lexeme,yytext); return ASSIGN;} 
"&&" {printf("%s",yytext);strcpy(yylval.lexeme,yytext); return AND;} 
"||" {printf("%s",yytext);strcpy(yylval.lexeme,yytext); return OR;} 
"," {printf("%s",yytext);strcpy(yylval.lexeme,yytext); return COMMA;}
";" {printf("%s",yytext);strcpy(yylval.lexeme,yytext); return SEMI;} 
"(" {printf("%s",yytext);strcpy(yylval.lexeme,yytext); return LEFT;} 
")" {printf("%s",yytext);strcpy(yylval.lexeme,yytext); return RIGHT;} 
"{" {printf("%s",yytext);strcpy(yylval.lexeme,yytext); return LCURL;} 
"}" {printf("%s",yytext);strcpy(yylval.lexeme,yytext); return RCURL;} 
[ \n\t] {/* SKIP */}
. {return yytext[0];}
%%