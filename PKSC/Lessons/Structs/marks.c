// WAP to store 5 students' marks and calculate the total sum and average of each students' marks, then publish.

#include <stdio.h>
#include <stdlib.h>

#define STD_COUNT 5

typedef struct student {
    int scode;
    char sname[20];
    int mark1, mark2, mark3;
    int sum;
    float avg;
}STUDENT;

int main() {
    int i = 0;

    STUDENT s[STD_COUNT];

    printf("Enter %d students' info: \n", STD_COUNT);

    for (; i < STD_COUNT; i++) {
        printf("Student code: ");
        scanf("%d", &s[i].scode);

        printf("Student name: ");
        scanf("%s", s[i].sname);

        printf("Enter 3 marks: ");
        scanf("%d %d %d", &s[i].mark1, &s[i].mark2, &s[i].mark3);

        s[i].sum = s[i].mark1 + s[i].mark2 + s[i].mark3;
        s[i].avg = (float)s[i].sum / 3;
    }

    printf("\n\nResult: \n\n");
    for (i = 0; i < STD_COUNT; i++) {
        printf("%d, %s, %d, %.2f\n", s[i].scode, s[i].sname, s[i].sum, s[i].avg);
    }

    return 0;
}