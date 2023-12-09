%option noyywrap
%{
    void fnct(char *s);
%}

%%
.* {fnct(yytext);/* Pass the string to function */}
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
    int x=0,y=0,i=0;
    int b=1; // flag to  store if any other charector is present in string other than x,y,z
    while(s[i]!='\0'){
        if(s[i]=='x'){
            x++;
        }
        else if(s[i]=='y'){
            y++;
        }
        else if(s[i]=='z'){
            // do nothing
        }
        else{
            b=0;// if b is 0 then reject the string
        }
        i++;
    }
    if(b==0){
        //if it contain char other than x,y,z
        printf("Reject %s",s);
    }
    else if((x%2)==(y%3)){
        printf("Accept %s",s);//given condition
    }
    else{
        printf("Reject %s",s);//else case
    }
}
