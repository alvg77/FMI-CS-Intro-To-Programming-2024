#include <iostream>
#include <cmath>

const std::size_t ROWS = 256;
const std::size_t COLUMNS = 256;

const std::size_t MAX_PEOPLE = 256;
const std::size_t ACC_FIELDS = 5;
const std::size_t MAX_CHAR = 256;


// task 1
void inputMatrix(int matrix[][COLUMNS], int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }
}

void printMatrix(int matrix[][COLUMNS], int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << matrix[i][j] << " | ";
        }
        std::cout << std::endl;
    }
}

int sumMatrixValues(int matrix[][COLUMNS], int m, int n) {
    int sum = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            sum += matrix[i][j];
        }
    }

    return sum;
}

int* sumMatrixRows(int matrix[][COLUMNS], int m, int n) {
    int *rowSums = new int[m];
    for (int i = 0; i < m; ++i) {
        int rowSum = 0;
        for (int j = 0; j < n; ++j) {
            rowSum += matrix[i][j];
        }
        rowSums[i] = rowSum;
    }

    return rowSums;
}

void printMatrixRowSums(int *rowSums, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << rowSums[i] << " ";
    }
}

int* sumMatrixColumns(int matrix[][COLUMNS], int m, int n) {
    int *columnSums = new int[m];
    for (int i = 0; i < m; ++i) {
        int columnSum = 0;
        for (int j = 0; j < n; ++j) {
            columnSum += matrix[j][i];
        }
        columnSums[i] = columnSum;
    }

    return columnSums;
}

void printMatrixRowColumns(int *columnSums, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << columnSums[i] << " ";
    }
}

void printSumAboveAndBelowPrimaryDiagonal(int matrix[][COLUMNS], int m, int n) {
    int sumBelow = 0;
    int sumAbove = 0;
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j > i) {
                sumAbove += matrix[i][j];
            } else if (j < i) {
                sumBelow += matrix[i][j];
            }
        }
    }
}

void printSecondaryDiagonal(int matrix[][COLUMNS], int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i + j == m-1) {
                std::cout << matrix[i][j];
            }
        }
    }
}

int calculateDeterminant(int matrix[][COLUMNS], int m, int n) {
    
}

// task 2
void snailIterate(int matrix[][COLUMNS], int m, int n) {

}

// task 3
bool isMagicSquare(int matrix[][COLUMNS], int n) {
    int *rowsSums = sumMatrixRows(matrix, n, n);
    
    for (int i = 0; i < n - 1; ++i) {
        if (rowsSums[i] != rowsSums[i + 1]) {
            delete[] rowsSums;
            return false;
        }
    }

    int *columnsSums = sumMatrixColumns(matrix, n, n);

    for (int i = 0; i < n - 1; ++i) {
        if (columnsSums[i] != columnsSums[i + 1]) {
            delete[] rowsSums;
            delete[] columnsSums; 
            return false;
        }
    }

    int primaryDiagonalSum = 0;
    int secondaryDiagonalSum = 0;

    for (int i = 0; i < n; ++i) {
        primaryDiagonalSum += matrix[i][i];
        secondaryDiagonalSum += matrix[i][n-i-1];
    }

    if (!(rowsSums[0] == columnsSums[0] == primaryDiagonalSum == primaryDiagonalSum)) {
        delete[] rowsSums;
        delete[] columnsSums;
        return false;
    }

    delete[] rowsSums;
    delete[] columnsSums;

    return true;
}

// task 4
void printTransposedMatrix(int matrix[][COLUMNS], int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << matrix[j][i] << " | ";
        }
        std::cout << std::endl;
    }
}

// task 5
void inputPeopleProfiles(char people[][ACC_FIELDS][MAX_CHAR], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cin.getline(people[i][j], COLUMNS);
        }
    }
}

int main() {


    return 0;
}
