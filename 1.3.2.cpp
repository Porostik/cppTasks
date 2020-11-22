#include <iostream>
#include <cmath>

using namespace std;

const double X = 0.5;
const double N = 20.0; 

int main() {
    srand(time(0));

    double result = 1.0;

    double firstCulc = N * pow(sqrt(pow(X, 2.0)), 1.0/3.0);
    
    for(int i = 1; i < N; i++) {
        result *= log10(sqrt(i * abs(X) + 1)) / 1.02 - 1 / i;
    }
    
    result = firstCulc + result;

    cout << "Результат: \n" << result << endl;

    return 0;
}