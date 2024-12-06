#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Define maximum size of the stack

// Stack structure
struct Stack {
    int arr[MAX];
    int top;
};

// Initialize the stack
void initStack(struct Stack* stack) {
    stack->top = -1;  // Stack is initially empty
}

// Check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

// Check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Push an element onto the stack
void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow! Cannot push %d\n", value);
    } else {
        stack->arr[++stack->top] = value;
    }
}

// Pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Cannot pop\n");
        return -1;
    } else {
        return stack->arr[stack->top--];
    }
}

// Peek the top element of the stack
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return stack->arr[stack->top];
    }
}

// Display the stack
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= stack->top; i++) {
            printf("%d ", stack->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Stack stack;
    int n, value;

    initStack(&stack);

    // Taking input for a few elements to push onto the stack
    printf("Enter number of elements to push (max %d): ", MAX);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter value for element %d: ", i + 1);
        scanf("%d", &value);
        push(&stack, value);
    }

    // Display the stack
    display(&stack);

    // Perform pop operation
    printf("%d popped from stack\n", pop(&stack));

    // Display the stack after pop
    display(&stack);

    // Peek the top element
    printf("Top element is: %d\n", peek(&stack));

    return 0;
}

// Enter number of elements to push (max 5): 3
// Enter value for element 1: 10
// Enter value for element 2: 20
// Enter value for element 3: 30
// Stack elements: 10 20 30 
// 30 popped from stack
// Stack elements: 10 20 
// Top element is: 20