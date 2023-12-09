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
        int begin;
        int trueList[100];
        int falseList[100];
    };

%}
%union {
    char lexeme[100];
    struct Node* node;
}
%token <lexeme> FOR VAR FLOAT_VAL RELOP INT_VAL PLUS MINUS STAR DIV OR AND SEMI LEFT RIGHT LCURL RCURL ASSIGN
%type <node> CODE STLIST ST E T F BLIST B
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
ST : FOR LEFT VAR ASSIGN E SEMI BLIST SEMI VAR ASSIGN E RIGHT LCURL STLIST RCURL {
$$=(struct Node*)malloc(sizeof(struct Node));
strcpy($$->str,$5->str);
strcat($$->str,$3);
strcat($$->str,"=t");
strcat($$->str,itoa($5->lexval));
strcat($$->str,"\n");
$$->begin=l++;
strcat($$->str,"L");
strcat($$->str,itoa($$->begin));
strcat($$->str,":\n");
strcat($$->str,$7->str);
for(int i=0;i<sizeof($7->trueList)/sizeof(int);i++){
    if($7->trueList[i]==-1) break;
    strcat($$->str,"L");
    strcat($$->str,itoa($7->trueList[i]));
    strcat($$->str,":\n");
}
strcat($$->str,$14->str);
strcat($$->str,"\n");
strcat($$->str,$9);
strcat($$->str,"=");
strcat($$->str,$11->str);
strcat($$->str," goto L");
strcat($$->str,itoa($$->begin));
strcat($$->str,"\n");
for(int i=0;i<sizeof($7->falseList)/sizeof(int);i++){
    if($7->falseList[i]==-1) break;
    strcat($$->str,"L");
    strcat($$->str,itoa($7->falseList[i]));
    strcat($$->str,": \n");
}
}
|VAR ASSIGN E SEMI {
    $$=(struct Node*)malloc(sizeof(struct Node));
    strcpy($$->str,$3->str);
    strcat($$->str,$1);
    strcat($$->str,"=");
    strcat($$->str,"t");
    strcat($$->str,itoa($3->lexval));
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
BLIST : BLIST OR BLIST {
    $$=(struct Node*)malloc(sizeof(struct Node));
    $$->True=$1->True;
    $$->False=$1->False;
    int i=0;
    int j=0;
    while($1->trueList[j]!=-1){
        $$->trueList[i++]=$1->trueList[j++];
    }
    j=0;
    while($3->trueList[j]!=-1){
        $$->trueList[i++]=$1->trueList[j++];
    }
    $$->trueList[i++]=-1;
    $$->falseList[0]=$3->False;
    $$->falseList[1]=-1;
    strcpy($$->str,$1->str);
    for(int i=0;i<sizeof($1->falseList)/sizeof(int);i++){
        if($1->falseList[i]==-1) break;
        strcat($$->str,"L");
		strcat($$->str,itoa($1->falseList[i]));
		strcat($$->str,":\n");
    }
    strcat($$->str,$3->str);
}| BLIST AND BLIST {

}| B {
    $$=$1;
};
B : E RELOP E{
    $$=(struct Node*)malloc(sizeof(struct Node));
    if($$->True==0){
        $$->True=l++;
    }
    if($$->False==0) $$->False=l++;
    $$->trueList[0]=$$->True;
    $$->trueList[1]=-1;
    $$->falseList[0]=$$->False;
    $$->falseList[1]=-1;
    strcpy($$->str,$1->str);
    strcat($$->str,$3->str);
    strcat($$->str,"if t");
    strcat($$->str,itoa($1->lexval));
    strcat($$->str,$2);
    strcat($$->str,"t");
    strcat($$->str,itoa($3->lexval));
    strcat($$->str,"goto L");
    strcat($$->str,itoa($$->True));
    strcat($$->str,"\ngoto ");
    strcat($$->str,itoa($$->False));
    strcat($$->str,"\n");
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