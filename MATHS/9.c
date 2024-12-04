//Aim: Write a program to find multiplication of two matrices.

//Theory: Matrix multiplication is an operation where the rows of the first matrix are multiplied with the columns of the second matrix, producing a new matrix, provided the number of columns in the first matrix equals the number of rows in the second matrix.

#include <stdio.h>

void multiplyMatrices(int mat1[][10], int mat2[][10], int result[][10], int r1, int c1, int c2) {
    // Initialize the result matrix to zero
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
        }
    }

    // Perform matrix multiplication
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void displayMatrix(int matrix[][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int r1, c1, r2, c2;

    // Input dimensions of the first matrix
    printf("Enter rows and columns of the first matrix: ");
    scanf("%d %d", &r1, &c1);

    // Input dimensions of the second matrix
    printf("Enter rows and columns of the second matrix: ");
    scanf("%d %d", &r2, &c2);

    // Check if multiplication is possible
    if (c1 != r2) {
        printf("Matrix multiplication not possible. Number of columns of the first matrix must equal the number of rows of the second matrix.\n");
        return 1;
    }

    int mat1[10][10], mat2[10][10], result[10][10];

    // Input elements of the first matrix
    printf("Enter elements of the first matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    // Input elements of the second matrix
    printf("Enter elements of the second matrix:\n");
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    // Multiply the matrices
    multiplyMatrices(mat1, mat2, result, r1, c1, c2);

    // Display the result
    printf("Resultant matrix after multiplication:\n");
    displayMatrix(result, r1, c2);

    return 0;
}

//Output:
// Enter rows and columns of the first matrix: 2 2
// Enter rows and columns of the second matrix: 2 2
// Enter elements of the first matrix:
// 1 2  
// 3 4
// Enter elements of the second matrix:
// 5 6
// 7 8
// Resultant matrix after multiplication:
// 19 22 
// 43 50