// WAP to print a box of alternating 1s & 0s
// By: D.B.

#include <stdio.h>

int main() {

    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            printf("%d", i % 2);
        }
        printf("\n");
    }
}