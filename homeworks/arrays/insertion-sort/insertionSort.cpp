#include <iostream>

void insertionSort(int arr[], int size); // insertion sort
int insertSort(int arr[], int size, int count, int x); // sort elements as you insert them
void printArr(int arr[], int size);

int main() {
    constexpr int arrSize = 10;
    int arr[arrSize] = {0};
    int count = 0;

    for (int i = 0; i < arrSize; ++i) {
        // int x;
        // std::cin >> x;
        // count = insertSort(arr, arrSize, count, x);

        std::cin >> arr[i];
    }
    insertionSort(arr, arrSize);
    printArr(arr, arrSize);

    return 0;
}

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        int val = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > val) {
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = val;
    }
}

int insertSort(int arr[], int size, int count, int x) {
    if (count == size) {
        return -1;
    }

    int insertionIndex = 0;
    while (insertionIndex < count && x >= arr[insertionIndex]) {
        ++insertionIndex;
    }

    for (int i = count - 1; i >= insertionIndex; --i) {
        arr[i+1] = arr[i]; 
    }

    arr[insertionIndex] = x;
    
    return count + 1;
}

void printArr(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
