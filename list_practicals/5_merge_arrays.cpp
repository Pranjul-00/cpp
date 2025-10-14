/*
 * PRACTICAL 5: MERGE TWO SORTED ARRAYS
 * ===================================
 * 
 * PURPOSE: Merge two sorted arrays into a single sorted array while maintaining
 *          the sorted order without using additional sorting algorithms.
 * 
 * ALGORITHM (Two-Pointer Technique):
 * 1. Input two sorted arrays of different sizes
 * 2. Use three pointers: i for first array, j for second array, k for result
 * 3. Compare elements at current positions of both arrays
 * 4. Place smaller element in result array and advance corresponding pointer
 * 5. Continue until one array is exhausted
 * 6. Copy remaining elements from non-exhausted array
 * 
 * KEY CONCEPTS DEMONSTRATED:
 * - Two-pointer technique for merging
 * - Efficient array merging without sorting
 * - Maintaining sorted order during merge
 * - Handling arrays of different sizes
 * - Linear time complexity algorithm
 * 
 * INPUT: Two sorted arrays with their sizes
 * OUTPUT: Single merged sorted array
 * 
 * TIME COMPLEXITY: O(n1 + n2) where n1, n2 are sizes of input arrays
 * SPACE COMPLEXITY: O(n1 + n2) for the merged array
 * 
 * EXAMPLE: [1,3,5] + [2,4,6,7] → [1,2,3,4,5,6,7]
 */

#include <iostream>                       // Include input/output stream library for cout, cin
using namespace std;                    // Use standard namespace to avoid writing std:: prefix

int main() {                                                             // Line 37: Main function definition
    int n1, n2;                                                          // Line 38: Variables to store array sizes
    
    // Input for first array
    cout << "Enter size of first sorted array: ";                         // Line 41: Prompt for first array size
    cin >> n1;                                                           // Line 42: Read first array size
    
    int arr1[100];                                                        // Line 44: Declare first array with maximum size 100
    cout << "Enter " << n1 << " sorted elements for first array: ";       // Line 45: Prompt for first array elements
    for (int i = 0; i < n1; i++) {                                       // Line 46: Loop to read first array elements
        cin >> arr1[i];                                                  // Line 47: Read each element of first array
    }                                                                     // Line 48: End of first array input loop
    
    // Input for second array
    cout << "\nEnter size of second sorted array: ";                      // Line 51: Prompt for second array size
    cin >> n2;                                                           // Line 52: Read second array size
    
    int arr2[100];                                                        // Line 54: Declare second array with maximum size 100
    cout << "Enter " << n2 << " sorted elements for second array: ";      // Line 55: Prompt for second array elements
    for (int i = 0; i < n2; i++) {                                       // Line 56: Loop to read second array elements
        cin >> arr2[i];                                                  // Line 57: Read each element of second array
    }                                                                     // Line 58: End of second array input loop
    
    // Display input arrays
    cout << "\n=== INPUT ARRAYS ===" << endl;                            // Line 61: Display section header
    cout << "First array: ";                                             // Line 62: Label for first array display
    for (int i = 0; i < n1; i++) {                                       // Line 63: Loop to display first array elements
        cout << arr1[i] << " ";                                          // Line 64: Display each element with space
    }                                                                     // Line 65: End of first array display loop
    cout << endl;                                                         // Line 66: New line after first array
    
    cout << "Second array: ";                                            // Line 68: Label for second array display
    for (int i = 0; i < n2; i++) {                                       // Line 69: Loop to display second array elements
        cout << arr2[i] << " ";                                          // Line 70: Display each element with space
    }                                                                     // Line 71: End of second array display loop
    cout << endl;                                                         // Line 72: New line after second array
    
    // Merge arrays using two-pointer technique
    int merged[200];                                                      // Line 75: Array to store merged result (size = arr1 + arr2)
    int i = 0, j = 0, k = 0;                                            // Line 76: Initialize pointers for arr1, arr2, and merged array
    
    cout << "\n=== MERGING PROCESS ===" << endl;                         // Line 78: Display merging process header
    
    // Compare elements from both arrays and merge in sorted order
    while (i < n1 && j < n2) {                                          // Line 81: Loop while both arrays have unprocessed elements
        if (arr1[i] <= arr2[j]) {                                        // Line 82: Compare current elements from both arrays
            merged[k] = arr1[i];                                         // Line 83: Add smaller element to merged array
            cout << "Adding " << arr1[i] << " from first array" << endl;   // Line 84: Display which element was added
            i++;                                                          // Line 85: Move to next element in first array
        } else {                                                          // Line 86: If second array element is smaller
            merged[k] = arr2[j];                                         // Line 87: Add element from second array
            cout << "Adding " << arr2[j] << " from second array" << endl;  // Line 88: Display which element was added
            j++;                                                          // Line 89: Move to next element in second array
        }                                                                 // Line 90: End of comparison
        k++;                                                              // Line 91: Move to next position in merged array
    }                                                                     // Line 92: End of main merging loop
    
    // Copy remaining elements from first array (if any)
    while (i < n1) {                                                     // Line 95: Loop for remaining elements in first array
        merged[k] = arr1[i];                                             // Line 96: Copy remaining element from first array
        cout << "Adding remaining " << arr1[i] << " from first array" << endl; // Line 97: Display remaining element addition
        i++;                                                              // Line 98: Move to next element in first array
        k++;                                                              // Line 99: Move to next position in merged array
    }                                                                     // Line 100: End of first array cleanup loop
    
    // Copy remaining elements from second array (if any)
    while (j < n2) {                                                     // Line 103: Loop for remaining elements in second array
        merged[k] = arr2[j];                                             // Line 104: Copy remaining element from second array
        cout << "Adding remaining " << arr2[j] << " from second array" << endl; // Line 105: Display remaining element addition
        j++;                                                              // Line 106: Move to next element in second array
        k++;                                                              // Line 107: Move to next position in merged array
    }                                                                     // Line 108: End of second array cleanup loop
    
    // Display merged result
    cout << "\n=== MERGED RESULT ===" << endl;                           // Line 111: Display result section header
    cout << "Merged sorted array: ";                                     // Line 112: Label for merged array display
    for (int i = 0; i < k; i++) {                                        // Line 113: Loop to display merged array elements
        cout << merged[i] << " ";                                        // Line 114: Display each merged element with space
    }                                                                     // Line 115: End of merged array display loop
    cout << endl;                                                         // Line 116: New line after merged array
    
    cout << "\nTotal elements in merged array: " << k << endl;           // Line 118: Display total count of merged elements
    cout << "Merge operation completed successfully!" << endl;            // Line 119: Display success message
    
    return 0;                                                             // Line 121: Return 0 to indicate successful execution
}
