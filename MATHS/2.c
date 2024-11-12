// Write a program to calculate arithmetic mean for discrete frequency distribution.
// Ifham Hashir

#include <stdio.h>

float calculate_arithmetic_mean(int values[], int frequencies[], int n) {
    int sum_fx = 0, sum_f = 0;

    // Calculate total of value * frequency and sum of frequencies
    for (int i = 0; i < n; i++) {
        sum_fx += values[i] * frequencies[i];
        sum_f += frequencies[i];
    }

    // Calculate the mean
    return (float)sum_fx / sum_f;
}

int main() {
    int n;

    // Input number of values
    printf("Enter the number of values: ");
    scanf("%d", &n);

    int values[n], frequencies[n];

    // Input values and frequencies
    printf("Enter the values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }

    printf("Enter the frequencies:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &frequencies[i]);
    }

    // Calculate and display the arithmetic mean
    float mean = calculate_arithmetic_mean(values, frequencies, n);
    printf("The arithmetic mean is: %.2f\n", mean);

    return 0;
}

// Output:
// Enter the number of values: 8
// Enter the values:
// 0 1 2 3 4 5 6 7
// Enter the frequencies:
// 14 21 25 43 51 40 39 12
// The arithmetic mean is: 3.76