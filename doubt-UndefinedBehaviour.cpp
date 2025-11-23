// output is 1 -2 -2 3 and 4 due to undefined behaviour, basically since we tweaked i multiple times. the compiler wasn't obliged to follow a specific order.

#include<iostream>
using namespace std;

int main(){
    int i = 7;

    cout << ((++i) - (i++)) + ((++i) - (i++)) << endl;
    cout << 10 - ++i << endl;
    cout << 11 - ++i << endl;
    cout << 17 - ++i << endl;
    cout << 19 - ++i << endl; 

    return 0;
}          

//-------------------------------------------

// this gives our intended output of 0 -2 -2 3 and 4.

#include<iostream>
using namespace std;

int main(){
    int i = 7;

    int a = ++i;
    int b = i++;
    int c = ++i;
    int d = i++;

    cout << a - b + c - d << endl;
    cout << 10 - ++i << endl;
    cout << 11 - ++i << endl;
    cout << 17 - ++i << endl;
    cout << 19 - ++i << endl; 

    return 0;
}