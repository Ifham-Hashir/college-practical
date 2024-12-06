#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Display the linked list
void displayList(struct Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Insert functions
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data), *temp = *head;
    if (!*head) { *head = newNode; return; }
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

void insertInMiddle(struct Node* head, int pos, int data) {
    struct Node* newNode = createNode(data), *temp = head;
    for (int i = 1; i < pos - 1 && temp->next; i++) temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete functions
void deleteFromBeginning(struct Node** head) {
    if (*head) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void deleteFromEnd(struct Node** head) {
    if (*head) {
        struct Node *temp = *head, *prev = NULL;
        while (temp->next) { prev = temp; temp = temp->next; }
        if (!prev) *head = NULL; else prev->next = NULL;
        free(temp);
    }
}

void deleteFromMiddle(struct Node** head, int pos) {
    struct Node *temp = *head, *prev = NULL;
    for (int i = 1; i < pos && temp; i++) { prev = temp; temp = temp->next; }
    if (temp) { prev->next = temp->next; free(temp); }
}

// Function to take input for the linked list
void takeInput(struct Node** head, int n) {
    int data;
    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i+1);
        scanf("%d", &data);
        insertAtEnd(head, data);
    }
}

int main() {
    struct Node* head = NULL;
    int n, data, pos;

    // Input the number of nodes
    printf("Enter the number of nodes in the linked list: ");
    scanf("%d", &n);

    // Take input for the linked list
    takeInput(&head, n);

    // Display the linked list
    printf("Linked List: ");
    displayList(head);

    // Insertions
    printf("Enter data to insert at the beginning: ");
    scanf("%d", &data);
    insertAtBeginning(&head, data);
    printf("Linked List after insertion at beginning: ");
    displayList(head);

    printf("Enter data to insert at the end: ");
    scanf("%d", &data);
    insertAtEnd(&head, data);
    printf("Linked List after insertion at end: ");
    displayList(head);

    // Insert in the middle
    printf("Enter position to insert in the middle: ");
    scanf("%d", &pos);
    printf("Enter data to insert in the middle: ");
    scanf("%d", &data);
    insertInMiddle(head, pos, data);
    printf("Linked List after insertion in middle: ");
    displayList(head);

    // Deletions
    deleteFromBeginning(&head);
    printf("Linked List after deleting from beginning: ");
    displayList(head);

    deleteFromEnd(&head);
    printf("Linked List after deleting from end: ");
    displayList(head);

    printf("Enter position to delete from middle: ");
    scanf("%d", &pos);
    deleteFromMiddle(&head, pos);
    printf("Linked List after deleting from middle: ");
    displayList(head);

    return 0;
}

//Output: 
// Enter the number of nodes in the linked list: 3
// Enter data for node 1: 10
// Enter data for node 2: 20
// Enter data for node 3: 30
// Linked List: 10 -> 20 -> 30 -> NULL
// Enter data to insert at the beginning: 5
// Linked List after insertion at beginning: 5 -> 10 -> 20 -> 30 -> NULL
// Enter data to insert at the end: 7
// Linked List after insertion at end: 5 -> 10 -> 20 -> 30 -> 7 -> NULL
// Enter position to insert in the middle: 3
// Enter data to insert in the middle: 25
// Linked List after insertion in middle: 5 -> 10 -> 25 -> 20 -> 30 -> 7 -> NULL
// Linked List after deleting from beginning: 10 -> 25 -> 20 -> 30 -> 7 -> NULL
// Linked List after deleting from end: 10 -> 25 -> 20 -> 30 -> NULL
// Enter position to delete from middle: 4
// Linked List after deleting from middle: 10 -> 25 -> 20 -> NULL