#include <stdio.h>
#include <stdlib.h>

typedef struct student {
    int scode;
    char sname[20];

    int mark1, mark2, mark3;
    int sum;

    struct student *next;
} STUDENT;

void grabage_collector(STUDENT *start) {
    STUDENT *temp;

    while (start != NULL) {
        temp = start;
        start = start->next;

        free(temp);
    }
}

int main() {
    STUDENT *p, *start = NULL, *temp = NULL;
    FILE *fp;
    fp = fopen("./context/std.dtb", "rb");

    p = (STUDENT *)malloc(sizeof(STUDENT));

    while (fread(p, sizeof(STUDENT), 1, fp) != 0) {
        p->next = NULL;
        if (start == NULL) {
            start = p;
        } else {
            temp = start;
            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = p;
        }

        p = (STUDENT *)(malloc(sizeof(STUDENT)));
    };

    fclose(fp);
 
    temp = start;
    while (temp != NULL) {
        printf("Student code: %d\n", temp->scode);
        printf("Student name: %s\n", temp->sname);
        printf("Marks: %d %d %d\n", temp->mark1, temp->mark2, temp->mark3);
        printf("Total: %d\n\n", temp->sum);

        temp = temp->next;
    }

    // table format
    printf("StdCode     Name          Mark 1   Mark 2   Mark 3    Total\n");
    printf("-----------------------------------------------------------\n");
    temp = start;
    while (temp != NULL) {
        printf("%-12d%-16s%-8d %-8d %-9d%d\n", temp->scode, temp->sname, temp->mark1, temp->mark2, temp->mark3, temp->sum);

        temp = temp->next;
    }
    printf("-----------------------------------------------------------");

    grabage_collector(start);
    
    return 0;
}