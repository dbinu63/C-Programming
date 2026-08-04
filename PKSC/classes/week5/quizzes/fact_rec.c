#include <stdio.h>

int fact(int);

int main() {
    int num;

    printf("What number would you like to find the factorial of? ");
    scanf("%d", &num);

    printf("%d! = %d", num, fact(num));

    return 0;
}

int fact(int num) {
    if (num == 0) {
        return 1;
    } else {
        return (num *= fact(num - 1));
    }
}