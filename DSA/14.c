#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Queue structure with front and rear pointers
struct Queue {
    struct Node *front, *rear;
};

// Initialize the queue
void initQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}

// Enqueue operation (add element to the rear of the queue)
void enqueue(struct Queue* q, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed! Cannot enqueue %d\n", value);
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) {  // If the queue is empty
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Dequeue operation (remove element from the front of the queue)
int dequeue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue underflow! Cannot dequeue\n");
        return -1;
    }

    struct Node* temp = q->front;
    int dequeuedValue = temp->data;

    q->front = q->front->next;
    if (q->front == NULL) {  // If the queue becomes empty
        q->rear = NULL;
    }
    free(temp);
    return dequeuedValue;
}

// Display the queue
void display(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    struct Node* temp = q->front;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Queue queue;
    int n, value;

    initQueue(&queue);

    // Taking input to enqueue elements
    printf("Enter the number of elements to enqueue: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter value for element %d: ", i + 1);
        scanf("%d", &value);
        enqueue(&queue, value);
    }

    // Display the queue
    display(&queue);

    // Dequeue an element
    printf("%d dequeued from the queue\n", dequeue(&queue));

    // Display the queue after dequeue
    display(&queue);

    return 0;
}

// Enter the number of elements to enqueue: 3
// Enter value for element 1: 10
// Enter value for element 2: 20
// Enter value for element 3: 30
// Queue elements: 10 20 30 
// 10 dequeued from the queue
// Queue elements: 20 30 