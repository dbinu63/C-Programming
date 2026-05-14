#include <stdio.h>

int main() {
    int in, num, arr[100];
    int temp = 0, i, j;

    printf("Enter the number of inputs: ");
    scanf("%d", &num);

    printf("Enter %d inputs: ", num);
    while (temp < num) {
        scanf("%d", &in);
        arr[temp] = in;
        temp++;
    }

    printf("Enter the number you would like to search for");
    scanf("")

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