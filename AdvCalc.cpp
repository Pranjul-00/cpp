#include <iostream>
#include  <typeinfo>
#include <string>
#include <cmath>

using namespace std;

int main() {
    cout << "Enter the password : ";
    string password;
    cin >> password;
    if(password == "Pranjul") {
        cout << "Access granted" << endl;
        cout << "Welcome to the dashboard \nChoose an option :" << endl;
        cout << "1. Add" << endl;
        cout << "2. Sub" << endl;
        cout << "3. Mul" << endl;
        cout << "4. Div" << endl;

        cout << "Enter your option : ";
        int option;
        cin >> option;
        cout << "You selected option " << option << endl;

        int num1, num2;
        cout << "Enter the first number : ";
        cin >> num1;
        cout << "Enter the second number : ";
        cin >> num2;
        if(option == 1) {
            cout << "The sum of " << num1 << " and " << num2 << " is " << num1 + num2 << endl;
        }
        else if(option == 2) {
            cout << "The difference of " << num1 << " and " << num2 << " is " << num1 - num2 << endl;
        }
        else if(option == 3) {
            cout << "The product of " << num1 << " and " << num2 << " is " << num1 * num2 << endl;
        }
        else if(option == 4) {
            cout << "The quotient of " << num1 << " and " << num2 << " is " << num1 / num2 << endl;
        }
    }
    else {
        cout << "Access denied" << endl;
    }
    return 0;
}