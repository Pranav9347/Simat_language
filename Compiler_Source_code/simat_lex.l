%{
	#include <stdio.h>
	#include <string.h>
	//#define YYDEBUG 1
	#include "y.tab.h"
	
	
%}

%option noyywrap

%%

Let|let|LET                             { return LET; }
DFA|dfa                                 { return DFA; }
NFA|nfa                                 { return NFA; }
PDA|pda                                 { return PDA; }
NPDA|npda                               { return NPDA; }
TM|tm                                   { return TM; }
alphabet|Alphabet|ALPHABET              { return ALPHABET; }
start|Start|START                       { return START; }
for|For|FOR                             { return FOR; }
final|Final|FINAL                       { return FINAL; }
transitions|Transitions|TRANSITIONS     { return TRANSITIONS; }
non_final|Non_final|NON_FINAL           { return NON_FINAL; }
string|String|STRING                    { return STRING; }
regex|REGEX   							{ return REGEX; }
d|D                                     { return D; }
if|If|IF                                { return IF; }
then|Then|THEN                          { return THEN; }
else|Else|ELSE                          { return ELSE; }



"\'"[a-zA-Z0-9]*"\'"					{ yylval.str = strdup(yytext + 1); 
    									yylval.str[1] = '\0'; return CHAR_CONST; }



"\""[^"]*"\""							{ yylval.str = strndup(yytext + 1, strlen(yytext) - 2);  										return STRING_LITERAL; }



"["             { return LBRACKET; }      // Left square bracket
"]"             { return RBRACKET; }      // Right square bracket
"{"             { return LBRACE; }        // Left curly brace
"}"             { return RBRACE; }        // Right curly brace
"("             { return LPAREN; }        // Left parenthesis
")"             { return RPAREN; }        // Right parenthesis
";"             { return SEMICOLON; }     // Semicolon
","             { return COMMA; }          // Comma





"//".*									{ /* Ignore single-line comments */ }



"/*"([^*]|\*+[^*/])*\*+"/"				{ /* Ignore multi-line comments */ }



"="                 { return ASSIGN; }
"."					{ return DOT; }
"+"					{ return KLEENEPLUS; }
"*"					{ return KLEENECLOSURE; }
intersection|Intersection|INTERSECTION		{ return INTERSECTION; }
union|Union|UNION	{ return UNION; }				
minus|Minus|MINUS	{ return MINUS; }

"&&"				{ return AND; }
"||"				{ return OR; }
"=="				{ return EQUALTO; }
":"					{ return COLON; }
"!="				{ return NOTEQUALTO; }

[a-zA-Z_][a-zA-Z0-9_]* 					{  yylval.str = strdup(yytext); return IDENTIFIER; }


[ \t]+                               	{ /* Ignore whitespace */ }

[\n]									{ return NEWLINE; }

.                                       { return UNKNOWN; }


%%


int main()
{
	//yydebug = 1;
	yyparse(); //starts the parsing(lex+syntax+semantic analysis)
	return 0;
}
