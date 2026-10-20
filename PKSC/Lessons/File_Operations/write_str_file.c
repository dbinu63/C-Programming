#include <stdio.h>
#include <stdlib.h>

typedef struct student {
    int scode;
    char sname[20];

    int mark1, mark2, mark3;

    int sum;

    struct student *next;
} STUDENT;

int get_max_code() {
    STUDENT p;
    FILE *fp;
    int max_code = 0;
    fp = fopen("./context/std.dtb", "rb");
    while (fread(&p, sizeof(p), 1, fp) != NULL) {
        if (p.scode > max_code) {
            max_code = p.scode;
        }
    }

    return max_code;
}

int main() {
    STUDENT p;
    FILE *fp;
    int sc;
    char ch, grade;

    fp = fopen("./context/std.dtb", "ab");

    sc = get_max_code() + 1;

    do {
        p.scode = sc++;

        printf("Student name: ");
        scanf("%s", p.sname);

        printf("Enter 3 marks: ");
        scanf("%d %d %d", &p.mark1, &p.mark2, &p.mark3);

        p.sum = p.mark1 + p.mark2 + p.mark3;

        fwrite(&p, sizeof(STUDENT), 1, fp);

        printf("Do you want more student records? (y/n): ");
        scanf(" %c", &ch);

    } while (ch == 'y');

    fclose(fp);
    return 0;
}