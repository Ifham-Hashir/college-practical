#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

// Insert a node in sorted order
void insertSorted(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;

    // If the list is empty or the new node should be at the beginning
    if (*head == NULL || (*head)->data >= data) {
        newNode->next = *head;
        if (*head != NULL)
            (*head)->prev = newNode;
        *head = newNode;
        return;
    }

    // Traverse to find the correct position for insertion
    while (temp->next != NULL && temp->next->data < data) {
        temp = temp->next;
    }

    // Insert at the end if necessary
    newNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Display the doubly linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, data;

    // Input the number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Input data and insert nodes in sorted order
    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        insertSorted(&head, data);
    }

    // Display the doubly linked list
    displayList(head);

    return 0;
}

// Enter the number of nodes: 3
// Enter data for node 1: 10
// Enter data for node 2: 20
// Enter data for node 3: 30
// Doubly Linked List: 10 <-> 20 <-> 30 <-> NULL