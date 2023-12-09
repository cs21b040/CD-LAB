%option noyywrap
%{
    void myprint(char*, char*);
%}

%%
.*(00).* {myprint("Reject", yytext);
/* if string contains 00 as substring reject it*/}
(0|1)*111(0|1)* {myprint("Accept", yytext);
/* Now our string doesnt contain 00 else it would be rejected in the start 
So Now if string contain 111 as substring accept it */}
.* {myprint("Reject", yytext);
/* At this point there is no concecutive 00 or 111 so reject it */}
%%
void myprint(char* token, char* lexeme) {
    printf("\n%s: %s\n", token, lexeme);
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