#include<stdio.h>

int main() {
    int num;
    int sum = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    num /= 10;
    while(num>9) {
        sum = sum + (num % 10);
        num = num / 10;
    }
    printf("Sum of internal digits is %d", sum);
    return 0;
} // couldn't find any issues