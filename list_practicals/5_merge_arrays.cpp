#include <iostream>
using namespace std;

int main() {
    int n1, n2;

    cout << "Enter size of first sorted array: ";
    cin >> n1;

    int arr1[100];
    cout << "Enter " << n1 << " sorted elements for first array: ";
    for (int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }

    cout << "\nEnter size of second sorted array: ";
    cin >> n2;

    int arr2[100];
    cout << "Enter " << n2 << " sorted elements for second array: ";
    for (int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }

    cout << "\n=== INPUT ARRAYS ===" << endl;
    cout << "First array: ";
    for (int i = 0; i < n1; i++) { cout << arr1[i] << " "; }
    cout << endl;

    cout << "Second array: ";
    for (int i = 0; i < n2; i++) { cout << arr2[i] << " "; }
    cout << endl;

    int merged[200];
    int i = 0, j = 0, k = 0;

    cout << "\n=== MERGING PROCESS ===" << endl;

    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            merged[k] = arr1[i];
            cout << "Taking " << arr1[i] << " from first array" << endl;
            i++;
        } else {
            merged[k] = arr2[j];
            cout << "Taking " << arr2[j] << " from second array" << endl;
            j++;
        }
        k++;
    }

    while (i < n1) {
        merged[k] = arr1[i];
        cout << "Adding remaining " << arr1[i] << " from first array" << endl;
        i++; k++;
    }

    while (j < n2) {
        merged[k] = arr2[j];
        cout << "Adding remaining " << arr2[j] << " from second array" << endl;
        j++; k++;
    }

    cout << "\n=== RESULT ===" << endl;
    cout << "Merged sorted array: ";
    for (int idx = 0; idx < k; idx++) { cout << merged[idx] << " "; }
    cout << endl;

    cout << "\nTotal elements in merged array: " << k << endl;
    cout << "Merging completed successfully!" << endl;

    return 0;
}
