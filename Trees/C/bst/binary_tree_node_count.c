#include <stdio.h>
#include <stdlib.h>

// Define a structure for the Binary Tree Node
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

// Recursive function to count the total number of nodes in the binary tree
int countNodes(struct Node* root) {
    if (root == NULL) {
        return 0;  // Base case: if the node is NULL, it doesn't count as a node
    }
    // Recursive case: count the current node + left subtree + right subtree
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    // Creating the binary tree with 8 nodes
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);

    // Counting the total number of nodes in the tree
    int totalNodes = countNodes(root);
    printf("Total number of nodes in the binary tree: %d\n", totalNodes);

    return 0;
}
