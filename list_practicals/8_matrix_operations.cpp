#include <iostream>
using namespace std;

// Function to input matrix
void inputMatrix(int matrix[][10], int rows, int cols) {
    cout << "Enter matrix elements:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
}

// Function to display matrix
void displayMatrix(int matrix[][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to add matrices
void addMatrices(int mat1[][10], int mat2[][10], int result[][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

// Function to multiply matrices
bool multiplyMatrices(int mat1[][10], int mat2[][10], int result[][10], int r1, int c1, int r2, int c2) {
    if (c1 != r2) {
        cout << "Error: Matrices cannot be multiplied (incompatible dimensions)" << endl;
        return false;
    }
    
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return true;
}

// Function to transpose matrix
void transposeMatrix(int matrix[][10], int result[][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int choice;
    int mat1[10][10], mat2[10][10], result[10][10];
    int r1, c1, r2, c2;
    
    while (true) {
        cout << "\n--- Matrix Operations Menu ---" << endl;
        cout << "1. Matrix Addition" << endl;
        cout << "2. Matrix Multiplication" << endl;
        cout << "3. Matrix Transpose" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter dimensions of first matrix (rows cols): ";
                cin >> r1 >> c1;
                cout << "Enter dimensions of second matrix (rows cols): ";
                cin >> r2 >> c2;
                
                if (r1 != r2 || c1 != c2) {
                    cout << "Error: Matrices must have same dimensions for addition" << endl;
                    break;
                }
                
                cout << "First matrix:" << endl;
                inputMatrix(mat1, r1, c1);
                cout << "Second matrix:" << endl;
                inputMatrix(mat2, r2, c2);
                
                addMatrices(mat1, mat2, result, r1, c1);
                cout << "Sum of matrices:" << endl;
                displayMatrix(result, r1, c1);
                break;
                
            case 2:
                cout << "Enter dimensions of first matrix (rows cols): ";
                cin >> r1 >> c1;
                cout << "Enter dimensions of second matrix (rows cols): ";
                cin >> r2 >> c2;
                
                cout << "First matrix:" << endl;
                inputMatrix(mat1, r1, c1);
                cout << "Second matrix:" << endl;
                inputMatrix(mat2, r2, c2);
                
                if (multiplyMatrices(mat1, mat2, result, r1, c1, r2, c2)) {
                    cout << "Product of matrices:" << endl;
                    displayMatrix(result, r1, c2);
                }
                break;
                
            case 3:
                cout << "Enter dimensions of matrix (rows cols): ";
                cin >> r1 >> c1;
                cout << "Enter matrix:" << endl;
                inputMatrix(mat1, r1, c1);
                
                transposeMatrix(mat1, result, r1, c1);
                cout << "Transpose of matrix:" << endl;
                displayMatrix(result, c1, r1);
                break;
                
            case 4:
                return 0;
                
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    
    return 0;
}
