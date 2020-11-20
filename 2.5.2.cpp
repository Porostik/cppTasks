#include <iostream>
#include <cmath>

using namespace std;

int main() {
    srand(time(0));

    int matrixSize; // Размер матрицы
    int sumOfMainDiagonal; // Сумма элементов главной диагонали матрицы

    cout << "Введите размер матрицы:\n"; // Получение размера матрицы
    cin >> matrixSize;

    int matrix[matrixSize][matrixSize]; // Матрица

    // Создание матрицы
    for(int i = 0; i < matrixSize; i++) {
        for(int j = 0; j < matrixSize; j++) {
            matrix[i][j] = 1 + rand() % 20;
        }
    }

    cout << "Изначальная матрица:\n";
    for(int i = 0; i < matrixSize; i++) {
        cout << "|";
        for(int j = 0; j < matrixSize; j++) {
            cout << matrix[i][j];
            if(matrix[i][j] < 10) {
                cout << " |";
            } else {
                cout << "|";
            }
        }
        cout << "\n";
    }

    // Преобразования матрицы
    for(int i = 0; i < matrixSize; i++) {
        for(int j = i + 1; j < matrixSize; j++) {
            if(matrix[j][i] > matrix[i][j]) {
                matrix[j][i] = floor((matrix[i][j] + matrix[j][i]) / 2);
            }
        }
    }

    cout << "-------------------------\n";

    cout << "Матрица после преобразований:\n";
    for(int i = 0; i < matrixSize; i++) {
        cout << "|";
        for(int j = 0; j < matrixSize; j++) {
            cout << matrix[i][j];
            if(matrix[i][j] < 10) {
                cout << " |";
            } else {
                cout << "|";
            }
        }
        cout << "\n";
    }

    for(int i = 0; i < matrixSize; i++) {
        sumOfMainDiagonal += matrix[i][i];
    }

    cout << "Сумма элементов главной диагонали матрицы:\n";
    cout << sumOfMainDiagonal << endl;

    return 0;
}
