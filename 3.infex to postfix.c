//shunting yard algoritmasi yardimiyle infex to postfix

#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void infixToPostfix(char* exp) {
    int i = 0;
    while (exp[i] != '\0') {
        char c = exp[i];
        if (isalnum(c)) {
            printf("%c", c);
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top != -1 && peek() != '(') {
                printf("%c", pop());
            }
            pop();
        } else if (isOperator(c)) {
            while (top != -1 && precedence(peek()) >= precedence(c)) {
                printf("%c", pop());
            }
            push(c);
        }
        i++;
    }
    while (top != -1) {
        printf("%c", pop());
    }
}

int main() {
    char exp[] = "A*(B+C)/D";
    infixToPostfix(exp);
    return 0;
}
