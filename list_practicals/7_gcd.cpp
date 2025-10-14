/*
 * PRACTICAL 7: GREATEST COMMON DIVISOR (GCD) CALCULATION
 * =====================================================
 * 
 * PURPOSE: Calculate the Greatest Common Divisor (GCD) of two numbers using both
 *          recursive and iterative implementations of Euclidean algorithm.
 * 
 * ALGORITHM (Euclidean Algorithm):
 * 1. GCD(a, b) = GCD(b, a % b) when b ≠ 0
 * 2. GCD(a, 0) = a (base case)
 * 3. Continue until remainder becomes 0
 * 
 * KEY CONCEPTS DEMONSTRATED:
 * - Euclidean algorithm for GCD calculation
 * - Recursive vs iterative implementation
 * - Mathematical algorithm implementation
 * - Modulo operation usage
 * - Menu-driven program design
 * 
 * INPUT: Two positive integers
 * OUTPUT: GCD of the two numbers
 * 
 * TIME COMPLEXITY: O(log(min(a,b))) for both methods
 * SPACE COMPLEXITY: O(log(min(a,b))) for recursive, O(1) for iterative
 * 
 * EXAMPLE: GCD(48, 18) = 6 because 6 is the largest number that divides both 48 and 18
 */

#include <iostream>                       // Include input/output stream library for cout, cin
using namespace std;                    // Use standard namespace to avoid writing std:: prefix

// Recursive implementation of Euclidean Algorithm for GCD
// Purpose: Finds GCD using the mathematical property: gcd(a,b) = gcd(b, a%b)
// Parameters: a, b - two positive integers
// Returns: Greatest Common Divisor of a and b
// Base case: when b becomes 0, a is the GCD
int gcdRecursive(int a, int b) {                                         // Function definition for recursive GCD
    // Base case: if b is 0, then GCD is a
    if (b == 0) {                                                        // Check if second number is zero (base case)
        return a;                                                        // Return first number as GCD
    }                                                                    // End of base case
    
    // Recursive case: gcd(a, b) = gcd(b, a % b)
    cout << "gcd(" << a << ", " << b << ") = gcd(" << b << ", " << (a % b) << ")" << endl; // Display recursive step
    return gcdRecursive(b, a % b);                                       // Recursive call with b and remainder
}

// Iterative implementation of Euclidean Algorithm for GCD
// Purpose: Finds GCD using loops instead of recursion
// Parameters: a, b - two positive integers
// Returns: Greatest Common Divisor of a and b
// More memory efficient than recursive version
int gcdIterative(int a, int b) {                                         // Function definition for iterative GCD
    cout << "\nIterative GCD calculation steps:" << endl;                // Display calculation header
    
    // Continue until b becomes 0
    while (b != 0) {                                                     // Loop until second number becomes zero
        cout << "gcd(" << a << ", " << b << ") -> ";                    // Display current step
        
        int temp = b;                                                    // Store b in temporary variable
        b = a % b;                                                       // Update b to remainder of a divided by b
        a = temp;                                                        // Update a to previous value of b
        
        cout << "gcd(" << a << ", " << b << ")" << endl;                // Display next step
    }                                                                    // End of while loop
    
    return a;                                                            // Return GCD (when b becomes 0, a contains GCD)
}

// Main function - demonstrates both recursive and iterative GCD calculation
int main() {                                                             // Main function definition
    int num1, num2, choice;                                              // Variables for two numbers and user choice
    
    cout << "=== GCD CALCULATOR ===" << endl;                            // Display program header
    cout << "Enter two positive integers:" << endl;                       // Prompt for input
    
    // Input two numbers
    cout << "First number: ";                                            // Prompt for first number
    cin >> num1;                                                         // Read first number
    cout << "Second number: ";                                           // Prompt for second number
    cin >> num2;                                                         // Read second number
    
    // Validate input
    if (num1 <= 0 || num2 <= 0) {                                       // Check if both numbers are positive
        cout << "Error: Please enter positive integers only." << endl;    // Display error message
        return 1;                                                        // Return error code
    }                                                                    // End of input validation
    
    // Display input
    cout << "\nCalculating GCD of " << num1 << " and " << num2 << endl;  // Display numbers being processed
    
    // Menu for method selection
    cout << "\n=== METHOD SELECTION ===" << endl;                        // Display method selection header
    cout << "1. Recursive Euclidean Algorithm" << endl;                  // Display option 1
    cout << "2. Iterative Euclidean Algorithm" << endl;                  // Display option 2
    cout << "Enter your choice (1 or 2): ";                             // Prompt for method choice
    cin >> choice;                                                       // Read user choice
    
    int result;                                                          // Variable to store GCD result
    
    switch (choice) {                                                    // Start switch statement for method selection
        case 1: {                                                        // Handle recursive method option
            cout << "\n=== RECURSIVE METHOD ===" << endl;                // Display recursive method header
            cout << "Recursive GCD calculation steps:" << endl;           // Display calculation steps header
            result = gcdRecursive(num1, num2);                           // Call recursive GCD function
            break;                                                       // Exit case 1
        }                                                                // End of case 1
        
        case 2: {                                                        // Handle iterative method option
            cout << "\n=== ITERATIVE METHOD ===" << endl;                // Display iterative method header
            result = gcdIterative(num1, num2);                           // Call iterative GCD function
            break;                                                       // Exit case 2
        }                                                                // End of case 2
        
        default:                                                         // Handle invalid choice
            cout << "Invalid choice! Using Recursive method by default." << endl; // Display default message
            result = gcdRecursive(num1, num2);                           // Use recursive method as default
            break;                                                       // Exit default case
    }                                                                    // End of switch statement
    
    // Display final result
    cout << "\n=== RESULT ===" << endl;                                  // Display result section header
    cout << "GCD of " << num1 << " and " << num2 << " is: " << result << endl; // Display final GCD result
    
    // Additional information
    cout << "\nMathematical verification:" << endl;                      // Display verification header
    cout << num1 << " = " << result << " × " << (num1 / result) << endl; // Show first number factorization
    cout << num2 << " = " << result << " × " << (num2 / result) << endl; // Show second number factorization
    
    return 0;                                                            // Return 0 to indicate successful execution
}
