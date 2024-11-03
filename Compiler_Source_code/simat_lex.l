%{
	#include <stdio.h>
	#include <string.h>
	//#define YYDEBUG 1
	#include "y.tab.h"

	int has_simat_extension(const char *filename) {
    const char *extension = ".simat";
    size_t len = strlen(filename);
    size_t ext_len = strlen(extension);
    
    // Check if the filename is at least as long as the extension
    if (len < ext_len) {
        return 0; // Invalid file type
    }
    
    // Compare the end of the filename with the expected extension
    return strcmp(filename + len - ext_len, extension) == 0;
}
	
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



int main(int argc, char *argv[]) 
{
	//yydebug = 1;
    if (argc < 2) {
        fprintf(stderr, "Usage: simat <input_file.simat>\n");
        return EXIT_FAILURE;
    }

    // Check if the input file has a .simat extension
    if (!has_simat_extension(argv[1])) {
        fprintf(stderr, "Invalid file type. Please provide a .simat file.\n");
        return EXIT_FAILURE;
    }

    // Your existing code to open the file and process it
    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    yyin = input_file;
    // Your parser logic goes here...

    
	yyparse(); //starts the parsing(lex+syntax+semantic analysis)
	fclose(input_file);
	return 0;
}
