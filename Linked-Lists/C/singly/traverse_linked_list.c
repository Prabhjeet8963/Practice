#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node *next;
};
void traverse(struct node *ptr) 
{
    while (ptr != NULL) 
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
void insertion_at_beg(struct node **head, int element) 
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node)); 
    new_node->data = element; 
    new_node->next = *head;   
    *head = new_node;         
}
int main() 
{
    struct node *head;
    struct node *second;
    struct node *third;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    head->data = 5;
    head->next = second;
    second->data = 9;
    second->next = third;
    third->data = 15;
    third->next = NULL;

    printf("Original linked list:\n");
    traverse(head);
    insertion_at_beg(&head, 20);
    traverse(head);
    free(head);
    free(second);
    free(third);

    return 0;
}