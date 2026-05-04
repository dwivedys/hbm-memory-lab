#include <stdio.h>
#include <string.h>

int main() {
    int a = 512;
    printf("%02x", a);
    printf("\n");

    unsigned char* p = (unsigned char *)&a;
    for(int i = 0; i < sizeof(a); i++) {
        printf("%02x ", p[i]);
    }
    printf("\n");

    return 0;
}