/*
 * PRACTICAL 5: MERGE TWO SORTED ARRAYS
 * ===================================
 *
 * PURPOSE: Merge two sorted arrays into a single sorted array while maintaining
 *          the sorted order without using additional sorting algorithms.
 *
 * IMPLEMENTATION NOTES:
 * - No external libraries included. Uses forward-declared C runtime functions.
 */

extern "C" int printf(const char*, ...);
extern "C" int scanf(const char*, ...);

int main() {
    int n1, n2;

    printf("Enter size of first sorted array: ");
    if (scanf("%d", &n1) != 1) { printf("Invalid input.\n"); return 1; }

    int arr1[100];
    printf("Enter %d sorted elements for first array: ", n1);
    for (int i = 0; i < n1; i++) {
        if (scanf("%d", &arr1[i]) != 1) { printf("Invalid input.\n"); return 1; }
    }

    printf("\nEnter size of second sorted array: ");
    if (scanf("%d", &n2) != 1) { printf("Invalid input.\n"); return 1; }

    int arr2[100];
    printf("Enter %d sorted elements for second array: ", n2);
    for (int i = 0; i < n2; i++) {
        if (scanf("%d", &arr2[i]) != 1) { printf("Invalid input.\n"); return 1; }
    }

    printf("\n=== INPUT ARRAYS ===\n");
    printf("First array: ");
    for (int i = 0; i < n1; i++) { printf("%d ", arr1[i]); }
    printf("\n");

    printf("Second array: ");
    for (int i = 0; i < n2; i++) { printf("%d ", arr2[i]); }
    printf("\n");

    int merged[200];
    int i = 0, j = 0, k = 0;

    printf("\n=== MERGING PROCESS ===\n");

    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            merged[k] = arr1[i];
            printf("Taking %d from first array\n", arr1[i]);
            i++;
        } else {
            merged[k] = arr2[j];
            printf("Taking %d from second array\n", arr2[j]);
            j++;
        }
        k++;
    }

    while (i < n1) {
        merged[k] = arr1[i];
        printf("Adding remaining %d from first array\n", arr1[i]);
        i++; k++;
    }

    while (j < n2) {
        merged[k] = arr2[j];
        printf("Adding remaining %d from second array\n", arr2[j]);
        j++; k++;
    }

    printf("\n=== RESULT ===\n");
    printf("Merged sorted array: ");
    for (int idx = 0; idx < k; idx++) { printf("%d ", merged[idx]); }
    printf("\n");

    printf("\nTotal elements in merged array: %d\n", k);
    printf("Merging completed successfully!\n");

    return 0;
}
