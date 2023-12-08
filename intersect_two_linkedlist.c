#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to find the intersection of two linked lists
struct Node* intersectLists(struct Node* list1, struct Node* list2) {
    struct Node* intersectionHead = NULL;
    struct Node* intersectionTail = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data == list2->data) {
            // Common node found, add it to the intersection list
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = list1->data;
            newNode->next = NULL;

            if (intersectionHead == NULL) {
                // First node in the intersection list
                intersectionHead = newNode;
                intersectionTail = newNode;
            } else {
                // Add the node to the end of the intersection list
                intersectionTail->next = newNode;
                intersectionTail = newNode;
            }

            // Move to the next nodes in both lists
            list1 = list1->next;
            list2 = list2->next;
        } else if (list1->data < list2->data) {
            // Move to the next node in the first list
            list1 = list1->next;
        } else {
            // Move to the next node in the second list
            list2 = list2->next;
        }
    }

    return intersectionHead;
}

int main() {
    // Creating linked list 1: 1 -> 2 -> 3 -> 4 -> 5
    struct Node* list1 = (struct Node*)malloc(sizeof(struct Node));
    list1->data = 1;
    list1->next = (struct Node*)malloc(sizeof(struct Node));
    list1->next->data = 2;
    list1->next->next = (struct Node*)malloc(sizeof(struct Node));
    list1->next->next->data = 3;
    list1->next->next->next = (struct Node*)malloc(sizeof(struct Node));
    list1->next->next->next->data = 4;
    list1->next->next->next->next = (struct Node*)malloc(sizeof(struct Node));
    list1->next->next->next->next->data = 5;
    list1->next->next->next->next->next = NULL;

    // Creating linked list 2: 3 -> 4 -> 5 -> 6 -> 7
    struct Node* list2 = (struct Node*)malloc(sizeof(struct Node));
    list2->data = 3;
    list2->next = (struct Node*)malloc(sizeof(struct Node));
    list2->next->data = 4;
    list2->next->next = (struct Node*)malloc(sizeof(struct Node));
    list2->next->next->data = 5;
    list2->next->next->next = (struct Node*)malloc(sizeof(struct Node));
    list2->next->next->next->data = 6;
    list2->next->next->next->next = (struct Node*)malloc(sizeof(struct Node));
    list2->next->next->next->next->data = 7;
    list2->next->next->next->next->next = NULL;

    // Finding intersection
    struct Node* intersection = intersectLists(list1, list2);

    // Printing the result
    if (intersection != NULL) {
        printf("Intersection found: ");
        printList(intersection);
    } else {
        printf("No intersection found.\n");
    }

    // Freeing memory
    free(list1);
    free(list2);
    free(intersection);

    return 0;
}