#include <stdio.h>
#include <stdlib.h>

 int main() {
    int i, j, n, m, count = 1;
    int ** matrix;

    scanf("%d %d", &n, &m);

    matrix = (int **)malloc(sizeof(int *) * n);
    for (i = 0; i < n; i++)
       matrix[i] = (int *)malloc(sizeof(int) * m);

    for (i = 0; i < n; i++) {
       for (j = 0; j < m; j++)
          matrix[i][j] = count++;
    }

    for (i = 0; i < n; i++) {
       for (j = 0; j < m; j++)
          printf("%d ", matrix[i][j]);
       printf("\n");
    }

    for (i = 0; i < n; i++)
       free(matrix[i]);
    free(matrix);

    return 0;
 }