//lexical analyzer system 

#include <iostream>
#include <cctype>
#include <fstream>
#include <string>
#include <cctype>
#include <unordered_map>
using namespace std;

/* Global declarations */
/* Variables */
int charClass;
char lexeme[100];
char nextChar;
int lexLen;
int token;
int nextToken;
const int END_OF_FILE = EOF; // Using a named constant for EOF
std::ifstream file("source_code.txt");


/* Function declarations */
void addChar();
void getChar();
void getNonBlank();
int lex();
void lookup();

/* Character classes */
#define LETTER 0
#define DIGIT 1
#define UNKNOWN 99


/* Token codes */
#define INT_LIT 10
#define IDENT 11
#define ASSIGN_OP 20
#define ADD_OP 21
#define SUB_OP 22
#define MULT_OP 23
#define DIV_OP 24
#define LEFT_PAREN 25
#define RIGHT_PAREN 26


/* main driver */
int main() {
  
    /* Open the input data file and process its contents */
    
    if (!file) {
        cout << "ERROR - cannot open file" << endl;
        return 1;
    } else {
        getChar();
        do {
            lex();
        } while (nextToken != EOF);
    }
    file.close();
    return 0;
}


/* lookup - a function to lookup operators and parentheses
   and return the token */
int lookup(char ch) {
    switch (ch) {
        case '(':
            addChar();
            nextToken = LEFT_PAREN;
            break;
        case ')':
            addChar();
            nextToken = RIGHT_PAREN;
            break;
        case '+':
            addChar();
            nextToken = ADD_OP;
            break;
        case '-':
            addChar();
            nextToken = SUB_OP;
            break;
        case '*':
            addChar();
            nextToken = MULT_OP;
            break;
        case '/':
            addChar();
            nextToken = DIV_OP;
            break;
        default:
            nextToken = EOF;
            break;
    }
    return nextToken;
}

// Function to add nextChar to lexeme
void addChar() {
    if (lexLen <= 98) {
        lexeme[lexLen++] = nextChar;
        lexeme[lexLen] = 0;
    } else {
        std::cerr << "Error - lexeme is too long" << std::endl;
    }
}
void getChar() {
    if (file.get(nextChar)) { // Read next character from file
        if (std::isalpha(nextChar))
            charClass = LETTER;
        else if (std::isdigit(nextChar))
            charClass = DIGIT;
        else
            charClass = UNKNOWN;
    } else {
        charClass = EOF; // Set class to EOF when end of file is reached
    }
}
// Function to call getChar until it returns a non-whitespace character
void getNonBlank() {
    while (std::isspace(nextChar)) {
        getChar();
    }
}
// Lexical analyzer function
int lex() {
    lexLen = 0; // Reset lexeme
    getNonBlank();
    
    switch (charClass) {
        /* Parse identifiers */
        case LETTER:
            addChar();
            getChar();
            while (charClass == LETTER || charClass == DIGIT) {
                addChar();
                getChar();
            }
            nextToken = IDENT;
            break;

        /* Parse integer literals */
        case DIGIT:
            addChar();
            getChar();
            while (charClass == DIGIT) {
                addChar();
                getChar();
            }
            nextToken = INT_LIT;
            break;

        /* Parentheses and operators */
        case UNKNOWN:
            lookup(nextChar);
            getChar();
            break;

        /* EOF */
        case EOF:
            nextToken = EOF;
            lexeme[0] = 'E';
            lexeme[1] = 'O';
            lexeme[2] = 'F';
            lexeme[3] = 0;
            break;
    } /* End of switch */

    std::cout << "Next token is: " << nextToken 
              << ", Next lexeme is " << lexeme << std::endl;
    
    return nextToken;
} /* End of function lex */
