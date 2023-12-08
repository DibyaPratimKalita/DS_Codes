#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node {
    int data;
    struct Node *next;
};

// Function to insert a number at the front of the linked list
struct Node* insertAtFront(struct Node* head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = head;
    return newNode;
}

// Function to insert a number at the end of the linked list
struct Node* insertAtLast(struct Node* head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    return head;
}

// Function to insert a number after a given number in the linked list
struct Node* insertAfter(struct Node* head, int afterData, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;

    struct Node* current = head;

    while (current != NULL && current->data != afterData) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Element %d not found in the list.\n", afterData);
        free(newNode);
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// Function to insert a number before a given number in the linked list
struct Node* insertBefore(struct Node* head, int beforeData, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;

    if (head == NULL) {
        printf("List is empty. Cannot insert before %d.\n", beforeData);
        free(newNode);
        return head;
    }

    if (head->data == beforeData) {
        newNode->next = head;
        return newNode;
    }

    struct Node* current = head;
    while (current->next != NULL && current->next->data != beforeData) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("Element %d not found in the list.\n", beforeData);
        free(newNode);
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Insert at front
    head = insertAtFront(head, 10);
    head = insertAtFront(head, 20);
    head = insertAtFront(head, 30);
    printf("Linked list after inserting at front: ");
    displayList(head);

    // Insert at last
    head = insertAtLast(head, 40);
    head = insertAtLast(head, 50);
    printf("Linked list after inserting at last: ");
    displayList(head);

    // Insert after a given number
    head = insertAfter(head, 30, 35);
    printf("Linked list after inserting after 30: ");
    displayList(head);

    // Insert before a given number
    head = insertBefore(head, 50, 45);
    printf("Linked list after inserting before 50: ");
    displayList(head);

    return 0;
}