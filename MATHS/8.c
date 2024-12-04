//Aim: Write a program to find mode for group continuous frequency distribution.

//Theory: The mode is the value or class interval that occurs most frequently in a dataset. For grouped data, it is calculated using a formula that identifies the modal class (class with the highest frequency) and estimates the mode considering frequencies of neighboring classes.

//Formula:

#include <stdio.h>

// Function to find the mode of grouped discrete frequency distribution
void findMode(float lowerBounds[], float upperBounds[], float frequencies[], int n) {
    int modalClassIndex = 0;
    float maxFrequency = frequencies[0];

    // Identify the modal class (class with maximum frequency)
    for (int i = 1; i < n; i++) {
        if (frequencies[i] > maxFrequency) {
            maxFrequency = frequencies[i];
            modalClassIndex = i;
        }
    }

    // Get required values for the mode formula
    float L = lowerBounds[modalClassIndex];      // Lower boundary of modal class
    float f_m = frequencies[modalClassIndex];    // Frequency of modal class
    float f_1 = modalClassIndex > 0 ? frequencies[modalClassIndex - 1] : 0; // Frequency of previous class
    float f_2 = modalClassIndex < n - 1 ? frequencies[modalClassIndex + 1] : 0; // Frequency of next class
    float h = upperBounds[modalClassIndex] - lowerBounds[modalClassIndex]; // Class width

    // Calculate the mode
    float mode = L + ((f_m - f_1) / ((f_m - f_1) + (f_m - f_2))) * h;

    // Output the mode
    printf("Mode of the distribution is: %.2f\n", mode);
}

int main() {
    int n;

    // Input the number of classes
    printf("Enter the number of classes: ");
    scanf("%d", &n);

    float lowerBounds[n], upperBounds[n], frequencies[n];

    // Input the lower bounds, upper bounds, and frequencies for the classes
    printf("Enter the lower bounds: ");
    for (int i = 0; i < n; i++) {
      scanf("%f", &lowerBounds[i]);
    }

    printf("Enter the upper bounds: ");
    for (int i = 0; i < n; i++) {
      scanf("%f", &upperBounds[i]);
    }

    printf("Enter the frequencies: ");
    for (int i = 0; i < n; i++) {
      scanf("%f", &frequencies[i]);
    }
    // Calculate and display the mode
    findMode(lowerBounds, upperBounds, frequencies, n);

    return 0;
}

//Output:
// Enter the number of classes: 10
// Enter the lower bounds: 10 20 30 40 50 60 70 80 90 100
// Enter the upper bounds: 20 30 40 50 60 70 80 90 100 110
// Enter the frequencies: 4 5 6 10 20 22 24 6 2 1
// Mode of the distribution is: 71.00