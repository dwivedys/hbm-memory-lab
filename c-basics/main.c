#include <stdio.h>
int main() {
    int A[] = {1,2,4};
    int B[] = {3,4,5};
    int C[3];

    for(int i = 0; i < 3; ++i) C[i] = A[i] + B[i];
    for(int i = 0; i < 3; ++i) printf("%d ", C[i]);

    printf("\n");
    return 0;
}