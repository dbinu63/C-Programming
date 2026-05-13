#include <stdio.h>

int main() {
    int in, z = 0, nz = 0, temp;

    printf("Enter an input: ");
    scanf("%d", &in);
    temp = in;

    while (temp > 0) {
        if (temp % 10) {
            nz++;
        } else {
            z++;
        }

        temp /= 10;
    }

    printf("There are %d zero and %d nonzero numbers in %d. ", z, nz, in);
}