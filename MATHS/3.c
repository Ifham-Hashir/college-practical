// Write a program to calculate arithmetic mean for group continuous frequency distribution.
// Ifham Hashir

#include <stdio.h>

// Function to calculate the arithmetic mean
float calculate_mean(int n, float lower_limits[], float upper_limits[], int freq[]) {
    float sum_fx = 0.0, sum_f = 0.0;
    
    // Calculate the mean using midpoint and frequency
    for (int i = 0; i < n; i++) {
        float midpoint = (lower_limits[i] + upper_limits[i]) / 2.0;
        sum_fx += freq[i] * midpoint;
        sum_f += freq[i];
    }
    
    // Return the calculated mean
    return sum_fx / sum_f;
}

int main() {
    int n;

    // Ask the user for the number of classs
    printf("Enter the number of class intervals: ");
    scanf("%d", &n);

    // Declare arrays for lower limits, upper limits, and freq
    float lower_limits[n], upper_limits[n];
    int freq[n];

    // Get the lower limits for each class
    printf("Enter the lower limits for each class interval:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &lower_limits[i]);
    }

    // Get the upper limits for each class
    printf("Enter the upper limits for each class interval:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &upper_limits[i]);
    }

    // Get the freq for each class
    printf("Enter the freq for each class interval:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &freq[i]);
    }

    // Calculate the mean
    float mean = calculate_mean(n, lower_limits, upper_limits, freq);

    // Display the result
    printf("The arithmetic mean is: %.2f\n", mean);

    return 0;
}

// Output:
// Enter the number of class intervals: 7
// Enter the lower limits for each class interval:
// 0 10 20 30 40 50 60   
// Enter the upper limits for each class interval:
// 10 20 30 40 50 60 70
// Enter the freq for each class interval:
// 6 5 8 15 7 6 3
// The arithmetic mean is: 33.40