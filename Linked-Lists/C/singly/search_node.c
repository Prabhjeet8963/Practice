#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* CreateNode() {
    Node* NewNode = (Node*)malloc(sizeof(Node));
    int input_data;
    printf("Enter a number: ");
    scanf("%d", &input_data);
    NewNode->data = input_data;
    NewNode->next = NULL;
    return NewNode;
}

void SearchNode(Node* startNode) {
    int searchNum;
    printf("\nEnter the number you want to search: ");
    scanf("%d", &searchNum);
    
    Node* temp = startNode;
    int pos = 1;
    int found = 0;
    while (temp) {
        if (temp->data == searchNum) {
            printf("Num found at position: %d\n", pos);
            found = 1;
        }
        temp = temp->next;
        pos++;
    }
    if (!found) {
        printf("Num not found\n");
    }
}

int main() {
    int n;
    printf("How many numbers do you want: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Invalid Input");
        exit(1);
    }
    
    Node* startNode = CreateNode();
    Node* temp = startNode; // Temp node which stores the n-1 node
    for (int i = 1; i < n; i++) {
        Node* NewNode = CreateNode();
        temp->next = NewNode; // Adding address of n-th node to n-1 node
        temp = NewNode;        
    }

    printf("Linked List:\n");
    temp = startNode;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    // Perform the search
    SearchNode(startNode);

    // Clean up linked list memory
    temp = startNode;
    while (temp) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }

    return 0;
}
