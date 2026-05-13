#include <stdio.h>

int main() {
    int in;
    long temp1 = 0;

    printf("Enter a number to check. ");
    scanf("%d", &in);
    printf("%d is:\n\n", in);


    // Prime number check
    temp1 = 0;
    for (int n = 2; n * n <= in; n++) {
        if (!(in % n)) {
            temp1++;
            break;
        }
    }
    temp1 ? printf("not prime, ") : printf("prime, ");


    // Palindrome check
    temp1 = in;
    int temp2 = 0;
    do {
        temp2 = temp2 * 10 + temp1 % 10;
        temp1 /= 10;
    } while (temp1);
    temp2 == in ? printf("a palindrome, ") : printf("not a palindrome, ");


    // Perfect number check
    temp1 = 0;
    for (int n = 1; n * n <= in; n++) {
        if (in % n == 0) {
            temp1 += n;
            if (n != in / n) {
                temp1 += in / n;
            }
        }
    }
    temp1 - in == in ? printf("perfect, ") : printf("not perfect, ");


    // Strong
    temp1 = in;
    temp2 = 1;
    int temp3 = 0;
    do {
        for (int i = 1; i <= temp1 % 10; i++) {
            temp2 *= i;
        }
        temp1 /= 10;
        temp3 += temp2;
        temp2 = 1;
    } while (temp1);
    temp3 == in ? printf("strong, ") : printf("not strong, ");


    // ArmStrong
    temp1 = in;
    temp2 = 0;
    temp3 = 0;
    int temp4 = 1;
    do {
        temp1 /= 10;
        temp2++;
    } while (temp1);
    for (temp1 = in; temp1; temp1 /= 10) {
        for (int j = 0; j < temp2; j++) {
            temp4 *= (temp1 % 10);
        }
        temp3 += temp4;
        temp4 = 1;
    }
    temp3 == in ? printf("armstrong, ") : printf("not armstrong, ");

    
    /*A better alternative would be: (not used so as to keep printed output clean)

    temp1 = in;
    temp2 = 1;
    temp3 = 0;
    for (temp1 = in; temp1; temp1 /= 10) {
        for (int j = 0; j < printf("%d", in); j++) {
            temp2 *= (temp1 % 10);
        }
        temp3 += temp2;
        temp2 = 1;
    }
    temp3 == in ? printf("armstrong, ") : printf("not armstrong, ");

    */


    // Spy
    temp1 = in;
    temp2 = 0;
    temp3 = 1;
    do {
        temp2 += temp1 % 10;
        temp3 *= temp1 % 10;
        temp1 /= 10;
    } while (temp1);
    temp2 == temp3 ? printf("a spy, ") : printf("not a spy, ");


    // Neon (sigma dig of self^2 = self)
    temp1 = (long) in * in;
    temp2 = 0;
    do {
        temp2 += temp1 % 10;
        temp1 /= 10;
    } while (temp1);
    temp2 == in ? printf("neon, ") : printf("not neon, ");


    // Fibonacci
    temp1 = 0;
    temp2 = 1;
    temp3 = 0;
    while ((temp1 < in || temp2 < in) && temp3 == 0) {
        temp1 += temp2;
        temp2 += temp1;
        temp3 = (in == temp1 || in == temp2 ? 1 : 0);
    }
    temp3 ? printf("and in the fibonacci sequence. \n") : printf("and not in the fibonacci sequence. \n");
    printf("\n");
    printf("\n");
    

    // WAP that... 
    // 1. counts strongs between 1-1000
    temp4 = 0;
    for (int i = 1; i <= 1000; i++) {
        temp1 = i;
        temp2 = 1;
        temp3 = 0;
        do {
            for (int j = 1; j <= temp1 % 10; j++) {
                temp2 *= j;
            }
            temp1 /= 10;
            temp3 += temp2;
            temp2 = 1;
        } while (temp1);
        if (temp3 == i) {
            temp4++;
        }
    }
    printf("There are %d strong numbers between 1 and 1000. ", temp4);
    printf("\n");
    printf("\n");
    

    // 2. displays primes between 1-1000
    printf("The primes between 1 and 1000 are: \n");
    for (int i = 2; i <= 1000; i++) {
        temp1 = 1;
        for (int n = 2; n * n <= i; n++) {
            if (!(i % n)) {
                temp1 = 0;
                break;
            }
        }
        if (temp1) {
            printf("%d, ", i);
        }
        temp1 = 1;
    }
    printf("\n");
    printf("\n");


    // 3. sums all perfects between 10-1000
    temp2 = 0;
    for (int i = 10; i <= 1000; i++) {
        temp1 = 0;
        for (int n = 1; n * n <= i; n++) {
            if (i % n == 0) {
                temp1 += n;
                if (n != i / n) {
                    temp1 += i / n;
                }
            }
        }
        temp2 += (temp1 - i == i ? i : 0);
    }
    printf("The sum of all perfect numbers between 1 and 1000 is: %d\n", temp2);
}