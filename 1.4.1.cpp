#include <iostream>
#include <cmath>

using namespace std;

//Создание массива случайных чисел от 1 до 20
int* createArray(int arrayLength) {
    int* resultArr = new int[arrayLength];
    for(int i = 0; i < arrayLength; i++) {
        
        int num = 1 + rand() % 20; 
        resultArr[i] = num;
    }   

    return resultArr;
}

// Расчёт формулы
int calculation(int R, int H) {
    double result = (M_PI * pow(H, 2)) * (R - H/3);

    return result;
}

int main() {
    srand(time(0));
    int arrayLength; // Длинна массивов

    // Получение длинны массивов
    cout << "Введите длинну массивов: \n";
    cin >> arrayLength;

    // Создание изначальных массивов
    int* arr1 = createArray(arrayLength);
    int* arr2 = createArray(arrayLength);

    // Вывод изначальных массивов
    cout << "Изначальные массивов: \n";
    for(int i = 0; i < arrayLength; i++) {
            cout << "|" << arr1[i] << "|";
    }
    cout << "\n";

    for(int i = 0; i < arrayLength; i++) {
            cout << "|" << arr2[i] << "|";
    }
    cout << "\n";

    int result = 0;

    // Расчёт результата
    for(int i = 0; i < arrayLength; i++) {
        result += calculation(arr1[i], arr2[i]);
    }

    // Вывод результата
    cout << "Результат: \n" << result << endl; 

    return 0;
}