# include <stdio.h>

void fun();

int main() {
    fun();
    fun();
    fun();
    return 0;
}

void fun() {
    // int x = 10;
    static int x = 10;
    x++;
    printf("%d,\n", x);
}