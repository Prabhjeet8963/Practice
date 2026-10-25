#include <stdio.h>
#include <stdlib.h>

// Define the structure for the Binary Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue structure for level order traversal
struct Queue {
    struct Node** arr;
    int front, rear;
    int size;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to create a queue
struct Queue* createQueue(int size) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->arr = (struct Node**)malloc(size * sizeof(struct Node*));
    queue->front = queue->rear = -1;
    queue->size = size;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == -1);
}

// Function to add a node to the queue
void enqueue(struct Queue* queue, struct Node* node) {
    if (queue->rear == queue->size - 1) {
        printf("Queue is full\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->arr[++queue->rear] = node;
}

// Function to remove a node from the queue
struct Node* dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return NULL;
    }
    struct Node* node = queue->arr[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }
    return node;
}

// Function for level order traversal using a queue
void levelOrderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    struct Queue* queue = createQueue(100); // Create a queue with capacity 100
    enqueue(queue, root); // Start with the root node

    while (!isEmpty(queue)) {
        struct Node* currentNode = dequeue(queue); // Dequeue a node
        printf("%d ", currentNode->data); // Print the node's data

        // Enqueue left and right children of the dequeued node
        if (currentNode->left != NULL) {
            enqueue(queue, currentNode->left);
        }
        if (currentNode->right != NULL) {
            enqueue(queue, currentNode->right);
        }
    }
}

// Main function to test the level order traversal
int main() {
    // Create a simple binary tree
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    // Perform level order traversal
    printf("Level Order Traversal: ");
    levelOrderTraversal(root);
    printf("\n");

    return 0;
}
