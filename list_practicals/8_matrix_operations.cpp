/*
 * PRACTICAL 8: MATRIX OPERATIONS
 * =============================
 *
 * PURPOSE: Implement fundamental matrix operations including addition, multiplication,
 *          and transpose using 2D arrays with a menu-driven interface.
 *
 * IMPLEMENTATION NOTES:
 * - No headers are included. Minimal C runtime prototypes are forward-declared
 *   and used for console I/O.
 */

extern "C" int printf(const char*, ...);
extern "C" int scanf(const char*, ...);

// Function to input matrix elements from user
// Purpose: Reads matrix elements row by row from user input
// Parameters: matrix - 2D array to store elements, rows - number of rows, cols - number of columns
void inputMatrix(int matrix[10][10], int rows, int cols) {               // Function definition for matrix input
    printf("Enter matrix elements (%dx%d):\n", rows, cols);
    
    for (int i = 0; i < rows; i++) {                                     // Loop through each row
        printf("Row %d: ", (i + 1));
        for (int j = 0; j < cols; j++) {                                 // Loop through each column in current row
            if (scanf("%d", &matrix[i][j]) != 1) { printf("Invalid input.\n"); return; }
        }                                                                // End of column loop
    }                                                                    // End of row loop
}

// Function to display matrix in formatted output
// Parameters: matrix - 2D array to display, rows - number of rows, cols - number of columns
void displayMatrix(int matrix[][10], int rows, int cols) {               // Function definition for matrix display
    for (int i = 0; i < rows; i++) {                                     // Loop through each row
        printf("[ ");                                                     // Display opening bracket for row
        for (int j = 0; j < cols; j++) {                                 // Loop through each column in current row
            printf("%d", matrix[i][j]);                                  // Display element at position [i][j]
            if (j < cols - 1) printf("\t");                             // Add tab separator between elements (except last)
        }                                                                // End of column loop
        printf(" ]\n");                                                  // Display closing bracket and new line
    }                                                                    // End of row loop
}

// Function to add two matrices
// Purpose: Performs element-wise addition of two matrices
// Parameters: mat1, mat2 - input matrices, result - output matrix, rows, cols - dimensions
// Prerequisite: Both matrices must have same dimensions
void addMatrices(int mat1[][10], int mat2[][10], int result[][10], int rows, int cols) { // Function definition for matrix addition
    printf("\nPerforming matrix addition...\n");
    
    for (int i = 0; i < rows; i++) {                                     // Loop through each row
        for (int j = 0; j < cols; j++) {                                 // Loop through each column
            result[i][j] = mat1[i][j] + mat2[i][j];                      // Add corresponding elements from both matrices
        }                                                                // End of column loop
    }                                                                    // End of row loop
    
    printf("Matrix addition completed successfully!\n");
}

// Function to multiply two matrices using dot product
// Parameters: mat1, mat2 - input matrices, result - output matrix
//            r1, c1 - dimensions of first matrix, r2, c2 - dimensions of second matrix
// Returns: true if multiplication possible, false otherwise
// Condition: Columns of first matrix must equal rows of second matrix
bool multiplyMatrices(int mat1[][10], int mat2[][10], int result[][10], int r1, int c1, int r2, int c2) { 
    // Check if multiplication is possible
    if (c1 != r2) {
        printf("\nError: Matrix multiplication not possible!\n");
        printf("Columns of first matrix (%d) must equal rows of second matrix (%d)\n", c1, r2);
        return false;
    }
    
    printf("\nPerforming matrix multiplication...\n");
    printf("Result will be a %dx%d matrix\n", r1, c2);
    
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
    
    printf("Matrix multiplication completed successfully!\n");
    return true;
}

// Function to transpose a matrix (convert rows to columns)
// Parameters: matrix - input matrix, result - transposed matrix, rows, cols - original dimensions
// Result: rows and columns are swapped in the transposed matrix
void transposeMatrix(int matrix[][10], int result[][10], int rows, int cols) { // Function definition for matrix transpose
    printf("\nPerforming matrix transpose...\n");
    printf("Original: %dx%d -> Transposed: %dx%d\n", rows, cols, cols, rows);
    
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
    
    printf("=== MATRIX OPERATIONS PROGRAM ===\n");
    printf("This program performs basic matrix operations on 2D arrays.\n");
    printf("Maximum supported matrix size: 10x10\n");
    
    // Main program loop
    while (true) {                                                       // Start infinite loop for menu
        printf("\n--- Matrix Operations Menu ---\n");
        printf("1. Matrix Addition (A + B)\n");
        printf("2. Matrix Multiplication (A × B)\n");
        printf("3. Matrix Transpose (A^T)\n");
        printf("4. Exit Program\n");
        printf("Enter your choice (1-4): ");
        if (scanf("%d", &choice) != 1) { printf("Invalid input.\n"); return 1; }
        
        switch (choice) {                                                // Start switch statement for menu handling
            case 1: // Matrix Addition
                printf("\n=== MATRIX ADDITION ===\n");
                printf("Enter dimensions of first matrix (rows cols): ");
                if (scanf("%d %d", &r1, &c1) != 2) { printf("Invalid input.\n"); return 1; }
                printf("Enter dimensions of second matrix (rows cols): ");
                if (scanf("%d %d", &r2, &c2) != 2) { printf("Invalid input.\n"); return 1; }
                
                if (r1 != r2 || c1 != c2) {                              // Check if matrices have same dimensions
                    printf("Error: Matrices must have same dimensions for addition!\n");
                    printf("First matrix: %dx%d, Second matrix: %dx%d\n", r1, c1, r2, c2);
                    break;
                }
                
                printf("\nFirst matrix (%dx%d):\n", r1, c1);
                inputMatrix(mat1, r1, c1);
                printf("\nSecond matrix (%dx%d):\n", r2, c2);
                inputMatrix(mat2, r2, c2);
                
                printf("\nMatrix A:\n");
                displayMatrix(mat1, r1, c1);
                printf("\nMatrix B:\n");
                displayMatrix(mat2, r2, c2);
                
                addMatrices(mat1, mat2, result, r1, c1);
                printf("\nResult (A + B):\n");
                displayMatrix(result, r1, c1);
                break;
                
            case 2: // Matrix Multiplication
                printf("\n=== MATRIX MULTIPLICATION ===\n");
                printf("Note: Columns of first matrix must equal rows of second matrix\n");
                printf("Enter dimensions of first matrix (rows cols): ");
                if (scanf("%d %d", &r1, &c1) != 2) { printf("Invalid input.\n"); return 1; }
                printf("Enter dimensions of second matrix (rows cols): ");
                if (scanf("%d %d", &r2, &c2) != 2) { printf("Invalid input.\n"); return 1; }
                
                printf("\nFirst matrix (%dx%d):\n", r1, c1);
                inputMatrix(mat1, r1, c1);
                printf("\nSecond matrix (%dx%d):\n", r2, c2);
                inputMatrix(mat2, r2, c2);
                
                printf("\nMatrix A (%dx%d):\n", r1, c1);
                displayMatrix(mat1, r1, c1);
                printf("\nMatrix B (%dx%d):\n", r2, c2);
                displayMatrix(mat2, r2, c2);
                
                if (multiplyMatrices(mat1, mat2, result, r1, c1, r2, c2)) {
                    printf("\nResult (A × B):\n");
                    displayMatrix(result, r1, c2);
                }
                break;
                
            case 3: // Matrix Transpose
                printf("\n=== MATRIX TRANSPOSE ===\n");
                printf("Enter dimensions of matrix (rows cols): ");
                if (scanf("%d %d", &r1, &c1) != 2) { printf("Invalid input.\n"); return 1; }
                printf("\nEnter matrix (%dx%d):\n", r1, c1);
                inputMatrix(mat1, r1, c1);
                
                printf("\nOriginal Matrix A:\n");
                displayMatrix(mat1, r1, c1);
                
                transposeMatrix(mat1, result, r1, c1);
                printf("\nTranspose of Matrix A (A^T):\n");
                displayMatrix(result, c1, r1);
                break;
                
            case 4: // Exit Program
                printf("\nThank you for using the Matrix Operations Program!\n");
                return 0;
                
            default: // Invalid choice
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    }
    
    return 0;                                                             // Return 0 to indicate successful execution
}
