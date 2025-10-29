#include <iostream>
#include <cstdlib>
using namespace std;

double power(int base, int exp) {
    double result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

int main(int argc, char* argv[]) {
    int n;

    if (argc > 1) {
        n = atoi(argv[1]);
    } else {
        cout << "Enter the number of terms: ";
        cin >> n;
    }

    double series = 0.0;

    cout << "\nCalculating alternating series with " << n << " terms:" << endl;
    cout << "Series: ";

    for (int i = 1; i <= n; i++) {
        double term = 1.0 / power(i, i);

        if (i > 1) {
            if (i % 2 == 1) {
                cout << " + ";
            } else {
                cout << " - ";
            }
        }

        cout << "1/" << i << "^" << i;

        if (i % 2 == 1) {
            series += term;
        } else {
            series -= term;
        }
    }

    cout << " = " << series << endl;
    cout << "\nAlternating Series Sum = " << series << endl;

    return 0;
}
