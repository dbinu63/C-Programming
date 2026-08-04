#include <stdio.h>
#include <ctype.h>

void vowel_cap(char *str);

int main() {
    char str[] = "The quick brown fox jumps over the lazy dog. ";

    printf("Upper function result: \n");
    vowel_cap(str);
    printf("%s", str);
}

void vowel_cap(char *str) {
    while (*str != '\0') {
        switch (*str) { // does not take into account vowels that are already uppercase, so pass as switch (tolower(*str))
            case 97: // can also just use 'a', 'e' here - chars are mini ints remember? 
            case 101:
            case 105:
            case 111:
            case 117:
                *str = toupper(*str);
                break;
            default: 
                *str = tolower(*str);
                break;
        }

        str += 1;
    }
}