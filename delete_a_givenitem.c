//write a program to delete a given item of doubly liked list

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

// Function to delete a given item from the doubly linked list
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("Doubly linked list is empty, deletion not possible\n");
        return;
    }

    struct Node* temp = *head;
    // Find the node containing the key
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Item %d not found in the doubly linked list\n", key);
        return;
    }

    // Adjust pointers to delete the node
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Deleted item %d from the doubly linked list\n", key);
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

    // Display the doubly linked list
    displayList(head);

    // Delete an item from the doubly linked list
    deleteNode(&head, 20);

    // Display the modified doubly linked list
    displayList(head);

    // Free memory allocated for the doubly linked list
    freeList(&head);

    return 0;
}