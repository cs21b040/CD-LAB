%{
    #include<stdio.h>
    extern FILE* yyin;
    int yylex();
    int l=0,t=0;
    int yyerror(char* c);
    struct Node {
        int lexval;
        char* str[1000];
        int True;
        int False;
        int cnt;
        int trueList[100];
        int falseList[100];
    };

%}
%union {
    char lexeme[100];
    struct Node* node;
}
%token <lexeme> FOR VAR FLOAT_VAL RELOP INT_VAL PLUS MINUS STAR DIV OR AND SEMI LEFT RIGHT LCURL RCURL ASSIGN COMMA
%type <node> CODE STLIST ST E T F PARAMS
%left OR
%left AND
%%
CODE: STLIST {
    $$=(struct Node*)malloc(sizeof(struct Node));
    strcpy($$->str,$1->str);
    printf("Accepted\n");
    printf("%s",$1->str);
}
STLIST: ST STLIST {
    $$=(struct Node*)malloc(sizeof(struct Node));
    strcpy($$->str,$1->str);
    strcat($$->str,$2->str);
}|{
    $$=(struct Node*)malloc(sizeof(struct Node));
    strcpy($$->str,"\n");
};
ST : VAR ASSIGN E SEMI {
    $$=(struct Node*)malloc(sizeof(struct Node));
    strcpy($$->str,$3->str);
    strcat($$->str,$1);
    strcat($$->str,"=");
    strcat($$->str,"t");
    strcat($$->str,itoa($3->lexval));
}
| VAR LEFT PARAMS RIGHT SEMI{
    $$=(struct Node*)malloc(sizeof(struct Node));
    strcpy($$->str,$3->str);
    strcat($$->str,"call ");
    strcat($$->str,$1);
    strcat($$->str,",");
    strcat($$->str,itoa($3->cnt));
};
PARAMS: VAR COMMA PARAMS {
    $$=(struct Node*)malloc(sizeof(struct Node));
    $$->cnt=$3->cnt+1;
    strcpy($$->str,"param ");
    strcat($$->str,$1);
    strcat($$->str,"\n");
    strcat($$->str,$3->str);
}
| VAR{
    $$=(struct Node*)malloc(sizeof(struct Node));
    $$->cnt=1;
    strcpy($$->str,"param ");
    strcat($$->str,$1);
    strcat($$->str,"\n");
};
E : E PLUS T {
    $$=(struct Node*)malloc(sizeof(struct Node));
    strcpy($$->str,$1->str);
    strcat($$->str,$3->str);
    strcat($$->str,"t");
    strcat($$->str,itoa(t));
    strcat($$->str,"=");
    strcat($$->str,"t");
    strcat($$->str,itoa($1->lexval));
    strcat($$->str,"+t");
    strcat($$->str,itoa($3->lexval));
    strcat($$->str,"\n");
    $$->lexval=t;
    t++;
}
| E MINUS T {
    $$=(struct Node*)malloc(sizeof(struct Node));
    strcpy($$->str,$1->str);
    strcat($$->str,$3->str);
    strcat($$->str,"t");
    strcat($$->str,itoa(t));
    strcat($$->str,"=");
    strcat($$->str,"t");
    strcat($$->str,itoa($1->lexval));
    strcat($$->str,"-t");
    strcat($$->str,itoa($3->lexval));
    strcat($$->str,"\n");
    $$->lexval=t;
    t++;
}
| T {
    $$=$1;

};
T : T STAR F {
    $$=(struct Node*)malloc(sizeof(struct Node));
    strcpy($$->str,$1->str);
    strcat($$->str,$3->str);
    strcat($$->str,"t");
    strcat($$->str,itoa(t));
    strcat($$->str,"=");
    strcat($$->str,"t");
    strcat($$->str,itoa($1->lexval));
    strcat($$->str,"*t");
    strcat($$->str,itoa($3->lexval));
    strcat($$->str,"\n");
    $$->lexval=t;
    t++;
}
| T DIV F {
    $$=(struct Node*)malloc(sizeof(struct Node));
    strcpy($$->str,$1->str);
    strcat($$->str,$3->str);
    strcat($$->str,"t");
    strcat($$->str,itoa(t));
    strcat($$->str,"=");
    strcat($$->str,"t");
    strcat($$->str,itoa($1->lexval));
    strcat($$->str,"/t");
    strcat($$->str,itoa($3->lexval));
    strcat($$->str,"\n");
    $$->lexval=t;
    t++;
}
| F{
    $$=$1;
};
F : LEFT E RIGHT {
    $$=$2;
}
| INT_VAL {
    $$=(struct Node*)malloc(sizeof(struct Node));
    strcpy($$->str,"t");
    strcat($$->str,itoa(t));
    strcat($$->str,"=");
    strcat($$->str,$1);
    strcat($$->str,"\n");
    $$->lexval=t;
    t++;
}
| VAR{
    $$=(struct Node*)malloc(sizeof(struct Node));
    strcpy($$->str,"t");
    strcat($$->str,itoa(t));
    strcat($$->str,"=");
    strcat($$->str,$1);
    strcat($$->str,"\n");
    $$->lexval=t;
    t++;
}
| FLOAT_VAL {
    $$=(struct Node*)malloc(sizeof(struct Node));
    strcpy($$->str,"t");
    strcat($$->str,itoa(t));
    strcat($$->str,"=");
    strcat($$->str,$1);
    strcat($$->str,"\n");
    $$->lexval=t;
    t++;
};

%%
int yyerror(char* c){
    printf("Rejected EXPR!!!\n");
}
int main(int argc,char* argv[]){
    if(argc>1){
        FILE* fp=fopen(argv[1],"r");
        if(fp) yyin= fp;
    }
    yyparse();
}
/* char* itoa(int i){
    char *c=(char*)malloc(sizeof(char)*100);
    sprintf(c,"%s",i);
    return c;
} */
char* itoa(int i){
    char *c=(char*)malloc(sizeof(char)*100);
    sprintf(c,"%d",i);
    return c;
}