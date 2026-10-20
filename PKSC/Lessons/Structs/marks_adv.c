// WAP to store 5 students' marks and calculate the total sum and average of each students' marks, then publish.

#include <stdio.h>
#include <stdlib.h>

#define STD_COUNT 5

typedef struct student {
    int scode;
    char sname[20];
    int marks[3];
    int sum;
    float avg;
    char grade;
}STUDENT;

void find_grade(STUDENT *);

int main() {
    int i = 0;
    int j = 0;

    STUDENT s[STD_COUNT];

    printf("Enter %d students' info: \n", STD_COUNT);

    for (; i < STD_COUNT; i++) {
        printf("Student code: ");
        scanf("%d", &s[i].scode);

        printf("Student name: ");
        scanf("%s", s[i].sname);

        printf("Enter 3 marks: ");
        s[i].sum = 0;
        for (; j < 3; j++) {
            scanf("%d", &s[i].marks[j]);
            s[i].sum += s[i].marks[j];
        }
        s[i].avg = (float)s[i].sum / 3;

        find_grade(&s[i]);
        j = 0;
        printf("\n\n");
    }

    printf("\n\nResult: \n\n");
    for (i = 0; i < STD_COUNT; i++) {
        if (s[i].grade == 'f') {
            printf("%d, %s, %c\n\n", s[i].scode, s[i].sname, s[i].grade - 32);
        } else {
            printf("%d, %s, %d, %.2f, %c\n\n", s[i].scode, s[i].sname, s[i].sum, s[i].avg, s[i].grade);
        }
    }

    return 0;
}

void find_grade(STUDENT *s) {
    int i = 0;
    
    for (; i < 3; i++) {
        if (s->marks[i] < 30) {
            s->grade = 'f';
        }
    }

    if (s->grade != 'f') {
        if (s->avg < 40.0) {
            s->grade = 'F';
        } else {
            switch ((int)s->avg / 10) {
                case 4:
                case 5:
                case 6:
                    s->grade = 'D';
                    break;
                case 7:
                    s->grade = 'C';
                    break;
                case 8:
                    s->grade = 'B';
                    break;
                default:
                    s->grade = 'A';
                    break;
            }

        }
    }
}