#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <stdlib.h>

void print_header();
void print_menu();

int main() {
    print_header();
    print_menu();

    printf("Enter a choice: ");s
};

void print_header() {
    printf("\t\t- - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    printf("\t\t-                                                   -\n");
    printf("\t\t-                WHOLE FRUITS MARKET                -\n");
    printf("\t\t-                                                   -\n");
    printf("\t\t- - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
}

void print_menu() {
    printf("\n\n");
    printf("\t\tMain Menu\n");
    printf("\t\t\t1. Add Item\n");
    printf("\t\t\t2. List Items\n");
    printf("\t\t\t3. Edit Items\n");
    printf("\t\t\t4. Sale\n");
    printf("\t\t\t5. Show Sale\n");
    printf("\t\t\t6. Show Invoice\n");
    printf("\t\t\t7. Quit\n");
}