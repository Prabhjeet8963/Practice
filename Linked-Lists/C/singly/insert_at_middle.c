#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* Next;
};

// Function to insert in the middle region
void mid(struct Node** Head, int x) {
    if (*Head == NULL || (*Head)->Next == NULL) {
        printf("List is too short for middle insertion.\n");
        return;
    }
    
    struct Node* slow = *Head;
    struct Node* fast = (*Head)->Next;

    
    while (fast != NULL && fast->Next != NULL) {
        slow = slow->Next;
        fast = fast->Next->Next;
    }

    // Insert after the middle
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->Next = slow->Next;
    slow->Next = temp;
}

void insertAtEnd(struct Node** Head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->Next = NULL;
    if (*Head == NULL) {
        *Head = newNode;
        return;
    }
    struct Node* current = *Head;
    while (current->Next != NULL) {
        current = current->Next;
    }
    current->Next = newNode;
}

void printList(struct Node* Head) {
    struct Node* temp = Head;
    printf("The linked list is: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->Next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* Head = NULL;

    // Populate the list with some initial values
    insertAtEnd(&Head, 1);
    insertAtEnd(&Head, 2);
    insertAtEnd(&Head, 3);
    insertAtEnd(&Head, 5); 

    printf("Original Linked List: ");
    printList(Head);

    int num;
    printf("Enter the number to be inserted in the middle region: ");
    scanf("%d", &num);

    mid(&Head, num);

    printf("After inserting in the middle region: ");
    printList(Head);

    return 0;
}