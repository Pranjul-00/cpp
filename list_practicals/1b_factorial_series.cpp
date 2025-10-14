/*
 * PRACTICAL 1B: FACTORIAL SERIES CALCULATION
 * ==========================================
 * 
 * PURPOSE: Calculate the sum of a factorial series where each term follows the pattern:
 *          S = 1 + 1/2! + 1/3! + 1/4! + ... + 1/n!
 * 
 * ALGORITHM:
 * 1. Accept number of terms (n) from user or command line
 * 2. Start with sum = 1 (first term)
 * 3. For each term i from 2 to n:
 *    - Calculate factorial of i
 *    - Add 1/i! to the sum
 * 4. Display the final sum
 * 
 * KEY CONCEPTS DEMONSTRATED:
 * - Factorial calculation using loops
 * - Mathematical series computation
 * - Command line argument handling
 * - Working with large numbers (long long)
 * 
 * INPUT: Number of terms (n)
 * OUTPUT: Sum of the factorial series
 * 
 * EXAMPLE: For n=4, S = 1 + 1/2 + 1/6 + 1/24 = 1.708333...
 * NOTE: This series converges to e (Euler's number) ≈ 2.71828
 */

#include <iostream>                       // Include input/output stream library for cout, cin
#include <cstdlib>                        // Include standard library for atoi function
using namespace std;                    // Use standard namespace to avoid writing std:: prefix

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

int main(int argc, char* argv[]) {                                       // Main function with command line arguments
    int n;                                                               // Variable to store number of terms
    
    // Check if command line argument is provided
    if (argc > 1) {                                                      // Check if at least one argument provided
        n = atoi(argv[1]);                                               // Convert first argument to integer
    } else {                                                             // If no command line argument
        cout << "Enter the number of terms: ";                          // Prompt user for input
        cin >> n;                                                        // Read number of terms from user
    }                                                                    // End of input handling
    
    double series = 1.0;                                                 // Initialize series sum to 1 (first term 1/1! = 1)
    
    cout << "\nCalculating factorial series with " << n << " terms:" << endl; // Display calculation header
    cout << "Series: 1";                                                 // Display first term
    
    // Calculate remaining terms and add to series sum
    for (int i = 2; i <= n; i++) {                                      // Loop from 2 to n (first term already included)
        double term = 1.0 / factorial(i);                               // Calculate current term (1/i!)
        series += term;                                                  // Add term to series sum
        
        cout << " + 1/" << i << "!";                                     // Display term in series format
    }                                                                    // End of series calculation loop
    
    // Display final result
    cout << " = " << series << endl;                                     // Display final series sum
    cout << "\nFactorial Series Sum = " << series << endl;               // Display result with label
    cout << "Note: This series converges to e (Euler's number) ≈ 2.71828" << endl; // Mathematical note
    
    return 0;                                                            // Return 0 to indicate successful execution
}
