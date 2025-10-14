/*
 * PRACTICAL 6: BINARY SEARCH IMPLEMENTATION
 * ========================================
 *
 * PURPOSE: Implement binary search algorithm using both recursive and iterative approaches
 *          to search for an element in a sorted array efficiently.
 *
 * IMPLEMENTATION NOTES:
 * - No headers are included. Minimal C runtime prototypes are forward-declared
 *   and used for console I/O.
 */

extern "C" int printf(const char*, ...);
extern "C" int scanf(const char*, ...);

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
int main() {
    int n, target, choice;

    printf("=== BINARY SEARCH DEMONSTRATION ===\n");
    printf("Note: Please ensure your array is sorted in ascending order.\n");

    printf("\nEnter the number of elements: ");
    if (scanf("%d", &n) != 1) { printf("Invalid input.\n"); return 1; }

    int arr[100];
    printf("Enter %d sorted elements: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) { printf("Invalid input.\n"); return 1; }
    }

    printf("\nArray: ");
    for (int i = 0; i < n; i++) { printf("%d ", arr[i]); }
    printf("\n");

    printf("\nEnter element to search: ");
    if (scanf("%d", &target) != 1) { printf("Invalid input.\n"); return 1; }

    printf("\n=== BINARY SEARCH MENU ===\n");
    printf("1. Recursive Binary Search\n");
    printf("2. Iterative Binary Search\n");
    printf("Enter your choice (1 or 2): ");
    if (scanf("%d", &choice) != 1) { printf("Invalid input.\n"); return 1; }

    int result = -1;

    switch (choice) {
        case 1: {
            printf("\nUsing Recursive Binary Search...\n");
            result = binarySearchRecursive(arr, 0, n - 1, target);
            break;
        }
        case 2: {
            printf("\nUsing Iterative Binary Search...\n");
            result = binarySearchIterative(arr, n, target);
            break;
        }
        default:
            printf("Invalid choice! Using Recursive Binary Search by default.\n");
            result = binarySearchRecursive(arr, 0, n - 1, target);
            break;
    }

    printf("\n=== SEARCH RESULT ===\n");
    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
        printf("Position in array: %d\n", (result + 1));
    } else {
        printf("Element %d not found in the array.\n", target);
        printf("Make sure the array is sorted in ascending order.\n");
    }

    return 0;
}
