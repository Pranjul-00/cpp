#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    
    int arr[100];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Remove duplicates
    int unique[100];
    int uniqueCount = 0;
    
    for (int i = 0; i < n; i++) {
        bool isDuplicate = false;
        for (int j = 0; j < uniqueCount; j++) {
            if (arr[i] == unique[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            unique[uniqueCount] = arr[i];
            uniqueCount++;
        }
    }
    
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < uniqueCount; i++) {
        cout << unique[i] << " ";
    }
    cout << endl;
    
    return 0;
}
