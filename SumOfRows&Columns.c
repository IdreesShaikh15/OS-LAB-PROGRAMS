#include <stdio.h>

int main() {
    int rows, columns, i, j;
    printf("Enter the number of rows and columns that you want to insert into the matrix: ");
    scanf("%d %d", &rows, &columns);

    int matrix[rows][columns];
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int rowsSum[rows];
    int columnsSum[columns];
    for (i = 0; i < rows; i++) {
        rowsSum[i] = 0;
        for (j = 0; j < columns; j++) {
            rowsSum[i] += matrix[i][j];
        }
    }

    for (j = 0; j < columns; j++) {
        columnsSum[j] = 0;
        for (i = 0; i < rows; i++) {
            columnsSum[j] += matrix[i][j];
        }
    }

    printf("The sum of each row is:\n");
    for (i = 0; i < rows; i++) {
        printf("Row %d: %d\n", i + 1, rowsSum[i]);
    }

    printf("The sum of each columns is:\n");
    for (j = 0; j < columns; j++) {
        printf("Column %d: %d\n", j + 1, columnsSum[j]);
    }

    return 0;
}
