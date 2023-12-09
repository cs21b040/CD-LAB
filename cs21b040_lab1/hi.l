%{
    
    void check(char*);
%}
%%
.* {printf("%s--->",yytext);check(yytext);}
%%

void check(char* s){
    int i;
    int cnt=0;
    int size=0;
    char c;
    for(i=0;s[i]!='\0';i++){
        size++;
        if(s[i]!='a' && s[i]!='b' && s[i]!='c' && s[i]!='d'){
            cnt++;
            
        }
    }
    printf("%d\n",size);
    if(cnt==1&& s[i-1]==s[size-1]){
        printf("Accepted\n");
    }
    else{
        printf("Not Accepted\n");
    }
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