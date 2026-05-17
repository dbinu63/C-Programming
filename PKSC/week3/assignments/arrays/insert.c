#include <stdio.h>

int main() {
    int num, arr[100];
    int i, in, pos;

    printf("Enter the number of inputs: ");
    scanf("%d", &num);

    printf("Enter %d inputs: ", num);
    for (i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }

    printf("This is what you entered: ");
    for (i = 0; i < num; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nWhat number would you like to input? ");
    scanf("%d", &in);
    printf("What position would you like to insert it? ");
    scanf("%d", &pos);
    if (pos < 1 || pos > num + 1) {
        return 0;
    }

    for (i = num; i > pos - 1; i--) {
        arr[i - 1] += arr[i];
        arr[i] = arr[i - 1] - arr[i];
        arr[i - 1] -= arr[i];
    }
    arr[pos - 1] = in;

    printf("Final product: ");
    for (i = 0; i <= num; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}