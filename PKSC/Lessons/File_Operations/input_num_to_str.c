#include <stdio.h>

int len(char *s) {
    int i = 0;

    while (s[i] != '\0') {
        i++;
    }

    return i;
}

void rev(char *s) {
    int length = len(s);
    int i;
    char temp;

    for (i = 0; i < length / 2; i++) {
        temp = s[i];
        s[i] = s[length - 1 - i];
        s[length - 1 - i] = temp;
    }
}

void copy(char *t, char *s) {
    int i = 0;

    while (s[i] != '\0') {
        t[i] = s[i];
        i++;
    }

    t[i] = '\0';
}

void to_string(int s, char *t) {
    char temp[10];
    int i = 0;

    while (s > 0) {
        temp[i] = (s % 10) + '0';
        s /= 10;
        i++;
    }

    temp[i] = '\0';

    rev(temp);
    copy(t, temp);
}

int main() {
    int num;
    char snum[10];

    printf("Enter a number: ");
    scanf("%d", &num);

    to_string(num, snum);

    printf("String is %s\n", snum);

    return 0;
}