#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 30
typedef struct {
    int z;
    char data[];
} mydata;

mydata *print_chars(char *txt) {
    mydata *d = malloc(sizeof(mydata) + 100);
    char *start = txt;
    int l = 0;
    while(*txt) {
        printf("%c ", *txt);
        txt++, l++;
    }
    // printf("\n");
    // printf("num chars %d\n", l);
    d->z = l;
    strcpy(d->data, start);
    printf("txt: %s\n", d->data);
    return d;
}

unsigned int hash(char *txt) {
    unsigned int hash = 5381;
    int c;

    while((c = *txt++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % SIZE;
}
int main() {
    char *n = "Saurabh";
    printf("hash of %s is %u\n", n, hash(n));
    mydata *md;
    md = print_chars(n);
    printf("text: %s\n", md->data);
    printf("length: %d\n", md->z);
    return 0;
}