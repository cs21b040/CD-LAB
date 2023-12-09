%option noyywrap
%{
%}
%%
("http"|"https"|"ftp")("://")([a-zA-Z0-9]*':'[a-zA-Z0-9]*'@')?(.*)(':'[0-9]*)?("/")?((.+)("/"))*(.*"?"(.+)("=")(.+)"&")*((.+)("=")(.+))?(.*) {
//SCHEME + USER + PASSWORD + HOST + PORT + PATH + KEY VALUE PAIRS
    printf("URL %s : \n",yytext);
    int i=0;
    printf("Scheme : ");
    for(i=0;yytext[i]!='\0';i++){
        if(yytext[i]==':' || yytext[i]=='/'){
            i++;
            break;
        }
        printf("%c",yytext[i]);
    }
    printf("\n");
    while(yytext[i]=='/') i++;
    //user + pass + host + port
    int atrate=0;
    for(int j=i;yytext[j]!='/';j++){
        if(yytext[j]=='@'){
            atrate++;
            break;
        }
    }
    if(atrate==1){
        printf("Username : ");
        for(;yytext[i]!=':';i++){
            printf("%c",yytext[i]);
        }
        printf("\n");
        i++;
        printf("Password : ");
        for(;yytext[i]!='@';i++){
            printf("%c",yytext[i]);
        }
        i++;
        printf("\n");
    }
    printf("Host : ");
    int b=0;
    for(;yytext[i]!='/' ;i++){
        if(yytext[i]==':'){
            b=1;
            break;
        }
        printf("%c",yytext[i]);
    }
    printf("\n");
    if(b==1){
        printf("Port : ");
        i++;
        for(;yytext[i]!='/' && yytext[i]!='\0';i++){
            printf("%c",yytext[i]);
        }
        printf("\n");
    }
    printf("Path : ");
    for(;yytext[i]!='\0';i++){
        if(yytext[i]=='?'){
            break;
        }
        printf("%c",yytext[i]);
    }
    printf("\n");
    if(yytext[i]=='?'){
        i++;
        printf("Key Value Pairs : ");
        for(;yytext[i]!='\0';i++){
            if(yytext[i]=='@'){
                break;
            }
            if(yytext[i]=='&'){
                printf("\n");
                i++;
            }
            printf("%c",yytext[i]);
        }
        printf("\n");
    }
    if(yytext[i]=='@'){
        i++;
        printf("Username : ");
        for(;yytext[i]!=':';i++){
            printf("%c",yytext[i]);
        }
        printf("\n");
        i++;
        printf("Password : ");
        for(;yytext[i]!='\0';i++){
            printf("%c",yytext[i]);
        }
        printf("\n");
    }
}
("file:///path/to/")(.*)(".".*) {
    //FILE + PATH
    printf("URL %s : \n",yytext);
    int i=8;
    printf("Path : ");
    for(;yytext[i]!='\0';i++){
        printf("%c",yytext[i]);
    }
    printf("\n");
}
("mailto:")(.*)(".".*) {
    //MAILTO + EMAIL
    printf("URL %s : \n",yytext);
    int i=7;
    printf("Email : ");
    for(;yytext[i]!='\0';i++){
        printf("%c",yytext[i]);
    }
    printf("\n");
}
.* {
    //ELSE INVALID URL
    printf("URL %s : \n",yytext);
    printf("Invalid URL\n"); 
}

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