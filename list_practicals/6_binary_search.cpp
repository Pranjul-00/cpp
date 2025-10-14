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
    int mid = left + (right - left) / 2;                                   // Line 47: Calculate middle index safely
    
    // Element found at middle
    if (arr[mid] == target) {                                               // Line 50: Check if middle element matches target
        return mid;                                                         // Line 51: Return index if element found
    }                                                                       // Line 52: End of found case
    
    // Target is in left half
    if (arr[mid] > target) {                                                // Line 55: Check if target is smaller than middle element
        return binarySearchRecursive(arr, left, mid - 1, target);          // Line 56: Recursively search left half
    }                                                                       // Line 57: End of left half case
    
    // Target is in right half
    return binarySearchRecursive(arr, mid + 1, right, target);             // Line 60: Recursively search right half
}

// Binary search implementation using iteration (loop-based approach)
// Parameters: arr - sorted array, n - array size, target - element to find
// Returns: index of target element if found, -1 if not found
int binarySearchIterative(int arr[], int n, int target) {               // Line 66: Function definition for iterative binary search
    int left = 0, right = n - 1;                                        // Line 67: Initialize search boundaries (start and end)
    
    // Continue searching while search space exists
    while (left <= right) {                                              // Line 70: Loop while valid search space remains
        // Calculate middle index
        int mid = left + (right - left) / 2;                            // Line 72: Calculate middle index to avoid overflow
        
        // Element found
        if (arr[mid] == target) {                                        // Line 75: Check if middle element matches target
            return mid;                                                  // Line 76: Return index if element found
        }                                                                // Line 77: End of found case
        
        // Target is in left half
        if (arr[mid] > target) {                                         // Line 80: Check if target is smaller than middle element
            right = mid - 1;                                            // Line 81: Update right boundary to search left half
        }                                                                // Line 82: End of left half case
        // Target is in right half
        else {                                                           // Line 84: Target is larger than middle element
            left = mid + 1;                                             // Line 85: Update left boundary to search right half
        }                                                                // Line 86: End of right half case
    }                                                                    // Line 87: End of search loop
    
    return -1;                                                           // Line 89: Return -1 if element not found
}

// Main function - demonstrates both recursive and iterative binary search
int main() {                                                             // Line 92: Main function definition
    int n, target, choice;                                               // Line 93: Variables for array size, target element, and user choice
    
    cout << "=== BINARY SEARCH DEMONSTRATION ===" << endl;              // Line 95: Display program header
    cout << "Note: Please ensure your array is sorted in ascending order." << endl; // Line 96: Display sorting requirement
    
    // Input array size
    cout << "\nEnter the number of elements: ";                          // Line 99: Prompt for array size
    cin >> n;                                                            // Line 100: Read array size
    
    int arr[100];                                                        // Line 102: Declare array with maximum size 100
    cout << "Enter " << n << " sorted elements: ";                       // Line 103: Prompt for array elements
    for (int i = 0; i < n; i++) {                                       // Line 104: Loop to read array elements
        cin >> arr[i];                                                  // Line 105: Read each element
    }                                                                    // Line 106: End of input loop
    
    // Display the array
    cout << "\nArray: ";                                                 // Line 109: Label for array display
    for (int i = 0; i < n; i++) {                                       // Line 110: Loop to display array elements
        cout << arr[i] << " ";                                          // Line 111: Display each element with space
    }                                                                    // Line 112: End of display loop
    cout << endl;                                                        // Line 113: New line after array display
    
    // Input target element
    cout << "\nEnter element to search: ";                               // Line 116: Prompt for target element
    cin >> target;                                                       // Line 117: Read target element
    
    // Menu for search method
    cout << "\n=== BINARY SEARCH MENU ===" << endl;                     // Line 120: Display menu header
    cout << "1. Recursive Binary Search" << endl;                        // Line 121: Display option 1
    cout << "2. Iterative Binary Search" << endl;                        // Line 122: Display option 2
    cout << "Enter your choice (1 or 2): ";                             // Line 123: Prompt for choice
    cin >> choice;                                                       // Line 124: Read user choice
    
    int result = -1;                                                     // Line 126: Initialize result variable
    
    switch (choice) {                                                    // Line 128: Start switch statement for method selection
        case 1: {                                                        // Line 129: Handle recursive search option
            cout << "\nUsing Recursive Binary Search..." << endl;        // Line 130: Display method being used
            result = binarySearchRecursive(arr, 0, n - 1, target);      // Line 131: Call recursive search function
            break;                                                       // Line 132: Exit case 1
        }                                                                // Line 133: End of case 1
        
        case 2: {                                                        // Line 135: Handle iterative search option
            cout << "\nUsing Iterative Binary Search..." << endl;        // Line 136: Display method being used
            result = binarySearchIterative(arr, n, target);             // Line 137: Call iterative search function
            break;                                                       // Line 138: Exit case 2
        }                                                                // Line 139: End of case 2
        
        default:                                                         // Line 141: Handle invalid choice
            cout << "Invalid choice! Using Recursive Binary Search by default." << endl; // Line 142: Display default message
            result = binarySearchRecursive(arr, 0, n - 1, target);      // Line 143: Use recursive search as default
            break;                                                       // Line 144: Exit default case
    }                                                                    // Line 145: End of switch statement
    
    // Display result
    cout << "\n=== SEARCH RESULT ===" << endl;                          // Line 148: Display result section header
    if (result != -1) {                                                  // Line 149: Check if element was found
        cout << "Element " << target << " found at index " << result << endl; // Line 150: Display found message with index
        cout << "Position in array: " << (result + 1) << endl;          // Line 151: Display 1-based position
    } else {                                                             // Line 152: Element not found case
        cout << "Element " << target << " not found in the array." << endl; // Line 153: Display not found message
        cout << "Make sure the array is sorted in ascending order." << endl; // Line 154: Display sorting reminder
    }                                                                    // Line 155: End of result display
    
    return 0;                                                            // Line 157: Return 0 to indicate successful execution
}
