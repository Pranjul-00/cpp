/*
 * PRACTICAL 9: FILE COPY WITH WHITESPACE REMOVAL
 * ==============================================
 * 
 * PURPOSE: Copy contents from one file to another while removing all whitespace
 *          characters (spaces, tabs, newlines, carriage returns) from the content.
 * 
 * ALGORITHM:
 * 1. Get source and destination file names from user
 * 2. Open source file for reading and destination file for writing
 * 3. Read file character by character
 * 4. Copy only non-whitespace characters to destination
 * 5. Close both files and report success/failure
 * 
 * KEY CONCEPTS DEMONSTRATED:
 * - File input/output operations using fstream
 * - Character-by-character file processing
 * - File stream error handling
 * - Conditional character filtering
 * - Resource management (file closing)
 * - ifstream and ofstream usage
 * 
 * INPUT: Source file name and destination file name
 * OUTPUT: Destination file with content copied (whitespaces removed)
 * 
 * FILE OPERATIONS:
 * - ifstream: Input file stream for reading
 * - ofstream: Output file stream for writing
 * - get(): Read single character from input stream
 * - put(): Write single character to output stream
 * 
 * WHITESPACE CHARACTERS REMOVED: space(' '), tab('\t'), newline('\n'), carriage return('\r')
 */

#include <iostream>                       // Include input/output stream library for cout, cin
#include <fstream>                        // Include file stream library for file operations
using namespace std;                    // Use standard namespace to avoid writing std:: prefix for file stream operations

int main() {                                                             //  Main function definition
    string sourceFile, destFile;                                        // 37: Variables to store file names
    
    cout << "=== FILE COPY PROGRAM ===" << endl;                        // 39: Display program header
    cout << "This program copies content from source file to destination file" << endl; // 40: Display program description
    cout << "while removing all whitespace characters (spaces, tabs, newlines)." << endl; // 41: Explain whitespace removal feature
    
    // Get source and destination file names
    cout << "\nEnter source file name (with extension): ";               // 44: Prompt for source file name
    cin >> sourceFile;                                                  // 45: Read source file name
    cout << "Enter destination file name (with extension): ";            // 46: Prompt for destination file name
    cin >> destFile;                                                    // 47: Read destination file name
    
    // Open source file for reading
    ifstream source(sourceFile);                                        // 50: Create input file stream object for source file
    if (!source.is_open()) {                                            // 51: Check if source file opened successfully
        cout << "\nError: Could not open source file '" << sourceFile << "'" << endl; // 52: Display error message
        cout << "Please check if the file exists and you have read permissions." << endl; // 53: Display troubleshooting tip
        return 1;                                                        // 54: Return error code 1
    }                                                                    // 55: End of source file check
    
    // Open destination file for writing
    ofstream destination(destFile);                                      // 58: Create output file stream object for destination file
    if (!destination.is_open()) {                                       // 59: Check if destination file opened successfully
        cout << "\nError: Could not create/open destination file '" << destFile << "'" << endl; // 60: Display error message
        cout << "Please check if you have write permissions in the directory." << endl; // 61: Display troubleshooting tip
        source.close();                                                  // 62: Close source file before exiting
        return 1;                                                        // 63: Return error code 1
    }                                                                    // 64: End of destination file check
    
    cout << "\nFiles opened successfully!" << endl;                     // 66: Display success message
    cout << "Copying content from '" << sourceFile << "' to '" << destFile << "'..." << endl; // 67: Display operation status
    cout << "Removing whitespace characters during copy process." << endl; // 68: Display processing note
    
    char ch;                                                             // 70: Variable to store each character read
    int totalChars = 0, copiedChars = 0, removedChars = 0;              // 71: Counters for statistics
    
    // Read character by character from source file
    while (source.get(ch)) {                                            // 74: Loop to read each character from source file
        totalChars++;                                                    // 75: Increment total character count
        
        // Check if character is whitespace (space, tab, newline, etc.)
        if (ch != ' ' && ch != '\t' && ch != '\n' && ch != '\r') {       // 78: Check if character is not whitespace
            destination.put(ch);                                         // 79: Write non-whitespace character to destination file
            copiedChars++;                                               // 80: Increment copied character count
        } else {                                                         // 81: Character is whitespace
            removedChars++;                                              // 82: Increment removed character count
        }                                                                // 83: End of whitespace check
    }                                                                    // 84: End of character reading loop
    
    // Close both files
    source.close();                                                      // 87: Close source file
    destination.close();                                                 // 88: Close destination file
    
    // Display operation summary
    cout << "\n=== FILE COPY COMPLETED ===" << endl;                    // 91: Display completion header
    cout << "Source file: " << sourceFile << endl;                      // 92: Display source file name
    cout << "Destination file: " << destFile << endl;                   // 93: Display destination file name
    cout << "Total characters read: " << totalChars << endl;             // 94: Display total character count
    cout << "Characters copied: " << copiedChars << endl;                // 95: Display copied character count
    cout << "Whitespace characters removed: " << removedChars << endl;   // 96: Display removed character count
    cout << "Copy operation completed successfully!" << endl;            // 97: Display success message
    
    return 0;                                                            // 99: Return 0 to indicate successful execution
}
