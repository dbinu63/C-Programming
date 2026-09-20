#include <stdio.h>

int main() {
    int num, arr[100];
    int i, j;

    printf("Enter the number of inputs: ");
    scanf("%d", &num);

    printf("Enter %d inputs: ", num);
    for (i = 0; i < num; i++) {
        scanf("%d", &arr[i]);
    }


    for (i = 0; i < num - 1; i++) {
        for (j = i + 1; j < num; j++) {
            if (arr[j] < arr[i]) {
                arr[i] += arr[j];
                arr[j] = arr[i] - arr[j];
                arr[i] -= arr[j];
            }
        }
    }

    for (i = 0; i < num - 1; i++) {
        printf("%d ", arr[i]);
    }
}