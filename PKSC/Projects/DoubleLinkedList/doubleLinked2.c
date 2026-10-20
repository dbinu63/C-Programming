#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} NODE;

NODE *create(NODE *, NODE **);
NODE *gc(NODE *);
NODE *insert(NODE *);
void display(NODE *, int);

int main() {
    NODE *dlist = NULL, *dlist_end = NULL;
    int opt;

    while (TRUE) {
        printf("Main Menu\n");
        printf("- - - - - - - - - - - - - - - - -\n");
        printf("\t1. Create\n");
        printf("\t2. Display\n");
        printf("\t3. Insert\n");
        printf("\t4. Delete\n");
        printf("\t0. Quit\n");
        printf("- - - - - - - - - - - - - - - - -\n");
        printf("Enter your choice: ");
        scanf("%d", &opt);
        printf("- - - - - - - - - - - - - - - - -\n\n");

        switch (opt) {
            case 0:
                return 0;
            case 1:
                dlist = create(dlist, &dlist_end);
                break;
            case 2:
                printf("Display Order\n");
                printf("1. First to Last\n");
                printf("2. Last to First\n");
                printf("Enter your choice: ");
                scanf("%d", &opt);

                if (opt == 1) {
                    display(dlist, opt);
                } else if (opt == 2) {
                    display(dlist_end, opt);
                } else {
                    printf("Invalid option.\n");
                }
                break;
            case 3:
                // Insert Func
                break;
            case 4:
                // Quit Func
                break;
            default: 
                printf("Invalid option. Please try again.");
        }
    }
}

NODE *create(NODE *start, NODE **end) {
    char opt;
	NODE *new_node = NULL, *temp = NULL; // newly added
    if (start != NULL) {
        printf("The list has already been created. If you continue, the existing data will be destroyed and you will start a new list. Do you want to continue? [y/n]: ");
        scanf(" %c", &opt);

        if (opt == 'y' || opt == 'Y') {
            start = gc(start);
        } else {
            printf("Operation cancelled. ");
            return start;
        }
    }
    
    do {
    	new_node = (NODE *)	malloc(sizeof(NODE));
    	new_node->prev = NULL;
    	new_node->next = NULL;
    	printf("Enter Data: ");
    	scanf("%d", &new_node->data);
    	
    	if(start==NULL)
    	{
    		start = new_node;
		}
		else
		{
			temp = start;
			while(temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = new_node;
			new_node->prev = temp;
		}
		printf("Do you want more node? [y/n]: ");
		scanf(" %c", &opt);
	} while(opt == 'y');

    *end = new_node;

    return start;
}

NODE *gc(NODE *start) {
    NODE *temp;

    while (start != NULL) {
        temp = start;
        start = start->next;
        free(temp);
    }

    return NULL;
}

NODE *insert(NODE *start) {
    NODE *new_node, *temp;
    int data, pos, i;

    printf("Enter the data to insert: ");
    if (scanf("%d", &data) != 1) {
        printf("Invalid input.\n");
        return start;
    }

    printf("Enter the position to insert at (starting from 1): ");
    if (scanf("%d", &pos) != 1 || pos < 1) {
        printf("Invalid position.\n");
        return start;
    }

    new_node = malloc(sizeof(NODE));

    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return start;
    }

    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (pos == 1) {
        new_node->next = start;

        if (start != NULL) {
            start->prev = new_node;
        }

        return new_node;
    }

    temp = start;

    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        free(new_node);
        return start;
    }

    new_node->next = temp->next;
    new_node->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = new_node;
    }

    temp->next = new_node;

    return start;
}

void display(NODE *start, int opt) {
    NODE *temp = start;

    if (start == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Doubly Linked List:\n");

    if (opt == 1) {
        while (temp != NULL) {
            printf("%d", temp->data);

            if (temp->next != NULL) {
                printf(" <-> ");
            }

            temp = temp->next;
        }
    } else if (opt == 2) {
        while (temp != NULL) {
            printf("%d", temp->data);

            if (temp->prev != NULL) {
                printf(" <-> ");
            }

            temp = temp->prev;
        }
    }

    printf("\n\n");
}