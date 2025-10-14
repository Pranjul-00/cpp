/*
 * PRACTICAL 1B: FACTORIAL SERIES CALCULATION
 * ==========================================
 *
 * PURPOSE: Calculate the sum of a factorial series where each term follows the pattern:
 *          S = 1 + 1/2! + 1/3! + 1/4! + ... + 1/n!
 *
 * IMPLEMENTATION NOTES:
 * - No external libraries included. Uses forward-declared C runtime functions.
 *
 * ALGORITHM:
 * 1. Accept number of terms (n) from user or command line
 * 2. Start with sum = 1 (first term)
 * 3. For each term i from 2 to n:
 *    - Calculate factorial of i
 *    - Add 1/i! to the sum
 * 4. Display the final sum
 *
 * NOTE: This series converges to e (Euler's number) ≈ 2.71828
 */

extern "C" int printf(const char*, ...);
extern "C" int scanf(const char*, ...);
extern "C" int atoi(const char*);

// Function to calculate factorial of a number using iterative method
// Parameters: n - the number whose factorial is to be calculated
// Returns: n! (factorial of n)
// Note: Uses long long to handle larger factorial values
long long factorial(int n) {                                            // Function definition to calculate factorial
    long long fact = 1;                                                 // Initialize factorial result to 1
    for (int i = 1; i <= n; i++) {                                      // Loop from 1 to n
        fact *= i;                                                       // Multiply factorial by current number
    }                                                                    // End of factorial calculation loop
    return fact;                                                         // Return calculated factorial
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

    double series = 1.0;

    printf("\nCalculating factorial series with %d terms:\n", n);
    printf("Series: 1");

    for (int i = 2; i <= n; i++) {
        double term = 1.0 / factorial(i);
        series += term;
        printf(" + 1/%d!", i);
    }

    printf(" = %.10f\n", series);
    printf("\nFactorial Series Sum = %.10f\n", series);
    printf("Note: This series converges to e (Euler's number) ≈ 2.71828\n");

    return 0;
}
