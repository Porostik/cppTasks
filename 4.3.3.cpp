#include <iostream>

using namespace std;

int main() {
    srand(time(0));

    int matrixSize; // Размер матрицы

    cout << "Введите размер матрицы\n";
    cin >> matrixSize;

    int matrix[matrixSize][matrixSize]; // Матрица

    // Создание матрицы
    for(int i = 0; i < matrixSize; i++) {
        for(int j = 0; j < matrixSize; j++) {
            matrix[i][j] = 1 + rand() % 20;
        }
    }

    cout << "\n";

    // Вывод изначальной матрицы
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

    cout << "------------------------------\n";
    
    int maxColumnSumIndex, maxRowSumIndex; // Номера строк с максимальной суммой элементов
    int maxColumnSum, maxRowSum; // Максимальные суммы строк и столбцов

    // Ввычисление столбца с максимальной суммой элементов
    for(int i = 0; i < matrixSize; i++) {
        int resultSum = 0;  // Сумма элементов столбца

        for(int j = 0; j < matrixSize; j++) {
            resultSum += matrix[i][j]; 
        }

        if (i == 0) {
            maxColumnSum = resultSum;
            maxColumnSumIndex = i;
        } else {
            if (maxColumnSum < resultSum) {
                maxColumnSum = resultSum;
                maxColumnSumIndex = i;
            }
        }
    }

    for(int i = 0; i < matrixSize; i++) {
        int resultSum = 0; // Сумма элементов строки

        for(int j = 0; j < matrixSize; j++) {
            resultSum += matrix[j][i];
        }

        if (i == 0) {
            maxRowSum = resultSum;
            maxRowSumIndex = i;
        } else {
            if (maxRowSum < resultSum) {
                maxRowSum = resultSum;
                maxRowSumIndex = i;
            }
        }
    }

    if (maxColumnSumIndex == maxRowSumIndex) {
        cout << "Сумма строки и столбца с максимальными суммами элементов:\n";
        cout << maxColumnSum + maxRowSum << endl;
    } else {
        cout << "Номер столбца с максимальной суммой элементов:\n";
        cout << maxColumnSumIndex << endl;
        cout << "Номер строки с максимальной суммой элементов:\n";
        cout << maxRowSumIndex << endl;
    }


    return 0;
}
