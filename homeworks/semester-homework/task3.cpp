#include <iostream>

void segmentTweet(const char* str);
void printTweet(const char* str, int segment_start, int segment_end, int segment_n);
bool isValidTweet(const char* str);
unsigned cppstrlen(const char* str);
bool isWhitespace(const char c);

int main() {
    const char* tweet = "Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in volup tate velit esse cillum dolore eu fugiat nulla pariatur. asdfsfasdasdfasdfsfasdasdfasdfsfasdasdfasdfsfasdasdfasdfsfasdasdfasdfsfasdasdfasdfsfasdasdfasdfsfasdasdfasdfsfasdasdfasdfsfasdasdfasdfsfasdasdfasdfsfasdasdfas Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in volup tate velit esse cillum dolore eu fugiat nulla pariatur. asdfsfasdasdfasdfsfasdasdfasdfsfasdasdfasdfsfasdasdfasdfsfasdasdfasdfsfasdasdfasdfsfasdasdfasdfsfasdasdfasdfsfasdasdfasdfsfasdasdfasdfsfasdasdfasdfsfasdasdfas Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in volup tate velit esse cillum dolore eu fugiat nulla pariatur. asdfsfasdasdfasdfsfasdasdfasdfsfasdasdfasdfsfasdasdfasdfsfasdasdfasdfsfasdasdfasdfsfasdasdfasdfsfasdasdfasdfsfasdasdfasdfsfasdasdfasdfsfasdasdfasdfsfasdasdfas Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in volup tate velit esse cillum dolore eu fugiat nulla pariatur. asdfsfasdasdfasdfsfasdasdfasdfsfasdasdfasdfsfasdasdfasdfsfasdasdfasdfsfasdasdfasdfsfasdasdfasdfsfasdasdfasdfsfasdasdfasdfsfasdasdfasdfsfasdasdfasdfsfasdasdfas";

    if (isValidTweet(tweet)) {
        segmentTweet(tweet);
    } else {
        std::cout << "Tweet cannot contain words above 280 characters!" << std::endl;
    }

    return 0;
}

void segmentTweet(const char* str) {
    int segment_end = 280;
    int segment_start = 0;
    int tweetLength = cppstrlen(str);
    int segment_n = 0;

    while (segment_start < tweetLength) {
        if (segment_end >= tweetLength) {
            segment_end = tweetLength - 1;
        } else {
            while (segment_end > segment_start && !isWhitespace(str[segment_end])) {
                segment_end -= 1;
            }
        }

        printTweet(str, segment_start, segment_end, segment_n);

        segment_start = segment_end + 1;
        segment_end = segment_start + 280;
        
        ++segment_n;
    }
}

void printTweet(const char* str, int segment_start, int segment_end, int segment_n) {    
    for (int j = 0; j < segment_n; ++j) {
        std::cout << "-----";
    }
    std::cout << "Traicho tweeted: ";
    for (int i = segment_start; i <= segment_end; ++i) {
        std::cout << str[i];
    }
    std::cout << std::endl;
}

bool isValidTweet(const char* str) {
    int counter = 0;
    int i = 0;
    
    while (str[i] != '\0') {
        if (str[i] == ' ') {
            if (counter > 280) {
                return false;
            }
            counter = 0;
        }

        ++counter;
        ++i;
    }

    return counter <= 280;
}

unsigned cppstrlen(const char* str) {
    unsigned counter = 0;

    while (str[counter] != '\0') {
        ++counter;
    }

    return counter;
}

bool isWhitespace(const char c) {
    return c == ' ' || c == '\t' || c == '\n';
}
