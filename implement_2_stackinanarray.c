//Write a program to implement two stacks in a single array

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct TwoStacks {
    int top1;
    int top2;
    int* array;
};

struct TwoStacks* createTwoStacks() {
    struct TwoStacks* ts = (struct TwoStacks*)malloc(sizeof(struct TwoStacks));
    ts->top1 = -1;
    ts->top2 = MAX_SIZE;
    ts->array = (int*)malloc(MAX_SIZE * sizeof(int));
    return ts;
}

void push1(struct TwoStacks* ts, int value) {
    if (ts->top1 < ts->top2 - 1) {
        ts->array[++ts->top1] = value;
    } else {
        printf("Stack Overflow\n");
    }
}

void push2(struct TwoStacks* ts, int value) {
    if (ts->top1 < ts->top2 - 1) {
        ts->array[--ts->top2] = value;
    } else {
        printf("Stack Overflow\n");
    }
}

int pop1(struct TwoStacks* ts) {
    if (ts->top1 >= 0) {
        int value = ts->array[ts->top1--];
        return value;
    } else {
        printf("Stack 1 Underflow\n");
        return -1;
    }
}

int pop2(struct TwoStacks* ts) {
    if (ts->top2 < MAX_SIZE) {
        int value = ts->array[ts->top2++];
        return value;
    } else {
        printf("Stack 2 Underflow\n");
        return -1;
    }
}

int main() {
    struct TwoStacks* ts = createTwoStacks();

    push1(ts, 10);
    push2(ts, 20);
    push1(ts, 30);
    push2(ts, 40);

    printf("Popped element from stack 1: %d\n", pop1(ts));
    printf("Popped element from stack 2: %d\n", pop2(ts));

    return 0;
}