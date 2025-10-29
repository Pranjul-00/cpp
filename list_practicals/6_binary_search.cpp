#include <iostream>
using namespace std;

int binarySearchRecursive(int arr[], int left, int right, int target) {
    if (left > right) {
        return -1;
    }
    
    int mid = left + (right - left) / 2;
    
    if (arr[mid] == target) {
        return mid;
    }
    
    if (arr[mid] > target) {
        return binarySearchRecursive(arr, left, mid - 1, target);
    }
    
    return binarySearchRecursive(arr, mid + 1, right, target);
}

int binarySearchIterative(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;
        }
        
        if (arr[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return -1;
}

int main() {
    int n, target, choice;

    cout << "=== BINARY SEARCH DEMONSTRATION ===" << endl;
    cout << "Note: Please ensure your array is sorted in ascending order." << endl;

    cout << "\nEnter the number of elements: ";
    cin >> n;

    int arr[100];
    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nArray: ";
    for (int i = 0; i < n; i++) { cout << arr[i] << " "; }
    cout << endl;

    cout << "\nEnter element to search: ";
    cin >> target;

    cout << "\n=== BINARY SEARCH MENU ===" << endl;
    cout << "1. Recursive Binary Search" << endl;
    cout << "2. Iterative Binary Search" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    int result = -1;

    switch (choice) {
        case 1: {
            cout << "\nUsing Recursive Binary Search..." << endl;
            result = binarySearchRecursive(arr, 0, n - 1, target);
            break;
        }
        case 2: {
            cout << "\nUsing Iterative Binary Search..." << endl;
            result = binarySearchIterative(arr, n, target);
            break;
        }
        default:
            cout << "Invalid choice! Using Recursive Binary Search by default." << endl;
            result = binarySearchRecursive(arr, 0, n - 1, target);
            break;
    }

    cout << "\n=== SEARCH RESULT ===" << endl;
    if (result != -1) {
        cout << "Element " << target << " found at index " << result << endl;
        cout << "Position in array: " << (result + 1) << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
        cout << "Make sure the array is sorted in ascending order." << endl;
    }

    return 0;
}
