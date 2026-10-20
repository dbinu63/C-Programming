/*
Pattern 3: (pat03.c)
1 1 1 1 1
0 0 0 0 0
1 1 1 1 1
0 0 0 0 0
1 1 1 1 1
*/
#include <stdio.h>

int main() {
    int a, b;
    for( a = 1; a <= 5; a++ ) { // row counter
        for( b = 1; b <= 5; b++) { // column counter
            printf(" %d ", a%2); // Optimized version of pat03.c, here we print what a%2 returns insted of 1 or 0
        }
    printf("\n");
    }
}