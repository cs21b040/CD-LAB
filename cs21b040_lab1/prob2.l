%option noyywrap
%{
    void fnct(char *s);
%}
%%
.* {fnct(yytext);}
%%
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
void fnct(char *s){
    char c,b;
    int i=0;
    int j=0;
    while(s[i]!='\0'){
        if(s[i]!='a' && s[i]!='b' && s[i]!='c' && s[i]!='d'){
            b=c;//store the previous character in b to check if it is equal to c in last
            j++;
            i++;
            c='J';//any other character 
            continue;
        }
        c=s[i];//update everychar it reads
        i++;
    }
    if(j==1){
        if(c==b){
            printf("Accept %s\n",s);
        }
        else {
            printf("Reject %s\n",s);
        }
    }
    else{
        //if more than one other charector reject it
        printf("Reject %s\n",s);
    }
}