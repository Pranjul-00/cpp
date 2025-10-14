/*
 * PRACTICAL 7: GREATEST COMMON DIVISOR (GCD) CALCULATION
 * =====================================================
 *
 * PURPOSE: Calculate the Greatest Common Divisor (GCD) of two numbers using both
 *          recursive and iterative implementations of Euclidean algorithm.
 *
 * IMPLEMENTATION NOTES:
 * - No external libraries included. Uses forward-declared C runtime functions.
 */

extern "C" int printf(const char*, ...);
extern "C" int scanf(const char*, ...);

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
    printf("gcd(%d, %d) = gcd(%d, %d)\n", a, b, b, (a % b));
    return gcdRecursive(b, a % b);                                       // Recursive call with b and remainder
}

// Iterative implementation of Euclidean Algorithm for GCD
// Purpose: Finds GCD using loops instead of recursion
// Parameters: a, b - two positive integers
// Returns: Greatest Common Divisor of a and b
// More memory efficient than recursive version
int gcdIterative(int a, int b) {                                         // Function definition for iterative GCD
    printf("\nIterative GCD calculation steps:\n");
    
    // Continue until b becomes 0
    while (b != 0) {                                                     // Loop until second number becomes zero
        printf("gcd(%d, %d) -> ", a, b);
        
        int temp = b;                                                    // Store b in temporary variable
        b = a % b;                                                       // Update b to remainder of a divided by b
        a = temp;                                                        // Update a to previous value of b
        
        printf("gcd(%d, %d)\n", a, b);
    }                                                                    // End of while loop
    
    return a;                                                            // Return GCD (when b becomes 0, a contains GCD)
}

// Main function - demonstrates both recursive and iterative GCD calculation
int main() {
    int num1, num2, choice;
    
    printf("=== GCD CALCULATOR ===\n");
    printf("Enter two positive integers:\n");
    
    printf("First number: ");
    if (scanf("%d", &num1) != 1) { printf("Invalid input.\n"); return 1; }
    printf("Second number: ");
    if (scanf("%d", &num2) != 1) { printf("Invalid input.\n"); return 1; }
    
    if (num1 <= 0 || num2 <= 0) {
        printf("Error: Please enter positive integers only.\n");
        return 1;
    }
    
    printf("\nCalculating GCD of %d and %d\n", num1, num2);
    
    printf("\n=== METHOD SELECTION ===\n");
    printf("1. Recursive Euclidean Algorithm\n");
    printf("2. Iterative Euclidean Algorithm\n");
    printf("Enter your choice (1 or 2): ");
    if (scanf("%d", &choice) != 1) { printf("Invalid input.\n"); return 1; }
    
    int result;
    
    switch (choice) {
        case 1: {
            printf("\n=== RECURSIVE METHOD ===\n");
            printf("Recursive GCD calculation steps:\n");
            result = gcdRecursive(num1, num2);
            break;
        }
        
        case 2: {
            printf("\n=== ITERATIVE METHOD ===\n");
            result = gcdIterative(num1, num2);
            break;
        }
        
        default:
            printf("Invalid choice! Using Recursive method by default.\n");
            result = gcdRecursive(num1, num2);
            break;
    }
    
    printf("\n=== RESULT ===\n");
    printf("GCD of %d and %d is: %d\n", num1, num2, result);
    
    printf("\nMathematical verification:\n");
    printf("%d = %d × %d\n", num1, result, (num1 / result));
    printf("%d = %d × %d\n", num2, result, (num2 / result));
    
    return 0;
}
