#include <stdio.h>

int main() {
    int theArray[10] = {9, 1, 1, 1, 1, 1, 1, 1, 1, 1}; // Initial array values
    int *ptr = theArray;  // Pointer to the array

    // Display original array
    printf("Original array contents:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", theArray[i]);
    }
    printf("\n");

    // Insert values using pointers
    *(ptr + 3) = 101; // Inserting 101 at index 3
    *(ptr + 6) = 63;  // Inserting 63 at index 6
    *(ptr + 9) = 21;  // Inserting 21 at index 9

    // Recalculate the sum
    int sum = 0;
    for (int i = 1; i < 10; i++) {
        sum += *(ptr + i);
    }
    *ptr = sum; // Store the sum at position 0

    // Display updated array
    printf("Updated array contents:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", theArray[i]);
    }
    printf("\n");

    return 0;
}
