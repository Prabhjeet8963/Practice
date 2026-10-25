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

int CountNodes(Node* startNode);

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
        temp = NewNode;        
    }

    printf("Linked List:\n");
    temp = startNode;
    while (temp)
    {
        printf("%d ",temp->data);
        temp = (temp->next);
    }
    int Nodes = CountNodes(startNode);
    printf("\nNo. of Nodes = %d",Nodes);
}

int CountNodes(Node* startNode)
{
    Node* temp = startNode;
    int count = 0;
    while (temp)
    {
        count++;
        temp = (temp->next);
    }
    return count;
}