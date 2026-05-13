#include <stdio.h>

int main() {
    int a = 5;

    for (a++; a > 1; a = 1) {
        printf("%d", a);
    };

    return 0;
}