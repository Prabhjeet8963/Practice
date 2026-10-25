#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* Next;
};

void insert(struct Node** Head, int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->Next = *Head;
    *Head = temp;
}

int main() {
    int x;
    struct Node* Head = NULL;

    printf("Enter a number to insert: ");
    scanf("%d", &x);

    insert(&Head, x);
    int y;
    printf("Enter another number to insert: ");
    scanf("%d", &y);
    insert(&Head, y);

    struct Node* temp = Head;
    printf("The linked list is: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->Next;
    }
    printf("NULL\n");

    return 0;
}