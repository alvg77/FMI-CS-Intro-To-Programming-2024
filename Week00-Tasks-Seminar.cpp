#include <iostream>
#include <cmath>

struct Point;

void task1();
void task2();
void task3();
void task4();
void task4Advanced();
void task5();
void task6();
void task7();

int digitCount(int num);
double findSideLen(Point A, Point B);

int main() {
    task1();
    task2();
    task3();
    task4();
    task4Advanced();
    task5();
    task6();
    task7();
    return 0;
}

struct Point {
    int x;
    int y;
};

void task1() {
    std::cout << "Hello, World!" << std::endl;
}

void task2() {
    int a, b;
    std::cin >> a >> b;
    std::cin.ignore(10000, '\n');
    std::cout << "a+b=" << a + b << std::endl;
}

void task3() {
    int a, b;
    std::cin >> a >> b;
    std::cin.ignore(10000, '\n');
    
    a = a + b;
    b = a - b;
    a = a - b;

    std::cout << "a=" << a << " b=" << b << std::endl;
}

void task4() {
    int a;
    std::cin >> a;
    std::cin.ignore(10000, '\n');
    std::cout << a%10 << (a/10)%10 << (a/100)%10 << (a/1000) << std::endl;
}

void task4Advanced() {
    int a;
    int newNum;

    std::cin >> a;
    std::cin.ignore(10000, '\n');

    int aDigits = digitCount(a);

    for (int i = 0; i < aDigits; i++) {
        int digit = (int) (a / pow(10, (double) i)) % 10;
        
        newNum += (int) pow(10, (aDigits - i - 1))*digit;
    }

    std::cout << newNum << std::endl;
}

void task5() {
    char letter;
    std::cin >> letter;
    std::cin.ignore(10000, '\n');

    std::cout << (char) (letter - 32);
}

void task6() {
    Point A, B, C;
    std::cin >> A.x >> A.y;
    std::cin >> B.x >> B.y;
    std::cin >> C.x >> C.y;
    std::cin.ignore(10000, '\n');
    
    double a = findSideLen(C, B);
    double b = findSideLen(A, C);
    double c = findSideLen(A, B);

    double p = (a + b + c) / 2;

    std::cout << sqrt(p*(p-a)*(p-b)*(p-c)) << std::endl;
}  

void task7() {
    int year;
    std::cin >> year;
    std::cin.ignore(10000, '\n');
    std::cout << ((year % 100 == 0 && year % 400 == 0) || (year % 100 != 0 && year % 4 == 0) ? "true" : "false") << std::endl;
}

int digitCount(int num) {
    int sum = 0;
    while (num != 0) {
        num /= 10;
        sum++;
    }
    return sum;
}

double findSideLen(Point A, Point B) {
    double side1 = pow(abs((double) A.x - (double) B.x), 2);
    double side2 = pow(abs((double) A.y - (double) B.y), 2);

    return sqrt(side1 + side2);
} 
