#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next; 
}Node;

Node* CreateNode()
{
    Node* NewNode = (Node*)malloc(sizeof(Node));
    int input_data;
    printf("Enter a number:");
    scanf("%d",&input_data);
    NewNode->data = input_data;

    NewNode->next = NULL;
    return NewNode;
}

Node* MergeList(Node* Node1,Node* Node2);

int main()
{
    int n=0;
    printf("How many numbers do you want in list 1:");
    scanf("%d",&n);
    if(n<=0)
    {
        printf("Invalid Input");
        exit(1);
    }
    Node* startNode1 = CreateNode();
    Node* temp = startNode1;          //Temp node which stores the n-1 node
    for(int i=1;i<n;i++)
    {
        Node* NewNode=CreateNode();
        temp->next = NewNode;        //Adding address of n-th node to n-1 node
        temp = NewNode;        
    }
    printf("How many numbers do you want in list 2:");
    scanf("%d",&n);
    if(n<=0)
    {
        printf("Invalid Input");
        exit(1);
    }
    Node* startNode2 = CreateNode();
    temp = startNode2;          //Temp node which stores the n-1 node
    for(int i=1;i<n;i++)
    {
        Node* NewNode=CreateNode();
        temp->next = NewNode;        //Adding address of n-th node to n-1 node
        temp = NewNode;        
    }
    printf("Linked List 1:\n");
    temp = startNode1;
    while (temp)
    {
        printf("%d ",temp->data);
        temp = (temp->next);
    }
    printf("\nLinked List 2:\n");
    temp = startNode2;
    while (temp)
    {
        printf("%d ",temp->data);
        temp = (temp->next);
    }
    startNode1 = MergeList(startNode1,startNode2);
    printf("\nMerged List:\n");
    temp = startNode1;
    while (temp)
    {
        printf("%d ",temp->data);
        temp = (temp->next);
    }
}

Node* MergeList(Node* HeadNode1,Node* HeadNode2)
{
    Node* temp=HeadNode1;
    Node* prev = NULL;
    while (temp)
    {
        prev = temp;
        temp = (temp->next);
    }   //at the end of the loop prev points to the last node of list 1
    prev->next = HeadNode2;
    return HeadNode1; 
}