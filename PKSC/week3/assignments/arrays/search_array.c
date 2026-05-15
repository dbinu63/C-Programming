#include <stdio.h>

int main() {
    int num, arr[100];
    int temp, i, j;

    printf("Enter the number of inputs: ");
    scanf("%d", &num);

    printf("Enter %d inputs: ", num);
    for (i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number you would like to search for: ");
    scanf("%d", &j);

    printf("Would you like to print the first instance, or all instances of the found search term? ");
    printf("\n1 - First instance only\n2 - All instances\n: ");
    scanf("%d", &temp);

    if (temp != 1 && temp != 2) {
        return 0;
    }

    for (i = 0; i < num; i++) {
        if (arr[i] == j) {
            printf("%d at position: %d\n", j, i + 1);
            if (temp == 1) {
                return 0;
            }
            temp = 0;
        }
    }

    if (temp) {
        printf("There were no instances of %d in the list: ", j);
        for (i = 0; i < num; i++) {
            printf("%d ", arr[i]);
        }
    }
}