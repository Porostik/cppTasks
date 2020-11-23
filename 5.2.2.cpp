#include <iostream>

using namespace std;

struct WorkTime {
    int openingHour;
    int closingHour;
};

struct Shop {
    string name;
    string area;
    WorkTime workTime;  
};

// Имена для случайного заполнения структуры магазина
const string names[] = {
    "Name1",
    "Name2",
    "Name3",
    "Name4",
    "Name5",
};

// Районы для случайного заполнения структуры магазина
const string areas[] = {
    "Area1",
    "Area2",
    "Area3",
    "Area4",
    "Area5",
};

// Время работы для случайного заполнения структуры магазина
const WorkTime workTimes[] = {
    { 9, 22 },
    { 10, 23 },
    { 11, 17 },
    { 10, 18 },
    { 8, 17 }
};

int main() {
    srand(time(0));
    
    int shopsCount;

    cout << "Введите количество магазинов: \n";
    cin >> shopsCount;
    cout << '\n';
    
    Shop shops[shopsCount];

    for(int i = 0; i < shopsCount; i++) {
        Shop newShop = {
            .name = names[rand() % 5],
            .area = areas[rand() % 5],
            .workTime = workTimes[rand() % 5]
        };

        shops[i] = newShop;
    }

    // Вывод изначальных магазинов
    cout << "Название  " << "Район  " << "Время работы" << endl;         
    for(int i = 0; i < shopsCount; i++) {
        cout << shops[i].name << "     " << shops[i].area << "    ";
        cout << shops[i].workTime.openingHour << "-" << shops[i].workTime.closingHour << endl;
    }

    cout << "------------------------------------\n";
    
    cout << "Результат: \n"; 

    for(int i = 0; i < shopsCount; i++) {
        if(shops[i].workTime.closingHour > 18) {
            cout << shops[i].name << "     " << shops[i].area << "    ";
            cout << shops[i].workTime.openingHour << "-" << shops[i].workTime.closingHour << endl;
        }
    }

    return 0;
}