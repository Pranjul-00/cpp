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
    int mid = left + (right - left) / 2;                                   // Calculate middle index safely
    
    // Element found at middle
    if (arr[mid] == target) {                                               // Check if middle element matches target
        return mid;                                                         // Return index if element found
    }                                                                       // End of found case
    
    // Target is in left half
    if (arr[mid] > target) {                                                // Check if target is smaller than middle element
        return binarySearchRecursive(arr, left, mid - 1, target);          // Recursively search left half
    }                                                                       // End of left half case
    
    // Target is in right half
    return binarySearchRecursive(arr, mid + 1, right, target);             // Recursively search right half
}

// Binary search implementation using iteration (loop-based approach)
// Parameters: arr - sorted array, n - array size, target - element to find
// Returns: index of target element if found, -1 if not found
int binarySearchIterative(int arr[], int n, int target) {               // Function definition for iterative binary search
    int left = 0, right = n - 1;                                        // Initialize search boundaries (start and end)
    
    // Continue searching while search space exists
    while (left <= right) {                                              // Loop while valid search space remains
        // Calculate middle index
        int mid = left + (right - left) / 2;                            // Calculate middle index to avoid overflow
        
        // Element found
        if (arr[mid] == target) {                                        // Check if middle element matches target
            return mid;                                                  // Return index if element found
        }                                                                // End of found case
        
        // Target is in left half
        if (arr[mid] > target) {                                         // Check if target is smaller than middle element
            right = mid - 1;                                            // Update right boundary to search left half
        }                                                                // End of left half case
        // Target is in right half
        else {                                                           // Target is larger than middle element
            left = mid + 1;                                             // Update left boundary to search right half
        }                                                                // End of right half case
    }                                                                    // End of search loop
    
    return -1;                                                           // Return -1 if element not found
}

// Main function - demonstrates both recursive and iterative binary search
int main() {                                                             // Main function definition
    int n, target, choice;                                               // Variables for array size, target element, and user choice
    
    cout << "=== BINARY SEARCH DEMONSTRATION ===" << endl;              // Display program header
    cout << "Note: Please ensure your array is sorted in ascending order." << endl; // Display sorting requirement
    
    // Input array size
    cout << "\nEnter the number of elements: ";                          // Prompt for array size
    cin >> n;                                                            // Read array size
    
    int arr[100];                                                        // Declare array with maximum size 100
    cout << "Enter " << n << " sorted elements: ";                       // Prompt for array elements
    for (int i = 0; i < n; i++) {                                       // Loop to read array elements
        cin >> arr[i];                                                  // Read each element
    }                                                                    // End of input loop
    
    // Display the array
    cout << "\nArray: ";                                                 // Label for array display
    for (int i = 0; i < n; i++) {                                       // Loop to display array elements
        cout << arr[i] << " ";                                          // Display each element with space
    }                                                                    // End of display loop
    cout << endl;                                                        // New line after array display
    
    // Input target element
    cout << "\nEnter element to search: ";                               // Prompt for target element
    cin >> target;                                                       // Read target element
    
    // Menu for search method
    cout << "\n=== BINARY SEARCH MENU ===" << endl;                     // Display menu header
    cout << "1. Recursive Binary Search" << endl;                        // Display option 1
    cout << "2. Iterative Binary Search" << endl;                        // Display option 2
    cout << "Enter your choice (1 or 2): ";                             // Prompt for choice
    cin >> choice;                                                       // Read user choice
    
    int result = -1;                                                     // Initialize result variable
    
    switch (choice) {                                                    // Start switch statement for method selection
        case 1: {                                                        // Handle recursive search option
            cout << "\nUsing Recursive Binary Search..." << endl;        // Display method being used
            result = binarySearchRecursive(arr, 0, n - 1, target);      // Call recursive search function
            break;                                                       // Exit case 1
        }                                                                // End of case 1
        
        case 2: {                                                        // Handle iterative search option
            cout << "\nUsing Iterative Binary Search..." << endl;        // Display method being used
            result = binarySearchIterative(arr, n, target);             // Call iterative search function
            break;                                                       // Exit case 2
        }                                                                // End of case 2
        
        default:                                                         // Handle invalid choice
            cout << "Invalid choice! Using Recursive Binary Search by default." << endl; // Display default message
            result = binarySearchRecursive(arr, 0, n - 1, target);      // Use recursive search as default
            break;                                                       // Exit default case
    }                                                                    // End of switch statement
    
    // Display result
    cout << "\n=== SEARCH RESULT ===" << endl;                          // Display result section header
    if (result != -1) {                                                  // Check if element was found
        cout << "Element " << target << " found at index " << result << endl; // Display found message with index
        cout << "Position in array: " << (result + 1) << endl;          // Display 1-based position
    } else {                                                             // Element not found case
        cout << "Element " << target << " not found in the array." << endl; // Display not found message
        cout << "Make sure the array is sorted in ascending order." << endl; // Display sorting reminder
    }                                                                    // End of result display
    
    return 0;                                                            // Return 0 to indicate successful execution
}
