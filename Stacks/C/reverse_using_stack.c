#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>


#define MAX_SIZE 50

struct Stack {
    int top;
    int capacity;
    char* arr;
};

   
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    if (stack == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (char*) malloc(stack->capacity * sizeof(char));
    if (stack->arr == NULL) {
        printf("Memory allocation failed\n");
        free(stack);
        return NULL;
    }
    return stack;
}

int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}


int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}


void push(struct Stack* stack, char item) {
    if (isFull(stack)) {
        printf("Overflow: Stack is full. Cannot push %c\n", item);
        return;
    }
    stack->arr[++stack->top] = item;
    printf("%c pushed to stack\n", item);
}


char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Underflow: Stack is empty. Cannot pop\n");
        return '\0';
    }
    return stack->arr[stack->top--];
}


void reverseString(struct Stack* stack, char* str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        push(stack, str[i]);
    }
    printf("Reversed string: ");
    for (int i = 0; i < length; i++) {
        printf("%c", pop(stack));
    }
    printf("\n");
}


void reversearr(struct Stack* stack, int* arr, int size) {
    for (int i = 0; i < size; i++) {
        push(stack, arr[i] + '0');
    }
    printf("Reversed arr: ");
    for (int i = 0; i < size; i++) {
        printf("%c", pop(stack));
    }
    printf("\n");
}

int main() {
    struct Stack* stack = createStack(100);
    if (stack == NULL) {
        return 1;
    }
    int choice;
    printf("Enter your choice:\n");
    printf("1. Reverse a string\n");
    printf("2. Reverse an arr\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1: {
            char str[MAX_SIZE];
            printf("Enter a string (max %d characters): ", MAX_SIZE - 1);
            scanf(" %[^\n]", str);
            printf("Original string: %s\n", str);
            reverseString(stack, str);
            break;
        }
        case 2: {
            int size;
            printf("Enter the size of the arr: ");
            scanf("%d", &size);
            int* arr = (int*) malloc(size * sizeof(int));
            printf("Enter the elements of the arr: ");
            for (int i = 0; i < size; i++) {
                scanf("%d", &arr[i]);
            }
            printf("Original arr: ");
            for (int i = 0; i < size; i++) {
                printf("%d", arr[i]);
            }
            printf("\n");
            reversearr(stack, arr, size);
            free(arr);
            break;
        }
        default:
            printf("Invalid choice\n");
    }
    return 0;
}