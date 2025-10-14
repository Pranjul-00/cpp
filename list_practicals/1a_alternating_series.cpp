// Minimal integer parser to avoid extra headers
int parseInt(const char* s) {
    if (!s || !*s) return 0;
    int sign = 1;
    long long val = 0;
    int i = 0;
    if (s[i] == '+') { i++; }
    else if (s[i] == '-') { sign = -1; i++; }
    for (; s[i] != '\0'; ++i) {
        char c = s[i];
        if (c < '0' || c > '9') break;
        val = val * 10 + (c - '0');
        if (val > 2147483647LL) { // clamp to int range
            val = 2147483647LL;
            break;
        }
    }
    return (int)(sign * val);
}
/*
 * PRACTICAL 1A: ALTERNATING SERIES CALCULATION
 * ============================================
 *
 * PURPOSE: Calculate the sum of an alternating series where each term follows the pattern:
 *          S = 1 - 1/2^2 + 1/3^3 - 1/4^4 + ... + (-1)^(n+1)/n^n
 *
 * ALGORITHM:
 * 1. Accept number of terms (n) from user or command line
 * 2. For each term i from 1 to n:
 *    - Calculate 1 / (i^i)
 *    - Add if i is odd, subtract if i is even
 * 3. Display the final sum
 *
 * INPUT: Number of terms (n)
 * OUTPUT: Sum of the alternating series
 *
 * EXAMPLE: For n = 4, S = 1 - 1/4 + 1/27 - 1/256 = 0.7130...
 */

#include <iostream>
using namespace std;

// Function to calculate power (base^exp) using iterative method
// Parameters: base - the base number, exp - the exponent
// Returns: base raised to the power of exp
double power(int base, int exp) {                                        // Function definition to calculate power
    double result = 1;                                                   // Initialize result to 1 (any number to power 0 is 1)
    for (int i = 0; i < exp; i++) {                                      // Loop from 0 to exponent-1
        result *= base;                                                  // Multiply result by base in each iteration
    }                                                                    // End of power calculation loop
    return result;                                                       // Return the calculated power
}

int main(int argc, char* argv[]) {
    int n;

    if (argc > 1) {
        n = parseInt(argv[1]);
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
