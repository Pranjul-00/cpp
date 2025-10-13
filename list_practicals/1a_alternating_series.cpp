#include <iostream>
using namespace std;

// Function to calculate power
double power(int base, int exp) {
    double result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

int main(int argc, char* argv[]) {
    int n;
    
    // Check command line arguments
    if (argc > 1) {
        n = atoi(argv[1]);
    } else {
        cout << "Enter the number of terms: ";
        cin >> n;
    }
    
    // Series: S = 1 - 1/2^2 + 1/3^3 - 1/4^4 ... (-1)^(n+1)/n^n
    double series = 0;
    for (int i = 1; i <= n; i++) {
        double term = 1.0 / power(i, i);
        if (i % 2 == 1) {
            series += term;  // Positive for odd positions
        } else {
            series -= term;  // Negative for even positions
        }
    }
    
    cout << "Alternating Series: S = 1 - 1/2^2 + 1/3^3 - 1/4^4 ... = " << series << endl;
    
    return 0;
}
