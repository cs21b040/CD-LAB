%option noyywrap
%{
    #include<stdbool.h>
    void addToFile(char* l,char* type);
    void E(FILE* fp);
    void E1(FILE* fp);
    void T(FILE* fp);
    void T1(FILE* fp);
    void F(FILE* fp);
    bool peek(FILE* fp,char* c);
    void check(FILE* fp);
    bool possible=true;
    /* tokens.txt will be created to store tokens and 
    when the parser completes parsing the file,
    the file will be deleted to ensure correctness for next inputs. */
%}
OPENB "("
CLOSEB ")"
ADD "+"
STAR "*"
ID [a-zA-Z][a-zA-Z0-9_]*
NUMCONST [0-9]+
%%
[' ']+ {}
{NUMCONST} {printf("%s",yytext);addToFile(yytext,"Num");}
{OPENB} {printf("%s",yytext);addToFile(yytext,"OpenB");}
{CLOSEB} {printf("%s",yytext);addToFile(yytext,"CloseB");}
{ADD} {printf("%s",yytext); addToFile(yytext,"Add");}
{STAR} {printf("%s",yytext); addToFile(yytext,"Star");}
{ID} {printf("%s",yytext);addToFile(yytext,"ID");}
[\n]+ {
    addToFile("EOF","EOF");
    FILE* fp=fopen("tokens.txt","r");
    E(fp);
    check(fp);
    fclose(fp);
    remove("tokens.txt");
    possible=true;
}
. {possible=false;printf("%s",yytext);}
%%

bool peek(FILE* fp,char* c){
    int i=0;
    while(!feof(fp)){
        char ch=fgetc(fp);
        if(ch==c[i]){
            i++;
        }
        else{
            fseek(fp,-i-1,SEEK_CUR);
            return false;
        }
        if(c[i]=='\0') {
            fseek(fp,-i,SEEK_CUR);
            return true;
        }
    }
    fseek(fp,-i,SEEK_CUR);
    return false;
}
void advance(FILE* fp){
    while(!feof(fp)){
        char ch=fgetc(fp);
        if(ch=='\n') return;
    }
}
void E(FILE* fp){
    if(peek(fp,"ID") || peek(fp,"Num")){
        T(fp);
        E1(fp);
        return;
    }
    else if(peek(fp,"OpenB")){
        T(fp);
        E1(fp);
        return;
    }
    possible=false;
}
void E1(FILE* fp){
    if(peek(fp,"Add")){
        advance(fp);
        T(fp);
        E1(fp);
        return;
    }
    else if(peek(fp,"EOF")){
        return;
    }
    else if(peek(fp,"CloseB")){
        return;
    }
    possible=false;
    return;
}
void T(FILE* fp){
    if(peek(fp,"ID")|| peek(fp,"Num")){
        F(fp);
        T1(fp);
        return;
    }
    if(peek(fp,"OpenB")){
        F(fp);
        T1(fp);
        return;
    }
    possible=false;
    return;
}
void T1(FILE* fp){
    if(peek(fp,"Add")){
        return;
    } 
    if(peek(fp,"EOF")){
        return;
    }
    if(peek(fp,"Star")){
        advance(fp);
        F(fp);
        T1(fp);
        return;
    }
    if(peek(fp,"CloseB")){
        return;
    }
    possible=false;
    return;
}
void F(FILE* fp){
    if(peek(fp,"ID")|| peek(fp,"Num")){
        advance(fp);
        return;
    }
    if(peek(fp,"OpenB")){
        advance(fp);
        E(fp);
        if(peek(fp,"CloseB")){
            advance(fp);
            return;
        }
        else{
            possible=false;
            return;
        }
    }
    possible=false;
    return;
}
void addToFile(char* l,char* type){
    FILE *fp=fopen("tokens.txt","a");
    fprintf(fp,"%s %s\n",type,l);
    fclose(fp);
}
void check(FILE* fp){
    if(peek(fp,"EOF") && possible){
        printf("--->YES\n");
    }
    else printf("--->NO\n");
}
int main(int argc, char* argv[]) {
    if(argc>1){
        FILE *fp=fopen(argv[1],"r");
        if(fp){
            yyin=fp;
        }
    }
    yylex();
    //for last line 
    addToFile("EOF","EOF");
    FILE* fp=fopen("tokens.txt","r");
    E(fp);
    check(fp);
    fclose(fp);
    //comment this below line to see the tokens.txt file for last input
    remove("tokens.txt");
    return 0;
}
