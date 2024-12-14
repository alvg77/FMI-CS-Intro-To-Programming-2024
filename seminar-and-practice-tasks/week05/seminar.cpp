#include <iostream>
#include <cstring>
#include <cmath>

int strlen_rec(const char str[], int i) {
    if (!str[i]) {
        return i;
    }
    return strlen_rec(str, i+1);
}

void shift_characters(char str[], int start_idx, int positions) {
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
        int number = 0;
        while (is_numeric(source[i])) {
            number = number * 10 + (int) (source[i] - '0');
            ++i;
        }
        if (number == 0) {
            destination[j++] = source[i++];
        } else {
            for (int k = 0; k < number; ++k) {
                destination[j++] = source[i];
            }
            ++i;
        }
    }
}

int find_word(const char str[], const char word[]) {
    int i = 0, j = 0;
    int start = 0;
    while (str[i]) {
        if (word[j] == '\0') {
            return start;
        }

        if (str[i] == word[j]) {
            if (j == 0) {
                start = i;
            }
            j++;
        } else if (str[i] != word[j]) {
            start = j = 0;
        }
        ++i;
    }

    return -1;
}

void remove_word(char str[], const char word[]) {
    int index  = find_word(str, word);
    shift_characters(str, index, strlen_rec(word, 0)+1);
}

void reverse_sentence(char destination[], const char source[]) {
    int i = 0, size = 0;
    int dest_i = 0;
    while (source[i]) {
        ++i;
    }
    --i;
    while (i >= 0) {
        while (source[i] != ' ' && i >= 0) {
            --i;
            size++;
        }
        for (int j = i+1; j < i+size+1; j++) {
            destination[dest_i++] = source[j];
        }
        destination[dest_i++] = ' ';
        --i;
        size = 0;
    }
    destination[dest_i++] = '\0'; 
}

void replace_word(char str[], const char word1[], const char word2[]) {
    
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
    // char buffer[255];
    // decode(buffer, "a2b10c");
    // std::cout << buffer << '\n'; // -> abbcccccccccc

    // task 6
    // std::cout << find_word("I am the best programmer ever", "programmer") << '\n'; // -> 14

    // task 7
    // char str[] = "I am the best programmer ever";
    // remove_word(str, "programmer");
    // std::cout << str << '\n'; // -> I am the best ever

    // task 8
    // char buffer[255];
    // reverse_sentence(buffer, "May the force be with you");
    // std::cout << buffer << '\n'; // -> you with be force the May

    // task 9
    char str[] = "I am the best programmer ever";
    replace_word(str, "programmer", "boxer");
    std::cout << str << '\n'; // -> I am the best boxer ever

    return 0;
}