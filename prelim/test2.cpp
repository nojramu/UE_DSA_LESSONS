#include <iostream>
using namespace std;

const int SIZE = 3;

void inputMatrix(int matrix[SIZE][SIZE]) {
    cout << "Enter the elements of the 3x3 matrix:" << endl;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cin >> matrix[i][j];
        }
    }
}

void showMatrix(int matrix[SIZE][SIZE]) {
    cout << "The matrix is:" << endl;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void sumRows(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        int sum = 0;
        for (int j = 0; j < SIZE; ++j) {
            sum += matrix[i][j];
        }
        cout << "Sum of row " << i + 1 << ": " << sum << endl;
    }
}

void sumColumns(int matrix[SIZE][SIZE]) {
    for (int j = 0; j < SIZE; ++j) {
        int sum = 0;
        for (int i = 0; i < SIZE; ++i) {
            sum += matrix[i][j];
        }
        cout << "Sum of column " << j + 1 << ": " << sum << endl;
    }
}

int main() {
    int matrix[SIZE][SIZE];
    inputMatrix(matrix);
    showMatrix(matrix);
    sumRows(matrix);
    sumColumns(matrix);
    return 0;
}
