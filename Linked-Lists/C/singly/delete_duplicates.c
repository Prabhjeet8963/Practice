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

Node* deleteDuplicates(Node* startNode);

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
    startNode = deleteDuplicates(startNode);
    printf("\nLinked List with Duplicates Deleted:\n");
    temp = startNode;
    while (temp)
    {
        printf("%d ",temp->data);
        temp = (temp->next);
    }
}

Node* deleteDuplicates(Node* startNode)
{
    Node* index = startNode;
    Node* temp = startNode->next;
    while(index != NULL)
    {
        int index_data = index->data;
        Node* prev = index;
        temp = index->next;
        while(temp)
        {
            if (temp->data == index_data)   //Remove the temp node
            {
                Node* RemovalNode = temp;
                prev->next=temp->next;
                temp = prev->next;
                free(RemovalNode);
                continue;
            }
            prev = prev->next;
            temp = temp->next;
        }
        index = index->next;
    }
    return startNode;
}