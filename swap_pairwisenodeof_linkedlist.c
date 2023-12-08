//. Write a program to swap pairwise of the nodes of a given linked list

#include <stdio.h>
#include <stdlib.h>

// Node structure for a linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to swap pairs of nodes in a linked list
struct Node* swapPairs(struct Node* head) {
    struct Node* dummy = (struct Node*)malloc(sizeof(struct Node));
    dummy->next = head;
    struct Node* prev = dummy;

    while (prev->next != NULL && prev->next->next != NULL) {
        struct Node* first = prev->next;
        struct Node* second = first->next;

        // Swapping nodes
        first->next = second->next;
        second->next = first;
        prev->next = second;

        // Move to the next pair
        prev = first;
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
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
    head->next->next->next->next->next = newNode(6);
    head->next->next->next->next->next->next = newNode(7);

    printf("Original Linked List: ");
    printLinkedList(head);

    // Swap pairs of nodes in the linked list
    head = swapPairs(head);

    printf("Linked List after swapping pairs: ");
    printLinkedList(head);

    return 0;
}
