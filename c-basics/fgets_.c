#include <stdio.h>

int main() {
    char buf[10];
    while((fgets(buf, sizeof(buf), stdin)) != NULL) {
        printf("%s\n", buf);
    }
    return 0;
}