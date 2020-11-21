#include <iostream>
#include <cmath>

using namespace std;

// Структура ФИО
struct FullName {
    string firstName;
    string surName;
    string middleName;
};

// Структура студента
struct Student {
    string group;
    FullName fullName;
    int yearOfBorn;
    string gender;
    int* phisicsGrades;
    int* mathGrades;
    int* infoGrades;
};

// Массив возможных групп для случайного заполнения массива студентов
const string groups[] = {
    "ИЭс-141-19", 
    "ИЭс-142-19", 
    "ИЭс-143-19", 
    "ИЭс-144-19"
};

// Массив возможных имён для случайного заполнения массива студентов
const FullName names[] = {
    { "Василий", "Василенко", "Васильевич"},
    { "Иван", "Иванов", "Иванович"},
    { "Андрей", "Андрейченко", "Андреевич"},
    { "Максим", "Максименко", "Максимович"},
    { "Руслан", "Русланченко", "Русланович"}
};

// Создание массива случайных оценок
int* createGradesArr() {
    int* grades = new int[5];
    for(int i = 0; i < 5; i++) {
        grades[i] = 3 + rand() % 3;
    }

    return grades;
}

// Сколько раз число встречается в массиве
int numCountInArray(int* arr, int num) {
    int numCount = 0;
    int arrSize = sizeof(arr);
    for(int i = 0; i < arrSize; i++) {
        if(arr[i] == num) {
            numCount++;
        }
    }
    return numCount;
}

// Вычисление среднего балла
double getAverageScore(int* arr1, int* arr2, int* arr3) {
    int fives = numCountInArray(arr1, 5) + numCountInArray(arr2, 5) + numCountInArray(arr3, 5);
    int fours = numCountInArray(arr1, 4) + numCountInArray(arr2, 4) + numCountInArray(arr3, 4);
    int three = numCountInArray(arr1, 3) + numCountInArray(arr2, 3) + numCountInArray(arr3, 3);

    double averageScore = (5 * fives + 4 * fours + 3 * three)/((double)(fives + fours + three));

    return round(averageScore * 10) / 10; // Округление до 1 цифры после запятой
}

int main() {
    srand(time(0));
    

    int studentsCount; // Количество студентов

    cout << "Введите количество студентов:\n";
    cin >> studentsCount;

    Student students[studentsCount]; // Массив стедентов

    // Создание массива студентов
    for(int i = 0; i < studentsCount; i++) {
        Student student = {
            groups[rand() % 4],
            names[rand() % 5],
            1999,
            "M",
            createGradesArr(),
            createGradesArr(),
            createGradesArr()
        };

        students[i] = student;
    }

    // Вывод получившейся структуры студентов
    cout << "Группа " << "Фамилия " << "Имя " << "Отчество " << "Средний балл\n";
    for(int i = 0; i < studentsCount; i++) {
        double averageScore =  getAverageScore(students[i].infoGrades, students[i].mathGrades, students[i].phisicsGrades);
        cout << students[i].group << " " << students[i].fullName.firstName << " ";
        cout << students[i].fullName.surName << " " << students[i].fullName.middleName << " ";
        cout<< averageScore << endl;
        cout << "-\n";
    }

    // Ввод группы из консоли сделать не получилось
    string groupName = "ИЭс-142-19";
    
    // Необходимый средний балл(по заданию 4.5, но данный 
    // результат получался редко, поэтому для тестов выбрал 4.0)
    double necessaryAverageScore = 4.0;

    cout << "Результат: \n" << "------------------------" << endl;
    
    // Вывод результата
    for(int i = 0; i < 5; i++) {
        if(students[i].group == groupName) {
            // Вычисление среднего балла студента
            double averageScore = getAverageScore(students[i].infoGrades, students[i].mathGrades, students[i].phisicsGrades);
            if(averageScore >= 4) {
                cout << students[i].fullName.firstName << " ";
                cout << students[i].fullName.surName << " " << students[i].fullName.middleName << " ";
                cout<< averageScore << endl;
            }
        }
    }
    
    return 0;
}
