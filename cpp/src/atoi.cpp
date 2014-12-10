#include "atoi.h"

#include <cmath>
#include <cstring>

const int ASCII_NUMBER_BASE = 48;

int myAtoi(const char *asciiString) {
    int integer = 0;

    int length = strlen(asciiString);
    for (int i = 0; i < length; i++) {
        int charIndex = length - 1 - i;

        if (charIndex == 0 && asciiString[charIndex] == '-') {
            integer *= -1;
            break;
        }

        int digit = asciiString[charIndex] - ASCII_NUMBER_BASE;

        integer += pow(10, i) * digit;
    }

    return integer;
}