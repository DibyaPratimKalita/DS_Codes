//Detect whether a linked list contains a loop (cycle) or not

#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
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

// Function to insert a new node at the beginning of the linked list
void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to detect a loop in the linked list
int detectLoop(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return 0; // No loop in an empty or single-node list
    }

    struct Node *slowPtr = head, *fastPtr = head;

    while (fastPtr != NULL && fastPtr->next != NULL) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        if (slowPtr == fastPtr) {
            return 1; // Loop detected
        }
    }

    return 0; // No loop found
}

int main() {
    struct Node* head = NULL;

    // Insert elements into the linked list
    insertNode(&head, 10);
    insertNode(&head, 20);
    insertNode(&head, 30);
    insertNode(&head, 40);

    // Create a loop for demonstration (uncomment to create a loop)
    // head->next->next->next->next = head;

    // Detect if the linked list contains a loop
    int loopExists = detectLoop(head);

    if (loopExists) {
        printf("Loop detected in the linked list\n");
    } else {
        printf("No loop found in the linked list\n");
    }

    return 0;
}