/*Write a program to delete from a doubly linked list as given below-
(a) Delete from front
(b) Delete from the last
(c) Delete a given number*/


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

// Function to delete from the front of the doubly linked list
struct Node* deleteFromFront(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Cannot delete from front.\n");
        return NULL;
    }

    struct Node* newHead = head->next;
    if (newHead != NULL) {
        newHead->prev = NULL;
    }

    free(head);
    return newHead;
}

// Function to delete from the last of the doubly linked list
struct Node* deleteFromLast(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Cannot delete from last.\n");
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
    return head;
}

// Function to delete a given number from the doubly linked list
struct Node* deleteNumber(struct Node* head, int key) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return NULL;
    }

    struct Node* current = head;

    // If the key is in the first node
    if (current->data == key) {
        head = current->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(current);
        return head;
    }

    // Find the node with the key
    while (current != NULL && current->data != key) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Key %d not found in the list. Cannot delete.\n", key);
        return head;
    }

    // Adjust the pointers to skip the node with the key
    if (current->prev != NULL) {
        current->prev->next = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);
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
    // Create a doubly linked list with elements 1, 2, 3, and 4
    struct Node* head = NULL;
    head = insertAtLast(head, 1);
    head = insertAtLast(head, 2);
    head = insertAtLast(head, 3);
    head = insertAtLast(head, 4);

    // Display the original doubly linked list
    printf("Original Doubly Linked List: ");
    displayList(head);

    // (a) Delete from front
    head = deleteFromFront(head);
    printf("Doubly Linked List after deleting from front: ");
    displayList(head);

    // (b) Delete from last
    head = deleteFromLast(head);
    printf("Doubly Linked List after deleting from last: ");
    displayList(head);

    // (c) Delete a given number (delete number 2)
    head = deleteNumber(head, 2);
    printf("Doubly Linked List after deleting the given number: ");
    displayList(head);

    // Free the memory used by the doubly linked list
    freeList(head);

    return 0;
}