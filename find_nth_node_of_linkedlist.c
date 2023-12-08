// Write a program to find nth node from the end of a linked list.
#include <stdio.h>
#include <stdlib.h>

// Node structure for a linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to find the nth node from the end of a linked list
struct Node* nthNodeFromEnd(struct Node* head, int n) {
    if (head == NULL || n <= 0) {
        printf("Invalid input or empty list.\n");
        return NULL;
    }

    struct Node* firstPtr = head;
    struct Node* secondPtr = head;

    // Move first pointer 'n' nodes ahead
    for (int i = 0; i < n; i++) {
        if (firstPtr == NULL) {
            printf("List is shorter than %d nodes.\n", n);
            return NULL;
        }
        firstPtr = firstPtr->next;
    }

    // Move both pointers until the first pointer reaches the end
    while (firstPtr != NULL) {
        firstPtr = firstPtr->next;
        secondPtr = secondPtr->next;
    }

    return secondPtr;
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

    int n = 2;

    // Find the nth node from the end of the linked list
    struct Node* result = nthNodeFromEnd(head, n);
    if (result != NULL) {
        printf("The %dth node from the end is: %d\n", n, result->data);
    }

    return 0;
}
