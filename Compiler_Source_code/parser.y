  //C declarations:
%{
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

%}

  //Bison declarations:
%union {
    char *str;           // For storing string values (e.g., identifiers, string literals)

}

 // Token declarations matching the lex file
%token LET DFA NFA PDA NPDA TM ALPHABET START FINAL TRANSITIONS NON_FINAL STRING REGEX D IF THEN ELSE FOR
%token <str> IDENTIFIER CHAR_CONST STRING_LITERAL 
%token DELIMITER UNKNOWN NEWLINE
%token ASSIGN DOT KLEENEPLUS KLEENECLOSURE INTERSECTION UNION MINUS AND OR EQUALTO COLON NOTEQUALTO
%token LBRACKET RBRACKET LBRACE RBRACE LPAREN RPAREN SEMICOLON COMMA


%type <fsa> transitions_section
%type <str> start_section alphabet_section function_call


  //Grammar Rules with assocciated semantic actions:
%%

    input: input line | /*epsilon*/ {} ;

    line: statement NEWLINE {semantic_error_lineno++;} | NEWLINE {semantic_error_lineno++;} ;

    statement: declaration | function_call | expression /*| conditionals | loops*/;

    declaration: 
        //string declarations-
        //initalizing an empty string
        LET IDENTIFIER ASSIGN STRING LBRACE RBRACE {
        if (search_symbol($2) != NULL) {
            char error_msg[100];
            snprintf(error_msg, sizeof(error_msg), "Identifier '%s' already declared", $2);
            semantic_error(error_msg, semantic_error_lineno);
            return 1;
        } else {
            insert_symbol($2, "string", NULL,NULL);
        }} |

        //initalizing with a string literal
        LET IDENTIFIER ASSIGN STRING LBRACE STRING_LITERAL RBRACE {
        if (search_symbol($2) != NULL) {
            char error_msg[100];
            snprintf(error_msg, sizeof(error_msg), "Identifier '%s' already declared", $2);
            semantic_error(error_msg, semantic_error_lineno);
            return 1;
        } else {
            insert_symbol($2, "string", $6,NULL);
        }} |

        //initalizing with another string variable
        LET IDENTIFIER ASSIGN STRING LBRACE IDENTIFIER RBRACE {
        if (search_symbol($2) != NULL) {
            char error_msg[100];
            snprintf(error_msg, sizeof(error_msg), "Identifier '%s' already declared", $2);
            semantic_error(error_msg, semantic_error_lineno);
            return 1;
        } else {
            Symbol* existing_symbol = search_symbol($6);
            if (existing_symbol == NULL) {
                char error_msg[100];
                snprintf(error_msg, sizeof(error_msg), "Identifier '%s' not declared!", $6);
                semantic_error(error_msg, semantic_error_lineno);
                return 1;
                }
            else if(!type_check("string",existing_symbol->type , semantic_error_lineno)){
                return 1;
            }
             
            else {
                // Insert new identifier into the symbol table, copying the value from the existing symbol
                insert_symbol($2, "string", strdup(existing_symbol->str_val),NULL);
            }
        }} |


        //regular expression declarations:
        //initializing an empty regex:
        LET IDENTIFIER ASSIGN REGEX LBRACE RBRACE {
        if (search_symbol($2) != NULL) {
            char error_msg[100];
            snprintf(error_msg, sizeof(error_msg), "Identifier '%s' already declared", $2);
            semantic_error(error_msg, semantic_error_lineno);
            return 1;
        } else {
            insert_symbol($2, "Regex", NULL,NULL);
        }display_symbol_table();} |

        //initalizing with a string literal:
        LET IDENTIFIER ASSIGN REGEX LBRACE STRING_LITERAL RBRACE {
        if (search_symbol($2) != NULL) {
            char error_msg[100];
            snprintf(error_msg, sizeof(error_msg), "Identifier '%s' already declared", $2);
            semantic_error(error_msg, semantic_error_lineno);
            return 1;
        } else {
            insert_symbol($2, "Regex", $6,NULL);
        }} |

        //initalizing with another regex variable
        LET IDENTIFIER ASSIGN REGEX LBRACE IDENTIFIER RBRACE {
        if (search_symbol($2) != NULL) {
            char error_msg[100];
            snprintf(error_msg, sizeof(error_msg), "Identifier '%s' already declared", $2);
            semantic_error(error_msg, semantic_error_lineno);
            return 1;
        } else {
            Symbol* existing_symbol = search_symbol($6);
            if (existing_symbol == NULL) {
                char error_msg[100];
                snprintf(error_msg, sizeof(error_msg), "Identifier '%s' not declared!", $6);
                semantic_error(error_msg, semantic_error_lineno);
                return 1;
                }
            else if(!type_check("Regex",existing_symbol->type , semantic_error_lineno)){
                return 1;
            }
             
            else {
                // Insert new identifier into the symbol table, copying the value from the existing symbol
                insert_symbol($2, "Regex", strdup(existing_symbol->str_val),NULL);
            }
        }} |

        //Automaton declarations:

        //DFA declarations:
        //initializing an empty DFA:
        LET IDENTIFIER ASSIGN DFA LBRACE RBRACE {
        if (search_symbol($2) != NULL) {
            char error_msg[100];
            snprintf(error_msg, sizeof(error_msg), "Identifier '%s' already declared", $2);
            semantic_error(error_msg, semantic_error_lineno);
            return 1;
        } else {
            insert_symbol($2, "DFA", NULL,NULL);
        }} |

        //initalizing with DFA attributes lists:
        LET IDENTIFIER ASSIGN DFA LBRACE NEWLINE alphabet_section start_section non_final_section final_section transitions_section RBRACE {
        if (search_symbol($2) != NULL) {
            char error_msg[100];
            snprintf(error_msg, sizeof(error_msg), "Identifier '%s' already declared", $2);
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

            strcpy(fsa->start,$8);
            insert_symbol($2, "DFA", NULL, fsa);

        }} |

        // Initializing with another DFA variable:
        LET IDENTIFIER ASSIGN DFA LBRACE IDENTIFIER RBRACE {
        if (search_symbol($2) != NULL) {
            char error_msg[100];
            snprintf(error_msg, sizeof(error_msg), "Identifier '%s' already declared", $2);
            semantic_error(error_msg, semantic_error_lineno);
            return 1;
        } else {
        // Check if the referenced DFA exists in the symbol table
        Symbol* existing_symbol = search_symbol($6);
        if (existing_symbol == NULL) {
            char error_msg[100];
            snprintf(error_msg, sizeof(error_msg), "Identifier '%s' not declared!", $6);
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
            insert_symbol($2, "DFA", NULL, new_fsa);
        }
    }
} ;

    alphabet_section: ALPHABET COLON LBRACKET CHAR_CONST alpha_dash RBRACKET SEMICOLON NEWLINE{
            alphabets[append++]=$4[0];
            alphabets[append]='\0';
            $$ = strdup(alphabets);     //alphabet_section nonterminal also holds the set of all alphabets as a string
            append=0;
        }
    alpha_dash: alpha_dash COMMA CHAR_CONST  {
            if (append < 30 - 1)
                alphabets[append++] = $3[0];
            else printf("Append overflow!\n");
        } | /*epsilon*/ ;

    start_section: START COLON STRING_LITERAL SEMICOLON NEWLINE{
         $$ = strdup($3); //store the start state in start_section
        } ;

    non_final_section: NON_FINAL COLON LBRACKET STRING_LITERAL nonfinaldash RBRACKET SEMICOLON NEWLINE{
            strcpy(non_final[append++],$4);
            //$$ = append;//let the non_final_section store the number of non-final states(strings)
            n_nonfinal = append;
            append=0;
        } ;

    nonfinaldash: nonfinaldash COMMA STRING_LITERAL  {
            if (append < 50)
                strcpy(non_final[append++], $3);
            else printf("Append overflow!\n");

        } | /*epsilon*/ ;

    final_section: FINAL COLON LBRACKET STRING_LITERAL finaldash RBRACKET SEMICOLON NEWLINE{
            strcpy(final[append++],$4);
            //$$ = append;//let the final_section store the number of final states(strings)
            n_final = append;
            append=0;
        } ;

    finaldash: finaldash COMMA STRING_LITERAL {
            if (append < 50)
                strcpy(final[append++], $3);
            else printf("Append overflow!\n");
        } | /*epsilon*/ ;

    transitions_section: TRANSITIONS COLON LBRACKET transit_func trandash RBRACKET SEMICOLON NEWLINE{
            //by here all the states and transitions are recorded.
            
        } ;

    trandash: trandash COMMA transit_func {

        } | /*epsilon*/ ;

    transit_func: D LPAREN STRING_LITERAL COMMA CHAR_CONST RPAREN ASSIGN STRING_LITERAL {
            //combine nonfinal and final states into 1 array:
            create_states();
            transition_table[get_pos_state($3)][get_pos_alpha($5[0])] = $8;
        } ;        


   function_call:
   //print and acceptance functions:
    IDENTIFIER LPAREN IDENTIFIER RPAREN {
        Symbol* var = search_symbol($3);
        if(strcmp($1,"print")==0) //if print(FSA/RE/s)
        {
            if(!var) //if var not declared
            {
                char error_msg[100];
                snprintf(error_msg, sizeof(error_msg), "Variable '%s' not declared", $3);
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
        else if(strcmp($1,"acceptance")==0) //if acceptance(s)
        {
            if(strcmp(var->type,"string")!=0)
            {
                char error_msg[100];
                snprintf(error_msg, sizeof(error_msg), "Variable '%s' not declared", $3);
                semantic_error(error_msg, semantic_error_lineno);
                return 1;
            }
            else
            {
                strcpy(function_name,$1);
                $$ = var->str_val;/*function_call is being assigned the str_val of the parameter passed, caught in expression*/
            }
        }
    } |
    IDENTIFIER LPAREN STRING_LITERAL RPAREN{
    if(strcmp($1,"print")==0)
    {
        if($3[0]=='\\' && $3[1]=='n'&& $3[2]=='\0')
        {
            printf("\n");
        }
        else printf("%s",$3);
    }
    else if(strcmp($1,"acceptance")==0) //if acceptance(s)
    {
        strcpy(function_name,$1);
        $$ = $3;//function_call is being assigned the STRING_LITERAL passed, caught in expression
    }
    } ;


   expression: 
        IDENTIFIER DOT function_call{
        Symbol* var = search_symbol($1);
        if(!var) //if var not declared
        {
            char error_msg[100];
            snprintf(error_msg, sizeof(error_msg), "Variable '%s' not declared", $1);
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
                    is_accepted(var->fsa,$3);
            }
        }
   } ;
%%


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