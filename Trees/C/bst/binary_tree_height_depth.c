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

// Function to calculate the height of a binary tree (Recursive)
int height(struct Node* root) {
    if (root == NULL) {
        return 0;  // Base case: height of empty tree is 0
    }
    // Recursive case: height is 1 + max(height of left subtree, height of right subtree)
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Function to calculate the depth of a node in the binary tree
int depth(struct Node* root, int value, int currentDepth) {
    if (root == NULL) {
        return -1;  // Node not found
    }
    if (root->data == value) {
        return currentDepth;  // Found the node, return the current depth
    }
    // Search for the node in the left or right subtree
    int leftDepth = depth(root->left, value, currentDepth + 1);
    if (leftDepth != -1) {
        return leftDepth;  // If found in the left subtree, return the depth
    }
    return depth(root->right, value, currentDepth + 1);  // Otherwise search in the right subtree
}

int main() {
    // Creating the binary tree
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);

    int choice, value;

    while (1) {
        // Menu for height and depth operations
        printf("\n--- Binary Tree Operations ---\n");
        printf("1. Calculate the Height of the Tree\n");
        printf("2. Find the Depth of a Node\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Calculate and print the height of the binary tree
                {
                    int treeHeight = height(root);
                    printf("Height of the binary tree: %d\n", treeHeight);
                }
                break;
            case 2:
                // Ask for the value of the node to find its depth
                {
                    printf("Enter the value of the node to find its depth: ");
                    scanf("%d", &value);
                    int nodeDepth = depth(root, value, 0);  // Starting depth from root (depth = 0)
                    if (nodeDepth != -1) {
                        printf("Depth of node with value %d: %d\n", value, nodeDepth);
                    } else {
                        printf("Node with value %d not found in the tree.\n", value);
                    }
                }
                break;
            case 3:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
