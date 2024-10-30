#include <iostream>

void swap(int a, int b);
bool isEven(int num);
double pow(double num, int power);
double min(double a, double b);
double max(double a, double b);
double minOf3(double a, double b, double c);
double maxOf3(double a, double b, double c);
bool isAlpha(char c);
bool isDigit(char c);
void matrix(int n, int m);
void printSquare(double x);
double findLargest(double a, double b, double c);
double deposit(double balance, double amount);
double withdraw(double balance, double amount);
void checkBalance(double balance);
int countDigit(int num, int digit);
bool risingSequence(double n[], size_t size);

int main() {
    matrix(3, 4);

    return 0;
}

void swap(int a, int b) {
    std::cout << "Value for a: " << a << std::endl;
    std::cout << "Value for b: " << b << std::endl;

    a += b;
    b = a - b;
    a = a - b;

    std::cout << "Value for a: " << a << std::endl;
    std::cout << "Value for b: " << b << std::endl;
}

bool isEven(int num) {
    return num % 2;
}

double pow(double num, int power) {
    for (int i = 0; i < power; ++i) {
        num *= power;
    }
    return num;
}

double min(double a, double b) {
    return (a > b) ? b : a;
}

double max(double a, double b) {
    return (a > b) ? a : b;
}

double minOf3(double a, double b, double c) {
    return min(a, min(b, c));
}

double maxOf3(double a, double b, double c) {
    return max(a, max(b, c));
}

bool isAlpha(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

void matrix(int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == j) {
                std::cout << i << " ";
            } else if (i < j) {
                std::cout << j-i << " ";
            } else if (i > j) {
                std::cout << j*i << " ";
            }
        }
        std::cout << std::endl;
    }
} 

void printSquare(double x) {
    std::cout << pow(x, 2) << std::endl;
}

double findLargest(double a, double b, double c) {
    return maxOf3(a, b, c);
}

double deposit(double balance, double amount) {
    return balance + amount;
}

double withdraw(double balance, double amount) {
    return balance - amount;
}

void checkBalance(double balance) {
    std::cout << balance << std::endl;
}

int countDigit(int num, int digit) {
    int count = 0;
    while (num > 0) {
        if (num % 10 == digit) {
            ++count;
        }
        num /= 10;
    }

    return count;
}

bool risingSequence(double n[], size_t size) {
    size_t i = 0; 
    while (n[i] <= n[i + 1] && i < size) {
        ++i;
    }
    return i == size;
}