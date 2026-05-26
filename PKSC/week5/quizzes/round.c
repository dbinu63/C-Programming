#include <stdio.h>

int dround(float in) {
    int m;
    m = in + 0.5;
    return m;
}
// or return (int)(in + 0.5)

int main() {
    float in;
    
    printf("Enter a number to round: ");
    scanf("%f", &in);

    printf("Rounded answer: %d", dround(in));
}