#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "items.h"

struct Item *head = NULL;

//--------------------------------------------------

void addIt() {
    char cont[15], desc[100], buf[10];
    int statIn, valid = 0;
    Status stat;

    do {
        printf("Enter contact (nums only): ");
        fgets(cont, 15, stdin);
        cont[strcspn(cont, "\n")] = 0;

        if (!isNums(cont)) {
            printf("Invalid number. Try again.\n");
        }

    } while (!isNums(cont));

    printf("Enter desc: ");
    fgets(desc, 100, stdin);
    desc[strcspn(desc, "\n")] = 0;

    do {
        printf("Status (0 = CLAIMED, 1 = FOUND, 2 = LOST): ");
        fgets(buf, 10, stdin);

        if (sscanf(buf, "%d", &statIn) == 1 &&
            statIn >= 0 && statIn <= 2) {
            valid = 1;
        } else {
            printf("Invalid status. Try again.\n");
        }

    } while (!valid);

    stat = (Status)statIn;

    struct Item *node = makeNew(rand(), cont, desc, stat);

    if (!head) {
        head = node;
    } else {
        struct Item *cur = head;
        while (cur->next) cur = cur->next;
        cur->next = node;
    }
}

//--------------------------------------------------

int main() {
    char buf[10];
    int ch;

    srand(1);

    printf("Welcome to ReUnite!\n");

    while (1) {

        int valid = 0;

        do {
            printf("\n(1) Create\n(2) Search\n(3) Quit\n> ");
            fgets(buf, 10, stdin);

            if (sscanf(buf, "%d", &ch) == 1 &&
                ch >= 1 && ch <= 3) {
                valid = 1;
            } else {
                printf("Invalid option. Try again.\n");
            }

        } while (!valid);

        switch (ch) {

            case 1:
                addIt();
                break;

            case 2:
                searchItems(head);
                break;

            case 3:
                printf("Thanks for using ReUnite.\n");
                return 0;
        }
    }
}