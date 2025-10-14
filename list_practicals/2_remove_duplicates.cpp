/*
 * PRACTICAL 2: REMOVE DUPLICATES FROM ARRAY
 * =========================================
 *
 * PURPOSE: Remove duplicate elements from an array and display the unique elements
 *          in the order they first appear in the original array.
 *
 * INPUT: Array size and elements
 * OUTPUT: Array with duplicates removed
 */

#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "=== REMOVE DUPLICATES FROM ARRAY ===" << endl;
    cout << "Enter the number of elements: ";
    cin >> n;

    if (n <= 0 || n > 100) {
        cout << "Error: Please enter a valid size between 1 and 100." << endl;
        return 1;
    }

    int arr[100];

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nOriginal array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int unique[100];
    int uniqueCount = 0;

    cout << "\nRemoving duplicates..." << endl;

    for (int i = 0; i < n; i++) {
        bool isDuplicate = false;
        for (int j = 0; j < uniqueCount; j++) {
            if (arr[i] == unique[j]) {
                isDuplicate = true;
                cout << "Duplicate found: " << arr[i] << " (skipping)" << endl;
                break;
            }
        }
        if (!isDuplicate) {
            unique[uniqueCount] = arr[i];
            cout << "Adding unique element: " << arr[i] << endl;
            uniqueCount++;
        }
    }

    cout << "\n=== RESULT ===" << endl;
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < uniqueCount; i++) {
        cout << unique[i] << " ";
    }
    cout << endl;

    cout << "\nOriginal array size: " << n << endl;
    cout << "Array size after removing duplicates: " << uniqueCount << endl;
    cout << "Number of duplicates removed: " << (n - uniqueCount) << endl;

    return 0;
}
