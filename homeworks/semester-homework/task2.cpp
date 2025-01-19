#include <iostream>
#include <cmath>

const unsigned MAX_LENGTH = 256;
const unsigned ALPHABET = 26;
 
void transformNumber(unsigned long number, char* str);
unsigned getNumberDigitNum(unsigned long number);

int main() {
    unsigned long number;
    std::cin >> number;

    char str[MAX_LENGTH];
    transformNumber(number, str);
    std::cout << str << std::endl;

    return 0;
}

void transformNumber(unsigned long number, char* str) {
    unsigned digitCount = getNumberDigitNum(number);
    unsigned i = 0;
    unsigned long long offset = (digitCount >= 1) ? pow(10, digitCount - 1) : 1;

    while (digitCount > 0 && i < MAX_LENGTH - 1) {
        unsigned digits = 0;

        digits = (number / offset) % 10;
        if (digitCount > 1 && digits > 0 && digits < 3) {
            offset /= 10;
            unsigned digitsExpanded = digits * 10 + ((number / offset) % 10);
            if (digitsExpanded <= ALPHABET) {
                --digitCount;
                digits = digitsExpanded;
            }
        }

        --digitCount;

        str[i++] = digits == 0 ? '.' : 'a' + digits - 1;

        if (digitCount >= 1) {
            offset = pow(10, digitCount - 1);
        }
    }

    str[i] = '\0';
}

unsigned getNumberDigitNum(unsigned long number) {
    unsigned counter = 0;
    while (number != 0) {
        number /= 10;
        ++counter;
    }

    return counter;
}
