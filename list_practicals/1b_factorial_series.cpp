#include <iostream>
#include <cstdlib>
using namespace std;

long long factorial(int n) {
    long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main(int argc, char* argv[]) {
    int n;

    if (argc > 1) {
        n = atoi(argv[1]);
    } else {
        cout << "Enter the number of terms: ";
        cin >> n;
    }

    double series = 1.0;

    cout << "\nCalculating factorial series with " << n << " terms:" << endl;
    cout << "Series: 1";

    for (int i = 2; i <= n; i++) {
        double term = 1.0 / factorial(i);
        series += term;
        cout << " + 1/" << i << "!";
    }

    cout << " = " << series << endl;
    cout << "\nFactorial Series Sum = " << series << endl;
    cout << "Note: This series converges to e (Euler's number) ≈ 2.71828" << endl;

    return 0;
}
