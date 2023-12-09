#ifndef _yy_defines_h_
#define _yy_defines_h_

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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE {
	int val;
	float fval;
	char lexeme[100];
	struct Node* Node;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;

#endif /* _yy_defines_h_ */
