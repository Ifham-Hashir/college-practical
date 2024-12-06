#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Push an element onto the stack
void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Stack overflow! Cannot push %d\n", value);
        return;
    }
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
    printf("%d pushed onto stack\n", value);
}

// Pop an element from the stack
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack underflow! Cannot pop\n");
        return -1;
    }
    struct Node* temp = *top;
    int poppedValue = temp->data;
    *top = (*top)->next;
    free(temp);
    return poppedValue;
}

// Peek the top element of the stack
int peek(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

// Display the stack
void display(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    struct Node* temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* stack = NULL;
    int n, value;

    // Input elements to push onto the stack
    printf("Enter number of elements to push: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value for element %d: ", i + 1);
        scanf("%d", &value);
        push(&stack, value);
    }

    // Display the stack
    display(stack);

    // Perform pop operation
    printf("%d popped from stack\n", pop(&stack));

    // Display the stack after pop
    display(stack);

    // Peek the top element
    printf("Top element is: %d\n", peek(stack));

    return 0;
}

// Enter number of elements to push: 3
// Enter value for element 1: 10
// 10 pushed onto stack
// Enter value for element 2: 20
// 20 pushed onto stack
// Enter value for element 3: 30
// 30 pushed onto stack
// Stack elements: 30 20 10 
// 30 popped from stack
// Stack elements: 20 10 
// Top element is: 20
