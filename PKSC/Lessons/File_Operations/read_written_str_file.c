#include <stdio.h>
#include <stdlib.h>

typedef struct student {
    int scode;
    char sname[20];

    int mark1, mark2, mark3;

    int sum;
} STUDENT;

int main() {
    STUDENT p;
    FILE *fp;
    fp = fopen("./context/std.dtb", "rb");

    while (fread(&p, sizeof(p), 1, fp) != 0) {
        printf("Student code: %d\n", p.scode);
        printf("Student name: %s\n", p.sname);
        printf("Marks: %d %d %d\n", p.mark1, p.mark2, p.mark3);
        printf("Total: %d\n\n", p.sum);
    }

    fclose(fp);
    return 0;
}