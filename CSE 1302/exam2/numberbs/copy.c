#include <stdio.h>
#include <stdlib.h>

void printCleanDupes(int sortedNumbers[100], int size) {
    int n = 0;

    for (int i = 0; i < size; i++) {
        if (i == 0 || sortedNumbers[i] != sortedNumbers[i-1]) {
            sortedNumbers[n] = sortedNumbers[i];
            n++;
        };
    };

    for (int i = 0; i < n; i++) {
        printf("%d ", sortedNumbers[i]);
    };

    printf("\nSize: %d\n", n);
};

int main() {
    FILE *fptr = fopen("numbers.txt", "r");

    char fileout[100];
    int sortedNumbers[100], n = 0;

    while (fgets(fileout, 100, fptr) != NULL) {
        sortedNumbers[n] = atoi(fileout);
        n++;
    };

    printCleanDupes(sortedNumbers, n);

    fclose(fptr);
};