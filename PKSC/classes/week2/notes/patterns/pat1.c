/*
Pattern 1: (pat01.c)
1 1 1 1 1
2 2 2 2 2
3 3 3 3 3
4 4 4 4 4
5 5 5 5 5
*/
#include <stdio.h>

int main() {
    int a, b;
    for( a = 1; a <= 5; a++ ) {
        for( b = 1; b <= 5; b++) {
            printf(" %d ", a);
        }
        printf("\n");
    }
}