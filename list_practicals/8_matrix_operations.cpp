/*
 * PRACTICAL 8: MATRIX OPERATIONS
 * ==============================
 *
 * PURPOSE: Perform basic matrix operations including addition, multiplication,
 *          and transpose on user-defined matrices.
 */

#include <iostream>
using namespace std;

// Function to input matrix elements from user
// Purpose: Reads matrix elements row by row from user input
// Parameters: matrix - 2D array to store elements, rows - number of rows, cols - number of columns
void inputMatrix(int matrix[][10], int rows, int cols, const char* name) {
    cout << "\nEnter elements for " << name << " (" << rows << "x" << cols << "):" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// Function to display matrix in formatted output
// Parameters: matrix - 2D array to display, rows - number of rows, cols - number of columns
void displayMatrix(int matrix[][10], int rows, int cols, const char* name) {
    cout << "\n" << name << " Matrix (" << rows << "x" << cols << "):" << endl;
    for (int i = 0; i < rows; i++) {
        cout << "[ ";
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "]" << endl;
    }
    cout << endl;
}

// Function to add two matrices
// Purpose: Performs element-wise addition of two matrices
// Parameters: mat1, mat2 - input matrices, result - output matrix, rows, cols - dimensions
// Prerequisite: Both matrices must have same dimensions
void addMatrices(int a[][10], int b[][10], int result[][10], int rows, int cols) {
    cout << "\nPerforming Matrix Addition..." << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
            cout << "result[" << i << "][" << j << "] = " << a[i][j] << " + " << b[i][j] << " = " << result[i][j] << endl;
        }
    }
}

// Function to multiply two matrices using dot product
// Parameters: mat1, mat2 - input matrices, result - output matrix
//            r1, c1 - dimensions of first matrix, r2, c2 - dimensions of second matrix
// Returns: true if multiplication possible, false otherwise
// Condition: Columns of first matrix must equal rows of second matrix
void multiplyMatrices(int a[][10], int b[][10], int result[][10], int r1, int c1, int c2) {
    cout << "\nPerforming Matrix Multiplication..." << endl;
    
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            cout << "\nCalculating result[" << i << "][" << j << "]:" << endl;
            
            for (int k = 0; k < c1; k++) {
                cout << "  " << a[i][k] << " * " << b[k][j] << " = " << (a[i][k] * b[k][j]) << endl;
                result[i][j] += a[i][k] * b[k][j];
            }
            cout << "  Sum = " << result[i][j] << endl;
        }
    }
}

// Function to transpose a matrix (convert rows to columns)
// Parameters: matrix - input matrix, result - transposed matrix, rows, cols - original dimensions
void transposeMatrix(int matrix[][10], int result[][10], int rows, int cols) {
    cout << "\nPerforming Matrix Transpose..." << endl;
    cout << "Original: " << rows << "x" << cols << " -> Transposed: " << cols << "x" << rows << endl;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

// Main function - Menu-driven matrix operations program
int main() {
    int choice;
    int matrix1[10][10], matrix2[10][10], result[10][10];
    int r1, c1, r2, c2;

    cout << "=== MATRIX OPERATIONS PROGRAM ===" << endl;
    cout << "\nSelect an operation:" << endl;
    cout << "1. Matrix Addition" << endl;
    cout << "2. Matrix Multiplication" << endl;
    cout << "3. Matrix Transpose" << endl;
    cout << "\nEnter your choice (1-3): ";
    cin >> choice;

    switch (choice) {
        case 1: {
            cout << "\n=== MATRIX ADDITION ===" << endl;
            cout << "Note: Both matrices must have the same dimensions." << endl;
            
            cout << "\nEnter dimensions for matrices:" << endl;
            cout << "Number of rows: ";
            cin >> r1;
            cout << "Number of columns: ";
            cin >> c1;
            
            r2 = r1; c2 = c1;
            
            inputMatrix(matrix1, r1, c1, "Matrix A");
            inputMatrix(matrix2, r2, c2, "Matrix B");
            
            displayMatrix(matrix1, r1, c1, "Matrix A");
            displayMatrix(matrix2, r2, c2, "Matrix B");
            
            addMatrices(matrix1, matrix2, result, r1, c1);
            displayMatrix(result, r1, c1, "Result (A + B)");
            break;
        }
        
        case 2: {
            cout << "\n=== MATRIX MULTIPLICATION ===" << endl;
            cout << "Note: Columns of first matrix must equal rows of second matrix." << endl;
            
            cout << "\nEnter dimensions for first matrix:" << endl;
            cout << "Number of rows: ";
            cin >> r1;
            cout << "Number of columns: ";
            cin >> c1;
            
            cout << "\nEnter dimensions for second matrix:" << endl;
            cout << "Number of rows: ";
            cin >> r2;
            cout << "Number of columns: ";
            cin >> c2;
            
            if (c1 != r2) {
                cout << "\nError: Matrix multiplication not possible!" << endl;
                cout << "Columns of first matrix (" << c1 << ") must equal rows of second matrix (" << r2 << ")." << endl;
                return 1;
            }
            
            inputMatrix(matrix1, r1, c1, "Matrix A");
            inputMatrix(matrix2, r2, c2, "Matrix B");
            
            displayMatrix(matrix1, r1, c1, "Matrix A");
            displayMatrix(matrix2, r2, c2, "Matrix B");
            
            multiplyMatrices(matrix1, matrix2, result, r1, c1, c2);
            displayMatrix(result, r1, c2, "Result (A × B)");
            break;
        }
        
        case 3: {
            cout << "\n=== MATRIX TRANSPOSE ===" << endl;
            cout << "\nEnter dimensions for matrix:" << endl;
            cout << "Number of rows: ";
            cin >> r1;
            cout << "Number of columns: ";
            cin >> c1;
            
            inputMatrix(matrix1, r1, c1, "Matrix A");
            displayMatrix(matrix1, r1, c1, "Original Matrix A");
            
            transposeMatrix(matrix1, result, r1, c1);
            displayMatrix(result, c1, r1, "Transpose of A");
            break;
        }
        
        default:
            cout << "Invalid choice! Please select 1, 2, or 3." << endl;
            return 1;
    }
    
    return 0;
}
