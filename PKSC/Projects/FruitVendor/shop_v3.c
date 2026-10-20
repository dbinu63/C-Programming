// Input validation mostly secure, may be small holes present, needs thorough review

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

// item structs
typedef struct my_date {
    int dd;
    int mm;
    int yy;
}MDATE;

typedef struct inode {
    int icode;
    char iname[50];
    char uom[50];
    double rate;
    struct inode *next;
}ITEM;

typedef struct smnode {
    int inv_no;
    MDATE dt;
    char cust_name[50];
    int item_count;
    double gross;
    double discount;
    double net;
    struct smnode *next;
}SMASTER;

typedef struct sdnode {
    int inv_no;
    int sl;
    int icode;
    double rate;
    int qty;
    int tot;
    struct sdnode *next;
}SDETAIL;

ITEM *item_list = NULL;
ITEM *get_items();

SMASTER *sales_master = NULL;
SMASTER *get_sales_master();

SDETAIL *sales_detail = NULL;
SDETAIL *get_sales_detail();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

// function prototypes
void print_header();
void print_menu();

int get_max(char *str);
void lcase(char *);
int compare(char *, char *);
void copy(char *, char *);
int is_exists(char *);

void add_item();
void show_items();
ITEM get_item_info(char *str);
// void edit_item();
// void delete_item();
void sales();
void show_sales();
void show_invoice();

void update_db();
void load_db();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

// main function
int main() {
    int opt;
    char ch;

    load_db();

    while(TRUE) {
        print_header();
        print_menu();

        // input reading
        printf("\n\n");
        printf("\t\tEnter a choice: ");
        while (scanf("%d", &opt) != 1 || opt < 1 || opt > 8) {
            printf("\n\t\tInvalid selection. Please try again: ");
            while (getchar() != '\n');
        }

        switch(opt) {
            case 1:
                add_item();
                break;
            case 2:
                show_items();
                break;
            case 3:
                // edit_item();
                break;
            case 4:
                //delete_item();
                printf("\n***The delete function is not yet complete.***\n");
                break;
            case 5:
                sales();
                break;
            case 6:
                show_sales();
                break;
            case 7:
                show_invoice();
                break;
            case 8:
                update_db();
                exit(0);
            default:
                break;
        }
    }

    return 0;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

// clears item_list
void update_db() {
    FILE *ft;
    ITEM *temp;
    SMASTER *smtemp;
    SDETAIL *sdtemp;

    // updating item_master.tbl
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

    // updating system_master.tbl
    ft = fopen("sales_master.tbl", "w");
    smtemp = sales_master;
    while (smtemp != NULL) {
        fwrite(smtemp, sizeof(SMASTER), 1, ft);
        smtemp = smtemp->next;
    }
    fclose(ft);

    while (sales_master != NULL) {
        smtemp = sales_master;
        sales_master = sales_master->next;
        free(smtemp);
    }

    // updating system_detail.tbl
    ft = fopen("sales_detail.tbl", "w");
    sdtemp = sales_detail;
    while (sdtemp != NULL) {
        fwrite(sdtemp, sizeof(SDETAIL), 1, ft);
        sdtemp = sdtemp->next;
    }
    fclose(ft);

    while (sales_detail != NULL) {
        sdtemp = sales_detail;
        sales_detail = sales_detail->next;
        free(sdtemp);
    }
}

// finds max icode in item_list for adding new items
int get_max(char *str) {
    int max_code = 0;
    ITEM *temp;
    SMASTER *smtemp;
    SDETAIL *sdtemp;
    
    if (compare(str, "item") == TRUE) {
        temp = item_list;
        while (temp != NULL) {
            if (max_code < temp->icode) {
                max_code = temp->icode;
            }
            temp = temp->next;
        }
    }

    if (compare(str, "sales") == TRUE) {
        smtemp = sales_master;
        while (smtemp != NULL) {
            if (max_code < smtemp->inv_no) {
                max_code = smtemp->inv_no;
            }
            smtemp = smtemp->next;
        }
    }

    if (compare(str, "details") == TRUE) {
        sdtemp = sales_detail;
        while (sdtemp != NULL) {
            if (max_code < sdtemp->inv_no) {
                max_code = sdtemp->inv_no;
            }
            sdtemp = sdtemp->next;
        }
    }


    return max_code;
}

void lcase(char *str) {
    int i = 0;

    while (str[i] != '\0') {
        str[i] = tolower(str[i]);
        i++;
    }
}

int compare (char *s, char *t) {
    int i = 0;

    while (s[i] != '\0' && t[i] != '\0') {
        if (s[i] != t[i]) {
            return FALSE;
        }
        i++;
    }

    if (s[i] == '\0' && t[i] == '\0') {
        return TRUE;
    } else {
        return FALSE;
    }
}

void copy(char *s, char *t) {
    int i = 0;

    while (s[i] != '\0') {
        t[i] = s[i];
        i++;
    }
    t[i] = '\0';
}

// checks if item being added already exists in item_list
// INCOMPLETE
int is_exists(char *str) {
    ITEM *temp = item_list;

    lcase(str);

    while (temp != NULL) {
        lcase(temp->iname);

        if (compare(str, temp->iname) == TRUE) {
            printf("\n\t\t%5d       %-17s %-16s %.2lf\n", temp->icode, temp->iname, temp->uom, temp->rate);
        temp = temp->next;
            return TRUE;
        }
        temp = temp->next;
    }
    return FALSE;
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

        temp.icode = get_max("item") + 1;

        // gathers item details
        printf("\t\tEnter name of item: ");
        gets(temp.iname);
        printf("\t\tEnter unit of measurement: ");
        gets(temp.uom);
        printf("\t\tEnter rate per unit: ");
        scanf("%lf", &temp.rate);

        // checks if item already exists in item_list
        if (is_exists(temp.iname) == TRUE) {
            printf("\n\n\t\tThis item already exists in the list. You cannot repeat items. \n");
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
        }
        printf("\n\t\tDo you want to add another item? (y/n): ");
        scanf(" %c", &ch); // single space here, as well as getchar() above clears buffer
        lcase(&ch);

        while (ch != 'y' && ch != 'n') {
            printf("\n\t\tUnknown input: %c. Please try again. Would you like to add another item? (y/n): ", ch);
            while (getchar() != '\n');
            scanf(" %c", &ch);
            lcase(&ch);
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

ITEM get_item_info(char *str) {
    ITEM *temp = item_list;
    ITEM empty = {0, "", "", 0.0, NULL};
    
    lcase(str);

    while (temp != NULL) {
        lcase(temp->iname);

        if (compare(str, temp->iname) == TRUE) {
            return *temp;
        }

        temp = temp->next;
    }

    printf("\n\t\tItem does not exist or could not be found: %s", str);
    return empty;
}

/* REQUIRES SOME EDITING - SHOULD NOT ACTUALLY DELETE ITEM (change visibility bool)
void edit_item() {
    ITEM *temp = item_list;
    char str[50];

    printf("Enter the name of the item you want to edit: ");
    gets(str);
    lcase(str);

    // switch to is_exist() func, no need to check here
    while (temp != NULL) {
        lcase(temp->iname);

        if (compare(str, temp->iname) == TRUE) {
            printf("\n\t\tEditing item: %s, %s, %lf\n", temp->iname, temp->uom, temp->rate);

            printf("\n\t\tEnter new rate per unit: ");
            scanf("%lf", &temp->rate);

            printf("\n\t\tItem successfully edited.\n");

            return;
        }
        temp = temp->next;
    }

    printf("\n\t\tItem does not exist: %s\n", str);
}

void delete_item() {
    char name[50];
    char ch;
    ITEM *temp = item_list;
    ITEM *prev = NULL;

    show_items();

    printf("\n\t\tEnter the name of the item you want to delete: ");
    gets(&name);
    lcase(name);

    // search for item
    while (temp != NULL) {
        lcase(temp->iname);
        if (compare(temp->iname, name) == TRUE) {

            printf("Are you sure you want to delete item: %s, %s, %lf? (y/n)\n", temp->iname, temp->uom, temp->rate);
            scanf("%c", &ch);
            lcase(&ch);

            if (ch != 'y') {
                printf("Deletion interrupted.");
                return;
            }

            if (prev == NULL) {
                item_list = temp->next;
            }
            else {
                prev->next = temp->next;
            }

            free(temp);

            printf("\n\t\tItem successfully deleted.\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("\n\t\tItem with name %s does not exist.\n", name);
}
*/

void sales() {
    char ch, item[50], customer[50];
    ITEM item_info;
    int qty, new_inv_no = 0, sl_no = 0;
    double tot_amt = 0, gross = 0, disc = 0, net = 0; 
    // setting sdtemp as pointer is helpful, since you will be using it twice
    SDETAIL *sdtemp = NULL, *start_detail = NULL, *prev_detail = NULL;
    SMASTER *smtemp = NULL, *start_master = NULL, *prev_master = NULL;

    new_inv_no = get_max("sales") + 1;

    do {
        getchar();
        sl_no++;

        printf("\n\t\tEnter item name: ");
        gets(item);

        item_info = get_item_info(item);

        // if item DNE
        while (item_info.icode == 0) {
            sl_no--;

            printf("\n\t\tInvalid selection. Please enter a valid item: ");
            gets(item);
            
            item_info = get_item_info(item);
        }

        printf("\n\t\tUOM: %s", item_info.uom);
        printf("\n\t\tUnit Price: %0.2lf", item_info.rate);

        printf("\n\n\t\tEnter quantity: ");
        scanf(" %d", &qty);

        if (qty > 0) {
            tot_amt = item_info.rate * qty;
            gross += tot_amt;

            printf("\n\t\t- - - - - - - - - - - - - - - Total Amount: %lf", tot_amt);
            printf("\n\t\t- - - - - - - - - - - - - - - - - - - - Gross: %lf", gross);

            sdtemp = (SDETAIL *)malloc(sizeof(SDETAIL));
            sdtemp->inv_no = new_inv_no;
            sdtemp->sl = sl_no;
            sdtemp->icode = item_info.icode;
            sdtemp->rate = item_info.rate;
            sdtemp->qty = qty;
            sdtemp->tot = tot_amt;
            sdtemp->next = NULL;

            if (start_detail == NULL) {
                start_detail = sdtemp;
            } else {
                prev_detail = start_detail;
                while (prev_detail->next != NULL) {
                    prev_detail = prev_detail->next;
                }

                prev_detail->next = sdtemp;
            }
            printf("\n\n");
        } else {
            printf("\n\t\tInvalid quantity.");
        }
        while (getchar() != '\n');
        printf("\t\tDo you want more items? (y/n): ");
        scanf(" %c", &ch);

        while (ch != 'y' && ch != 'n') {
            printf("\n\t\tUnkown input: %c. Please try again. Would you like to add another item? (y/n)", ch);
            while (getchar() != '\n');
            scanf(" %c", &ch);
            lcase(&ch);
        }
    } while (ch == 'y');

    printf("\n\n\t\tEnter discount, if any: ");
    scanf("%lf", &disc);

    net = gross - disc;

    printf("\n\t\t- - - - - - - - - - - - - - - - - - - - - - - - - - -");
    printf("\n\t\tGross: %-2lf", gross);
    printf("\n\t\tDiscount: %-2lf", disc);
    printf("\n\t\tNet: %-2lf", net);
    printf("\n\t\t- - - - - - - - - - - - - - - - - - - - - - - - - - -");

    smtemp = (SMASTER *)malloc(sizeof(SMASTER));

    smtemp->inv_no = new_inv_no;
    // smtemp->dt = dt;
    smtemp->item_count = sl_no;
    smtemp->gross = gross;
    smtemp->discount = disc;
    smtemp->net = net;
    smtemp->next = NULL;

    printf("\n\t\tEnter customer name: ");
    getchar();
    gets(customer);

    strcpy(smtemp->cust_name, customer);

    printf("\n\n\t\tComplete transaction? (y/n): ");
    scanf(" %c", &ch);
    lcase(&ch);

    while (ch != 'y' && ch != 'n') {
        printf("\n\t\tUnkown input: %c. Please try again. Would you like to complete the transaction? (y/n)", ch);
        while (getchar() != '\n');
        scanf(" %c", &ch);
        lcase(&ch);
    }

    if (ch == 'y') {

        // Move temporary sdetail list to global sales_detail list
        if (sales_detail == NULL) {
            sales_detail = start_detail;
        } else {
            prev_detail = sales_detail;

            while (prev_detail->next != NULL) {
                prev_detail = prev_detail->next;
            }

            prev_detail->next = start_detail;
        }

        // move temporary smaster node to global sales_master list
        if (sales_master == NULL) {
            sales_master = smtemp;
        } else {
            prev_master = sales_master;

            while (prev_master->next != NULL) {
                prev_master = prev_master->next;
            }

            prev_master->next = smtemp;
        }

        printf("\n\t\tBill processed. ");
        printf("\n\t\tThank you, visit again.");

    } else {

        printf("\n\t\tBill cancelled.");

        // free temporary sdetail records
        while (start_detail != NULL) {
            sdtemp = start_detail;
            start_detail = start_detail->next;
            free(sdtemp);
        }

        // free temporary smaster record
        free(smtemp);
    }
}

// displays all completed sales
void show_sales() {
    SMASTER *smtemp = sales_master;

    if (smtemp == NULL) {
        printf("\n\n\t\tNo sales have been recorded yet.\n");
        return;
    }

    printf("\n\n");
    printf("\n\t\t%-10s %-25s %-10s %-10s %-10s %-10s",
           "Invoice", "Customer", "Items", "Gross", "Discount", "Net");
    printf("\n\t\t- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");

    while (smtemp != NULL) {
        printf("\n\t\t%-10d %-25s %-10d %-10.2lf %-10.2lf %-10.2lf\n",
               smtemp->inv_no,
               smtemp->cust_name,
               smtemp->item_count,
               smtemp->gross,
               smtemp->discount,
               smtemp->net);

        smtemp = smtemp->next;
    }

    printf("\n\t\t- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
}


// displays a single invoice and all of its detail lines
void show_invoice() {
    int inv_no;
    char ch;
    int found = FALSE;

    SMASTER *smtemp;
    SDETAIL *sdtemp;
    ITEM *item_info;

    do {
        printf("\n\t\tEnter invoice number: ");
        while (scanf("%d", &inv_no) != 1) {
            printf("Invalid selection. Please try again: ");
            while (getchar() != '\n');
        }

        // search sales_master for requested invoice
        smtemp = sales_master;

        while (smtemp != NULL) {
            if (smtemp->inv_no == inv_no) {
                found = TRUE;
                break;
            }

            smtemp = smtemp->next;
        }

        if (found == FALSE) {
            printf("\n\t\tInvoice number %d does not exist.\n", inv_no);
        } else {
            // printng invoice header
            printf("\n\n\t\t- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
            printf("\n\t\t\t\tWHOLE FRUITS MARKET");
            printf("\n\t\t- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");

            printf("\n\t\tInvoice: %-10d Customer: %s\n",
                   smtemp->inv_no,
                   smtemp->cust_name);

            printf("\n\t\t- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
            printf("\n\t\t%-5s %-20s %-10s %-8s %-10s",
                   "SL", "Item", "Rate", "Qty", "Total");
            printf("\n\t\t- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");

            // search sales_detail for all records
            sdtemp = sales_detail;

            while (sdtemp != NULL) {
                if (sdtemp->inv_no == inv_no) {

                    // finding item name using icode stored in sales_detail
                    item_info = item_list;

                    while (item_info != NULL) {
                        if (item_info->icode == sdtemp->icode) {
                            break;
                        }

                        item_info = item_info->next;
                    }

                    if (item_info != NULL) {
                        printf("\n\t\t%-5d %-20s %-10.2lf %-8d %-10d\n",
                               sdtemp->sl,
                               item_info->iname,
                               sdtemp->rate,
                               sdtemp->qty,
                               sdtemp->tot);
                    }
                }

                sdtemp = sdtemp->next;
            }

            // printing  invoice totals from master
            printf("\n\t\t- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -");
            printf("\n\t\tGross:    %10.2lf", smtemp->gross);
            printf("\n\t\tDiscount: %10.2lf", smtemp->discount);
            printf("\n\t\tNet:      %10.2lf", smtemp->net);
            printf("\n\t\t- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
        }

        printf("\n\t\tShow another invoice? (y/n): ");
        scanf(" %c", &ch);
        lcase(&ch);

        found = FALSE;

        while (ch != 'y' && ch != 'n') {
            printf("\n\t\tUnkown input: %c. Please try again. Would you like to add another item? (y/n)", ch);
            while (getchar() != '\n');
            scanf(" %c", &ch);
            lcase(&ch);
        }

    } while (ch == 'y');
}

/*
complete show_invoice & show_sale functions - print a receipt, use invoice number to search smaster for price and customer name, then filter sdetail for all elements containing same invoice number and print as list
 or for show_sale - show all sales thus far*/

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
        copy(temp.iname, new_node->iname);
        copy(temp.uom, new_node->uom);
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

SMASTER *get_sales_master() {
    FILE *fs;
    SMASTER *start = NULL, *new_node = NULL, *prev = NULL;
    SMASTER temp;

    fs = fopen("sales_master.tbl", "r");

    while (fread(&temp, sizeof(temp), 1, fs) != 0) {
        new_node = (SMASTER *)malloc(sizeof(SMASTER));

        new_node->inv_no = temp.inv_no;
        new_node->dt = temp.dt;
        strcpy(new_node->cust_name, temp.cust_name);
        new_node->item_count = temp.item_count;
        new_node->gross = temp.gross;
        new_node->discount = temp.discount;
        new_node->net = temp.net;
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

SDETAIL *get_sales_detail() {
    FILE *fs;
    SDETAIL *start = NULL, *new_node = NULL, *prev = NULL;
    SDETAIL temp;

    fs = fopen("sales_detail.tbl", "r");

    while (fread(&temp, sizeof(temp), 1, fs) != 0) {
        new_node = (SDETAIL *)malloc(sizeof(SDETAIL));

        new_node->inv_no = temp.inv_no;
        new_node->sl = temp.sl;
        new_node->icode = temp.icode;
        new_node->rate = temp.rate;
        new_node->qty = temp.qty;
        new_node->tot = temp.tot;

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

void load_db() {
    item_list = get_items();
    sales_master = get_sales_master();
    sales_detail = get_sales_detail();
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
    printf("\t\t\t3. Edit Item\n");
    printf("\t\t\t4. Delete Item\n");
    printf("\t\t\t5. Sale\n");
    printf("\t\t\t6. Show Sale\n");
    printf("\t\t\t7. Show Invoice\n");
    printf("\t\t\t8. Quit\n");
}