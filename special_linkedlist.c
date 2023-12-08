/*Write a program to make a special linked list called a multi-linked list. The pointers are defined as
follows- i) the next pointer points to the next items, ii) the prev pointer points to the previous items,
iii) the random pointer points to random nodes, iv) the asc pointer points to the next larger number,
and v) the dsc pointer points to the next smaller number.
(a) Write a program to insert many items into the multi-linked list such that we can display a)
ascending order, b) descending order, and c) random order in O(n) time complexity*/

/*Author : RAJ ROY*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAscending(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL || (*head)->data >= newNode->data) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    while (current->next != NULL && current->next->data < newNode->data) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void display(struct Node* head) {
    struct Node* current = head;

    printf("Ascending Order: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    printf("Descending Order: ");
    while (head != NULL) {
        struct Node* max = head;
        current = head;

        while (current != NULL) {
            if (current->data > max->data) {
                max = current;
            }
            current = current->next;
        }

        printf("%d ", max->data);
        if (max == head) {
            head = head->next;
        } else {
            struct Node* prev = head;
            while (prev->next != max) {
                prev = prev->next;
            }
            prev->next = max->next;
        }
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        int data = rand() % 100; 
        insertAscending(&head, data);
    }

    display(head);

    return 0;
}
