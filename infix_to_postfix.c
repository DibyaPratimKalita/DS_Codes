#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Structure to represent a stack
struct Stack {
    int top;
    char items[MAX_SIZE];
};

// Function to initialize an empty stack
void initializeStack(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to check the precedence of an operator
int getPrecedence(char operator) {
    if (operator == '+' || operator == '-')
        return 1;
    else if (operator == '*' || operator == '/')
        return 2;
    else if (operator == '^')
        return 3;
    else
        return 0; // For '(' and ')'
}

// Function to push an item onto the stack
void push(struct Stack* stack, char item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->items[++stack->top] = item;
}

// Function to pop an item from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top--];
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char infix[], char postfix[]) {
    struct Stack stack;
    initializeStack(&stack);

    int i, j;
    i = j = 0;

    while (infix[i] != '\0') {
        char token = infix[i];

        if (token >= 'a' && token <= 'z' || token >= 'A' && token <= 'Z') {
            // If the token is an operand, add it to the postfix expression
            postfix[j++] = token;
        } else if (token == '(') {
            // If the token is '(', push it onto the stack
            push(&stack, token);
        } else if (token == ')') {
            // If the token is ')', pop and output operators from the stack
            // until '(' is encountered
            while (!isEmpty(&stack) && stack.items[stack.top] != '(') {
                postfix[j++] = pop(&stack);
            }
            // Pop '(' from the stack
            pop(&stack);
        } else {
            // If the token is an operator, pop and output operators from the stack
            // until an operator with lower precedence or '(' is encountered
            while (!isEmpty(&stack) && getPrecedence(stack.items[stack.top]) >= getPrecedence(token)) {
                postfix[j++] = pop(&stack);
            }
            // Push the current operator onto the stack
            push(&stack, token);
        }

        i++;
    }

    // Pop any remaining operators from the stack and append them to the postfix expression
    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }

    // Null-terminate the postfix expression
    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    // Input infix expression
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    // Convert infix to postfix
    infixToPostfix(infix, postfix);

    // Output postfix expression
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
