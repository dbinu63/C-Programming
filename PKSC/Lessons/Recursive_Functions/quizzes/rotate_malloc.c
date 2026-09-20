#include <stdio.h>
#include <stdlib.h>

void rotate(int *m, int n) {
    int i = 0;

    for (; i < n - 1; i++) {
        m[i] += m[i + 1];
        m[i + 1] = m[i] - m[i + 1];
        m[i] -= m[i + 1];
    }
}

int main() {
    int *arr;
    int n, i;

    printf("Enter the number of elements to put into the array: ");
    scanf("%d", &n);

    arr = (int * )malloc(n * sizeof(int));

    printf("Enter %d elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    rotate(arr, n);

    printf("Post rotation array: ");
    for (i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }

    free(arr);
    return 0;
}