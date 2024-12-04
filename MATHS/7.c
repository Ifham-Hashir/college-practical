//Aim: Write a program to find mode for discrete frequency distribution.

//Theory: The mode in a discrete frequency distribution is the value that occurs most frequently, corresponding to the highest frequency in the dataset. It represents the most typical or popular value.

#include <stdio.h>

void findMode(int values[], int frequencies[], int n) {
    int maxFrequency = frequencies[0];
    int mode = values[0];

    // Loop to find the highest frequency and its corresponding value
    for (int i = 1; i < n; i++) {
        if (frequencies[i] > maxFrequency) {
            maxFrequency = frequencies[i];
            mode = values[i];
        }
    }

    printf("Mode of the distribution is: %d\n", mode);
}

int main() {
    int n;

    // Input the number of data points
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    int values[n], frequencies[n];

    // Input values and their frequencies
    printf("Enter the values: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }

    printf("Enter the frequencies: ");
    for (int i = 0; i < n; i++) {
      scanf("%d", &frequencies[i]);
    }

    // Find and display the mode
    findMode(values, frequencies, n);

    return 0;
}

//Output: 
// Enter the number of data points: 5
// Enter the values: 10 20 30 40 50
// Enter the frequencies: 3 7 4 9 5
// Mode of the distribution is: 40