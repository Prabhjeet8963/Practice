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

// Function to find the LCA of two nodes in the BST
struct Node* findLCA(struct Node* root, int n1, int n2) {
    // Base case: if the tree is empty
    if (root == NULL) {
        return NULL;
    }

    // If both n1 and n2 are smaller than root, then LCA lies in the left subtree
    if (root->data > n1 && root->data > n2) {
        return findLCA(root->left, n1, n2);
    }

    // If both n1 and n2 are greater than root, then LCA lies in the right subtree
    if (root->data < n1 && root->data < n2) {
        return findLCA(root->right, n1, n2);
    }

    // If one of n1 or n2 is smaller and the other is larger, root is the LCA
    return root;
}

int main() {
    struct Node* root = NULL;

    // Insert nodes into the BST
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 25);
    root = insert(root, 35);

    // Find and print the LCA of two nodes
    int n1 = 5, n2 = 15;
    struct Node* lca = findLCA(root, n1, n2);
    if (lca != NULL) {
        printf("LCA of %d and %d is: %d\n", n1, n2, lca->data);
    } else {
        printf("LCA not found.\n");
    }

    return 0;
}
