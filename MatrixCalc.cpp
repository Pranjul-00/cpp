#include <iostream>
using namespace std;

void getMatrix(int mat[][10], int r, int c, string n);
void showMatrix(int mat[][10], int r, int c);
void addMatrix(int A[][10], int B[][10], int res[][10], int r, int c);
void subMatrix(int A[][10], int B[][10], int res[][10], int r, int c);
void mulMatrix(int A[][10], int B[][10], int res[][10], int r1, int c1, int c2);
void transMatrix(int mat[][10], int res[][10], int r, int c);

int main() {
    int r1, c1, r2, c2;
    int A[10][10], B[10][10], res[10][10];
    int op;
    
    cout << "Enter rows for matrix A: ";
    cin >> r1;
    cout << "Enter columns for matrix A: ";
    cin >> c1;
    
    cout << "Enter rows for matrix B: ";
    cin >> r2;
    cout << "Enter columns for matrix B: ";
    cin >> c2;
    
    getMatrix(A, r1, c1, "A");
    getMatrix(B, r2, c2, "B");
    
    cout << "\nMatrix Operations Menu:\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Transpose\n";
    cout << "Enter your choice (1-4): ";
    cin >> op;
    
    switch(op) {
        case 1:
            if (r1 == r2 && c1 == c2) {
                addMatrix(A, B, res, r1, c1);
                cout << "\nResult of A + B:\n";
                showMatrix(res, r1, c1);
            } else {
                cout << "Error: Matrices must have same dimensions for addition!";
            }
            break;
            
        case 2:
            if (r1 == r2 && c1 == c2) {
                subMatrix(A, B, res, r1, c1);
                cout << "\nResult of A - B:\n";
                showMatrix(res, r1, c1);
            } else {
                cout << "Error: Matrices must have same dimensions for subtraction!";
            }
            break;
            
        case 3:
            if (c1 == r2) {
                mulMatrix(A, B, res, r1, c1, c2);
                cout << "\nResult of A * B:\n";
                showMatrix(res, r1, c2);
            } else {
                cout << "Error: Cannot multiply - columns of A must equal rows of B!";
            }
            break;
            
        case 4:
            transMatrix(A, res, r1, c1);
            cout << "\nTranspose of Matrix A:\n";
            showMatrix(res, c1, r1);
            
            transMatrix(B, res, r2, c2);
            cout << "\nTranspose of Matrix B:\n";
            showMatrix(res, c2, r2);
            break;
            
        default:
            cout << "Invalid choice!";
    }
    
    return 0;
}

void getMatrix(int mat[][10], int r, int c, string n) {
    cout << "\nEnter elements for matrix " << n << " (" << r << "x" << c << "):\n";
    cout << "Enter elements row by row.\n";
    cout << "For each element, enter the number and press Enter:\n";
    
    for (int i = 0; i < r; i++) {
        cout << "Row " << i+1 << ":\n";
        for (int j = 0; j < c; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
}

void showMatrix(int mat[][10], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void addMatrix(int A[][10], int B[][10], int res[][10], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            res[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subMatrix(int A[][10], int B[][10], int res[][10], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            res[i][j] = A[i][j] - B[i][j];
        }
    }
}

void mulMatrix(int A[][10], int B[][10], int res[][10], int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                res[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void transMatrix(int mat[][10], int res[][10], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            res[j][i] = mat[i][j];
        }
    }
}