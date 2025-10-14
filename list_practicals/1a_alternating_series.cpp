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
 *    - Calculate 1/i^i
 *    - Add if i is odd, subtract if i is even
 * 3. Display the final sum
 * 
 * KEY CONCEPTS DEMONSTRATED:
 * - Mathematical series computation
 * - Power calculation using loops
 * - Command line argument handling
 * - Alternating sign pattern implementation
 * 
 * INPUT: Number of terms (n)
 * OUTPUT: Sum of the alternating series
 * 
 * EXAMPLE: For n=4, S = 1 - 1/4 + 1/27 - 1/256 = 0.7130...
 */

#include <iostream>                       // Include input/output stream library for cout, cin
#include <cstdlib>                        // Include standard library for atoi function
using namespace std;                    // Use standard namespace to avoid writing std:: prefix

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

int main(int argc, char* argv[]) {                                       // Main function with command line arguments
    int n;                                                               // Variable to store number of terms
    
    // Check if command line argument is provided
    if (argc > 1) {                                                      // Check if at least one argument provided
        n = atoi(argv[1]);                                               // Convert first argument to integer
    } else {                                                             // If no command line argument
        cout << "Enter the number of terms: ";                          // Prompt user for input
        cin >> n;                                                        // Read number of terms from user
    }                                                                    // End of input handling
    
    double series = 0;                                                   // Initialize series sum to 0
    
    cout << "\nCalculating alternating series with " << n << " terms:" << endl; // Display calculation header
    cout << "Series: ";                                                  // Start displaying series formula
    
    // Calculate each term and add/subtract to series sum
    for (int i = 1; i <= n; i++) {                                      // Loop from 1 to n terms
        double term = 1.0 / power(i, i);                                // Calculate current term (1/i^i)
        
        // Display term with appropriate sign
        if (i > 1) {                                                     // For terms after first, show sign
            if (i % 2 == 1) {                                            // If term number is odd
                cout << " + ";                                           // Display plus sign
            } else {                                                     // If term number is even
                cout << " - ";                                           // Display minus sign
            }                                                            // End of sign display
        }                                                                // End of sign check
        
        cout << "1/" << i << "^" << i;                                   // Display term formula
        
        // Add or subtract term based on position (alternating)
        if (i % 2 == 1) {                                                // If term position is odd
            series += term;                                              // Add term to series sum
        } else {                                                         // If term position is even
            series -= term;                                              // Subtract term from series sum
        }                                                                // End of alternating logic
    }                                                                    // End of series calculation loop
    
    // Display final result
    cout << " = " << series << endl;                                     // Display final series sum
    cout << "\nAlternating Series Sum = " << series << endl;             // Display result with label
    
    return 0;                                                            // Return 0 to indicate successful execution
}
