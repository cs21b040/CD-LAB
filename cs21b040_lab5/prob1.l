%option noyywrap
%{
    #include <stdio.h>
    #include <stdlib.h>
    // #include "y.tab.h"
    #include <stdbool.h>
    bool possible=true;
    bool valid(char* s);
%}
%%
.*";" {
    valid(yytext);
}
%%
bool valid(char* s){
    int date=0;
    int i=0;
    for(;s[i]!='\0';i++){
        if(date!=0 && s[i]==' ') break;
        if(s[i]==' ') continue;
        date=date*10+s[i]-'0';
    }
    printf("date :%i \n",date);
    return 0;
    /* for(;s[i]!='\0';i++){
        if(s[i]==' ') continue;
        else if(s[i]=='-') break;
        else possible=false;
    }
    if(date/100!=0) possible=false;
    char c[3]={'0','0','0'};
    for(;s[i]!='\0';i++){
        if(s[i]==' ') continue;
        if(s[i]>='A' && s[i]<='Z' && s[i+1]!='\0' && s[i+2]!='\0'){
            c[0]=s[i];
            c[1]=s[i+1];
            c[2]=s[i+2];
            break;
        }
    }
    for(;s[i]!='\0';i++){
        if(s[i]==' ') continue;
        else if(s[i]=='-') break;
        else possible=false;
    }
    bool temp=false;
    char* month[12]={"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    for(int j=0;j<12;j++){
        if(month[i]==c){
            temp=true;
            break;
        }
    }
    int year=0;
    for(;s[i]!='\0';i++){
        if(year!=0 && s[i]==' ') break;
        if(s[i]==' ') continue;
        year=year*10+s[i]-'0';
    }
    while(s[i]==' ') continue;
    if(s[i]==';'){
        printf("\n %i %s %i",date,c,year);
    } */
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