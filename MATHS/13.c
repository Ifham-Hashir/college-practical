#include <stdio.h>
#include <math.h>

// Function to calculate mean
float mean(float arr[], int n) {
    float sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
}

// Function to calculate Pearson's coefficient
float pearsonCoefficient(float x[], float y[], int n) {
    float mean_x = mean(x, n);
    float mean_y = mean(y, n);

    float numerator = 0.0, sum_x2 = 0.0, sum_y2 = 0.0;
    for (int i = 0; i < n; i++) {
        float diff_x = x[i] - mean_x;
        float diff_y = y[i] - mean_y;
        numerator += diff_x * diff_y;
        sum_x2 += diff_x * diff_x;
        sum_y2 += diff_y * diff_y;
    }

    return numerator / sqrt(sum_x2 * sum_y2);
}

int main() {
    int n;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    float x[n], y[n];

    printf("Enter values of x:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &x[i]);
    }

    printf("Enter values of y:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &y[i]);
    }

    float r = pearsonCoefficient(x, y, n);
    printf("\nKarl Pearson's Coefficient of Correlation (r): %.4f\n", r);

    return 0;
}

//Output
// Enter the number of data points: 5
// Enter values of x:
// 1 2 3 4 5
// Enter values of y:
// 2 4 6 8 10

// Karl Pearson's Coefficient of Correlation (r): 1.0000