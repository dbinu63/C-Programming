#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
    int scode;
    char sname[50];
    int mark1, mark2, mark3;
    int sum;
    float avg;

    struct Student *next;
} STUDENT;

STUDENT* createStudent() {
    STUDENT * = (STUDENT*)malloc(sizeof(STUDENT));

    printf("\nEnter student code: ");
    scanf("%d", &newNode->scode);

    printf("Enter student name: ");
    scanf(" %49[^\n]", newNode->sname);

    printf("Enter mark 1: ");
    scanf("%d", &newNode->mark1);

    printf("Enter mark 2: ");
    scanf("%d", &newNode->mark2);

    printf("Enter mark 3: ");
    scanf("%d", &newNode->mark3);

    newNode->sum = newNode->mark1 + newNode->mark2 + newNode->mark3;
    newNode->avg = newNode->sum / 3.0f;

    newNode->next = NULL;

    return newNode;
}

void printStudents(STUDENT *head) {
    printf("\n--- Student Records ---\n");

    while (head != NULL) {
        printf("\nCode: %d", head->scode);
        printf("\nName: %s", head->sname);
        printf("\nMarks: %d %d %d", head->mark1, head->mark2, head->mark3);
        printf("\nSum: %d", head->sum);
        printf("\nAverage: %.2f\n", head->avg);

        head = head->next;
    }
}

int main() {
    STUDENT *head = NULL, *temp = NULL, *newNode;
    char choice;

    do {
        newNode = createStudent();

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        printf("\nAdd another student? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printStudents(head);

    return 0;
}