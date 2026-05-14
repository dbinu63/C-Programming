#include <stdio.h>

int main() {
    int in, num, arr[100];
    int np = 0, temp = 0, i, j;

    printf("Enter the number of inputs: ");
    scanf("%d", &num);

    printf("Enter %d inputs: ", num);
    while (temp < num) {
        scanf("%d", &in);
        arr[temp] = in;
        temp++;
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