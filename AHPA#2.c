#include <stdio.h>
 
int main()
{
    const int numStudents = 9; //store the number of students in the class

    int seat1 = 1, seat2 = 2, seat3 = 3, seat4 = 4, seat5 = 5, seat6 = 6, seat7 = 7, seat8 = 8, seat9 = 9; //store the students' steating locations

    char name1 = 'B', name2 = 'M', name3 = 'T', name4 = 'J', name5 = 'P', name6 = 'E', name7 = 'H', name8 = 'R', name9 = 'X'; //store the students' names

    float score1 = 79.5, score2 = 82.1, score3 = 74.6, score4 = 91.1, score5 = 78.8, score6 = 97.2, score7 = 85.7, score8 = 65.4, score9 = 70.3; //store the students' scores

    printf("Number of students in the class: %d\n\n", numStudents); //print the number of students in the class

    printf("%d %c %.1f   %d %c %.1f   %d %c %.1f\n", seat1, name1, score1, seat2, name2, score2, seat3, name3, score3);
    printf("%d %c %.1f   %d %c %.1f   %d %c %.1f\n", seat4, name4, score4, seat5, name5, score5, seat6, name6, score6);
    printf("%d %c %.1f   %d %c %.1f   %d %c %.1f", seat7, name7, score7, seat8, name8, score8, seat9, name9, score9);

    return 0;
}