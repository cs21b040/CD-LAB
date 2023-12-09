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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 68 "prob1.y"
typedef union YYSTYPE {
	int val;
	float fval;
	char lexeme[100];
	struct Node* Node;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 103 "y.tab.c"

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
#define INT 281
#define FLOAT 282
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    7,    7,    8,    8,    8,    8,    8,    8,    2,
    2,   14,   14,   14,    1,   13,   13,   13,    3,    9,
    9,    9,   10,   10,   10,   11,   11,   11,   11,   11,
   11,    6,    6,    6,    6,   12,    4,    4,    5,    5,
    5,
};
static const YYINT yylen[] = {                            2,
    1,    2,    1,    4,    2,   11,    7,    7,    7,    2,
    0,    4,    6,    3,    1,    3,    3,    1,    3,    3,
    3,    1,    3,    3,    1,    2,    2,    2,    2,    2,
    1,    2,    2,    2,    2,    1,    3,    1,    1,    1,
    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    1,    0,
    0,    0,   36,   33,   35,    0,    0,    0,    5,    2,
   34,   32,    0,    0,    0,    0,    0,   41,   40,   31,
   38,    0,    0,   25,    0,   18,    0,    0,    0,    0,
    0,   29,   28,   39,   26,    0,    4,    0,    0,    0,
    0,   30,   27,    0,    0,    0,    0,    0,    0,   37,
    0,    0,   23,   24,    0,    0,   17,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    7,    0,    0,
    9,   10,    0,    0,   14,    0,    0,    0,    0,    6,
   13,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {                           0,
  260,  261,  262,  269,  275,  276,  284,  290,  291,  292,
  296,  258,  260,  296,  296,  267,  267,  267,  257,  291,
  261,  262,  260,  261,  262,  264,  267,  281,  282,  288,
  289,  293,  294,  295,  296,  287,  293,  297,  297,  285,
  293,  296,  296,  260,  288,  293,  257,  263,  264,  265,
  266,  261,  262,  259,  268,  273,  274,  268,  268,  268,
  294,  294,  295,  295,  293,  271,  297,  297,  271,  271,
  291,  291,  277,  278,  286,  298,  272,  272,  293,  279,
  272,  286,  270,  279,  291,  271,  291,  291,  280,  272,
  257,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {                          7,
   40,   75,   36,   30,   31,    8,    9,   10,   37,   33,
   34,   35,   38,   76,
};
static const YYINT yysindex[] = {                      -151,
 -234, -229, -229, -214, -198, -186,    0, -224,    0, -151,
 -255, -239,    0,    0,    0, -239, -239, -239,    0,    0,
    0,    0,    0, -229, -229, -216, -239,    0,    0,    0,
    0, -209, -149,    0, -156,    0, -244, -257, -211, -228,
 -141,    0,    0,    0,    0, -170,    0, -239, -239, -239,
 -239,    0,    0, -239, -213, -239, -239, -188, -171,    0,
 -149, -149,    0,    0, -141, -151,    0, -161, -151, -150,
 -212, -146, -239, -143, -139, -150, -133,    0, -250, -151,
    0,    0, -131, -151,    0, -151, -142, -130, -118,    0,
    0,
};
static const YYINT yyrindex[] = {                         0,
 -132,    0,    0,    0,    0,    0,    0,    0,    0,    8,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -227,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -184,    0,    0,    0,    0,    0,    0,    0,
 -127,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -172, -160,    0,    0, -196,    0,    0, -207,    0, -129,
    0,    0,    0,    0,    0, -129,    1,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -157,    0,    0,    0,
    0,
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
    0,
};
#endif
static const YYINT yygindex[] = {                         0,
    0,   68,    0,  119,    0,    0,  -10,    0,   -9,   83,
   84,    2,   -7,    0,
};
#define YYTABLESIZE 288
static const YYINT yytable[] = {                         20,
    8,   11,   32,   14,   15,   21,   22,    3,   41,   39,
   55,   11,   48,   49,   54,   56,   57,   46,   48,   49,
   23,   24,   25,   12,   26,   42,   43,   27,   84,   39,
   13,   39,   19,   36,   36,   39,   39,   39,   39,   59,
   39,   28,   29,   44,   65,   39,   39,   47,   67,   68,
   27,   39,   16,   48,   49,   71,   58,   66,   72,   77,
   16,   56,   57,   79,   28,   29,   16,   11,   17,   85,
   11,   19,   22,   87,   22,   88,   19,   19,   22,   22,
   18,   11,   69,   22,   20,   11,   20,   11,   22,   22,
   20,   20,   48,   49,   22,   20,   21,   60,   21,   70,
   20,   20,   21,   21,   52,   53,   20,   21,    1,    2,
    3,   56,   21,   21,   12,   50,   51,    4,   21,   12,
   12,   48,   49,    5,    6,   78,   73,   74,   36,   36,
   61,   62,   81,   63,   64,   80,   83,   89,   91,   86,
   15,   90,   11,   82,   45,    0,    0,    0,    0,    0,
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
    8,    8,    8,    0,    0,    0,    0,    0,    0,    8,
    0,    0,    8,    0,    0,    8,    8,    8,    8,    3,
    8,    0,    0,    0,    3,    3,    0,    3,
};
static const YYINT yycheck[] = {                         10,
    0,    0,   12,    2,    3,  261,  262,    0,   18,   17,
  268,   10,  263,  264,  259,  273,  274,   27,  263,  264,
  260,  261,  262,  258,  264,   24,   25,  267,  279,  257,
  260,  259,  257,  261,  262,  263,  264,  265,  266,  268,
  268,  281,  282,  260,   54,  273,  274,  257,   56,   57,
  267,  279,  267,  263,  264,   66,  268,  271,   69,  272,
  268,  273,  274,   73,  281,  282,  274,   66,  267,   80,
   69,  268,  257,   84,  259,   86,  273,  274,  263,  264,
  267,   80,  271,  268,  257,   84,  259,   86,  273,  274,
  263,  264,  263,  264,  279,  268,  257,  268,  259,  271,
  273,  274,  263,  264,  261,  262,  279,  268,  260,  261,
  262,  273,  273,  274,  272,  265,  266,  269,  279,  277,
  278,  263,  264,  275,  276,  272,  277,  278,  261,  262,
   48,   49,  272,   50,   51,  279,  270,  280,  257,  271,
  268,  272,  272,   76,   26,   -1,   -1,   -1,   -1,   -1,
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
  260,  261,  262,   -1,   -1,   -1,   -1,   -1,   -1,  269,
   -1,   -1,  272,   -1,   -1,  275,  276,  277,  278,  272,
  280,   -1,   -1,   -1,  277,  278,   -1,  280,
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
   -1,   -1,   -1,   -1,   -1,   -1,   -1,
};
#endif
#define YYFINAL 7
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 282
#define YYUNDFTOKEN 299
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
"RCURL","AND","OR","WHILE","SWITCH","CASE","DEFAULT","COLON","BREAK","INT",
"FLOAT","$accept","START","JEXPR","CASES","B","R","ID","UNARY","STLIST","STMT",
"E","T","F","VARTEMP","BLIST","CASEBLK","illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : START",
"START : STLIST",
"STLIST : STMT STLIST",
"STLIST : STMT",
"STMT : VAR ASSIGN E SEMI",
"STMT : UNARY SEMI",
"STMT : IF LPAREN BLIST RPAREN LCURL STLIST RCURL ELSE LCURL STLIST RCURL",
"STMT : WHILE LPAREN BLIST RPAREN LCURL STLIST RCURL",
"STMT : IF LPAREN BLIST RPAREN LCURL STLIST RCURL",
"STMT : SWITCH LPAREN JEXPR RPAREN LCURL CASES RCURL",
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
"VARTEMP : VAR",
"R : LPAREN E RPAREN",
"R : ID",
"ID : VAR",
"ID : FLOAT",
"ID : INT",

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
#line 563 "prob1.y"

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
	initialize(&st);
	initialize(&stOut);
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
#line 587 "y.tab.c"

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
#line 83 "prob1.y"
	{	
	yyval.Node = (struct Node*)malloc(sizeof(struct Node));
	strcpy(yyval.Node->str, yystack.l_mark[0].Node->str);
	printf("\n%s", yystack.l_mark[0].Node->str);
}
#line 1264 "y.tab.c"
break;
case 2:
#line 89 "prob1.y"
	{
	yyval.Node = (struct Node*)malloc(sizeof(struct Node));
	strcpy(yyval.Node->str, yystack.l_mark[-1].Node->str);
	strcat(yyval.Node->str, "\n");
	strcat(yyval.Node->str, yystack.l_mark[0].Node->str);
}
#line 1274 "y.tab.c"
break;
case 3:
#line 95 "prob1.y"
	{
	strcpy(yyval.Node->str, yystack.l_mark[0].Node->str);
}
#line 1281 "y.tab.c"
break;
case 4:
#line 98 "prob1.y"
	{
		yyval.Node = (struct Node*)malloc(sizeof(struct Node));
		strcpy(yyval.Node->str, yystack.l_mark[-1].Node->str);
		strcat(yyval.Node->str, yystack.l_mark[-3].lexeme);
		strcat(yyval.Node->str, " = ");
		strcat(yyval.Node->str, "t");
		strcat(yyval.Node->str, get_label(yystack.l_mark[-1].Node->lexval));
		strcat(yyval.Node->str, "\n");
}
#line 1294 "y.tab.c"
break;
case 5:
#line 107 "prob1.y"
	{
		strcpy(yyval.Node->str, yystack.l_mark[-1].Node->str);
}
#line 1301 "y.tab.c"
break;
case 6:
#line 110 "prob1.y"
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
#line 1330 "y.tab.c"
break;
case 7:
#line 135 "prob1.y"
	{
	yyval.Node = (struct Node*)malloc(sizeof(struct Node));
	yyval.Node->begin=l;
	l++;
	strcat(yyval.Node->str,"L");
	strcat(yyval.Node->str,get_label(yyval.Node->begin));
	strcat(yyval.Node->str,":\n");
	strcat(yyval.Node->str,yystack.l_mark[-4].Node->str);
	for(int i=0;i<sizeof(yystack.l_mark[-4].Node->TrueList)/sizeof(int);i++){
		if(yystack.l_mark[-4].Node->TrueList[i]==-1) break;
		strcat(yyval.Node->str,"L");
		strcat(yyval.Node->str,get_label(yystack.l_mark[-4].Node->TrueList[i]));
		strcat(yyval.Node->str,": \n");
	}
	strcat(yyval.Node->str,yystack.l_mark[-1].Node->str);
	strcat(yyval.Node->str," goto L");
	strcat(yyval.Node->str,get_label(yyval.Node->begin));
	strcat(yyval.Node->str,"\n");
	for(int i=0;i<sizeof(yystack.l_mark[-4].Node->FalseList)/sizeof(int);i++){
		if(yystack.l_mark[-4].Node->FalseList[i]==-1) break;
		strcat(yyval.Node->str,"L");
		strcat(yyval.Node->str,get_label(yystack.l_mark[-4].Node->FalseList[i]));
		strcat(yyval.Node->str,": \n");
	}
}
#line 1359 "y.tab.c"
break;
case 8:
#line 160 "prob1.y"
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
#line 1381 "y.tab.c"
break;
case 9:
#line 178 "prob1.y"
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
#line 1400 "y.tab.c"
break;
case 10:
#line 193 "prob1.y"
	{
	yyval.Node=(struct Node*)malloc(sizeof(struct Node));
	strcpy(yyval.Node->str,yystack.l_mark[-1].Node->str);
	strcat(yyval.Node->str,"L");
	strcat(yyval.Node->str,get_label(yystack.l_mark[-1].Node->False));
	strcat(yyval.Node->str,":\n");
	strcat(yyval.Node->str,yystack.l_mark[0].Node->str);
}
#line 1412 "y.tab.c"
break;
case 11:
#line 201 "prob1.y"
	{
	yyval.Node=(struct Node*)malloc(sizeof(struct Node));
	strcpy(yyval.Node->str,"");
}
#line 1420 "y.tab.c"
break;
case 12:
#line 205 "prob1.y"
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
#line 1439 "y.tab.c"
break;
case 13:
#line 220 "prob1.y"
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
#line 1466 "y.tab.c"
break;
case 14:
#line 243 "prob1.y"
	{
yyval.Node=(struct Node*)malloc(sizeof(struct Node));
strcpy(yyval.Node->str,yystack.l_mark[0].Node->str);
strcat(yyval.Node->str,"\n");
}
#line 1475 "y.tab.c"
break;
case 15:
#line 248 "prob1.y"
	{
	yyval.Node = (struct Node*)malloc(sizeof(struct Node));
	strcpy(yyval.Node->str, yystack.l_mark[0].Node->str);
	yyval.Node->lexval = yystack.l_mark[0].Node->lexval;
	push(&st,yystack.l_mark[0].Node->lexval);
}
#line 1485 "y.tab.c"
break;
case 16:
#line 254 "prob1.y"
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
#line 1516 "y.tab.c"
break;
case 17:
#line 281 "prob1.y"
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
#line 1543 "y.tab.c"
break;
case 18:
#line 304 "prob1.y"
	{
	yyval.Node = yystack.l_mark[0].Node;
}
#line 1550 "y.tab.c"
break;
case 19:
#line 307 "prob1.y"
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
#line 1582 "y.tab.c"
break;
case 20:
#line 335 "prob1.y"
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
#line 1600 "y.tab.c"
break;
case 21:
#line 349 "prob1.y"
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
#line 1618 "y.tab.c"
break;
case 22:
#line 363 "prob1.y"
	{
	strcpy(yyval.Node->str, yystack.l_mark[0].Node->str);
}
#line 1625 "y.tab.c"
break;
case 23:
#line 366 "prob1.y"
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
#line 1643 "y.tab.c"
break;
case 24:
#line 380 "prob1.y"
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
#line 1661 "y.tab.c"
break;
case 25:
#line 394 "prob1.y"
	{
	strcpy(yyval.Node->str, yystack.l_mark[0].Node->str);
}
#line 1668 "y.tab.c"
break;
case 26:
#line 397 "prob1.y"
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
#line 1683 "y.tab.c"
break;
case 27:
#line 408 "prob1.y"
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
#line 1700 "y.tab.c"
break;
case 28:
#line 421 "prob1.y"
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
#line 1717 "y.tab.c"
break;
case 29:
#line 434 "prob1.y"
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
#line 1734 "y.tab.c"
break;
case 30:
#line 447 "prob1.y"
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
#line 1751 "y.tab.c"
break;
case 31:
#line 460 "prob1.y"
	{
	strcpy(yyval.Node->str, yystack.l_mark[0].Node->str);
}
#line 1758 "y.tab.c"
break;
case 32:
#line 464 "prob1.y"
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
#line 1775 "y.tab.c"
break;
case 33:
#line 477 "prob1.y"
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
#line 1792 "y.tab.c"
break;
case 34:
#line 490 "prob1.y"
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
#line 1809 "y.tab.c"
break;
case 35:
#line 503 "prob1.y"
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
#line 1826 "y.tab.c"
break;
case 36:
#line 517 "prob1.y"
	{
	yyval.Node = (struct Node*)malloc(sizeof(struct Node));
	strcpy(yyval.Node->str, yystack.l_mark[0].lexeme);
	yyval.Node->lexval = t; 
	t++;			 
}
#line 1836 "y.tab.c"
break;
case 37:
#line 523 "prob1.y"
	{
	yyval.Node = (struct Node*)malloc(sizeof(struct Node));
	yyval.Node->lexval = yystack.l_mark[-1].Node->lexval;
	strcpy(yyval.Node->str, yystack.l_mark[-1].Node->str);
}
#line 1845 "y.tab.c"
break;
case 38:
#line 528 "prob1.y"
	{
	strcpy(yyval.Node->str, yystack.l_mark[0].Node->str);
}
#line 1852 "y.tab.c"
break;
case 39:
#line 531 "prob1.y"
	{
	yyval.Node = (struct Node*)malloc(sizeof(struct Node));
	strcpy(yyval.Node->str, "t");
	strcat(yyval.Node->str, get_label(t));
	strcat(yyval.Node->str, " = ");
	strcat(yyval.Node->str, yystack.l_mark[0].lexeme);
	strcat(yyval.Node->str, "\n");
	yyval.Node->lexval = t;				
	t++;
}
#line 1866 "y.tab.c"
break;
case 40:
#line 541 "prob1.y"
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
#line 1880 "y.tab.c"
break;
case 41:
#line 551 "prob1.y"
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
#line 1894 "y.tab.c"
break;
#line 1896 "y.tab.c"
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
