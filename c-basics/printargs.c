#include <stdio.h>

int main(int argc, char *argv[]) {
    char **p = argv;
    printf("num args: %d\n", argc);
    int i = 0;
    while(*p) {
        printf("%ld : %s\n", p - argv, *p);
        p++;
    }
    return 0;
}
