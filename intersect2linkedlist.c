//Write a program to intersect two linked lists (see the definition of the intersection in set theory)
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

struct Node* intersectLinkedLists(struct Node* list1, struct Node* list2) {
    struct Node* result = NULL;
    struct Node* tail = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data == list2->data) {
            push(&result, list1->data);
            if (tail == NULL) {
                tail = result;
            } else {
                tail->next = (struct Node*)malloc(sizeof(struct Node));
                tail = tail->next;
                tail->data = list1->data;
                tail->next = NULL;
            }
            list1 = list1->next;
            list2 = list2->next;
        } else if (list1->data < list2->data) {
            list1 = list1->next;
        } else {
            list2 = list2->next;
        }
    }

    return result;
}

int main() {
    // Creating linked lists representing sets: {1, 2, 3, 4, 5} and {3, 4, 5, 6, 7}
    struct Node* list1 = NULL;
    push(&list1, 5);
    push(&list1, 4);
    push(&list1, 3);
    push(&list1, 2);
    push(&list1, 1);

    struct Node* list2 = NULL;
    push(&list2, 7);
    push(&list2, 6);
    push(&list2, 5);
    push(&list2, 4);
    push(&list2, 3);

    printf("List 1: ");
    printLinkedList(list1);

    printf("List 2: ");
    printLinkedList(list2);

    struct Node* intersection = intersectLinkedLists(list1, list2);

    printf("Intersection of Lists: ");
    printLinkedList(intersection);

    return 0;
}

