#include <iostream>

const unsigned MAX_SIZE = 256;

void modifyMatrix(unsigned matrix[][MAX_SIZE], int rows, int cols);
void shiftDownward(unsigned matrix[][MAX_SIZE], int rows, unsigned shiftCol, unsigned positions);
void printMatrix(unsigned matrix[][MAX_SIZE], int rows, int cols);

int main() {
    unsigned matrix[MAX_SIZE][MAX_SIZE] = {
        {1,2,3},
        {4,5,6},
        {7,8,9},
        {10,11,12}
    };

    modifyMatrix(matrix, 4, 3);
    printMatrix(matrix, 4, 3);
    
    return 0;
}

void modifyMatrix(unsigned matrix[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < cols; ++i) {
        shiftDownward(matrix, rows, i, i+1);
    }
}

void shiftDownward(unsigned matrix[][MAX_SIZE], int rows, unsigned shiftCol, unsigned positions) {
    positions %= rows;

    if (positions == 0) {
        return;
    }

    for (int shift = 0; shift < positions; ++shift) {
        int prev = matrix[(positions - 1) % rows][shiftCol];
        for (int i = 0; i < rows; ++i) {
            int curr = matrix[(i + positions) % rows][shiftCol];
            matrix[(i + positions) % rows][shiftCol] = prev;
            prev = curr;
        }
    }
}

void printMatrix(unsigned matrix[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
