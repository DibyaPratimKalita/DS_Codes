// Write a program to reverse a linked list using iterative method

#include <stdio.h>
#include <stdlib.h>

// Node structure for a linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to reverse a linked list iteratively
struct Node* reverseLinkedList(struct Node* head) {
    struct Node *prev = NULL, *current = head, *next = NULL;

    while (current != NULL) {
        next = current->next;  // Store the next node
        current->next = prev;  // Reverse the link

        prev = current;  // Move pointers one position ahead
        current = next;
    }

    return prev;  // New head of the reversed list
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

    // Reverse the linked list
    head = reverseLinkedList(head);

    printf("Reversed Linked List: ");
    printLinkedList(head);

    return 0;
}
