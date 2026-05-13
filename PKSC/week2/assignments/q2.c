#include<stdio.h>
int main() {
    int num;
    int i, first=0, last=0;
    for (num = 100; num <= 999; ++num) {
        for (i = 2; i <= num/2; i++) { // using 101 as example, num%i is checked until i == 50, loop breaks, i++ is performed one last time, pushing i to 51. 
            if(num%i==0) break;
        }
        if(i>num) { // since the loop leaves i at num/2 + 1 (example input: 101, i = 51), i will never be greater than num - needs to be changed to i > num / 2 [51 > (101/2 = 50)]
            if(first==0) {
                first = num;
            }
            last = num;
        }
    }
    printf("Sum of first (%d) and last (%d) primer number is %d", first, last, first+last);
    return 0;
}