#include <stdio.h>

int main (void)
{
    int student_grade;

    printf("Please enter your grade:\n");
    scanf("%d", &student_grade);

    if (student_grade > 100 || student_grade < 0) {
        printf("Invalid input!");
    }
    else if(student_grade < 60) {
        printf("F");
    }

    else if (student_grade < 65) {
    printf("D");
    }

    else if (student_grade < 70) {
        printf("D+");
    }

    else if (student_grade < 75) {
    printf("C");
    }

    else if (student_grade < 80) {
    printf("C+");
    }

    else if (student_grade < 85) {
        printf("B");
    }

    else if (student_grade < 90) {
        printf("B+");
    }

    else if (student_grade < 95) {
        printf("A");
    }

    else {
        printf("A+");
    }

    printf("\n");
}