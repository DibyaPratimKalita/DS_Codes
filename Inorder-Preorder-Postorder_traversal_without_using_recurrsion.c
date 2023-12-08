//Inorder-Preorder-Postorder_traversal_without_using_recurrsion

#include <stdio.h>
#include <stdlib.h>

// Node structure for a binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Stack structure for iterative traversals
struct Stack {
    struct Node** array;
    int top;
    unsigned capacity;
};

// Function to create a stack
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (struct Node**)malloc(stack->capacity * sizeof(struct Node*));
    return stack;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push a node to the stack
void push(struct Stack* stack, struct Node* item) {
    if (isFull(stack)) {
        return;
    }
    stack->array[++stack->top] = item;
}

// Function to pop a node from the stack
struct Node* pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        return NULL;
    }
    return stack->array[stack->top--];
}

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

// Iterative Inorder traversal
void inorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    struct Node* current = root;
    struct Stack* stack = createStack(100); // Assuming the maximum size of the stack is 100

    while (current != NULL || !isEmpty(stack)) {
        while (current != NULL) {
            push(stack, current);
            current = current->left;
        }
        current = pop(stack);
        printf("%d ", current->data);
        current = current->right;
    }
    free(stack->array);
    free(stack);
}

// Iterative Preorder traversal
void preorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    struct Node* current = root;
    struct Stack* stack = createStack(100); // Assuming the maximum size of the stack is 100

    push(stack, current);

    while (!isEmpty(stack)) {
        current = pop(stack);
        printf("%d ", current->data);

        if (current->right != NULL) {
            push(stack, current->right);
        }
        if (current->left != NULL) {
            push(stack, current->left);
        }
    }
    free(stack->array);
    free(stack);
}

// Iterative Postorder traversal
void postorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    struct Node* current = root;
    struct Stack* stack1 = createStack(100); // Assuming the maximum size of the stack is 100
    struct Stack* stack2 = createStack(100);

    push(stack1, current);

    while (!isEmpty(stack1)) {
        current = pop(stack1);
        push(stack2, current);

        if (current->left != NULL) {
            push(stack1, current->left);
        }
        if (current->right != NULL) {
            push(stack1, current->right);
        }
    }

    while (!isEmpty(stack2)) {
        current = pop(stack2);
        printf("%d ", current->data);
    }
    free(stack1->array);
    free(stack1);
    free(stack2->array);
    free(stack2);
}

int main() {
    // Create a binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Iterative Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Iterative Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Iterative Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}