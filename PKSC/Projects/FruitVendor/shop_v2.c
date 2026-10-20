#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

ITEM *item_list = NULL;
ITEM *get_items();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

// function prototypes
void print_header();
void print_menu();

int get_max();
int is_exists(ITEM);

void add_item();
void show_items();

void refresh();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

// main function
int main() {
    int opt;
    char ch;

    item_list = get_items();

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
                show_items();
                break;
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
                refresh();
                exit(0);
        }

        // clears screen after each finished transcation
        // NEEDS TROUBLESHOOTING, CLEARS ALL BUT LATEST TRANSACTION
        system("clear");
    }

    return 0;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

// clears item_list
void refresh() {
    FILE *ft;
    ITEM *temp;

    ft = fopen("item_master.tbl", "w");
    temp = item_list;
    while (temp != NULL) {
        fwrite(temp, sizeof(ITEM), 1, ft);
        temp = temp->next;
    }
    fclose(ft);

    while (item_list != NULL) {
        temp = item_list;
        item_list = item_list->next;
        free(temp);
    }
}

// finds max icode in item_list for adding new items
int get_max() {
    int max_code = 0;
    ITEM *temp;
    
    temp = item_list;
    while (temp != NULL) {
        if (max_code < temp->icode) {
            max_code = temp->icode;
        }
        temp = temp->next;
    }
    return max_code;
}

// checks if item being added already exists in item_list
int is_exists(ITEM input) {
    ITEM *temp;
    temp = item_list;
    char a[50], b[50];

    strcpy(a, input.iname);
    strcpy(b, temp->iname);

    for (int i = 0; a[i]; i++)
        a[i] = tolower((char)a[i]);

    for (int i = 0; b[i]; i++)
        b[i] = tolower((char)b[i]);

    while (temp != NULL) {
        if (strcmp(a, b) == 0) {
            return 0;
        }
        temp = temp->next;
    }
    return 1;
}

int count_items() {
    int count = 0;
    ITEM *temp;
    temp = item_list;
    while (temp != NULL) {
        temp = temp->next;
        count++;
    }
    return count;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

// adds items to item_list
void add_item() {
    char ch;
    ITEM temp;
    ITEM *prev, *new_node = NULL;

    do {
        getchar();

        temp.icode = get_max() + 1;

        // gathers item details
        printf("\t\tEnter name of item: ");
        gets(temp.iname);
        printf("\t\tEnter unit of measurement: ");
        gets(temp.uom);
        printf("\t\tEnter rate per unit: ");
        scanf("%lf", &temp.rate);

        // checks if item already exists in item_list
        if (is_exists(temp) == FALSE) {
            printf("\n\n\t\tThis item already exists in the list. You cannot repeat items. ");
        } else {
            // creates new item for insertion
            new_node = (ITEM *)malloc(sizeof(ITEM));
            new_node->icode = temp.icode;
            strcpy(new_node->iname, temp.iname);
            strcpy(new_node->uom, temp.uom);
            new_node->rate = temp.rate;
            new_node->next = NULL;

            // inserts into best position in item_list
            if (item_list == NULL) {
                item_list = new_node;
            } else {
                prev = item_list;
                while (prev->next != NULL) {
                    prev = prev->next;
                }
                prev->next = new_node;
            }

            printf("\n\t\tDo you want to add another item? (y/n): ");
            scanf(" %c", &ch); // single space here, as well as getchar() above clears buffer
        }
    } while (ch == 'y');
}

// displays existing items in table format
void show_items() {
    ITEM *temp;
    temp = item_list;

    printf("\n\n\t\t code:      item:             uom:             rate:\n");
    printf("\t\t- - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    while (temp != NULL) {
        printf("\t\t%5d       %-17s %-16s %.2lf\n", temp->icode, temp->iname, temp->uom, temp->rate);
        temp = temp->next;
    }
    printf("\t\t- - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

// gathers data for item_list global variable
ITEM *get_items() {
    FILE *fs;
    ITEM *start = NULL, *new_node = NULL, *prev = NULL;
    ITEM temp;

    fs = fopen("item_master.tbl", "r");

    while (fread(&temp, sizeof(temp), 1, fs) != 0) {
        new_node = (ITEM *)malloc(sizeof(ITEM));
        new_node->icode = temp.icode;
        strcpy(new_node->iname, temp.iname);
        strcpy(new_node->uom, temp.uom);
        new_node->rate = temp.rate;
        new_node->next = NULL;

        if (start == NULL) {
            start = new_node;
        } else {
            prev = start;
            while (prev->next != NULL) {
                prev = prev->next;
            }
            prev->next = new_node;
        }
    }
    fclose(fs);
    return start;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

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