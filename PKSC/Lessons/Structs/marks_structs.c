#include <stdio.h>
#include <stdlib.h>

typedef struct student {
    int scode;
    char sname[20];

    int mark1, mark2, mark3;

    int sum;
    float avg;

    struct student *next;
} STUDENT;

int dround(float n) {
    int m; 
    m = n + 0.5;
    return m;
}

int main() {
    int ch;
    STUDENT *rec;
    STUDENT *start = NULL;
    STUDENT *temp = NULL;

    int ravg;
    char grade;

    do {
        // malloc, create the structure
        rec = (STUDENT *)malloc(sizeof(STUDENT));
        rec->next = NULL;

        // reading data
        printf("Student code: ");
        scanf("%d", &rec->scode);

        printf("Student name: ");
        scanf("%s", rec->sname);

        printf("Enter 3 marks: ");
        scanf("%d %d %d", &rec->mark1, &rec->mark2, &rec->mark3);

        // calc sum/avg
        rec->sum = rec->mark1 + rec->mark2 + rec->mark3;
        rec->avg = (float)rec->sum / 3;

        // linking
        if (start == NULL) {
            start = rec;
        } else {
            temp = start;
            while (temp->next != NULL) temp = temp->next;
            temp->next = rec;
        }

        printf("Do you want more student records? [y/n]");
        getchar();
        ch = getchar();
    } while (ch == 'y');

    printf("\n\nResult: \n\n");
    temp = start;
    while (temp != NULL) {
        ravg = dround(temp->avg);
        
        switch (ravg / 10) {
            case 0:
            case 1:
            case 2:
                grade = 'F';
                break;
            case 3:
            case 4:
                grade = 'C';
            case 5:
            case 6:
                grade = 'B';
                break;
            default:
                grade = 'A';
                break;
            }

        printf("%d, %s, %d, %.2f, %c\n", temp->scode, temp->sname, temp->sum, temp->avg, grade);
        temp = temp->next;
    }

    // garbage collection
    while (start != NULL) {
        temp = start;
        start = temp->next;
        free(temp);
    }

    return 0;
}