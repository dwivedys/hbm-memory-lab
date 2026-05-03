#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int secretNumber = 5;
    int guess;
    int times = 0;
    printf("Enter your guess; enter 'q' to quit: ");
    while(times < 3) {
        scanf("%d", &guess);
        if(strcmp(guess, 'q')) return 0;
        if(guess == secretNumber) {
            printf("Congratulations you guessed correctly\n");
            return 0;
        }
        times++;
        printf("Try again: ");
    }
    printf("You could not guess the right number in time\n");
    return 0;
}