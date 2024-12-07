#include <iostream>

const size_t SIZE = 3;

int sumAboveUnder(int matrix[][SIZE], int n, int m) {
    int sum = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i != j) {
                sum += matrix[i][j];
            }

            if (i + j != SIZE-1) {
                sum += matrix[i][j];
            }
        }
    }

    return sum;
}

void printOdd(int matrix[][SIZE], int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] % 2 == 1) {
                std::cout << matrix[i][j] << std::endl;
            }
        }
    }
}

int (*multiplyScalar(int matrix[][SIZE], int m, int n, int scalar))[SIZE] {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] *= scalar;
        }
    }

    return matrix;
}

double (*multiplyScalar(double matrix[][SIZE], int m, int n, double scalar))[SIZE] {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] *= scalar;
        }
    }

    return matrix;
}

void reverseArr(int *arr, int size) {
    int j = size - 1;
    for (int i = 0; i < size/2; ++i) {
        arr[i] += arr[j];
        arr[j] = arr[i] - arr[j];
        arr[i] = arr[i] - arr[j];
        --j;
    }
}



int main() {


    return 0;
}