#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next; 
    struct Node* prev;
}Node;

Node* CreateNode()
{
    Node* NewNode = (Node*)malloc(sizeof(Node));
    int input_data;
    printf("Enter a number:");
    scanf("%d",&input_data);
    NewNode->data = input_data;

    NewNode->next = NULL;
    NewNode->prev = NULL;
    return NewNode;
}

Node* ReverseList(Node* startNode);

int main()
{
    int n=0;
    printf("How many numbers do you want:");
    scanf("%d",&n);
    if(n<=0)
    {
        printf("Invalid Input");
        exit(1);
    }
    Node* startNode = CreateNode();
    Node* temp = startNode;          //Temp node which stores the n-1 node
    for(int i=1;i<n;i++)
    {
        Node* NewNode=CreateNode();
        temp->next = NewNode;        //Adding address of n-th node to n-1 node
        NewNode->prev = temp;
        temp = NewNode;        
    }
    Node* end = temp;
    printf("Linked List:\n");
    temp = startNode;
    while (temp)
    {
        printf("%d ",temp->data);
        temp = (temp->next);
    }
    printf("\nReversed Linked List:\n");
    startNode = ReverseList(startNode);
    temp = startNode;
    while (temp)
    {
        printf("%d ",temp->data);
        temp = (temp->next);
    }
}

Node* ReverseList(Node* startNode)
{
    Node* temp = startNode;
    Node* prevNode = temp->prev;    //stores the previous node of temp
    Node* nextNode = temp->next;    //stores the next node of temp
    while (temp)
    {
        nextNode = temp->next;              //nextNode and prevNode are temp storage pointers which help to swap next and prev pointers of temp
        prevNode = temp->prev;
        temp->next=prevNode;                            //changes the next to prev and prev to next
        temp->prev=nextNode;
        startNode = temp;                               //moves along with temp to get the last node
        temp = nextNode;
    }                                //ends when temp reaches null which means startNode points to the last node of original list
    return startNode;
}