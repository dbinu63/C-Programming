#include <stdio.h>

int x = 30;

int main() {
    int x = 10;

    printf("%d\n", x);

    { // blocks can be made anywhere
        extern int x;
        printf("%d\n", x);
    }

    return 0;
}
