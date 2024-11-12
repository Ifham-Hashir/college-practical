// Write a program to calculate median for group continuous frequency distribution.
// Ifham Hashir

#include <stdio.h>

// Function to calculate the median
float calculate_median(int n, float lower[], float upper[], int freq[]) {
    int total_freq = 0;
    int cumu_freq[n];

    // Calculate total frequency and cumulative frequencies
    for (int i = 0; i < n; i++) {
        total_freq += freq[i];
        cumu_freq[i] = total_freq;
    }

    // Calculate N/2
    int half_total = total_freq / 2;

    // Find the median class (first cumulative frequency >= N/2)
    int median_class = 0;
    while (median_class < n && cumu_freq[median_class] < half_total) {
        median_class++;
    }

    // Calculate necessary values for the formula
    float L = lower[median_class];               // Lower limit of median class
    int F = (median_class == 0) ? 0 : cumu_freq[median_class - 1]; // Cumulative frequency before median class
    int f = freq[median_class];                  // Frequency of median class
    float h = upper[median_class] - lower[median_class]; // Class width

    // Apply the median formula
    return L + ((half_total - F) / (float)f) * h;
}

int main() {
    int n;

    // Input the number of classes
    printf("Enter the number of classes: ");
    scanf("%d", &n);

    // Declare arrays for lower and upper limits and frequencies
    float lower[n], upper[n];
    int freq[n];

    // Input the lower and upper limits for each class
    printf("Enter the lower limits for each class:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &lower[i]);
    }

    printf("Enter the upper limits for each class:\n");
      for (int i = 0; i < n; i++) {
        scanf("%f", &upper[i]);
    }

    // Input the frequencies for each class
    printf("Enter the frequencies for each class:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &freq[i]);
    }

    // Calculate the median
    float median = calculate_median(n, lower, upper, freq);

    // Display the result
    printf("The median is: %.2f\n", median);

    return 0;
}

// Output:
// Enter the number of classes: 8
// Enter the lower limits for each class:
// 0 5 10 15 20 25 30 35
// Enter the upper limits for each class:
// 5 10 15 20 25 30 35 40
// Enter the frequencies for each class:
// 75 250 350 192 68 35 24 6
// The median is: 12.50