#include <stdio.h>
#define max 3

void floyd_warshall(int mat[max][max]) {
    for (int k = 0; k < max; k++) {
        for (int i = 0; i < max; i++) {
            for (int j = 0; j < max; j++) {
                if (i == j) {
                    mat[i][j] = 0;
                }
                else {
                    int a = mat[i][j];
                    int b = mat[i][k] + mat[k][j];
                    if (a < b) {
                        mat[i][j] = a;
                    }
                    else {
                        mat[i][j] = b;
                    }
                     
                }
            }
        }
    }
}

void main() {
    int mat[max][max] = 
    {{999,5,999},
    {999,999,1},
    {2,999,999}};
    floyd_warshall(mat);
    for (int i = 0; i < max; i++) {
        for (int j = 0; j < max; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}