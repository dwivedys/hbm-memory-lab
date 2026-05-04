#include <stdio.h>
#include <string.h>

int main() {
    
    char buf[20];
    memset(buf, 'X', 20);
    printf("%s", buf);
    printf("\n");

    memset(buf, 'A', 10);
    printf("%s", buf);
    printf("\n");

    memset(buf + (20 - 10), 'B', 10);
    printf("%s", buf);
    printf("\n");

    
    int arr[5];
    memset(arr, 1, 5);
    for(int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}