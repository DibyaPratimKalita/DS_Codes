//. Write a program to delete all occurrences of a given key in a linked list.
#include <stdio.h>
#include <stdlib.h>

// Node structure for a linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to delete all occurrences of a given key in a linked list
struct Node* deleteOccurrences(struct Node* head, int key) {
    struct Node* dummy = (struct Node*)malloc(sizeof(struct Node));
    dummy->next = head;
    struct Node* current = dummy;
    struct Node* temp;

    while (current->next != NULL) {
        if (current->next->data == key) {
            temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }

    head = dummy->next;
    free(dummy);
    return head;
}

// Function to print the linked list
void printLinkedList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to create a new node in the linked list
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (!node) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    node->data = data;
    node->next = NULL;
    return node;
}

int main() {
    // Creating a sample linked list: 1 -> 2 -> 2 -> 4 -> 2 -> 5
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(2);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(2);
    head->next->next->next->next->next = newNode(5);

    printf("Original Linked List: ");
    printLinkedList(head);

    int key = 2;

    // Delete all occurrences of 'key' in the linked list
    head = deleteOccurrences(head, key);

    printf("Linked List after deleting all occurrences of %d: ", key);
    printLinkedList(head);

    return 0;
}
