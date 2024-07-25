#include <stdio.h>

int romanToInt(char* s) {
    int num = 0;

    while (*s) {
        if (*s == 'M') {
            num += 1000;
        } else if (*s == 'D') {
            num += 500;
        } else if (*s == 'C') {
            if (*(s + 1) == 'M') {
                num += 900;
                s++;
            } else if (*(s + 1) == 'D') {
                num += 400;
                s++;
            } else {
                num += 100;
            }
        } else if (*s == 'L') {
            num += 50;
        } else if (*s == 'X') {
            if (*(s + 1) == 'C') {
                num += 90;
                s++;
            } else if (*(s + 1) == 'L') {
                num += 40;
                s++;
            } else {
                num += 10;
            }
        } else if (*s == 'V') {
            num += 5;
        } else if (*s == 'I') {
            if (*(s + 1) == 'X') {
                num += 9;
                s++;
            } else if (*(s + 1) == 'V') {
                num += 4;
                s++;
            } else {
                num += 1;
            }
        }
        s++;
    }

    return num;
}

int main() {
    char s[] = "MCMXCIV";
    printf("Roman numeral %s is %d\n", s, romanToInt(s));  // Output should be 1994
    return 0;
}
