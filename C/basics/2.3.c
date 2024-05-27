#include <stdio.h>
void sparse_to_3tuple(int mat[][100], int rows, int cols) {
    int sparse[100][3]; 
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] != 0) {
                sparse[count][0] = i;
                sparse[count][1] = j;
                sparse[count][2] = mat[i][j];
                count++;
            }
        }
    }
    printf("3-Tuple Representation:\n");
    for (int i = 0; i < count; i++) {
        printf("%d %d %d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
}
int main() {
    int rows, cols;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    int matrix[100][100];
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    sparse_to_3tuple(matrix, rows, cols);
    return 0;
}