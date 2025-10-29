#include <iostream>
using namespace std;

int gcdRecursive(int a, int b) {
    if (b == 0) {
        return a;
    }
    
    cout << "gcd(" << a << ", " << b << ") = gcd(" << b << ", " << (a % b) << ")" << endl;
    return gcdRecursive(b, a % b);
}

int gcdIterative(int a, int b) {
    cout << "\nIterative GCD calculation steps:" << endl;
    
    while (b != 0) {
        cout << "gcd(" << a << ", " << b << ") -> ";
        
        int temp = b;
        b = a % b;
        a = temp;
        
        cout << "gcd(" << a << ", " << b << ")" << endl;
    }
    
    return a;
}

int main() {
    int num1, num2, choice;
    
    cout << "=== GCD CALCULATOR ===" << endl;
    cout << "Enter two positive integers:" << endl;
    
    cout << "First number: ";
    cin >> num1;
    cout << "Second number: ";
    cin >> num2;
    
    if (num1 <= 0 || num2 <= 0) {
        cout << "Error: Please enter positive integers only." << endl;
        return 1;
    }
    
    cout << "\nCalculating GCD of " << num1 << " and " << num2 << endl;
    
    cout << "\n=== METHOD SELECTION ===" << endl;
    cout << "1. Recursive Euclidean Algorithm" << endl;
    cout << "2. Iterative Euclidean Algorithm" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;
    
    int result;
    
    switch (choice) {
        case 1: {
            cout << "\n=== RECURSIVE METHOD ===" << endl;
            cout << "Recursive GCD calculation steps:" << endl;
            result = gcdRecursive(num1, num2);
            break;
        }
        
        case 2: {
            cout << "\n=== ITERATIVE METHOD ===" << endl;
            result = gcdIterative(num1, num2);
            break;
        }
        
        default:
            cout << "Invalid choice! Using Recursive method by default." << endl;
            result = gcdRecursive(num1, num2);
            break;
    }
    
    cout << "\n=== RESULT ===" << endl;
    cout << "GCD of " << num1 << " and " << num2 << " is: " << result << endl;
    
    cout << "\nMathematical verification:" << endl;
    cout << num1 << " = " << result << " × " << (num1 / result) << endl;
    cout << num2 << " = " << result << " × " << (num2 / result) << endl;
    
    return 0;
}
