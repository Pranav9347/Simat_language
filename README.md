
# Simat Language Documentation

## Introduction
**Simat** is a language designed for simulating various types of automata, including finite state machines, pushdown automata, and Turing machines. Files in Simat have the `.simat` extension. This document provides an overview of the language syntax, tokens, and functions. Automata  are abstract models of machines that perform computations by moving through a series of states. Automata theory is the study of automata and the computational problems that can be solved using them. For more info about automatons, see [wikipedia](https://en.wikipedia.org/wiki/Automata_theory#:~:text=Automata%20theory%20is%20the%20study,input%20symbol%20as%20its%20arguments.)

## Aim
The primary aim of Simat is to simplify the representation, simulation, and operation of automata. It allows users to define states, transitions, and acceptance conditions in a user-friendly manner, enhancing the understanding of automata theory and its applications.

## Use Cases
Simat can be utilized in various scenarios, including:
- Educational purposes, such as using in automata theory in computer science courses, test-purposes(for verifying the automatons coded)
- Students can simulate and verify their automata designs.
- Research applications for prototyping and testing automata-related algorithms.
- Software development for applications that require finite state machines, such as parsers, lexical analyzers, and protocol analyzers.

## Advantages
Simat offers several advantages:
- **User-Friendly Interface:** Simplifies the definition and manipulation of automata.
- **Educational Tool:** Enhances understanding of automata concepts through practical application.
- **Extensibility:** Allows for easy addition of new features and automata types in future iterations.
- **Visualization:** Enables graphical representation of automata for better understanding.

## 1. Compiling
To compile a Simat file, use the following command:
```bash
simat filename.simat
```


## 2. Language Tokens
- **Keywords:** `Let, intersect, union, minus, string, regular_expression, DFA, NFA, PDA, NPDA, TM, NTM`
- **Identifier rules:** Same as C-language rules.
- **Delimiters:** `: ; ( ) { } ,`
- **Operators:** `+` (or), `*` (Kleene closure), `k+` (Kleene plus), `&&` (logical AND), `||` (logical OR), `!=` (NOT equal-to), `==` (equality check)
- **Constants:** String literals `"..."`

## 3. Syntax
### 3.1 Declaring Automata
Automata are defined with `Let` statements, specifying the type and attributes. For example:
```plaintext
Let <var_name> = DFA{
			alphabet: set of comma-separated alphabets enclosed in [];
			start: 1 start state (any letter);
			non_final: set of comma-separated non-final states enclosed in [];
			final: set of comma-separated final states enclosed in [];
			transitions: d(state, symbol) = state (comma-separated transitions) enclosed in []
			(mapping must be unique/deterministic);
		}
```
In code for example DFA accepting strings ending with '1':
```
	Let D1 = DFA{
		alphabet: ['0','1'];
		start: "q0";
		non_final: ["q0"];
		final: ["q1"];
		transitions: [d("q0",'0')="q0", d("q0",'1')="q1", d("q1",'0')="q0", d("q1",'1')="q1"];
	}
```
#### Examples
- **NFA:**
```plaintext
Let <var_name> = NFA{
				alphabet: set of comma-separated alphabets enclosed in [];
				start: 1 start state;
				non_final: set of non-final states enclosed in [];
				final: set of final states enclosed in [];
				transitions: d(state, symbol) = state (comma-separated transitions) enclosed in []
				(mapping can be non-deterministic);
			}
```
    
- **PDA:**
```plaintext
Let <var_name> = PDA{
				alphabet: set of comma-separated alphabets;
				Stack alphabet: set of stack alphabets;
				stack_symbol: 1 stack symbol (any letter);
				start: 1 start state (any letter);
				non_final: set of comma-separated non-final states;
				final: set of comma-separated final states;
				transitions: d(state, symbol) = state (comma-separated transitions) enclosed in [];
			}
```

The order of listing properties in an automaton declaration does not matter.

### 3.2 Declaring Strings
```plaintext
Let s = string{}
Let s = string{a} //where a is a string var declared before
Let s = string{"hello world"}
```

### 3.3 Declaring Regular Expressions
```plaintext
Let RE = regex{}
Let RE = regex{"(a+b)*"}
Let RE = regex{m} //where m is a regex var declared before
```

### 3.4 Automaton Functions
Automata have various built-in functions:
- `D1.acceptance(string var)` - displays "Accepted" or "Rejected".
- `D1.minimize()` - minimizes the DFA.
- `D1.to_regex()` - converts DFA to regular expression.
- `RE.to_DFA()` and `N.to_DFA()` - converts regular expression or NFA to DFA.
- `RE.to_NFA()` - converts regular expression to NFA.
- `D1.display_graphically()` - displays automaton graphically.

### 3.5 Automaton Operations
Basic automaton operations include:
- `D1 intersection D2` - intersection of two DFAs.
- `D1 union D2` - union of two DFAs.
- `D1 minus D2` - difference between two DFAs.

### 3.6 Loops
Simat includes support for loops, enabling repeated execution over tokens. Example syntax:
```plaintext
for each token in line {
    D1.acceptance(token)
}
```

### 3.7 Conditionals
Conditional statements allow for branching logic based on acceptance results. Example syntax:
```plaintext
if (D1.acceptance(str) == true) {
    print("keyword")
} else {
    print("not a keyword")
}
```

### 3.8 Comments
Simat supports comments in C-style, allowing users to add inline explanations:
```plaintext
// This is a single-line comment
/*...*/ This a multi-line comment
```

### 3.9 Print Function
The `print()` function outputs strings, regular expressions, or resultant automatons. Example:
```plaintext
print("Automaton accepted the string")
print(RE)
```

### 3.10 Example Program: Lexical Analysis Simulation
Below is a sample Simat program demonstrating a lexical analysis simulation for C code:
```plaintext
Let line = string{"int a = 10;"}// example line of C code
// Split the line into tokens based on spaces
for each token in line {
    // Check if the token is a keyword using the Keyword DFA
    if (KeywordDFA.acceptance(token) == true) {
        print("{token} is a keyword")
    } else {
        print("{token} is not a keyword")
    }
    
    // Check if the token is an identifier using the Identifier DFA
    if (IdentifierDFA.acceptance(token) == true) {
        print("{token}is an identifier")
    } else {
        print("{token} is not an identifier")
    }
    
    // Additional checks for other token types can be added here
}
```

