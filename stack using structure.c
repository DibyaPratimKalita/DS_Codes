/*Stack can be built using an array. Write a program to implement stack using structure for the
following function-
(a) isEmpty()
(b) isFull()
(c) Push()
(d) Pop()
(e) Peek()*/

#include <stdio.h>
#include <stdbool.h>

// Maximum size of the stack
#define MAX_SIZE 100

// Structure to represent a stack
struct Stack {
    int arr[MAX_SIZE];
    int top;
};

// Function to check if the stack is empty
bool isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
bool isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow, cannot push %d\n", value);
    } else {
        stack->arr[++stack->top] = value;
        printf("Pushed %d onto the stack\n", value);
    }
}

// Function to pop an element from the stack
void pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow, cannot pop\n");
    } else {
        printf("Popped %d from the stack\n", stack->arr[stack->top--]);
    }
}

// Function to peek at the top element of the stack
void peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty, cannot peek\n");
    } else {
        printf("Top element of the stack: %d\n", stack->arr[stack->top]);
    }
}

// Function to display whether the stack is empty or full
void displayStatus(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
    } else if (isFull(stack)) {
        printf("Stack is full\n");
    } else {
        printf("Stack is neither empty nor full\n");
    }
}

int main() {
    // Initialize an empty stack
    struct Stack stack;
    stack.top = -1;

    // Demonstrate stack operations
    displayStatus(&stack);

    push(&stack, 10);
    displayStatus(&stack);

    push(&stack, 20);
    displayStatus(&stack);

    push(&stack, 30);
    displayStatus(&stack);

    peek(&stack);

    pop(&stack);
    displayStatus(&stack);

    pop(&stack);
    displayStatus(&stack);

    peek(&stack);

    pop(&stack); // Stack will be empty at this point
    displayStatus(&stack);

    return 0;
}