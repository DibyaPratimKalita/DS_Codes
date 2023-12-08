/* We are given a linked list and positions m and n. Write a program to reverse the linked list from position
m to n.*/

#include <stdio.h>
#include <stdlib.h>

// Node structure for a linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to reverse a linked list from position m to n
struct Node* reverseBetween(struct Node* head, int m, int n) {
    if (head == NULL || m == n) {
        return head;
    }

    struct Node* prev = NULL;
    struct Node* current = head;

    // Traverse to the position before m
    for (int i = 1; i < m && current != NULL; i++) {
        prev = current;
        current = current->next;
    }

    struct Node* beforeM = prev; // Node before position m
    struct Node* nodeM = current; // Node at position m

    // Reversing the nodes from position m to n
    prev = NULL;
    for (int i = m; i <= n && current != NULL; i++) {
        struct Node* nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    // Update pointers to connect the reversed part with the original list
    if (beforeM != NULL) {
        beforeM->next = prev;
    } else {
        head = prev; // When reversing from the start of the list
    }
    nodeM->next = current;

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
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    printf("Original Linked List: ");
    printLinkedList(head);

    int m = 2;
    int n = 4;

    // Reverse the linked list from position m to n
    head = reverseBetween(head, m, n);

    printf("Reversed Linked List from position %d to %d: ", m, n);
    printLinkedList(head);

    return 0;
}
