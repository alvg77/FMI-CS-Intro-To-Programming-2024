#include <iostream>
#include <cstring>
#include <cmath>

bool is_numeric(char c) {
    return c >= '0' && c <= '9';
}

bool is_whitespace(char c) {
    return c != ' ' && c != '\n' && c != '\t';
}

void to_upper_case(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] += 'A' - 'a';
        }
        ++i;
    }
}

int atoi(const char str[]) {
    int c = str[0] == '-';
    int i = c;

    int number = 0;
    while (str[i] && is_numeric(str[i])) {
        number = number*10 + (str[i] - '0');
        ++i;
    }

    return c ? number : -number;
}



std::size_t find_longest_word(const char str[]) {
    int longest_index = 0;
    int longest_len = 0;
    int i = 0;

    while (str[i]) {
        int len = 0;
        int word_start_index = i;
        if (is_whitespace(str[i])) {
            while (is_whitespace(str[i])) {
                ++len;
                ++i;
            }
        } else {
            ++i;
        }
        
        if (longest_len < len) {
            longest_len = len;
            longest_index = word_start_index;
        }
    }

    return longest_index;
}

void trim(char str[]) {
    int i = 0;
    int j = 0;
    int w_count = 0;

    while (str[i] && str[i] == ' ') {
        ++w_count;
        ++i;
    }

    while ((str[i] && str[i+1]) && !(str[i] == ' ' && str[i+1] == 0)) {
        str[j++] = str[i++];
    }

    str[j] = '\0';
}

void decode(char destination[], const char source[]) {
    int i = 0;
    int j = 0;
    while (source[i] && source[i + 1]) {
        int num_index = i + 1;
        while(is_numeric(source[num_index])) {

        }
        i += num_index;
    }
}

int main() {
    // task 1 
    // char str[] = "Hello Jimmy!";
    // to_upper_case(str);
    // std::cout << str << '\n'; // -> HELLO JIMMY!

    // task 2
    // std::cout << atoi("123filler") + atoi("-81morefiller") << '\n'; // -> 42

    //task 3
    // std::cout << find_longest_word("Hello, my name is Ivancho") << '\n'; // -> 18

    // task 4
    // char str[] = "    Hello World     ";
    // trim(str);
    // std::cout << str << '\n'; // -> Hello World

    // task 5
    return 0;
}