#include <stdio.h>
#include <ctype.h>

int main() {
    char ch; // set to 0 or something, so garbage value does not end up @ 32 randomly
    int up; // same here, set to 1 so as to avoid issues with garbage values & toupper the first character

    while ((ch = getchar()) != '\n') {
        if (up) {
            ch = toupper(ch);
            printf("%c", ch);
        } else {
            ch = tolower(ch);
            printf("%c", ch);
        }

        up = ch == 32 ? 1 : 0;
    }
    return 0;
}