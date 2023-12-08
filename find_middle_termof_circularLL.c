//Write a program to find the middle item of a circular linked list.

#include <stdio.h>
#include <stdlib.h>

// Node structure for the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the circular linked list
void insertItem(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
    printf("Inserted %d \n", data);
}

// Function to find the middle item in a circular linked list
void findMiddle(struct Node* head) {
    if (head == NULL) {
        printf("Circular linked list is empty\n");
        return;
    }

    struct Node *slowPtr = head, *fastPtr = head;

    while (fastPtr != NULL && fastPtr->next != head) {
        fastPtr = fastPtr->next->next;
        slowPtr = slowPtr->next;
        if (fastPtr == head || fastPtr->next == head) {
            break;
        }
    }

    printf("The middle item of the circular linked list is: %d\n", slowPtr->data);
}

// Function to free memory allocated for the circular linked list
// (The freeList function remains the same as the previous implementations)
// Code is identical to the 'Insert an Item in a Circular Linked List' code block.

int main() {
    struct Node* head = NULL;

    // Insert items into the circular linked list
    insertItem(&head, 10);
    insertItem(&head, 20);
    insertItem(&head, 30);
    insertItem(&head, 40);
    insertItem(&head, 50);

    // Find the middle item of the circular linked list
    findMiddle(head);

    // Free memory allocated for the circular linked list
    // (Freeing part remains the same as previous implementations)
    // Code is identical to the 'Insert an Item in a Circular Linked List' code block.

    return 0;
}