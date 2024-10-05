// Online C compiler to run C program online
#include <stdio.h>
#include <stdio.h>
#include <string.h>

// Define a structure to store student information
struct Student {
    char name[50];
    int age;
    char uNumber[10];
    float gpa;
    char livesOnCampus[4];  // "yes" or "no"
    char hasPaid[4];        // "yes" or "no"
};

int main() {
    // Create a structure variable for one student
    struct Student student1;
    
    // Enter data into the structure variable
    printf("Enter the student's name: ");
    fgets(student1.name, sizeof(student1.name), stdin);
    // Remove newline character from the name if present
    size_t length = strlen(student1.name);
    if (length > 0 && student1.name[length - 1] == '\n') {
        student1.name[length - 1] = '\0';
    }

    printf("Enter the student's age: ");
    scanf("%d", &student1.age);
    
    printf("Enter the student's U number: ");
    scanf("%s", student1.uNumber);
    
    printf("Enter the student's GPA: ");
    scanf("%f", &student1.gpa);
    
    printf("Does the student live on campus (yes/no)? ");
    scanf("%s", student1.livesOnCampus);
    
    printf("Has the student paid for the current semester (yes/no)? ");
    scanf("%s", student1.hasPaid);

    // Copy data from student1 to student2
    struct Student student2 = student1;
    
    // Change the name, and switch the answers for where they live and if they have paid
    strcpy(student2.name, "McIntosh"); // Replace with the desired new name
    if (strcmp(student2.livesOnCampus, "yes") == 0) {
        strcpy(student2.livesOnCampus, "no");
    } else {
        strcpy(student2.livesOnCampus, "yes");
    }

    if (strcmp(student2.hasPaid, "yes") == 0) {
        strcpy(student2.hasPaid, "no");
    } else {
        strcpy(student2.hasPaid, "yes");
    }

    // Print out the current data for both students
    printf("\n--- Student 1 Information ---\n");
    printf("Name: %s\n", student1.name);
    printf("Age: %d\n", student1.age);
    printf("U Number: %s\n", student1.uNumber);
    printf("GPA: %.2f\n", student1.gpa);
    printf("Lives on Campus: %s\n", student1.livesOnCampus);
    printf("Has Paid: %s\n", student1.hasPaid);

    printf("\n--- Student 2 Information ---\n");
    printf("Name: %s\n", student2.name);
    printf("Age: %d\n", student2.age);
    printf("U Number: %s\n", student2.uNumber);
    printf("GPA: %.2f\n", student2.gpa);
    printf("Lives on Campus: %s\n", student2.livesOnCampus);
    printf("Has Paid: %s\n", student2.hasPaid);

    return 0;
}
