#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* left; 
    int data;          
    struct Node* right; 
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = data; 
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data); 
    }
    if (data < root->data) {
        root->left = insert(root->left, data); 
    } else {
        root->right = insert(root->right, data); 
    }
    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left); 
        printf("%d ", root->data);
        inorder(root->right); 
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left); 
        postorder(root->right); 
        printf("%d ", root->data); 
    }
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data); 
        preorder(root->left); 
        preorder(root->right); 
    }
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 22);
    root = insert(root, 45);
    root = insert(root, 36);
    root = insert(root, 41);
    root = insert(root, 50);
    root = insert(root, 40);
    root = insert(root, 73);
    printf("In-order Traversal: ");
    inorder(root);
    printf("\n");

    printf("Post-order Traversal: ");
    postorder(root);
    printf("\n");

    printf("Pre-order Traversal: ");
    preorder(root);
    printf("\n");

    return 0;
}