//Write a program to evaluate an expression using stack. For instance, 4+6*3-10/2

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent a stack
struct Stack {
    int top;
    double items[MAX_SIZE];
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
void push(struct Stack* stack, double item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->items[++stack->top] = item;
}

// Function to pop an item from the stack
double pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top--];
}

// Function to evaluate an expression
double evaluateExpression(char expression[]) {
    struct Stack operandStack;
    struct Stack operatorStack;

    initializeStack(&operandStack);
    initializeStack(&operatorStack);

    int i = 0;
    while (expression[i] != '\0') {
        if (expression[i] >= '0' && expression[i] <= '9') {
            // If the current character is a digit, extract the number
            double operand = 0.0;
            while (expression[i] >= '0' && expression[i] <= '9') {
                operand = operand * 10 + (expression[i] - '0');
                i++;
            }
            // Push the operand onto the operand stack
            push(&operandStack, operand);
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            // If the current character is an operator, push it onto the operator stack
            while (!isEmpty(&operatorStack) &&
                   ((expression[i] == '*' || expression[i] == '/') &&
                    (operatorStack.items[operatorStack.top] == '*' || operatorStack.items[operatorStack.top] == '/')) ||
                   ((expression[i] == '+' || expression[i] == '-') &&
                    (operatorStack.items[operatorStack.top] == '+' || operatorStack.items[operatorStack.top] == '-' ||
                     operatorStack.items[operatorStack.top] == '*' || operatorStack.items[operatorStack.top] == '/'))) {
                // Pop and evaluate operators from the operator stack and perform the operation
                double operand2 = pop(&operandStack);
                double operand1 = pop(&operandStack);
                char operator = pop(&operatorStack);
                switch (operator) {
                    case '+':
                        push(&operandStack, operand1 + operand2);
                        break;
                    case '-':
                        push(&operandStack, operand1 - operand2);
                        break;
                    case '*':
                        push(&operandStack, operand1 * operand2);
                        break;
                    case '/':
                        push(&operandStack, operand1 / operand2);
                        break;
                }
            }
            // Push the current operator onto the operator stack
            push(&operatorStack, expression[i]);
            i++;
        } else {
            // Ignore other characters (such as spaces)
            i++;
        }
    }

    // Pop and evaluate any remaining operators from the operator stack
    while (!isEmpty(&operatorStack)) {
        double operand2 = pop(&operandStack);
        double operand1 = pop(&operandStack);
        char operator = pop(&operatorStack);
        switch (operator) {
            case '+':
                push(&operandStack, operand1 + operand2);
                break;
            case '-':
                push(&operandStack, operand1 - operand2);
                break;
            case '*':
                push(&operandStack, operand1 * operand2);
                break;
            case '/':
                push(&operandStack, operand1 / operand2);
                break;
        }
    }

    // The final result should be at the top of the operand stack
    return pop(&operandStack);
}

int main() {
    char expression[] = "4+6*3-10/2";
    double result = evaluateExpression(expression);
    printf("Result: %f\n", result);

    return 0;
}