/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "parser.y"

	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>

	#define TABLE_SIZE 100  // Size of the hash table

    int yyerror(const char *msg);  // Error function
    int semantic_error_lineno=0;
    extern int yylex(); //lex token generator function
    extern char* yytext;

char alphabets[30];//set of all alphabets string
int n_nonfinal=0;
char non_final[50][25];
int n_final=0;
char final[50][25];
int n_states=0;
char states[100][25];//union of final and non-final states
char *transition_table[100][30]; // Transition table

char function_name[30];

 //create a struct of DFA to associate it with DFA's
typedef struct //struct to hold both NFA and DFA
{
    int determinism; //1:DFA/0:NFA
    char alphabets[30];
    char start[20];
    int n_nonfinal;
    char non_final[50][25];
    int n_final;
    char final[50][25];
    int n_states;
    char states[100][25];
    char *transition_table[100][30];
}FSA;

// Define the symbol structure
typedef struct Symbol {
    char *name;
    char *type;
    char *str_val;
    FSA *fsa;
    struct Symbol *next;
} Symbol;

int append=0; //to append alphabets into array
Symbol *symbol_table[TABLE_SIZE];

 //function declarations for the construction of transition table:
 void create_states();
int get_pos_state(char* state);
int get_pos_alpha(char alpha);

 // Function declarations for symbol table management
    unsigned int hash(const char *name);
    Symbol *create_symbol(const char *name, const char *type, char* value, FSA *fsa);
    void insert_symbol(const char *name, const char *type, char* value, FSA *fsa);
    Symbol *search_symbol(const char *name);
    void display_symbol_table();

    void display_fsa_details(Symbol *current);
    void is_accepted(FSA *fsa, char *input);

    // Function declarations for error handling and type checking
    void semantic_error(const char *msg, int line);
    int type_check(const char* expected, const char* actual, int line);


#line 142 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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


#line 292 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_LET = 3,                        /* LET  */
  YYSYMBOL_DFA = 4,                        /* DFA  */
  YYSYMBOL_NFA = 5,                        /* NFA  */
  YYSYMBOL_PDA = 6,                        /* PDA  */
  YYSYMBOL_NPDA = 7,                       /* NPDA  */
  YYSYMBOL_TM = 8,                         /* TM  */
  YYSYMBOL_ALPHABET = 9,                   /* ALPHABET  */
  YYSYMBOL_START = 10,                     /* START  */
  YYSYMBOL_FINAL = 11,                     /* FINAL  */
  YYSYMBOL_TRANSITIONS = 12,               /* TRANSITIONS  */
  YYSYMBOL_NON_FINAL = 13,                 /* NON_FINAL  */
  YYSYMBOL_STRING = 14,                    /* STRING  */
  YYSYMBOL_REGEX = 15,                     /* REGEX  */
  YYSYMBOL_D = 16,                         /* D  */
  YYSYMBOL_IF = 17,                        /* IF  */
  YYSYMBOL_THEN = 18,                      /* THEN  */
  YYSYMBOL_ELSE = 19,                      /* ELSE  */
  YYSYMBOL_FOR = 20,                       /* FOR  */
  YYSYMBOL_IDENTIFIER = 21,                /* IDENTIFIER  */
  YYSYMBOL_CHAR_CONST = 22,                /* CHAR_CONST  */
  YYSYMBOL_STRING_LITERAL = 23,            /* STRING_LITERAL  */
  YYSYMBOL_DELIMITER = 24,                 /* DELIMITER  */
  YYSYMBOL_UNKNOWN = 25,                   /* UNKNOWN  */
  YYSYMBOL_NEWLINE = 26,                   /* NEWLINE  */
  YYSYMBOL_ASSIGN = 27,                    /* ASSIGN  */
  YYSYMBOL_DOT = 28,                       /* DOT  */
  YYSYMBOL_KLEENEPLUS = 29,                /* KLEENEPLUS  */
  YYSYMBOL_KLEENECLOSURE = 30,             /* KLEENECLOSURE  */
  YYSYMBOL_INTERSECTION = 31,              /* INTERSECTION  */
  YYSYMBOL_UNION = 32,                     /* UNION  */
  YYSYMBOL_MINUS = 33,                     /* MINUS  */
  YYSYMBOL_AND = 34,                       /* AND  */
  YYSYMBOL_OR = 35,                        /* OR  */
  YYSYMBOL_EQUALTO = 36,                   /* EQUALTO  */
  YYSYMBOL_COLON = 37,                     /* COLON  */
  YYSYMBOL_NOTEQUALTO = 38,                /* NOTEQUALTO  */
  YYSYMBOL_LBRACKET = 39,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 40,                  /* RBRACKET  */
  YYSYMBOL_LBRACE = 41,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 42,                    /* RBRACE  */
  YYSYMBOL_LPAREN = 43,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 44,                    /* RPAREN  */
  YYSYMBOL_SEMICOLON = 45,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 46,                     /* COMMA  */
  YYSYMBOL_YYACCEPT = 47,                  /* $accept  */
  YYSYMBOL_input = 48,                     /* input  */
  YYSYMBOL_line = 49,                      /* line  */
  YYSYMBOL_statement = 50,                 /* statement  */
  YYSYMBOL_declaration = 51,               /* declaration  */
  YYSYMBOL_alphabet_section = 52,          /* alphabet_section  */
  YYSYMBOL_alpha_dash = 53,                /* alpha_dash  */
  YYSYMBOL_start_section = 54,             /* start_section  */
  YYSYMBOL_non_final_section = 55,         /* non_final_section  */
  YYSYMBOL_nonfinaldash = 56,              /* nonfinaldash  */
  YYSYMBOL_final_section = 57,             /* final_section  */
  YYSYMBOL_finaldash = 58,                 /* finaldash  */
  YYSYMBOL_transitions_section = 59,       /* transitions_section  */
  YYSYMBOL_trandash = 60,                  /* trandash  */
  YYSYMBOL_transit_func = 61,              /* transit_func  */
  YYSYMBOL_function_call = 62,             /* function_call  */
  YYSYMBOL_expression = 63                 /* expression  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   87

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  34
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  101

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   301


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    94,    94,    94,    96,    96,    98,    98,    98,   103,
     114,   125,   152,   163,   174,   202,   213,   260,   325,   331,
     335,   337,   341,   348,   353,   355,   362,   366,   368,   373,
     375,   377,   386,   425,   443
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "LET", "DFA", "NFA",
  "PDA", "NPDA", "TM", "ALPHABET", "START", "FINAL", "TRANSITIONS",
  "NON_FINAL", "STRING", "REGEX", "D", "IF", "THEN", "ELSE", "FOR",
  "IDENTIFIER", "CHAR_CONST", "STRING_LITERAL", "DELIMITER", "UNKNOWN",
  "NEWLINE", "ASSIGN", "DOT", "KLEENEPLUS", "KLEENECLOSURE",
  "INTERSECTION", "UNION", "MINUS", "AND", "OR", "EQUALTO", "COLON",
  "NOTEQUALTO", "LBRACKET", "RBRACKET", "LBRACE", "RBRACE", "LPAREN",
  "RPAREN", "SEMICOLON", "COMMA", "$accept", "input", "line", "statement",
  "declaration", "alphabet_section", "alpha_dash", "start_section",
  "non_final_section", "nonfinaldash", "final_section", "finaldash",
  "transitions_section", "trandash", "transit_func", "function_call",
  "expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-31)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -31,     0,   -31,    -8,   -23,   -31,   -31,   -11,   -31,   -31,
     -31,     2,     6,    -9,   -31,     4,   -10,   -31,   -12,    -7,
      -6,    -5,    -3,   -31,   -31,   -20,   -19,   -14,    -2,    25,
     -31,    -1,     1,   -31,     3,     5,   -31,   -31,     7,    29,
     -31,   -31,   -31,   -31,     9,    12,    33,    20,    27,    14,
      41,   -31,     8,    15,    18,    44,   -30,    31,    35,    21,
      22,    19,    17,    42,   -31,   -31,    40,    26,   -31,    43,
     -31,   -29,   -31,    50,   -31,    23,    47,   -16,    24,   -31,
      45,   -31,    28,    49,    51,   -15,   -31,    52,   -31,    30,
      32,    50,   -31,    53,    54,   -31,    37,   -31,    55,    56,
     -31
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     1,     0,     0,     5,     2,     0,     6,     7,
       8,     0,     0,     0,     4,     0,     0,    34,     0,     0,
       0,     0,     0,    32,    33,     0,     0,     0,     0,     0,
      15,     0,     0,     9,     0,     0,    12,    17,     0,     0,
      11,    10,    14,    13,     0,     0,     0,     0,     0,     0,
       0,    20,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    21,    24,     0,     0,    16,     0,
      19,     0,    27,     0,    18,     0,     0,     0,     0,    30,
       0,    23,     0,     0,     0,     0,    22,     0,    26,     0,
       0,     0,    25,     0,     0,    29,     0,    28,     0,     0,
      31
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -31,   -31,   -31,   -31,   -31,   -31,   -31,   -31,   -31,   -31,
     -31,   -31,   -31,   -31,    -4,    71,   -31
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     6,     7,     8,    39,    56,    46,    50,    71,
      55,    77,    61,    85,    79,     9,    10
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
       2,    28,    31,     3,    32,    12,    29,    34,    20,    35,
      62,    75,    18,    11,    19,    14,    63,    76,    21,    22,
      13,     4,    30,    33,    82,    90,     5,    16,    36,    15,
      83,    91,    23,    13,    38,    25,    26,    24,    27,    45,
      37,    40,    51,    41,    44,    42,    49,    43,    47,    48,
      52,    53,    54,    57,    58,    59,    60,    64,    65,    67,
      66,    68,    69,    72,    70,    73,    78,    84,    80,    74,
      81,    86,    88,    87,    89,    96,    93,    94,    92,   100,
      97,    98,    99,    17,     0,     0,     0,    95
};

static const yytype_int8 yycheck[] =
{
       0,    21,    21,     3,    23,    28,    26,    21,     4,    23,
      40,    40,    21,    21,    23,    26,    46,    46,    14,    15,
      43,    21,    42,    42,    40,    40,    26,    21,    42,    27,
      46,    46,    44,    43,     9,    41,    41,    44,    41,    10,
      42,    42,    22,    42,    37,    42,    13,    42,    39,    37,
      23,    37,    11,    45,    39,    37,    12,    26,    23,    37,
      39,    42,    45,    23,    22,    39,    16,    43,    45,    26,
      23,    26,    23,    45,    23,    22,    46,    45,    26,    23,
      26,    44,    27,    12,    -1,    -1,    -1,    91
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    48,     0,     3,    21,    26,    49,    50,    51,    62,
      63,    21,    28,    43,    26,    27,    21,    62,    21,    23,
       4,    14,    15,    44,    44,    41,    41,    41,    21,    26,
      42,    21,    23,    42,    21,    23,    42,    42,     9,    52,
      42,    42,    42,    42,    37,    10,    54,    39,    37,    13,
      55,    22,    23,    37,    11,    57,    53,    45,    39,    37,
      12,    59,    40,    46,    26,    23,    39,    37,    42,    45,
      22,    56,    23,    39,    26,    40,    46,    58,    16,    61,
      45,    23,    40,    46,    43,    60,    26,    45,    23,    23,
      40,    46,    26,    46,    45,    61,    22,    26,    44,    27,
      23
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    48,    49,    49,    50,    50,    50,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    52,    53,
      53,    54,    55,    56,    56,    57,    58,    58,    59,    60,
      60,    61,    62,    62,    63
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     1,     1,     1,     1,     6,
       7,     7,     6,     7,     7,     6,    12,     7,     8,     3,
       0,     5,     8,     3,     0,     8,     3,     0,     8,     3,
       0,     8,     4,     4,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 3: /* input: %empty  */
#line 94 "parser.y"
                                    {}
#line 1392 "y.tab.c"
    break;

  case 4: /* line: statement NEWLINE  */
#line 96 "parser.y"
                            {semantic_error_lineno++;}
#line 1398 "y.tab.c"
    break;

  case 5: /* line: NEWLINE  */
#line 96 "parser.y"
                                                                 {semantic_error_lineno++;}
#line 1404 "y.tab.c"
    break;

  case 9: /* declaration: LET IDENTIFIER ASSIGN STRING LBRACE RBRACE  */
#line 103 "parser.y"
                                                   {
        if (search_symbol((yyvsp[-4].str)) != NULL) {
            char error_msg[100];
            snprintf(error_msg, sizeof(error_msg), "Identifier '%s' already declared", (yyvsp[-4].str));
            semantic_error(error_msg, semantic_error_lineno);
            return 1;
        } else {
            insert_symbol((yyvsp[-4].str), "string", NULL,NULL);
        }}
#line 1418 "y.tab.c"
    break;

  case 10: /* declaration: LET IDENTIFIER ASSIGN STRING LBRACE STRING_LITERAL RBRACE  */
#line 114 "parser.y"
                                                                  {
        if (search_symbol((yyvsp[-5].str)) != NULL) {
            char error_msg[100];
            snprintf(error_msg, sizeof(error_msg), "Identifier '%s' already declared", (yyvsp[-5].str));
            semantic_error(error_msg, semantic_error_lineno);
            return 1;
        } else {
            insert_symbol((yyvsp[-5].str), "string", (yyvsp[-1].str),NULL);
        }}
#line 1432 "y.tab.c"
    break;

  case 11: /* declaration: LET IDENTIFIER ASSIGN STRING LBRACE IDENTIFIER RBRACE  */
#line 125 "parser.y"
                                                              {
        if (search_symbol((yyvsp[-5].str)) != NULL) {
            char error_msg[100];
            snprintf(error_msg, sizeof(error_msg), "Identifier '%s' already declared", (yyvsp[-5].str));
            semantic_error(error_msg, semantic_error_lineno);
            return 1;
        } else {
            Symbol* existing_symbol = search_symbol((yyvsp[-1].str));
            if (existing_symbol == NULL) {
                char error_msg[100];
                snprintf(error_msg, sizeof(error_msg), "Identifier '%s' not declared!", (yyvsp[-1].str));
                semantic_error(error_msg, semantic_error_lineno);
                return 1;
                }
            else if(!type_check("string",existing_symbol->type , semantic_error_lineno)){
                return 1;
            }
             
            else {
                // Insert new identifier into the symbol table, copying the value from the existing symbol
                insert_symbol((yyvsp[-5].str), "string", strdup(existing_symbol->str_val),NULL);
            }
        }}
#line 1460 "y.tab.c"
    break;

  case 12: /* declaration: LET IDENTIFIER ASSIGN REGEX LBRACE RBRACE  */
#line 152 "parser.y"
                                                  {
        if (search_symbol((yyvsp[-4].str)) != NULL) {
            char error_msg[100];
            snprintf(error_msg, sizeof(error_msg), "Identifier '%s' already declared", (yyvsp[-4].str));
            semantic_error(error_msg, semantic_error_lineno);
            return 1;
        } else {
            insert_symbol((yyvsp[-4].str), "Regex", NULL,NULL);
        }display_symbol_table();}
#line 1474 "y.tab.c"
    break;

  case 13: /* declaration: LET IDENTIFIER ASSIGN REGEX LBRACE STRING_LITERAL RBRACE  */
#line 163 "parser.y"
                                                                 {
        if (search_symbol((yyvsp[-5].str)) != NULL) {
            char error_msg[100];
            snprintf(error_msg, sizeof(error_msg), "Identifier '%s' already declared", (yyvsp[-5].str));
            semantic_error(error_msg, semantic_error_lineno);
            return 1;
        } else {
            insert_symbol((yyvsp[-5].str), "Regex", (yyvsp[-1].str),NULL);
        }}
#line 1488 "y.tab.c"
    break;

  case 14: /* declaration: LET IDENTIFIER ASSIGN REGEX LBRACE IDENTIFIER RBRACE  */
#line 174 "parser.y"
                                                             {
        if (search_symbol((yyvsp[-5].str)) != NULL) {
            char error_msg[100];
            snprintf(error_msg, sizeof(error_msg), "Identifier '%s' already declared", (yyvsp[-5].str));
            semantic_error(error_msg, semantic_error_lineno);
            return 1;
        } else {
            Symbol* existing_symbol = search_symbol((yyvsp[-1].str));
            if (existing_symbol == NULL) {
                char error_msg[100];
                snprintf(error_msg, sizeof(error_msg), "Identifier '%s' not declared!", (yyvsp[-1].str));
                semantic_error(error_msg, semantic_error_lineno);
                return 1;
                }
            else if(!type_check("Regex",existing_symbol->type , semantic_error_lineno)){
                return 1;
            }
             
            else {
                // Insert new identifier into the symbol table, copying the value from the existing symbol
                insert_symbol((yyvsp[-5].str), "Regex", strdup(existing_symbol->str_val),NULL);
            }
        }}
#line 1516 "y.tab.c"
    break;

  case 15: /* declaration: LET IDENTIFIER ASSIGN DFA LBRACE RBRACE  */
#line 202 "parser.y"
                                                {
        if (search_symbol((yyvsp[-4].str)) != NULL) {
            char error_msg[100];
            snprintf(error_msg, sizeof(error_msg), "Identifier '%s' already declared", (yyvsp[-4].str));
            semantic_error(error_msg, semantic_error_lineno);
            return 1;
        } else {
            insert_symbol((yyvsp[-4].str), "DFA", NULL,NULL);
        }}
#line 1530 "y.tab.c"
    break;

  case 16: /* declaration: LET IDENTIFIER ASSIGN DFA LBRACE NEWLINE alphabet_section start_section non_final_section final_section transitions_section RBRACE  */
#line 213 "parser.y"
                                                                                                                                           {
        if (search_symbol((yyvsp[-10].str)) != NULL) {
            char error_msg[100];
            snprintf(error_msg, sizeof(error_msg), "Identifier '%s' already declared", (yyvsp[-10].str));
            semantic_error(error_msg, semantic_error_lineno);
            return 1;
        } else {
            FSA *fsa = (FSA *)malloc(sizeof(FSA));
            fsa->determinism = 1;
            //*fsa = $10; doesnt work as deep copy is required
            // Deep copy of fields
            strncpy(fsa->alphabets, alphabets, sizeof(fsa->alphabets)); // Assuming alphabets is a global string
            fsa->n_nonfinal = n_nonfinal;
            for (int i = 0; i < n_nonfinal; i++) {
                strcpy(fsa->non_final[i], non_final[i]); 
            }
            fsa->n_final = n_final;
            for (int i = 0; i < n_final; i++) {
                strcpy(fsa->final[i],final[i]); // Allocate and copy each final state
            }
            fsa->n_states = n_states;
            for (int i = 0; i < n_states; i++) {
                strcpy(fsa->states[i],states[i]); // Allocate and copy each state
            }
            
            // Deep copy transition table
            for (int i = 0; i < n_states; i++) {
                for (int j = 0; j < 30; j++) { // Adjust size as needed
                    if (transition_table[i][j] != NULL) {
                        // Allocate memory for each entry before copying
                        fsa->transition_table[i][j] = (char *)malloc(strlen(transition_table[i][j]) + 1);
                        
                        // Copy the string from existing_fsa to new_fsa
                        strcpy(fsa->transition_table[i][j], transition_table[i][j]);
                    } else {
                        // Set to NULL if the original entry is NULL
                        fsa->transition_table[i][j] = NULL;
                    }
                }
            }

            strcpy(fsa->start,(yyvsp[-4].str));
            insert_symbol((yyvsp[-10].str), "DFA", NULL, fsa);

        }}
#line 1580 "y.tab.c"
    break;

  case 17: /* declaration: LET IDENTIFIER ASSIGN DFA LBRACE IDENTIFIER RBRACE  */
#line 260 "parser.y"
                                                           {
        if (search_symbol((yyvsp[-5].str)) != NULL) {
            char error_msg[100];
            snprintf(error_msg, sizeof(error_msg), "Identifier '%s' already declared", (yyvsp[-5].str));
            semantic_error(error_msg, semantic_error_lineno);
            return 1;
        } else {
        // Check if the referenced DFA exists in the symbol table
        Symbol* existing_symbol = search_symbol((yyvsp[-1].str));
        if (existing_symbol == NULL) {
            char error_msg[100];
            snprintf(error_msg, sizeof(error_msg), "Identifier '%s' not declared!", (yyvsp[-1].str));
            semantic_error(error_msg, semantic_error_lineno);
            return 1;
        } else if (!type_check("DFA", existing_symbol->type, semantic_error_lineno)) {
            return 1; // Type mismatch
        } else {
            // Here you would need to perform a deep copy of the FSA structure
            FSA *existing_fsa = existing_symbol->fsa; // Assume existing_symbol has a pointer to the FSA

            // Allocate new FSA and copy over properties
            FSA *new_fsa = malloc(sizeof(FSA));
            if (new_fsa == NULL) {
                perror("Failed to allocate memory for new FSA");
                exit(1);
            }
            new_fsa->determinism = existing_fsa->determinism;
            strncpy(new_fsa->alphabets, existing_fsa->alphabets, sizeof(new_fsa->alphabets));
            new_fsa->n_nonfinal = existing_fsa->n_nonfinal;
            for (int i = 0; i < existing_fsa->n_nonfinal; i++) {
                strcpy(new_fsa->non_final[i],existing_fsa->non_final[i]);
            }
            new_fsa->n_final = existing_fsa->n_final;
            for (int i = 0; i < existing_fsa->n_final; i++) {
                strcpy(new_fsa->final[i],existing_fsa->final[i]);
            }
            new_fsa->n_states = existing_fsa->n_states;
            for (int i = 0; i < existing_fsa->n_states; i++) {
                strcpy(new_fsa->states[i],existing_fsa->states[i]);
            }

            // Deep copy transition table
            for (int i = 0; i < existing_fsa->n_states; i++) {
                for (int j = 0; j < 30; j++) { // Adjust size as needed
                    if (existing_fsa->transition_table[i][j] != NULL) {
                        // Allocate memory for each entry before copying
                        new_fsa->transition_table[i][j] = (char *)malloc(strlen(existing_fsa->transition_table[i][j]) + 1);
                        
                        // Copy the string from existing_fsa to new_fsa
                        strcpy(new_fsa->transition_table[i][j], existing_fsa->transition_table[i][j]);
                    } else {
                        // Set to NULL if the original entry is NULL
                        new_fsa->transition_table[i][j] = NULL;
                    }
                }
            }

            strcpy(new_fsa->start,existing_fsa->start); // Assuming start is a string
            
            // Insert new identifier into the symbol table with the copied FSA
            insert_symbol((yyvsp[-5].str), "DFA", NULL, new_fsa);
        }
    }
}
#line 1649 "y.tab.c"
    break;

  case 18: /* alphabet_section: ALPHABET COLON LBRACKET CHAR_CONST alpha_dash RBRACKET SEMICOLON NEWLINE  */
#line 325 "parser.y"
                                                                                              {
            alphabets[append++]=(yyvsp[-4].str)[0];
            alphabets[append]='\0';
            (yyval.str) = strdup(alphabets);     //alphabet_section nonterminal also holds the set of all alphabets as a string
            append=0;
        }
#line 1660 "y.tab.c"
    break;

  case 19: /* alpha_dash: alpha_dash COMMA CHAR_CONST  */
#line 331 "parser.y"
                                             {
            if (append < 30 - 1)
                alphabets[append++] = (yyvsp[0].str)[0];
            else printf("Append overflow!\n");
        }
#line 1670 "y.tab.c"
    break;

  case 21: /* start_section: START COLON STRING_LITERAL SEMICOLON NEWLINE  */
#line 337 "parser.y"
                                                               {
         (yyval.str) = strdup((yyvsp[-2].str)); //store the start state in start_section
        }
#line 1678 "y.tab.c"
    break;

  case 22: /* non_final_section: NON_FINAL COLON LBRACKET STRING_LITERAL nonfinaldash RBRACKET SEMICOLON NEWLINE  */
#line 341 "parser.y"
                                                                                                      {
            strcpy(non_final[append++],(yyvsp[-4].str));
            //$$ = append;//let the non_final_section store the number of non-final states(strings)
            n_nonfinal = append;
            append=0;
        }
#line 1689 "y.tab.c"
    break;

  case 23: /* nonfinaldash: nonfinaldash COMMA STRING_LITERAL  */
#line 348 "parser.y"
                                                     {
            if (append < 50)
                strcpy(non_final[append++], (yyvsp[0].str));
            else printf("Append overflow!\n");

        }
#line 1700 "y.tab.c"
    break;

  case 25: /* final_section: FINAL COLON LBRACKET STRING_LITERAL finaldash RBRACKET SEMICOLON NEWLINE  */
#line 355 "parser.y"
                                                                                           {
            strcpy(final[append++],(yyvsp[-4].str));
            //$$ = append;//let the final_section store the number of final states(strings)
            n_final = append;
            append=0;
        }
#line 1711 "y.tab.c"
    break;

  case 26: /* finaldash: finaldash COMMA STRING_LITERAL  */
#line 362 "parser.y"
                                              {
            if (append < 50)
                strcpy(final[append++], (yyvsp[0].str));
            else printf("Append overflow!\n");
        }
#line 1721 "y.tab.c"
    break;

  case 28: /* transitions_section: TRANSITIONS COLON LBRACKET transit_func trandash RBRACKET SEMICOLON NEWLINE  */
#line 368 "parser.y"
                                                                                                    {
            //by here all the states and transitions are recorded.
            
        }
#line 1730 "y.tab.c"
    break;

  case 29: /* trandash: trandash COMMA transit_func  */
#line 373 "parser.y"
                                          {

        }
#line 1738 "y.tab.c"
    break;

  case 31: /* transit_func: D LPAREN STRING_LITERAL COMMA CHAR_CONST RPAREN ASSIGN STRING_LITERAL  */
#line 377 "parser.y"
                                                                                        {
            //combine nonfinal and final states into 1 array:
            create_states();
            transition_table[get_pos_state((yyvsp[-5].str))][get_pos_alpha((yyvsp[-3].str)[0])] = (yyvsp[0].str);
        }
#line 1748 "y.tab.c"
    break;

  case 32: /* function_call: IDENTIFIER LPAREN IDENTIFIER RPAREN  */
#line 386 "parser.y"
                                        {
        Symbol* var = search_symbol((yyvsp[-1].str));
        if(strcmp((yyvsp[-3].str),"print")==0) //if print(FSA/RE/s)
        {
            if(!var) //if var not declared
            {
                char error_msg[100];
                snprintf(error_msg, sizeof(error_msg), "Variable '%s' not declared", (yyvsp[-1].str));
                semantic_error(error_msg, semantic_error_lineno);
                return 1;
            }
            else
            {
                if(strcmp(var->type,"string")==0) //s
                    printf("%s", var->str_val);
                else if(strcmp(var->type,"DFA")==0) //DFA
                {
                    display_fsa_details(var);
                }
                else if(strcmp(var->type,"Regex")==0)
                    printf("%s",var->str_val);
            }
        }
        else if(strcmp((yyvsp[-3].str),"acceptance")==0) //if acceptance(s)
        {
            if(strcmp(var->type,"string")!=0)
            {
                char error_msg[100];
                snprintf(error_msg, sizeof(error_msg), "Variable '%s' not declared", (yyvsp[-1].str));
                semantic_error(error_msg, semantic_error_lineno);
                return 1;
            }
            else
            {
                strcpy(function_name,(yyvsp[-3].str));
                (yyval.str) = var->str_val;/*function_call is being assigned the str_val of the parameter passed, caught in expression*/
            }
        }
    }
#line 1792 "y.tab.c"
    break;

  case 33: /* function_call: IDENTIFIER LPAREN STRING_LITERAL RPAREN  */
#line 425 "parser.y"
                                           {
    if(strcmp((yyvsp[-3].str),"print")==0)
    {
        if((yyvsp[-1].str)[0]=='\\' && (yyvsp[-1].str)[1]=='n'&& (yyvsp[-1].str)[2]=='\0')
        {
            printf("\n");
        }
        else printf("%s",(yyvsp[-1].str));
    }
    else if(strcmp((yyvsp[-3].str),"acceptance")==0) //if acceptance(s)
    {
        strcpy(function_name,(yyvsp[-3].str));
        (yyval.str) = (yyvsp[-1].str);//function_call is being assigned the STRING_LITERAL passed, caught in expression
    }
    }
#line 1812 "y.tab.c"
    break;

  case 34: /* expression: IDENTIFIER DOT function_call  */
#line 443 "parser.y"
                                    {
        Symbol* var = search_symbol((yyvsp[-2].str));
        if(!var) //if var not declared
        {
            char error_msg[100];
            snprintf(error_msg, sizeof(error_msg), "Variable '%s' not declared", (yyvsp[-2].str));
            semantic_error(error_msg, semantic_error_lineno);
            return 1;
        }
        else
        {
            if(strcmp("acceptance",function_name)==0)
            {
                if(strcmp(var->type,"DFA")!=0)
                {
                    char error_msg[100];
                    snprintf(error_msg, sizeof(error_msg), "Invalid variable type!");
                    semantic_error(error_msg, semantic_error_lineno);
                    return 1;
                }
                else
                    is_accepted(var->fsa,(yyvsp[0].str));
            }
        }
   }
#line 1842 "y.tab.c"
    break;


#line 1846 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 468 "parser.y"



  //Additional C code:

//Union of non_final and final states:
void create_states()
{
    n_states = n_final+n_nonfinal;
    for(int i=0; i<n_nonfinal; i++)
        strcpy(states[i],non_final[i]);
    for(int j=0; j<n_final; j++)
        strcpy(states[n_nonfinal+j],final[j]);
}

int get_pos_state(char* state)
{
    for(int i=0; i<n_states; i++)
        if(strcmp(states[i],state)==0)
            return i;
    return -1;//invalid state!
}

int get_pos_alpha(char alpha)
{
    int index=0;
    char x = alphabets[index];
    do
    {
        if(x == alpha)
            return index;
        x = alphabets[++index];
    }while(x!='\0');
    return -1;//invalid alphabet!
}

  // Hash function to map symbol names to hash table indices
unsigned int hash(const char *name) {
    unsigned long long int hash = 0;
    while (*name) {
        hash = (hash << 3) + *name++;
    }
    return hash % TABLE_SIZE;
}

// Create a new symbol
Symbol *create_symbol(const char *name, const char *type, char* value, FSA *fsa) {
    Symbol *new_symbol = (Symbol *)malloc(sizeof(Symbol));
    new_symbol->name = strdup(name);
    new_symbol->type = strdup(type);
    if (value != NULL)
        new_symbol->str_val = strdup(value);
    else
        new_symbol->str_val = NULL;
    new_symbol->fsa = fsa; // Set the FSA pointer
    new_symbol->next = NULL;
    return new_symbol;
}

// Insert a symbol into the symbol table
void insert_symbol(const char *name, const char *type, char* value, FSA *fsa) {
    unsigned int index = hash(name);
    Symbol *new_symbol = create_symbol(name, type, value, fsa); 

    // Insert at the beginning of the linked list at this index
    new_symbol->next = symbol_table[index];
    symbol_table[index] = new_symbol;
}

// Search for a symbol in the symbol table by name
Symbol *search_symbol(const char *name) {
    unsigned int index = hash(name);
    Symbol *current = symbol_table[index];

    // Traverse the linked list at this index
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;  // Symbol found
        }
        current = current->next;
    }
    return NULL;  // Symbol not found
}


void semantic_error(const char *msg, int line) {
    fprintf(stderr, "Semantic error at line %d: %s\n", line, msg);
}

int type_check(const char* expected, const char* actual, int line) {
    Symbol* sym = search_symbol(actual);
    if (sym && strcmp(sym->type, expected) == 0) {
        return 1;  // Types match
    } else {
        fprintf(stderr, "Type error at line %d: expected %s but got %s\n", line, expected, sym ? sym->type : "undefined");
        return 0;
    }
}

int yyerror(const char *msg) {
    fprintf(stderr, "Syntax error at line %d: %s at token:%s\n", semantic_error_lineno, msg, yytext);
    return 0;
}

void display_symbol_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (symbol_table[i] != NULL) {
            Symbol *current = symbol_table[i];
            printf("Index %d:\n", i);
            while (current != NULL) {
                printf("  Name: %s, Type: %s, Value: %s\n", current->name, current->type, current->str_val);
                
                // If there is an associated FSA, print its details
                if (current->fsa != NULL) {
                    display_fsa_details(current);
                }
                
                current = current->next;
            }
        }
    }
}

// Function to display FSA details
void display_fsa_details(Symbol *current) {
    if (current->fsa != NULL) {
        printf("    FSA Details:\n");
        (current->fsa->determinism == 1)?printf("    DFA\n"): (printf("    NFA\n"));
        printf("    Start State: %s\n", current->fsa->start);

        // Display Non-Final States
        printf("    Non-Final States: ");
        for (int j = 0; j < current->fsa->n_nonfinal; j++) {
            printf("%s", current->fsa->non_final[j]);
            if (j < current->fsa->n_nonfinal - 1) {
                printf(", "); // Comma separation
            }
        }
        printf("\n");

        // Display Final States
        printf("    Final States: ");
        for (int j = 0; j < current->fsa->n_final; j++) {
            printf("%s", current->fsa->final[j]);
            if (j < current->fsa->n_final - 1) {
                printf(", "); // Comma separation
            }
        }
        printf("\n");

        // Display the alphabets used
        printf("    Alphabets: ");
        for (int i = 0; i < strlen(current->fsa->alphabets); i++) {
            printf("%c", current->fsa->alphabets[i]);
            if (i < strlen(current->fsa->alphabets) - 1) {
                printf(", "); // Comma separation
            }
        }
        printf("\n");

        // Display Transition Table
        printf("    Transition Table:\n");
        printf("      +-----------------------+\n"); // Top border
        printf("      | States     ");
        for (int i = 0; i < strlen(current->fsa->alphabets); i++) {
            printf("| %c ", current->fsa->alphabets[i]); // Column headings as per alphabets
        }
        printf("|\n");
        printf("      +-----------------------+\n"); // Header separator

        // Print the transition table with state names and transitions
        for (int j = 0; j < current->fsa->n_states; j++) {
            printf("      | State %s: ", current->fsa->states[j]);
            for (int k = 0; k < strlen(current->fsa->alphabets); k++) {
                printf("| %s ", current->fsa->transition_table[j][k] != NULL ? current->fsa->transition_table[j][k] : "NULL");
            }
            printf("|\n");
        }
        printf("      +-----------------------+\n"); // Bottom border
    } else {
        printf("No FSA details available.\n");
    }
}

// Function to check if a string is accepted by the FSA (DFA/NFA)
void is_accepted(FSA *fsa, char *input) {
    // Start at the initial state
    char *current_state = fsa->start;

    // Iterate over the input string
    for (int i = 0; i < strlen(input); i++) {
        // Get the index of the input character in the alphabet
        int alphabet_index = -1;
        for (int j = 0; j < strlen(fsa->alphabets); j++) {
            if (fsa->alphabets[j] == input[i]) {
                alphabet_index = j;
                break;
            }
        }

        if (alphabet_index == -1) {
            printf("The string %s is rejected by the FSA (invalid alphabet character).\n", input);
            return;
        }

        // Get the index of the current state in the states array
        int state_index = -1;
        for (int j = 0; j < fsa->n_states; j++) {
            if (strcmp(fsa->states[j], current_state) == 0) {
                state_index = j;
                break;
            }
        }

        if (state_index == -1) {
            printf("The string %s is rejected by the FSA (invalid state).\n", input);
            return;
        }

        // Transition to the next state
        current_state = fsa->transition_table[state_index][alphabet_index];
        if (current_state == NULL) {
            printf("The string %s is rejected by the FSA (no transition found).\n", input);
            return;
        }
    }

    // Check if the final state is an accepting state
    int is_final = 0;
    for (int i = 0; i < fsa->n_final; i++) {
        if (strcmp(fsa->final[i], current_state) == 0) {
            is_final = 1;
            break;
        }
    }

    if (is_final) {
        printf("The string %s is accepted by the FSA.\n", input);
    } else {
        printf("The string %s is rejected by the FSA.\n", input);
    }
}
