//Write a program to calculate median for discrete frequency distribution
// Ifham Hashir

#include <stdio.h>

// Function to calculate the median
float calc_median(int obs[], int freq[], int n) {
    int cumu_freq[n];
    int total = 0;

    // Calculate total frequency and cumulative frequencies
    for (int i = 0; i < n; i++) {
        total += freq[i];
        cumu_freq[i] = total;
    }

    // Calculate N/2
    int half_total = total / 2;

    // Find the median class (the smallest observation with cumulative frequency >= N/2)
    for (int i = 0; i < n; i++) {
        if (cumu_freq[i] >= half_total) {
            return obs[i];
        }
    }

    return -1; // In case no median is found, which is unlikely
}

int main() {
    int n;

    // Ask the user for the number of observations
    printf("Enter the number of observations: ");
    scanf("%d", &n);

    // Declare arrays for observations and frequencies
    int obs[n], freq[n];

    // Input the observations
    printf("Enter the observations:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &obs[i]);
    }

    // Input the frequencies
    printf("Enter the frequencies for each observation:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &freq[i]);
    }

    // Calculate the median
    float median = calc_median(obs, freq, n);

    // Display the result
    printf("The median is: %.2f\n", median);

    return 0;
}

// Output:
// Enter the number of observations: 9
// Enter the observations:
// 0 1 2 3 4 5 6 7 8
// Enter the frequencies for each observation:
// 1 9 26 59 72 52 29 7 1
// The median is: 4.00