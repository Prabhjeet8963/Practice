#include<stdio.h>
#include<stdlib.h>
struct Node{
         int data;
         struct Node * next;
};
struct Node*head; 
void insert(int x,int n)
{
struct  Node *temp1=(struct Node*)malloc(sizeof(struct Node));
struct Node *temp2=head;
temp1->data=x;
temp1->next=NULL;
if(n==1){
    temp1->next=head;
    head=temp1;
    return;
}
for(int i=0;i<n-2;i++)
{
    temp2=temp2->next;

}
temp1->next=temp2->next;
temp2->next=temp1;
}
void print()
{
    struct Node *temp=head;
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void main()
{
    head=NULL;
    insert(10,1);
    insert(3,2);
    insert(5,3);
    print();
}