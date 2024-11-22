// 2.	Write a program to perform Bubble Sort, Selection sort, Insertion sort in an array.
// Ifham Hashir

#include <stdio.h>

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i; // Find the minimum element in the unsorted part
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        // Swap arr[i] and arr[minIdx]
        int temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements that are greater than key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int n;

    // Input array size
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Input array elements
    int arr[n], arrBubble[n], arrSelection[n], arrInsertion[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        arrBubble[i] = arr[i];     // Copy for Bubble Sort
        arrSelection[i] = arr[i]; // Copy for Selection Sort
        arrInsertion[i] = arr[i]; // Copy for Insertion Sort
    }

    // Bubble Sort
    bubbleSort(arrBubble, n);
    printf("\nArray after Bubble Sort: ");
    printArray(arrBubble, n);

    // Selection Sort
    selectionSort(arrSelection, n);
    printf("Array after Selection Sort: ");
    printArray(arrSelection, n);

    // Insertion Sort
    insertionSort(arrInsertion, n);
    printf("Array after Insertion Sort: ");
    printArray(arrInsertion, n);

    return 0;
}

// Output:
// Enter the size of the array: 5
// Enter 5 elements: 64 34 25 12 22

// Array after Bubble Sort: 12 22 25 34 64 
// Array after Selection Sort: 12 22 25 34 64 
// Array after Insertion Sort: 12 22 25 34 64 