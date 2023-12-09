%{
	#include <stdio.h>
	#include <string.h>
	#include<stdlib.h>
	#include<stdbool.h>
	#include<ctype.h>
	#include<limits.h>
	#include<math.h>
	int yylex();
	int yyerror();
	int t=0;
	int l=0;
	int MAX_SIZE=200;
	struct Node {
		int True;
		int TrueList[100];
		int FalseList[100];
		int False;
		int lexval;
		float fval;
		int intVal;
		int type;
		int begin;
		int next;
		char str[10000];
	};
	int cnt=0;
	char* to_String(float num);
	char* get_label(int t);
	extern FILE * yyin;
	struct stack{
		int top;
		int arr[500];
	};
	void initialize(struct stack *st) {
    	st->top = -1;
	}

	void push(struct stack *st, int value) {
		if (st->top < MAX_SIZE - 1) {
			st->arr[++st->top] = value;
		} else {
			printf("stack is full. Cannot push %d\n", value);
		}
	}

	int pop(struct stack *st) {
		if (st->top >= 0) {
			return st->arr[st->top--];
		} else {
			printf("stack is empty\n");
			return -1; 
		}
	}
	int peek(struct stack *st) {
		if (st->top >= 0) {
			return st->arr[st->top];
		} else {
			printf("stack is empty\n");
			return -1; 
		}
	}
	int checkEmpty(struct stack *st) {
		return (st->top == -1);
	}
	struct stack st;
	struct stack stOut;
	struct obj{
		int scope;
		int mem;
	};
	struct obj scope[100];
	int scopeIdx=0;
	int scopeCnt=0;
	FILE* fp;
	struct var{
		char *name[100];
		int type[100];
		int lastIdx;
	};
	struct var varList[100];
	int varIdx[100]={0};
	bool b=false;
	bool undec=false;
%}

%union {
	int val;
	float fval;
	char lexeme[100];
	struct Node* Node;
}

%token <lexeme> SEMI ASSIGN RELOP VAR INCR DECR PLUS MINUS STAR DIV LPAREN RPAREN IF ELSE LCURL RCURL AND OR WHILE SWITCH CASE DEFAULT COLON BREAK DT_INT DT_FLOAT DT_CHAR COMMA LSQB RSQB CHAR
%token <val> INT
%token <fval> FLOAT
%type <Node> START JEXPR CASES B R ID UNARY STLIST STMT E T F VARTEMP BLIST CASEBLK PARAMS DT BRACKETS VARTEMP2
%left OR
%left AND
%%

START: STLIST {	
	$$ = (struct Node*)malloc(sizeof(struct Node));
	strcpy($$->str, $1->str);
	if(!b && !undec) printf("\n%s", $1->str);
	else printf("\n");
};
STLIST:  STLIST STMT{
	$$ = (struct Node*)malloc(sizeof(struct Node));
	strcpy($$->str, $1->str);
	strcat($$->str, "\n");
	strcat($$->str, $2->str);
}
| STMT{
	strcpy($$->str, $1->str);
};
STMT: DT PARAMS SEMI{
	$$ = (struct Node*)malloc(sizeof(struct Node));
	for(int i=0;($2->str[i]!='\0');i++){
		if($2->str[i]==',') continue;
		int next_comma=i;
		while($2->str[next_comma]!=',' && $2->str[next_comma]!='\0') next_comma++;
		char* temp=(char*)malloc(sizeof(char)*(next_comma-i+1));
		int j=0;
		for(j=0;j<next_comma-i;j++){
			temp[j]=$2->str[i+j];
		}
		i=i+j-1;
		temp[j]='\0';
		struct var hi= varList[scope[scopeIdx-1].scope];
		hi.name[hi.lastIdx]=(char) malloc(sizeof(char)*100);
		hi.type[hi.lastIdx]=$1->type;
		hi.name[hi.lastIdx++]=temp;
		varList[scope[scopeIdx-1].scope]=hi;
		strcat($$->str,intToHex(scope[scopeIdx-1].mem));
		strcat($$->str," ");
		strcat($$->str,temp);
		strcat($$->str," ");
		char* type;
		if($1->type==1) {
			strcpy(type,"int");
			if($2->lexval >1) {
				strcpy(type,"int[] ");
				strcat(type,get_label($2->lexval*4));
			}
			scope[scopeIdx-1].mem+=4*$2->lexval;
		}
		else if($1->type==2) {
			strcpy(type,"float");
			if($2->lexval >1) {
				strcpy(type,"float[] ");
				strcat(type,get_label($2->lexval*8));
			}
			scope[scopeIdx-1].mem+=8*$2->lexval;
		}
		else {
			strcpy(type,"char");
			if($2->lexval >1) {
				strcpy(type,"char[] ");
				strcat(type,get_label($2->lexval));
			}
			scope[scopeIdx-1].mem+=1*$2->lexval;
		}
		strcat($$->str,type);
		strcat($$->str,"\n");
		//checking varList
		// printf("%d %d %s %s\n",scope[scopeIdx-1].scope,hi.lastIdx-1,hi.name[hi.lastIdx-1],temp);
		// printf("%s %s %s\n",intToHex(scope[scopeIdx-1].mem),temp,type);
	}
}
|{$$ = (struct Node*)malloc(sizeof(struct Node));
	scope[scopeIdx++].scope=scopeCnt++;
	scope[scopeIdx-1].mem=0;
}LCURL STLIST RCURL{
	struct var temp=varList[scope[scopeIdx-1].scope];
	for(int i=0;i<temp.lastIdx;i++){
		for(int j=i+1;j<temp.lastIdx;j++){
			if(strcmp(temp.name[i],"")==0) continue;
			if(strcmp(temp.name[i],temp.name[j])==0){
				b=true;
				strcpy(varList[scope[scopeIdx-1].scope].name[j],"");
				if(temp.type[i]!=temp.type[j]){
					printf("\nError:conflicting types for %s \n",temp.name[i]);
					continue;
				}
				printf("\nError: redeclaration of %s \n",temp.name[i]);
			}
		}
	}
	strcpy($$->str,$3->str);
	scope[scopeIdx-1].mem=0;
	scopeIdx--;
}
| VAR ASSIGN E SEMI{
		$$ = (struct Node*)malloc(sizeof(struct Node));
		checkVar($1);
		strcpy($$->str, $3->str);
		strcat($$->str, $1);
		strcat($$->str, " = ");
		strcat($$->str, "t");
		strcat($$->str, get_label($3->lexval));
		strcat($$->str, "\n");
}
| UNARY SEMI{
		strcpy($$->str, $1->str);
}
| IF LPAREN BLIST RPAREN LCURL STLIST RCURL ELSE LCURL STLIST RCURL {
	$$ = (struct Node*)malloc(sizeof(struct Node)); 
	strcat($$->str,$3->str);
	for(int i=0;i<sizeof($3->TrueList)/sizeof(int);i++){
		if($3->TrueList[i]==-1) break;
		strcat($$->str,"L");
		strcat($$->str,get_label($3->TrueList[i]));
		strcat($$->str,": \n");
	}
	strcat($$->str,$6->str);
	strcat($$->str," goto L");
	strcat($$->str,get_label(l));
	strcat($$->str,"\n");
	for(int i=0;i<sizeof($3->FalseList)/sizeof(int);i++){
		if($3->FalseList[i]==-1) break;
		strcat($$->str,"L");
		strcat($$->str,get_label($3->FalseList[i]));
		strcat($$->str,": \n");
	}
	strcat($$->str,$10->str);
	strcat($$->str,"L");
	strcat($$->str,get_label(l));
	strcat($$->str,":\n");
	l++;
}
| WHILE LPAREN BLIST RPAREN {
	scope[scopeIdx++].scope=scopeCnt++;
	scope[scopeIdx-1].mem=0;
} LCURL STLIST RCURL {
	$$ = (struct Node*)malloc(sizeof(struct Node));
	$$->begin=l;
	l++;
	strcat($$->str,"L");
	strcat($$->str,get_label($$->begin));
	strcat($$->str,":\n");
	strcat($$->str,$3->str);
	for(int i=0;i<sizeof($3->TrueList)/sizeof(int);i++){
		if($3->TrueList[i]==-1) break;
		strcat($$->str,"L");
		strcat($$->str,get_label($3->TrueList[i]));
		strcat($$->str,": \n");
	}
	strcat($$->str,$7->str);
	strcat($$->str," goto L");
	strcat($$->str,get_label($$->begin));
	strcat($$->str,"\n");
	for(int i=0;i<sizeof($3->FalseList)/sizeof(int);i++){
		if($3->FalseList[i]==-1) break;
		strcat($$->str,"L");
		strcat($$->str,get_label($3->FalseList[i]));
		strcat($$->str,": \n");
	}
	scope[scopeIdx-1].mem=0;
	scopeIdx--;
}
| IF LPAREN BLIST RPAREN LCURL STLIST RCURL {
	$$ = (struct Node*)malloc(sizeof(struct Node));
	strcat($$->str,$3->str);
	for(int i=0;i<sizeof($3->TrueList)/sizeof(int);i++){
		if($3->TrueList[i]==-1) break;
		strcat($$->str,"L");
		strcat($$->str,get_label($3->TrueList[i]));
		strcat($$->str,": \n");
	}
	strcat($$->str,$6->str);
	strcat($$->str,"\n");
	for(int i=0;i<sizeof($3->FalseList)/sizeof(int);i++){
		if($3->FalseList[i]==-1) break;
		strcat($$->str,"L");
		strcat($$->str,get_label($3->FalseList[i]));
		strcat($$->str,": \n");
	}
}
|SWITCH LPAREN JEXPR RPAREN LCURL CASES RCURL{
	$$=(struct Node*)malloc(sizeof(struct Node));
	strcpy($$->str,$3->str);
	strcat($$->str,"\n");
	strcat($$->str,$6->str);
	strcat($$->str,"L");
	if(checkEmpty(&stOut)==1){
		strcat($$->str,get_label(l));
		l++;
	}
	else strcat($$->str,get_label(peek(&stOut)));
	strcat($$->str,":\n");
	if(checkEmpty(&st)==0)pop(&st);
	if(checkEmpty(&stOut)==0)pop(&stOut);
};
DT : DT_INT {
	$$ = (struct Node*)malloc(sizeof(struct Node));
	$$->type=1;
}| DT_FLOAT {
	$$ = (struct Node*)malloc(sizeof(struct Node));
	$$->type=2;
}| DT_CHAR {
	$$ = (struct Node*)malloc(sizeof(struct Node));
	$$->type=3;
};
PARAMS: VARTEMP2 BRACKETS COMMA PARAMS {
	$$=(struct Node*)malloc(sizeof(struct Node));
	$$->lexval=$2->lexval;
	strcpy($$->str,$1->str);
	strcat($$->str,",");
	strcat($$->str,$4->str);
}|VARTEMP2 BRACKETS ASSIGN E COMMA PARAMS {
	$$=(struct Node*)malloc(sizeof(struct Node));
	$$->lexval=$2->lexval;
	strcpy($$->str,$1->str);
	strcat($$->str,",");
	printf("\n%s",$4->str);
	printf("%s = t%d\n",$1->str,$4->lexval);
	strcat($$->str,$6->str);
}| VARTEMP2 BRACKETS {
	$$=(struct Node*)malloc(sizeof(struct Node));
	$$->lexval=$2->lexval;
	strcpy($$->str,$1->str);
}|VARTEMP2 BRACKETS ASSIGN E{
	$$=(struct Node*)malloc(sizeof(struct Node));
	$$->lexval=$2->lexval;
	printf("\n%s",$4->str);
	printf("%s = t%d\n",$1->str,$4->lexval);
	strcpy($$->str,$1->str);
};
BRACKETS:LSQB INT RSQB BRACKETS{
	$$ = (struct Node*) malloc(sizeof(struct Node));
	$$->lexval=$2*$4->lexval;
}
|{
	$$ = (struct Node*) malloc(sizeof(struct Node));
	$$->lexval=1;
};
CASES: CASEBLK CASES {
	$$=(struct Node*)malloc(sizeof(struct Node));
	strcpy($$->str,$1->str);
	strcat($$->str,"L");
	strcat($$->str,get_label($1->False));
	strcat($$->str,":\n");
	strcat($$->str,$2->str);
}
|{
	$$=(struct Node*)malloc(sizeof(struct Node));
	strcpy($$->str,"");
};
CASEBLK: CASE E COLON STLIST{
	$$=(struct Node*)malloc(sizeof(struct Node));
    strcpy($$->str,$2->str);
    strcat($$->str,"ifFalse ");
    $$->False=l;
    l++;
    strcat($$->str,"t");
    strcat($$->str,get_label($2->lexval));
    strcat($$->str,"==t");
    strcat($$->str,get_label(peek(&st)));
    strcat($$->str," goto L");
    strcat($$->str,get_label($$->False));
    strcat($$->str,"\n");
    strcat($$->str,$4->str);
}
|CASE E COLON STLIST BREAK SEMI{
	$$=(struct Node*)malloc(sizeof(struct Node));
    strcpy($$->str,$2->str);
    strcat($$->str,"ifFalse ");
    $$->False=l;
    l++;
    strcat($$->str,"t");
    strcat($$->str,get_label($2->lexval));
    strcat($$->str,"==t");
    strcat($$->str,get_label(peek(&st)));
    strcat($$->str," goto L");
    strcat($$->str,get_label($$->False));
    strcat($$->str,"\n");
    strcat($$->str,$4->str);
    strcat($$->str," goto L");
    if(checkEmpty(&stOut)==1){
		strcat($$->str,get_label(l));
		push(&stOut,l);
		l++;
    }
    else strcat($$->str,get_label(peek(&stOut)));
    strcat($$->str,"\n");
}
|DEFAULT COLON STLIST{
$$=(struct Node*)malloc(sizeof(struct Node));
strcpy($$->str,$3->str);
strcat($$->str,"\n");
};
JEXPR : E {
	$$ = (struct Node*)malloc(sizeof(struct Node));
	strcpy($$->str, $1->str);
	$$->lexval = $1->lexval;
	push(&st,$1->lexval);
};
BLIST : BLIST OR BLIST {
	$$ = (struct Node*)malloc(sizeof(struct Node));
	$$->True=$1->True;
	$$->False=$3->False;
	int j=0;
	int i=0;
	while(i<sizeof($1->TrueList)/sizeof(int)){
		if($1->TrueList[i]==-1) break;
		$$->TrueList[j++]=$1->TrueList[i++];
	}
	i=0;
	while(i<sizeof($3->TrueList)/sizeof(int)){
		if($3->TrueList[i]==-1) break;
		$$->TrueList[j++]=$3->TrueList[i++];
	}
	$$->TrueList[j++]=-1;
	$$->FalseList[0]=$3->False;
	$$->FalseList[1]=-1;
	strcpy($$->str,$1->str);
	for(int i=0;i<sizeof($1->FalseList)/sizeof(int);i++){
		if($1->FalseList[i]==-1) break;
		strcat($$->str,"L");
		strcat($$->str,get_label($1->FalseList[i]));
		strcat($$->str,":\n");
	}
	strcat($$->str,$3->str);
}
| BLIST AND BLIST {
	$$ = (struct Node*)malloc(sizeof(struct Node));
	$$->False=$1->False;
	$$->TrueList[0]=$3->TrueList[0];
	$$->TrueList[1]=-1;
	int j=0;
	int i=0;
	while(i<sizeof($1->FalseList)/sizeof(int)){
		if($1->FalseList[i]==-1) break;
		$$->FalseList[j++]=$1->FalseList[i++];
	}
	i=0;
	while(i<sizeof($3->FalseList)/sizeof(int)){
		if($3->FalseList[i]==-1) break;
		$$->FalseList[j++]=$3->FalseList[i++];
	}
	$$->FalseList[j++]=-1;
	strcpy($$->str,$1->str);
	strcat($$->str,"L");
	strcat($$->str,get_label($1->True));
	strcat($$->str,":\n");
	strcat($$->str,$3->str);
}
| B {
	$$ = $1;
};
B: E RELOP E {
	$$ = (struct Node*)malloc(sizeof(struct Node));
	if($$->True==0){
		$$->True = l;
		l++;
	}
	if($$->False==0){
		$$->False = l;
		l++;
	}
	$$->TrueList[0] = $$->True;
	$$->TrueList[1]=-1;
	$$->FalseList[0] = $$->False;
	$$->FalseList[1]=-1;
	strcpy($$->str, $1->str);
	strcat($$->str,$3->str);
	strcat($$->str,"if t");
	strcat($$->str,get_label($1->lexval));
	strcat($$->str," ");
	strcat($$->str,$2);
	strcat($$->str," t");
	strcat($$->str,get_label($3->lexval));
	strcat($$->str," goto L");
	strcat($$->str,get_label($$->True));
	strcat($$->str,"\ngoto L");
	strcat($$->str,get_label($$->False));
	strcat($$->str,"\n");
};
E: E PLUS T {
	$$ = (struct Node*)malloc(sizeof(struct Node));
	strcpy($$->str, $1->str);
	strcat($$->str, $3->str);
	strcat($$->str, "t");
	strcat($$->str, get_label(t));
	strcat($$->str, " = t");
	strcat($$->str, get_label($1->lexval));
	strcat($$->str, " + t");
	strcat($$->str, get_label($3->lexval));
	strcat($$->str, "\n");
	$$->lexval = t;
	t++;
}
| E MINUS T {
	$$ = (struct Node*)malloc(sizeof(struct Node));
	strcpy($$->str, $1->str);
	strcat($$->str, $3->str);
	strcat($$->str, "t");
	strcat($$->str, get_label(t));
	strcat($$->str, " = t");
	strcat($$->str, get_label($1->lexval));
	strcat($$->str, " - t");
	strcat($$->str, get_label($3->lexval));
	strcat($$->str, "\n");
	$$->lexval = t;
	t++;
}
| T {
	strcpy($$->str, $1->str);
};
T: T STAR F {
	$$ = (struct Node*)malloc(sizeof(struct Node));
	strcpy($$->str, $1->str);
	strcat($$->str, $3->str);
	strcat($$->str, "t");
	strcat($$->str, get_label(t));
	strcat($$->str, " = t");
	strcat($$->str, get_label($1->lexval));
	strcat($$->str, " * t");
	strcat($$->str, get_label($3->lexval));
	strcat($$->str, "\n");
	$$->lexval = t;
	t++;
}
| T DIV F {
	$$ = (struct Node*)malloc(sizeof(struct Node));
	strcpy($$->str, $1->str);
	strcat($$->str, $3->str);
	strcat($$->str, "t");
	strcat($$->str, get_label(t));
	strcat($$->str, " = t");
	strcat($$->str, get_label($1->lexval));
	strcat($$->str, " / t");
	strcat($$->str, get_label($3->lexval));
	strcat($$->str, "\n");
	$$->lexval = t;
	t++;
}
| F {
	strcpy($$->str, $1->str);
};
F:MINUS R {
	$$ = (struct Node*)malloc(sizeof(struct Node));
	strcat($$->str, $2->str);
	strcat($$->str, "t");
	strcat($$->str, get_label(t));
	strcat($$->str, " = -t");
	strcat($$->str, get_label($2->lexval));
	strcat($$->str, "\n");
	$$->lexval = t;
	t++;
}
|VARTEMP DECR {
	$$ = (struct Node*)malloc(sizeof(struct Node));
	strcpy($$->str, "t");
	strcat($$->str, get_label($1->lexval));
	strcat($$->str, " = ");
	strcat($$->str, $1->str);
	strcat($$->str, "-1\n");
	strcat($$->str, $1->str);
	strcat($$->str, " = t");
	strcat($$->str, get_label($1->lexval));
	strcat($$->str, "\n");
	$$->lexval = $1->lexval;
}
|DECR VARTEMP {
	$$ = (struct Node*)malloc(sizeof(struct Node));
	strcpy($$->str, "t");
	strcat($$->str, get_label($2->lexval));
	strcat($$->str, " = ");
	strcat($$->str, $2->str);
	strcat($$->str, "-1\n");
	strcat($$->str, $2->str);
	strcat($$->str, " = t");
	strcat($$->str, get_label($2->lexval));
	strcat($$->str, "\n");
	$$->lexval = $2->lexval;
}
|INCR VARTEMP {
	$$ = (struct Node*)malloc(sizeof(struct Node));
	strcpy($$->str, "t");
	strcat($$->str, get_label($2->lexval));
	strcat($$->str, " = ");
	strcat($$->str, $2->str);
	strcat($$->str, "+1\n");
	strcat($$->str, $2->str);
	strcat($$->str, " = t");
	strcat($$->str, get_label($2->lexval));
	strcat($$->str, "\n");
	$$->lexval = $2->lexval;
}
| VARTEMP INCR {
	$$ = (struct Node*)malloc(sizeof(struct Node));
	strcpy($$->str, "t");
	strcat($$->str, get_label($1->lexval));
	strcat($$->str, " = ");
	strcat($$->str, $1->str);
	strcat($$->str, "+1\n");
	strcat($$->str, $1->str);
	strcat($$->str, " = t");
	strcat($$->str, get_label($1->lexval));
	strcat($$->str, "\n");
	$$->lexval = $1->lexval;
}
| R {
	strcpy($$->str, $1->str);
};

UNARY:VARTEMP DECR {
	$$ = (struct Node*)malloc(sizeof(struct Node));
	strcpy($$->str, "t");
	strcat($$->str, get_label($1->lexval));
	strcat($$->str, " = ");
	strcat($$->str, $1->str);
	strcat($$->str, "-1\n");
	strcat($$->str, $1->str);
	strcat($$->str, " = t");
	strcat($$->str, get_label($1->lexval));
	strcat($$->str, "\n");
	$$->lexval = $1->lexval;
} 
|INCR VARTEMP {
	$$ = (struct Node*)malloc(sizeof(struct Node));
	strcpy($$->str, "t");
	strcat($$->str, get_label($2->lexval));
	strcat($$->str, " = ");
	strcat($$->str, $2->str);
	strcat($$->str, "+1\n");
	strcat($$->str, $2->str);
	strcat($$->str, " = t");
	strcat($$->str, get_label($2->lexval));
	strcat($$->str, "\n");
	$$->lexval = $2->lexval;
}
| VARTEMP INCR {
	$$ = (struct Node*)malloc(sizeof(struct Node));
	strcpy($$->str, "t");
	strcat($$->str, get_label($1->lexval));
	strcat($$->str, " = ");
	strcat($$->str, $1->str);
	strcat($$->str, "+1\n");
	strcat($$->str, $1->str);
	strcat($$->str, " = t");
	strcat($$->str, get_label($1->lexval));
	strcat($$->str, "\n");
	$$->lexval = $1->lexval;
}
| DECR VARTEMP {
	$$ = (struct Node*)malloc(sizeof(struct Node));
	strcpy($$->str, "t");
	strcat($$->str, get_label($2->lexval));
	strcat($$->str, " = ");
	strcat($$->str, $2->str);
	strcat($$->str, "-1\n");
	strcat($$->str, $2->str);
	strcat($$->str, " = t");
	strcat($$->str, get_label($2->lexval));
	strcat($$->str, "\n");
	$$->lexval = $2->lexval;
};

VARTEMP2: VAR {
	$$ = (struct Node*)malloc(sizeof(struct Node));
	strcpy($$->str, $1);
	$$->lexval = t; 
	t++;			 
};
VARTEMP: VAR {
	$$ = (struct Node*)malloc(sizeof(struct Node));
	checkVar($1);
	strcpy($$->str, $1);
	$$->lexval = t; 
	t++;			 
};
R: LPAREN E RPAREN {
	$$ = (struct Node*)malloc(sizeof(struct Node));
	$$->lexval = $2->lexval;
	strcpy($$->str, $2->str);
}
| ID {
	strcpy($$->str, $1->str);
};
ID: VAR {
	$$ = (struct Node*)malloc(sizeof(struct Node));
	checkVar($1);
	strcpy($$->str, "t");
	strcat($$->str, get_label(t));
	strcat($$->str, " = ");
	strcat($$->str, $1);
	strcat($$->str, "\n");
	$$->lexval = t;				
	t++;
}
| FLOAT {
	$$ = (struct Node*)malloc(sizeof(struct Node));
	strcpy($$->str, "t");
	strcat($$->str, get_label(t));
	strcat($$->str, " = ");
	strcat($$->str, to_String($1));
	strcat($$->str, "\n");
	$$->lexval = t;		
	t++;
}
| INT {
	$$ = (struct Node*)malloc(sizeof(struct Node));
	strcpy($$->str, "t");
	strcat($$->str, get_label(t));
	strcat($$->str, " = ");
	strcat($$->str, get_label($1));
	strcat($$->str, "\n");
	$$->lexval = t;
	t++;
}
| VAR LSQB E RSQB {
	checkVar($1);
	$$ = (struct Node*)malloc(sizeof(struct Node));
	strcpy($$->str,$3->str);
	strcat($$->str, "t");
	strcat($$->str, get_label(t));
	strcat($$->str, " = ");
	strcat($$->str, $1);
	strcat($$->str, "[");
	strcat($$->str, "t");
	strcat($$->str, get_label($3->lexval));
	strcat($$->str, "]");
	strcat($$->str, "\n");
	$$->lexval = t;
	t++;
}
| CHAR{
	$$ = (struct Node*)malloc(sizeof(struct Node));
	strcpy($$->str, "t");
	strcat($$->str, get_label(t));
	strcat($$->str, " = ");
	strcat($$->str,$1);
	strcat($$->str, "\n");
	$$->lexval = t;
	t++;
};
%%

int yyerror(){
		printf("\tRejected EXPR\n\n");
}
void checkVar(char* s){
	for(int i=0;i<scopeIdx;i++){
		int j=scope[i].scope;
		int k=0;
		while(k<varList[j].lastIdx){
			if(strcmp(s,varList[j].name[k])==0) return ;
			k++;
		}
	}
	undec=true;
	printf("\nError : Undeclared Variable in Use : %s\n", s);
	return;
}
int main(int argc, char* argv[])
{
	if(argc > 1)
	{
		FILE *fp = fopen(argv[1], "r");
		if(fp) yyin = fp;
	}
	initialize(&st);
	initialize(&stOut);
	fp=fopen("symTable.txt","r");
	scope[scopeIdx].scope=scopeCnt++;
	scope[scopeIdx].mem=0;
	scopeIdx++;
	yyparse();
	return 0;
}

char* to_String(float num){
		char* str = (char*)malloc(100*sizeof(char));
		sprintf(str, "%f", num);
		return str;
}
char* get_label(int t){
	int cnt=0;
	int temp=t;
	int rev=0;
	if(temp==0) cnt=1;
	while(temp!=0){
		cnt++;
		rev=rev*10+temp%10;
		temp/=10;
	}
	char* ans=(char *)malloc(sizeof(char)*cnt);
	for(int i=0;i<cnt;i++){
		ans[i]=rev%10+'0';
		rev/=10;
	}
	return ans;
}

char* intToHex(int num){
	char* str = (char*)malloc(100*sizeof(char));
	sprintf(str, "0x%04x", num);
	return str;
}
