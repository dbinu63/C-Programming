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

    for (i = 0; i < num / 2; i++) {
        temp = arr[i];
        arr[i] = arr[num - i - 1];
        arr[num - i - 1] = temp;
    }

    for (i = 0; i < num; i++) {
        printf("%d ", arr[i]);
    }
}