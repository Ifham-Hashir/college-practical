//Aim: Write a program to calculate semi inter quartile range for discrete frequency distribution.

//Theory:The Semi-Interquartile Range measures the spread of the middle 50% of data in a distribution. It is calculated as half the difference between the third quartile (𝑄3) and the first quartile (𝑄1).

//Formula: (Q3-Q1)/2

#include <stdio.h>

// Function to calculate cumulative frequencies
void calcCumFreq(int freq[], int cumFreq[], int n) {
    cumFreq[0] = freq[0];
    for (int i = 1; i < n; i++) {
        cumFreq[i] = cumFreq[i - 1] + freq[i];
    }
}

// Function to find quartile value
float findQuartile(float pos, int val[], int cumFreq[], int n) {
    for (int i = 0; i < n; i++) {
        if (pos <= cumFreq[i]) {
            int prevFreq = (i == 0) ? 0 : cumFreq[i - 1];
            int classFreq = cumFreq[i] - prevFreq;
            float prop = (pos - prevFreq) / classFreq;
            return val[i] + prop * (val[i + 1] - val[i]);
        }
    }
    return -1; // Error case
}

int main() {
    int n;

    // Input number of data points
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    int val[n], freq[n], cumFreq[n];

    // Input values and frequencies
    printf("Enter the values: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }

    printf("Enter the frequencies: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &freq[i]);
    }

    // Calculate cumulative frequencies
    calcCumFreq(freq, cumFreq, n);

    // Total frequency
    int totalFreq = cumFreq[n - 1];

    // Positions of Q1 and Q3
    float posQ1 = totalFreq / 4.0;
    float posQ3 = 3 * totalFreq / 4.0;

    // Find Q1 and Q3
    float Q1 = findQuartile(posQ1, val, cumFreq, n);
    float Q3 = findQuartile(posQ3, val, cumFreq, n);

    // Calculate semi-interquartile range
    float SIQR = (Q3 - Q1) / 2.0;

    // Display results
    printf("Q1: %.2f\n", Q1);
    printf("Q3: %.2f\n", Q3);
    printf("Semi-Interquartile Range: %.2f\n", SIQR);

    return 0;
}

//Output: 
// Enter the number of data points: 5
// Enter the values: 10 20 30 40 50
// Enter the frequencies: 3 5 2 4 6
// Q1: 24.00
// Q3: 41.67
// Semi-Interquartile Range: 8.83
