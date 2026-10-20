#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int mult(int a, int b) {
    return a * b;
}

int sub(int a, int b) {
    return a - b;
}

int main() {
    int (*ptr[])(int, int) = {add, mult, sub};
    int n = 0;

    for (; n < sizeof(ptr) - 1; n++) {
        printf("%d\n", ptr[n](10, 20));
    }

    return 0;
}