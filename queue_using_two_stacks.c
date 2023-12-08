/*Write a program to implement a queue using two stacks and implement the following functions-
(a) isFull()
(b) isEmpty()
(c) enQueue()
(d) deQueue()*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent a stack
struct Stack {
    int top;
    int items[MAX_SIZE];
};

// Function to initialize an empty stack
void initializeStack(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isStackEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isStackFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push an item onto the stack
void push(struct Stack* stack, int item) {
    if (isStackFull(stack)) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->items[++stack->top] = item;
}

// Function to pop an item from the stack
int pop(struct Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top--];
}

// Function to check if the queue is full
int isFull(struct Stack* stack1, struct Stack* stack2) {
    return stack1->top + stack2->top == MAX_SIZE - 1;
}

// Function to check if the queue is empty
int isEmpty(struct Stack* stack1, struct Stack* stack2) {
    return isStackEmpty(stack1) && isStackEmpty(stack2);
}

// Function to enqueue (insert) an element into the queue
void enQueue(struct Stack* stack1, struct Stack* stack2, int value) {
    if (isFull(stack1, stack2)) {
        printf("Queue is full, cannot enqueue %d\n", value);
        exit(EXIT_FAILURE);
    }

    // Push the element onto stack1
    push(stack1, value);
    printf("Enqueued %d into the queue\n", value);
}

// Function to dequeue (remove) an element from the queue
int deQueue(struct Stack* stack1, struct Stack* stack2) {
    if (isEmpty(stack1, stack2)) {
        printf("Queue is empty, cannot dequeue\n");
        exit(EXIT_FAILURE);
    }

    // If stack2 is empty, transfer elements from stack1 to stack2
    if (isStackEmpty(stack2)) {
        while (!isStackEmpty(stack1)) {
            push(stack2, pop(stack1));
        }
    }

    // Pop the element from stack2 (which is the front of the queue)
    return pop(stack2);
}

int main() {
    struct Stack stack1, stack2;
    initializeStack(&stack1);
    initializeStack(&stack2);

    // Enqueue elements into the queue
    enQueue(&stack1, &stack2, 10);
    printf("Is Queue empty? %s\n", isEmpty(&stack1, &stack2) ? "Yes" : "No");
    printf("Is Queue full? %s\n", isFull(&stack1, &stack2) ? "Yes" : "No");

    enQueue(&stack1, &stack2, 20);
    printf("Is Queue empty? %s\n", isEmpty(&stack1, &stack2) ? "Yes" : "No");
    printf("Is Queue full? %s\n", isFull(&stack1, &stack2) ? "Yes" : "No");

    enQueue(&stack1, &stack2, 30);
    printf("Is Queue empty? %s\n", isEmpty(&stack1, &stack2) ? "Yes" : "No");
    printf("Is Queue full? %s\n", isFull(&stack1, &stack2) ? "Yes" : "No");

    // Dequeue elements from the queue
    printf("Dequeued element: %d\n", deQueue(&stack1, &stack2));
    printf("Dequeued element: %d\n", deQueue(&stack1, &stack2));
    printf("Dequeued element: %d\n", deQueue(&stack1, &stack2));

    return 0;
}