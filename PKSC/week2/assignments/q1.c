// WAP to determine the factorial of an input number
// By: D.B.

#include<stdio.h>

int main() {
    int num, fact = 1;
    printf("Enter A Number");
    scanf("%d", &num);
    while(num)
        fact *= num--;
    printf("Factorial is %d", fact);
    return 0;
}