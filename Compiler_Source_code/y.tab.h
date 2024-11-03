/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    LET = 258,                     /* LET  */
    DFA = 259,                     /* DFA  */
    NFA = 260,                     /* NFA  */
    PDA = 261,                     /* PDA  */
    NPDA = 262,                    /* NPDA  */
    TM = 263,                      /* TM  */
    ALPHABET = 264,                /* ALPHABET  */
    START = 265,                   /* START  */
    FINAL = 266,                   /* FINAL  */
    TRANSITIONS = 267,             /* TRANSITIONS  */
    NON_FINAL = 268,               /* NON_FINAL  */
    STRING = 269,                  /* STRING  */
    REGEX = 270,                   /* REGEX  */
    D = 271,                       /* D  */
    IF = 272,                      /* IF  */
    THEN = 273,                    /* THEN  */
    ELSE = 274,                    /* ELSE  */
    FOR = 275,                     /* FOR  */
    IDENTIFIER = 276,              /* IDENTIFIER  */
    CHAR_CONST = 277,              /* CHAR_CONST  */
    STRING_LITERAL = 278,          /* STRING_LITERAL  */
    DELIMITER = 279,               /* DELIMITER  */
    UNKNOWN = 280,                 /* UNKNOWN  */
    NEWLINE = 281,                 /* NEWLINE  */
    ASSIGN = 282,                  /* ASSIGN  */
    DOT = 283,                     /* DOT  */
    KLEENEPLUS = 284,              /* KLEENEPLUS  */
    KLEENECLOSURE = 285,           /* KLEENECLOSURE  */
    INTERSECTION = 286,            /* INTERSECTION  */
    UNION = 287,                   /* UNION  */
    MINUS = 288,                   /* MINUS  */
    AND = 289,                     /* AND  */
    OR = 290,                      /* OR  */
    EQUALTO = 291,                 /* EQUALTO  */
    COLON = 292,                   /* COLON  */
    NOTEQUALTO = 293,              /* NOTEQUALTO  */
    LBRACKET = 294,                /* LBRACKET  */
    RBRACKET = 295,                /* RBRACKET  */
    LBRACE = 296,                  /* LBRACE  */
    RBRACE = 297,                  /* RBRACE  */
    LPAREN = 298,                  /* LPAREN  */
    RPAREN = 299,                  /* RPAREN  */
    SEMICOLON = 300,               /* SEMICOLON  */
    COMMA = 301                    /* COMMA  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define LET 258
#define DFA 259
#define NFA 260
#define PDA 261
#define NPDA 262
#define TM 263
#define ALPHABET 264
#define START 265
#define FINAL 266
#define TRANSITIONS 267
#define NON_FINAL 268
#define STRING 269
#define REGEX 270
#define D 271
#define IF 272
#define THEN 273
#define ELSE 274
#define FOR 275
#define IDENTIFIER 276
#define CHAR_CONST 277
#define STRING_LITERAL 278
#define DELIMITER 279
#define UNKNOWN 280
#define NEWLINE 281
#define ASSIGN 282
#define DOT 283
#define KLEENEPLUS 284
#define KLEENECLOSURE 285
#define INTERSECTION 286
#define UNION 287
#define MINUS 288
#define AND 289
#define OR 290
#define EQUALTO 291
#define COLON 292
#define NOTEQUALTO 293
#define LBRACKET 294
#define RBRACKET 295
#define LBRACE 296
#define RBRACE 297
#define LPAREN 298
#define RPAREN 299
#define SEMICOLON 300
#define COMMA 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 74 "parser.y"

    char *str;           // For storing string values (e.g., identifiers, string literals)


#line 164 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
