/*
 * PRACTICAL 2: REMOVE DUPLICATES FROM ARRAY
 * =========================================
 *
 * PURPOSE: Remove duplicate elements from an array and display the unique elements
 *          in the order they first appear in the original array.
 *
 * IMPLEMENTATION NOTES:
 * - No external libraries included. Uses forward-declared C runtime functions.
 */

extern "C" int printf(const char*, ...);
extern "C" int scanf(const char*, ...);

int main() {
    int n;

    printf("=== REMOVE DUPLICATES FROM ARRAY ===\n");
    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (n <= 0 || n > 100) {
        printf("Error: Please enter a valid size between 1 and 100.\n");
        return 1;
    }

    int arr[100];

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
    }

    printf("\nOriginal array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int unique[100];
    int uniqueCount = 0;

    printf("\nRemoving duplicates...\n");

    for (int i = 0; i < n; i++) {
        bool isDuplicate = false;
        for (int j = 0; j < uniqueCount; j++) {
            if (arr[i] == unique[j]) {
                isDuplicate = true;
                printf("Duplicate found: %d (skipping)\n", arr[i]);
                break;
            }
        }
        if (!isDuplicate) {
            unique[uniqueCount] = arr[i];
            printf("Adding unique element: %d\n", arr[i]);
            uniqueCount++;
        }
    }

    printf("\n=== RESULT ===\n");
    printf("Array after removing duplicates: ");
    for (int i = 0; i < uniqueCount; i++) {
        printf("%d ", unique[i]);
    }
    printf("\n");

    printf("\nOriginal array size: %d\n", n);
    printf("Array size after removing duplicates: %d\n", uniqueCount);
    printf("Number of duplicates removed: %d\n", (n - uniqueCount));

    return 0;
}
