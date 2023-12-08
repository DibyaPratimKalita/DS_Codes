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

// Function to reverse a doubly linked list
struct Node* reverseList(struct Node* head) {
    struct Node *temp = NULL, *current = head;

    while (current != NULL) {
        // Swap next and prev pointers of the current node
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Move to the next node
        current = current->prev;
    }

    // Check if the list is not empty
    if (temp != NULL) {
        head = temp->prev; // The last node is now the head
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
    // Create a doubly linked list with elements 1, 2, 3, and 4
    struct Node* head = NULL;
    head = createNode(1);
    head->next = createNode(2);
    head->next->prev = head;
    head->next->next = createNode(3);
    head->next->next->prev = head->next;
    head->next->next->next = createNode(4);
    head->next->next->next->prev = head->next->next;

    // Display the original doubly linked list
    printf("Original Doubly Linked List: ");
    displayList(head);

    // Reverse the doubly linked list
    head = reverseList(head);
    printf("Reversed Doubly Linked List: ");
    displayList(head);

    // Free the memory used by the doubly linked list
    freeList(head);

    return 0;
}