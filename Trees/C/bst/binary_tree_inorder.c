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
    // If the tree is empty, return a new node
    if (root == NULL) {
        return newNode(data);
    }

    // Otherwise, recur down the tree
    if (data < root->data) {
        root->left = insert(root->left, data);  // Insert in left subtree
    } else if (data > root->data) {
        root->right = insert(root->right, data);  // Insert in right subtree
    }

    // Return the (unchanged) node pointer
    return root;
}

// Function to perform inorder traversal of the BST (Left, Root, Right)
void inorder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);    // Visit left subtree
    printf("%d ", root->data);  // Visit root
    inorder(root->right);   // Visit right subtree
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

    // Perform inorder traversal to display the nodes in sorted order
    printf("Inorder Traversal (Sorted Order): ");
    inorder(root);
    printf("\n");

    return 0;
}
