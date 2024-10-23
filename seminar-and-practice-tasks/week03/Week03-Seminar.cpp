#include <iostream>
#include <cmath>

std::string toBinaryStr(unsigned);
unsigned toBinary(unsigned);
void cubes(unsigned);
void sequence(unsigned);
void primes(unsigned);
double combinations(unsigned long, unsigned long);
bool magicNumber(unsigned);
unsigned biggestDigitSum(unsigned);
void printSatisfyingPredicates(unsigned);
unsigned diffBiggestSmallestDigit(unsigned);

unsigned long factorial(unsigned long);
unsigned digitSum(unsigned);
bool isPrime(unsigned);

int main() {
    // task 1
    // std::cout << toBinary(13) << std::endl;
    // task 2
    //  cubes(900);
    // task 3
    //  sequence(6);
    // task 4
    // primes(5);
    // task 5
    // std::cout << combinations(10, 4) << std::endl;
    // task 6
    // std::cout << std::boolalpha << magicNumber(28) << std::endl;
    // task 7
    // std::cout << biggestDigitSum(4) << std::endl;
    // task 8
    // printSatisfyxingPredicates(7);

    return 0;
}

std::string toBinaryStr(unsigned num) {
    std::string binary = "";

    while (num != 0) {
        if (num % 2 == 0) {
            binary.insert(0, "0");
        } else {
            binary.insert(0, "1");
        }
        num /= 2;
    }
    return binary;
}

unsigned toBinary(unsigned num) {
    unsigned binary = 0;
    unsigned counter = 0;

    while (num != 0) {
        binary += std::pow(10, counter++) * (num % 2);
        num /= 2;
    }
    return binary;
}

void cubes(unsigned num) {
    unsigned i = 1, cube = 1;

    while (num > cube) {
        std::cout << cube << " ";
        cube = std::pow(++i, 3);
    }

    std::cout << std::endl;
}

void sequence(unsigned n) {
    for (unsigned i = 1; i <= n; ++i) {
        std::cout << 2 * i * i * i + 3 * i << " ";
    }
    std::cout << std::endl;
}

void primes(unsigned n) {
    for (unsigned i = 2; i < n; ++i) {
        bool isPrime = true;
        unsigned j = 2;
        while (j <= std::sqrt(i) && isPrime) {
            if (i % j == 0) {
                isPrime = false;
            }
            ++j;
        }

        if (isPrime) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}

double combinations(unsigned long n, unsigned long k) {
    return static_cast<double>(factorial(n)) /
           static_cast<double>((factorial(k) * factorial(n - k)));
}

bool magicNumber(unsigned n) {
    unsigned sum = 0;
    for (unsigned i = 1; i < n; ++i) {
        if (n % i == 0) {
            sum += i;
        }
    }

    return sum == n;
}

unsigned biggestDigitSum(unsigned n) {
    unsigned biggest = 0, biggestSum = 0;

    for (unsigned i = 0; i < n; ++i) {
        unsigned num, sum;
        std::cin >> num;
        sum = digitSum(num);

        if (biggestSum < sum) {
            biggest = num;
            biggestSum = sum;
        }
    }

    return biggest;
}

void printSatisfyingPredicates(unsigned n) {
    unsigned count = 0;
    unsigned i = 10;

    while (count < n) {
        if (isPrime(digitSum(i)) && diffBiggestSmallestDigit(i) == 3) {
            std::cout << i << std::endl;
            ++count;
        }
        ++i;
    }
}

bool isPrime(unsigned num) {
    unsigned i = 2;

    while (i <= sqrt(num)) {
        if (num % i == 0) return false;
        ++i;
    }
    return true;
}

unsigned long factorial(unsigned long n) {
    unsigned long f = 1;
    for (unsigned i = n; i > 1; --i) {
        f *= i;
    }

    return f;
}

unsigned digitSum(unsigned num) {
    unsigned sum = 0;
    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

unsigned diffBiggestSmallestDigit(unsigned n) {
    unsigned min = n % 10, max = n % 10;
    n /= 10;
    while (n != 0) {
        unsigned digit = n % 10;
        if (digit > max) {
            max = digit;
        } else if (digit < min) {
            min = digit;
        }
        n /= 10;
    }
    return max - min;
}