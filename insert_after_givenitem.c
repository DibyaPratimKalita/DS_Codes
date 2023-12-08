//Write a program to Insert after the given item in a doubly linked list

#include <stdio.h>
#include <stdlib.h>

// Node structure for the doubly linked list
struct Node {
    int data;
    struct Node* prev;
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
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node after a given node in the doubly linked list
void insertAfter(struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }

    struct Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    if (prevNode->next != NULL) {
        prevNode->next->prev = newNode;
    }
    prevNode->next = newNode;
    newNode->prev = prevNode;

    printf("Inserted %d after %d in the doubly linked list\n", data, prevNode->data);
}

// Function to display the elements of the doubly linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("Doubly linked list is empty\n");
        return;
    }

    struct Node* temp = head;
    printf("Doubly linked list: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to free memory allocated for the doubly linked list
void freeList(struct Node** head) {
    struct Node *current = *head, *temp;
    if (*head == NULL) {
        return;
    }

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }

    *head = NULL;
}

int main() {
    struct Node* head = NULL;

    // Insert items into the doubly linked list
    head = createNode(10);
    struct Node* secondNode = createNode(20);
    head->next = secondNode;
    secondNode->prev = head;
    displayList(head);

    insertAfter(head, 15);

    // Display the doubly linked list
    displayList(head);

    // Free memory allocated for the doubly linked list
    freeList(&head);

    return 0;
}