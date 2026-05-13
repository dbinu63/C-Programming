#include<stdio.h>

int main() {
    int num, fact;
    printf("Enter A Number");
    scanf("%d", &num);
    while(num)
        fact *= num--;
    printf("Factorial is ", fact); // requires %d in string
    return 0;
}