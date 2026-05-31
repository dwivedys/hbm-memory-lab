#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_arr(char **arr, int elems) {
    for(int i = 0; i < elems; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");
}

int main() {
    
    char a[] = "apple";
    char b[] = "banana";
    char c[] = "cherry";
    char d[] = "doughnut";
    char *fruits[] = {a, b, c, d};
    char **p = fruits;
    
    int sz = sizeof(fruits)/sizeof(fruits[0]);
    printf("num elems in fruits array: %d\n", sz);
    
    // print array
    print_arr(fruits, sz);

    // populate new array
    char *buff[sz]; // an array to hold sz pointers to char strings
    for(int i = 0; i < sz; i++) {
        buff[i] = p[i];
    } 

    // print buff elems
    print_arr(buff, sz);
    
    // now modify the first element of buff and see the first element of fruits also change
    //buff[0] = "Bell Bottom";
    strncpy(buff[0], "Bell Bottom", strlen("Bell Bottom") + 1);
    print_arr(fruits, sz);
    print_arr(buff, sz);

    return 0;
}