#ifndef ITEMS_H
#define ITEMS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    CLM,
    FND,
    LST
} Status;

struct Item {
    int id;
    char desc[100];
    char contact[15];
    Status status;
    int password;
    struct Item *next;
};

struct Item *makeNew(int id, char contact[15], char desc[100], Status status);

void searchItems(struct Item *hd);
void itPrint(struct Item *it, int idx);
int isNums(const char *s);

#endif