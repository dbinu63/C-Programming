/*
   Author: Don Binu
   Program: Library Book Manager
   Purpose: Demonstrates the use of structs, pointers, dynamic memory, and arrays to manage books in a library system. The program initializes static and dynamic books, prints their details, updates fields, and frees dynamically allocated memory.
   Reflection: The program works correctly, but variable names are short and a few unnecessary labels (`goto`) are used. Improvements could include more descriptive names and consistent function use.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { char t[100]; char a[100]; int yr; int pg; } Bk;

void bk_init(Bk *b, const char *t, const char *a, int yr, int pg) {
    strncpy(b->t, t, sizeof(b->t) - 1); strncpy(b->a, a, sizeof(b->a) - 1);
    b->t[sizeof(b->t) - 1] = '\0'; b->a[sizeof(b->a) - 1] = '\0';
    b->yr = yr; b->pg = pg;
}

void bk_print(const Bk *b) {
    printf("  Title  : %s\n", b->t); printf("  Author : %s\n", b->a);
    printf("  Year   : %d\n", b->yr); printf("  Pages  : %d\n", b->pg);
}

Bk *bk_new(const char *t, const char *a, int yr, int pg) {
    Bk *b = (Bk *)malloc(sizeof(Bk));
    if (b == NULL) { fprintf(stderr, "Error: malloc failed in bk_new.\n"); return NULL; }
    bk_init(b, t, a, yr, pg); return b;
}

void bk_arr_print(const Bk arr[], int sz) {
    int i = 0;
    while (i < sz) { printf("  [Book %d]\n", i + 1); bk_print(&arr[i]); printf("\n"); i++; }
}

void bk_upd(Bk *b, int pg, int yr) { b->pg = pg; b->yr = yr; }

void bk_free(Bk *b) { free(b); }

int main(void)
{
    printf("=== Static Books (Step 2 & 3) ===\n\n");

    Bk b1; b1.yr = 1997; b1.pg = 309;
    strncpy(b1.t, "Harry Potter and the Sorcerer's Stone", sizeof(b1.t) - 1);
    strncpy(b1.a, "J.K. Rowling", sizeof(b1.a) - 1);
    b1.t[sizeof(b1.t) - 1] = '\0'; b1.a[sizeof(b1.a) - 1] = '\0';

    Bk b2; b2.yr = 1998; b2.pg = 341;
    strncpy(b2.t, "Harry Potter and the Chamber of Secrets", sizeof(b2.t) - 1);
    strncpy(b2.a, "J.K. Rowling", sizeof(b2.a) - 1);
    b2.t[sizeof(b2.t) - 1] = '\0'; b2.a[sizeof(b2.a) - 1] = '\0';

    printf("[book1]\n"); printBook: bk_print(&b1);
    printf("\n[book2]\n"); goto printBook2; printBook2: bk_print(&b2);

    printf("\n=== Array of Books (Step 4 & 7) ===\n\n");

    Bk lib[5];
    bk_init(&lib[0], "Harry Potter and the Prisoner of Azkaban", "J.K. Rowling", 1999, 435);
    bk_init(&lib[1], "Harry Potter and the Goblet of Fire",      "J.K. Rowling", 2000, 734);
    bk_init(&lib[2], "Harry Potter and the Order of the Phoenix","J.K. Rowling", 2003, 870);
    bk_init(&lib[3], "Harry Potter and the Half-Blood Prince",   "J.K. Rowling", 2005, 652);
    bk_init(&lib[4], "Harry Potter and the Deathly Hallows",     "J.K. Rowling", 2007, 759);
    int libSz = 5;

    bk_arr_print(lib, libSz);

    printf("=== Dynamic Book (Steps 5 & 6) ===\n\n");

    Bk *db = bk_new("The Lightning Thief", "Rick Riordan", 2005, 377);
    if (db != NULL) { bk_print(db); }

    printf("\n=== Updating dynBook (Step 8) ===\n\n");
    printf("Before update:\n");
    bk_print(db);

    int newPg = 400; int newYr = 2006;
    bk_upd(db, newPg, newYr);

    printf("\nAfter update (pages -> %d, year -> %d):\n", newPg, newYr);
    bk_print(db);

    bk_free(db); db = NULL;
    printf("\n[dynBook memory freed successfully]\n");

    printf("\n=== Program complete ===\n");
    return 0;
}