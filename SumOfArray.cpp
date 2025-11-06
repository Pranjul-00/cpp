#include <iostream>
using namespace std;

int sumArray(int arr[], int size){
    int sum = 0;
    for(int i = 0; i < size; i++){
        sum = sum + arr[i];
    }
        return sum;
}

int main(){
    const int ArraySize=5;
    int Numbers[ArraySize];

    cout << "Enter 5 numbers: " << endl;

    for(int i=0;i<ArraySize;i++){
        cout<<"Enter number "<<i+1<<": ";
        cin>>Numbers[i];
    }

    cout << "Your Provided Array is: " << "{ ";

    for(int i=0;i<ArraySize;i++){
        cout<<Numbers[i]<<" ";
    }
    
    cout<<"}"<<endl;

    cout<<"Sum of array is: "<<sumArray(Numbers, ArraySize)<<endl;
    return 0;
}


// Q. How array passing works in C++
// When you pass an array to a function in C++, you aren't actually copying the entire array. Instead, the program passes a pointer to the first element of the array.