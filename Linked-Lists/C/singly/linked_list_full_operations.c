#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* CreateNode() {
    Node* NewNode = (Node*)malloc(sizeof(Node));
    int input_data;
    printf("Enter a number: ");
    scanf("%d", &input_data);
    NewNode->data = input_data;
    NewNode->next = NULL;
    return NewNode;
}

Node* InsertNode(Node* startNode, int n) {
    int pos;
    Node* temp = startNode;
    printf("\nEnter the position in which you want to insert: ");
    scanf("%d", &pos);
    if (pos <= 0 || pos > n + 1) {
        printf("Invalid input\n");
        exit(1);
    }
    if (pos == 1) {
        Node* insertNode = CreateNode();
        insertNode->next = startNode;
        startNode = insertNode;
    } else {
        pos--;
        for (int i = 1; i < pos; i++) {
            temp = temp->next;
        }
        Node* insertNode = CreateNode();
        insertNode->next = temp->next;
        temp->next = insertNode;
    }
    temp = startNode;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return startNode;
}

Node* DeleteNode(Node* startNode, int n) {
    int pos;
    printf("\nEnter the position of the element you want to delete: ");
    scanf("%d", &pos);
    if (pos <= 0 || pos > n) {
        printf("Invalid input\n");
        exit(1);
    }
    Node* temp = startNode;
    if (pos == 1) {
        temp = temp->next;
        startNode = temp;
    } else {
        pos--;
        for (int i = 1; i < pos; i++) {
            temp = temp->next;
        }
        Node* DeletionNode = temp->next;
        temp->next = DeletionNode->next;
        free(DeletionNode);
    }
    temp = startNode;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return startNode;
}

void SearchNode(Node* startNode, int n) {
    int searchNum;
    printf("\nEnter the number you want to search: ");
    scanf("%d", &searchNum);
    Node* temp = startNode;
    int pos = 1;
    int searchCheck = 0;
    while (temp) {
        if (temp->data == searchNum) {
            searchCheck = 1;
            printf("Num found at position: %d\n", pos);
            break;
        }
        temp = temp->next;
        pos++;
    }
    if (searchCheck == 0) {
        printf("Num not found\n");
    }
}

int CountNodes(Node* startNode) {
    int count = 0;
    Node* temp = startNode;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

void DisplayList(Node* startNode) {
    Node* temp = startNode;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List elements: ");
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

Node* ReverseList(Node* startNode) {
    Node* prev = NULL;
    Node* current = startNode;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    startNode = prev;
    return startNode;
}

void SortList(Node* startNode) {
    if (startNode == NULL || startNode->next == NULL)
        return;
    Node* i = startNode;
    while (i != NULL) {
        Node* j = i->next;
        while (j != NULL) {
            if (i->data > j->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
            j = j->next;
        }
        i = i->next;
    }
}

Node* MergeLists(Node* h1, Node* h2) {
    if (!h1) return h2;
    if (!h2) return h1;

    Node* result = NULL;
    if (h1->data < h2->data) {
        result = h1;
        result->next = MergeLists(h1->next, h2);
    } else {
        result = h2;
        result->next = MergeLists(h1, h2->next);
    }
    return result;
}

void FindMiddle(Node* startNode) {
    if (startNode == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* slow = startNode;
    Node* fast = startNode;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("Middle element is: %d\n", slow->data);
}

int main() {
    int n = 0;
    printf("How many numbers do you want: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Invalid Input\n");
        exit(1);
    }

    Node* startNode = CreateNode();
    Node* temp = startNode;
    for (int i = 1; i < n; i++) {
        Node* NewNode = CreateNode();
        temp->next = NewNode;
        temp = NewNode;
    }

    printf("Linked List: \n");
    DisplayList(startNode);

    while (1) {
        int userChoice;
        printf("\nInput:\n1. To insert an element\n2. To delete an element\n3. To search an element\n4. To count nodes\n5. To reverse the list\n6. To sort the list\n7. To merge two lists\n8. To find the middle node\n9. To exit the program\n");
        scanf("%d", &userChoice);
        switch (userChoice) {
            case 1:
                startNode = InsertNode(startNode, n);
                n++;
                break;
            case 2:
                startNode = DeleteNode(startNode, n);
                n--;
                break;
            case 3:
                SearchNode(startNode, n);
                break;
            case 4:
                printf("Node count: %d\n", CountNodes(startNode));
                break;
            case 5:
                startNode = ReverseList(startNode);
                printf("List reversed.\n");
                DisplayList(startNode);
                break;
            case 6:
                SortList(startNode);
                printf("List sorted.\n");
                DisplayList(startNode);
                break;
            case 7: {
                Node* secondList = NULL;
                printf("Creating second list...\n");
                secondList = CreateNode();
                Node* temp2 = secondList;
                for (int i = 1; i < 3; i++) {  // Adding a few elements to the second list
                    Node* NewNode = CreateNode();
                    temp2->next = NewNode;
                    temp2 = NewNode;
                }
                startNode = MergeLists(startNode, secondList);
                printf("Lists merged.\n");
                DisplayList(startNode);
                break;
            }
            case 8:
                FindMiddle(startNode);
                break;
            case 9:
                printf("Exiting...\n");
                exit(1);
                break;
            default:
                printf("Invalid input, try again.\n");
                break;
        }
    }

    return 0;
}
