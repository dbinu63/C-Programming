#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Book {
    int bookID;
    char title[MAX];
    char author[MAX];
    int year;
    struct Book* next;
} Book;

Book* head = NULL;

void addBook() {
    Book* newBook = (Book*)malloc(sizeof(Book));

    printf("Enter BookID: ");
    scanf("%d", &newBook->bookID);
    getchar();

    printf("Enter Title: ");
    fgets(newBook->title, MAX, stdin);
    newBook->title[strcspn(newBook->title, "\n")] = '\0';

    printf("Enter Author: ");
    fgets(newBook->author, MAX, stdin);
    newBook->author[strcspn(newBook->author, "\n")] = '\0';

    printf("Enter Year: ");
    scanf("%d", &newBook->year);

    newBook->next = NULL;

    // Empty list case
    if (head == NULL) {
        head = newBook;
    } else {
        Book* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newBook;
    }

    printf("Book added successfully!\n");
}

void removeBook(int id) {
    Book *temp = head, *prev = NULL;

    // Case: empty list
    if (head == NULL) {
        printf("Library is empty.\n");
        return;
    }

    // Case: first node
    if (temp != NULL && temp->bookID == id) {
        head = temp->next;
        free(temp);
        printf("Book removed successfully.\n");
        return;
    }

    // Search in rest
    while (temp != NULL && temp->bookID != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Book not found.\n");
        return;
    }

    // Remove node
    prev->next = temp->next;
    free(temp);

    printf("Book removed successfully.\n");
}

void searchByID(int id) {
    Book* temp = head;

    while (temp != NULL) {
        if (temp->bookID == id) {
            printf("\nBook Found:\n");
            printf("BookID: %d\nTitle: %s\nAuthor: %s\nYear: %d\n",
                   temp->bookID, temp->title, temp->author, temp->year);
            return;
        }
        temp = temp->next;
    }

    printf("Book not found.\n");
}

void searchByTitle(char title[]) {
    Book* temp = head;

    while (temp != NULL) {
        if (strcmp(temp->title, title) == 0) {
            printf("\nBook Found:\n");
            printf("BookID: %d\nTitle: %s\nAuthor: %s\nYear: %d\n",
                   temp->bookID, temp->title, temp->author, temp->year);
            return;
        }
        temp = temp->next;
    }

    printf("Book not found.\n");
}

void displayBooks() {
    Book* temp = head;

    if (temp == NULL) {
        printf("No books available.\n");
        return;
    }

    printf("\nBooks in the Library:\n");

    while (temp != NULL) {
        printf("\nBookID: %d\nTitle: %s\nAuthor: %s\nYear: %d\n",
               temp->bookID, temp->title, temp->author, temp->year);
        temp = temp->next;
    }
}

void freeList() {
    Book* temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int choice, id;
    char title[MAX];

    do {
        printf("\nLibrary Management System:\n");
        printf("1. Add a book\n");
        printf("2. Remove a book\n");
        printf("3. Search by BookID\n");
        printf("4. Search by Title\n");
        printf("5. Display all books\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                printf("Enter BookID to remove: ");
                scanf("%d", &id);
                removeBook(id);
                break;
            case 3:
                printf("Enter BookID to search: ");
                scanf("%d", &id);
                searchByID(id);
                break;
            case 4:
                printf("Enter Title to search: ");
                fgets(title, MAX, stdin);
                title[strcspn(title, "\n")] = '\0';
                searchByTitle(title);
                break;
            case 5:
                displayBooks();
                break;
            case 6:
                freeList();
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 6);

    return 0;
}