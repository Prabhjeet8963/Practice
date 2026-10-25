#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the end of the doubly linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to insert a node in the middle of the doubly linked list
void insertInMiddle(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    // If the list is empty, insert at the beginning
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* slow = *head;
    struct Node* fast = *head;

    // Use the slow and fast pointer technique to find the middle
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Insert the new node after the slow pointer (middle)
    newNode->next = slow;
    newNode->prev = slow->prev;

    if (slow->prev != NULL) {
        slow->prev->next = newNode;
    } else {
        // If slow is the head, update head
        *head = newNode;
    }
    
    slow->prev = newNode;
}

// Function to delete a node with a specific value from the doubly linked list
void deleteNode(struct Node** head, int value) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete %d.\n", value);
        return;
    }

    struct Node* current = *head;

    // Traverse the list to find the node to delete
    while (current != NULL) {
        if (current->data == value) {
            // Node found
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                // If it's the head node
                *head = current->next;
            }

            if (current->next != NULL) {
                current->next->prev = current->prev;
            }

            free(current);
            printf("Deleted %d from the list.\n", value);
            return;
        }
        current = current->next;
    }

    printf("Value %d not found in the list.\n", value);
}

// Function to search for a node with a specific value in the doubly linked list
void searchNode(struct Node* head, int value) {
    struct Node* current = head;
    int position = 0;

    while (current != NULL) {
        if (current->data == value) {
            printf("Value %d found at position %d.\n", value, position);
            return;
        }
        current = current->next;
        position++;
    }

    printf("Value %d not found in the list.\n", value);
}

// Function to display the doubly linked list
void displayList(struct Node* node) {
    struct Node* last;
    printf("Traversal in forward direction:\n");
    while (node != NULL) {
        printf("%d ", node->data);
        last = node;
        node = node->next;
    }
    
    printf("\nTraversal in reverse direction:\n");
    while (last != NULL) {
        printf("%d ", last->data);
        last = last->prev;
    }
    printf("\n");
}

// Main function to demonstrate the doubly linked list
int main() {
    struct Node* head = NULL;

    // Inserting nodes into the doubly linked list
    insertEnd(&head, 10); // Insert 10 at the end
    insertEnd(&head, 20); // Insert 20 at the end
    insertEnd(&head, 40); // Insert 40 at the end
    insertEnd(&head, 50);
    
    displayList(head);
    
 // Insert 30 in the middle
    insertInMiddle(&head, 30);
    
    // Display the doubly linked list
    displayList(head);

    // Search for a node
    searchNode(head, 20); // Search for node with value 20
    searchNode(head, 50); // Search for node with value 50

    // Delete a node
    deleteNode(&head, 20); // Delete node with value 20
    displayList(head); // Display the list after deletion

    // Free the allocated memory (optional)
    struct Node* current = head;
    struct Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    return 0;
}