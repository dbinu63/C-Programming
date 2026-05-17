#include <stdio.h>

int main() {
    int num, arr[100];
    int temp, i, j;

    printf("Enter the number of inputs: ");
    scanf("%d", &num);

    printf("Enter %d inputs: ", num);
    for (temp = 0; temp < num; temp++) {
        scanf("%d", &arr[temp]);
    }

    for (i = 0; i < num - 1; i++) {
        for (j = 0; j < num - 1; j++) {
            if (arr[j + 1] < arr[j]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < num; i++) {
        printf("%d ", arr[i]);
    }
}