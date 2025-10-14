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

#include <iostream>                       // Line 32: Include input/output stream library for cout, cin
using namespace std;                    // Line 33: Use standard namespace to avoid writing std:: prefix

// Recursive implementation of Euclidean Algorithm for GCD
// Purpose: Finds GCD using the mathematical property: gcd(a,b) = gcd(b, a%b)
// Parameters: a, b - two positive integers
// Returns: Greatest Common Divisor of a and b
// Base case: when b becomes 0, a is the GCD
int gcdRecursive(int a, int b) {                                         // Line 40: Function definition for recursive GCD
    // Base case: if b is 0, then GCD is a
    if (b == 0) {                                                        // Line 42: Check if second number is zero (base case)
        return a;                                                        // Line 43: Return first number as GCD
    }                                                                    // Line 44: End of base case
    
    // Recursive case: gcd(a, b) = gcd(b, a % b)
    cout << "gcd(" << a << ", " << b << ") = gcd(" << b << ", " << (a % b) << ")" << endl; // Line 47: Display recursive step
    return gcdRecursive(b, a % b);                                       // Line 48: Recursive call with b and remainder
}

// Iterative implementation of Euclidean Algorithm for GCD
// Purpose: Finds GCD using loops instead of recursion
// Parameters: a, b - two positive integers
// Returns: Greatest Common Divisor of a and b
// More memory efficient than recursive version
int gcdIterative(int a, int b) {                                         // Line 55: Function definition for iterative GCD
    cout << "\nIterative GCD calculation steps:" << endl;                // Line 56: Display calculation header
    
    // Continue until b becomes 0
    while (b != 0) {                                                     // Line 59: Loop until second number becomes zero
        cout << "gcd(" << a << ", " << b << ") -> ";                    // Line 60: Display current step
        
        int temp = b;                                                    // Line 62: Store b in temporary variable
        b = a % b;                                                       // Line 63: Update b to remainder of a divided by b
        a = temp;                                                        // Line 64: Update a to previous value of b
        
        cout << "gcd(" << a << ", " << b << ")" << endl;                // Line 66: Display next step
    }                                                                    // Line 67: End of while loop
    
    return a;                                                            // Line 69: Return GCD (when b becomes 0, a contains GCD)
}

// Main function - demonstrates both recursive and iterative GCD calculation
int main() {                                                             // Line 72: Main function definition
    int num1, num2, choice;                                              // Line 73: Variables for two numbers and user choice
    
    cout << "=== GCD CALCULATOR ===" << endl;                            // Line 75: Display program header
    cout << "Enter two positive integers:" << endl;                       // Line 76: Prompt for input
    
    // Input two numbers
    cout << "First number: ";                                            // Line 79: Prompt for first number
    cin >> num1;                                                         // Line 80: Read first number
    cout << "Second number: ";                                           // Line 81: Prompt for second number
    cin >> num2;                                                         // Line 82: Read second number
    
    // Validate input
    if (num1 <= 0 || num2 <= 0) {                                       // Line 85: Check if both numbers are positive
        cout << "Error: Please enter positive integers only." << endl;    // Line 86: Display error message
        return 1;                                                        // Line 87: Return error code
    }                                                                    // Line 88: End of input validation
    
    // Display input
    cout << "\nCalculating GCD of " << num1 << " and " << num2 << endl;  // Line 91: Display numbers being processed
    
    // Menu for method selection
    cout << "\n=== METHOD SELECTION ===" << endl;                        // Line 94: Display method selection header
    cout << "1. Recursive Euclidean Algorithm" << endl;                  // Line 95: Display option 1
    cout << "2. Iterative Euclidean Algorithm" << endl;                  // Line 96: Display option 2
    cout << "Enter your choice (1 or 2): ";                             // Line 97: Prompt for method choice
    cin >> choice;                                                       // Line 98: Read user choice
    
    int result;                                                          // Line 100: Variable to store GCD result
    
    switch (choice) {                                                    // Line 102: Start switch statement for method selection
        case 1: {                                                        // Line 103: Handle recursive method option
            cout << "\n=== RECURSIVE METHOD ===" << endl;                // Line 104: Display recursive method header
            cout << "Recursive GCD calculation steps:" << endl;           // Line 105: Display calculation steps header
            result = gcdRecursive(num1, num2);                           // Line 106: Call recursive GCD function
            break;                                                       // Line 107: Exit case 1
        }                                                                // Line 108: End of case 1
        
        case 2: {                                                        // Line 110: Handle iterative method option
            cout << "\n=== ITERATIVE METHOD ===" << endl;                // Line 111: Display iterative method header
            result = gcdIterative(num1, num2);                           // Line 112: Call iterative GCD function
            break;                                                       // Line 113: Exit case 2
        }                                                                // Line 114: End of case 2
        
        default:                                                         // Line 116: Handle invalid choice
            cout << "Invalid choice! Using Recursive method by default." << endl; // Line 117: Display default message
            result = gcdRecursive(num1, num2);                           // Line 118: Use recursive method as default
            break;                                                       // Line 119: Exit default case
    }                                                                    // Line 120: End of switch statement
    
    // Display final result
    cout << "\n=== RESULT ===" << endl;                                  // Line 123: Display result section header
    cout << "GCD of " << num1 << " and " << num2 << " is: " << result << endl; // Line 124: Display final GCD result
    
    // Additional information
    cout << "\nMathematical verification:" << endl;                      // Line 127: Display verification header
    cout << num1 << " = " << result << " × " << (num1 / result) << endl; // Line 128: Show first number factorization
    cout << num2 << " = " << result << " × " << (num2 / result) << endl; // Line 129: Show second number factorization
    
    return 0;                                                            // Line 131: Return 0 to indicate successful execution
}
