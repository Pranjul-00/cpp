#include <iostream>
using namespace std;

// Binary search with recursion
int binarySearchRecursive(int arr[], int left, int right, int target) {
    if (left > right) {
        return -1;
    }
    
    int mid = left + (right - left) / 2;
    
    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] > target) {
        return binarySearchRecursive(arr, left, mid - 1, target);
    } else {
        return binarySearchRecursive(arr, mid + 1, right, target);
    }
}

// Binary search without recursion
int binarySearchIterative(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return -1;
}

int main() {
    int n, target, choice;
    
    cout << "Enter number of elements: ";
    cin >> n;
    
    int arr[100];
    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "Enter element to search: ";
    cin >> target;
    
    cout << "Choose search method:" << endl;
    cout << "1. Recursive Binary Search" << endl;
    cout << "2. Iterative Binary Search" << endl;
    cout << "Enter choice: ";
    cin >> choice;
    
    int result = -1;
    
    if (choice == 1) {
        result = binarySearchRecursive(arr, 0, n - 1, target);
        cout << "Using recursive method: ";
    } else if (choice == 2) {
        result = binarySearchIterative(arr, n, target);
        cout << "Using iterative method: ";
    } else {
        cout << "Invalid choice!" << endl;
        return 1;
    }
    
    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }
    
    return 0;
}
