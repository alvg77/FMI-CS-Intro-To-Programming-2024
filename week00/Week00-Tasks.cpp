#include <iostream>

void task0();
void task1();
void task2();
void task3();
void task4();
void task5();
void task6();
void task7();

int max(int, int);
int min(int, int);

int main()
{
    task0();
    task1();
    task2();
    task3();
    task4();
    task5();
    task6();
    task7();

    return 0;
}

void task0() {
    std::cout << "Something about coffee" << std::endl;
}

void task1() {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    std::cin.ignore(10000, '\n');

    int digits[3] = { number / 100, (number / 10) % 10, number % 10 };

    std::cout << "first digit: " << digits[0] << std::endl;
    std::cout << "second digit: " << digits[1] << std::endl;
    std::cout << "third digit: " << digits[2] << std::endl;

    std::cout << "sum: " << digits[0] + digits[1] + digits[2];
}

void task2() {
    int a, b;
    std::cin >> a >> b;
    std::cin.ignore(10000, '\n');

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    a = a + b;
    b = a - b;
    a = a - b;

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
}

void task3() {
    int a, b;
    std::cin >> a >> b;
    std::cin.ignore(10000, '\n');
    std::cout << "num 1: " << a << ", num 2: " << b << " -> " << (a % b == 0 ? 1 : 0) << std::endl;
}

void task4() {
    int a, b;
    std::cin >> a >> b;
    std::cin.ignore(10000, '\n');
    std::cout << a * b << " - " << ((a * b) % 2 == 0 ? 1 : 0) << std::endl;
}

void task5() {
    int a, b, c;
    std::cin >> a >> b >> c;
    std::cin.ignore(10000, '\n');
    std::cout << ((a + b > c && a + c > b && b + c > a) == 1 ? "true" : "false") << std::endl;
}

void task6() {
    int a, b, c;
    std::cin >> a >> b >> c;
    std::cin.ignore(10000, '\n');
    std::cout << max(a, max(b, c)) << ", " << min(a, min(b, c));
}

void task7() {
    int num;
    int intervalStart, intervalEnd;

    std::cin >> num;
    std::cin >> intervalStart >> intervalEnd;
    std::cin.ignore(10000, '\n');

    if (num >= intervalStart && num <= intervalEnd) {
        std::cout << "true" << std::endl;
    }
    else {
        std::cout << "false" << std::endl;
    }
}

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}
