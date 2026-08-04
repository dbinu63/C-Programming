#include <stdio.h>
#include <stdlib.h>

void pass(int *arr_a, int *arr_b, int pos, int cyc);
void print(char text[], int *arr, int n);

int main() {
    int *arr_a, *arr_b;
    int n, i;

    printf("Enter the number of elements to put into the array: ");
    scanf("%d", &n);

    arr_a = (int *)malloc(n * sizeof(int));
    arr_b = (int *)malloc(n * sizeof(int));
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr_a[i]);
    }

    print("First list: ", arr_a, n);
    pass(arr_a, arr_b, 0, n);
    print("\nSecond list: ", arr_b, n);

    return 0;
}

void print(char text[], int *arr, int n) {
    int i;

    printf("%s", text);
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

void pass(int *arr_a, int *arr_b, int pos, int cyc) {
    if (cyc > pos) {
        arr_b[pos] = arr_a[pos] * arr_a[pos];
        pass(arr_a, arr_b, ++pos, cyc);
    }
}