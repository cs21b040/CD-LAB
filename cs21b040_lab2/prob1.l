%option noyywrap
%{
    void addToFile(char* l);
%}
INT "int"
FLOAT "float"
CHAR "char"
VOID "void"
IF "if"
ELSE "else"
WHILE "while"
FOR "for"
BREAK "break"
CONTINUE "continue"
SWITCH "switch"
CASE "case"
STRUCT "struct"
UNION "union"
RETURN "return"
OPENB "("
CLOSEB ")"
OPENCB "{"
CLOSECB "}"
OPENSB "["
CLOSESB "]"
SEMICOLON ";"
COMMA ","
DOT "."
ASSIGN "="
ADD "+"
SUB "-"
DIV "/"
STAR "*"
MOD "%"
AND "&"
OR "|"
NOT "!"
EQ "=="
NE "!="
LT "<"
GT ">"
LE "<="
GE ">="
ID [a-zA-Z][a-zA-Z0-9_]*
NUMCONST [0-9]+
FLOATCONST [0-9]+"."[0-9]+
CHARCONST "'"[a-zA-Z0-9]"'"
PRINTF "printf"
SCANF "scanf"
AUTO "auto"
CONST "const"
SHORT "short"
LONG "long"
DOUBLE "double"
REGISTER "register"
SIGNED "signed"
SIZEOF "sizeof"
GOTO "goto"
%%
"//".* {/* Do Nothing */}
"/*"(.|\n)*"*/" {/* Do Nothing */}
\n {/* Ignore new Line */}
[ \t] {/* Ignore White Space */}
("#".*\n) {/* Ignore Headers & Define's */}
("typedef".*\n) {/* Ignore typedef */}
{INT} {printf("INT %s\n",yytext);}
\".*\" {printf("STRINGCONST %s\n",yytext);}
{NUMCONST} {printf("NUMCONST %s\n",yytext);}
{FLOATCONST} {printf("FLOATCONST %s\n",yytext);}
{CHARCONST} {printf("CHARCONST %s\n",yytext);}
{FLOAT} {printf("FLOAT %s\n",yytext);}
{CHAR} {printf("CHAR %s\n",yytext);}
{VOID} {printf("VOID %s\n",yytext);}
{IF} {printf("IF %s\n",yytext);}
{ELSE} {printf("ELSE %s\n",yytext);}
{WHILE} {printf("WHILE %s\n",yytext);}
{FOR} {printf("FOR %s\n",yytext);}
{STRUCT} {printf("STRUCT %s\n",yytext);}
{UNION} {printf("UNION %s\n",yytext);}
{RETURN} {printf("RETURN %s\n",yytext);}
{OPENB} {printf("OPENB %s\n",yytext);}
{BREAK} {printf("BREAK %s\n",yytext);}
{CONTINUE} {printf("CONTINUE %s\n",yytext);}
{SWITCH} {printf("SWITCH %s\n",yytext);}
{CASE} {printf("CASE %s\n",yytext);}
{CLOSEB} {printf("CLOSEB %s\n",yytext);}
{OPENCB} {printf("OPENCB %s\n",yytext);}
{CLOSECB} {printf("CLOSECB %s\n",yytext);}
{OPENSB} {printf("OPENSB %s\n",yytext);}
{CLOSESB} {printf("CLOSESB %s\n",yytext);}
{SEMICOLON} {printf("SEMICOLON %s\n",yytext);}
{COMMA} {printf("COMMA %s\n",yytext);}
{DOT} {printf("DOT %s\n",yytext);}
{ASSIGN} {printf("ASSIGN %s\n",yytext);}
{PRINTF} {printf("PRINTF %s\n",yytext);addToFile(yytext);}
{SCANF} {printf("SCANF %s\n",yytext);addToFile(yytext);}
{SIGNED} {printf("SIGNED %s\n",yytext);}
{SIZEOF} {printf("SIZEOF %s\n",yytext);addToFile(yytext);}
{ADD} {printf("ADD %s\n",yytext);}
{SUB} {printf("SUB %s\n",yytext);}
{DIV} {printf("DIV %s\n",yytext);}
{STAR} {printf("STAR %s\n",yytext);}
{MOD} {printf("MOD %s\n",yytext);}
{AND} {printf("AND %s\n",yytext);}
{OR} {printf("OR %s\n",yytext);}
{NOT} {printf("NOT %s\n",yytext);}
{EQ} {printf("EQ %s\n",yytext);}
{NE} {printf("NE %s\n",yytext);}
{LT} {printf("LT %s\n",yytext);}
{GT} {printf("GT %s\n",yytext);}
{LE} {printf("LE %s\n",yytext);}
{GE} {printf("GE %s\n",yytext);}
{GOTO} {printf("GOTO %s\n",yytext);}
{AUTO} {printf("AUTO %s\n",yytext);}
{CONST} {printf("CONST %s\n",yytext);}
{SHORT} {printf("SHORT %s\n",yytext);}
{LONG} {printf("LONG %s\n",yytext);}
{DOUBLE} {printf("DOUBLE %s\n",yytext);}
{REGISTER} {printf("REGISTER %s\n",yytext);}
{ID} {printf("ID %s\n",yytext);addToFile(yytext);}
. {printf("ERROR %s\n",yytext);}
%%
void addToFile(char* l){
    FILE *fp=fopen("symbol_table.txt","a");
    fprintf(fp,"%s IDENTIFIER\n",l);
    fclose(fp);
}
int main(int argc, char* argv[]) {
    if(argc>1){
        FILE *fp=fopen(argv[1],"r");
        if(fp){
            yyin=fp;
        }
    }
    yylex();
    return 0;
}