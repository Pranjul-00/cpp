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

int main() {                                                             // Main function definition
    int n1, n2;                                                          // Variables to store array sizes
    
    // Input for first array
    cout << "Enter size of first sorted array: ";                         // Prompt for first array size
    cin >> n1;                                                           // Read first array size
    
    int arr1[100];                                                        // Declare first array with maximum size 100
    cout << "Enter " << n1 << " sorted elements for first array: ";       // Prompt for first array elements
    for (int i = 0; i < n1; i++) {                                       // Loop to read first array elements
        cin >> arr1[i];                                                  // Read each element of first array
    }                                                                     // End of first array input loop
    
    // Input for second array
    cout << "\nEnter size of second sorted array: ";                      // Prompt for second array size
    cin >> n2;                                                           // Read second array size
    
    int arr2[100];                                                        // Declare second array with maximum size 100
    cout << "Enter " << n2 << " sorted elements for second array: ";      // Prompt for second array elements
    for (int i = 0; i < n2; i++) {                                       // Loop to read second array elements
        cin >> arr2[i];                                                  // Read each element of second array
    }                                                                     // End of second array input loop
    
    // Display input arrays
    cout << "\n=== INPUT ARRAYS ===" << endl;                            // Display input section header
    cout << "First array: ";                                             // Label for first array
    for (int i = 0; i < n1; i++) {                                       // Loop to display first array
        cout << arr1[i] << " ";                                          // Display each element with space
    }                                                                     // End of first array display loop
    cout << endl;                                                         // New line after first array
    
    cout << "Second array: ";                                            // Label for second array
    for (int i = 0; i < n2; i++) {                                       // Loop to display second array
        cout << arr2[i] << " ";                                          // Display each element with space
    }                                                                     // End of second array display loop
    cout << endl;                                                         // New line after second array
    
    // Merge arrays using two-pointer technique
    int merged[200];                                                      // Array to store merged result (max size 200)
    int i = 0, j = 0, k = 0;                                             // Initialize pointers for arr1, arr2, and merged array
    
    cout << "\n=== MERGING PROCESS ===" << endl;                         // Display merging process header
    
    // Compare elements from both arrays and merge in sorted order
    while (i < n1 && j < n2) {                                           // Continue while both arrays have elements
        if (arr1[i] <= arr2[j]) {                                        // Compare current elements
            merged[k] = arr1[i];                                          // Take element from first array
            cout << "Taking " << arr1[i] << " from first array" << endl;  // Display which element is taken
            i++;                                                          // Move to next element in first array
        } else {                                                          // If second array element is smaller
            merged[k] = arr2[j];                                          // Take element from second array
            cout << "Taking " << arr2[j] << " from second array" << endl; // Display which element is taken
            j++;                                                          // Move to next element in second array
        }                                                                 // End of comparison
        k++;                                                              // Move to next position in merged array
    }                                                                     // End of main merging loop
    
    // Copy remaining elements from first array (if any)
    while (i < n1) {                                                      // Check if first array has remaining elements
        merged[k] = arr1[i];                                              // Copy remaining element from first array
        cout << "Adding remaining " << arr1[i] << " from first array" << endl; // Display remaining element
        i++;                                                              // Move to next element in first array
        k++;                                                              // Move to next position in merged array
    }                                                                     // End of first array cleanup loop
    
    // Copy remaining elements from second array (if any)
    while (j < n2) {                                                      // Check if second array has remaining elements
        merged[k] = arr2[j];                                              // Copy remaining element from second array
        cout << "Adding remaining " << arr2[j] << " from second array" << endl; // Display remaining element
        j++;                                                              // Move to next element in second array
        k++;                                                              // Move to next position in merged array
    }                                                                     // End of second array cleanup loop
    
    // Display final merged array
    cout << "\n=== RESULT ===" << endl;                                  // Display result section header
    cout << "Merged sorted array: ";                                     // Label for merged array
    for (int i = 0; i < k; i++) {                                        // Loop to display merged array
        cout << merged[i] << " ";                                         // Display each element with space
    }                                                                     // End of merged array display loop
    cout << endl;                                                         // New line after merged array
    
    cout << "\nTotal elements in merged array: " << k << endl;           // Display total count of merged elements
    cout << "Merging completed successfully!" << endl;                   // Display success message
    
    return 0;                                                             // Return 0 to indicate successful execution
}
