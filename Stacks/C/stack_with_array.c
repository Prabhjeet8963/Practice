#include <limits.h> 
#include <stdio.h> 
#include <stdlib.h> 
 
#define MAX_SIZE 100 
 
// A structure to represent a stack 
struct Stack { 
    int top; 
    int capacity; 
    int* array; 
}; 
 
// Function to create a stack of given capacity. It 
// initializes size of stack as 0 
struct Stack* createStack(unsigned capacity) 
{ 
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack)); 
    stack->capacity = capacity; 
    stack->top = -1; 
    stack->array= (int*)malloc(stack->capacity * sizeof(int)); 
    return stack; 
} 
 
// Stack is full when top is equal to the last index 
int isFull(struct Stack* stack) 
{ 
    return stack->top == stack->capacity - 1; 
} 
 
// Stack is empty when top is equal to -1 
int isEmpty(struct Stack* stack) 
{ 
    return stack->top == -1; 
} 
 
// Function to add an item to stack. It increases top by 1 
void push(struct Stack* stack, int item) 
{ 
    if (isFull(stack)) { 
        printf("Overflow\n"); 
        return; 
    } 
    stack->array[++stack->top] = item; 
    printf("%d pushed to stack\n", item); 
} 
 
// Function to remove an item from stack. It decreases top 
// by 1 
int pop(struct Stack* stack) 
{ 
    if (isEmpty(stack)) { 
        printf("Underflow\n"); 
        return INT_MIN; 
    } 
    return stack->array[stack->top--]; 
} 
 
// Function to return the top from stack without removing it 
int peek(struct Stack* stack) 
{ 
    if (isEmpty(stack)) { 
        printf("Stack is empty\n"); 
        return INT_MIN; 
    } 
    return stack->array[stack->top]; 
} 
 
// Function to display stack elements 
void display(struct Stack* stack) 
{ 
    if (isEmpty(stack)) { 
        printf("Stack is empty\n"); 
    } 
    else { 
        for (int i = stack->top; i >= 0; i--) { 
            printf("%d\n", stack->array[i]); 
        } 
    } 
} 
 
// Driver program to test above functions 
int main() 
{ 
    struct Stack* stack = createStack(100); 
 
    printf("Is the stack empty? %s\n", isEmpty(stack) ? "Yes" : "No");
    printf("Is the stack full? %s\n", isFull(stack) ? "Yes" : "No");
 
    push(stack, 1); 
    push(stack, 2); 
    push(stack, 3); 
 
    printf("%d popped from stack\n", pop(stack)); 
    printf("Top element is %d\n", peek(stack)); 
 
    printf("Elements present in stack:\n"); 
    display(stack); 
 
    printf("Is the stack empty? %s\n", isEmpty(stack) ? "Yes" : "No");
    printf("Is the stack full? %s\n", isFull(stack) ? "Yes" : "No");
 
    return 0; 
} 
