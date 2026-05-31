#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp = fopen("dir.c", "r");
    if(!fp) {
        perror("Error opening file");
        exit(1);
    }
    char buf[1024];
    while(fgets(buf, sizeof(buf), fp)) {
        printf("%s", buf);
    }
    fclose(fp);
    return 0;

}