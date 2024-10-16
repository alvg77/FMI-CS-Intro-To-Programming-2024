#include <iostream>
#include <cmath>

void task0();
void task1();
void task2();
void task3();
void task4();
void task5();
void task6();
void task7();
void task8();

int main() {

    task0();
    task1();
    task2();
    task3();
    task4();
    task5();
    task6();
    task7();
    task8();

    return 0;
}

void task0() {
    int n;
    long factorial = 1;
    std::cin >> n;

    for (int i = n; i >= 2; --i) {
        factorial *= i;
    }

    std::cout << factorial << std::endl;
}

void task1() {
    int members;
    std::cin >> members;

    for (int i = 1; i <= members; ++i) {
        std::cout << "a" << i << ": " << i*i + 3*i << std::endl;
    }
}

void task2() {
    int n;
    int biggestNegative = 0;

    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int temp;
        std::cin >> temp;

        if (biggestNegative == 0 && temp < 0 || biggestNegative < temp && temp < 0) {
            biggestNegative = temp;
        }
    }

    if (biggestNegative == 0) {
        std::cout << "No negative elements were entered!" << std::endl;
    } else {
        std::cout << biggestNegative << std::endl;
    }
}

void task3() {
    int n;
    int prev = 0, curr = 1;
    std::cin >> n;

    if (n == 1) {
        std::cout << 0 << std::endl;
        return;
    }

    for(int i = 0; i < n - 2; ++i) {
        curr += prev;
        prev = curr - prev;
    }

    std::cout << curr << std::endl;
}

void task4() {
    int temp;
    int sum = 0;

    do {
        std::cin >> temp;
        sum += temp;
    } while (temp != 0);

    std::cout << sum;
}

void task5() {
    int num;
    int sum = 0;

    std::cin >> num;

    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }
    
    std::cout << sum << std::endl;
}

void task6() {
    int num;
    int pow;

    int result = 1;

    std::cin >> num >> pow;

    if (pow != 0) {
        for (int i = 0; i < pow; ++i) {
            result *= num;
        }
    }

    std::cout << result << std::endl;
}

void task7() {
    for (char i = 'B'; i <= 'Z'; ++i) {
        if (i != 'E' && i != 'I' && i != 'O' && i != 'U' && i != 'Y') {
            std::cout << i << " ";
        }
    }
}

void task8() {
    int n;
    
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            std::cout << "-";
        }

        std::cout << 0;

        for (int j = 0; j < n-i-1; j++) {
            std::cout << "+";
        }

        std::cout << std::endl;
    }
} 
