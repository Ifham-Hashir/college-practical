// 4.	Write a program to perform i) Addition of Matrix ii) Multiplication of Matrix.

// Ifham Hashir

#include <stdio.h>

// Function to add two matrices
void addMatrices(int a[10][10], int b[10][10], int result[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int a[10][10], int b[10][10], int result[10][10], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// Function to print a matrix
void printMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int a[10][10], b[10][10], result[10][10];
    int rowsA, colsA, rowsB, colsB;

    // Input dimensions for matrix A
    printf("Enter rows and columns for matrix A: ");
    scanf("%d %d", &rowsA, &colsA);

    // Input dimensions for matrix B
    printf("Enter rows and columns for matrix B: ");
    scanf("%d %d", &rowsB, &colsB);

    // Input matrix A
    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Input matrix B
    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    // Addition of matrices
    if (rowsA == rowsB && colsA == colsB) {
        addMatrices(a, b, result, rowsA, colsA);
        printf("\nResult of Addition:\n");
        printMatrix(result, rowsA, colsA);
    } else {
        printf("\nAddition is not possible. Dimensions of A and B must be the same.\n");
    }

    // Multiplication of matrices
    if (colsA == rowsB) {
        multiplyMatrices(a, b, result, rowsA, colsA, colsB);
        printf("\nResult of Multiplication:\n");
        printMatrix(result, rowsA, colsB);
    } else {
        printf("\nMultiplication is not possible. Columns of A must match rows of B.\n");
    }

    return 0;
}

// Output: 
// Enter rows and columns for matrix A: 2 3
// Enter rows and columns for matrix B: 3 2
// Enter elements of matrix A:
// 1 2 3
// 4 5 6
// Enter elements of matrix B:
// 7 8
// 9 10
// 11 12

// Addition is not possible. Dimensions of A and B must be the same.

// Result of Multiplication:
// 58 64 
// 139 154 