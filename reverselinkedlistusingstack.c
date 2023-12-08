// Write a program to reverse a linked list using a) stack 

#include <stdio.h>
#include <stdlib.h>

// Node structure for a linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to push elements onto the stack
void push(struct Node** top, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

// Function to pop elements from the stack
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack is empty.\n");
        return -1; // Assuming -1 denotes an error value
    }
    struct Node* temp = *top;
    int data = temp->data;
    *top = temp->next;
    free(temp);
    return data;
}

// Function to reverse a linked list using a stack
void reverseLinkedList(struct Node** head) {
    if (*head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    struct Node* current = *head;
    struct Node* stack = NULL;

    // Push elements onto the stack
    while (current != NULL) {
        push(&stack, current->data);
        current = current->next;
    }

    // Pop elements to construct the reversed linked list
    current = *head;
    while (current != NULL) {
        current->data = pop(&stack);
        current = current->next;
    }
}

// Function to print the linked list
void printLinkedList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to create a new node in the linked list
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (!node) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    node->data = data;
    node->next = NULL;
    return node;
}

int main() {
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    printf("Original Linked List: ");
    printLinkedList(head);

    // Reverse the linked list using a stack
    reverseLinkedList(&head);

    printf("Reversed Linked List: ");
    printLinkedList(head);

    return 0;
}
