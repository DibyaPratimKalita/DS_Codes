/*Write a program to insert in a doubly linked list as given below
(a) Insert at front
(b) Insert at last
(c) Insert after a given node
(d) Insert before a given nod*/

#include <stdio.h>
#include <stdlib.h>

// Structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to display the doubly linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to insert at the front of the doubly linked list
struct Node* insertAtFront(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        return newNode;
    }

    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

// Function to insert at the last of the doubly linked list
struct Node* insertAtLast(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        return newNode;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
    return head;
}

// Function to insert after a given node in the doubly linked list
struct Node* insertAfterNode(struct Node* head, struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL.\n");
        return head;
    }

    struct Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    newNode->prev = prevNode;

    if (prevNode->next != NULL) {
        prevNode->next->prev = newNode;
    }

    prevNode->next = newNode;
    return head;
}

// Function to insert before a given node in the doubly linked list
struct Node* insertBeforeNode(struct Node* head, struct Node* nextNode, int data) {
    if (nextNode == NULL) {
        printf("Next node cannot be NULL.\n");
        return head;
    }

    struct Node* newNode = createNode(data);
    newNode->prev = nextNode->prev;
    newNode->next = nextNode;

    if (nextNode->prev != NULL) {
        nextNode->prev->next = newNode;
    }

    nextNode->prev = newNode;

    if (newNode->prev == NULL) {
        return newNode; // newNode is the new head
    }

    return head;
}

// Function to free the memory used by the doubly linked list
void freeList(struct Node* head) {
    struct Node* current = head;
    struct Node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

int main() {
    // Create a doubly linked list with elements 1, 2, and 3
    struct Node* head = NULL;
    head = insertAtLast(head, 1);
    head = insertAtLast(head, 2);
    head = insertAtLast(head, 3);

    // Display the original doubly linked list
    printf("Original Doubly Linked List: ");
    displayList(head);

    // (a) Insert at front
    head = insertAtFront(head, 0);
    printf("Doubly Linked List after inserting at front: ");
    displayList(head);

    // (b) Insert at last
    head = insertAtLast(head, 4);
    printf("Doubly Linked List after inserting at last: ");
    displayList(head);

    // (c) Insert after a given node (insert after node with data 2)
    struct Node* nodeToInsertAfter = head->next;
    head = insertAfterNode(head, nodeToInsertAfter, 10);
    printf("Doubly Linked List after inserting after a given node: ");
    displayList(head);

    // (d) Insert before a given node (insert before node with data 2)
    struct Node* nodeToInsertBefore = head->next->next;
    head = insertBeforeNode(head, nodeToInsertBefore, 7);
    printf("Doubly Linked List after inserting before a given node: ");
    displayList(head);

    // Free the memory used by the doubly linked list
    freeList(head);

    return 0;
}