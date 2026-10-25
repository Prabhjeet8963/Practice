#include <stdio.h>
#include <stdlib.h>

// Define structure for AVL tree node
struct Node {
    int data;
    struct Node *left, *right;
    int height;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    node->height = 1;  // New node is initially at height 1
    return node;
}

// Function to get the height of a node
int height(struct Node* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

// Function to get the balance factor of a node
int getBalance(struct Node* node) {
    if (node == NULL) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

// Right rotation
struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;
    
    // Perform rotation
    x->right = y;
    y->left = T2;
    
    // Update heights
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    
    return x;  // New root
}

// Left rotation
struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;
    
    // Perform rotation
    y->left = x;
    x->right = T2;
    
    // Update heights
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    
    return y;  // New root
}

// Left-Right rotation (Double rotation)
struct Node* leftRightRotate(struct Node* node) {
    node->left = leftRotate(node->left);
    return rightRotate(node);
}

// Right-Left rotation (Double rotation)
struct Node* rightLeftRotate(struct Node* node) {
    node->right = rightRotate(node->right);
    return leftRotate(node);
}

// Insert a node into the AVL tree
struct Node* insert(struct Node* node, int data) {
    // Perform normal BST insert
    if (node == NULL) {
        return newNode(data);
    }
    
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    } else {
        // Duplicates not allowed
        return node;
    }
    
    // Update the height of this ancestor node
    node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));
    
    // Get the balance factor of this ancestor node to check if it became unbalanced
    int balance = getBalance(node);
    
    // If the node becomes unbalanced, then there are 4 cases
    
    // Left Left Case
    if (balance > 1 && data < node->left->data) {
        return rightRotate(node);
    }
    
    // Right Right Case
    if (balance < -1 && data > node->right->data) {
        return leftRotate(node);
    }
    
    // Left Right Case
    if (balance > 1 && data > node->left->data) {
        return leftRightRotate(node);
    }
    
    // Right Left Case
    if (balance < -1 && data < node->right->data) {
        return rightLeftRotate(node);
    }
    
    return node;
}

// Function to perform in-order traversal and print the AVL tree
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Main function
int main() {
    struct Node* root = NULL;
    
    // Inserting nodes into the AVL tree
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 25);
    root = insert(root, 35);
    
    // Display the AVL tree in in-order
    printf("In-order traversal of the AVL tree: ");
    inorder(root);
    printf("\n");
    
    return 0;
}
