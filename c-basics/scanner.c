#include <stdio.h>
#include <stdlib.h>

int main() {
    char *msg = NULL;
    printf("enter a message: ");
    scanf("%s", msg);
    printf("%s\n", msg);
    
    // char name[50];
    // int age;
    // printf("Enter your name and age: ");
    // scanf("%s %d", name, &age);
    // printf("Hello %s you are %d years old\n", name, age);
    return 0;
}