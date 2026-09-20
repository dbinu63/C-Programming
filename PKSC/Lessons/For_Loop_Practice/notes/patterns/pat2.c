/*
Pattern 2: (pat02.c)
1 2 3 4 5
1 2 3 4 5 
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
*/
#include <stdio.h>

int main() {
    int a, b;
    for( a = 1; a <= 5; a++ ) {
        for( b = 1; b <= 5; b++) {
            printf(" %d ", b); // if you compare with pat01.c, you can see we are printing b instead of a
        }
        printf("\n");
    }
}