#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    int freq;
    struct Node *left, *right;
};

struct MinHeap {
    int size;
    struct Node **array;
};

void swap(struct Node** a, struct Node** b) {
    struct Node* temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx, left = 2 * idx + 1, right = 2 * idx + 2;
    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq) smallest = left;
    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq) smallest = right;
    if (smallest != idx) { swap(&minHeap->array[smallest], &minHeap->array[idx]); minHeapify(minHeap, smallest); }
}

struct Node* extractMin(struct MinHeap* minHeap) {
    struct Node* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(struct MinHeap* minHeap, struct Node* node) {
    int i = minHeap->size++;
    while (i && node->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = node;
}

struct Node* buildHuffmanTree(char data[], int freq[], int size) {
    struct MinHeap* minHeap = malloc(sizeof(struct MinHeap));
    minHeap->size = size;
    minHeap->array = malloc(size * sizeof(struct Node*));
    for (int i = 0; i < size; i++) {
        struct Node* node = malloc(sizeof(struct Node));
        node->data = data[i];
        node->freq = freq[i];
        node->left = node->right = NULL;
        minHeap->array[i] = node;
    }

    for (int i = (size - 2) / 2; i >= 0; i--) minHeapify(minHeap, i);
    
    while (minHeap->size > 1) {
        struct Node *left = extractMin(minHeap), *right = extractMin(minHeap);
        struct Node* top = malloc(sizeof(struct Node));
        top->data = '$';
        top->freq = left->freq + right->freq;
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

void printHuffmanCodes(struct Node* root, int arr[], int top) {
    if (root->left) { arr[top] = 0; printHuffmanCodes(root->left, arr, top + 1); }
    if (root->right) { arr[top] = 1; printHuffmanCodes(root->right, arr, top + 1); }
    if (!(root->left || root->right)) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++) printf("%d", arr[i]);
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter number of characters: ");
    scanf("%d", &n);

    char data[n];
    int freq[n];
    
    printf("Enter the characters and their frequencies:\n");
    for (int i = 0; i < n; i++) {
        printf("Character: ");
        scanf(" %c", &data[i]);
        printf("Frequency: ");
        scanf("%d", &freq[i]);
    }
    
    struct Node* root = buildHuffmanTree(data, freq, n);
    
    int arr[100], top = 0;
    printf("\nHuffman Codes:\n");
    printHuffmanCodes(root, arr, top);
    
    return 0;
}

// Enter number of characters: 3
// Enter the characters and their frequencies:
// Character: A
// Frequency: 5
// Character: B
// Frequency: 9
// Character: C
// Frequency: 12

// Huffman Codes:
// C: 0
// A: 10
// B: 11