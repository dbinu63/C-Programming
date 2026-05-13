#include <stdio.h>

int main() {
    int grade;

    printf("Enter a grade to convert to letter format: ");
    while (!scanf(" %d", &grade) || grade > 100 || grade < 0) {
        printf("There was a problem with the input you entered. Please try again: ");
        while (getchar() != '\n');
    }

    grade = --grade / 10;

    switch (grade) {
        case 9: 
            printf("The grade is an A");
            break;
        case 8: 
            printf("The grade is an B");
            break;
        case 7: 
            printf("The grade is an C");
            break;
        case 6: 
            printf("The grade is an D");
            break;
        default: 
            if (grade >= 3) {
                printf("The grade is lower than a D, but passing. ");
            } else {
                printf("The grade is lower than a D, and failing. ");
            }
    }

    return 0;
}