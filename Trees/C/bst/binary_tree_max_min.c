#include <stdio.h>
#include <stdlib.h>

// Define the structure for the Binary Search Tree Node
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

// Function to insert a node into the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return newNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);  // Insert in left subtree
    } else if (data > root->data) {
        root->right = insert(root->right, data);  // Insert in right subtree
    }
    return root;
}

// Function to find the minimum element in the BST
int findMin(struct Node* root) {
    struct Node* current = root;
    while (current && current->left != NULL) {
        current = current->left;  // Move to the leftmost node
    }
    return current ? current->data : -1;  // Return -1 if tree is empty
}

// Function to find the maximum element in the BST
int findMax(struct Node* root) {
    struct Node* current = root;
    while (current && current->right != NULL) {
        current = current->right;  // Move to the rightmost node
    }
    return current ? current->data : -1;  // Return -1 if tree is empty
}

int main() {
    struct Node* root = NULL;  // Initialize an empty tree

    // Insert nodes into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Find and print the minimum and maximum elements in the BST
    printf("Minimum element in the BST: %d\n", findMin(root));
    printf("Maximum element in the BST: %d\n", findMax(root));

    return 0;
}
