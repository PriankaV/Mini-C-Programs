#include <stdio.h>
#include <stdlib.h>

int main() {
    int **matrix;
    int rows = 3;
    int columns = 4;

    //Allocate memory for rows (array of pointers)
    matrix = (int **)malloc(rows * sizeof(int *));
    if (matrix == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    //Allocate memory for each row
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(columns * sizeof(int));
        if (matrix[i] == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            return 1;
        }
    }

    //Use the matrix for operations

    //Free memory for each row
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }

    //Free memory for the array of pointers
    free(matrix);

    return 0;
}
