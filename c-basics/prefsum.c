#include <stdio.h>
#include <limits.h>


int main() {
    int arr[3] = {-1, 2, 4};
    int ps[3];
    ps[0] = arr[0];
    size_t sz = sizeof(arr)/sizeof(arr[0]);
// ps array contains the prefix sums upto each index in the original array
    for(size_t i = 1; i < sz; i++) {
        ps[i] = ps[i-1] + arr[i]; 
    }
    printf("prefix sums: ");
    
    for(int i = 1; i < sz; i++) {
        printf("%d ", ps[i]);
    }
    printf("\n");
}