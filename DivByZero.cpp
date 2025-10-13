#include <iostream>
using namespace std;

int main(){
    int num, denom;
    cout << "Enter Numerator : ";
    cin >> num;
    cout << "Enter Denominator : ";
    cin >> denom;
    if(denom == 0){
        cout << "Error : Division by zero" << endl;
        return 0;
    }
    else{
        cout << "The division of " << num << " and " << denom << " is " << num / denom << endl;
        cout << "The Quotient is " << num / denom << endl;
        cout << "The Remainder is " << num % denom << endl;
    }
    return 0;
}