#include <iostream>

bool checkPresenceOfOne(int n); // task 0 
bool validTimeInterval(unsigned short interval); // task 1
short getIntervalDiff(unsigned short first, unsigned short second);
short getResultIntoTimeForm(short result);
bool commonDivider(short num1, short num2); // task2
bool isCarSuitable(bool is_old, bool has_air_conditioning, int km, int horsePower, double price); // task 3
double calculateMuseumTicketPrice(int groupSize, double ticketPrice); // task 4
double getTicketDiscount(int groupSize);
void findNthSequenceMembers(int n);

int main() {
    // task 0
    // bool onePresent = checkPresenceOfOne(54321);
    // if (onePresent) {
    //     std::cout << "YES" << std::endl;
    // } else {
    //     std::cout << "NO" << std::endl;
    // }
    
    //task 1
    // unsigned short timeStart, timeEnd;
    // std::cin >> timeStart >> timeEnd;
    // if (getIntervalDiff(timeStart, timeEnd) == -1) {
	// std::cout << timeStart << " " << timeEnd << " -> INVALID" << std::endl;
    // } else {
    //     std::cout << getIntervalDiff(timeStart, timeEnd);
    // }

    // task 2
    // std::cout << std::boolalpha << commonDivider(6, 28) << std::endl;

    // task 3
    // bool old = true, airConditioning = true;
    // int km = 100000, horsePower = 80;
    // double price = 5000;
    // if (isCarSuitable(old, airConditioning, km, horsePower, price)) {
    //     std::cout << "will buy" << std::endl;
    // } else {
    //     std::cout << "won't buy" << std::endl;
    // }

    // task 4
    // int groupSize;
    // double ticketPrice;

    // std::cin >> groupSize >> ticketPrice;
    // std::cout << calculateMuseumTicketPrice(groupSize, ticketPrice) << std::endl;

    // task 5
    // int n;
    // std::cin >> n;
    // findNthSequenceMembers(n);

    return 0;
}

bool checkPresenceOfOne(int n) {
    while (n > 0 && n % 10 != 1) {
        n /= 10;
    }
    return n % 10 == 1;
}

bool validTimeInterval(unsigned short interval) {
    if (interval > 2359) {
	return false;
    }
    return interval % 100 <= 59 &&  interval/100 <= 24;
}

short getIntervalDiff(unsigned short first, unsigned short second) {
    if (!validTimeInterval(first) || !validTimeInterval(second)) {
	return -1;
    }
    
    short result = second - first;
    if (result < 0) {
    	result = 2400 - first + second;
    } else if (result == 0) {
        result = 2400;
    }
    
    result = getResultIntoTimeForm(result);
    
    return result;
}

short getResultIntoTimeForm(short result) {
    int minutes = result % 100;
    int hoursToAdd = 0;

    while (minutes >= 60){ 
	minutes -= 60;
	++hoursToAdd;
    }
    
    return ((result / 100) + hoursToAdd) * 100 + minutes;
}

bool commonDivider(short num1, short num2) {
    int d = 2;
    int min = num1 > num2 ? num2 : num1;
    while (d < min/2 && (num1%d == 0 && num2%(d*d) != 0)) {
        ++d;
    }
    return !(d == min/2);
}

bool isCarSuitable(bool is_old, bool has_air_conditioning, int km, int horsePower, double price) {
    return (
            is_old && (
                (has_air_conditioning && km < 115000 && horsePower >= 70 && price <= 6000) || 
                (!has_air_conditioning && km < 180000 && horsePower >= 60 && price <= 2000)) || 
            !is_old && 
                horsePower >= 70 && horsePower <= 90 && price <= 25000
           );
}

double calculateMuseumTicketPrice(int groupSize, double ticketPrice) {
    double fullPrice = groupSize * ticketPrice;
    double discount = getTicketDiscount(groupSize);


    return fullPrice - (fullPrice * discount) / 100;
}

double getTicketDiscount(int groupSize) {
    if (groupSize >= 5 && groupSize <= 10) {
        return 5;
    } else if (groupSize >= 11 && groupSize <= 20) {
        return 10;
    } else if (groupSize >= 21) {
        return 15;
    }

    return 0;
}

void findNthSequenceMembers(int n) {
    int nCounter = 0;
    int seqRepetitionCounter = 0;
    int seqNumber = 1;
    while (nCounter < n) {
        ++nCounter;
        ++seqRepetitionCounter;
        std::cout << seqNumber << " ";

        if (seqNumber == seqRepetitionCounter) {
            ++seqNumber;
            seqRepetitionCounter = 0;
        }
    }
    std::cout << std::endl;
}