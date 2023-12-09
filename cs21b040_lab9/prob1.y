%{
		#include <stdio.h>
		#include <string.h>
		#include<stdlib.h>
		#include<ctype.h>
		#include<math.h>
		int yylex();
		int yyerror();
		int t=0;
		int l=0;
		struct Node {
			int True;
			int TrueList[100];
			int FalseList[100];
			int False;
			int lexval;
			float fval;
			int intVal;
			int begin;
			int next;
			char str[10000];
		};
	char* to_String(float num);
	char* get_label(int t);
	extern FILE * yyin;
%}

%union {
	int val;
	float fval;
	char lexeme[100];
	struct Node* node;
}

%token <lexeme> SEMI ASSIGN RELOP VAR INCR DECR PLUS MINUS STAR DIV LPAREN RPAREN IF ELSE LCURL RCURL AND OR WHILE
%token <val> INT
%token <fval> FLOAT
%type <node> START B R ID UNARY STLIST STMT E T F VARTEMP BLIST
%left OR
%left AND
%%

START: STLIST {	
	$$ = (struct Node*)malloc(sizeof(struct Node));
	strcpy($$->str, $1->str);
	printf("\n%s", $1->str);
};

STLIST: STMT STLIST {
	$$ = (struct Node*)malloc(sizeof(struct Node));
	strcpy($$->str, $1->str);
	strcat($$->str, "\n");
	strcat($$->str, $2->str);
}
| STMT{
	strcpy($$->str, $1->str);
};
STMT: VAR ASSIGN E SEMI{
		$$ = (struct Node*)malloc(sizeof(struct Node));
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
	strcat($$->str,"goto L");
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
| WHILE LPAREN BLIST RPAREN LCURL STLIST RCURL {
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
	strcat($$->str,$6->str);
	strcat($$->str,"goto L");
	strcat($$->str,get_label($$->begin));
	strcat($$->str,"\n");
	for(int i=0;i<sizeof($3->FalseList)/sizeof(int);i++){
		if($3->FalseList[i]==-1) break;
		strcat($$->str,"L");
		strcat($$->str,get_label($3->FalseList[i]));
		strcat($$->str,": \n");
	}
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

VARTEMP: VAR {
	$$ = (struct Node*)malloc(sizeof(struct Node));
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
};

%%

int yyerror(){
		printf("\tRejected EXPR\n\n");
}

int main(int argc, char* argv[])
{
	if(argc > 1)
	{
		FILE *fp = fopen(argv[1], "r");
		if(fp) yyin = fp;
	}
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