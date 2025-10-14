/*
 * PRACTICAL 3: ALPHABET FREQUENCY COUNTER
 * ======================================
 * 
 * PURPOSE: Count the frequency of each alphabet character from command line arguments
 *          and display the results in a tabular format.
 * 
 * ALGORITHM:
 * 1. Check if command line arguments are provided
 * 2. Initialize an array to count occurrences of each alphabet (A-Z)
 * 3. Process each command line argument character by character:
 *    - Convert to uppercase for uniform counting
 *    - Increment count for valid alphabetic characters
 * 4. Display results in tabular format (only non-zero counts)
 * 
 * KEY CONCEPTS DEMONSTRATED:
 * - Command line argument processing (argc, argv)
 * - Character manipulation and ASCII values
 * - Array indexing using character arithmetic
 * - Case-insensitive character processing
 * - Frequency counting algorithm
 * - Formatted output display
 * 
 * INPUT: Text strings as command line arguments
 * OUTPUT: Frequency table of alphabetic characters
 * 
 * USAGE: program.exe "Hello World" "Programming"
 * 
 * CHARACTER MAPPING: 'A'/'a' → index 0, 'B'/'b' → index 1, ..., 'Z'/'z' → index 25
 */

#include <iostream>                       // Include input/output stream library for cout, cin
using namespace std;                    // Use standard namespace to avoid writing std:: prefix

int main(int argc, char* argv[]) {                                        // Main function with command line arguments
    // Array to store count of each alphabet (A-Z), initialized to 0
    int count[26] = {0};                                                  // Array for 26 letters, all initialized to 0
    
    // Check if command line arguments are provided
    if (argc < 2) {                                                       // Check if at least one argument provided
        cout << "Usage: " << argv[0] << " <text1> <text2> ..." << endl;    // Display usage instructions
        cout << "Please provide text as command line arguments." << endl;   // Display error message
        cout << "Example: " << argv[0] << " \"Hello World\" \"Programming\"" << endl; // Show example usage
        return 1;                                                         // Return error code 1
    }                                                                     // End of error check
    
    cout << "Processing command line arguments:" << endl;                 // Display processing header
    
    // Process each command line argument (starting from index 1)
    for (int i = 1; i < argc; i++) {                                     // Loop through command line arguments
        char* str = argv[i];                                              // Get current argument string
        cout << "Argument " << i << ": \"" << str << "\"" << endl;          // Display current argument being processed
        
        int j = 0;                                                        // Initialize character index
        // Process each character in the current string
        while (str[j] != '\0') {                                          // Loop until null terminator
            char ch = str[j];                                             // Get current character
            
            // Check for lowercase letters (a-z)
            if (ch >= 'a' && ch <= 'z') {                                 // Check if lowercase letter
                count[ch - 'a']++;                                        // Increment count for this letter (map 'a'→0, 'b'→1, etc.)
            }                                                             // End of lowercase check
            // Check for uppercase letters (A-Z)
            else if (ch >= 'A' && ch <= 'Z') {                            // Check if uppercase letter
                count[ch - 'A']++;                                        // Increment count for this letter (map 'A'→0, 'B'→1, etc.)
            }                                                             // End of uppercase check
            // Ignore non-alphabetic characters (spaces, numbers, symbols)
            
            j++;                                                          // Move to next character
        }                                                                 // End of character processing loop
    }                                                                     // End of argument processing loop
    
    // Display results in tabular format
    cout << "\n=== ALPHABET FREQUENCY TABLE ===" << endl;                 // Display table header
    cout << "Alphabet\tOccurrences" << endl;                             // Display column headers
    cout << "--------\t-----------" << endl;                             // Display separator line
    
    bool foundAny = false;                                                // Flag to track if any letters found
    for (int i = 0; i < 26; i++) {                                       // Loop through all 26 letters
        if (count[i] > 0) {                                               // Check if letter has non-zero count
            // Convert index back to character: 0→'A', 1→'B', ..., 25→'Z'
            cout << (char)('A' + i) << "\t\t" << count[i] << endl;         // Display letter and its count
            foundAny = true;                                              // Set flag indicating letters were found
        }                                                                 // End of count check
    }                                                                     // End of display loop
    
    if (!foundAny) {                                                      // Check if no letters were found
        cout << "No alphabetic characters found in the input." << endl;   // Display no letters message
    }                                                                     // End of no letters check
    
    return 0;                                                             // Return 0 to indicate successful execution
}
