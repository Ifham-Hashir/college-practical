//Aim: Write a program to find addition of two matrices

//Theory: Matrix addition involves adding corresponding elements of two matrices of the same dimensions to produce a new matrix, where each element is the sum of the respective elements from the input matrices.

#include <stdio.h>

void addMatrices(int mat1[][10], int mat2[][10], int result[][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
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
    int rows, cols;

    // Input dimensions of the matrices
    printf("Enter the number of rows and columns of the matrices: ");
    scanf("%d %d", &rows, &cols);

    int mat1[10][10], mat2[10][10], result[10][10];

    // Input elements of the first matrix
    printf("Enter elements of the first matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    // Input elements of the second matrix
    printf("Enter elements of the second matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    // Add the matrices
    addMatrices(mat1, mat2, result, rows, cols);

    // Display the result
    printf("Resultant matrix after addition:\n");
    displayMatrix(result, rows, cols);

    return 0;
}

//Output: 
// Enter the number of rows and columns of the matrices: 2 2
// Enter elements of the first matrix:
// 1 2
// 3 4
// Enter elements of the second matrix:
// 5 6
// 7 8
// Resultant matrix after addition:
// 6 8 
// 10 12 