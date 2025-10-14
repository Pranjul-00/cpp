/*
 * PRACTICAL 1A: ALTERNATING SERIES CALCULATION
 * ============================================
 *
 * PURPOSE: Calculate the sum of an alternating series where each term follows the pattern:
 *          S = 1 - 1/2^2 + 1/3^3 - 1/4^4 + ... + (-1)^(n+1)/n^n
 *
 * IMPLEMENTATION NOTES:
 * - No external libraries included. Uses forward-declared C runtime functions.
 *
 * ALGORITHM:
 * 1. Accept number of terms (n) from user or command line
 * 2. For each term i from 1 to n:
 *    - Calculate 1 / (i^i)
 *    - Add if i is odd, subtract if i is even
 * 3. Display the final sum
 */

extern "C" int printf(const char*, ...);
extern "C" int scanf(const char*, ...);
extern "C" int atoi(const char*);

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
        n = atoi(argv[1]);
    } else {
        printf("Enter the number of terms: ");
        if (scanf("%d", &n) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
    }

    double series = 0.0;

    printf("\nCalculating alternating series with %d terms:\n", n);
    printf("Series: ");

    for (int i = 1; i <= n; i++) {
        double term = 1.0 / power(i, i);

        if (i > 1) {
            if (i % 2 == 1) {
                printf(" + ");
            } else {
                printf(" - ");
            }
        }

        printf("1/%d^%d", i, i);

        if (i % 2 == 1) {
            series += term;
        } else {
            series -= term;
        }
    }

    printf(" = %.10f\n", series);
    printf("\nAlternating Series Sum = %.10f\n", series);

    return 0;
}
