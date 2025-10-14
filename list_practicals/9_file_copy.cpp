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

int main() {                                                             // Main function definition
    string sourceFile, destFile;                                        // Variables to store file names
    
    cout << "=== FILE COPY PROGRAM ===" << endl;                        // Display program header
    cout << "This program copies content from source file to destination file" << endl; // Display program description
    cout << "while removing all whitespace characters (spaces, tabs, newlines)." << endl; // Explain whitespace removal feature
    
    // Get source and destination file names
    cout << "\nEnter source file name (with extension): ";               // Prompt for source file name
    cin >> sourceFile;                                                  // Read source file name
    cout << "Enter destination file name (with extension): ";            // Prompt for destination file name
    cin >> destFile;                                                    // Read destination file name
    
    // Open source file for reading
    ifstream source(sourceFile);                                        // Create input file stream object for source file
    if (!source.is_open()) {                                            // Check if source file opened successfully
        cout << "\nError: Could not open source file '" << sourceFile << "'" << endl; // Display error message
        cout << "Please check if the file exists and you have read permissions." << endl; // Display troubleshooting tip
        return 1;                                                        // Return error code 1
    }                                                                    // End of source file check
    
    // Open destination file for writing
    ofstream destination(destFile);                                      // Create output file stream object for destination file
    if (!destination.is_open()) {                                       // Check if destination file opened successfully
        cout << "\nError: Could not create/open destination file '" << destFile << "'" << endl; // Display error message
        cout << "Please check if you have write permissions in the directory." << endl; // Display troubleshooting tip
        source.close();                                                  // Close source file before exiting
        return 1;                                                        // Return error code 1
    }                                                                    // End of destination file check
    
    cout << "\nFiles opened successfully!" << endl;                     // Display success message
    cout << "Copying content from '" << sourceFile << "' to '" << destFile << "'..." << endl; // Display operation status
    cout << "Removing whitespace characters during copy process." << endl; // Display processing note
    
    char ch;                                                             // Variable to store each character read
    int totalChars = 0, copiedChars = 0, removedChars = 0;              // Counters for statistics
    
    // Read character by character from source file
    while (source.get(ch)) {                                            // Loop to read each character from source file
        totalChars++;                                                    // Increment total character count
        
        // Check if character is whitespace (space, tab, newline, etc.)
        if (ch != ' ' && ch != '\t' && ch != '\n' && ch != '\r') {       // Check if character is not whitespace
            destination.put(ch);                                         // Write non-whitespace character to destination file
            copiedChars++;                                               // Increment copied character count
        } else {                                                         // Character is whitespace
            removedChars++;                                              // Increment removed character count
        }                                                                // End of whitespace check
    }                                                                    // End of character reading loop
    
    // Close both files
    source.close();                                                      // Close source file
    destination.close();                                                 // Close destination file
    
    // Display operation summary
    cout << "\n=== FILE COPY COMPLETED ===" << endl;                    // Display completion header
    cout << "Source file: " << sourceFile << endl;                      // Display source file name
    cout << "Destination file: " << destFile << endl;                   // Display destination file name
    cout << "Total characters read: " << totalChars << endl;             // Display total character count
    cout << "Characters copied: " << copiedChars << endl;                // Display copied character count
    cout << "Whitespace characters removed: " << removedChars << endl;   // Display removed character count
    cout << "Copy operation completed successfully!" << endl;            // Display success message
    
    return 0;                                                            // Return 0 to indicate successful execution
}
