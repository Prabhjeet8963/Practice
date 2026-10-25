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

int checkPalin(Node* startNode);
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
        temp = NewNode;        
    }

    printf("Linked List:\n");
    temp = startNode;
    while (temp)
    {
        printf("%d ",temp->data);
        temp = (temp->next);
    }
    int palin = checkPalin(startNode);
    if (palin == 1)
    {
        printf("\nYes, It is a palindrome list\n");
    }
    else
    {
        printf("\nNo, It is not a palindrome list\n");
    }
    temp = startNode;
    while (temp)
    {
        printf("%d ",temp->data);
        temp = (temp->next);
    }

    return 0;
}

int checkPalin(Node* startNode)
{
    if(startNode->next==NULL)
    {
        return 1;
    }
    Node* slowPoint = startNode;
    Node* fastPoint = startNode;
    while(fastPoint->next != NULL && fastPoint->next->next != NULL)
    {
        slowPoint = slowPoint->next;        //moves 1 step at a time
        fastPoint = fastPoint->next->next;  //moves 2 steps at a time
    }   //seperates the list into 2 halfs
    Node* temp1 = startNode;
    slowPoint->next = ReverseList(slowPoint->next);             //reverse the 2nd half of the list to check palindrome
    Node* temp2 = slowPoint->next;
    while(temp2)
    {
        if(temp1->data != temp2->data)
        {
            slowPoint->next = ReverseList(slowPoint->next);     //data not equal reverse the second half and return false
            return 0;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }   //data of both halfs equal therefore palindrome, reverse and return true
    slowPoint->next = ReverseList(slowPoint->next);
    return 1; 
}
// 1 2 3 4 | 1 2 3
// 1 2 3 4 | 4 3 2 1

Node* ReverseList(Node* startNode)
{
    Node* prev = startNode;
    Node* temp = startNode->next;
    startNode->next = NULL;
    while (temp)
    {
        Node* nextNode = (temp->next);              //prev = n-1 node , temp = n node , next = n+1 node (n starts from 2nd element)
        temp->next=prev;                            //changes the next pointer of (n) to point to (n-1)
        prev = temp;
        temp = nextNode;
    }                                               //ends when temp reaches null which means prev points to the first node of new list
    startNode = prev;
    return startNode;
}
