#include <iostream>

const size_t SIZE = 256;

void print_chars(const char str[]);
bool contains(const char str[], char c);
int strlength(const char str[]);
void to_upper(const char str[]);
void to_lower(const char str[]);
void to_lower_upper(const char str[]);
char* get_substring(const char str[], const size_t start, const size_t end);
void manipulateStr(char str[]);
char* enumerate_letters(const char str[]);
void reverse_pairs(char str[]);
bool is_palindrome(const char str[]);

bool is_lowercase(char c);
bool is_uppercase(char c);
bool is_letter(char c);
void shift_left(char str[], int start_idx, int positions);

int main() {

    // task 1
    // print_chars("Hello, World!");

    // task 2
    // std::cout << std::boolalpha << contains("ABCD", 'C') << std::endl;
    // std::cout << std::boolalpha << contains("ABCD", 'c') << std::endl;

    // task 3
    // std::cout << strlength("12345") << std::endl;

    // task 4
    

    return 0;
}

void print_chars(const char str[]) {
    int i = 0;
    while (str[i]) {
        std::cout << str[i++] << std::endl;
    }
}

bool contains(const char str[], char c) {
    int i = 0;
    while (str[i]) {
        if (str[i++] == c) {
            return true;
        }
    }

    return false;
}

int strlength(const char str[]) {
    int counter = 0;
    while (str[counter++]);

    return counter-1;
}

void to_upper(char str[]) {
    int i = 0;
    while (str[i]) {
        if (is_lowercase(str[i])) {
            str[i] += 'A' - 'a';
        }
        ++i;
    }
}

void to_lower(char str[]) {
    int i = 0;
    while (str[i]) {
        if (is_uppercase(str[i])) {
            str[i] -= 'A' - 'a';
        }
        ++i;
    }
} 

void to_upper_lower(char str[]) {
    int i = 0;
    int to_upper = true;

    while (str[i]) {
        if (to_upper && is_lowercase(str[i])) {
            str[i] += 'A' - 'a';
        } else if (!to_upper && is_uppercase(str[i])) {
            str[i] -= 'A' - 'a';
        }

        if (is_letter(str[i])) {
            to_upper = !to_upper;
        }

        ++i;
    }
}

char* get_substring(const char str[], const size_t start, const size_t end) {
    char* new_str = new char[SIZE];
    int i = start;
    int j = 0;
    while (str[i] && i <= end && j <= 254) {
        new_str[j++] = str[i];
        ++i;
    }
    new_str[j] = '\0';

    return new_str;
}

void manipulateStr(char str[]) {
    bool first_letter = true;
    int i = 0;

    while (str[i]) {
        if (is_lowercase(str[i]) && first_letter) {
            str[i] += 'A' - 'a';
            first_letter = false;
        } else if (is_uppercase(str[i]) && !first_letter) {
            str[i] -= 'A' - 'a';
        } else if (str[i] == ' ') {
            shift_left(str, i, 1);
            first_letter = true;
        }

        ++i;
    }
}

char* enumerate_letters(const char str[]) {
    char *new_str = new char[strlength(str) * 2];
    int letters[26]{0};
    int i = 0;

    while (str[i]) {
        if (is_uppercase(str[i])) {
            letters[str[i] - 'A'] += 1;
        } else if (is_lowercase(str[i])) {
            letters[str[i] - 'a'] += 1;
        }
        ++i;
    }

    i = 0;
    while(str[i]) {
        new_str[i] = str[i];
        if (is_uppercase(str[i])) {
            new_str[i+1] = letters[str[i] - 'A'];
        } else if (is_lowercase(str[i])) {
            new_str[i+1] = letters[str[i] - 'a'];
        }
        i+=2;
    }

    return new_str;
}

void shift_left(char str[], int start_idx, int positions) {
    if (start_idx < 0) {
        return;
    }

    if (positions <= 0) {
        return;
    }

    int i = start_idx;
    int j = start_idx + positions;
    while (str[i] && str[j]) {
        str[i] = str[j];
        ++i;
        ++j;
    }

    if (str[i] && str[j] == '\0') {
        str[i] = str[j];
    }
}

void reverse_pairs(char str[]) {
    int i = 0;
    int length = strlength(str);

    for (int i = 0; i < length; i += 2) {
        char temp = str[i];
        str[i] = str[i+1];
        str[i+1] = temp;
    }
}

bool is_palindrome(const char str[]) {
    int i = 0;
    int j = strlength(str) - 1;

    while (i < j) {
        if (str[i] != str[j]) {
            return false;
        }
    }

    return true;
}

bool is_lowercase(const char c) {
    return c >= 'a' || c <= 'z';
}

bool is_uppercase(const char c) {
    return c >= 'A' || c <= 'Z';
}

bool is_letter(const char c) {
    return is_lowercase(c) || is_uppercase(c);
}
