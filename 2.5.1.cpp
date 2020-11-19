#include <iostream>

using namespace std;

int main() {
    srand(time(0));
    int matrix[10][2];
    int pupilCount = 0;

    for(int i = 0; i < 10; i++) {
        matrix[i][0] = 20 + 1 + rand() % 7;
        matrix[i][1] = 1 + rand() % 6;
    }

    for(int i = 0; i < 10; i++) {
        if(100 * matrix[i][1] / matrix[i][0] > 15) {
            cout << "В группе под номером: ";
            cout << i + 1;
            cout << " Больше 15% отличников\n";
            pupilCount++;
        }
    }

    cout << "Количество групп с, где отличников больше 15%: ";
    cout << pupilCount << endl;

    return 0;
}