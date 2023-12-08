#include <stdio.h>
#include <stdlib.h>

// Structure to represent a stack
struct Stack {
    int top;
    char items[100];
};

// Function to initialize an empty stack
void initializeStack(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an item onto the stack
void push(struct Stack* stack, char item) {
    if (stack->top == 99) {
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

// Function to check whether parentheses are balanced
int areParenthesesBalanced(char expression[]) {
    struct Stack stack;
    initializeStack(&stack);

    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
            // If the current character is an opening parenthesis, push it onto the stack
            push(&stack, expression[i]);
        } else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {
            // If the current character is a closing parenthesis, check if the stack is empty
            if (isEmpty(&stack)) {
                return 0; // Unbalanced, as there is no matching opening parenthesis
            }

            // Pop the top element from the stack and check if it matches the current closing parenthesis
            char topElement = pop(&stack);
            if ((expression[i] == ')' && topElement != '(') ||
                (expression[i] == ']' && topElement != '[') ||
                (expression[i] == '}' && topElement != '{')) {
                return 0; // Mismatched opening and closing parentheses
            }
        }
    }

    // If the stack is empty, all parentheses are balanced
    return isEmpty(&stack);
}

int main() {
    char expression[100];

    // Input expression
    printf("Enter an expression: ");
    scanf("%s", expression);

    // Check if parentheses are balanced
    if (areParenthesesBalanced(expression)) {
        printf("Parentheses are balanced.\n");
    } else {
        printf("Parentheses are not balanced.\n");
    }

    return 0;
}



