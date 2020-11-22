#include <iostream>
#include <cmath>

using namespace std;

const double MAX = 1.0;
const double MIN = 0.55;
const double STEP = 0.01;

int main() {
    srand(time(0));
    
    int n = 10;

    cout << "X " << " Y";
    for(int i = 0; i < n; i++) {
        double x = MIN + (STEP * i);
        double y = 1 / sqrt(x) + pow(log(abs(0.2 + sin(x))), 2.0) + pow(x * x, 1.0/3.0);
        cout << x << "  " << y << endl;
    }

    return 0;
}