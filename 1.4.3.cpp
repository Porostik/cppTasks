#include <iostream>

using namespace std;

// Умножение элементов массива заданое количество раз
int getMultiply(int arr1[], int arr2[], int currentIndex) {
    int result = 1; // Результат умножения

    for(int j = 0; j <= currentIndex; j++) {
        result = result * (arr1[j] + arr2[j]); 
    }

    return result;
}

//Создание массива путём самостоятельного ввода чисел
// int* createArray(int arrayLength) {
//     int* resultArr = new int[arrayLength];
//     for(int i = 0; i < arrayLength; i++) {
//         int num;
//         cout << "Введите элемент массива: ";
//         cin >> num;
//         resultArr[i] = num;
//     }   

//     return resultArr;
// }

//Создание массива случайных чисел от -10 до 20
int* createArray(int arrayLength) {
    int* resultArr = new int[arrayLength];
    for(int i = 0; i < arrayLength; i++) {
        
        int num =  10 - rand() % 20; 
        resultArr[i] = num;
    }   

    return resultArr;
}

int main() {   
    srand(time(NULL));
    int arrayLength; // Длинна массива
    int result = 0; // Наименьший среди результатов умножения
    
    // Задание длинны массивов
    cout << "Введите длину массивов\n";
    cin >> arrayLength;
    int* arr1 = createArray(arrayLength); // Создание первого массива
    int* arr2 = createArray(arrayLength); // Создание второго массива

    for(int m = 0; m < arrayLength; m++) {
        // Результат для текущего индекса
        int resultForCurrentIndex = getMultiply(arr1, arr2, m);
        if(m == 0) {
            result = resultForCurrentIndex;
        }

        if(result > resultForCurrentIndex) {
            result = resultForCurrentIndex;
        }
    }

    cout << result << endl;

    return 0;
}