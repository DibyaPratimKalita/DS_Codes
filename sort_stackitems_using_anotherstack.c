//Write a program to sort the stack items using another stack

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

struct Stack {
    int top;
    int* array;
};

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->array = (int*)malloc(MAX_SIZE * sizeof(int));
    return stack;
}

int isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

void push(struct Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->array[stack->top--];
}

void sortStack(struct Stack* stack) {
    struct Stack* tempStack = createStack();

    while (!isEmpty(stack)) {
        int temp = pop(stack);

        while (!isEmpty(tempStack) && tempStack->array[tempStack->top] < temp) {
            push(stack, pop(tempStack));
        }

        push(tempStack, temp);
    }

    while (!isEmpty(tempStack)) {
        push(stack, pop(tempStack));
    }

    free(tempStack->array);
    free(tempStack);
}

void printStack(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack contents: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

int main() {
    struct Stack* stack = createStack();

    push(stack, 30);
    push(stack, -5);
    push(stack, 18);
    push(stack, 14);
    push(stack, -3);

    printf("Original stack:\n");
    printStack(stack);

    sortStack(stack);

    printf("\nStack after sorting:\n");
    printStack(stack);

    free(stack->array);
    free(stack);

    return 0;
}