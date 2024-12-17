#include <iostream>
#include <cmath>

const std::size_t ARR_SIZE = 255;

// task 1
int* find_longest_arithmetic_progression_subarray(int* arr, std::size_t size);

// task 2
double number_problem(double* arr, std::size_t size);

// task 3
bool is_anagram(const char* str1, const char* str2);

// task 4
long encode(const char* sentence, char* letters, int* codes, std::size_t size);

// task 5
unsigned max_gcd_connected_elements(unsigned matrix[][ARR_SIZE], int rows, int cols, unsigned k);
unsigned _max_gcd_connected_elements(unsigned matrix[][ARR_SIZE], bool used[][ARR_SIZE], int rows, int cols, unsigned k, int x, int y);
unsigned gcd(unsigned n1, unsigned n2);
bool is_valid(int rows, int cols, int x, int y);

int main() {
    // task 1 
    int arr1[] {0, 2, 4, 5, 2, 3, -1, -5, -9, -6, -3, 5};
    int arr2[] {3, 4, 5, 6, 7, 8, 1, 0, -1, -2, -3, -4, -5}; 
    int* ptr = find_longest_arithmetic_progression_subarray(arr2, 13);

    if (ptr != nullptr) {
        std::cout << *ptr << std::endl;
    }

    // task 2
    double arr3[] {1.6, 2.3, 3, 3.7, 4.4};
    std::cout << number_problem(arr3, 5) << std::endl;

    // task 3
    std::cout << std::boolalpha << is_anagram("LISTEN", "SILENT") << std::endl;

    // task 4  
    int codes[ARR_SIZE] {4, 2, 7, 9, 5, 3};
    char letters[ARR_SIZE] {'a', 'g', 'l', 'y', 'b', 'e'};

    const char* sentence = "The bigger they are, the harder they fall.";

    std::cout << encode(sentence, letters, codes, 6) << std::endl;

    // task 5
    unsigned k = 54;
    unsigned matrix[][ARR_SIZE] {
        { 24, 36, 32, 72 },
        { 68, 18, 44, 126 },
        { 92, 78, 90, 144 },
        { 84, 21, 36, 0 }
    };

    std::cout << max_gcd_connected_elements(matrix, 4, 4, k) << std::endl;

    return 0;
}

// task 1
int* find_longest_arithmetic_progression_subarray(int* arr, std::size_t size) {
    int d, prev;
    int* ptr = arr;
    unsigned count = 2, prev_count = 2;
    unsigned prev_start_idx = 0;

    if (size <= 2) {
        return ptr;
    }

    d = *(arr + 1) - *arr;
    prev = *(arr + 1);
    
    for (int i = 2; i < size; ++i) {
        if (d == (*(arr + i) - prev)) {
            count++;
        } else {
            if (prev_count < count) {
                ptr = arr + prev_start_idx;
            }
            prev_count = count;
            count = 2;
            prev_start_idx = i-1;
            d = *(arr + i) - prev;
        }
        prev = *(arr + i);
    }

    return ptr;
}

// task 2
double number_problem(double* arr, std::size_t size) {

}

// task 3
bool is_anagram(const char* str1, const char* str2) {
    int letter_count[26] {0};

    int i = 0;    
    
    while (str1[i] && str2[i]) {
        char l1 = str1[i];
        if (l1 >= 'A' && l1 <= 'Z') {
            l1 = 'a' + l1 - 'A';
        }
        ++letter_count[l1 - 'a'];

        char l2 = str2[i];
        if (l2 >= 'A' && l2 <= 'Z') {
            l2 = 'a' + l2 - 'A';
        }
        --letter_count[l2 - 'a'];
        ++i;
    }

    if (*(str1 + i) || *(str2 + i)) {
        return false;
    }

    for (int i = 0; i < 26; ++i) {
        if (letter_count[i] != 0) { 
            return false;
        }
    }

    return true;
}

long encode(const char* sentence, char* letters, int* codes, std::size_t size) {
    int i = 0;
    long product = 1;
    long code = 0;

    bool word_encoded = false;

    while(sentence[i]) {
        if (sentence[i] != ' ') {
            for (int j = 0; j < size; ++j) {
                if (letters[j] == sentence[i]) {
                    word_encoded = true;
                    product *= codes[j];
                }
            }
        } else {
            if (word_encoded) {
                code += product;
                product = 1;
            }
            word_encoded = false;
        }
        ++i;
    }

    if (word_encoded) {
        code += product;
    }

    return code;
}

unsigned max_gcd_connected_elements(unsigned matrix[][ARR_SIZE], int rows, int cols, unsigned k) {
    if (rows <= 0 || cols <= 1) {
        return 0;
    }

    bool used[ARR_SIZE][ARR_SIZE] {false};
    int max = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int current = _max_gcd_connected_elements(matrix, used, rows, cols, k, i, j);
            if (max < current) {
                max = current;
            }
        }
    }

    return max;
}

unsigned _max_gcd_connected_elements(unsigned matrix[][ARR_SIZE], bool used[][ARR_SIZE], int rows, int cols, unsigned k, int x, int y) {
    used[x][y] = true;

    unsigned gcd_val = gcd(k, matrix[x][y]);
    int count = 0;

    for (int i = -1; i <= 1; i += 2) {
        int new_x = x + i, new_y = y;   
        if (!used[new_x][new_y] && is_valid(rows, cols, new_x, new_y) && gcd_val == gcd(matrix[new_x][new_y], k)) {
            count += _max_gcd_connected_elements(matrix, used, rows, cols, k, new_x, new_y);
        }

        new_x = x, new_y = y + i;
        if (!used[new_x][new_y] && is_valid(rows, cols, new_x, new_y) && gcd_val == gcd(matrix[new_x][new_y], k)) {
            count += _max_gcd_connected_elements(matrix, used, rows, cols, k, new_x, new_y);
        }
    } 

    return 1 + count;
}

unsigned gcd(unsigned n1, unsigned n2) {
    unsigned res = n1 > n2 ? n2 : n1;

    while (res > 0 && !(n1 % res == 0 && n2 % res == 0)) {
        --res;
    }

    return res;
}

bool is_valid(int rows, int cols, int x, int y) {
    return x < rows && y < cols && x >= 0 && y >= 0;
}