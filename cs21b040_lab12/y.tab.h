#ifndef _yy_defines_h_
#define _yy_defines_h_

#define FOR 257
#define VAR 258
#define FLOAT_VAL 259
#define RELOP 260
#define INT_VAL 261
#define PLUS 262
#define MINUS 263
#define STAR 264
#define DIV 265
#define OR 266
#define AND 267
#define SEMI 268
#define LEFT 269
#define RIGHT 270
#define LCURL 271
#define RCURL 272
#define ASSIGN 273
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE {
    char lexeme[100];
    struct Node* node;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;

#endif /* _yy_defines_h_ */
