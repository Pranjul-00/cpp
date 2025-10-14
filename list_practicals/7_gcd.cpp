/*
 * PRACTICAL 7: GREATEST COMMON DIVISOR (GCD) CALCULATION
 * =====================================================
 *
 * PURPOSE: Calculate the Greatest Common Divisor (GCD) of two numbers using both
 *          recursive and iterative implementations of Euclidean algorithm.
 */

#include <iostream>
using namespace std;

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
    cout << "gcd(" << a << ", " << b << ") = gcd(" << b << ", " << (a % b) << ")" << endl;
    return gcdRecursive(b, a % b);                                       // Recursive call with b and remainder
}

// Iterative implementation of Euclidean Algorithm for GCD
// Purpose: Finds GCD using loops instead of recursion
// Parameters: a, b - two positive integers
// Returns: Greatest Common Divisor of a and b
// More memory efficient than recursive version
int gcdIterative(int a, int b) {                                         // Function definition for iterative GCD
    cout << "\nIterative GCD calculation steps:" << endl;
    
    // Continue until b becomes 0
    while (b != 0) {                                                     // Loop until second number becomes zero
        cout << "gcd(" << a << ", " << b << ") -> ";
        
        int temp = b;                                                    // Store b in temporary variable
        b = a % b;                                                       // Update b to remainder of a divided by b
        a = temp;                                                        // Update a to previous value of b
        
        cout << "gcd(" << a << ", " << b << ")" << endl;
    }                                                                    // End of while loop
    
    return a;                                                            // Return GCD (when b becomes 0, a contains GCD)
}

// Main function - demonstrates both recursive and iterative GCD calculation
int main() {                                                             // Main function definition
    int num1, num2, choice;                                              // Variables for two numbers and user choice
    
    cout << "=== GCD CALCULATOR ===" << endl;
    cout << "Enter two positive integers:" << endl;
    
    cout << "First number: ";
    cin >> num1;
    cout << "Second number: ";
    cin >> num2;
    
    if (num1 <= 0 || num2 <= 0) {                                       // Check if both numbers are positive
        cout << "Error: Please enter positive integers only." << endl;
        return 1;                                                        // Return error code
    }
    
    cout << "\nCalculating GCD of " << num1 << " and " << num2 << endl;
    
    cout << "\n=== METHOD SELECTION ===" << endl;
    cout << "1. Recursive Euclidean Algorithm" << endl;
    cout << "2. Iterative Euclidean Algorithm" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;
    
    int result;
    
    switch (choice) {                                                    // Start switch statement for method selection
        case 1: {                                                        // Handle recursive method option
            cout << "\n=== RECURSIVE METHOD ===" << endl;
            cout << "Recursive GCD calculation steps:" << endl;
            result = gcdRecursive(num1, num2);                           // Call recursive GCD function
            break;                                                       // Exit case 1
        }
        
        case 2: {                                                        // Handle iterative method option
            cout << "\n=== ITERATIVE METHOD ===" << endl;
            result = gcdIterative(num1, num2);                           // Call iterative GCD function
            break;                                                       // Exit case 2
        }
        
        default:                                                         // Handle invalid choice
            cout << "Invalid choice! Using Recursive method by default." << endl;
            result = gcdRecursive(num1, num2);                           // Use recursive method as default
            break;                                                       // Exit default case
    }
    
    cout << "\n=== RESULT ===" << endl;
    cout << "GCD of " << num1 << " and " << num2 << " is: " << result << endl;
    
    cout << "\nMathematical verification:" << endl;
    cout << num1 << " = " << result << " × " << (num1 / result) << endl;
    cout << num2 << " = " << result << " × " << (num2 / result) << endl;
    
    return 0;                                                            // Return 0 to indicate successful execution
}
