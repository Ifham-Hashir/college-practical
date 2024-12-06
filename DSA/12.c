#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Define the maximum size of the stack

// Stack structure
struct Stack {
    int arr[MAX];
    int top;
};

// Initialize the stack
void initStack(struct Stack* stack) {
    stack->top = -1;
}

// Push an element onto the stack
void push(struct Stack* stack, int value) {
    if (stack->top == MAX - 1) {
        printf("Stack overflow! Cannot push %d\n", value);
    } else {
        stack->arr[++stack->top] = value;
        printf("%d pushed onto stack\n", value);
    }
}

// Pop an element from the stack
int pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow! Cannot pop\n");
        return -1;
    } else {
        return stack->arr[stack->top--];
    }
}

// Display the stack
void display(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = stack->top; i >= 0; i--) {
            printf("%d ", stack->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Stack stack;
    int n, value;

    initStack(&stack);

    // Perform operations
    printf("Enter elements to push onto the stack (max %d):", MAX);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);
        push(&stack, value);
    }

    printf("\nCurrent stack: ");
    display(&stack);

    printf("\nPerforming pop operation...\n");
    value = pop(&stack);
    if (value != -1) {
        printf("%d popped from stack\n", value);
    }

    printf("\nStack after pop: ");
    display(&stack);

    return 0;
}

// Enter elements to push onto the stack (max 5):3
// Enter value: 10
// 10 pushed onto stack
// Enter value: 20
// 20 pushed onto stack
// Enter value: 30
// 30 pushed onto stack

// Current stack: Stack elements: 30 20 10 

// Performing pop operation...
// 30 popped from stack

// Stack after pop: Stack elements: 20 10 