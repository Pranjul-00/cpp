#include <iostream>
using namespace std;

// GCD with recursion
int gcdRecursive(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcdRecursive(b, a % b);
}

// GCD without recursion
int gcdIterative(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2, choice;
    
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    
    cout << "Choose method:" << endl;
    cout << "1. Recursive GCD" << endl;
    cout << "2. Iterative GCD" << endl;
    cout << "Enter choice: ";
    cin >> choice;
    
    int result;
    
    if (choice == 1) {
        result = gcdRecursive(num1, num2);
        cout << "GCD using recursion: " << result << endl;
    } else if (choice == 2) {
        result = gcdIterative(num1, num2);
        cout << "GCD using iteration: " << result << endl;
    } else {
        cout << "Invalid choice!" << endl;
        return 1;
    }
    
    return 0;
}
