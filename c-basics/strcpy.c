#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void strcpy_(char *s, char *t) {
    while((*s++ = *t++)) {
        ;
    }
    //printf("%s\n", s);
}
int main() {
    
    char *msg = "Such a lovely day";
    char *msg_copy = strdup(msg);
    if(!msg_copy) {
        perror("Error allocating memory");
    }
    printf("%s\n", msg_copy);
    free(msg_copy);
    
    char s[15] = "Hello";
    char t[] = "World is new";
    printf("s_addr: %p t_addr: %p byte_diff: %ld\n", (void*)s, (void*)t, t - s);
    strcpy_(s, t);
    printf("%s\n", s);
    printf("%s\n", t);

    return 0;
}