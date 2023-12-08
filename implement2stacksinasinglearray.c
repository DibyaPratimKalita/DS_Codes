/*Write a program to implement two stacks in a single array and implement the following functions-
(a) isFull()
(b) isEmpty()
(c) Push()
(d) Pop()
(e) Peek()*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent two stacks in a single array
struct TwoStacks {
    int top1;
    int top2;
    int items[MAX_SIZE];
};

// Function to initialize the two stacks
void initializeTwoStacks(struct TwoStacks* stacks) {
    stacks->top1 = -1;
    stacks->top2 = MAX_SIZE;
}

// Function to check if the first stack is empty
int isStack1Empty(struct TwoStacks* stacks) {
    return stacks->top1 == -1;
}

// Function to check if the second stack is empty
int isStack2Empty(struct TwoStacks* stacks) {
    return stacks->top2 == MAX_SIZE;
}

// Function to check if the first stack is full
int isStack1Full(struct TwoStacks* stacks) {
    return stacks->top1 + 1 == stacks->top2;
}

// Function to check if the second stack is full
int isStack2Full(struct TwoStacks* stacks) {
    return stacks->top2 - 1 == stacks->top1;
}

// Function to push an item onto the first stack
void push1(struct TwoStacks* stacks, int item) {
    if (isStack1Full(stacks)) {
        printf("Stack 1 overflow\n");
        exit(EXIT_FAILURE);
    }
    stacks->items[++stacks->top1] = item;
    printf("Pushed %d onto Stack 1\n", item);
}

// Function to push an item onto the second stack
void push2(struct TwoStacks* stacks, int item) {
    if (isStack2Full(stacks)) {
        printf("Stack 2 overflow\n");
        exit(EXIT_FAILURE);
    }
    stacks->items[--stacks->top2] = item;
    printf("Pushed %d onto Stack 2\n", item);
}

// Function to pop an item from the first stack
int pop1(struct TwoStacks* stacks) {
    if (isStack1Empty(stacks)) {
        printf("Stack 1 underflow\n");
        exit(EXIT_FAILURE);
    }
    return stacks->items[stacks->top1--];
}

// Function to pop an item from the second stack
int pop2(struct TwoStacks* stacks) {
    if (isStack2Empty(stacks)) {
        printf("Stack 2 underflow\n");
        exit(EXIT_FAILURE);
    }
    return stacks->items[stacks->top2++];
}

// Function to peek at the top item of the first stack
int peek1(struct TwoStacks* stacks) {
    if (isStack1Empty(stacks)) {
        printf("Stack 1 is empty, cannot peek\n");
        exit(EXIT_FAILURE);
    }
    return stacks->items[stacks->top1];
}

// Function to peek at the top item of the second stack
int peek2(struct TwoStacks* stacks) {
    if (isStack2Empty(stacks)) {
        printf("Stack 2 is empty, cannot peek\n");
        exit(EXIT_FAILURE);
    }
    return stacks->items[stacks->top2];
}

int main() {
    struct TwoStacks stacks;
    initializeTwoStacks(&stacks);

    // Push elements onto the stacks
    push1(&stacks, 10);
    printf("Is Stack 1 empty? %s\n", isStack1Empty(&stacks) ? "Yes" : "No");
    printf("Is Stack 1 full? %s\n", isStack1Full(&stacks) ? "Yes" : "No");

    push2(&stacks, 20);
    printf("Is Stack 2 empty? %s\n", isStack2Empty(&stacks) ? "Yes" : "No");
    printf("Is Stack 2 full? %s\n", isStack2Full(&stacks) ? "Yes" : "No");

    push1(&stacks, 30);
    printf("Is Stack 1 empty? %s\n", isStack1Empty(&stacks) ? "Yes" : "No");
    printf("Is Stack 1 full? %s\n", isStack1Full(&stacks) ? "Yes" : "No");

    // Pop elements from the stacks
    printf("Popped from Stack 1: %d\n", pop1(&stacks));
    printf("Popped from Stack 2: %d\n", pop2(&stacks));
    printf("Popped from Stack 1: %d\n", pop1(&stacks));

    // Peek at the top items of the stacks
    printf("Top of Stack 1: %d\n", peek1(&stacks));
    printf("Top of Stack 2: %d\n", peek2(&stacks));

    return 0;
}
