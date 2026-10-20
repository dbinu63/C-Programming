#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) { // argc - argument count, argv - argument variables
    int n, i;
    n = atoi(argv[1]);
    for (i = 1; i <= n; i++) {
        printf("%s\n", argv[2]);
    }
    return 0;
}