/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 2
#define YYMINOR 0
#define YYPATCH 20230521

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#undef YYBTYACC
#define YYBTYACC 0
#define YYDEBUGSTR YYPREFIX "debug"
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "prob1.y"
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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 87 "prob1.y"
typedef union YYSTYPE {
	int val;
	float fval;
	char lexeme[100];
	struct Node* Node;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 122 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

#if !(defined(yylex) || defined(YYSTATE))
int YYLEX_DECL();
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define SEMI 257
#define ASSIGN 258
#define RELOP 259
#define VAR 260
#define INCR 261
#define DECR 262
#define PLUS 263
#define MINUS 264
#define STAR 265
#define DIV 266
#define LPAREN 267
#define RPAREN 268
#define IF 269
#define ELSE 270
#define LCURL 271
#define RCURL 272
#define AND 273
#define OR 274
#define WHILE 275
#define SWITCH 276
#define CASE 277
#define DEFAULT 278
#define COLON 279
#define BREAK 280
#define DT_INT 281
#define DT_FLOAT 282
#define DT_CHAR 283
#define COMMA 284
#define LSQB 285
#define RSQB 286
#define CHAR 287
#define INT 288
#define FLOAT 289
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    7,    7,    8,   19,    8,    8,    8,    8,   20,
    8,    8,    8,   16,   16,   16,   15,   15,   15,   15,
   17,   17,    2,    2,   14,   14,   14,    1,   13,   13,
   13,    3,    9,    9,    9,   10,   10,   10,   11,   11,
   11,   11,   11,   11,    6,    6,    6,    6,   18,   12,
    4,    4,    5,    5,    5,    5,    5,
};
static const YYINT yylen[] = {                            2,
    1,    2,    1,    3,    0,    4,    4,    2,   11,    0,
    8,    7,    7,    1,    1,    1,    4,    6,    2,    4,
    4,    0,    2,    0,    4,    6,    3,    1,    3,    3,
    1,    3,    3,    3,    1,    3,    3,    1,    2,    2,
    2,    2,    2,    1,    2,    2,    2,    2,    1,    1,
    3,    1,    1,    1,    1,    4,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,   14,   15,   16,    0,
    0,    0,    3,    0,    0,    0,    0,   50,   46,   48,
    0,    0,    0,    8,    2,   47,   45,   49,    0,    0,
    0,    0,    0,    0,    0,    0,   57,   55,   54,   44,
   52,    0,    0,   38,    0,   31,    0,    0,    0,    0,
    0,    4,    0,    0,    0,    0,   42,   41,    0,   39,
    0,    7,    0,    0,    0,    0,   43,   40,    0,    0,
    0,    0,   10,    0,    0,    0,    0,    6,    0,   51,
    0,    0,   36,   37,    0,    0,   30,    0,    0,    0,
    0,    0,   17,   56,    0,    0,    0,    0,    0,    0,
   21,    0,    0,    0,    0,    0,   13,   23,   18,    0,
   11,    0,    0,    0,    0,    0,    0,    9,   26,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {                           0,
  260,  261,  262,  269,  275,  276,  281,  282,  283,  291,
  297,  298,  299,  303,  307,  310,  258,  260,  303,  303,
  267,  267,  267,  257,  299,  261,  262,  260,  306,  309,
  271,  260,  261,  262,  264,  267,  287,  288,  289,  295,
  296,  300,  301,  302,  303,  294,  300,  304,  304,  292,
  300,  257,  285,  308,  298,  285,  303,  303,  260,  295,
  300,  257,  263,  264,  265,  266,  261,  262,  259,  268,
  273,  274,  268,  268,  288,  258,  284,  272,  300,  268,
  301,  301,  302,  302,  300,  271,  304,  304,  311,  271,
  286,  300,  306,  286,  298,  271,  277,  278,  293,  305,
  308,  284,  272,  298,  300,  279,  272,  293,  306,  270,
  272,  279,  298,  271,  298,  298,  280,  272,  257,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {                         10,
   50,   99,   46,   40,   41,   11,   12,   13,   47,   43,
   44,   45,   48,  100,   29,   15,   54,   30,   16,   89,
};
static const YYINT yysindex[] = {                      -197,
 -228, -219, -219, -222, -211, -191,    0,    0,    0,    0,
 -187, -197,    0, -194, -180, -189, -214,    0,    0,    0,
 -214, -214, -214,    0,    0,    0,    0,    0, -155, -178,
 -197, -161, -219, -219, -249, -214,    0,    0,    0,    0,
    0, -152, -172,    0, -139,    0, -168, -131, -121, -129,
 -154,    0, -175, -233,  -65, -214,    0,    0, -161,    0,
  -93,    0, -214, -214, -214, -214,    0,    0, -214, -142,
 -214, -214,    0, -113, -120, -214, -180,    0, -209,    0,
 -172, -172,    0,    0, -154, -197,    0, -104,  -99, -146,
 -178, -164,    0,    0,  -48, -197, -214, -102,  -87, -146,
    0, -180,  -82,  -31, -251, -197,    0,    0,    0,  -80,
    0, -197, -197, -197,   25,   42,  -68,    0,    0,
};
static const YYINT yyrindex[] = {                       -77,
 -128,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    3,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -250,
  -77, -242,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -119,    0,    0,    0,    0,    0,    0,    0,
  -78,    0,    0,  -58,  -77,    0,    0,    0, -138,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -100,  -81,    0,    0, -112,  -77,    0, -208,    0,  -72,
 -250,  -56,    0,    0,  -77,  -77,    0,    0,    0,  -72,
    0,    0,    1,  -77,    0,  -77,    0,    0,    0,    0,
    0,  -77,  -52,  -77,  -35,  -77,    0,    0,    0,
};
#if YYBTYACC
static const YYINT yycindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
#endif
static const YYINT yygindex[] = {                         0,
    0,  102,    0,  171,    0,    0,  -25,  -12,   -7,   87,
  115,    2,  -13,    0,  -50,    0,  117,    0,    0,    0,
};
#define YYTABLESIZE 325
static const YYINT yytable[] = {                         25,
   12,   14,    1,   19,   20,   55,   22,   22,   49,   42,
   59,   63,   64,   14,   53,   51,   53,   36,   50,   50,
   53,   53,   53,   53,   76,   53,   93,  112,   61,   17,
   53,   53,   14,   22,   57,   58,   53,   37,   38,   39,
   18,   53,   25,   53,   21,   32,   33,   34,   79,   35,
   77,  109,   36,   63,   64,   22,   14,   87,   88,   29,
   95,   85,    1,    2,    3,   29,   26,   27,   92,   24,
  104,    4,   37,   38,   39,   23,   94,    5,    6,   28,
  113,   31,   25,    7,    8,    9,  115,   14,  116,  105,
   69,   25,   65,   66,   63,   64,   14,   14,   63,   64,
   25,   52,   25,   25,   62,   14,   53,   14,   63,   64,
   63,   64,   75,   14,   14,   14,   14,   14,   53,  102,
   53,   67,   68,   56,   53,   53,   53,   53,   86,   53,
   97,   98,   50,   50,   53,   53,   70,   35,   74,   35,
   53,   71,   72,   35,   35,   53,   73,   53,   35,   81,
   82,   71,   72,   35,   35,   32,   33,   90,   33,   35,
   32,   32,   33,   33,   35,   91,   35,   33,   71,   63,
   64,   96,   33,   33,   80,   34,  106,   34,   33,   83,
   84,   34,   34,   33,  107,   33,   34,  110,  119,   28,
  114,   34,   34,    5,    1,    2,    3,   34,   19,   24,
   20,  108,   34,    4,   34,   60,   78,  101,    0,    5,
    6,    1,    2,    3,    0,    7,    8,    9,    5,   27,
    4,    0,    0,  103,   27,   27,    5,    6,    1,    2,
    3,    0,    7,    8,    9,    5,   25,    4,    0,    0,
  111,   25,   25,    5,    6,    0,    0,    0,    0,    7,
    8,    9,    0,    0,    0,    0,    0,    0,    0,    0,
   12,   12,   12,    0,    0,    0,    0,    0,    0,   12,
    0,   12,   12,    5,    0,   12,   12,   12,   12,    0,
   12,   12,   12,   12,    1,    2,    3,    0,    0,    0,
    0,    0,    0,    4,    0,    0,    0,    0,    0,    5,
    6,    1,    2,    3,  117,    7,    8,    9,    0,    0,
    4,    0,    0,  118,    0,    0,    5,    6,    0,    0,
    0,    0,    7,    8,    9,
};
static const YYINT yycheck[] = {                         12,
    0,    0,    0,    2,    3,   31,  257,  258,   22,   17,
  260,  263,  264,   12,  257,   23,  259,  267,  261,  262,
  263,  264,  265,  266,  258,  268,   77,  279,   36,  258,
  273,  274,   31,  284,   33,   34,  279,  287,  288,  289,
  260,  284,   55,  286,  267,  260,  261,  262,   56,  264,
  284,  102,  267,  263,  264,  267,   55,   71,   72,  268,
   86,   69,  260,  261,  262,  274,  261,  262,   76,  257,
   96,  269,  287,  288,  289,  267,  286,  275,  276,  260,
  106,  271,   95,  281,  282,  283,  112,   86,  114,   97,
  259,  104,  265,  266,  263,  264,   95,   96,  263,  264,
  113,  257,  115,  116,  257,  104,  285,  106,  263,  264,
  263,  264,  288,  112,  113,  114,  115,  116,  257,  284,
  259,  261,  262,  285,  263,  264,  265,  266,  271,  268,
  277,  278,  261,  262,  273,  274,  268,  257,  268,  259,
  279,  273,  274,  263,  264,  284,  268,  286,  268,   63,
   64,  273,  274,  273,  274,  268,  257,  271,  259,  279,
  273,  274,  263,  264,  284,  286,  286,  268,  273,  263,
  264,  271,  273,  274,  268,  257,  279,  259,  279,   65,
   66,  263,  264,  284,  272,  286,  268,  270,  257,  268,
  271,  273,  274,  271,  260,  261,  262,  279,  257,  272,
  257,  100,  284,  269,  286,   35,  272,   91,   -1,  275,
  276,  260,  261,  262,   -1,  281,  282,  283,  271,  272,
  269,   -1,   -1,  272,  277,  278,  275,  276,  260,  261,
  262,   -1,  281,  282,  283,  271,  272,  269,   -1,   -1,
  272,  277,  278,  275,  276,   -1,   -1,   -1,   -1,  281,
  282,  283,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  260,  261,  262,   -1,   -1,   -1,   -1,   -1,   -1,  269,
   -1,  271,  272,  271,   -1,  275,  276,  277,  278,   -1,
  280,  281,  282,  283,  260,  261,  262,   -1,   -1,   -1,
   -1,   -1,   -1,  269,   -1,   -1,   -1,   -1,   -1,  275,
  276,  260,  261,  262,  280,  281,  282,  283,   -1,   -1,
  269,   -1,   -1,  272,   -1,   -1,  275,  276,   -1,   -1,
   -1,   -1,  281,  282,  283,
};
#if YYBTYACC
static const YYINT yyctable[] = {                        -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,
};
#endif
#define YYFINAL 10
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 289
#define YYUNDFTOKEN 312
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"$end",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"error","SEMI","ASSIGN","RELOP","VAR",
"INCR","DECR","PLUS","MINUS","STAR","DIV","LPAREN","RPAREN","IF","ELSE","LCURL",
"RCURL","AND","OR","WHILE","SWITCH","CASE","DEFAULT","COLON","BREAK","DT_INT",
"DT_FLOAT","DT_CHAR","COMMA","LSQB","RSQB","CHAR","INT","FLOAT","$accept",
"START","JEXPR","CASES","B","R","ID","UNARY","STLIST","STMT","E","T","F",
"VARTEMP","BLIST","CASEBLK","PARAMS","DT","BRACKETS","VARTEMP2","$$1","$$2",
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : START",
"START : STLIST",
"STLIST : STLIST STMT",
"STLIST : STMT",
"STMT : DT PARAMS SEMI",
"$$1 :",
"STMT : $$1 LCURL STLIST RCURL",
"STMT : VAR ASSIGN E SEMI",
"STMT : UNARY SEMI",
"STMT : IF LPAREN BLIST RPAREN LCURL STLIST RCURL ELSE LCURL STLIST RCURL",
"$$2 :",
"STMT : WHILE LPAREN BLIST RPAREN $$2 LCURL STLIST RCURL",
"STMT : IF LPAREN BLIST RPAREN LCURL STLIST RCURL",
"STMT : SWITCH LPAREN JEXPR RPAREN LCURL CASES RCURL",
"DT : DT_INT",
"DT : DT_FLOAT",
"DT : DT_CHAR",
"PARAMS : VARTEMP2 BRACKETS COMMA PARAMS",
"PARAMS : VARTEMP2 BRACKETS ASSIGN E COMMA PARAMS",
"PARAMS : VARTEMP2 BRACKETS",
"PARAMS : VARTEMP2 BRACKETS ASSIGN E",
"BRACKETS : LSQB INT RSQB BRACKETS",
"BRACKETS :",
"CASES : CASEBLK CASES",
"CASES :",
"CASEBLK : CASE E COLON STLIST",
"CASEBLK : CASE E COLON STLIST BREAK SEMI",
"CASEBLK : DEFAULT COLON STLIST",
"JEXPR : E",
"BLIST : BLIST OR BLIST",
"BLIST : BLIST AND BLIST",
"BLIST : B",
"B : E RELOP E",
"E : E PLUS T",
"E : E MINUS T",
"E : T",
"T : T STAR F",
"T : T DIV F",
"T : F",
"F : MINUS R",
"F : VARTEMP DECR",
"F : DECR VARTEMP",
"F : INCR VARTEMP",
"F : VARTEMP INCR",
"F : R",
"UNARY : VARTEMP DECR",
"UNARY : INCR VARTEMP",
"UNARY : VARTEMP INCR",
"UNARY : DECR VARTEMP",
"VARTEMP2 : VAR",
"VARTEMP : VAR",
"R : LPAREN E RPAREN",
"R : ID",
"ID : VAR",
"ID : FLOAT",
"ID : INT",
"ID : VAR LSQB E RSQB",
"ID : CHAR",

};
#endif

#if YYDEBUG
int      yydebug;
#endif

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;
int      yynerrs;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
YYLTYPE  yyloc; /* position returned by actions */
YYLTYPE  yylloc; /* position from the lexer */
#endif

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
#ifndef YYLLOC_DEFAULT
#define YYLLOC_DEFAULT(loc, rhs, n) \
do \
{ \
    if (n == 0) \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 0).last_line; \
        (loc).first_column = YYRHSLOC(rhs, 0).last_column; \
        (loc).last_line    = YYRHSLOC(rhs, 0).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, 0).last_column; \
    } \
    else \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 1).first_line; \
        (loc).first_column = YYRHSLOC(rhs, 1).first_column; \
        (loc).last_line    = YYRHSLOC(rhs, n).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, n).last_column; \
    } \
} while (0)
#endif /* YYLLOC_DEFAULT */
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#if YYBTYACC

#ifndef YYLVQUEUEGROWTH
#define YYLVQUEUEGROWTH 32
#endif
#endif /* YYBTYACC */

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#ifndef YYINITSTACKSIZE
#define YYINITSTACKSIZE 200
#endif

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  *p_base;
    YYLTYPE  *p_mark;
#endif
} YYSTACKDATA;
#if YYBTYACC

struct YYParseState_s
{
    struct YYParseState_s *save;    /* Previously saved parser state */
    YYSTACKDATA            yystack; /* saved parser stack */
    int                    state;   /* saved parser state */
    int                    errflag; /* saved error recovery status */
    int                    lexeme;  /* saved index of the conflict lexeme in the lexical queue */
    YYINT                  ctry;    /* saved index in yyctable[] for this conflict */
};
typedef struct YYParseState_s YYParseState;
#endif /* YYBTYACC */
/* variables for the parser stack */
static YYSTACKDATA yystack;
#if YYBTYACC

/* Current parser state */
static YYParseState *yyps = 0;

/* yypath != NULL: do the full parse, starting at *yypath parser state. */
static YYParseState *yypath = 0;

/* Base of the lexical value queue */
static YYSTYPE *yylvals = 0;

/* Current position at lexical value queue */
static YYSTYPE *yylvp = 0;

/* End position of lexical value queue */
static YYSTYPE *yylve = 0;

/* The last allocated position at the lexical value queue */
static YYSTYPE *yylvlim = 0;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
/* Base of the lexical position queue */
static YYLTYPE *yylpsns = 0;

/* Current position at lexical position queue */
static YYLTYPE *yylpp = 0;

/* End position of lexical position queue */
static YYLTYPE *yylpe = 0;

/* The last allocated position at the lexical position queue */
static YYLTYPE *yylplim = 0;
#endif

/* Current position at lexical token queue */
static YYINT  *yylexp = 0;

static YYINT  *yylexemes = 0;
#endif /* YYBTYACC */
#line 741 "prob1.y"

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
#line 677 "y.tab.c"

/* For use in generated program */
#define yydepth (int)(yystack.s_mark - yystack.s_base)
#if YYBTYACC
#define yytrial (yyps->save)
#endif /* YYBTYACC */

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE *newps;
#endif

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    newps = (YYLTYPE *)realloc(data->p_base, newsize * sizeof(*newps));
    if (newps == 0)
        return YYENOMEM;

    data->p_base = newps;
    data->p_mark = newps + i;
#endif

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;

#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%sdebug: stack size increased to %d\n", YYPREFIX, newsize);
#endif
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    free(data->p_base);
#endif
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif /* YYPURE || defined(YY_NO_LEAKS) */
#if YYBTYACC

static YYParseState *
yyNewState(unsigned size)
{
    YYParseState *p = (YYParseState *) malloc(sizeof(YYParseState));
    if (p == NULL) return NULL;

    p->yystack.stacksize = size;
    if (size == 0)
    {
        p->yystack.s_base = NULL;
        p->yystack.l_base = NULL;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        p->yystack.p_base = NULL;
#endif
        return p;
    }
    p->yystack.s_base    = (YYINT *) malloc(size * sizeof(YYINT));
    if (p->yystack.s_base == NULL) return NULL;
    p->yystack.l_base    = (YYSTYPE *) malloc(size * sizeof(YYSTYPE));
    if (p->yystack.l_base == NULL) return NULL;
    memset(p->yystack.l_base, 0, size * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    p->yystack.p_base    = (YYLTYPE *) malloc(size * sizeof(YYLTYPE));
    if (p->yystack.p_base == NULL) return NULL;
    memset(p->yystack.p_base, 0, size * sizeof(YYLTYPE));
#endif

    return p;
}

static void
yyFreeState(YYParseState *p)
{
    yyfreestack(&p->yystack);
    free(p);
}
#endif /* YYBTYACC */

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab
#if YYBTYACC
#define YYVALID        do { if (yyps->save)            goto yyvalid; } while(0)
#define YYVALID_NESTED do { if (yyps->save && \
                                yyps->save->save == 0) goto yyvalid; } while(0)
#endif /* YYBTYACC */

int
YYPARSE_DECL()
{
    int yym, yyn, yystate, yyresult;
#if YYBTYACC
    int yynewerrflag;
    YYParseState *yyerrctx = NULL;
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  yyerror_loc_range[3]; /* position of error start/end (0 unused) */
#endif
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
    if (yydebug)
        fprintf(stderr, "%sdebug[<# of symbols on state stack>]\n", YYPREFIX);
#endif
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    memset(yyerror_loc_range, 0, sizeof(yyerror_loc_range));
#endif

#if YYBTYACC
    yyps = yyNewState(0); if (yyps == 0) goto yyenomem;
    yyps->save = 0;
#endif /* YYBTYACC */
    yym = 0;
    /* yyn is set below */
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base;
#endif
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
#if YYBTYACC
        do {
        if (yylvp < yylve)
        {
            /* we're currently re-reading tokens */
            yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc = *yylpp++;
#endif
            yychar = *yylexp++;
            break;
        }
        if (yyps->save)
        {
            /* in trial mode; save scanner results for future parse attempts */
            if (yylvp == yylvlim)
            {   /* Enlarge lexical value queue */
                size_t p = (size_t) (yylvp - yylvals);
                size_t s = (size_t) (yylvlim - yylvals);

                s += YYLVQUEUEGROWTH;
                if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL) goto yyenomem;
                if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL) goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL) goto yyenomem;
#endif
                yylvp   = yylve = yylvals + p;
                yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp   = yylpe = yylpsns + p;
                yylplim = yylpsns + s;
#endif
                yylexp  = yylexemes + p;
            }
            *yylexp = (YYINT) YYLEX;
            *yylvp++ = yylval;
            yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *yylpp++ = yylloc;
            yylpe++;
#endif
            yychar = *yylexp++;
            break;
        }
        /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
        yychar = YYLEX;
#if YYBTYACC
        } while (0);
#endif /* YYBTYACC */
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)",
                            YYDEBUGSTR, yydepth, yystate, yychar, yys);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, " <%s>", YYSTYPE_TOSTRING(yychar, yylval));
#endif
            fputc('\n', stderr);
        }
#endif
    }
#if YYBTYACC

    /* Do we have a conflict? */
    if (((yyn = yycindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
        yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        YYINT ctry;

        if (yypath)
        {
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: CONFLICT in state %d: following successful trial parse\n",
                                YYDEBUGSTR, yydepth, yystate);
#endif
            /* Switch to the next conflict context */
            save = yypath;
            yypath = save->save;
            save->save = NULL;
            ctry = save->ctry;
            if (save->state != yystate) YYABORT;
            yyFreeState(save);

        }
        else
        {

            /* Unresolved conflict - start/continue trial parse */
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
            {
                fprintf(stderr, "%s[%d]: CONFLICT in state %d. ", YYDEBUGSTR, yydepth, yystate);
                if (yyps->save)
                    fputs("ALREADY in conflict, continuing trial parse.\n", stderr);
                else
                    fputs("Starting trial parse.\n", stderr);
            }
#endif
            save                  = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (save == NULL) goto yyenomem;
            save->save            = yyps->save;
            save->state           = yystate;
            save->errflag         = yyerrflag;
            save->yystack.s_mark  = save->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (save->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            save->yystack.l_mark  = save->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (save->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            save->yystack.p_mark  = save->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (save->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            ctry                  = yytable[yyn];
            if (yyctable[ctry] == -1)
            {
#if YYDEBUG
                if (yydebug && yychar >= YYEOF)
                    fprintf(stderr, "%s[%d]: backtracking 1 token\n", YYDEBUGSTR, yydepth);
#endif
                ctry++;
            }
            save->ctry = ctry;
            if (yyps->save == NULL)
            {
                /* If this is a first conflict in the stack, start saving lexemes */
                if (!yylexemes)
                {
                    yylexemes = (YYINT *) malloc((YYLVQUEUEGROWTH) * sizeof(YYINT));
                    if (yylexemes == NULL) goto yyenomem;
                    yylvals   = (YYSTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYSTYPE));
                    if (yylvals == NULL) goto yyenomem;
                    yylvlim   = yylvals + YYLVQUEUEGROWTH;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpsns   = (YYLTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYLTYPE));
                    if (yylpsns == NULL) goto yyenomem;
                    yylplim   = yylpsns + YYLVQUEUEGROWTH;
#endif
                }
                if (yylvp == yylve)
                {
                    yylvp  = yylve = yylvals;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp  = yylpe = yylpsns;
#endif
                    yylexp = yylexemes;
                    if (yychar >= YYEOF)
                    {
                        *yylve++ = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                        *yylpe++ = yylloc;
#endif
                        *yylexp  = (YYINT) yychar;
                        yychar   = YYEMPTY;
                    }
                }
            }
            if (yychar >= YYEOF)
            {
                yylvp--;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp--;
#endif
                yylexp--;
                yychar = YYEMPTY;
            }
            save->lexeme = (int) (yylvp - yylvals);
            yyps->save   = save;
        }
        if (yytable[yyn] == ctry)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                                YYDEBUGSTR, yydepth, yystate, yyctable[ctry]);
#endif
            if (yychar < 0)
            {
                yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp++;
#endif
                yylexp++;
            }
            if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                goto yyoverflow;
            yystate = yyctable[ctry];
            *++yystack.s_mark = (YYINT) yystate;
            *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *++yystack.p_mark = yylloc;
#endif
            yychar  = YYEMPTY;
            if (yyerrflag > 0) --yyerrflag;
            goto yyloop;
        }
        else
        {
            yyn = yyctable[ctry];
            goto yyreduce;
        }
    } /* End of code dealing with conflicts */
#endif /* YYBTYACC */
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                            YYDEBUGSTR, yydepth, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yylloc;
#endif
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;
#if YYBTYACC

    yynewerrflag = 1;
    goto yyerrhandler;
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */

yyerrlab:
    /* explicit YYERROR from an action -- pop the rhs of the rule reduced
     * before looking for error recovery */
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif

    yynewerrflag = 0;
yyerrhandler:
    while (yyps->save)
    {
        int ctry;
        YYParseState *save = yyps->save;
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: ERROR in state %d, CONFLICT BACKTRACKING to state %d, %d tokens\n",
                            YYDEBUGSTR, yydepth, yystate, yyps->save->state,
                    (int)(yylvp - yylvals - yyps->save->lexeme));
#endif
        /* Memorize most forward-looking error state in case it's really an error. */
        if (yyerrctx == NULL || yyerrctx->lexeme < yylvp - yylvals)
        {
            /* Free old saved error context state */
            if (yyerrctx) yyFreeState(yyerrctx);
            /* Create and fill out new saved error context state */
            yyerrctx                 = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (yyerrctx == NULL) goto yyenomem;
            yyerrctx->save           = yyps->save;
            yyerrctx->state          = yystate;
            yyerrctx->errflag        = yyerrflag;
            yyerrctx->yystack.s_mark = yyerrctx->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (yyerrctx->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yyerrctx->yystack.l_mark = yyerrctx->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (yyerrctx->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yyerrctx->yystack.p_mark = yyerrctx->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (yyerrctx->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yyerrctx->lexeme         = (int) (yylvp - yylvals);
        }
        yylvp          = yylvals   + save->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yylpp          = yylpsns   + save->lexeme;
#endif
        yylexp         = yylexemes + save->lexeme;
        yychar         = YYEMPTY;
        yystack.s_mark = yystack.s_base + (save->yystack.s_mark - save->yystack.s_base);
        memcpy (yystack.s_base, save->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
        yystack.l_mark = yystack.l_base + (save->yystack.l_mark - save->yystack.l_base);
        memcpy (yystack.l_base, save->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yystack.p_mark = yystack.p_base + (save->yystack.p_mark - save->yystack.p_base);
        memcpy (yystack.p_base, save->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
        ctry           = ++save->ctry;
        yystate        = save->state;
        /* We tried shift, try reduce now */
        if ((yyn = yyctable[ctry]) >= 0) goto yyreduce;
        yyps->save     = save->save;
        save->save     = NULL;
        yyFreeState(save);

        /* Nothing left on the stack -- error */
        if (!yyps->save)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%sdebug[%d,trial]: trial parse FAILED, entering ERROR mode\n",
                                YYPREFIX, yydepth);
#endif
            /* Restore state as it was in the most forward-advanced error */
            yylvp          = yylvals   + yyerrctx->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylpp          = yylpsns   + yyerrctx->lexeme;
#endif
            yylexp         = yylexemes + yyerrctx->lexeme;
            yychar         = yylexp[-1];
            yylval         = yylvp[-1];
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc         = yylpp[-1];
#endif
            yystack.s_mark = yystack.s_base + (yyerrctx->yystack.s_mark - yyerrctx->yystack.s_base);
            memcpy (yystack.s_base, yyerrctx->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yystack.l_mark = yystack.l_base + (yyerrctx->yystack.l_mark - yyerrctx->yystack.l_base);
            memcpy (yystack.l_base, yyerrctx->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yystack.p_mark = yystack.p_base + (yyerrctx->yystack.p_mark - yyerrctx->yystack.p_base);
            memcpy (yystack.p_base, yyerrctx->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yystate        = yyerrctx->state;
            yyFreeState(yyerrctx);
            yyerrctx       = NULL;
        }
        yynewerrflag = 1;
    }
    if (yynewerrflag == 0) goto yyinrecovery;
#endif /* YYBTYACC */

    YYERROR_CALL("syntax error");
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yyerror_loc_range[1] = yylloc; /* lookahead position is error start position */
#endif

#if !YYBTYACC
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
#endif
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: state %d, error recovery shifting to state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* lookahead position is error end position */
                yyerror_loc_range[2] = yylloc;
                YYLLOC_DEFAULT(yyloc, yyerror_loc_range, 2); /* position of error span */
                *++yystack.p_mark = yyloc;
#endif
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: error recovery discarding state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* the current TOS position is the error start position */
                yyerror_loc_range[1] = *yystack.p_mark;
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
                if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark, yystack.p_mark);
#else
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
                --yystack.s_mark;
                --yystack.l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                --yystack.p_mark;
#endif
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, error recovery discarding token %d (%s)\n",
                            YYDEBUGSTR, yydepth, yystate, yychar, yys);
        }
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval, &yylloc);
#else
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
    yym = yylen[yyn];
#if YYDEBUG
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: state %d, reducing by rule %d (%s)",
                        YYDEBUGSTR, yydepth, yystate, yyn, yyrule[yyn]);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            if (yym > 0)
            {
                int i;
                fputc('<', stderr);
                for (i = yym; i > 0; i--)
                {
                    if (i != yym) fputs(", ", stderr);
                    fputs(YYSTYPE_TOSTRING(yystos[yystack.s_mark[1-i]],
                                           yystack.l_mark[1-i]), stderr);
                }
                fputc('>', stderr);
            }
#endif
        fputc('\n', stderr);
    }
#endif
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)

    /* Perform position reduction */
    memset(&yyloc, 0, sizeof(yyloc));
#if YYBTYACC
    if (!yytrial)
#endif /* YYBTYACC */
    {
        YYLLOC_DEFAULT(yyloc, &yystack.p_mark[-yym], yym);
        /* just in case YYERROR is invoked within the action, save
           the start of the rhs as the error start position */
        yyerror_loc_range[1] = yystack.p_mark[1-yym];
    }
#endif

    switch (yyn)
    {
case 1:
#line 102 "prob1.y"
	{	
	yyval.Node = (struct Node*)malloc(sizeof(struct Node));
	strcpy(yyval.Node->str, yystack.l_mark[0].Node->str);
	if(!b && !undec) printf("\n%s", yystack.l_mark[0].Node->str);
	else printf("\n");
}
#line 1355 "y.tab.c"
break;
case 2:
#line 108 "prob1.y"
	{
	yyval.Node = (struct Node*)malloc(sizeof(struct Node));
	strcpy(yyval.Node->str, yystack.l_mark[-1].Node->str);
	strcat(yyval.Node->str, "\n");
	strcat(yyval.Node->str, yystack.l_mark[0].Node->str);
}
#line 1365 "y.tab.c"
break;
case 3:
#line 114 "prob1.y"
	{
	strcpy(yyval.Node->str, yystack.l_mark[0].Node->str);
}
#line 1372 "y.tab.c"
break;
case 4:
#line 117 "prob1.y"
	{
	yyval.Node = (struct Node*)malloc(sizeof(struct Node));
	for(int i=0;(yystack.l_mark[-1].Node->str[i]!='\0');i++){
		if(yystack.l_mark[-1].Node->str[i]==',') continue;
		int next_comma=i;
		while(yystack.l_mark[-1].Node->str[next_comma]!=',' && yystack.l_mark[-1].Node->str[next_comma]!='\0') next_comma++;
		char* temp=(char*)malloc(sizeof(char)*(next_comma-i+1));
		int j=0;
		for(j=0;j<next_comma-i;j++){
			temp[j]=yystack.l_mark[-1].Node->str[i+j];
		}
		i=i+j-1;
		temp[j]='\0';
		struct var hi= varList[scope[scopeIdx-1].scope];
		hi.name[hi.lastIdx]=(char) malloc(sizeof(char)*100);
		hi.type[hi.lastIdx]=yystack.l_mark[-2].Node->type;
		hi.name[hi.lastIdx++]=temp;
		varList[scope[scopeIdx-1].scope]=hi;
		strcat(yyval.Node->str,intToHex(scope[scopeIdx-1].mem));
		strcat(yyval.Node->str," ");
		strcat(yyval.Node->str,temp);
		strcat(yyval.Node->str," ");
		char* type;
		if(yystack.l_mark[-2].Node->type==1) {
			strcpy(type,"int");
			if(yystack.l_mark[-1].Node->lexval >1) {
				strcpy(type,"int[] ");
				strcat(type,get_label(yystack.l_mark[-1].Node->lexval*4));
			}
			scope[scopeIdx-1].mem+=4*yystack.l_mark[-1].Node->lexval;
		}
		else if(yystack.l_mark[-2].Node->type==2) {
			strcpy(type,"float");
			if(yystack.l_mark[-1].Node->lexval >1) {
				strcpy(type,"float[] ");
				strcat(type,get_label(yystack.l_mark[-1].Node->lexval*8));
			}
			scope[scopeIdx-1].mem+=8*yystack.l_mark[-1].Node->lexval;
		}
		else {
			strcpy(type,"char");
			if(yystack.l_mark[-1].Node->lexval >1) {
				strcpy(type,"char[] ");
				strcat(type,get_label(yystack.l_mark[-1].Node->lexval));
			}
			scope[scopeIdx-1].mem+=1*yystack.l_mark[-1].Node->lexval;
		}
		strcat(yyval.Node->str,type);
		strcat(yyval.Node->str,"\n");
		/*checking varList*/
		/* printf("%d %d %s %s\n",scope[scopeIdx-1].scope,hi.lastIdx-1,hi.name[hi.lastIdx-1],temp);*/
		/* printf("%s %s %s\n",intToHex(scope[scopeIdx-1].mem),temp,type);*/
	}
}
#line 1430 "y.tab.c"
break;
case 5:
#line 171 "prob1.y"
	{yyval.Node = (struct Node*)malloc(sizeof(struct Node));
	scope[scopeIdx++].scope=scopeCnt++;
	scope[scopeIdx-1].mem=0;
}
#line 1438 "y.tab.c"
break;
case 6:
#line 174 "prob1.y"
	{
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
	strcpy(yyval.Node->str,yystack.l_mark[-1].Node->str);
	scope[scopeIdx-1].mem=0;
	scopeIdx--;
}
#line 1462 "y.tab.c"
break;
case 7:
#line 194 "prob1.y"
	{
		yyval.Node = (struct Node*)malloc(sizeof(struct Node));
		checkVar(yystack.l_mark[-3].lexeme);
		strcpy(yyval.Node->str, yystack.l_mark[-1].Node->str);
		strcat(yyval.Node->str, yystack.l_mark[-3].lexeme);
		strcat(yyval.Node->str, " = ");
		strcat(yyval.Node->str, "t");
		strcat(yyval.Node->str, get_label(yystack.l_mark[-1].Node->lexval));
		strcat(yyval.Node->str, "\n");
}
#line 1476 "y.tab.c"
break;
case 8:
#line 204 "prob1.y"
	{
		strcpy(yyval.Node->str, yystack.l_mark[-1].Node->str);
}
#line 1483 "y.tab.c"
break;
case 9:
#line 207 "prob1.y"
	{
	yyval.Node = (struct Node*)malloc(sizeof(struct Node)); 
	strcat(yyval.Node->str,yystack.l_mark[-8].Node->str);
	for(int i=0;i<sizeof(yystack.l_mark[-8].Node->TrueList)/sizeof(int);i++){
		if(yystack.l_mark[-8].Node->TrueList[i]==-1) break;
		strcat(yyval.Node->str,"L");
		strcat(yyval.Node->str,get_label(yystack.l_mark[-8].Node->TrueList[i]));
		strcat(yyval.Node->str,": \n");
	}
	strcat(yyval.Node->str,yystack.l_mark[-5].Node->str);
	strcat(yyval.Node->str," goto L");
	strcat(yyval.Node->str,get_label(l));
	strcat(yyval.Node->str,"\n");
	for(int i=0;i<sizeof(yystack.l_mark[-8].Node->FalseList)/sizeof(int);i++){
		if(yystack.l_mark[-8].Node->FalseList[i]==-1) break;
		strcat(yyval.Node->str,"L");
		strcat(yyval.Node->str,get_label(yystack.l_mark[-8].Node->FalseList[i]));
		strcat(yyval.Node->str,": \n");
	}
	strcat(yyval.Node->str,yystack.l_mark[-1].Node->str);
	strcat(yyval.Node->str,"L");
	strcat(yyval.Node->str,get_label(l));
	strcat(yyval.Node->str,":\n");
	l++;
}
#line 1512 "y.tab.c"
break;
case 10:
#line 232 "prob1.y"
	{
	scope[scopeIdx++].scope=scopeCnt++;
	scope[scopeIdx-1].mem=0;
}
#line 1520 "y.tab.c"
break;
case 11:
#line 235 "prob1.y"
	{
	yyval.Node = (struct Node*)malloc(sizeof(struct Node));
	yyval.Node->begin=l;
	l++;
	strcat(yyval.Node->str,"L");
	strcat(yyval.Node->str,get_label(yyval.Node->begin));
	strcat(yyval.Node->str,":\n");
	strcat(yyval.Node->str,yystack.l_mark[-5].Node->str);
	for(int i=0;i<sizeof(yystack.l_mark[-5].Node->TrueList)/sizeof(int);i++){
		if(yystack.l_mark[-5].Node->TrueList[i]==-1) break;
		strcat(yyval.Node->str,"L");
		strcat(yyval.Node->str,get_label(yystack.l_mark[-5].Node->TrueList[i]));
		strcat(yyval.Node->str,": \n");
	}
	strcat(yyval.Node->str,yystack.l_mark[-1].Node->str);
	strcat(yyval.Node->str," goto L");
	strcat(yyval.Node->str,get_label(yyval.Node->begin));
	strcat(yyval.Node->str,"\n");
	for(int i=0;i<sizeof(yystack.l_mark[-5].Node->FalseList)/sizeof(int);i++){
		if(yystack.l_mark[-5].Node->FalseList[i]==-1) break;
		strcat(yyval.Node->str,"L");
		strcat(yyval.Node->str,get_label(yystack.l_mark[-5].Node->FalseList[i]));
		strcat(yyval.Node->str,": \n");
	}
	scope[scopeIdx-1].mem=0;
	scopeIdx--;
}
#line 1551 "y.tab.c"
break;
case 12:
#line 262 "prob1.y"
	{
	yyval.Node = (struct Node*)malloc(sizeof(struct Node));
	strcat(yyval.Node->str,yystack.l_mark[-4].Node->str);
	for(int i=0;i<sizeof(yystack.l_mark[-4].Node->TrueList)/sizeof(int);i++){
		if(yystack.l_mark[-4].Node->TrueList[i]==-1) break;
		strcat(yyval.Node->str,"L");
		strcat(yyval.Node->str,get_label(yystack.l_mark[-4].Node->TrueList[i]));
		strcat(yyval.Node->str,": \n");
	}
	strcat(yyval.Node->str,yystack.l_mark[-1].Node->str);
	strcat(yyval.Node->str,"\n");
	for(int i=0;i<sizeof(yystack.l_mark[-4].Node->FalseList)/sizeof(int);i++){
		if(yystack.l_mark[-4].Node->FalseList[i]==-1) break;
		strcat(yyval.Node->str,"L");
		strcat(yyval.Node->str,get_label(yystack.l_mark[-4].Node->FalseList[i]));
		strcat(yyval.Node->str,": \n");
	}
}
#line 1573 "y.tab.c"
break;
case 13:
#line 280 "prob1.y"
	{
	yyval.Node=(struct Node*)malloc(sizeof(struct Node));
	strcpy(yyval.Node->str,yystack.l_mark[-4].Node->str);
	strcat(yyval.Node->str,"\n");
	strcat(yyval.Node->str,yystack.l_mark[-1].Node->str);
	strcat(yyval.Node->str,"L");
	if(checkEmpty(&stOut)==1){
		strcat(yyval.Node->str,get_label(l));
		l++;
	}
	else strcat(yyval.Node->str,get_label(peek(&stOut)));
	strcat(yyval.Node->str,":\n");
	if(checkEmpty(&st)==0)pop(&st);
	if(checkEmpty(&stOut)==0)pop(&stOut);
}
#line 1592 "y.tab.c"
break;
case 14:
#line 295 "prob1.y"
	{
	yyval.Node = (struct Node*)malloc(sizeof(struct Node));
	yyval.Node->type=1;
}
#line 1600 "y.tab.c"
break;
case 15:
#line 298 "prob1.y"
	{
	yyval.Node = (struct Node*)malloc(sizeof(struct Node));
	yyval.Node->type=2;
}
#line 1608 "y.tab.c"
break;
case 16:
#line 301 "prob1.y"
	{
	yyval.Node = (struct Node*)malloc(sizeof(struct Node));
	yyval.Node->type=3;
}
#line 1616 "y.tab.c"
break;
case 17:
#line 305 "prob1.y"
	{
	yyval.Node=(struct Node*)malloc(sizeof(struct Node));
	yyval.Node->lexval=yystack.l_mark[-2].Node->lexval;
	strcpy(yyval.Node->str,yystack.l_mark[-3].Node->str);
	strcat(yyval.Node->str,",");
	strcat(yyval.Node->str,yystack.l_mark[0].Node->str);
}
#line 1627 "y.tab.c"
break;
case 18:
#line 311 "prob1.y"
	{
	yyval.Node=(struct Node*)malloc(sizeof(struct Node));
	yyval.Node->lexval=yystack.l_mark[-4].Node->lexval;
	strcpy(yyval.Node->str,yystack.l_mark[-5].Node->str);
	strcat(yyval.Node->str,",");
	printf("\n%s",yystack.l_mark[-2].Node->str);
	printf("%s = t%d\n",yystack.l_mark[-5].Node->str,yystack.l_mark[-2].Node->lexval);
	strcat(yyval.Node->str,yystack.l_mark[0].Node->str);
}
#line 1640 "y.tab.c"
break;
case 19:
#line 319 "prob1.y"
	{
	yyval.Node=(struct Node*)malloc(sizeof(struct Node));
	yyval.Node->lexval=yystack.l_mark[0].Node->lexval;
	strcpy(yyval.Node->str,yystack.l_mark[-1].Node->str);
}
#line 1649 "y.tab.c"
break;
case 20:
#line 323 "prob1.y"
	{
	yyval.Node=(struct Node*)malloc(sizeof(struct Node));
	yyval.Node->lexval=yystack.l_mark[-2].Node->lexval;
	printf("\n%s",yystack.l_mark[0].Node->str);
	printf("%s = t%d\n",yystack.l_mark[-3].Node->str,yystack.l_mark[0].Node->lexval);
	strcpy(yyval.Node->str,yystack.l_mark[-3].Node->str);
}
#line 1660 "y.tab.c"
break;
case 21:
#line 330 "prob1.y"
	{
	yyval.Node = (struct Node*) malloc(sizeof(struct Node));
	yyval.Node->lexval=yystack.l_mark[-2].val*yystack.l_mark[0].Node->lexval;
}
#line 1668 "y.tab.c"
break;
case 22:
#line 334 "prob1.y"
	{
	yyval.Node = (struct Node*) malloc(sizeof(struct Node));
	yyval.Node->lexval=1;
}
#line 1676 "y.tab.c"
break;
case 23:
#line 338 "prob1.y"
	{
	yyval.Node=(struct Node*)malloc(sizeof(struct Node));
	strcpy(yyval.Node->str,yystack.l_mark[-1].Node->str);
	strcat(yyval.Node->str,"L");
	strcat(yyval.Node->str,get_label(yystack.l_mark[-1].Node->False));
	strcat(yyval.Node->str,":\n");
	strcat(yyval.Node->str,yystack.l_mark[0].Node->str);
}
#line 1688 "y.tab.c"
break;
case 24:
#line 346 "prob1.y"
	{
	yyval.Node=(struct Node*)malloc(sizeof(struct Node));
	strcpy(yyval.Node->str,"");
}
#line 1696 "y.tab.c"
break;
case 25:
#line 350 "prob1.y"
	{
	yyval.Node=(struct Node*)malloc(sizeof(struct Node));
    strcpy(yyval.Node->str,yystack.l_mark[-2].Node->str);
    strcat(yyval.Node->str,"ifFalse ");
    yyval.Node->False=l;
    l++;
    strcat(yyval.Node->str,"t");
    strcat(yyval.Node->str,get_label(yystack.l_mark[-2].Node->lexval));
    strcat(yyval.Node->str,"==t");
    strcat(yyval.Node->str,get_label(peek(&st)));
    strcat(yyval.Node->str," goto L");
    strcat(yyval.Node->str,get_label(yyval.Node->False));
    strcat(yyval.Node->str,"\n");
    strcat(yyval.Node->str,yystack.l_mark[0].Node->str);
}
#line 1715 "y.tab.c"
break;
case 26:
#line 365 "prob1.y"
	{
	yyval.Node=(struct Node*)malloc(sizeof(struct Node));
    strcpy(yyval.Node->str,yystack.l_mark[-4].Node->str);
    strcat(yyval.Node->str,"ifFalse ");
    yyval.Node->False=l;
    l++;
    strcat(yyval.Node->str,"t");
    strcat(yyval.Node->str,get_label(yystack.l_mark[-4].Node->lexval));
    strcat(yyval.Node->str,"==t");
    strcat(yyval.Node->str,get_label(peek(&st)));
    strcat(yyval.Node->str," goto L");
    strcat(yyval.Node->str,get_label(yyval.Node->False));
    strcat(yyval.Node->str,"\n");
    strcat(yyval.Node->str,yystack.l_mark[-2].Node->str);
    strcat(yyval.Node->str," goto L");
    if(checkEmpty(&stOut)==1){
		strcat(yyval.Node->str,get_label(l));
		push(&stOut,l);
		l++;
    }
    else strcat(yyval.Node->str,get_label(peek(&stOut)));
    strcat(yyval.Node->str,"\n");
}
#line 1742 "y.tab.c"
break;
case 27:
#line 388 "prob1.y"
	{
yyval.Node=(struct Node*)malloc(sizeof(struct Node));
strcpy(yyval.Node->str,yystack.l_mark[0].Node->str);
strcat(yyval.Node->str,"\n");
}
#line 1751 "y.tab.c"
break;
case 28:
#line 393 "prob1.y"
	{
	yyval.Node = (struct Node*)malloc(sizeof(struct Node));
	strcpy(yyval.Node->str, yystack.l_mark[0].Node->str);
	yyval.Node->lexval = yystack.l_mark[0].Node->lexval;
	push(&st,yystack.l_mark[0].Node->lexval);
}
#line 1761 "y.tab.c"
break;
case 29:
#line 399 "prob1.y"
	{
	yyval.Node = (struct Node*)malloc(sizeof(struct Node));
	yyval.Node->True=yystack.l_mark[-2].Node->True;
	yyval.Node->False=yystack.l_mark[0].Node->False;
	int j=0;
	int i=0;
	while(i<sizeof(yystack.l_mark[-2].Node->TrueList)/sizeof(int)){
		if(yystack.l_mark[-2].Node->TrueList[i]==-1) break;
		yyval.Node->TrueList[j++]=yystack.l_mark[-2].Node->TrueList[i++];
	}
	i=0;
	while(i<sizeof(yystack.l_mark[0].Node->TrueList)/sizeof(int)){
		if(yystack.l_mark[0].Node->TrueList[i]==-1) break;
		yyval.Node->TrueList[j++]=yystack.l_mark[0].Node->TrueList[i++];
	}
	yyval.Node->TrueList[j++]=-1;
	yyval.Node->FalseList[0]=yystack.l_mark[0].Node->False;
	yyval.Node->FalseList[1]=-1;
	strcpy(yyval.Node->str,yystack.l_mark[-2].Node->str);
	for(int i=0;i<sizeof(yystack.l_mark[-2].Node->FalseList)/sizeof(int);i++){
		if(yystack.l_mark[-2].Node->FalseList[i]==-1) break;
		strcat(yyval.Node->str,"L");
		strcat(yyval.Node->str,get_label(yystack.l_mark[-2].Node->FalseList[i]));
		strcat(yyval.Node->str,":\n");
	}
	strcat(yyval.Node->str,yystack.l_mark[0].Node->str);
}
#line 1792 "y.tab.c"
break;
case 30:
#line 426 "prob1.y"
	{
	yyval.Node = (struct Node*)malloc(sizeof(struct Node));
	yyval.Node->False=yystack.l_mark[-2].Node->False;
	yyval.Node->TrueList[0]=yystack.l_mark[0].Node->TrueList[0];
	yyval.Node->TrueList[1]=-1;
	int j=0;
	int i=0;
	while(i<sizeof(yystack.l_mark[-2].Node->FalseList)/sizeof(int)){
		if(yystack.l_mark[-2].Node->FalseList[i]==-1) break;
		yyval.Node->FalseList[j++]=yystack.l_mark[-2].Node->FalseList[i++];
	}
	i=0;
	while(i<sizeof(yystack.l_mark[0].Node->FalseList)/sizeof(int)){
		if(yystack.l_mark[0].Node->FalseList[i]==-1) break;
		yyval.Node->FalseList[j++]=yystack.l_mark[0].Node->FalseList[i++];
	}
	yyval.Node->FalseList[j++]=-1;
	strcpy(yyval.Node->str,yystack.l_mark[-2].Node->str);
	strcat(yyval.Node->str,"L");
	strcat(yyval.Node->str,get_label(yystack.l_mark[-2].Node->True));
	strcat(yyval.Node->str,":\n");
	strcat(yyval.Node->str,yystack.l_mark[0].Node->str);
}
#line 1819 "y.tab.c"
break;
case 31:
#line 449 "prob1.y"
	{
	yyval.Node = yystack.l_mark[0].Node;
}
#line 1826 "y.tab.c"
break;
case 32:
#line 452 "prob1.y"
	{
	yyval.Node = (struct Node*)malloc(sizeof(struct Node));
	if(yyval.Node->True==0){
		yyval.Node->True = l;
		l++;
	}
	if(yyval.Node->False==0){
		yyval.Node->False = l;
		l++;
	}
	yyval.Node->TrueList[0] = yyval.Node->True;
	yyval.Node->TrueList[1]=-1;
	yyval.Node->FalseList[0] = yyval.Node->False;
	yyval.Node->FalseList[1]=-1;
	strcpy(yyval.Node->str, yystack.l_mark[-2].Node->str);
	strcat(yyval.Node->str,yystack.l_mark[0].Node->str);
	strcat(yyval.Node->str,"if t");
	strcat(yyval.Node->str,get_label(yystack.l_mark[-2].Node->lexval));
	strcat(yyval.Node->str," ");
	strcat(yyval.Node->str,yystack.l_mark[-1].lexeme);
	strcat(yyval.Node->str," t");
	strcat(yyval.Node->str,get_label(yystack.l_mark[0].Node->lexval));
	strcat(yyval.Node->str," goto L");
	strcat(yyval.Node->str,get_label(yyval.Node->True));
	strcat(yyval.Node->str,"\ngoto L");
	strcat(yyval.Node->str,get_label(yyval.Node->False));
	strcat(yyval.Node->str,"\n");
}
#line 1858 "y.tab.c"
break;
case 33:
#line 480 "prob1.y"
	{
	yyval.Node = (struct Node*)malloc(sizeof(struct Node));
	strcpy(yyval.Node->str, yystack.l_mark[-2].Node->str);
	strcat(yyval.Node->str, yystack.l_mark[0].Node->str);
	strcat(yyval.Node->str, "t");
	strcat(yyval.Node->str, get_label(t));
	strcat(yyval.Node->str, " = t");
	strcat(yyval.Node->str, get_label(yystack.l_mark[-2].Node->lexval));
	strcat(yyval.Node->str, " + t");
	strcat(yyval.Node->str, get_label(yystack.l_mark[0].Node->lexval));
	strcat(yyval.Node->str, "\n");
	yyval.Node->lexval = t;
	t++;
}
#line 1876 "y.tab.c"
break;
case 34:
#line 494 "prob1.y"
	{
	yyval.Node = (struct Node*)malloc(sizeof(struct Node));
	strcpy(yyval.Node->str, yystack.l_mark[-2].Node->str);
	strcat(yyval.Node->str, yystack.l_mark[0].Node->str);
	strcat(yyval.Node->str, "t");
	strcat(yyval.Node->str, get_label(t));
	strcat(yyval.Node->str, " = t");
	strcat(yyval.Node->str, get_label(yystack.l_mark[-2].Node->lexval));
	strcat(yyval.Node->str, " - t");
	strcat(yyval.Node->str, get_label(yystack.l_mark[0].Node->lexval));
	strcat(yyval.Node->str, "\n");
	yyval.Node->lexval = t;
	t++;
}
#line 1894 "y.tab.c"
break;
case 35:
#line 508 "prob1.y"
	{
	strcpy(yyval.Node->str, yystack.l_mark[0].Node->str);
}
#line 1901 "y.tab.c"
break;
case 36:
#line 511 "prob1.y"
	{
	yyval.Node = (struct Node*)malloc(sizeof(struct Node));
	strcpy(yyval.Node->str, yystack.l_mark[-2].Node->str);
	strcat(yyval.Node->str, yystack.l_mark[0].Node->str);
	strcat(yyval.Node->str, "t");
	strcat(yyval.Node->str, get_label(t));
	strcat(yyval.Node->str, " = t");
	strcat(yyval.Node->str, get_label(yystack.l_mark[-2].Node->lexval));
	strcat(yyval.Node->str, " * t");
	strcat(yyval.Node->str, get_label(yystack.l_mark[0].Node->lexval));
	strcat(yyval.Node->str, "\n");
	yyval.Node->lexval = t;
	t++;
}
#line 1919 "y.tab.c"
break;
case 37:
#line 525 "prob1.y"
	{
	yyval.Node = (struct Node*)malloc(sizeof(struct Node));
	strcpy(yyval.Node->str, yystack.l_mark[-2].Node->str);
	strcat(yyval.Node->str, yystack.l_mark[0].Node->str);
	strcat(yyval.Node->str, "t");
	strcat(yyval.Node->str, get_label(t));
	strcat(yyval.Node->str, " = t");
	strcat(yyval.Node->str, get_label(yystack.l_mark[-2].Node->lexval));
	strcat(yyval.Node->str, " / t");
	strcat(yyval.Node->str, get_label(yystack.l_mark[0].Node->lexval));
	strcat(yyval.Node->str, "\n");
	yyval.Node->lexval = t;
	t++;
}
#line 1937 "y.tab.c"
break;
case 38:
#line 539 "prob1.y"
	{
	strcpy(yyval.Node->str, yystack.l_mark[0].Node->str);
}
#line 1944 "y.tab.c"
break;
case 39:
#line 542 "prob1.y"
	{
	yyval.Node = (struct Node*)malloc(sizeof(struct Node));
	strcat(yyval.Node->str, yystack.l_mark[0].Node->str);
	strcat(yyval.Node->str, "t");
	strcat(yyval.Node->str, get_label(t));
	strcat(yyval.Node->str, " = -t");
	strcat(yyval.Node->str, get_label(yystack.l_mark[0].Node->lexval));
	strcat(yyval.Node->str, "\n");
	yyval.Node->lexval = t;
	t++;
}
#line 1959 "y.tab.c"
break;
case 40:
#line 553 "prob1.y"
	{
	yyval.Node = (struct Node*)malloc(sizeof(struct Node));
	strcpy(yyval.Node->str, "t");
	strcat(yyval.Node->str, get_label(yystack.l_mark[-1].Node->lexval));
	strcat(yyval.Node->str, " = ");
	strcat(yyval.Node->str, yystack.l_mark[-1].Node->str);
	strcat(yyval.Node->str, "-1\n");
	strcat(yyval.Node->str, yystack.l_mark[-1].Node->str);
	strcat(yyval.Node->str, " = t");
	strcat(yyval.Node->str, get_label(yystack.l_mark[-1].Node->lexval));
	strcat(yyval.Node->str, "\n");
	yyval.Node->lexval = yystack.l_mark[-1].Node->lexval;
}
#line 1976 "y.tab.c"
break;
case 41:
#line 566 "prob1.y"
	{
	yyval.Node = (struct Node*)malloc(sizeof(struct Node));
	strcpy(yyval.Node->str, "t");
	strcat(yyval.Node->str, get_label(yystack.l_mark[0].Node->lexval));
	strcat(yyval.Node->str, " = ");
	strcat(yyval.Node->str, yystack.l_mark[0].Node->str);
	strcat(yyval.Node->str, "-1\n");
	strcat(yyval.Node->str, yystack.l_mark[0].Node->str);
	strcat(yyval.Node->str, " = t");
	strcat(yyval.Node->str, get_label(yystack.l_mark[0].Node->lexval));
	strcat(yyval.Node->str, "\n");
	yyval.Node->lexval = yystack.l_mark[0].Node->lexval;
}
#line 1993 "y.tab.c"
break;
case 42:
#line 579 "prob1.y"
	{
	yyval.Node = (struct Node*)malloc(sizeof(struct Node));
	strcpy(yyval.Node->str, "t");
	strcat(yyval.Node->str, get_label(yystack.l_mark[0].Node->lexval));
	strcat(yyval.Node->str, " = ");
	strcat(yyval.Node->str, yystack.l_mark[0].Node->str);
	strcat(yyval.Node->str, "+1\n");
	strcat(yyval.Node->str, yystack.l_mark[0].Node->str);
	strcat(yyval.Node->str, " = t");
	strcat(yyval.Node->str, get_label(yystack.l_mark[0].Node->lexval));
	strcat(yyval.Node->str, "\n");
	yyval.Node->lexval = yystack.l_mark[0].Node->lexval;
}
#line 2010 "y.tab.c"
break;
case 43:
#line 592 "prob1.y"
	{
	yyval.Node = (struct Node*)malloc(sizeof(struct Node));
	strcpy(yyval.Node->str, "t");
	strcat(yyval.Node->str, get_label(yystack.l_mark[-1].Node->lexval));
	strcat(yyval.Node->str, " = ");
	strcat(yyval.Node->str, yystack.l_mark[-1].Node->str);
	strcat(yyval.Node->str, "+1\n");
	strcat(yyval.Node->str, yystack.l_mark[-1].Node->str);
	strcat(yyval.Node->str, " = t");
	strcat(yyval.Node->str, get_label(yystack.l_mark[-1].Node->lexval));
	strcat(yyval.Node->str, "\n");
	yyval.Node->lexval = yystack.l_mark[-1].Node->lexval;
}
#line 2027 "y.tab.c"
break;
case 44:
#line 605 "prob1.y"
	{
	strcpy(yyval.Node->str, yystack.l_mark[0].Node->str);
}
#line 2034 "y.tab.c"
break;
case 45:
#line 609 "prob1.y"
	{
	yyval.Node = (struct Node*)malloc(sizeof(struct Node));
	strcpy(yyval.Node->str, "t");
	strcat(yyval.Node->str, get_label(yystack.l_mark[-1].Node->lexval));
	strcat(yyval.Node->str, " = ");
	strcat(yyval.Node->str, yystack.l_mark[-1].Node->str);
	strcat(yyval.Node->str, "-1\n");
	strcat(yyval.Node->str, yystack.l_mark[-1].Node->str);
	strcat(yyval.Node->str, " = t");
	strcat(yyval.Node->str, get_label(yystack.l_mark[-1].Node->lexval));
	strcat(yyval.Node->str, "\n");
	yyval.Node->lexval = yystack.l_mark[-1].Node->lexval;
}
#line 2051 "y.tab.c"
break;
case 46:
#line 622 "prob1.y"
	{
	yyval.Node = (struct Node*)malloc(sizeof(struct Node));
	strcpy(yyval.Node->str, "t");
	strcat(yyval.Node->str, get_label(yystack.l_mark[0].Node->lexval));
	strcat(yyval.Node->str, " = ");
	strcat(yyval.Node->str, yystack.l_mark[0].Node->str);
	strcat(yyval.Node->str, "+1\n");
	strcat(yyval.Node->str, yystack.l_mark[0].Node->str);
	strcat(yyval.Node->str, " = t");
	strcat(yyval.Node->str, get_label(yystack.l_mark[0].Node->lexval));
	strcat(yyval.Node->str, "\n");
	yyval.Node->lexval = yystack.l_mark[0].Node->lexval;
}
#line 2068 "y.tab.c"
break;
case 47:
#line 635 "prob1.y"
	{
	yyval.Node = (struct Node*)malloc(sizeof(struct Node));
	strcpy(yyval.Node->str, "t");
	strcat(yyval.Node->str, get_label(yystack.l_mark[-1].Node->lexval));
	strcat(yyval.Node->str, " = ");
	strcat(yyval.Node->str, yystack.l_mark[-1].Node->str);
	strcat(yyval.Node->str, "+1\n");
	strcat(yyval.Node->str, yystack.l_mark[-1].Node->str);
	strcat(yyval.Node->str, " = t");
	strcat(yyval.Node->str, get_label(yystack.l_mark[-1].Node->lexval));
	strcat(yyval.Node->str, "\n");
	yyval.Node->lexval = yystack.l_mark[-1].Node->lexval;
}
#line 2085 "y.tab.c"
break;
case 48:
#line 648 "prob1.y"
	{
	yyval.Node = (struct Node*)malloc(sizeof(struct Node));
	strcpy(yyval.Node->str, "t");
	strcat(yyval.Node->str, get_label(yystack.l_mark[0].Node->lexval));
	strcat(yyval.Node->str, " = ");
	strcat(yyval.Node->str, yystack.l_mark[0].Node->str);
	strcat(yyval.Node->str, "-1\n");
	strcat(yyval.Node->str, yystack.l_mark[0].Node->str);
	strcat(yyval.Node->str, " = t");
	strcat(yyval.Node->str, get_label(yystack.l_mark[0].Node->lexval));
	strcat(yyval.Node->str, "\n");
	yyval.Node->lexval = yystack.l_mark[0].Node->lexval;
}
#line 2102 "y.tab.c"
break;
case 49:
#line 662 "prob1.y"
	{
	yyval.Node = (struct Node*)malloc(sizeof(struct Node));
	strcpy(yyval.Node->str, yystack.l_mark[0].lexeme);
	yyval.Node->lexval = t; 
	t++;			 
}
#line 2112 "y.tab.c"
break;
case 50:
#line 668 "prob1.y"
	{
	yyval.Node = (struct Node*)malloc(sizeof(struct Node));
	checkVar(yystack.l_mark[0].lexeme);
	strcpy(yyval.Node->str, yystack.l_mark[0].lexeme);
	yyval.Node->lexval = t; 
	t++;			 
}
#line 2123 "y.tab.c"
break;
case 51:
#line 675 "prob1.y"
	{
	yyval.Node = (struct Node*)malloc(sizeof(struct Node));
	yyval.Node->lexval = yystack.l_mark[-1].Node->lexval;
	strcpy(yyval.Node->str, yystack.l_mark[-1].Node->str);
}
#line 2132 "y.tab.c"
break;
case 52:
#line 680 "prob1.y"
	{
	strcpy(yyval.Node->str, yystack.l_mark[0].Node->str);
}
#line 2139 "y.tab.c"
break;
case 53:
#line 683 "prob1.y"
	{
	yyval.Node = (struct Node*)malloc(sizeof(struct Node));
	checkVar(yystack.l_mark[0].lexeme);
	strcpy(yyval.Node->str, "t");
	strcat(yyval.Node->str, get_label(t));
	strcat(yyval.Node->str, " = ");
	strcat(yyval.Node->str, yystack.l_mark[0].lexeme);
	strcat(yyval.Node->str, "\n");
	yyval.Node->lexval = t;				
	t++;
}
#line 2154 "y.tab.c"
break;
case 54:
#line 694 "prob1.y"
	{
	yyval.Node = (struct Node*)malloc(sizeof(struct Node));
	strcpy(yyval.Node->str, "t");
	strcat(yyval.Node->str, get_label(t));
	strcat(yyval.Node->str, " = ");
	strcat(yyval.Node->str, to_String(yystack.l_mark[0].fval));
	strcat(yyval.Node->str, "\n");
	yyval.Node->lexval = t;		
	t++;
}
#line 2168 "y.tab.c"
break;
case 55:
#line 704 "prob1.y"
	{
	yyval.Node = (struct Node*)malloc(sizeof(struct Node));
	strcpy(yyval.Node->str, "t");
	strcat(yyval.Node->str, get_label(t));
	strcat(yyval.Node->str, " = ");
	strcat(yyval.Node->str, get_label(yystack.l_mark[0].val));
	strcat(yyval.Node->str, "\n");
	yyval.Node->lexval = t;
	t++;
}
#line 2182 "y.tab.c"
break;
case 56:
#line 714 "prob1.y"
	{
	checkVar(yystack.l_mark[-3].lexeme);
	yyval.Node = (struct Node*)malloc(sizeof(struct Node));
	strcpy(yyval.Node->str,yystack.l_mark[-1].Node->str);
	strcat(yyval.Node->str, "t");
	strcat(yyval.Node->str, get_label(t));
	strcat(yyval.Node->str, " = ");
	strcat(yyval.Node->str, yystack.l_mark[-3].lexeme);
	strcat(yyval.Node->str, "[");
	strcat(yyval.Node->str, "t");
	strcat(yyval.Node->str, get_label(yystack.l_mark[-1].Node->lexval));
	strcat(yyval.Node->str, "]");
	strcat(yyval.Node->str, "\n");
	yyval.Node->lexval = t;
	t++;
}
#line 2202 "y.tab.c"
break;
case 57:
#line 730 "prob1.y"
	{
	yyval.Node = (struct Node*)malloc(sizeof(struct Node));
	strcpy(yyval.Node->str, "t");
	strcat(yyval.Node->str, get_label(t));
	strcat(yyval.Node->str, " = ");
	strcat(yyval.Node->str,yystack.l_mark[0].lexeme);
	strcat(yyval.Node->str, "\n");
	yyval.Node->lexval = t;
	t++;
}
#line 2216 "y.tab.c"
break;
#line 2218 "y.tab.c"
    default:
        break;
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
        {
            fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[YYFINAL], yyval));
#endif
            fprintf(stderr, "shifting from state 0 to final state %d\n", YYFINAL);
        }
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yyloc;
#endif
        if (yychar < 0)
        {
#if YYBTYACC
            do {
            if (yylvp < yylve)
            {
                /* we're currently re-reading tokens */
                yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylloc = *yylpp++;
#endif
                yychar = *yylexp++;
                break;
            }
            if (yyps->save)
            {
                /* in trial mode; save scanner results for future parse attempts */
                if (yylvp == yylvlim)
                {   /* Enlarge lexical value queue */
                    size_t p = (size_t) (yylvp - yylvals);
                    size_t s = (size_t) (yylvlim - yylvals);

                    s += YYLVQUEUEGROWTH;
                    if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL)
                        goto yyenomem;
                    if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL)
                        goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL)
                        goto yyenomem;
#endif
                    yylvp   = yylve = yylvals + p;
                    yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp   = yylpe = yylpsns + p;
                    yylplim = yylpsns + s;
#endif
                    yylexp  = yylexemes + p;
                }
                *yylexp = (YYINT) YYLEX;
                *yylvp++ = yylval;
                yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                *yylpp++ = yylloc;
                yylpe++;
#endif
                yychar = *yylexp++;
                break;
            }
            /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
            yychar = YYLEX;
#if YYBTYACC
            } while (0);
#endif /* YYBTYACC */
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)\n",
                                YYDEBUGSTR, yydepth, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[yystate], yyval));
#endif
        fprintf(stderr, "shifting from state %d to state %d\n", *yystack.s_mark, yystate);
    }
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    *++yystack.p_mark = yyloc;
#endif
    goto yyloop;
#if YYBTYACC

    /* Reduction declares that this path is valid. Set yypath and do a full parse */
yyvalid:
    if (yypath) YYABORT;
    while (yyps->save)
    {
        YYParseState *save = yyps->save;
        yyps->save = save->save;
        save->save = yypath;
        yypath = save;
    }
#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%s[%d]: state %d, CONFLICT trial successful, backtracking to state %d, %d tokens\n",
                        YYDEBUGSTR, yydepth, yystate, yypath->state, (int)(yylvp - yylvals - yypath->lexeme));
#endif
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    yylvp          = yylvals + yypath->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yylpp          = yylpsns + yypath->lexeme;
#endif
    yylexp         = yylexemes + yypath->lexeme;
    yychar         = YYEMPTY;
    yystack.s_mark = yystack.s_base + (yypath->yystack.s_mark - yypath->yystack.s_base);
    memcpy (yystack.s_base, yypath->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
    yystack.l_mark = yystack.l_base + (yypath->yystack.l_mark - yypath->yystack.l_base);
    memcpy (yystack.l_base, yypath->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base + (yypath->yystack.p_mark - yypath->yystack.p_base);
    memcpy (yystack.p_base, yypath->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
    yystate        = yypath->state;
    goto yyloop;
#endif /* YYBTYACC */

yyoverflow:
    YYERROR_CALL("yacc stack overflow");
#if YYBTYACC
    goto yyabort_nomem;
yyenomem:
    YYERROR_CALL("memory exhausted");
yyabort_nomem:
#endif /* YYBTYACC */
    yyresult = 2;
    goto yyreturn;

yyabort:
    yyresult = 1;
    goto yyreturn;

yyaccept:
#if YYBTYACC
    if (yyps->save) goto yyvalid;
#endif /* YYBTYACC */
    yyresult = 0;

yyreturn:
#if defined(YYDESTRUCT_CALL)
    if (yychar != YYEOF && yychar != YYEMPTY)
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval, &yylloc);
#else
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */

    {
        YYSTYPE *pv;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYLTYPE *pp;

        for (pv = yystack.l_base, pp = yystack.p_base; pv <= yystack.l_mark; ++pv, ++pp)
             YYDESTRUCT_CALL("cleanup: discarding state",
                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv, pp);
#else
        for (pv = yystack.l_base; pv <= yystack.l_mark; ++pv)
             YYDESTRUCT_CALL("cleanup: discarding state",
                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
    }
#endif /* defined(YYDESTRUCT_CALL) */

#if YYBTYACC
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    while (yyps)
    {
        YYParseState *save = yyps;
        yyps = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
    while (yypath)
    {
        YYParseState *save = yypath;
        yypath = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
#endif /* YYBTYACC */
    yyfreestack(&yystack);
    return (yyresult);
}
