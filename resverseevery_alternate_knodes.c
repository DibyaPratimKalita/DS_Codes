/*Given a linked list, write a function to reverse every alternate k nodes (where k is an input to the
function) in an efficient way.*/
#include <stdio.h>
#include <stdlib.h>

// Node structure for a linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to reverse k nodes in a linked list
struct Node* reverseKNodes(struct Node* head, int k) {
    if (head == NULL || k <= 1) {
        return head;
    }

    struct Node* current = head;
    struct Node* prevTail = NULL;
    struct Node* prev = NULL;
    struct Node* next = NULL;
    int count = 0;

    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    if (head != NULL) {
        head->next = current;
    }

    count = 0;
    while (current != NULL && count < k - 1) {
        current = current->next;
        count++;
    }

    if (current != NULL) {
        current->next = reverseKNodes(current->next, k);
    }

    return prev;
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
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
    head->next->next->next->next->next = newNode(6);
    head->next->next->next->next->next->next = newNode(7);
    head->next->next->next->next->next->next->next = newNode(8);
    head->next->next->next->next->next->next->next->next = newNode(9);
    head->next->next->next->next->next->next->next->next->next = newNode(10);

    printf("Original Linked List: ");
    printLinkedList(head);

    int k = 7;

    // Reverse every alternate k nodes in the linked list
    head = reverseKNodes(head, k);

    printf("Linked List after reversing every alternate %d nodes: ", k);
    printLinkedList(head);

    return 0;
}
