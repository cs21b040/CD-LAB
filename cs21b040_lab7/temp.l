%{
 
    
%}
%%
[a]* {printf("hi");}
.* {printf("hello");}
%%
int main(int argc,char* argv[]){
    if(argc>1){
        FILE* fp=fopen(argv[1],"r");
        if(fp){
            yyin=fp;
        }
    }
    yylex();
    return 0;
}