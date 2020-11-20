#include <iostream>

using namespace std;

const int MATRIX_SIZE = 5; // Размер матрицы
const int ARRAY_SIZE = 5; // Размер массива

// Поиск одинковых значений в массиве
bool findSameValuesInArray(int arr[ARRAY_SIZE]) {
    for(int i = 0; i < ARRAY_SIZE; i++) {
        for(int j = i; j < ARRAY_SIZE; j++) {
            if(arr[i] == arr[j + 1]) {
                return true;
            }
        }
    }

    return false;
}

// Вывод массива
void writeArray(int arr[ARRAY_SIZE]) {
    for(int i = 0; i < ARRAY_SIZE; i++) {
        cout << '|';
        cout << arr[i];
    }

    cout << "|\n";
    cout << "------------------------------\n";
}

int main() {
    srand(time(0));

    int array[ARRAY_SIZE]; // Массив
    int matrix[MATRIX_SIZE][MATRIX_SIZE]; // Матрица

    // Создание матрицы
    for(int i = 0; i < MATRIX_SIZE; i++) {
        for(int j = 0; j < MATRIX_SIZE; j++) {
            matrix[i][j] = 1 + rand() % 20;
        }
    }

    // Создание массива
    for(int i = 0; i < ARRAY_SIZE; i++) {
        int arrayElement;
        cout << "Введите ";
        cout << i + 1;
        cout << " элемент массива: ";
        cin >> arrayElement;
        array[i] = arrayElement;
    }

    cout << "\n";

    // Вывод изначальной матрицы
    cout << "Изначальная матрица:\n";
    for(int i = 0; i < MATRIX_SIZE; i++) {
        cout << "|";
        for(int j = 0; j < MATRIX_SIZE; j++) {
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

    // Вывод изначального массива
    cout << "Изначальный массив:\n";
    writeArray(array);
    
    // Поиск одинковых элементов в массиве
    if(findSameValuesInArray(array)) {
        // Модификация массива
        for(int i = 0; i < ARRAY_SIZE; i++) {
            array[i] = array[i] + matrix[i][i];
        }

        // Вывод массива после модификации
        cout << "Массив после модификации:\n";
        writeArray(array);
    } else {
        cout << "В массиве нет одинковых элементов\n";
    }

    return 0;
}