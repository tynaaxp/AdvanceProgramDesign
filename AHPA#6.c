#include <stdio.h>
#include <stdlib.h>  // For rand() and srand()
#include <time.h>    // For time()

int main() {
    int i, j;

    // Part 1: Multiplication Table (1-12)
    printf("Multiplication Table:\n");

    // Loop through rows (1 to 12)
    for (i = 1; i <= 12; i++) {
        // Loop through columns (1 to 12)
        for (j = 1; j <= 12; j++) {
            printf("%4d", i * j); // Display the product formatted with spaces
        }
        printf("\n"); // Newline after each row
    }

    printf("\n");

    // Part 2: Number Guessing Game
    int guess, number;

    // Seed the random number generator
    srand(time(0));

    // Generate a random number between 1 and 10
    number = (rand() % 10) + 1;

    // Guessing loop
    do {
        printf("Enter your guess (1-10): ");
        scanf("%d", &guess);

        if (guess > number) {
            printf("Too high!\n");
        } else if (guess < number) {
            printf("Too low!\n");
        } else {
            printf("You guessed it!\n");
        }
    } while (guess != number); // Repeat until the guess is correct

    return 0;
}