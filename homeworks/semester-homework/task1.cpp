#include <iostream>

void getNextDate(unsigned day, unsigned month, unsigned year);
void displayDate(unsigned day, unsigned month, unsigned year);
const char* getWeekDay(unsigned day, unsigned month, unsigned year);
const char* getMonth(unsigned month);
unsigned getMonthDays(unsigned month, unsigned year);
bool isLeapYear(unsigned year);

int main() {
    int day;
    int month;
    int year;

    std::cout << "Day: ";
    std::cin >> day;
    std::cout << "Month: ";
    std::cin >> month;
    std::cout << "Year: ";
    std::cin >> year;

    getNextDate(day, month, year);

    return 0;
}

void getNextDate(unsigned day, unsigned month, unsigned year) {
    if (day < 1 || day > getMonthDays(month, year)) {
        std::cout << "Invalid value for day number!" << std::endl;
        return;
    } 

    unsigned monthDays = getMonthDays(month, year);
    if (monthDays == 0) {
        std::cout << "Invalid value for month number!" << std::endl;
        return;
    }

    if (year < 1900 || year > 2100) {
        std::cout << "Invalid value for year number!" << std::endl;
        return;
    }
    
    if (day == monthDays) {
        if (month == 12) {
            month = 1;
            ++year;
        } else {
            ++month;
        }
        day = 1;
    } else {
        ++day;
    }

    displayDate(day, month, year);
}

void displayDate(unsigned day, unsigned month, unsigned year) {
    const char* weekDayString = getWeekDay(day, month, year);
    const char* monthString = getMonth(month);

    if (weekDayString == nullptr) {
        std::cout << "Cannot calculate weekday!";
        return;
    }

    if (monthString == nullptr) {
        std::cout << "Invalid month index!";
        return;
    }

    std::cout << weekDayString << ", " << day << " " << monthString << ", " << year << std::endl;
}

// using Zeller's congruence formula
const char* getWeekDay(unsigned day, unsigned month, unsigned year) {
    if (month == 1) {
        month = 13;
        year--;
    }

    if (month == 2) {
        month = 14;
        year--;
    }

    unsigned yearOfCentury = year % 100;
    unsigned century = year / 100;

    unsigned weekday = (day + 13 * (month + 1) / 5 + yearOfCentury + yearOfCentury / 4 + century / 4 + 5 * century) % 7;

    switch (weekday) {
        case 0: return "Saturday";
        case 1: return "Sunday";
        case 2: return "Monday";
        case 3: return "Tuesday";
        case 4: return "Wednesday";
        case 5: return "Thursday";
        case 6: return "Friday";
        default: return nullptr;
    }
}

const char* getMonth(unsigned month) {
    switch (month) {
        case 1: return "January";
        case 2: return "February";
        case 3: return "March";
        case 4: return "April";
        case 5: return "May";
        case 6: return "June";
        case 7: return "July";
        case 8: return "August";
        case 9: return "September";
        case 10: return "October";
        case 11: return "November";
        case 12: return "December";
        default: return nullptr;
    }
}

unsigned getMonthDays(unsigned month, unsigned year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 2: 
            return 28 + isLeapYear(year);
        case 4: case 6: case 9: case 11: 
            return 30;  
        default: 
            return 0;  
    }
}

bool isLeapYear(unsigned year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
