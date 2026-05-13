#include <stdio.h>

int main() {
    int in, num, arr[100];
    int np = 0, temp = 0, n = 2;

    printf("Enter the number of inputs: ");
    scanf("%d", &num);

    printf("Enter %d inputs: ", num);
    while (temp < num) {
        scanf("%d", &in);
        arr[temp] = in;
        temp++;
    }

    for (temp; temp >= 0; temp--) {
        for (n; n * n <= arr[temp]; n++) {
            if (!(arr[temp] % n)) {
                np++;
                break;
            }
        }
        n = 2;
    }

    printf("There are %d prime numbers in the inputs you entered. ", num - np);
}