#include <stdio.h>
#include <math.h>

// Function to calculate ranks
void calculateRanks(float arr[], int rank[], int n) {
    for (int i = 0; i < n; i++) {
        int r = 1;
        for (int j = 0; j < n; j++) {
            if (arr[j] > arr[i]) {
                r++;
            }
        }
        rank[i] = r;
    }
}

// Function to calculate Spearman's rank correlation coefficient
float spearmanCoefficient(int rank_x[], int rank_y[], int n) {
    int d2_sum = 0;
    for (int i = 0; i < n; i++) {
        int d = rank_x[i] - rank_y[i];
        d2_sum += d * d;
    }
    return 1 - ((6.0 * d2_sum) / (n * (n * n - 1)));
}

int main() {
    int n;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    float x[n], y[n];
    int rank_x[n], rank_y[n];

    printf("Enter values of x:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &x[i]);
    }

    printf("Enter values of y:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &y[i]);
    }

    calculateRanks(x, rank_x, n);
    calculateRanks(y, rank_y, n);

    float r = spearmanCoefficient(rank_x, rank_y, n);
    printf("\nSpearman's Rank Correlation Coefficient (r): %.4f\n", r);

    return 0;
}

// Enter the number of data points: 5
// Enter values of x:
// 10 20 30 40 50
// Enter values of y:
// 8 16 28 35 45

// Spearman's Rank Correlation Coefficient (r): 1.0000