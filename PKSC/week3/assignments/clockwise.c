#include <stdio.h>

int main() {
    int in, num, arr[100];
    int i, j;

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
    printf("\nHow many moves would you like to make: ");
    scanf("%d", &in);

    for (i = 1; i <= in; i++) {
        for (j = num; j > 0; j--) {
            arr[j - 1] += arr[j];
            arr[j] = arr[j - 1] - arr[j];
            arr[j - 1] -= arr[j];
        }
        arr[0] = arr[num];
    }

    printf("Final product: \n");
    for (i = 0; i < num; i++) {
        printf("%d ", arr[i]);
    }
}