#include <stdio.h>

int main() {
/*
    1 2 3   1 2 3
    4 5 6   4 5 6
    7 8 9   7 8 9 

    1 * 1 + 2 * 4 + 3 * 7               = 30
    4 * 1 + 5 * 4 + 6 * 7               = 66
    7 * 1 + 8 * 4 + 9 * 7 = 7 + 32 + 63 = 102
*/
    int A[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int B[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int C[3][3] = {0};

    for(int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                C[i][j] += A[i][k] * B[k][j];
            } 
        }
    }

    printf("Printing resultant matrix of the matrix multiplication:\n");
    for(int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", C[i][j]); // row major
        }
    }
    printf("\n");

    return 0;

}