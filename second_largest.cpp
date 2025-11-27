#include <iostream>
#include <climits> // For INT_MIN

using namespace std;

int findSecondLargest(int arr[], int n);

int main() {
    // Hardcoded for quick testing/grading
    int data[] = {12, 35, 1, 10, 34, 1, 35};
    int n = sizeof(data) / sizeof(data[0]);

    int result = findSecondLargest(data, n);

    if (result != INT_MIN)
        cout << "The second largest element is: " << result << endl;
    else
        cout << "No second largest element found." << endl;

    return 0;
}

int findSecondLargest(int arr[], int n) {
    if (n < 2) return INT_MIN; // Not enough elements

    int first = INT_MIN;
    int second = INT_MIN;

    for (int i = 0; i < n; i++) {
        // Case 1: New largest found
        if (arr[i] > first) {
            second = first;   // Demote the current winner to second place
            first = arr[i];   // Update winner
        } 
        // Case 2: Number is smaller than first, but bigger than second
        // AND it's not equal to first (to avoid duplicates counting as second)
        else if (arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }

    return second;
}