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
    scanf("%d", &num);

    printf("Would you like to print the first instance, or all instances of the found search term?");
    printf("\n1 - First instance only\n2 - All instances");
    scanf("%d", &temp);

    if (temp != 1 || temp != 2) {
        return 0;
    }

    for (i = 0; i < num; i++) {
        if (arr[i] == num) {
            printf("%d at position: %d", num, i + 1);
            if (temp == 2) {
                return 0;
            }
        }
    }
}