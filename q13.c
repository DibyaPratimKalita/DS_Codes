/*Given a linked list and a value x, write a program to partition it such that all nodes less than x come
first, then all nodes with a value equal to x, and finally nodes with a value greater than or equal to x.
(Hints: call by reference).*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

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

void printLinkedList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void partition(struct Node** head, int x) {
    struct Node* smallerHead = NULL;
    struct Node* smallerTail = NULL;
    struct Node* greaterHead = NULL;
    struct Node* greaterTail = NULL;
    struct Node* current = *head;

    while (current != NULL) {
        if (current->data < x) {
            if (smallerHead == NULL) {
                smallerHead = current;
                smallerTail = current;
            } else {
                smallerTail->next = current;
                smallerTail = current;
            }
        } else {
            if (greaterHead == NULL) {
                greaterHead = current;
                greaterTail = current;
            } else {
                greaterTail->next = current;
                greaterTail = current;
            }
        }
        current = current->next;
    }

    if (smallerTail != NULL) {
        smallerTail->next = greaterHead;
        *head = smallerHead;
    } else {
        *head = greaterHead;
    }

    if (greaterTail != NULL) {
        greaterTail->next = NULL;
    }
}

int main() {
    // Creating a linked list: 1 -> 4 -> 3 -> 2 -> 5 -> 2
    struct Node* head = NULL;
    push(&head, 2);
    push(&head, 5);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 1);

    printf("Original Linked List: ");
    printLinkedList(head);

    int x = 3; // Partition value

    partition(&head, x);

    printf("Linked List after partition around %d: ", x);
    printLinkedList(head);

    return 0;
}
