/*Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity*/
//Solution:
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int precedence(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    if(op == '^') return 3;
    return 0;
}

int main() {
    char infix[100], postfix[100];
    int k = 0;

    scanf("%s", infix);

    for(int i = 0; i < strlen(infix); i++) {

        if(isalnum(infix[i])) {
            postfix[k++] = infix[i];
        }

        else if(infix[i] == '(') {
            push(infix[i]);
        }

        else if(infix[i] == ')') {
            while(peek() != '(')
                postfix[k++] = pop();
            pop();
        }

        else {
            while(top != -1 && precedence(peek()) >= precedence(infix[i]))
                postfix[k++] = pop();

            push(infix[i]);
        }
    }

    while(top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';

    printf("%s", postfix);

    return 0;
}