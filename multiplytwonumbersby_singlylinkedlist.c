//. Write a program to multiply two numbers represented by a singly linked list
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

struct Node* multiplyNumbers(struct Node* l1, struct Node* l2) {
    if (l1 == NULL || l2 == NULL) {
        printf("Empty list(s).\n");
        return NULL;
    }

    l1 = reverseList(l1);
    l2 = reverseList(l2);

    int len1 = 0, len2 = 0;

    struct Node* temp1 = l1;
    while (temp1 != NULL) {
        len1++;
        temp1 = temp1->next;
    }

    struct Node* temp2 = l2;
    while (temp2 != NULL) {
        len2++;
        temp2 = temp2->next;
    }

    int* result = (int*)calloc(len1 + len2, sizeof(int));

    temp1 = l1;
    int i = 0;

    while (temp1 != NULL) {
        int carry = 0;
        temp2 = l2;
        int j = 0;

        while (temp2 != NULL) {
            result[i + j] += temp1->data * temp2->data + carry;
            carry = result[i + j] / 10;
            result[i + j] %= 10;
            j++;
            temp2 = temp2->next;
        }

        if (carry > 0) {
            result[i + j] += carry;
        }

        i++;
        temp1 = temp1->next;
    }

    struct Node* resList = NULL;
    struct Node* resTemp = NULL;

    for (int k = 0; k < len1 + len2; k++) {
        push(&resList, result[k]);
    }

    free(result);
    return resList;
}

int main() {
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

    struct Node* product = multiplyNumbers(num1, num2);

    printf("Product of Numbers represented by Linked Lists: ");
    printLinkedList(product);

    return 0;
}

