// Write a program to calculate median for normal observation.
// Ifham Hashir

#include <stdio.h>

// Function to sort the array (using Bubble Sort for simplicity)
void sort_array(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to calculate the median
float calculate_median(float arr[], int n) {
    // Sort the array first
    sort_array(arr, n);
    
    // If the number of observations is odd, return the middle element
    if (n % 2 != 0) {
        return arr[n / 2];
    } 
    // If the number of observations is even, return the average of the two middle elements
    else {
        return (arr[(n - 1) / 2] + arr[n / 2]) / 2.0;
    }
}

int main() {
    int n;

    // Ask the user for the number of observations
    printf("Enter the number of observations: ");
    scanf("%d", &n);

    // Declare an array to store the observations
    float observations[n];

    // Input the observations
    printf("Enter the observations:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &observations[i]);
    }

    // Calculate the median
    float median = calculate_median(observations, n);

    // Display the result
    printf("The median is: %.2f\n", median);

    return 0;
}

// Output:
// Enter the number of observations: 6
// Enter the observations:
// 3 1 5 2 7 9
// The median is: 4.00