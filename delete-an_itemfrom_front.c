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

// Function to insert a new node at the front of the doubly linked list
void insertAtFront(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
    printf("Inserted %d \n", data);
}

// Function to delete the first node from the doubly linked list
void deleteFromFront(struct Node** head) {
    if (*head == NULL) {
        printf("Doubly linked list is empty, deletion not possible\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);

    printf("Deleted the first item from the doubly linked list\n");
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

    // Insert items at the front of the doubly linked list
    insertAtFront(&head, 10);
    insertAtFront(&head, 20);
    insertAtFront(&head, 30);
    insertAtFront(&head, 40);

    // Display the doubly linked list
    displayList(head);

    // Delete the first item from the doubly linked list
    deleteFromFront(&head);

    // Display the modified doubly linked list
    displayList(head);

    // Free memory allocated for the doubly linked list
    freeList(&head);

    return 0;
}