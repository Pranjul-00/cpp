#include <iostream>
using namespace std;

int findGCD(int a, int b){
    if (b==0){
        return a;
    }
    return findGCD(b, a%b);
}

int main(){
    int n1,n2;
    cout << "Enter 2 Numbers (e.g. 2 3) : ";
    cin >> n1 >> n2;

    cout << "GCD is " << findGCD(n1,n2);
}