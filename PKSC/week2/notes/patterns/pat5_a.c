/*
Pattern 5_a: (pat05_a.c)
1 0 0 0 1
0 1 0 1 0
0 0 1 0 0
0 1 0 1 0
1 0 0 0 1

for n values
*/
#include <stdio.h>

int main() {
    int a, b;
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
	
    if(n%2==0) n++;
    printf("\n");
    for( a = 1; a <= n; a++ ) { // row counter
        for( b = 1; b <= n; b++) { // column counter
            if( (a==b) || (a+b==(n+1))) {
                printf(" * ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
}
