/*
 * PRACTICAL 6: BINARY SEARCH IMPLEMENTATION
 * ========================================
 * 
 * PURPOSE: Implement binary search algorithm using both recursive and iterative approaches
 *          to search for an element in a sorted array efficiently.
 * 
 * ALGORITHM (Binary Search):
 * 1. Start with entire sorted array
 * 2. Find middle element and compare with target
 * 3. If match found, return index
 * 4. If target < middle, search left half
 * 5. If target > middle, search right half
 * 6. Repeat until found or search space exhausted
 * 
 * KEY CONCEPTS DEMONSTRATED:
 * - Binary search algorithm (divide and conquer)
 * - Recursive vs iterative implementation
 * - Logarithmic time complexity O(log n)
 * - Efficient searching in sorted arrays
 * - Menu-driven program with user choice
 * 
 * INPUT: Sorted array, target element, search method choice
 * OUTPUT: Index of target element or "not found" message
 * 
 * TIME COMPLEXITY: O(log n) where n is the number of elements
 * SPACE COMPLEXITY: O(log n) for recursive, O(1) for iterative
 * 
 * PREREQUISITE: Array must be sorted in ascending order
 */

#include <iostream>                       // Include input/output stream library for cout, cin
using namespace std;                    // Use standard namespace to avoid writing std:: prefix

// Recursive Binary Search Function
// Purpose: Searches for target element using divide-and-conquer approach
// Parameters: arr - sorted array, left - start index, right - end index, target - element to find
// Returns: index of target if found, -1 if not found
// Time Complexity: O(log n), Space Complexity: O(log n) due to recursion stack
int binarySearchRecursive(int arr[], int left, int right, int target) {     // Function definition with array and search parameters
    // Base case: element not found
    if (left > right) {                                                     // Check if search space is exhausted
        return -1;                                                          // Return -1 indicating element not found
    }                                                                       // End of base case
    
    // Calculate middle index to avoid overflow
    int mid = left + (right - left) / 2;                                   // 47: Calculate middle index safely
    
    // Element found at middle
    if (arr[mid] == target) {                                               // 50: Check if middle element matches target
        return mid;                                                         // 51: Return index if element found
    }                                                                       // 52: End of found case
    
    // Target is in left half
    if (arr[mid] > target) {                                                // 55: Check if target is smaller than middle element
        return binarySearchRecursive(arr, left, mid - 1, target);          // 56: Recursively search left half
    }                                                                       // 57: End of left half case
    
    // Target is in right half
    return binarySearchRecursive(arr, mid + 1, right, target);             // 60: Recursively search right half
}

// Binary search implementation using iteration (loop-based approach)
// Parameters: arr - sorted array, n - array size, target - element to find
// Returns: index of target element if found, -1 if not found
int binarySearchIterative(int arr[], int n, int target) {               // 66: Function definition for iterative binary search
    int left = 0, right = n - 1;                                        // 67: Initialize search boundaries (start and end)
    
    // Continue searching while search space exists
    while (left <= right) {                                              // 70: Loop while valid search space remains
        // Calculate middle index
        int mid = left + (right - left) / 2;                            // 72: Calculate middle index to avoid overflow
        
        // Element found
        if (arr[mid] == target) {                                        // 75: Check if middle element matches target
            return mid;                                                  // 76: Return index if element found
        }                                                                // 77: End of found case
        
        // Target is in left half
        if (arr[mid] > target) {                                         // 80: Check if target is smaller than middle element
            right = mid - 1;                                            // 81: Update right boundary to search left half
        }                                                                // 82: End of left half case
        // Target is in right half
        else {                                                           // 84: Target is larger than middle element
            left = mid + 1;                                             // 85: Update left boundary to search right half
        }                                                                // 86: End of right half case
    }                                                                    // 87: End of search loop
    
    return -1;                                                           // 89: Return -1 if element not found
}

// Main function - demonstrates both recursive and iterative binary search
int main() {                                                             // 92: Main function definition
    int n, target, choice;                                               // 93: Variables for array size, target element, and user choice
    
    cout << "=== BINARY SEARCH DEMONSTRATION ===" << endl;              // 95: Display program header
    cout << "Note: Please ensure your array is sorted in ascending order." << endl; // 96: Display sorting requirement
    
    // Input array size
    cout << "\nEnter the number of elements: ";                          // 99: Prompt for array size
    cin >> n;                                                            // 100: Read array size
    
    int arr[100];                                                        // 102: Declare array with maximum size 100
    cout << "Enter " << n << " sorted elements: ";                       // 103: Prompt for array elements
    for (int i = 0; i < n; i++) {                                       // 104: Loop to read array elements
        cin >> arr[i];                                                  // 105: Read each element
    }                                                                    // 106: End of input loop
    
    // Display the array
    cout << "\nArray: ";                                                 // 109: Label for array display
    for (int i = 0; i < n; i++) {                                       // 110: Loop to display array elements
        cout << arr[i] << " ";                                          // 111: Display each element with space
    }                                                                    // 112: End of display loop
    cout << endl;                                                        // 113: New line after array display
    
    // Input target element
    cout << "\nEnter element to search: ";                               // 116: Prompt for target element
    cin >> target;                                                       // 117: Read target element
    
    // Menu for search method
    cout << "\n=== BINARY SEARCH MENU ===" << endl;                     // 120: Display menu header
    cout << "1. Recursive Binary Search" << endl;                        // 121: Display option 1
    cout << "2. Iterative Binary Search" << endl;                        // 122: Display option 2
    cout << "Enter your choice (1 or 2): ";                             // 123: Prompt for choice
    cin >> choice;                                                       // 124: Read user choice
    
    int result = -1;                                                     // 126: Initialize result variable
    
    switch (choice) {                                                    // 128: Start switch statement for method selection
        case 1: {                                                        // 129: Handle recursive search option
            cout << "\nUsing Recursive Binary Search..." << endl;        // 130: Display method being used
            result = binarySearchRecursive(arr, 0, n - 1, target);      // 131: Call recursive search function
            break;                                                       // 132: Exit case 1
        }                                                                // 133: End of case 1
        
        case 2: {                                                        // 135: Handle iterative search option
            cout << "\nUsing Iterative Binary Search..." << endl;        // 136: Display method being used
            result = binarySearchIterative(arr, n, target);             // 137: Call iterative search function
            break;                                                       // 138: Exit case 2
        }                                                                // 139: End of case 2
        
        default:                                                         // 141: Handle invalid choice
            cout << "Invalid choice! Using Recursive Binary Search by default." << endl; // 142: Display default message
            result = binarySearchRecursive(arr, 0, n - 1, target);      // 143: Use recursive search as default
            break;                                                       // 144: Exit default case
    }                                                                    // 145: End of switch statement
    
    // Display result
    cout << "\n=== SEARCH RESULT ===" << endl;                          // 148: Display result section header
    if (result != -1) {                                                  // 149: Check if element was found
        cout << "Element " << target << " found at index " << result << endl; // 150: Display found message with index
        cout << "Position in array: " << (result + 1) << endl;          // 151: Display 1-based position
    } else {                                                             // 152: Element not found case
        cout << "Element " << target << " not found in the array." << endl; // 153: Display not found message
        cout << "Make sure the array is sorted in ascending order." << endl; // 154: Display sorting reminder
    }                                                                    // 155: End of result display
    
    return 0;                                                            // 157: Return 0 to indicate successful execution
}
