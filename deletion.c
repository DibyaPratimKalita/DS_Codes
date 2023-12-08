include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node {
    int data;
    struct Node *next;
};

// Function to insert a number at the front of the linked list
struct Node *insertAtFront(struct Node *head, int newData) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = head;
    return newNode;
}

// Function to insert a number at the end of the linked list
struct Node *insertAtLast(struct Node *head, int newData) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    return head;
}

// Function to delete a number from the front of the linked list
struct Node *deleteFromFront(struct Node *head) {
    if (head == NULL) {
        printf("List is empty. Cannot delete from front.\n");
        return NULL;
    }

    struct Node *newHead = head->next;
    free(head);
    return newHead;
}

// Function to delete a number from the last of the linked list
struct Node *deleteFromLast(struct Node *head) {
    if (head == NULL) {
        printf("List is empty. Cannot delete from last.\n");
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node *current = head;
    struct Node *prev = NULL;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    free(current);
    if (prev != NULL) {
        prev->next = NULL;
    } else {
        // If there was only one element in the list
        head = NULL;
    }

    return head;
}

// Function to delete a given number from the linked list
struct Node *deleteGivenNumber(struct Node *head, int target) {
    if (head == NULL) {
        printf("List is empty. Cannot delete %d.\n", target);
        return NULL;
    }

    if (head->data == target) {
        struct Node *newHead = head->next;
        free(head);
        return newHead;
    }

    struct Node *current = head;
    struct Node *prev = NULL;
    while (current != NULL && current->data != target) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Element %d not found in the list.\n", target);
        return head;
    }

    if (prev != NULL) {
        prev->next = current->next;
    } else {
        // If the target is the first element in the list
        head = current->next;
    }

    free(current);
    return head;
}

// Function to display the linked list
void displayList(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;

    // Insert at front
    head = insertAtFront(head, 10);
    head = insertAtFront(head, 20);
    head = insertAtFront(head, 30);
    printf("Linked list after inserting at front: ");
    displayList(head);

    // Insert at last
    head = insertAtLast(head, 40);
    head = insertAtLast(head, 50);
    printf("Linked list after inserting at last: ");
    displayList(head);

    // Delete from front
    head = deleteFromFront(head);
    printf("Linked list after deleting from front: ");
    displayList(head);

    // Delete from last
    head = deleteFromLast(head);
    printf("Linked list after deleting from last: ");
    displayList(head);

    // Delete a given number
    head = deleteGivenNumber(head, 20);
    printf("Linked list after deleting 20: ");
    displayList(head);

    return 0;
}