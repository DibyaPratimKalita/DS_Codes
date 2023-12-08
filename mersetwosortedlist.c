//. Write a program to merge two sorted linked lists such that the resultant linked list becomes sorted
#include <stdio.h>
#include <stdlib.h>

// Node structure for a linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to merge two sorted linked lists
struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }

    struct Node* result = NULL;

    if (list1->data <= list2->data) {
        result = list1;
        result->next = mergeSortedLists(list1->next, list2);
    } else {
        result = list2;
        result->next = mergeSortedLists(list1, list2->next);
    }

    return result;
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
    // Creating sorted linked lists: list1: 1 -> 3 -> 5 -> 7; list2: 2 -> 4 -> 6 -> 8
    struct Node* list1 = newNode(1);
    list1->next = newNode(3);
    list1->next->next = newNode(5);
    list1->next->next->next = newNode(7);

    struct Node* list2 = newNode(2);
    list2->next = newNode(4);
    list2->next->next = newNode(6);
    list2->next->next->next = newNode(8);

    printf("Sorted Linked List 1: ");
    printLinkedList(list1);

    printf("Sorted Linked List 2: ");
    printLinkedList(list2);

    // Merge the sorted linked lists
    struct Node* mergedList = mergeSortedLists(list1, list2);

    printf("Merged Sorted Linked List: ");
    printLinkedList(mergedList);

    return 0;
}
