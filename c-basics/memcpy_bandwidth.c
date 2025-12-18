// Measures effective memory throughput using a large buffer.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

double seconds(struct timespec start, struct timespec end) {
    return (end.tv_sec - start.tv_sec) +
           (end.tv_nsec - start.tv_nsec) / 1e9;
}

int main() {
    const size_t size = 500 * 1024 * 1024; // 500MB
    char *src = malloc(size);
    char *dst = malloc(size);

    if (!src || !dst) {
        printf("Memory allocation failed\n");
        return 1;
    }

    memset(src, 1, size);

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    memcpy(dst, src, size);
    clock_gettime(CLOCK_MONOTONIC, &end);

    double t = seconds(start, end);
    double gb = size / (1024.0 * 1024.0 * 1024.0);

    printf("Copied %.2f GB in %.6f seconds\n", gb, t);
    printf("Effective bandwidth: %.2f GB/s\n", gb / t);

    free(src);
    free(dst);
    return 0;
}
