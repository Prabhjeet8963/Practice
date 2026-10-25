#include <stdio.h>
#include <stdlib.h>

// Define the structure for the Binary Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function for right rotation
struct Node* rightRotate(struct Node* root) {
    struct Node* newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;
    return newRoot;
}

// Function for left rotation
struct Node* leftRotate(struct Node* root) {
    struct Node* newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;
    return newRoot;
}

// Function for left-right rotation (left rotate followed by right rotate)
struct Node* leftRightRotate(struct Node* root) {
    root->left = leftRotate(root->left);  // Left rotation
    return rightRotate(root);  // Right rotation
}

// Function for right-left rotation (right rotate followed by left rotate)
struct Node* rightLeftRotate(struct Node* root) {
    root->right = rightRotate(root->right);  // Right rotation
    return leftRotate(root);  // Left rotation
}

// Function to print in-order traversal of the tree
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    // Create a sample binary tree
    struct Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(15);
    root->left->left = newNode(2);
    root->left->right = newNode(7);
    root->right->right = newNode(20);
    
    printf("Original Tree (In-order): ");
    inorder(root);
    printf("\n");

    // Perform Right Rotation
    root = rightRotate(root);
    printf("Right Rotation (In-order): ");
    inorder(root);
    printf("\n");

    // Perform Left Rotation
    root = leftRotate(root);
    printf("Left Rotation (In-order): ");
    inorder(root);
    printf("\n");

    // Perform Left-Right Rotation
    root = leftRightRotate(root);
    printf("Left-Right Rotation (In-order): ");
    inorder(root);
    printf("\n");

    // Perform Right-Left Rotation
    root = rightLeftRotate(root);
    printf("Right-Left Rotation (In-order): ");
    inorder(root);
    printf("\n");

    return 0;
}
