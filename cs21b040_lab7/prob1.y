%{
#include<stdio.h>
#include<stdlib.h>
int yylex();
int yyerror(char *);
int eflag=1;
extern FILE * yyin;
struct Node{
	char lexval[20];
	char token[20];
	int val;
	float fval;
	struct Node *left;
	struct Node *right;
};
void postOrder(struct Node *root);
void preOrder(struct Node *root);
%}
%union{
	char lexeme[20];
	int val;
	float fval;
	struct Node *node;
}
%token VAR FLOAT INT PLUS MINUS STAR DIV LPAREN RPAREN DECR INCR ASSIGN SEMI 
%type <lexeme> VAR
%type <fval> FLOAT 
%type <val> INT
%type <node> E T F P S U VARTEMP POST_VAR

%%
S :	U SEMI {
	printf("\t\tAccepted EXPR\n\n");
	printf("Post Order\n");
	postOrder($1);
	printf("\n\n");
	printf("Pre Order\n");
	preOrder($1);
	printf("\n\nEnd of test case %d\n\n",eflag);
	eflag++;
  } S | {};
U : VARTEMP ASSIGN E {
	$$ = (struct Node *)malloc(sizeof(struct Node));
	$$->left = $1;
	$$->right= $3;
	strcpy($$->lexval,"=");
	strcpy($$->token,"OP");
};
E : E PLUS T {
	$$ = (struct Node *)malloc(sizeof(struct Node));
	$$->left = $1;
	$$->right= $3;
	strcpy($$->lexval,"+");
	strcpy($$->token,"OP");
  }
  | E MINUS T {
	$$ = (struct Node *)malloc(sizeof(struct Node));
	$$->left = $1;
	$$->right= $3;
	strcpy($$->lexval,"-");
	strcpy($$->token,"OP");
  }
  |T{
	$$ = $1;
  };
T : T STAR F {
	$$ = (struct Node *)malloc(sizeof(struct Node));
	$$->left = $1;
	$$->right= $3;
	strcpy($$->lexval,"*");
	strcpy($$->token,"OP");
  }
  | T DIV F {
	$$ = (struct Node *)malloc(sizeof(struct Node));
	$$->left = $1;
	$$->right= $3;
	strcpy($$->lexval,"/");
	strcpy($$->token,"OP");
  }
  | F {
	$$ = $1;
  };
F : DECR VARTEMP {
	$$ =(struct Node*) malloc(sizeof(struct Node));
	$$->left = NULL;
	$$->right = $2;
	strcpy($$->lexval,"--");
	strcpy($$->token,"OP");
  }
  | INCR VARTEMP {
	$$ =(struct Node*) malloc(sizeof(struct Node));
	$$->left = NULL;
	$$->right = $2;
	strcpy($$->lexval,"++");
	strcpy($$->token,"OP");
  }
  | MINUS P{
	$$ =(struct Node*) malloc(sizeof(struct Node));
	$$->left  = NULL;
	$$->right = $2;
	strcpy($$->lexval,"-");
	strcpy($$->token,"OP");
  }
  | POST_VAR INCR {
	$$ =(struct Node*) malloc(sizeof(struct Node));
	$$->left = $1;
	$$->right = NULL;
	strcpy($$->lexval,"++");
	strcpy($$->token,"OP");
  }
  | POST_VAR DECR  {
	$$ =(struct Node*) malloc(sizeof(struct Node));
	$$->left = $1;
	$$->right = NULL;
	strcpy($$->lexval,"--");
	strcpy($$->token,"OP");
  }
  | P{
	$$ = $1;
  };
POST_VAR : VARTEMP {
	$$ = $1;
  }
  | MINUS VARTEMP {
	$$ =(struct Node*) malloc(sizeof(struct Node));
	$$->left = NULL;
	$$->right = $2;
	strcpy($$->lexval,"-");
	strcpy($$->token,"OP");
  };
P : VAR {
	$$ =(struct Node*) malloc(sizeof(struct Node));
	$$->left = NULL;
	$$->right = NULL;
	strcpy($$->lexval,$1);
	strcpy($$->token,"VAR");
  }
  | LPAREN E RPAREN {
	$$ = $2;
  }
  | INT {
	$$ =(struct Node*) malloc(sizeof(struct Node));
	$$->left = NULL;
	$$->right = NULL;
	$$->val = $1;
	strcpy($$->lexval,"");
	strcpy($$->token,"INT");
  }
  | FLOAT {
	$$ =(struct Node*) malloc(sizeof(struct Node));
	$$->left = NULL;
	$$->right = NULL;
	$$->fval = $1;
	strcpy($$->lexval,"");
	strcpy($$->token,"FLOAT");
  };
VARTEMP :VAR {
	$$ =(struct Node*) malloc(sizeof(struct Node));
	$$->left = NULL;
	$$->right = NULL;
	strcpy($$->lexval,$1);
	strcpy($$->token,"VAR");
  } ;
%%
int yyerror(char *s){
    while(yylex()!=SEMI) {;}
    printf("\t\tRejected EXPR\n");
	printf("\n\nEnd of test case %d\n\n",eflag);
	eflag++;
	yyparse();
}

int main(int argc, char* argv[]){
	if(argc > 1){
		FILE *fp = fopen(argv[1], "r");
		if(fp)
			yyin = fp;
	}
	yyparse();
	return 0;
}

void postOrder(struct Node *root){
	if(root){
		postOrder(root->left);
		postOrder(root->right);
		if(!(strcmp(root->token,"VAR")) || !(strcmp(root->token,"OP"))){
			printf("\n%s\t\t%s",root->token,root->lexval);
		}
		else if(!(strcmp(root->token,"INT"))){
			printf("\n%s\t\t%d",root->token,root->val);
		}
		else if(!(strcmp(root->token,"FLOAT"))){
			printf("\n%s\t\t%f",root->token,root->fval);
		}
	}
}

void preOrder(struct Node *root){
	if(root){
		if(!(strcmp(root->token,"VAR")) || !(strcmp(root->token,"OP"))){
			printf("\n%s\t\t%s",root->token,root->lexval);
		}
		else if(!(strcmp(root->token,"INT"))){
			printf("\n%s\t\t%d",root->token,root->val);
		}
		else if(!(strcmp(root->token,"FLOAT"))){
			printf("\n%s\t\t%f",root->token,root->fval);
		}
		preOrder(root->left);
		preOrder(root->right);
	}
}
