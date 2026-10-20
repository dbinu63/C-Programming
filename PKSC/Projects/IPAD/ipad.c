// Don Binu dbinu63@gmail.com
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Consts
#define TRUE 1
#define FALSE 0

// Global
typedef struct node {
    int octet[4];
    char alias[11];
    struct node *next;
}address_t;
address_t *list = NULL;

// - - - - - - - - - - - -

// Prototypes
void menuSys();
address_t* insertNode(address_t *, address_t *);
address_t* getNode(char *); 
void displayList(address_t *);
address_t* addAddress(address_t *);
void lookUpAddress(address_t *);
void updateAddress(address_t *);
address_t* deleteAddress(address_t *);
void saveData(address_t *);
void displayAliasToLocation(address_t *);

int isValidIP(address_t *);
int isValidAlias(address_t *);
int isValidNode(address_t *);
int isSameIP(address_t *, address_t *);
int isSameAlias(address_t *, address_t *);

// - - - - - - - - - - - -

// Main & Menu Display
int main() {
    char str[30];
    FILE *fp;

    fp = fopen("CS531_Inet.txt", "r");
    if (fp == NULL) {
        printf("\n\nERROR: Unable to open the file. \n\n");
        exit(1);
    } else {
        while (fgets(str, 30, fp) != NULL) {
            list = insertNode(list, getNode(str));
        }
    }

    fclose(fp);
    menuSys();
}

void menuSys() {
    int opt;

    while (TRUE) {
        printf("\n\n-----IPAD: Internet Protocol Address Data Program-----\n");
        printf("\t1. Add Address\n");
        printf("\t2. Look Up Address\n");
        printf("\t3. Update Address\n");
        printf("\t4. Delete Address\n");
        printf("\t5. Display List\n");
        printf("\t6. Display Aliases for Location\n");
        printf("\t7. Save to File\n");
        printf("\t8. Quit\n\n");

        printf("\tEnter choice: ");
        scanf("%d", &opt);

        printf("------------------------------------------------------\n\n");

        switch (opt) {
            case 1:
                addAddress(list);
                break;
            case 2:
                lookUpAddress(list);
                break;
            case 3:
                updateAddress(list);
                break;
            case 4:
                list = deleteAddress(list);
                break;
            case 5:
                displayList(list);
                break;
            case 6:
                displayAliasToLocation(list);
                break;
            case 7:
                saveData(list);
                break;
            case 8:
                printf("\nThank you for using IPAD.\n\n");
                printf("\n------------------------------------------------------\n\n");
                exit(0);
                break;
            default: 
                printf("%d is not a valid option. Please try again.", opt);
                break;
        }
        printf("\n------------------------------------------------------\n\n");
    }
}

// - - - - - - - - - - - -

// Core Functions
address_t* getNode(char *str) {
    address_t *new_node;
    new_node = (address_t *)malloc(sizeof(address_t));

    if (new_node == NULL) {
        printf("\n\nERROR: node creation failed.\n\n");
        exit(1);
    }

    sscanf(str, "%d.%d.%d.%d %s", &new_node->octet[0], &new_node->octet[1], &new_node->octet[2], &new_node->octet[3], new_node->alias);

    new_node->next = NULL;

    return new_node;
}

address_t* insertNode(address_t *start, address_t *data) {
    address_t *temp;
    temp = start;

    if (start == NULL) {
        return data; 
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = data;

    return start;
}

void displayList(address_t *start) {
    char octet[16];
    address_t *temp = start;

    if (temp == NULL) {
        printf("There are no addresses to display.\n\n");
        return;
    }

    printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    printf("%-25s %s\n", "IP Address", "Alias");
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");

    while (temp != NULL) {
        sprintf(octet, "%d.%d.%d.%d", temp->octet[0], temp->octet[1], temp->octet[2], temp->octet[3]);
        printf("%-25s %s\n", octet, temp->alias);
        temp = temp->next;
    }
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    printf("\n");
}

address_t* addAddress(address_t *start) {
    address_t *new_node, *temp;
    
    new_node = (address_t *)malloc(sizeof(address_t));
    if (new_node == NULL) {
        printf("\n\nERROR: node creation failed.\n\n");
        exit(1);
    }

    printf("\nEnter the address you want to add: ");
    scanf("%d.%d.%d.%d", &new_node->octet[0], &new_node->octet[1], &new_node->octet[2], &new_node->octet[3]);

    printf("Enter an alias for this address: ");
    scanf("%10s", new_node->alias);

    new_node->next = NULL;

    if (!isValidIP(new_node) || !isValidAlias(new_node)) {
        free(new_node);
        return start;
    }

    if (start == NULL) {
        return new_node;
    }

    temp = start;
    while (temp->next != NULL) {
        if (isSameIP(new_node, temp)) {
            printf("Error: IP address already exists.\n\n");
            free(new_node);
            return start;
        }

        if (isSameAlias(new_node, temp)) {
            printf("Error: Alias already in use.\n\n");
            free(new_node);
            return start;
        }

        temp = temp->next;
    }
    if (isSameIP(new_node, temp)) {
        printf("Error: IP address already exists.\n\n");
        free(new_node);
        return start;
    }

    if (isSameAlias(new_node, temp)) {
        printf("Error: Alias already in use.\n\n");
        free(new_node);
        return start;
    }
    temp->next = new_node;

    printf("IP successfully added.\n\n");

    return start;
}

void lookUpAddress(address_t *start) {
    char alias[11];
    address_t *temp = start;

    if (start == NULL) {
        printf("\nNo addresses to look up.\n\n");
        return;
    }

    printf("\nEnter the name (alias) of the address you are searching for: ");
    scanf("%10s", alias);

    while (temp != NULL) {
        if (strcmp(temp->alias, alias) == 0) {
            printf("Address found: %d.%d.%d.%d (%s)\n\n", temp->octet[0], temp->octet[1], temp->octet[2], temp->octet[3], alias);
            return;
        }
        temp = temp->next;
    }

    printf("No address found with the alias: %s\n\n", alias);
    return;
}

void updateAddress(address_t *start) {
    char alias[11];
    int octet[4], update;
    address_t *temp = start;

    if (start == NULL) {
        printf("\nNo addresses to update.\n\n");
        return;
    }

    printf("\nEnter the name (alias) of the address you wish to update: ");
    scanf("%10s", alias);

    while (temp != NULL) {
        if (strcmp(temp->alias, alias) == 0) {
            for (int i = 0; i < 4; i++) {
                octet[i] = temp->octet[i];
            }

            printf("Address found: %d.%d.%d.%d (%s)\n", temp->octet[0], temp->octet[1], temp->octet[2], temp->octet[3], temp->alias);

            printf("\nWhat would you like to update?\n");
            printf("1. Address\n");
            printf("2. Alias\n");
            printf("0. Cancel\n");
            printf("Enter choice: ");
            scanf("%d", &update);

            if (update == 1) {
                printf("\nEnter the new address: ");
                scanf("%d.%d.%d.%d", &temp->octet[0], &temp->octet[1], &temp->octet[2], &temp->octet[3]);
            } else if (update == 2) {
                printf("\nEnter the new alias: ");
                scanf("%10s", temp->alias);
            }
            else if (update == 0) {
                printf("\nOperation cancelled.\n\n");
                return;
            } else {
                printf("\nInvalid option. Operation cancelled.\n\n");
                return;
            }

            if (!isValidNode(temp)) {
                    for (int i = 0; i < 4; i++) {
                        temp->octet[i] = octet[i];
                    }
                    strcpy(temp->alias, alias);

                    printf("The information you entered was invalid. Update cancelled. Please try again. \n\n");
                    return;
                }

                printf("Successfully updated.\n\n");
                return;
        }

        temp = temp->next;
    }

    printf("No address found with the alias: %s\n\n", alias);
    return;
}

address_t* deleteAddress(address_t *start) {
    char alias[11], confirm;
    address_t *temp = start, *garbage;

    if (start == NULL) {
        printf("\nNo addresses to delete.\n\n");
        return NULL;
    }

    printf("\nEnter the name (alias) of the address you wish to delete: ");
    scanf("%10s", alias);

    if (strcmp(start->alias, alias) == 0) {
        printf("Address found: %d.%d.%d.%d (%s)\n", start->octet[0], start->octet[1], start->octet[2], start->octet[3], alias);
            
        printf("\nAre you sure you want to delete this address? (y/n): ");
        scanf(" %c", &confirm);

        if (confirm == 'y' || confirm == 'Y') {
            garbage = start;
            start = start->next;
            free(garbage);
        } else {
            printf("Operation cancelled.\n\n");
        }

        return start;
    }


    while (temp->next != NULL) {
        if (strcmp(temp->next->alias, alias) == 0) {
            printf("Address found: %d.%d.%d.%d (%s)\n", temp->next->octet[0], temp->next->octet[1], temp->next->octet[2], temp->next->octet[3], alias);
            
            printf("\nAre you sure you want to delete this address? (y/n): ");
            scanf(" %c", &confirm);

            if (confirm == 'y' || confirm == 'Y') {
                garbage = temp->next;
                temp->next = garbage->next;

                free(garbage);
                printf("Address successfully deleted.\n\n");
            } else {
                printf("Operation cancelled.\n\n");
            }

            return start;
        }
        temp = temp->next;
    }

    printf("No address found with the alias: %s\n\n", alias);
    return start;
}

void saveData(address_t *start) {
    char str[30], octet[16], confirmation;
    FILE *fp;
    address_t *temp = NULL;

    fp = fopen("CS531_Inet.txt", "r");
    if (fp == NULL) {
        printf("\n\nERROR: Unable to open the file. \n\n");
        exit(1);
    } else {
        printf("\nPrevious Version: \n");
        printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
        printf("%-25s %s\n", "IP Address", "Alias");
        printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
        while (fgets(str, 30, fp) != NULL) {
            temp = getNode(str);
            sprintf(octet, "%d.%d.%d.%d", temp->octet[0], temp->octet[1], temp->octet[2], temp->octet[3]); // for formatting purposes
            printf("%-25s %s\n", octet, temp->alias);
        }
        printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");

        if (temp == NULL) {
            printf("No addresses were previously stored.\n");
        }
    }
    fclose(fp);

    printf("\n\nCurrent version:\n");
    displayList(list);

    printf("\n\nSave changes to file? (y/n): ");
    scanf(" %c", &confirmation);
    if (confirmation == 'y' || confirmation == 'Y') {
        temp = start;
        fp = fopen("CS531_Inet.txt", "w");

        while (temp != NULL) {
            sprintf(octet, "%d.%d.%d.%d", temp->octet[0], temp->octet[1], temp->octet[2], temp->octet[3]);
            fprintf(fp, "%s %s\n", octet, temp->alias);

            temp = temp->next;
        }
        fclose(fp);

        printf("Changes saved successfully. ");
    }

    return;
}


void displayAliasToLocation(address_t *start) {
    char octet[16];
    char input[16];
    address_t *temp = start;

    if (start == NULL) {
        printf("\nNo addresses to look up.\n\n");
        return;
    }

    printf("\nEnter the IP address you are searching for: ");
    scanf("%15s", input);

    while (temp != NULL) {
        sprintf(octet, "%d.%d.%d.%d", temp->octet[0], temp->octet[1], temp->octet[2], temp->octet[3]);

        if (strcmp(octet, input) == 0) {
            printf("Address found: %s (%s)\n\n", octet, temp->alias);
            return;
        }

        temp = temp->next;
    }

    printf("No address found with IP: %s\n\n", input);
}

// - - - - - - - - - - - -

// Helper Functions
int isValidIP(address_t *node) {
    int i;
    address_t *temp = list;
    
    for (i = 0; i < 4; i++) {
        if (node->octet[i] < 0 || node->octet[i] > 255) {
            printf("Error: Invalid IP address. Octet must be valu between 0 and 255.");
            return FALSE;
        }
    }

    if (temp == NULL) {
        return TRUE;
    }

    while (temp->next != NULL) {
        if (temp != node && isSameIP(node, temp)) {
            printf("Error: IP address already exists. ");
            return FALSE;
        }
        temp = temp->next;
    }
    if (temp != node && isSameIP(node, temp)) {
        printf("Error: IP address already exists. ");
        return FALSE;
    }

    return TRUE;
}

// UPDATELIST, LOOKUPADDRESS

int isValidAlias(address_t *node) {
    int i, character;
    address_t *temp = list;
    
    character = node->alias[0];
    if ((character < 65 || character > 90) && (character < 97 || character > 122)) {
        printf("Error: Alias must start with alphabetic character.");
        return FALSE;
    }

    for (i = 1; node->alias[i] != '\0'; i++) {
        character = node->alias[i];
        if ((character < 48 || character > 57) && (character < 65 || character > 90) && (character < 97 || character > 122) && character != 45 && character != 95) {
            printf("Error: Alias can only contain these characters: \'0\'-\'9\', \'a\'-\'z\', \'A\'-\'Z\', \'_\', \'-\'");
            return FALSE;
        }
    }

    if (temp == NULL) {
        return TRUE;
    }

    while (temp->next != NULL) {
        if (temp != node && isSameAlias(node, temp)) {
            printf("Error: Alias already in use. ");
            return FALSE;
        }
        temp = temp->next;
    }
    if (temp != node && isSameAlias(node, temp)) {
        printf("Error: Alias already in use. ");
        return FALSE;
    }

    return TRUE;
}

int isValidNode(address_t *node) {
    return isValidIP(node) && isValidAlias(node);
}

int isSameIP(address_t *node, address_t *test) {
    int i;

    for (i = 0; i < 4; i++) {
        if (node->octet[i] != test->octet[i]) {
            return FALSE;
        }
    }

    return TRUE;
}

int isSameAlias(address_t *node, address_t *test) {    
    return strcmp(node->alias, test->alias) == 0;
}