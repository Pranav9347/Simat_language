 // Header:
 //section which will be added to the lex.yy.c code
%{
	#include <stdio.h>
	#include <string.h>

	void print_token(const char* token_type, const char* token_value){
		printf("Token type: %s, token: %s\n",token_type,token_value);
	}
%}

 // Definitions:
 // for single-source files or lexers without multi-file input handling do noyywrap
%option noyywrap


 // Rules:
 //Starts and ends with %%, rules represented as [RE] {Action(C code)}

%%

 //Keywords
Let|let|LET|DFA|dfa|NFA|nfa|PDA|pda|NPDA|npda|TM|tm|alphabet|Alphabet|ALPHABET|start|Start|START|for|For|FOR|final|Final|FINAL|transitions|Transitions|TRANSITIONS|non_final|Non_final|NON_FINAL|string|String|STRING|regular_expression|Regular_expression|REGULAR_EXPRESSION|d|D|if|If|IF|then|Then|THEN|else|Else|ELSE                           { print_token("Keyword",yytext); }


[a-zA-Z_][a-zA-Z0-9_]* 					{ print_token("Identifier", yytext); }



"\'"[a-zA-Z0-9]*"\'"					{ print_token("Char Constant", yytext); }



"\""[^'"]*"\""					{ print_token("String literal", yytext); }



\]|\[|\{|\}|\(|\)|\;|,|"|"|'|"\""		{ print_token("Delimiter", yytext); }



"//".*									{ /* Ignore single-line comments */ }



"/*"([^*]|\*+[^*/])*\*+"/"				{ /* Ignore multi-line comments */ }



\.|\+|\*|intersection|Intersection|INTERSECTION|union|Union|UNION|minus|Minus|MINUS|"&&"|"||"|=|==|:|!=	{ print_token("Operator", yytext); }


[ \t\n]+                               	{ /* Ignore whitespace */ }


.                                       { print_token("Unknown", yytext); }


%%


int main()
{
	yylex(); //starts the lexical analysis
	return 0;
}