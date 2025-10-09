#include <iostream>

using namespace std;

int main() {
    int size, n;
    
    cout << "Enter the number of elements in the array: ";
    cin >> size;
    
    int numbers[100];
    
    cout << "Enter " << size << " numbers: ";
    for(int i = 0; i < size; i++) {
        cin >> numbers[i];
    }
    
    cout << "Enter which largest number you want to find (n): ";
    cin >> n;
    
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(numbers[j] < numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
    
    cout << "\nSorted array (descending): ";
    for(int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    int uniqueArray[100];
    int uniqueSize = 0;
    
    for(int i = 0; i < size; i++) {
        bool isDuplicate = false;
        for(int j = 0; j < uniqueSize; j++) {
            if(numbers[i] == uniqueArray[j]) {
                isDuplicate = true;
                break;
            }
        }
        if(!isDuplicate) {
            uniqueArray[uniqueSize] = numbers[i];
            uniqueSize++;
        }
    }
    
    cout << "Array after removing duplicates: ";
    for(int i = 0; i < uniqueSize; i++) {
        cout << uniqueArray[i] << " ";
    }
    cout << endl;
    
    if(n > uniqueSize) {
        cout << "\nError: There are only " << uniqueSize 
             << " unique numbers, but you asked for the " << n << "th largest." << endl;
    } else {
        cout << "\nThe " << n << "th largest number is: " << uniqueArray[n-1] << endl;
    }
    
    return 0;
}