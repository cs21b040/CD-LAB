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
				int False;
				int lexval;
				float fval;
				int intVal;
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
%type <node> START B R ID UNARY STLIST STMT E T F VARTEMP 
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
| IF LPAREN B RPAREN LCURL STLIST RCURL ELSE LCURL STLIST RCURL {
	$$ = (struct Node*)malloc(sizeof(struct Node));
	$3->True=l;
	l++;
	$3->False=l;
	l++;
	strcat($$->str,$3->str);
	strcat($$->str," goto L");
	strcat($$->str,get_label($3->True));
	strcat($$->str,"\ngoto L");
	strcat($$->str,get_label($3->False));
	strcat($$->str,"\nL");
	strcat($$->str,get_label($3->True));
	strcat($$->str,":\n");
	strcat($$->str,$6->str);
	strcat($$->str,"goto L");
	strcat($$->str,get_label(l));
	strcat($$->str,"\n L");
	strcat($$->str,get_label($3->False));
	strcat($$->str,":\n");
	strcat($$->str,$10->str);
	strcat($$->str,"L");
	strcat($$->str,get_label(l));
	l++;
	strcat($$->str,":\n");
}
| IF LPAREN B RPAREN LCURL STLIST RCURL {
	$$ = (struct Node*)malloc(sizeof(struct Node));
	strcat($$->str,$3->str);
	strcat($$->str," goto L");
	strcat($$->str,get_label($3->True));
	strcat($$->str,"\ngoto L");
	strcat($$->str,get_label($3->False));
	strcat($$->str,"\nL");
	strcat($$->str,get_label($3->True));
	strcat($$->str,":\n");
	strcat($$->str,$6->str);
	strcat($$->str,"L");
	strcat($$->str,get_label($3->False));
	strcat($$->str,":\n");
};

B: E RELOP E {
	$$ = (struct Node*)malloc(sizeof(struct Node));

	strcpy($$->str, $1->str);
	strcat($$->str,$3->str);
	strcat($$->str,"if t");
	strcat($$->str,get_label($1->lexval));
	strcat($$->str," ");
	strcat($$->str,$2);
	strcat($$->str," t");
	strcat($$->str,get_label($3->lexval));
}
| B OR B {
  $$ = (struct Node*)malloc(sizeof(struct Node));
  $1->True = $$->True;
  $1->False = l;
  l++;
  $3->True = $$->True;
  $3->False = $$->False;
  strcat($$->str, $1->str);
  strcat($$->str, "goto L");
  strcat($$->str, get_label($1->True));
  strcat($$->str, "\n");
  strcat($$->str, $3->str);
}
| B AND B {
  $$ = (struct Node*)malloc(sizeof(struct Node));
  $1->True = l;
  $1->False = $$->False;
  $3->True = $$->True;
  $3->False = $$->False;
  strcat($$->str, $1->str);
  strcat($$->str, "goto L");
  strcat($$->str, get_label($1->True));
  strcat($$->str, "\n");
  strcat($$->str, $3->str);
  l++;
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