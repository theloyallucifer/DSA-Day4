#include <stdio.h>
#include <stdlib.h> 

#define MAX 100    

char stack[MAX];
int top = -1;


void push(char x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = x;
}


char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

int precedence(char x) {
    switch (x) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}


int isOperator(char x) {
    return x == '+' || x == '-' || x == '*' || x == '/' || x == '^';
}


int isOperand(char x) {
    return (x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z');
}


void infixToPostfix(char* infix) {
    char *e = infix; 
    char x;

    while (*e != '\0') {
        if (isOperand(*e)) {  
            printf("%c ", *e);
        } else if (*e == '(') {  
            push(*e);
        } else if (*e == ')') {  
            while ((x = pop()) != '(') {
                printf("%c ", x);
            }
        } else if (isOperator(*e)) {  
            while (top != -1 && precedence(stack[top]) >= precedence(*e)) {
                printf("%c ", pop());
            }
            push(*e);
        }
        e++;  
    }

    
    while (top != -1) {
        printf("%c ", pop());
    }
}

int main() {
    char infix[MAX];

    printf("Enter an infix expression: ");
    gets(infix); 
    
    printf("Postfix expression: ");
    infixToPostfix(infix);  

    return 0;
}

