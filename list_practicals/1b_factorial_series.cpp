#include <iostream>
using namespace std;

// Function to calculate factorial
long long factorial(int n) {
    long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
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
    
    // Series: S = 1 + 1/2! + 1/3! + 1/4! ... + 1/n!
    double series = 1.0; // Start with 1 (first term)
    for (int i = 2; i <= n; i++) {
        series += 1.0 / factorial(i);
    }
    
    cout << "Factorial Series: S = 1 + 1/2! + 1/3! + 1/4! ... = " << series << endl;
    
    return 0;
}
