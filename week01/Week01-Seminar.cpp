#include <iostream>
#include <cmath>

struct Point;

void task1();
void task2();
void task3();
void task4();
void task5();
void task6();
void task7();
void task8();

short digitCount(short);
double distanceBetweenPoints(Point, Point);

int main() {
    task1();
    task2();
    task3();
    task4();
    task5();
    task6();
    task7();
    task8();
}

struct Point {
    double x;
    double y;
};

void task1() {
    short num;
    short digit;

    bool correctDigits;

    do {
        std::cin >> num;
        correctDigits = digitCount(num) == 4;

        if (!correctDigits) 
            std::cout << "Enter a four digit number!" << std::endl;
    } while (!correctDigits);
    std::cin >> digit;
    std::cin.ignore(10000, '\n');

    // if (num / 1000 == digit || (num / 100) % 10 == digit || (num / 10) % 10 == digit || num % 10 == digit) { /* true */ } else { /* fasle */ }

    while (num != 0) {
        if (digit % 10 == digit) {
            std::cout << std::boolalpha << true << std::endl;
            return;
        }
    }

    std::cout << std::boolalpha << false << std::endl;
}

void task2() {
    short num;

    std::cin >> num;
    std::cin.ignore(10000, '\n');

    short firstTwoDigits = num / 1000 + (num / 100) % 10;
    short secondTwoDigits = (num / 10) % 10 + num % 10;

    if (firstTwoDigits == secondTwoDigits) {
        std::cout << "Number is magical" << std::endl;
    } else {
        std::cout << "Number is not magical" << std::endl;
    }
}

void task3() {
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

void task4() {
    Point point, center;
    double radius;

    std::cin >> point.x >> point.y;
    std::cin >> center.x >> center.y;
    std::cin >> radius;
    std::cin.ignore(10000, '\n');

    double distance = distanceBetweenPoints(point, center);

    // constexpr has compile time evaluation, can be used in such context
    constexpr double EPSILON = 10e-6;

    if (radius > distance) {
        std::cout << "Inside" << std::endl;
    // fabs is only for floating point numbers
    } else if (std::fabs(distance - radius) < EPSILON) {
        std::cout << "On" << std::endl;
    } else {
        std::cout << "Outside" << std::endl;
    }
}

void task5() {
    short age;
    std::cin >> age;

    std::cout << (age >= 18 ? "You are good to go" : "You are underage") << std::endl;
}

void task6() {
    // use only tenrary
    short a, b, c;

    std::cin >> a >> b >> c;

    short max = a > b && a > c ? a : b > c ? b : c;
    short min = a < b && a < c ? a : b < c ? b : c;
    short mid = a + b + c - max - mid;

    std::cout << max << " " << mid << " " << min << " " << std::endl;
}

void task7()  {
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

void task8() {
    char figureType;
    Point figurePoint, otherPoint;

    std::cin >> figureType;
    std::cin >> figurePoint.x >> figurePoint.y;
    std::cin >> otherPoint.x >> otherPoint.y;

    switch (figureType) {
    case 'r':
        std::cout << (figurePoint.x == otherPoint.x || figurePoint.y == otherPoint.y ? "Yes" : "No");
        break;
    case 'b':
        std::cout << (abs(figurePoint.x - otherPoint.x) == abs(figurePoint.y - otherPoint.y) ? "Yes" : "No"); 
        break;
    case 'q':
        // I LOVE TEnRARY OPERATORS
        std::cout << 
            (
                (
                    figurePoint.x == otherPoint.x || figurePoint.y == otherPoint.y) || 
                    (abs(figurePoint.x - otherPoint.x) == abs(figurePoint.y - otherPoint.y)
                ) 
                ? 
                    "Yes" 
                : 
                    "No"
            )
        << std::endl;
        break;
    case 'h':
        std::cout << (abs(figurePoint.y - otherPoint.y) * abs(figurePoint.x - figurePoint.x) == 2 ? "Yes" : "No");
        break;
    default:
        break;
    }
}

short digitCount(short num) {
    short count = 0;   
    while (num != 0) {
        count++;
        num /= 10;
    }

    return count;
}

double distanceBetweenPoints(Point A, Point B) {
    return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
}
