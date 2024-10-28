#include <iostream>

int sum(const int arr[], std::size_t size);
int find(const int arr[], std::size_t size, int element);
bool is_set(const int arr[], std::size_t size);
void reverse(int arr[], std::size_t size);
std::size_t filter(int destination[], const int source[], std::size_t size);
int most_common(const int arr[], std::size_t size);
std::size_t longest_subarray_size(const int arr[], std::size_t size);
void bubble_sort(int arr[], std::size_t size);
void selection_sort(int arr[], std::size_t size);

void print(const int arr[], std::size_t size);

int main() {
    // task 1
    // int arr[] = {16, 23, 7, 18, 39};
    // std::cout << sum(arr, 5) << std::endl; // -> 103

    // task 2
    // int arr[]{8, 0, 2, 6, 9, 2, 7};
    // std::cout << find(arr, 7, 2) << std::endl; // -> 2
    // std::cout << find(arr, 7, 16) << std::endl; // -> -1

    // task 3 
    // int arr1[]{2, 5, 6, 11, 17};
    // int arr2[]{2, 5, 5, 11, 17};
    // std::cout<<std::boolalpha<<is_set(arr1, 5) << std::endl; // -> true
    // std::cout<<std::boolalpha<<is_set(arr2, 5) << std::endl; // -> false

    // task 4
    // int arr[]{0, 1, 2, 3, 4};
    // reverse(arr, 5);
    // print(arr, 5); // -> 4 3 2 1 0

    // task 5
    // int source[]{5, 14, 28, 6, 98, 24, 35, 68, 21};
    // int destination[255];
    // int size = filter(destination, source, 9);
    // print(destination, size); // -> 98 35

    // task 6
    // int arr[]{4, 1, 1, 4, 2, 3, 4, 4, 1, 2, 4, 9, 3};
    // std::cout << most_common(arr, 13) << std::endl; // -> 4

    // task 7
    // int arr1[]{1, 1, 2, 3, 3, 3, 4, 2, 2, 2, 2, 1, 1};
    // int arr2[]{1, 1, 2, 3, 3, 3, 4, 2, 2, 2, 2, 1, 1, 1, 1, 1};
    // std::cout << longest_subarray_size(arr1, 13) << std::endl; // -> 4
    // std::cout << longest_subarray_size(arr2, 16) << std::endl; // -> 5

    // task 8
    // int arr[]{10, 5, 8, 3, 13, 7};
    // bubble_sort(arr, 6);
    // selection_sort(arr, 6);
    // print(arr, 6); // -> 3 5 7 8 10 13

    return 0;
}

int sum(const int arr[], std::size_t size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}

int find(const int arr[], std::size_t size, int element) {
    int i = 0;

    while(arr[i] != element && i < size) {
        ++i;
    }

    return arr[i] == element ? i : -1;
}

bool is_set(const int arr[], std::size_t size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i+1; j < size; ++j) {
            if (arr[i] == arr[j]) {
                return false;
            }
        }
    }

    return true;
}

void reverse(int arr[], std::size_t size) {
    int j = size-1;
    for(int i = 0; i < size/2; ++i) {
        arr[i] += arr[j];
        arr[j] = arr[i] - arr[j];
        arr[i] -= arr[j];
        --j;
    }
}

std::size_t filter(int destination[], const int source[], std::size_t size) {
    int counter = 0;

    for(int i = 0; i < size; ++i) {
        if (source[i] > 30 && source[i] % 7 == 0) {
            destination[counter++] = source[i];
        }
    }

    return counter;
}

int most_common(const int arr[], std::size_t size) {
    int most_common_num;
    int max_occ = 0;

    for (int i = 0; i < size; ++i) {
        int occ = 1;
        for(int j = 0; j < size; ++j) {
            if (i != j && arr[i] == arr[j]) {
                occ += 1;
            }
        }

        if (max_occ < occ) {
            most_common_num = arr[i];
            max_occ = occ;
        }
    }

    return most_common_num;
}

std::size_t longest_subarray_size(const int arr[], std::size_t size) {
    int largest = 1, temp_len = 1;
    
    for (int i = 0; i < size-1; ++i) {
        if (arr[i] == arr[i+1]) {

            temp_len += 1;
        } else if (largest < temp_len) {
            largest = temp_len;
            temp_len = 1;
        }
    }

    if (largest < temp_len) {
        largest = temp_len;
    }

    return largest;
}

void bubble_sort(int arr[], std::size_t size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j+1]) {
                arr[j] += arr[j+1];
                arr[j+1] = arr[j] - arr[j+1];
                arr[j] = arr[j] - arr[j+1];
            } 
        }
    }
}

void selection_sort(int arr[], std::size_t size) {
    int pos = 0;

    for (int i = 0; i < size - 1; ++i) {
        int min = arr[i], min_pos = i;

        for (int j = i + 1; j < size; ++j) {
            if (min > arr[j]) {
                min = arr[j];
                min_pos = j;
            }
        }

        int temp = arr[pos];
        arr[pos] = arr[min_pos];
        arr[min_pos] = temp;

        ++pos;
    }
}

void print(const int arr[], std::size_t size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}