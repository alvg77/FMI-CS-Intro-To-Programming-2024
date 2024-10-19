#include <iostream>
#include <limits>

void task1();
void task2();
void task3();
void task4();
void task5();
void task6();
void task7();
void task8();

int main() {
    task7();

    return 0;
}

void task1() {
    int a, b;
    int sum = 0;

    std::cin >> a >> b;

    for(int i = a; i <= b; ++i) {
        sum+=i;
    } 

    std::cout << sum << std::endl;
}

void task2() {
    unsigned int n;
    int max = std::numeric_limits<int>().min();

    for (int i = 0; i < n-1; ++i) {
        int temp;
        std::cin >> temp;
        max = std::max(temp, max);
    }

    std::cout << max << std::endl;
}

void task3() {
    int n;
    int nff = 1;

    std::cin >> n;

    for (int i = n; i > 0; i-=2) {
        nff *= i;
    }

    std::cout << "n!!=" << nff << std::endl;
}

void task4() {
    // 2**31 = 2 * 2**30 = 2 * (2**2)**15 = ...
    
    double x, result = 1;
    int n;

    std::cin >> x >> n;

    if (n < 0) {
        x = 1/x;
        n = -n;
    }

    if (n == 0) {
        std::cout << "pow(" << x << "," << n << ")=" << result << std::endl;
        return;
    }

    while (n != 0) {
        if (n % 2) {
            result *= x;
            n = n - 1;
        }
        x *= x;
        n = n / 2;
    }

    std::cout << "pow=" << result << std::endl;
}

void task5() {
    unsigned int n;
    bool prime = true;
    unsigned int i = 2;

    std::cin >> n;

    while (i <= sqrt(n) && prime) {
        if (n % i == 0) prime = false; 
        ++i;
    }

    if (prime) 
        std::cout << "A prime number" << std::endl;
    else  
        std::cout << "Not a prime number" << std::endl;
}

void task6() {
    unsigned int n;
    unsigned int fibP = 0, fibC = 1;
    unsigned int i = 2;

    std::cin >> n;

    if (n == 1) {
        std::cout << "0" << std::endl;
    } else {
        while (i < n) {
            fibC = fibC + fibP;
            fibP = fibC - fibP;
            ++i;
        }

        std::cout << fibC << std::endl;
    }
}

void task7() {
    unsigned int n;
    unsigned int sum = 1;
    
    std::cin >> n;

    for (int i = 2; i <= n/2; ++i) {
        if (n % i == 0) {
            std::cout << i << std::endl;
            sum += i;
        }
    }
    
    std::cout << sum << std::endl;
}

void task8() {
    int n;
    
    std::cin >> n;
    for (int i = 0; i < n/2+1; ++i) {
        for (int s = 0; s < n/2 - i+1/2; ++s) {
            std::cout << " ";
        }
        for (int d = 0; d < 2 * i + 1; ++d) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < n/2; ++i) {
        std::cout << " ";
    }
    std::cout << "|" << std::endl;
}

void task9() {
    unsigned int n;
    unsigned count = 0;

    std::cin >> n;

    while(n != 0) {
        ++count;
        n /= 10;
    } 

    std::cout << n << std::endl;
}

void task10(){
    unsigned int n;
    unsigned int sum = 0;

    std::cin >> n;

    while (n != 0) {
        sum += n%10;
        n/=10;
    }

    std::cout << n << std::endl;
}

void task11() {
    unsigned int a, b;
    unsigned int largest = 1;

    std::cin >> a >> b;

    for (int i = 2; i <= std::min(a, b); i++) {
        if (a % i == 0 && b % i == 0) {
            largest = i;
        }
    }

    std::cout << "largest: " << largest << std::endl;
}

void task12() {

}

void task13() {

}