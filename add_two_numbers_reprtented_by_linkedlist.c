#include <stdio.h>
#include <stdlib.h>

// Definition for a singly-linked list node
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to add two numbers represented by linked lists
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* current = dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;

        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = sum % 10;
        current->next = NULL;
    }

    struct ListNode* result = dummy->next;
    free(dummy);

    return result;
}

// Function to create a new linked list node
struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

// Function to print a linked list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // Example usage
    struct ListNode* l1 = createNode(2);
    l1->next = createNode(4);
    l1->next->next = createNode(3);

    struct ListNode* l2 = createNode(5);
    l2->next = createNode(6);
    l2->next->next = createNode(4);

    printf("Input: ");
    printList(l1);
    printList(l2);

    struct ListNode* sum = addTwoNumbers(l1, l2);

    printf("Sum: ");
    printList(sum);

    // Free the allocated memory
    while (l1 != NULL) {
        struct ListNode* temp = l1;
        l1 = l1->next;
        free(temp);
    }

    while (l2 != NULL) {
        struct ListNode* temp = l2;
        l2 = l2->next;
        free(temp);
    }

    while (sum != NULL) {
        struct ListNode* temp = sum;
        sum = sum->next;
        free(temp);
    }

    return 0;
}