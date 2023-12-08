//Write a program to perform the Morris traversal on a binary tree

#include <stdio.h>
#include <stdlib.h>

// Node structure for a binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function for Morris inorder traversal
void morrisInorderTraversal(struct Node* root) {
    struct Node* current = root;
    while (current != NULL) {
        if (current->left == NULL) {
            printf("%d ", current->data);
            current = current->right;
        } else {
            // Find the inorder predecessor of current
            struct Node* predecessor = current->left;
            while (predecessor->right != NULL && predecessor->right != current) {
                predecessor = predecessor->right;
            }

            // Make current as the right child of its inorder predecessor
            if (predecessor->right == NULL) {
                predecessor->right = current;
                current = current->left;
            } else {
                // Revert the changes made in the tree
                predecessor->right = NULL;
                printf("%d ", current->data);
                current = current->right;
            }
        }
    }
}

int main() {
    // Create a binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Morris Inorder Traversal: ");
    morrisInorderTraversal(root);
    printf("\n");

    return 0;
}