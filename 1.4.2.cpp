#include <iostream>

using namespace std;

int max(int num1, int num2) {
    if(num1 < num2) {
        return num2;
    }

    return num1;
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

//Создание массива случайных чисел от 1 до 20
int* createArray(int arrayLength) {
    int* resultArr = new int[arrayLength];
    for(int i = 0; i < arrayLength; i++) {
        
        int num =  10 - rand() % 20; 
        resultArr[i] = num;
    }   

    return resultArr;
}

int main() {   
    int arrayLength;
    
    cout << "Введите длину массивов\n";
    cin >> arrayLength;
    int* arr1 = createArray(arrayLength);
    int* arr2 = createArray(arrayLength);

    int result[arrayLength];
    int elementsFromArr1 = 0;

    for(int i = 0; i < 9; i++) {
        int maxOfTwoNums = max(arr1[i], arr2[i]);
        result[i] = maxOfTwoNums;
        if(maxOfTwoNums == arr1[i]) {
            elementsFromArr1++;
        }
    }

    cout << "Конечный массив:\n";
    for(int i = 0; i < 9; i++) {
        cout << result[i] << endl;
    }

    cout << "Количество элементов из массива arr1:\n";
    cout << elementsFromArr1 << endl;
    return 0;
}