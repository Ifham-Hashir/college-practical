#include <stdio.h>
#define MAX 5  // Define the maximum size of the queue

// Queue structure
struct Queue {
    int arr[MAX];
    int front, rear;
};

// Initialize the queue
void initQueue(struct Queue* q) {
    q->front = 0;
    q->rear = -1;
}

// Insert an element into the queue
void enqueue(struct Queue* q, int value) {
    q->arr[++q->rear] = value;
}

// Delete an element from the queue
int dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

// Display the queue
void display(struct Queue* q) {
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Queue queue;
    int n, value;

    initQueue(&queue);

    // Taking input for enqueue operation
    printf("Enter the number of elements to insert (max %d): ", MAX);
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value for element %d: ", i + 1);
        scanf("%d", &value);
        enqueue(&queue, value);
    }

    // Display the queue
    display(&queue);

    // Perform dequeue operation
    printf("%d deleted from the queue\n", dequeue(&queue));

    // Display the queue after deletion
    display(&queue);

    return 0;
}

// Enter the number of elements to insert (max 5): 3
// Enter value for element 1: 10
// Enter value for element 2: 20
// Enter value for element 3: 30
// Queue elements: 10 20 30 
// 10 deleted from the queue
// Queue elements: 20 30 