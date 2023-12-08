// Write a function that counts the number of times a given int occurs in a linked list
#include <stdio.h>
#include <stdlib.h>

// Node structure for a linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to count occurrences of a given int in a linked list
int countOccurrences(struct Node* head, int key) {
    int count = 0;
    struct Node* current = head;

    while (current != NULL) {
        if (current->data == key) {
            count++;
        }
        current = current->next;
    }

    return count;
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

    // Count the number of occurrences of 'key' in the linked list
    int occurrences = countOccurrences(head, key);
    printf("The number %d occurs %d times in the linked list.\n", key, occurrences);

    return 0;
}
