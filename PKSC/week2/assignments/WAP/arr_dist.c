#include <stdio.h>

int main() {
    int num, temp = 0, in, arr[100], dist;
    int largest, lloc = 0, smallest, sloc = 0;

    printf("Enter the number of inputs: ");
    scanf("%d", &num);

    printf("Enter %d inputs: ", num);
    while (temp < num) {
        scanf("%d", &in);
        arr[temp] = in;
        temp++;
    }
    temp--;

    smallest = arr[0];
    largest = arr[0];
    for (; temp >= 0; temp--) {
        if (arr[temp] < smallest) {
            smallest = arr[temp];
            sloc = temp;
        }
        if (arr[temp] > largest) {
            largest = arr[temp];
            lloc = temp;
        }
    }

    dist = lloc - sloc;
    if (dist < 0) {
        dist = 0 - dist;
    }

    printf("The largest number is %d, and the smallest is %d.\n", largest, smallest);
    printf("The distance between the two is %d units.", dist);
}