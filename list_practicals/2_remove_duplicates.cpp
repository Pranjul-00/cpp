/*
 * PRACTICAL 2: REMOVE DUPLICATES FROM ARRAY
 * =========================================
 * 
 * PURPOSE: Remove duplicate elements from an array and display the unique elements
 *          in the order they first appear in the original array.
 * 
 * ALGORITHM:
 * 1. Accept array size and elements from user
 * 2. Create a new array to store unique elements
 * 3. For each element in original array:
 *    - Check if it already exists in unique array
 *    - If not found, add it to unique array
 * 4. Display the unique array
 * 
 * KEY CONCEPTS DEMONSTRATED:
 * - Array manipulation and traversal
 * - Nested loops for searching
 * - Boolean logic for duplicate detection
 * - Linear search algorithm
 * - Memory efficient duplicate removal
 * 
 * INPUT: Array size (n) and n integer elements
 * OUTPUT: Array with duplicates removed
 * 
 * TIME COMPLEXITY: O(n²) where n is the number of elements
 * SPACE COMPLEXITY: O(n) for the unique array
 * 
 * EXAMPLE: Input [1,2,2,3,1,4] → Output [1,2,3,4]
 */

#include <iostream>                       // Include input/output stream library for cout, cin
using namespace std;                    // Use standard namespace to avoid writing std:: prefix

int main() {                                                             // Main function definition
    int n;                                                               // Variable to store array size
    
    cout << "=== REMOVE DUPLICATES FROM ARRAY ===" << endl;             // Display program header
    cout << "Enter the number of elements: ";                           // Prompt for array size
    cin >> n;                                                            // Read array size from user
    
    // Validate array size
    if (n <= 0 || n > 100) {                                            // Check if array size is valid
        cout << "Error: Please enter a valid size between 1 and 100." << endl; // Display error message
        return 1;                                                        // Return error code
    }                                                                    // End of validation
    
    int arr[100];                                                        // Declare array with maximum size 100
    
    cout << "Enter " << n << " elements: ";                             // Prompt for array elements
    for (int i = 0; i < n; i++) {                                       // Loop to read array elements
        cin >> arr[i];                                                  // Read each element
    }                                                                    // End of input loop
    
    // Display original array
    cout << "\nOriginal array: ";                                        // Label for original array
    for (int i = 0; i < n; i++) {                                       // Loop to display original array
        cout << arr[i] << " ";                                          // Display each element with space
    }                                                                    // End of display loop
    cout << endl;                                                        // New line after array
    
    // Remove duplicates using nested loops
    int unique[100];                                                     // Array to store unique elements
    int uniqueCount = 0;                                                 // Counter for unique elements
    
    cout << "\nRemoving duplicates..." << endl;                         // Display process status
    
    for (int i = 0; i < n; i++) {                                       // Loop through original array
        bool isDuplicate = false;                                        // Flag to check if element is duplicate
        
        // Check if current element already exists in unique array
        for (int j = 0; j < uniqueCount; j++) {                         // Loop through unique array
            if (arr[i] == unique[j]) {                                   // Compare current element with unique elements
                isDuplicate = true;                                      // Mark as duplicate if found
                cout << "Duplicate found: " << arr[i] << " (skipping)" << endl; // Display duplicate message
                break;                                                   // Exit inner loop
            }                                                            // End of comparison
        }                                                                // End of unique array check
        
        // If not duplicate, add to unique array
        if (!isDuplicate) {                                              // If element is not duplicate
            unique[uniqueCount] = arr[i];                                // Add element to unique array
            cout << "Adding unique element: " << arr[i] << endl;         // Display addition message
            uniqueCount++;                                               // Increment unique count
        }                                                                // End of duplicate check
    }                                                                    // End of duplicate removal loop
    
    // Display result
    cout << "\n=== RESULT ===" << endl;                                  // Display result header
    cout << "Array after removing duplicates: ";                        // Label for result array
    for (int i = 0; i < uniqueCount; i++) {                             // Loop to display unique elements
        cout << unique[i] << " ";                                        // Display each unique element
    }                                                                    // End of result display loop
    cout << endl;                                                        // New line after result
    
    cout << "\nOriginal array size: " << n << endl;                     // Display original size
    cout << "Array size after removing duplicates: " << uniqueCount << endl; // Display final size
    cout << "Number of duplicates removed: " << (n - uniqueCount) << endl; // Display count of removed elements
    
    return 0;                                                            // Return 0 to indicate successful execution
}
