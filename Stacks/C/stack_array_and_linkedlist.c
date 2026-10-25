#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack using Array
int stackArray[MAX];
int topArray = -1;

// Stack using Linked List
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* topLinkedList = NULL;

// Array-based Stack functions
void pushArray(int value) {
    if (topArray == MAX - 1) {
        printf("Stack Overflow: Cannot push %d\n", value);
        return;
    }
    stackArray[++topArray] = value;
    printf("%d pushed onto the array stack.\n", value);
}

void popArray() {
    if (topArray == -1) {
        printf("Stack Underflow: No elements to pop.\n");
        return;
    }
    printf("Popped element from array stack: %d\n", stackArray[topArray--]);
}

void peekArray() {
    if (topArray == -1) {
        printf("Array stack is empty.\n");
        return;
    }
    printf("Top element of array stack: %d\n", stackArray[topArray]);
}

void isEmptyArray() {
    if (topArray == -1)
        printf("Array stack is empty.\n");
    else
        printf("Array stack is not empty.\n");
}

void isFullArray() {
    if (topArray == MAX - 1)
        printf("Array stack is full.\n");
    else
        printf("Array stack is not full.\n");
}

void displayArray() {
    if (topArray == -1) {
        printf("Array stack is empty.\n");
        return;
    }
    printf("Array stack elements (top to bottom): ");
    for (int i = topArray; i >= 0; i--) {
        printf("%d ", stackArray[i]);
    }
    printf("\n");
}

// Linked List-based Stack functions
void pushLinkedList(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Stack Overflow: Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->next = topLinkedList;
    topLinkedList = newNode;
    printf("%d pushed onto the linked list stack.\n", value);
}

void popLinkedList() {
    if (topLinkedList == NULL) {
        printf("Stack Underflow: No elements to pop.\n");
        return;
    }
    Node* temp = topLinkedList;
    printf("Popped element from linked list stack: %d\n", temp->data);
    topLinkedList = topLinkedList->next;
    free(temp);
}

void peekLinkedList() {
    if (topLinkedList == NULL) {
        printf("Linked list stack is empty.\n");
        return;
    }
    printf("Top element of linked list stack: %d\n", topLinkedList->data);
}

void isEmptyLinkedList() {
    if (topLinkedList == NULL)
        printf("Linked list stack is empty.\n");
    else
        printf("Linked list stack is not empty.\n");
}

void isFullLinkedList() {
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL)
        printf("Linked list stack is full (memory exhausted).\n");
    else {
        printf("Linked list stack is not full.\n");
        free(temp);
    }
}

void displayLinkedList() {
    if (topLinkedList == NULL) {
        printf("Linked list stack is empty.\n");
        return;
    }
    Node* temp = topLinkedList;
    printf("Linked list stack elements (top to bottom): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function with menu to select either Array or Linked List-based Stack
int main() {
    int choice, value, stackChoice;

    printf("Select Stack Type:\n1. Array-based Stack\n2. Linked List-based Stack\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &stackChoice);

    while (1) {
        if (stackChoice == 1) {
            printf("\n--- Array Stack Operations Menu ---\n");
            printf("1. Push\n2. Pop\n3. Peek\n4. Check Empty\n5. Check Full\n6. Display\n7. Exit\n");
        } else if (stackChoice == 2) {
            printf("\n--- Linked List Stack Operations Menu ---\n");
            printf("1. Push\n2. Pop\n3. Peek\n4. Check Empty\n5. Check Full\n6. Display\n7. Exit\n");
        } else {
            printf("Invalid stack choice. Exiting program.\n");
            exit(0);
        }

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                if (stackChoice == 1)
                    pushArray(value);
                else
                    pushLinkedList(value);
                break;
            case 2:
                if (stackChoice == 1)
                    popArray();
                else
                    popLinkedList();
                break;
            case 3:
                if (stackChoice == 1)
                    peekArray();
                else
                    peekLinkedList();
                break;
            case 4:
                if (stackChoice == 1)
                    isEmptyArray();
                else
                    isEmptyLinkedList();
                break;
            case 5:
                if (stackChoice == 1)
                    isFullArray();
                else
                    isFullLinkedList();
                break;
            case 6:
                if (stackChoice == 1)
                    displayArray();
                else
                    displayLinkedList();
                break;
            case 7:
                printf("Exiting program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
