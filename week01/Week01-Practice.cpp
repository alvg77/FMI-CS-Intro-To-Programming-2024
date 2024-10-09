#include <iostream>

void task0();
bool task1(int);
void task2();
void task3();
void task4();
void task5();
void task6();
void task7();
void bonus0();

bool salad(int, int, int, int, int, int);
bool soup(int, int, int, int, int, int);
bool stew(int, int, int, int, int, int);

bool biggestFirstDigit(int);

int main() {
    task0();
    std::cout << std::boolalpha << task1(2000) << std::endl;
    task2();
    task3();
    task4();
    task5();
    task6();
    task7();
    bonus0();
    return 0;
}

void task0() {
    double a, b;
    char sign;

    std::cin >> a >> b;
    std::cin.ignore(10000, '\n');
    std::cin >> sign;

    switch (sign) {
        case '+':
            std::cout << a + b << std::endl;
        break;
        case '-':
            std::cout << a - b << std::endl;
        break;
        case '*':
            std::cout << a * b << std::endl;
        break;
        case '/':
            std::cout << a / b << std::endl;
        break;
        default:
            std::cout << "Invalid operation" << std::endl;
        break;
    }
}

bool task1(int year) {
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

void task2() {
    char symbol;

    std::cin >> symbol;
    std::cin.ignore(10000, '\n');

    if ((symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z')) {
        std::cout << "letter" << std::endl;
    } else if (symbol >= '0' && symbol <= '9') {
        std::cout << "number" << std::endl;
    } else {
        std::cout << "special character" << std::endl;
    }
}

void task3() {
    short month;
    std::cout << "Enter a month: " << std::endl;
    std::cin  >> month;

    if (month == 0) {
        std::cout << "0 is not a valid month!" << std::endl;
        return;
    }

    switch ((month % 12) + 1) {
        case 1: case 2: case 12:
            std::cout << "Winter" << std::endl;
            break;
        case 3: case 4: case 5:
            std::cout << "Spring" << std::endl;
            break;
        case 6: case 7: case 8:
            std::cout << "Summer" << std::endl;
            break;
        case 9: case 10: case 11:
            std::cout << "Fall" << std::endl;
            break;
        default:
            std::cout << "Something went wrong" << std::endl;
    }
}

void task4() {
    int a, b;
    std::cout << "Enter a and b for ax + b = 0" << std::endl;
    std::cin >> a >> b;

    if ((a == 0 && b != 0) || (a != 0 && (-b % a == 0))) {
        std::cout << "NO" << std::endl;
    } else if ((b == 0 && a == 0) || (a != 0 && b == 0)) {
        std::cout << "INF" << std::endl;
    } else if (a != 0 && b != 0) {
        std::cout << "x=" << -b/a << std::endl;
    }
}

// quadratic

void task5() {
    int month, year;
    std::cout << "Enter month and year: " << std::endl;
    std::cin >> month >> year;

    if (month < 1 || month > 12) {
        std::cout << "Invalid input" << std::endl;
        return;
    }

    switch (month) {
        case 2:
            if (task1(year)) std::cout << 29 << std::endl;
            else std::cout << 28 << std::endl;
            break;
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            std::cout << 31 << std::endl;
            break;
        case 4: case 6: case 9: case 11:
            std::cout << 30 << std::endl;
            break;
        default:
            std::cout << "Something went wrong" << std::endl;
    }
}

void task6() {
    short price, usbPorts, ram;
    bool ssd;

    std::cin >> price;
    std::cin >> usbPorts;
    std::cin >> ram;
    std::cin >> ssd;

    bool wouldBuy = ((price > 1000 && price < 1500) && usbPorts >= 3 && ram >= 8 && ssd) ||
                    (price <= 800 && (!ssd || ram < 8) && usbPorts >= 3);

    std::cout << std::boolalpha << wouldBuy << std::endl;
}

void task7() {
    int num;
    std::cin >> num;

    if (biggestFirstDigit(num) && (num/1000)%2 == 1) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}

void bonus0() {
    int tomatoes;
    int peppers;
    int carrots;
    int olives;
    int potatoes;
    int flavouring;

    bool traichoWillEat = false;

    std::cin >> tomatoes >> peppers >> carrots >> olives >> potatoes >> flavouring;

    if (salad(tomatoes, peppers, carrots, olives, potatoes, flavouring)) {
        std::cout << "Salad" << std::endl;
        traichoWillEat = true;
    }

    if (soup(tomatoes, peppers, carrots, olives, potatoes, flavouring)) {
        std::cout << "Soup" << std::endl;
        traichoWillEat = true;
    }

    if (stew(tomatoes, peppers, carrots, olives, potatoes, flavouring)) {
        std::cout << "Stew" << std::endl;
        traichoWillEat = true;
    }

    if (!traichoWillEat) {
        std::cout << "Traicho will not eat" << std::endl;
    }
}

bool salad(int tomatoes, int peppers, int carrots, int olives, int potatoes, int flavouring) {
    return tomatoes >= 1 && peppers >= 2 && carrots >= 3 && olives >= 3 && potatoes >= 3 && flavouring >= 150;
}

bool soup(int tomatoes, int peppers, int carrots, int olives, int potatoes, int flavouring) {
    return tomatoes >= 1 && peppers >= 2 && carrots >= 3 && olives >= 3 && potatoes >= 3 && flavouring >= 150;
}

bool stew(int tomatoes, int peppers, int carrots, int olives, int potatoes, int flavouring) {
    return tomatoes >= 1 && peppers >= 2 && carrots >= 3 && olives >= 3 && potatoes >= 3 && flavouring >= 150;
}

bool biggestFirstDigit(const int num) {
    const int fist = num / 1000;
    int n = num - fist * 1000;
    while (n != 0) {
        if (fist <= n % 10) {
            return false;
        }
        n /= 10;
    }
    return true;
}
