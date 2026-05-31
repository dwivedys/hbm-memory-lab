#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    //printf("%lu\n", strlen("is"));
    const char *str = "something is brewing";
    if(strstr(str, "not")) {
        printf("okay\n");
    } else {
        printf("Not okay\n");
    }
    char *name = "Saurabh";
    char *srchstr = "au";
    int l = strlen(srchstr);
    char littlestr[5];
    char *ptr = strstr(name, srchstr);
    strncpy(littlestr, ptr, l);
    //null terminate
    littlestr[l] = '\0';
    printf("littlestr: %s\n", littlestr);

    char *retval;
    retval = strstr(str, "is");
    printf("\n%s\n", retval);
    int idx = retval - str;
    printf("%.*s", (int)strlen("is"), retval);

    printf("\n");
    return 0;

}