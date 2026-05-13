#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// employee struct
typedef struct {
    int id;
    char name[50];
    float salary;
} Employee;

//--------------------------------------------------

int readInt(const char *prompt, int *out) {
    char buf[50];
    printf("%s", prompt);
    if (fgets(buf, sizeof(buf), stdin) == NULL) return 0;
    return sscanf(buf, "%d", out) == 1;
}

int readFlt(const char *prompt, float *out) {
    char buf[50];
    printf("%s", prompt);
    if (fgets(buf, sizeof(buf), stdin) == NULL) return 0;
    return sscanf(buf, "%f", out) == 1;
}

//--------------------------------------------------

void addEmp(const char *fname) {

    Employee emp;

    FILE *fp = fopen(fname, "a");
    if (fp == NULL) {
        printf("error opening file\n");
        return;
    }

    while (!readInt("Employee ID: ", &emp.id)) {
        printf("bad input, numbers only\n");
    }

    printf("Name: ");
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = 0;

    while (!readFlt("Salary: ", &emp.salary)) {
        printf("bad input, numbers only\n");
    }

    fprintf(fp, "%d %s %.2f\n", emp.id, emp.name, emp.salary);
    fclose(fp);

    printf("done\n");
}

//--------------------------------------------------

void dispEmps(const char *fname) {

    Employee emp;

    FILE *fp = fopen(fname, "r");
    if (fp == NULL) {
        printf("no file found\n");
        return;
    }

    printf("\n--- records ---\n");
    printf("ID / Name / Salary\n");

    while (fscanf(fp, "%d %s %f", &emp.id, emp.name, &emp.salary) != EOF) {
        printf("%d  %s  %.2f\n", emp.id, emp.name, emp.salary);
    }

    fclose(fp);
}

//--------------------------------------------------

int cntEmps(const char *fname) {

    Employee emp;
    int cnt = 0;

    FILE *fp = fopen(fname, "r");
    if (fp == NULL) return 0;

    while (fscanf(fp, "%d %s %f", &emp.id, emp.name, &emp.salary) != EOF) {
        cnt++;
    }

    fclose(fp);
    return cnt;
}

//--------------------------------------------------

void avgSal(const char *fname) {

    Employee emp;
    float sum = 0;
    int cnt = 0;

    FILE *fp = fopen(fname, "r");
    if (fp == NULL) {
        printf("cant open file\n");
        return;
    }

    while (fscanf(fp, "%d %s %f", &emp.id, emp.name, &emp.salary) != EOF) {
        sum += emp.salary;
        cnt++;
    }

    fclose(fp);

    if (cnt == 0) {
        printf("nothing here\n");
        return;
    }

    float avg = sum / cnt;
    printf("avg salary: %.2f\n", avg);
}

//--------------------------------------------------

void srchByID(const char *fname, int sid) {

    Employee emp;
    int found = 0;

    FILE *fp = fopen(fname, "r");
    if (fp == NULL) {
        printf("cant open file\n");
        return;
    }

    while (fscanf(fp, "%d %s %f", &emp.id, emp.name, &emp.salary) != EOF) {
        if (emp.id == sid) {
            printf("found em:\n");
            printf("ID: %d\nName: %s\nSalary: %.2f\n", emp.id, emp.name, emp.salary);
            found = 1;
            break;
        }
    }

    if (!found) printf("not found\n");

    fclose(fp);
}

//--------------------------------------------------

int main() {

    int ch, sid;
    const char *fname = "employees.txt";

    printf("Employee Management System\n");

    do {
        printf("\n1. add employee\n");
        printf("2. display all\n");
        printf("3. avg salary\n");
        printf("4. count\n");
        printf("5. search by ID\n");
        printf("6. exit\n");

        while (!readInt("> ", &ch) || ch < 1 || ch > 6) {
            printf("invalid\n");
        }

        switch(ch) {
            case 1:
                addEmp(fname);
                break;
            case 2:
                dispEmps(fname);
                break;
            case 3:
                avgSal(fname);
                break;
            case 4:
                printf("total: %d\n", cntEmps(fname));
                break;
            case 5:
                while (!readInt("enter ID: ", &sid)) {
                    printf("bad input, numbers only\n");
                }
                srchByID(fname, sid);
                break;
            case 6:
                break;
        }

    } while (ch != 6);
    return 0;
}