#include <stdio.h>

void setZeroes(int matrix[][100], int m, int n) {

    int firstRowZero = 0;

    for (int j = 0; j < n; j++) {
        if (matrix[0][j] == 0) {
            firstRowZero = 1;
            break;
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {

            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;   
                matrix[0][j] = 0;   
            }
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {

            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    if (matrix[0][0] == 0) {
        for (int i = 0; i < m; i++) {
            matrix[i][0] = 0;
        }
    }

    if (firstRowZero) {
        for (int j = 0; j < n; j++) {
            matrix[0][j] = 0;
        }
    }
}

int main() {

    int matrix[100][100];
    int m, n;

    scanf("%d %d", &m, &n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    setZeroes(matrix, m, n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}