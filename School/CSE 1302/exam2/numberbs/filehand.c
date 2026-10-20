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

    printf("\n\nSize: %d\n", n);

    FILE *out = fopen("removedduplicates.txt", "w");

    for (int i = 0; i < n; i++) {
        fprintf(out, "%d\n", sortedNumbers[i]);
    }

    fclose(out);
};

int main() {
    FILE *fptr;
    fptr = fopen("numbers.txt", "r");

    char fileout[100];
    int i = 0, sortedNumbers[100];
    
    while (fgets(fileout, 100, fptr) != NULL) {
        int num = atoi(fileout);
        sortedNumbers[i] = num;
        i++;
    };

    printCleanDupes(sortedNumbers, i);

    fclose(fptr);
};