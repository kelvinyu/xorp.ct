#ifndef YYERRCODE
#define YYERRCODE 256
#endif

#define YY_BOOL 257
#define YY_INT 258
#define YY_UINT 259
#define YY_UINTRANGE 260
#define YY_STR 261
#define YY_ID 262
#define YY_IPV4 263
#define YY_IPV4RANGE 264
#define YY_IPV4NET 265
#define YY_IPV6 266
#define YY_IPV6RANGE 267
#define YY_IPV6NET 268
#define YY_NOT 269
#define YY_AND 270
#define YY_XOR 271
#define YY_OR 272
#define YY_HEAD 273
#define YY_CTR 274
#define YY_NE_INT 275
#define YY_EQ 276
#define YY_NE 277
#define YY_LE 278
#define YY_GT 279
#define YY_LT 280
#define YY_GE 281
#define YY_ADD 282
#define YY_SUB 283
#define YY_MUL 284
#define YY_SEMICOLON 285
#define YY_LPAR 286
#define YY_RPAR 287
#define YY_ASSIGN 288
#define YY_SET 289
#define YY_REGEX 290
#define YY_ACCEPT 291
#define YY_REJECT 292
#define YY_PROTOCOL 293
typedef union {
	char *c_str;
	Node *node;
} YYSTYPE;
extern YYSTYPE yy_policy_parserlval;
