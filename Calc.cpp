#include <iostream>
using namespace std;

int main(){
    int num1,num2; //defines two integer variables
    cout << "Enter First number : "; //asks for first number
    cin >> num1;
    cout << "Enter Second number : "; //asks for second number
    cin >> num2;
    cout << "Addition of " << num1 << " and " << num2 << " is " << num1 + num2 << endl; //prints addition
    cout << "Subtraction of " << num1 << " and " << num2 << " is " << num1 - num2 << endl; //prints subtraction
    cout << "Multiplication of " << num1 << " and " << num2 << " is " << num1 * num2 << endl; //prints multiplication
    cout << "Division of " << num1 << " and " << num2 << " is " << num1 / num2 << endl; //prints division
    return 0;
}