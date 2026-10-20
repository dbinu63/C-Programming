#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

// item struct
typedef struct inode {
    int icode;
    char iname[50];
    char uom[50];
    double rate;
    struct inode *next;
}ITEM;

// function prototypes
void print_header();
void print_menu();

int get_max(char*);

void add_item();

// main function
int main() {
    int opt;
    char ch;

    while(TRUE) {
        print_header();
        print_menu();

        // input reading
        printf("\n\n");
        printf("\t\tEnter a choice: ");
        scanf("%d", &opt);
        switch(opt) {
            case 1:
                add_item();
                break;
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
                exit(0);
                return 0;
        }
    }

    return 0;
}

// gets max icode in item master file
int get_max(char *fname) {
    int max_code = 0;
    FILE *fs;
    ITEM temp;
    fs = fopen(fname, "r");

    if (fs == NULL) {
        printf("Error in retrieving file.");
        exit(1);
        return 0; // Could not open file
    }

    while(fread(&temp, sizeof(temp), 1, fs) != 0) {
        if (max_code < temp.icode) {
            max_code = temp.icode;
        }
    }

    fclose(fs);
    return max_code;
}

// add_item function: reads input and adds, along with automatically generated icode from get_max, 
void add_item() {
    char ch;    
    FILE *ft;
    ITEM temp;
    temp.icode = get_max("item_master.tbl") + 1;

     ft = fopen("item_master.tbl", "a");
    do {
        getchar();

        printf("\t\tEnter name of item: ");
        fgets(temp.iname, sizeof(temp.iname), stdin); // change to fgets()
        printf("\t\tEnter unit of measurement: ");
        fgets(temp.uom, sizeof(temp.uom), stdin);
        printf("\t\tEnter rate per unit: ");
        gets(&temp.rate);

        fwrite(&temp, sizeof(temp), 1, ft);
        printf("Record added successfully. ");

        printf("Do you want to add another item? (y/n): ");
        scanf(" %c", &ch); // single space here, as well as getchar() above clears buffer
    } while (ch == 'y');

    fclose(ft);
}

// prints header
void print_header() {
    printf("\n\n");
    printf("\t\t- - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    printf("\t\t-                                                   -\n");
    printf("\t\t-                WHOLE FRUITS MARKET                -\n");
    printf("\t\t-                                                   -\n");
    printf("\t\t- - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
}

// prints menu
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