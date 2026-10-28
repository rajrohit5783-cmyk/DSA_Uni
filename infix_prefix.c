#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX 100

// ==========================================
// BLOCK 1: GLOBAL STACK OPERATIONS
// ==========================================
char STACK[MAX];
int top = -1;

void push(char item) {
    STACK[++top] = item;
}

char pop() {
    return STACK[top--];
}

char peek() {
    return STACK[top];
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// ==========================================
// BLOCK 2: INFIX TO POSTFIX CONVERSION (POLISH)
// ==========================================
void POLISH(char* Q, char* P) {
    int i = 0, j = 0;
    
    // Step 1: Push "(" onto STACK and add ")" to the end of Q
    push('(');
    int len = strlen(Q);
    Q[len] = ')';
    Q[len + 1] = '\0';

    // Step 2: Scan Q from left to right until STACK is empty
    while (top != -1) {
        char element = Q[i++];

        // Step 3: If an OPERAND is encountered, add it to P
        if (isalnum(element)) {
            P[j++] = element;
        }
        // Step 4: If a left parenthesis is encountered, push it
        else if (element == '(') {
            push(element);
        }
        // Step 5: If an operator is encountered
        else if (element == '+' || element == '-' || element == '*' || element == '/' || element == '^') {
            while (peek() != '(' && precedence(peek()) >= precedence(element)) {
                P[j++] = pop();
            }
            push(element);
        }
        // Step 6: If a right parenthesis is encountered
        else if (element == ')') {
            while (peek() != '(') {
                P[j++] = pop();
            }
            pop(); // Remove the left parenthesis '('
        }
    }
    P[j] = '\0'; // Terminate postfix string
}

// ==========================================
// BLOCK 3: POSTFIX EXPRESSION EVALUATION
// ==========================================
int evaluatePostfix(char* P) {
    int evalStack[MAX];
    int evalTop = -1;
    int i = 0;

    // Step 1: Add a Right Parenthesis ")" at the end of P [Sentinel]
    int len = strlen(P);
    P[len] = ')';
    P[len + 1] = '\0';

    // Step 2: Scan P from left to right until ")" is encountered
    while (P[i] != ')') {
        char element = P[i++];

        // Step 3: If an OPERAND is encountered, put it on STACK
        if (isdigit(element)) {
            evalStack[++evalTop] = element - '0'; // Convert char to actual integer
        }
        // Step 4: If an OPERATOR is encountered
        else {
            // i) Remove top 2 elements
            int A = evalStack[evalTop--]; // Top element
            int B = evalStack[evalTop--]; // Next to top element
            int result = 0;

            // ii) Evaluate B X A
            switch (element) {
                case '+': result = B + A; break;
                case '-': result = B - A; break;
                case '*': result = B * A; break;
                case '/': result = B / A; break;
                case '^': result = (int)pow(B, A); break;
            }
            // iii) Place result back on STACK
            evalStack[++evalTop] = result;
        }
    }
    // Step 5 & 6: Return the top value and exit
    return evalStack[evalTop];
}

// ==========================================
// BLOCK 4: MAIN EXECUTIVE PROGRAM
// ==========================================
int main() {
    char Q[MAX] = "5*(6+2)-8/4"; // Change this to try out expressions
    char P[MAX];

    printf("Input Infix Expression (Q): %s\n", Q);

    // Run Conversion Block
    POLISH(Q, P);
    printf("Resulting Postfix Notation (P): %s\n", P);

    // Run Evaluation Block
    int VALUE = evaluatePostfix(P);
    printf("Final Evaluation Value: %d\n", VALUE);

    return 0;
}