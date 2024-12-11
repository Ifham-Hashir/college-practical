#include <stdio.h>
#include <math.h>

// Function to calculate sums
void calculateSums(float x[], float y[], int n, float* sum_x, float* sum_y, float* sum_xy, float* sum_x2, float* sum_y2) {
    *sum_x = *sum_y = *sum_xy = *sum_x2 = *sum_y2 = 0;
    for (int i = 0; i < n; i++) {
        *sum_x += x[i];
        *sum_y += y[i];
        *sum_xy += x[i] * y[i];
        *sum_x2 += x[i] * x[i];
        *sum_y2 += y[i] * y[i];
    }
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

    float sum_x, sum_y, sum_xy, sum_x2, sum_y2;
    calculateSums(x, y, n, &sum_x, &sum_y, &sum_xy, &sum_x2, &sum_y2);

    float mean_x = sum_x / n;
    float mean_y = sum_y / n;

    float b = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
    float a = mean_y - b * mean_x;

    float d = (n * sum_xy - sum_x * sum_y) / (n * sum_y2 - sum_y * sum_y);
    float c = mean_x - d * mean_y;

    printf("\nRegression equation of y on x: y = %.4f + %.4fx\n", a, b);
    printf("Regression equation of x on y: x = %.4f + %.4fy\n", c, d);

    return 0;
}

// Enter the number of data points: 4
// Enter values of x:
// 5 10 15 20
// Enter values of y:
// 3 6 9 15

// Regression equation of y on x: y = -1.5000 + 0.7800x
// Regression equation of x on y: x = 2.2857 + 1.2381y