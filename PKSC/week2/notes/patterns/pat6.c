/*
Pattern 6: (pat06.c)
0 0 1 0 0
0 0 1 0 0
1 1 1 1 1
0 0 1 0 0
0 0 1 0 0


*/
#include <stdio.h>

int main() {
     int a, b;
	
     for( a = 1; a <= 5; a++ ) { // row counter
        for( b = 1; b <= 5; b++) { // column counter
            if( (a==3) || (b==3)) {
                printf(" 1 ");
            } else {
                printf(" 0 ");
            }
        }
        printf("\n");
    }
}