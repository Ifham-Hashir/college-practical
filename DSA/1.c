// 1.	Write a program for Linear Search and Binary Search on an array
// Ifham Hashir

#include <stdio.h>

// Linear Search function
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // Return the index where key is found
        }
    }
    return -1; // Return -1 if key is not found
}

// Binary Search function
int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid; // Return the index where key is found
        }
        if (arr[mid] < key) {
            left = mid + 1; // Key is in the right half
        } else {
            right = mid - 1; // Key is in the left half
        }
    }
    return -1; // Return -1 if key is not found
}

int main() {
    int n, key;

    // Taking the size of the array from the user
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    // Taking array elements as input from the user
    printf("Enter the elements of the array (in sorted order for Binary Search):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Taking the key to be searched from the user
    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Linear Search
    int linearResult = linearSearch(arr, n, key);
    if (linearResult != -1) {
        printf("Element found at index %d using Linear Search.\n", linearResult);
    } else {
        printf("Element not found using Linear Search.\n");
    }

    // Binary Search (for binary search, array should be sorted)
    int binaryResult = binarySearch(arr, 0, n - 1, key);
    if (binaryResult != -1) {
        printf("Element found at index %d using Binary Search.\n", binaryResult);
    } else {
        printf("Element not found using Binary Search.\n");
    }

    return 0;
}


// Output:
// Enter the number of elements in the array: 5
// Enter the elements of the array (in sorted order for Binary Search):
// 2 3 6 8 9
// Enter the element to search: 8
// Element found at index 3 using Linear Search.
// Element found at index 3 using Binary Search.