/*
 * PRACTICAL 8: MATRIX OPERATIONS
 * =============================
 * 
 * PURPOSE: Implement fundamental matrix operations including addition, multiplication,
 *          and transpose using 2D arrays with a menu-driven interface.
 * 
 * OPERATIONS SUPPORTED:
 * 1. Matrix Addition - Add corresponding elements of two matrices
 * 2. Matrix Multiplication - Multiply two matrices using dot product
 * 3. Matrix Transpose - Convert rows to columns and vice versa
 * 
 * KEY CONCEPTS DEMONSTRATED:
 * - 2D array manipulation and traversal
 * - Matrix arithmetic operations
 * - Nested loops for matrix processing
 * - Menu-driven program design
 * - Input validation for matrix dimensions
 * - Dynamic matrix operations based on user input
 * 
 * INPUT: Matrix dimensions and elements based on selected operation
 * OUTPUT: Result matrix after performing the selected operation
 * 
 * MATHEMATICAL RULES:
 * - Addition: Matrices must have same dimensions (m×n + m×n = m×n)
 * - Multiplication: Columns of first = Rows of second (m×n × n×p = m×p)
 * - Transpose: m×n matrix becomes n×m matrix
 */

#include <iostream>                       // Line 32: Include input/output stream library for cout, cin
using namespace std;                    // Line 33: Use standard namespace to avoid writing std:: prefix

// Function to input matrix elements from user
// Purpose: Reads matrix elements row by row from user input
// Parameters: matrix - 2D array to store elements, rows - number of rows, cols - number of columns
void inputMatrix(int matrix[10][10], int rows, int cols) {               // Line 37: Function definition for matrix input
    cout << "Enter matrix elements (" << rows << "x" << cols << "):" << endl; // Line 38: Display input prompt with dimensions
    
    for (int i = 0; i < rows; i++) {                                     // Line 40: Loop through each row
        cout << "Row " << (i + 1) << ": ";                              // Line 41: Display current row number (1-based)
        for (int j = 0; j < cols; j++) {                                 // Line 42: Loop through each column in current row
            cin >> matrix[i][j];                                         // Line 43: Read element at position [i][j]
        }                                                                // Line 44: End of column loop
    }                                                                    // Line 45: End of row loop
}

// Function to display matrix in formatted output
// Parameters: matrix - 2D array to display, rows - number of rows, cols - number of columns
void displayMatrix(int matrix[][10], int rows, int cols) {               // Line 49: Function definition for matrix display
    for (int i = 0; i < rows; i++) {                                     // Line 50: Loop through each row
        cout << "[ ";                                                     // Line 51: Display opening bracket for row
        for (int j = 0; j < cols; j++) {                                 // Line 52: Loop through each column in current row
            cout << matrix[i][j];                                        // Line 53: Display element at position [i][j]
            if (j < cols - 1) cout << "\t";                              // Line 54: Add tab separator between elements (except last)
        }                                                                // Line 55: End of column loop
        cout << " ]" << endl;                                            // Line 56: Display closing bracket and new line
    }                                                                    // Line 57: End of row loop
}

// Function to add two matrices
// Purpose: Performs element-wise addition of two matrices
// Parameters: mat1, mat2 - input matrices, result - output matrix, rows, cols - dimensions
// Prerequisite: Both matrices must have same dimensions
void addMatrices(int mat1[][10], int mat2[][10], int result[][10], int rows, int cols) { // Line 64: Function definition for matrix addition
    cout << "\nPerforming matrix addition..." << endl;                   // Line 65: Display operation status
    
    for (int i = 0; i < rows; i++) {                                     // Line 67: Loop through each row
        for (int j = 0; j < cols; j++) {                                 // Line 68: Loop through each column
            result[i][j] = mat1[i][j] + mat2[i][j];                      // Line 69: Add corresponding elements from both matrices
        }                                                                // Line 70: End of column loop
    }                                                                    // Line 71: End of row loop
    
    cout << "Matrix addition completed successfully!" << endl;           // Line 73: Display completion message
}

// Function to multiply two matrices using dot product
// Parameters: mat1, mat2 - input matrices, result - output matrix
//            r1, c1 - dimensions of first matrix, r2, c2 - dimensions of second matrix
// Returns: true if multiplication possible, false otherwise
// Condition: Columns of first matrix must equal rows of second matrix
bool multiplyMatrices(int mat1[][10], int mat2[][10], int result[][10], int r1, int c1, int r2, int c2) { 
    // Check if multiplication is possible
    if (c1 != r2) {                                                      // Line 83: Check multiplication compatibility condition
        cout << "\nError: Matrix multiplication not possible!" << endl;   // Line 84: Display error message
        cout << "Columns of first matrix (" << c1 << ") must equal rows of second matrix (" << r2 << ")" << endl; // Line 85: Explain the condition
        return false;                                                    // Line 86: Return false indicating failure
    }                                                                    // Line 87: End of compatibility check
    
    cout << "\nPerforming matrix multiplication..." << endl;            // Line 89: Display operation status
    cout << "Result will be a " << r1 << "x" << c2 << " matrix" << endl; // Line 90: Display result matrix dimensions
    
    // Initialize result matrix to zero
    for (int i = 0; i < r1; i++) {                                      // Line 93: Loop through result matrix rows
        for (int j = 0; j < c2; j++) {                                  // Line 94: Loop through result matrix columns
            result[i][j] = 0;                                           // Line 95: Initialize each element to zero
        }                                                               // Line 96: End of column initialization loop
    }                                                                   // Line 97: End of row initialization loop
    
    // Perform multiplication using dot product
    for (int i = 0; i < r1; i++) {                                      // Line 100: Loop through rows of first matrix
        for (int j = 0; j < c2; j++) {                                  // Line 101: Loop through columns of second matrix
            for (int k = 0; k < c1; k++) {                              // Line 102: Loop for dot product calculation
                result[i][j] += mat1[i][k] * mat2[k][j];                // Line 103: Accumulate dot product (sum of products)
            }                                                           // Line 104: End of dot product loop
        }                                                               // Line 105: End of second matrix column loop
    }                                                                   // Line 106: End of first matrix row loop
    
    cout << "Matrix multiplication completed successfully!" << endl;     // Line 108: Display completion message
    return true;                                                        // Line 109: Return true indicating success
}

// Function to transpose a matrix (convert rows to columns)
// Parameters: matrix - input matrix, result - transposed matrix, rows, cols - original dimensions
// Result: rows and columns are swapped in the transposed matrix
void transposeMatrix(int matrix[][10], int result[][10], int rows, int cols) { // Line 115: Function definition for matrix transpose
    cout << "\nPerforming matrix transpose..." << endl;                  // Line 116: Display operation status
    cout << "Original: " << rows << "x" << cols << " -> Transposed: " << cols << "x" << rows << endl; // Line 117: Display dimension change
    
    // Swap rows and columns: result[j][i] = matrix[i][j]
    for (int i = 0; i < rows; i++) {                                     // Line 120: Loop through original matrix rows
        for (int j = 0; j < cols; j++) {                                 // Line 121: Loop through original matrix columns
            result[j][i] = matrix[i][j];                                 // Line 122: Swap row and column indices
        }                                                                // Line 123: End of column loop
    }                                                                    // Line 124: End of row loop
}

// Main function - Menu-driven matrix operations program
int main() {                                                             // Line 128: Main function definition
    int choice;                                                          // Line 129: Variable to store user menu choice
    int mat1[10][10], mat2[10][10], result[10][10];                     // Line 130: Declare matrices with maximum size 10x10
    int r1, c1, r2, c2;                                                 // Line 131: Variables for matrix dimensions
    
    cout << "=== MATRIX OPERATIONS PROGRAM ===" << endl;               // Line 133: Display program header
    cout << "This program performs basic matrix operations on 2D arrays." << endl; // Line 134: Display program description
    cout << "Maximum supported matrix size: 10x10" << endl;             // Line 135: Display size limitation
    
    // Main program loop
    while (true) {                                                       // Line 138: Start infinite loop for menu
        cout << "\n--- Matrix Operations Menu ---" << endl;              // Line 139: Display menu header
        cout << "1. Matrix Addition (A + B)" << endl;                   // Line 140: Display option 1
        cout << "2. Matrix Multiplication (A × B)" << endl;              // Line 141: Display option 2
        cout << "3. Matrix Transpose (A^T)" << endl;                     // Line 142: Display option 3
        cout << "4. Exit Program" << endl;                               // Line 143: Display exit option
        cout << "Enter your choice (1-4): ";                            // Line 144: Prompt for user choice
        cin >> choice;                                                   // Line 145: Read user choice
        
        switch (choice) {                                                // Line 147: Start switch statement for menu handling
            case 1: // Matrix Addition
                cout << "\n=== MATRIX ADDITION ===" << endl;               // Line 149: Display addition operation header
                cout << "Enter dimensions of first matrix (rows cols): ";   // Line 150: Prompt for first matrix dimensions
                cin >> r1 >> c1;                                            // Line 151: Read first matrix dimensions
                cout << "Enter dimensions of second matrix (rows cols): ";  // Line 152: Prompt for second matrix dimensions
                cin >> r2 >> c2;                                            // Line 153: Read second matrix dimensions
                
                // Check if addition is possible
                if (r1 != r2 || c1 != c2) {                                 // Line 156: Check if matrices have same dimensions
                    cout << "Error: Matrices must have same dimensions for addition!" << endl; // Line 157: Display error message
                    cout << "First matrix: " << r1 << "x" << c1 << ", Second matrix: " << r2 << "x" << c2 << endl; // Line 158: Show dimension mismatch
                    break;                                                   // Line 159: Exit case if dimensions don't match
                }                                                            // Line 160: End of dimension check
                
                cout << "\nFirst matrix (" << r1 << "x" << c1 << "):" << endl; // Line 162: Prompt for first matrix input
                inputMatrix(mat1, r1, c1);                                  // Line 163: Read first matrix elements
                cout << "\nSecond matrix (" << r2 << "x" << c2 << "):" << endl; // Line 164: Prompt for second matrix input
                inputMatrix(mat2, r2, c2);                                  // Line 165: Read second matrix elements
                
                cout << "\nMatrix A:" << endl;                            // Line 167: Label for first matrix display
                displayMatrix(mat1, r1, c1);                                // Line 168: Display first matrix
                cout << "\nMatrix B:" << endl;                            // Line 169: Label for second matrix display
                displayMatrix(mat2, r2, c2);                                // Line 170: Display second matrix
                
                addMatrices(mat1, mat2, result, r1, c1);                    // Line 172: Call matrix addition function
                cout << "\nResult (A + B):" << endl;                       // Line 173: Label for result display
                displayMatrix(result, r1, c1);                              // Line 174: Display addition result
                break;                                                       // Line 175: Exit case 1
                
            case 2: // Matrix Multiplication
                cout << "\n=== MATRIX MULTIPLICATION ===" << endl;         // Line 177: Display multiplication operation header
                cout << "Note: Columns of first matrix must equal rows of second matrix" << endl; // Line 178: Display multiplication rule
                cout << "Enter dimensions of first matrix (rows cols): ";   // Line 179: Prompt for first matrix dimensions
                cin >> r1 >> c1;                                            // Line 180: Read first matrix dimensions
                cout << "Enter dimensions of second matrix (rows cols): ";  // Line 181: Prompt for second matrix dimensions
                cin >> r2 >> c2;                                            // Line 182: Read second matrix dimensions
                
                cout << "\nFirst matrix (" << r1 << "x" << c1 << "):" << endl; // Line 184: Prompt for first matrix input
                inputMatrix(mat1, r1, c1);                                  // Line 185: Read first matrix elements
                cout << "\nSecond matrix (" << r2 << "x" << c2 << "):" << endl; // Line 186: Prompt for second matrix input
                inputMatrix(mat2, r2, c2);                                  // Line 187: Read second matrix elements
                
                cout << "\nMatrix A (" << r1 << "x" << c1 << "):" << endl; // Line 189: Label for first matrix display
                displayMatrix(mat1, r1, c1);                                // Line 190: Display first matrix
                cout << "\nMatrix B (" << r2 << "x" << c2 << "):" << endl; // Line 191: Label for second matrix display
                displayMatrix(mat2, r2, c2);                                // Line 192: Display second matrix
                
                if (multiplyMatrices(mat1, mat2, result, r1, c1, r2, c2)) { // Line 194: Call multiplication function and check success
                    cout << "\nResult (A × B):" << endl;                    // Line 195: Label for result display
                    displayMatrix(result, r1, c2);                          // Line 196: Display multiplication result
                }                                                            // Line 197: End of successful multiplication
                break;                                                       // Line 198: Exit case 2
                
            case 3: // Matrix Transpose
                cout << "\n=== MATRIX TRANSPOSE ===" << endl;              // Line 200: Display transpose operation header
                cout << "Enter dimensions of matrix (rows cols): ";          // Line 201: Prompt for matrix dimensions
                cin >> r1 >> c1;                                            // Line 202: Read matrix dimensions
                cout << "\nEnter matrix (" << r1 << "x" << c1 << "):" << endl; // Line 203: Prompt for matrix input
                inputMatrix(mat1, r1, c1);                                  // Line 204: Read matrix elements
                
                cout << "\nOriginal Matrix A:" << endl;                   // Line 206: Label for original matrix display
                displayMatrix(mat1, r1, c1);                                // Line 207: Display original matrix
                
                transposeMatrix(mat1, result, r1, c1);                      // Line 209: Call transpose function
                cout << "\nTranspose of Matrix A (A^T):" << endl;          // Line 210: Label for transpose result
                displayMatrix(result, c1, r1);                              // Line 211: Display transpose result (dimensions swapped)
                break;                                                       // Line 212: Exit case 3
                
            case 4: // Exit Program
                cout << "\nThank you for using the Matrix Operations Program!" << endl; // Line 215: Display exit message
                return 0;                                                    // Line 216: Return 0 and exit program
                
            default: // Invalid choice
                cout << "Invalid choice! Please enter a number between 1 and 4." << endl; // Line 219: Display error for invalid choice
        }                                                                    // Line 220: End of switch statement
    }                                                                        // Line 221: End of while loop
    
    return 0;                                                                // Line 223: Return 0 to indicate successful execution
}
