/*
    This program implements INSERTION SORT procedure as taught in CLRS boook
    28th May 2026
*/

#include <stdio.h>

void print_array(int *A, int n) {
    for(int i = 0; i < n; i++) printf("%d ", A[i]);
    printf("\n");
}

void insertion_sort(int *A, int n) {
    int j, key;
    for(int i = 1; i < n; i++) {
        key = A[i];
        j = i - 1;
        while(j >= 0 && A[j] > key) {
            A[j+1] = A[j];
            j = j - 1;
        }
        A[j+1] = key;
    }    
}
int main() {
    int A[] = {2,1};
    int n = sizeof(A)/sizeof(A[0]);
    printf("Original Array: ");
    print_array(A, n);
    insertion_sort(A, n);
    printf("Sorted Array  : ");
    print_array(A, n);
    return 0;
}