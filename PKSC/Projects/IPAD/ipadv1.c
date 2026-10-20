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

int isValidIP(address_t *);
int isValidAlias(address_t *);
int isValidNode(address_t *); // calls above 2, just in rare situation wherein you have to check the whole node instead of either property
int isSameIP(address_t *, address_t *);
int isSameAlias(address_t *, address_t *);

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

    menuSys();
}

// Functions
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

        switch (opt) {
            case 1:
                addAddress(list);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                displayList(list);
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                printf("Thank you for using IPAD. ");
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
        return data; // data is dynmaically created in getNode and made a local variable in insertNode. Once insertNode returns, all local variables are cleared. So it's not safe to return the address of these local variables. 
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = data;

    return start;
}

void displayList(address_t *start) {
    address_t *temp = start;

    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("\n%-16s %-12s\n", "IP Address", "Alias");
    printf("------------------------------------------------------\n");

    while (temp != NULL) {
        printf("%d.%d.%d.%d %-12s\n", temp->octet[0], temp->octet[1], temp->octet[2], temp->octet[3], temp->alias);
        temp = temp->next;
    }
}

address_t* addAddress(address_t *start) {
    address_t *new_node, *temp = start;
    int i = 0;

    new_node = (address_t *)malloc(sizeof(address_t));
    if (new_node == NULL) {
        printf("\n\nERROR: node creation failed.\n\n");
        exit(1);
    }

    printf("Enter the address you want to add:\n");
    scanf("%d.%d.%d.%d", &new_node->octet[0], &new_node->octet[1], &new_node->octet[2], &new_node->octet[3]);
    printf("Enter an alias for this address:\n");
    scanf("%10s", new_node->alias);
    new_node->next = NULL;

    if (start == NULL) {
        if (!isValidNode(new_node)) {
            free(new_node);
        } else {
            start = new_node;
        }

        return start;
    }

    if (!isValidNode(new_node)) {
        free(new_node);
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    return start;

    /*
    while (temp->next != NULL) {
        if (temp->octet[0] == new_node->octet[0] && temp->octet[1] == new_node->octet[1] && temp->octet[2] == new_node->octet[2] && temp->octet[3] == new_node->octet[3]) {
            printf("Error: IP address already exists.\n");
            free(new_node);
            return start;
        }
        if (strcmp(temp->alias, new_node->alias) == 0) {
            printf("Error: Alias already in use.\n");
            free(new_node);
            return start;
        }
        temp = temp->next;
    }
    if (temp->octet[0] == new_node->octet[0] && temp->octet[1] == new_node->octet[1] && temp->octet[2] == new_node->octet[2] && temp->octet[3] == new_node->octet[3]) {
        printf("Error: IP address already exists.\n");
        free(new_node);
        return start;
    }
    if (strcmp(temp->alias, new_node->alias) == 0) {
        printf("Error: Alias already in use.\n");
        free(new_node);
        return start;
    }

    temp->next = new_node;

    return start;
    */
}

// - - - - - - - - - - - -

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
        if (isSameIP(node, temp)) {
            printf("Error: IP address already exists.");
            return FALSE;
        }
        temp = temp->next;
    }
    if (isSameIP(node, temp)) {
        printf("Error: IP address already exists.");
        return FALSE;
    }

    return TRUE;
}

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
        if (isSameAlias(node, temp)) {
            printf("Error: Alias already in use.");
            return FALSE;
        }
        temp = temp->next;
    }
    if (isSameAlias(node, temp)) {
        printf("Error: Alias already in use.");
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