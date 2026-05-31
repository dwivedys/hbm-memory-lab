#include <stdio.h>
#define ELEMS 1024

long dotprd (int *A, int *B, size_t n) {
    long res = 0;
    for(int i = 0; i < n; i++) {
        res += A[i] * B[i];
    }
    return res;
}

long *array_mult(int *A, int *B, long *C, size_t n) {
    for(int i = 0; i < ELEMS; i++) {
        for(int j = 0; j < ELEMS; j++) {
            C[i] += A[i] * B[j];
        }
    }
    return C;
}

int main(int argc, char *argv[]) {
    int A[ELEMS];
    int B[ELEMS];
    long C[ELEMS];
    
    /*
        A[]: [0,1,2,3,...,1021,1022, 1023]
        B[]: [1023, 1022, ... 2,1,0]
        C[]: []
    */

    for(int i = 0; i < ELEMS; i++) C[i] = 0;
    for(int i = 0; i < ELEMS; i++) A[i] = i;
    for(int i = ELEMS-1; i >= 0; i--) B[ELEMS-1 - i] = i;
    
    
    long *multres = array_mult(A, B, C, ELEMS);
    for(int i = 0; i < 10; i++) {
        printf("%d: %ld\n", i, multres[i]);
    }
    
    long res = dotprd(A, B, ELEMS);
    printf("dot product of A and B: %ld\n", res);

    char **p = argv;
    printf("num args: %d\n", argc);
    int i = 0;
    while(*p) {
        printf("%ld : %s\n", p - argv, *p);
        p++;
    }
    return 0;
}
