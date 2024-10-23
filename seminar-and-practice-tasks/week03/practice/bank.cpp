#include <iostream>
#include <limits>

// global variables bad, but otherwise i literally have to do double checkBalance(double x) { return x; }
double balance = 0;

void withdraw(double amount) {
    if (amount > balance) {
        std::cout << "Insufficient balance" << std::endl;
    } else {
        std::cout << "Withdrawal successful" << std::endl;
        balance -= amount;
    }
}

void deposit(double amount) {
    if (amount <= 0) {
        std::cout << "You need to deposit a positive number of money" << std::endl;
    } else {
        std::cout << "Deposit successful";
        balance += amount;
    }
}

double checkBalance() {
    return balance;
}

int main() {
    deposit(1000);
    withdraw(500);
    withdraw(200);
    withdraw(400);
    std::cout << checkBalance() << std::endl;
    deposit(400);
    std::cout << checkBalance() << std::endl;

    return 0;
}