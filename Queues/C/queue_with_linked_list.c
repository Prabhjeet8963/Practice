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

Node* Enqueue(Node* startNode);
Node* Dequeue(Node* startNode);
int Front(Node* startNode);
int Rear(Node* startNode);
int QueueSize(Node* startNode);
int isEmpty(Node* startNode);

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

    while (1)
    {
        printf("Linked List:\n");
        temp = startNode;
        while (temp)
        {
            printf("%d ",temp->data);
            temp = (temp->next);
        }
        int userChoice;
        printf("\nInput:\n1.To insert an element:\n2.To delete an element:\n3.To get the front element:\n");
        printf("4.To get the rear element:\n5.To get the Queue size\n6.To check if the Queue is empty\n0.To Exit the program:");
        scanf("%d",&userChoice);
        switch (userChoice)
        {
        case 0:
            exit(1);
        case 1:
            startNode=Enqueue(startNode);
            break;
        case 2:
            startNode=Dequeue(startNode);
            break;
        case 3:
            int front = Front(startNode);
            printf("The element in the front is:%d\n",front);
            break;
        case 4:
            int rear = Rear(startNode);
            printf("The element in the rear is:%d\n",rear);
            break;
        case 5:
            int size = QueueSize(startNode);
            printf("The size of the queue is:%d\n",size);
            break;
        case 6:
            int check = isEmpty(startNode);
            if (check==1)
            {
                printf("Yes it is empty\n");
            }
            else
            {
                printf("It is not empty\n");
            }
            break;
        default:
        printf("Invalid input,Try again");
            break;
        }
    }
}

Node* Enqueue(Node* startNode)
{
    Node* temp = startNode;
    Node* prev = NULL;
    while(temp)
    {
        prev=temp;
        temp=temp->next;
    } 
    Node* lastNode = prev;
    Node* insertNode = CreateNode();
    lastNode->next = insertNode;
    if(startNode==NULL)
    {
        //empty list
        startNode=insertNode;
        return startNode;
    }
    return startNode;
}

Node* Dequeue(Node* startNode)
{
    if(startNode==NULL)
    {
        printf("Queue Underflow:\n");
        exit(1);
    }
    Node* DeletionNode = startNode;
    startNode=startNode->next;
    free(DeletionNode);
    return startNode;
}

int Front(Node* startNode)
{
    if(startNode==NULL)
    {
        return -9999;
    }
    return startNode->data;
}
int Rear(Node* startNode)
{
    if(startNode==NULL)
    {
        return -9999;
    }
    Node* temp = startNode;
    Node* prev = NULL;
    while(temp)
    {
        prev=temp;
        temp=temp->next;
    } 
    Node* lastNode = prev;
    return lastNode->data;
}
int QueueSize(Node* startNode)
{
    int count = 0;
    Node* temp = startNode;
    while(temp)
    {
        count++;
        temp=temp->next;
    } 
    return count;
}
int isEmpty(Node* startNode)
{
    if(startNode==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}