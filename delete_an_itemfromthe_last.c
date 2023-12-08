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

// Function to insert a new node at the end of the doubly linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Inserted %d at the end of the doubly linked list\n", data);
}

// Function to delete the last item from the doubly linked list
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("Doubly linked list is empty, deletion not possible\n");
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        *head = NULL;
    }
    free(temp);

    printf("Deleted the last item from the doubly linked list\n");
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

    // Insert items at the end of the doubly linked list
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);

    // Display the doubly linked list
    displayList(head);

    // Delete the last item from the doubly linked list
    deleteFromEnd(&head);

    // Display the modified doubly linked list
    displayList(head);

    // Free memory allocated for the doubly linked list
    freeList(&head);

    return 0;
}