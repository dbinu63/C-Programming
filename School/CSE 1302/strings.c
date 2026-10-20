#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 500

void countCharacters(char str[]) {
    int freq[256] = {0};

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]);
        freq[(unsigned char)ch]++;
    }

    printf("\nCharacter frequencies:\n");
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            printf("'%c' appears %d times\n", i, freq[i]);
        }
    }
}

void wordFrequency(char str[]) {
    char word[100];
    int count = 0;

    printf("Enter word to search: ");
    fgets(word, 100, stdin);
    word[strcspn(word, "\n")] = '\0';

    int lenStr = strlen(str);
    int lenWord = strlen(word);

    for (int i = 0; i <= lenStr - lenWord; i++) {
        int match = 1;

        for (int j = 0; j < lenWord; j++) {
            if (tolower(str[i + j]) != tolower(word[j])) {
                match = 0;
                break;
            }
        }

        if (match) count++;
    }

    printf("The word '%s' appears %d times.\n", word, count);
}

void toTitleCase(char str[]) {
    int newWord = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            if (newWord) {
                str[i] = toupper(str[i]);
                newWord = 0;
            } else {
                str[i] = tolower(str[i]);
            }
        } else {
            newWord = 1;
        }
    }

    printf("Title case: %s\n", str);
}

void extractSubstring(char str[]) {
    int start, length;
    int strLen = strlen(str);

    printf("Enter starting index: ");
    scanf("%d", &start);
    printf("Enter length: ");
    scanf("%d", &length);
    getchar();

    if (start < 0 || start >= strLen || length < 0) {
        printf("Invalid input.\n");
        return;
    }

    if (start + length > strLen) {
        length = strLen - start;
    }

    char sub[MAX];

    for (int i = 0; i < length; i++) {
        sub[i] = str[start + i];
    }
    sub[length] = '\0';

    printf("Extracted substring: %s\n", sub);
}

void replaceSpaces(char str[]) {
    char result[MAX];
    int j = 0;
    int spaceFlag = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            if (!spaceFlag) {
                result[j++] = ' ';
                spaceFlag = 1;
            }
        } else {
            result[j++] = str[i];
            spaceFlag = 0;
        }
    }

    result[j] = '\0';
    printf("Updated string: '%s'\n", result);
}

int main() {
    char str[MAX];
    int choice;

    printf("Enter a text: ");
    fgets(str, MAX, stdin);

    // Remove newline if present
    str[strcspn(str, "\n")] = '\0';

    do {
        printf("\nChoose an operation:\n");
        printf("1. Count character occurrences\n");
        printf("2. Find word frequency\n");
        printf("3. Convert to title case\n");
        printf("4. Extract a substring\n");
        printf("5. Replace multiple spaces\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume leftover newline

        switch (choice) {
            case 1:
                countCharacters(str);
                break;
            case 2:
                wordFrequency(str);
                break;
            case 3:
                toTitleCase(str);
                break;
            case 4:
                extractSubstring(str);
                break;
            case 5:
                replaceSpaces(str);
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 6);

    return 0;
}