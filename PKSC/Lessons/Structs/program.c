#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
    int scode;
    char sname[50];
    int mark1, mark2, mark3;
    int sum;
    float avg;

    struct Student *next;
}STUDENT ;

int main() {
    FILE *fp;
    struct Student s;
    char choice;

    fp = fopen("/week6/students.dat", "ab");

    do {
        printf("\nEnter Student ID: ");
        scanf("%d", &s.id);

        printf("Enter Student Name: ");
        scanf(" %49[^\n]", s.name);

        printf("Enter GPA: ");
        scanf("%f", &s.gpa);

        fwrite(&s, sizeof(struct Student), 1, fp);

        printf("Add another student? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    fclose(fp);

    printf("\nRecords saved successfully.\n");

    return 0;
}