%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "y.tab.h"
%}
%%
"int" {strcpy(yylval.lexeme,yytext);return DT_INT;}
"float" {strcpy(yylval.lexeme,yytext);return DT_FLOAT;}
"char" {strcpy(yylval.lexeme,yytext);return DT_CHAR;}
"if"   {strcpy(yylval.lexeme,yytext);return IF;}
"else" {strcpy(yylval.lexeme,yytext);return ELSE;}
"while" {strcpy(yylval.lexeme,yytext);return WHILE;}
"break" {strcpy(yylval.lexeme,yytext);return BREAK;}
"switch" {strcpy(yylval.lexeme,yytext);return SWITCH;}
"case" {strcpy(yylval.lexeme,yytext);return CASE;}
"default" {strcpy(yylval.lexeme,yytext);return DEFAULT;}
[a-zA-Z]([a-zA-Z0-9_])* {
    strcpy(yylval.lexeme,yytext);
    return VAR;
}
[0-9]+ {
    yylval.val=atoi(yytext);
     return INT;
}
[0-9]+\.[0-9]+ {
    char* a=yytext;
    yylval.fval=atof(a);
    return FLOAT;
}
"," {strcpy(yylval.lexeme,yytext);return COMMA;}
"="  {strcpy(yylval.lexeme,yytext);return ASSIGN;}
"--" {strcpy(yylval.lexeme,yytext);return DECR;}
"++" {strcpy(yylval.lexeme,yytext);return INCR;}
"+"  {strcpy(yylval.lexeme,yytext);return PLUS;}
"-"  {strcpy(yylval.lexeme,yytext);return MINUS;}
"*"  {strcpy(yylval.lexeme,yytext);return STAR;}
"/"  {strcpy(yylval.lexeme,yytext);return DIV;}
"("  {strcpy(yylval.lexeme,yytext);return LPAREN;}
")"  {strcpy(yylval.lexeme,yytext);return RPAREN;}
"{"  {strcpy(yylval.lexeme,yytext);return LCURL;}
"}"  {strcpy(yylval.lexeme,yytext);return RCURL;}
"["  {strcpy(yylval.lexeme,yytext);return LSQB;}
"]"  {strcpy(yylval.lexeme,yytext);return RSQB;}
"\'"[a-zA-Z]"\'" {strcpy(yylval.lexeme,yytext);return CHAR;}
"=="|"<="|">="|"<"|">"|"!=" {
    strcpy(yylval.lexeme, yytext);
    return RELOP;
}
"||" {
    strcpy(yylval.lexeme, yytext);
    return OR;
}
"&&" {
    strcpy(yylval.lexeme, yytext);
    return AND;
}
"//".*[\n] {}
";" {strcpy(yylval.lexeme, yytext);return SEMI;}
":" {strcpy(yylval.lexeme, yytext);return COLON;}
[ ]  {printf("%s",yytext);};
[\t\n] {;}
. {return yytext[0];}
%%