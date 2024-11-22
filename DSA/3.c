// 3.Write a program to insert and delete a new element in the middle of the one dimensional  array.

//Ifham Hashir

#include <stdio.h>

// Function to insert an element in the middle of the array
void insertInMiddle(int arr[], int n, int element) {
    int pos = n / 2; // Find the middle position
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = element;
}

// Function to delete an element from the middle of the array
void deleteFromMiddle(int arr[], int n) {
    int pos = (n - 1) / 2; // Find the middle position
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int arr[100], n, element;

    // Input the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Input the array elements
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Insert an element in the middle
    printf("Enter the element to insert in the middle: ");
    scanf("%d", &element);
    insertInMiddle(arr, n, element);
    n++; // Increment size of array after insertion
    printf("Array after insertion: ");
    printArray(arr, n);

    // Delete the middle element
    deleteFromMiddle(arr, n);
    n--; // Decrement size of array after deletion
    printf("Array after deletion: ");
    printArray(arr, n);

    return 0;
}

// Output:
// Enter the size of the array: 5
// Enter 5 elements: 10 20 30 40 50
// Enter the element to insert in the middle: 27
// Array after insertion: 10 20 27 30 40 50 
// Array after deletion: 10 20 30 40 50