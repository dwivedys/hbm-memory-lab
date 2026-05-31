#include <stdio.h>
int fib2(int n) {
    if(n < 1) return -1;
    int fibresults[n+1];
    fibresults[0] = 0;
    fibresults[1] = 1;
    int k = 2;
    while (k <= n) {
        fibresults[k] = fibresults[k-1] + fibresults[k-2];
        k++;
    }
    return fibresults[n];

}

int fib(int n) {
    if (n < 1) return -1;
    if (n == 0 || n == 1) return n;
    return fib(n-1) + fib(n-2);
}
// 1  2  3  4  5  6  7  8,  9
// 0, 1, 1, 2, 3, 5, 8, 13, 21
int main() {
    int num = 0;
    printf("fib: fib(%d): %d\n", num, fib(num-1));
    printf("fib2: fib(%d): %d\n", num, fib2(num));
    return 0;
}