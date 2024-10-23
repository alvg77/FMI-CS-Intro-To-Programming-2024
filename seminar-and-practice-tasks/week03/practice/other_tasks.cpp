#include <iostream>

void numSwap(int&, int&); // task 1
bool isEven(int); // task 1
double pow(double, int); // task 2 
double min(double, double);
double max(double, double);
double minOf3(double, double, double);
double maxOf3(double, double, double);
bool isAlpha(char);
bool isDigit(char);
void matrix(int, int); // task 3
void square(double); // task 4
double biggest(double, double, double); // task5

int main() {
    int a = 10, b = 5;
    numSwap(a, b);

    std::cout << std::boolalpha << isEven(10) << std::endl;


    return 0;
}

void numSwap(int& a, int& b) {
    a = a + b;
    b = a - b;
}

bool isEven(int num) {
    return !(num%2); 
}