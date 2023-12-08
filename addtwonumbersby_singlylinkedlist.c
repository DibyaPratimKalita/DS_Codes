//. Write a program to add two numbers represented by a singly linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of a linked list
void push(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
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

// Function to reverse a linked list
struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Function to add two numbers represented by linked lists
struct Node* addNumbers(struct Node* l1, struct Node* l2) {
    struct Node* result = NULL;
    struct Node* current = NULL;
    int carry = 0, sum;

    while (l1 != NULL || l2 != NULL || carry) {
        sum = carry + (l1 ? l1->data : 0) + (l2 ? l2->data : 0);
        carry = sum / 10;
        sum %= 10;

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        if (!newNode) {
            printf("Memory allocation failed.\n");
            return NULL;
        }
        newNode->data = sum;
        newNode->next = NULL;

        if (result == NULL) {
            result = newNode;
        } else {
            current->next = newNode;
        }
        current = newNode;

        if (l1) {
            l1 = l1->next;
        }
        if (l2) {
            l2 = l2->next;
        }
    }

    return result;
}

int main() {
    // Creating linked lists representing numbers: 243 (3 -> 4 -> 2) and 564 (4 -> 6 -> 5)
    struct Node* num1 = NULL;
    push(&num1, 2);
    push(&num1, 4);
    push(&num1, 3);

    struct Node* num2 = NULL;
    push(&num2, 5);
    push(&num2, 6);
    push(&num2, 4);

    printf("Number 1 represented by Linked List: ");
    printLinkedList(num1);

    printf("Number 2 represented by Linked List: ");
    printLinkedList(num2);

    // Adding numbers represented by linked lists
    struct Node* sum = addNumbers(num1, num2);

    printf("Sum of Numbers represented by Linked Lists: ");
    printLinkedList(sum);

    return 0;
}
