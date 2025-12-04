#include <iostream>
using namespace std;

//function for sum

void sum(int A[10][10], int r1, int c1, int B[10][10], int r2, int c2) {
    if (r1 != r2 || c1 != c2) {
        cout << "Matrices are incompatible for addition." << endl;    // since for addn: both matrices should be of same order.
        return;
    }
    cout << "Sum of Matrices :" << endl;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cout << A[i][j] + B[i][j] << " ";
        }
        cout << endl;
    }
}


//Function for product of matrices

void product(int A[10][10], int r1, int c1, int B[10][10], int r2, int c2) {
    if (c1 != r2) {
        cout << "Matrices are incompatible for multiplication." << endl;     // for multiplication: A = mXn and B = nXp, result = mXp
        return;
    }
    cout << "Product Matrix:" << endl;
    for (int i = 0; i < r1; i++) {           //row of A
        for (int j = 0; j < c2; j++) {       //column of B
            int val = 0;
            for (int k = 0; k < c1; k++) {
                val += A[i][k] * B[k][j];
            }
            cout << val << " ";
        }
        cout << endl;
    }
}

// Function to give transpose of the matrix.
// transpose will not throw any errors because we are performing action on a single matrix.

void transpose(int A[10][10], int r, int c) {            
    cout << "Transpose Matrix:" << endl;
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            cout << A[j][i] << " ";           //instead of iXj just print jXi
        }
        cout << endl;
    }
}

int main() {
    int r1, c1, r2, c2;
    int A[10][10], B[10][10];

    cout << "Enter rows and columns for Matrix A: ";     //ask for order of matrix A
    cin >> r1 >> c1;
    cout << "Enter elements for Matrix A:" << endl;      //ask for elements in A
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++) cin >> A[i][j];

    cout << "Enter rows and cols for Matrix B: ";        //ask for order of matrix B
    cin >> r2 >> c2;
    cout << "Enter elements for Matrix B:" << endl;      //ask for elements in B
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++) cin >> B[i][j];     

    int choice;
    cout << "\n1. Sum\n2. Product\n3. Transpose\nEnter choice: ";         //display user a choice of the functions available and ask for input.
    cin >> choice;

    // the arguments for the functions are like (int A[10][10], int r1, int c1, int B[10][10], int r2, int c2); here r and c are number of rows and columns respectively.

    switch (choice) {
        case 1: sum(A, r1, c1, B, r2, c2);
            break;
        case 2: product(A, r1, c1, B, r2, c2); 
            break;
        case 3: 
            cout << "Transposing Matrix A..." << endl;
            transpose(A, r1, c1); 
            break;
        default: cout << "Invalid choice";
    }

    return 0;
}