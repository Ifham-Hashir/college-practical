#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a linked list with n nodes
struct Node* createLinkedList(int n) {
    if (n <= 0) return NULL; // If n is zero or negative, return NULL

    struct Node *head = NULL, *temp = NULL, *newNode;
    int value;

    // Loop to create n nodes
    for (int i = 1; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (!newNode) {
            printf("Memory allocation failed\n");
            exit(1);
        }

        printf("Enter data for node %d: ", i);
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode; // The first node becomes the head
        } else {
            temp->next = newNode; // Link the previous node to the new node
        }
        temp = newNode; // Update the temp pointer
    }

    return head;
}

// Function to display the linked list
void displayLinkedList(struct Node* head) {
    if (head == NULL) {
        printf("The linked list is empty.\n");
        return;
    }

    printf("Linked List: ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    struct Node* head = createLinkedList(n);

    displayLinkedList(head);

    return 0;
}

//Output:
// Enter the number of nodes: 3
// Enter data for node 1: 11
// Enter data for node 2: 7
// Enter data for node 3: 10
// Linked List: 11 -> 7 -> 10 -> NULL