//Write a program to print the middle of a given linked list.
#include <stdio.h>
#include <stdlib.h>

// Node structure for a linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to find the middle of a linked list
struct Node* findMiddle(struct Node* head) {
    if (head == NULL) {
        printf("Empty list.\n");
        return NULL;
    }

    struct Node* slowPtr = head;
    struct Node* fastPtr = head;

    while (fastPtr != NULL && fastPtr->next != NULL) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }

    return slowPtr;
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

    // Find the middle node of the linked list
    struct Node* middle = findMiddle(head);
    if (middle != NULL) {
        printf("Middle of the Linked List: %d\n", middle->data);
    }

    return 0;
}
