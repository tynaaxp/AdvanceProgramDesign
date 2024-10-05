#include <stdio.h>

void switcher(int *finalExams, int size) {
    // Loop through the array using pointer arithmetic
    for (int i = 0; i < size; i++) {
        if (*(finalExams + i) >= 60 && *(finalExams + i) <= 69) {
            *(finalExams + i) += 71 - *(finalExams + i);  
        }
    }
}

int main() {
    // Given finalExams array
    int finalExams[] = {90, 82, 65, 79, 67, 82, 94, 64, 88, 78, 92, 61, 96, 83, 74};
    int size = sizeof(finalExams) / sizeof(finalExams[0]);  // Calculate the size of the array

    // Print original scores
    printf("Scores before changing:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", finalExams[i]);
    }
    printf("\n\n");

    // Call the switcher function to modify grades
    switcher(finalExams, size);

    // Print scores after changing
    printf("Scores after changing:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", finalExams[i]);
    }
    printf("\n");

    return 0;
}
