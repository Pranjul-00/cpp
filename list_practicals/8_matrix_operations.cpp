/*
 * PRACTICAL 8: MATRIX OPERATIONS
 * =============================
 *
 * PURPOSE: Implement fundamental matrix operations including addition, multiplication,
 *          and transpose using 2D arrays with a menu-driven interface.
 */

#include <iostream>
using namespace std;

// Function to input matrix elements from user
// Purpose: Reads matrix elements row by row from user input
// Parameters: matrix - 2D array to store elements, rows - number of rows, cols - number of columns
void inputMatrix(int matrix[10][10], int rows, int cols) {               // Function definition for matrix input
    cout << "Enter matrix elements (" << rows << "x" << cols << "):" << endl;
    
    for (int i = 0; i < rows; i++) {                                     // Loop through each row
        cout << "Row " << (i + 1) << ": ";
        for (int j = 0; j < cols; j++) {                                 // Loop through each column in current row
            cin >> matrix[i][j];
        }                                                                // End of column loop
    }                                                                    // End of row loop
}

// Function to display matrix in formatted output
// Parameters: matrix - 2D array to display, rows - number of rows, cols - number of columns
void displayMatrix(int matrix[][10], int rows, int cols) {               // Function definition for matrix display
    for (int i = 0; i < rows; i++) {                                     // Loop through each row
        cout << "[ ";                                                     // Display opening bracket for row
        for (int j = 0; j < cols; j++) {                                 // Loop through each column in current row
            cout << matrix[i][j];                                        // Display element at position [i][j]
            if (j < cols - 1) cout << "\t";                              // Add tab separator between elements (except last)
        }                                                                // End of column loop
        cout << " ]" << endl;                                            // Display closing bracket and new line
    }                                                                    // End of row loop
}

// Function to add two matrices
// Purpose: Performs element-wise addition of two matrices
// Parameters: mat1, mat2 - input matrices, result - output matrix, rows, cols - dimensions
// Prerequisite: Both matrices must have same dimensions
void addMatrices(int mat1[][10], int mat2[][10], int result[][10], int rows, int cols) { // Function definition for matrix addition
    cout << "\nPerforming matrix addition..." << endl;
    
    for (int i = 0; i < rows; i++) {                                     // Loop through each row
        for (int j = 0; j < cols; j++) {                                 // Loop through each column
            result[i][j] = mat1[i][j] + mat2[i][j];                      // Add corresponding elements from both matrices
        }                                                                // End of column loop
    }                                                                    // End of row loop
    
    cout << "Matrix addition completed successfully!" << endl;
}

// Function to multiply two matrices using dot product
// Parameters: mat1, mat2 - input matrices, result - output matrix
//            r1, c1 - dimensions of first matrix, r2, c2 - dimensions of second matrix
// Returns: true if multiplication possible, false otherwise
// Condition: Columns of first matrix must equal rows of second matrix
bool multiplyMatrices(int mat1[][10], int mat2[][10], int result[][10], int r1, int c1, int r2, int c2) { 
    // Check if multiplication is possible
    if (c1 != r2) {
        cout << "\nError: Matrix multiplication not possible!" << endl;
        cout << "Columns of first matrix (" << c1 << ") must equal rows of second matrix (" << r2 << ")" << endl;
        return false;
    }
    
    cout << "\nPerforming matrix multiplication..." << endl;
    cout << "Result will be a " << r1 << "x" << c2 << " matrix" << endl;
    
    // Initialize result matrix to zero
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
        }
    }
    
    // Perform multiplication using dot product
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    
    cout << "Matrix multiplication completed successfully!" << endl;
    return true;
}

// Function to transpose a matrix (convert rows to columns)
// Parameters: matrix - input matrix, result - transposed matrix, rows, cols - original dimensions
// Result: rows and columns are swapped in the transposed matrix
void transposeMatrix(int matrix[][10], int result[][10], int rows, int cols) { // Function definition for matrix transpose
    cout << "\nPerforming matrix transpose..." << endl;
    cout << "Original: " << rows << "x" << cols << " -> Transposed: " << cols << "x" << rows << endl;
    
    // Swap rows and columns: result[j][i] = matrix[i][j]
    for (int i = 0; i < rows; i++) {                                     // Loop through original matrix rows
        for (int j = 0; j < cols; j++) {                                 // Loop through original matrix columns
            result[j][i] = matrix[i][j];                                 // Swap row and column indices
        }                                                                // End of column loop
    }                                                                    // End of row loop
}

// Main function - Menu-driven matrix operations program
int main() {                                                             // Main function definition
    int choice;                                                          // Variable to store user menu choice
    int mat1[10][10], mat2[10][10], result[10][10];                     // Declare matrices with maximum size 10x10
    int r1, c1, r2, c2;                                                 // Variables for matrix dimensions
    
    cout << "=== MATRIX OPERATIONS PROGRAM ===" << endl;
    cout << "This program performs basic matrix operations on 2D arrays." << endl;
    cout << "Maximum supported matrix size: 10x10" << endl;
    
    // Main program loop
    while (true) {                                                       // Start infinite loop for menu
        cout << "\n--- Matrix Operations Menu ---" << endl;
        cout << "1. Matrix Addition (A + B)" << endl;
        cout << "2. Matrix Multiplication (A × B)" << endl;
        cout << "3. Matrix Transpose (A^T)" << endl;
        cout << "4. Exit Program" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        
        switch (choice) {                                                // Start switch statement for menu handling
            case 1: // Matrix Addition
                cout << "\n=== MATRIX ADDITION ===" << endl;
                cout << "Enter dimensions of first matrix (rows cols): ";
                cin >> r1 >> c1;
                cout << "Enter dimensions of second matrix (rows cols): ";
                cin >> r2 >> c2;
                
                if (r1 != r2 || c1 != c2) {                              // Check if matrices have same dimensions
                    cout << "Error: Matrices must have same dimensions for addition!" << endl;
                    cout << "First matrix: " << r1 << "x" << c1 << ", Second matrix: " << r2 << "x" << c2 << endl;
                    break;
                }
                
                cout << "\nFirst matrix (" << r1 << "x" << c1 << "):" << endl;
                inputMatrix(mat1, r1, c1);
                cout << "\nSecond matrix (" << r2 << "x" << c2 << "):" << endl;
                inputMatrix(mat2, r2, c2);
                
                cout << "\nMatrix A:" << endl;
                displayMatrix(mat1, r1, c1);
                cout << "\nMatrix B:" << endl;
                displayMatrix(mat2, r2, c2);
                
                addMatrices(mat1, mat2, result, r1, c1);
                cout << "\nResult (A + B):" << endl;
                displayMatrix(result, r1, c1);
                break;
                
            case 2: // Matrix Multiplication
                cout << "\n=== MATRIX MULTIPLICATION ===" << endl;
                cout << "Note: Columns of first matrix must equal rows of second matrix" << endl;
                cout << "Enter dimensions of first matrix (rows cols): ";
                cin >> r1 >> c1;
                cout << "Enter dimensions of second matrix (rows cols): ";
                cin >> r2 >> c2;
                
                cout << "\nFirst matrix (" << r1 << "x" << c1 << "):" << endl;
                inputMatrix(mat1, r1, c1);
                cout << "\nSecond matrix (" << r2 << "x" << c2 << "):" << endl;
                inputMatrix(mat2, r2, c2);
                
                cout << "\nMatrix A (" << r1 << "x" << c1 << "):" << endl;
                displayMatrix(mat1, r1, c1);
                cout << "\nMatrix B (" << r2 << "x" << c2 << "):" << endl;
                displayMatrix(mat2, r2, c2);
                
                if (multiplyMatrices(mat1, mat2, result, r1, c1, r2, c2)) {
                    cout << "\nResult (A × B):" << endl;
                    displayMatrix(result, r1, c2);
                }
                break;
                
            case 3: // Matrix Transpose
                cout << "\n=== MATRIX TRANSPOSE ===" << endl;
                cout << "Enter dimensions of matrix (rows cols): ";
                cin >> r1 >> c1;
                cout << "\nEnter matrix (" << r1 << "x" << c1 << "):" << endl;
                inputMatrix(mat1, r1, c1);
                
                cout << "\nOriginal Matrix A:" << endl;
                displayMatrix(mat1, r1, c1);
                
                transposeMatrix(mat1, result, r1, c1);
                cout << "\nTranspose of Matrix A (A^T):" << endl;
                displayMatrix(result, c1, r1);
                break;
                
            case 4: // Exit Program
                cout << "\nThank you for using the Matrix Operations Program!" << endl;
                return 0;
                
            default: // Invalid choice
                cout << "Invalid choice! Please enter a number between 1 and 4." << endl;
        }
    }
    
    return 0;                                                             // Return 0 to indicate successful execution
}
