/*
 * PRACTICAL 4: COMPREHENSIVE STRING MANIPULATION MENU
 * ==================================================
 * 
 * PURPOSE: Demonstrate various string operations through a menu-driven program
 *          including address display, concatenation, comparison, length calculation,
 *          case conversion, reversal, and string insertion.
 * 
 * FEATURES:
 * 1. Show memory addresses of each character in a string
 * 2. Concatenate two strings without using library functions
 * 3. Compare two strings lexicographically
 * 4. Calculate string length using pointer arithmetic
 * 5. Convert lowercase to uppercase
 * 6. Reverse a string in-place
 * 7. Insert one string into another at specified position
 * 
 * KEY CONCEPTS DEMONSTRATED:
 * - Menu-driven programming with switch-case
 * - String manipulation without library functions
 * - Pointer arithmetic and memory addresses
 * - Character array operations
 * - Manual implementation of string functions
 * - Input buffer management with cin.ignore()
 * 
 * INPUT: User choice and corresponding string inputs
 * OUTPUT: Results of various string operations
 */

#include <iostream>                       // Include input/output stream library for cout, cin
using namespace std;                    // Use standard namespace to avoid writing std:: prefix

// Function to display memory address of each character in a string
// Purpose: Demonstrates how strings are stored in memory as character arrays
// Parameter: str - pointer to the string whose addresses are to be displayed
void showAddresses(char* str) {                                          // Function definition with char pointer parameter
    cout << "\n=== CHARACTER MEMORY ADDRESSES ===" << endl;             // Display function header
    cout << "Index\tChar\tAddress" << endl;                             // Display column headers
    cout << "-----\t----\t-------" << endl;                             // Display separator line
    
    for (int i = 0; str[i] != '\0'; i++) {                               // Loop through each character until null terminator
        cout << i << "\t'" << str[i] << "'\t" << (void*)&str[i] << endl;  // Display index, character, and memory address
    }                                                                     // End of for loop
    cout << "Note: Addresses are consecutive, showing contiguous memory storage." << endl; // Educational note about memory layout
}

// Function to concatenate two strings manually (without strcat)
// Purpose: Combines two strings into one result string
// Parameters: str1 - first string, str2 - second string, result - output string
void concatenateStrings(char* str1, char* str2, char* result) {          // Function definition with three char pointers
    int i = 0, j = 0;                                                    // Initialize indices for source and destination
    
    // Copy first string to result
    while (str1[i] != '\0') {                                             // Loop through first string until null terminator
        result[j++] = str1[i++];                                          // Copy character and increment both indices
    }                                                                     // End of first string copy loop
    
    // Copy second string to result (starting where first ended)
    i = 0;                                                                // Reset source index for second string
    while (str2[i] != '\0') {                                             // Loop through second string until null terminator
        result[j++] = str2[i++];                                          // Copy character and increment both indices
    }                                                                     // End of second string copy loop
    
    result[j] = '\0';                                                     // Add null terminator to complete the string
}

// Function to compare two strings lexicographically (without strcmp)
// Purpose: Compares strings character by character using ASCII values
// Parameters: str1, str2 - strings to compare
// Returns: -1 if str1 < str2, 0 if equal, 1 if str1 > str2
int compareStrings(char* str1, char* str2) {                             // Function definition returning int
    int i = 0;                                                            // Initialize character index
    
    // Compare characters until difference found or end reached
    while (str1[i] != '\0' && str2[i] != '\0') {                         // Loop while both strings have characters
        if (str1[i] < str2[i]) return -1;                                // Return -1 if str1 character is smaller
        if (str1[i] > str2[i]) return 1;                                 // Return 1 if str1 character is larger
        i++;                                                              // Move to next character
    }                                                                     // End of comparison loop
    
    // Handle cases where strings have different lengths
    if (str1[i] == '\0' && str2[i] == '\0') return 0;                    // Return 0 if both strings ended (equal)
    return (str1[i] == '\0') ? -1 : 1;                                   // Return -1 if str1 shorter, 1 if str2 shorter
}

// Function to calculate string length using pointer arithmetic (without strlen)
// Purpose: Demonstrates pointer arithmetic to find string length
// Parameter: str - string whose length is to be calculated
// Returns: length of the string (number of characters before null terminator)
int calculateLength(char* str) {                                         // Function definition returning int
    char* ptr = str;                                                      // Initialize pointer to start of string
    
    // Move pointer until null terminator is found
    while (*ptr != '\0') {                                                // Loop until null terminator found
        ptr++;                                                            // Increment pointer to next character
    }                                                                     // End of length counting loop
    
    // Return difference between end and start pointers
    return ptr - str;                                                     // Pointer arithmetic gives length
}

// Function to convert lowercase letters to uppercase (without toupper)
// Purpose: Converts all lowercase letters in string to uppercase
// Parameter: str - string to be converted (modified in-place)
// Note: Uses ASCII value difference between 'a' and 'A' (32)
void toUppercase(char* str) {                                            // 106: Function definition with char pointer
    for (int i = 0; str[i] != '\0'; i++) {                               // 107: Loop through each character
        // Check if character is lowercase letter
        if (str[i] >= 'a' && str[i] <= 'z') {                            // 109: Check if character is lowercase
            str[i] = str[i] - 32;                                         // 110: Convert to uppercase (subtract ASCII difference)
        }                                                                 // 111: End of lowercase check
        // Non-lowercase characters remain unchanged
    }                                                                     // 113: End of conversion loop
}

// Function to reverse a string in-place (without strrev)
// Purpose: Reverses the order of characters in the string
// Parameter: str - string to be reversed (modified in-place)
// Algorithm: Swap characters from both ends moving towards center
void reverseString(char* str) {                                          // 120: Function definition with char pointer
    int len = calculateLength(str);                                       // 121: Get string length using our custom function
    
    // Swap characters from start and end, moving towards center
    for (int i = 0; i < len / 2; i++) {                                  // 124: Loop from start to middle of string
        char temp = str[i];                                               // 125: Store character from start in temporary variable
        str[i] = str[len - 1 - i];                                       // 126: Move character from end to start position
        str[len - 1 - i] = temp;                                         // 127: Move stored character to end position
    }                                                                     // 128: End of swapping loop
}

// Function to insert one string into another at specified position
// Purpose: Inserts insertStr into mainStr at given position
// Parameters: mainStr - original string, insertStr - string to insert,
//            pos - insertion position, result - output string
void insertString(char* mainStr, char* insertStr, int pos, char* result) {
    int i = 0, j = 0, k = 0;
    
    // Step 1: Copy characters before insertion position
    while (i < pos && mainStr[i] != '\0') {
        result[k++] = mainStr[i++];
    }
    
    // Step 2: Insert the new string at specified position
    while (insertStr[j] != '\0') {
        result[k++] = insertStr[j++];
    }
    
    // Step 3: Copy remaining characters from original string
    while (mainStr[i] != '\0') {
        result[k++] = mainStr[i++];
    }
    
    result[k] = '\0';  // Add null terminator
}

// Main function - Menu-driven program for string operations
int main() {                                                             // 131: Main function definition
    int choice;                                                           // 132: Variable to store user menu choice
    char str1[100], str2[100], result[200];                              // 133: Character arrays for string storage
    
    do {                                                                  // 135: Start of menu loop
        // Display menu options
        cout << "\n=== STRING MANIPULATION MENU ===" << endl;             // 137: Display menu header
        cout << "1. Show Memory Addresses of Characters" << endl;          // 138: Display option 1
        cout << "2. Concatenate Two Strings" << endl;                     // 139: Display option 2
        cout << "3. Compare Two Strings" << endl;                         // 140: Display option 3
        cout << "4. Calculate String Length" << endl;                     // 141: Display option 4
        cout << "5. Convert to Uppercase" << endl;                        // 142: Display option 5
        cout << "6. Reverse String" << endl;                              // 143: Display option 6
        cout << "0. Exit" << endl;                                        // 144: Display exit option
        cout << "\nEnter your choice: ";                                  // 145: Prompt for user input
        cin >> choice;                                                    // 146: Read user choice
        cin.ignore();                                                     // 147: Clear input buffer after reading integer
        
        switch (choice) {                                                 // 149: Start switch statement for menu handling
            case 1: {                                                     // 150: Handle option 1 - show addresses
                cout << "\nEnter a string: ";                             // 151: Prompt for string input
                cin.getline(str1, 100);                                  // 152: Read string with spaces
                showAddresses(str1);                                      // 153: Call function to display addresses
                break;                                                    // 154: Exit case 1
            }                                                             // 155: End of case 1
            
            case 2: {                                                     // 157: Handle option 2 - concatenation
                cout << "\nEnter first string: ";                         // 158: Prompt for first string
                cin.getline(str1, 100);                                  // 159: Read first string
                cout << "Enter second string: ";                          // 160: Prompt for second string
                cin.getline(str2, 100);                                  // 161: Read second string
                
                concatenateStrings(str1, str2, result);                  // 163: Call concatenation function
                cout << "\nConcatenated string: \"" << result << "\"" << endl; // 164: Display result
                cout << "First string: \"" << str1 << "\"" << endl;        // 165: Display original first string
                cout << "Second string: \"" << str2 << "\"" << endl;       // 166: Display original second string
                break;                                                    // 167: Exit case 2
            }                                                             // 168: End of case 2
            
            case 3: {                                                     // 170: Handle option 3 - comparison
                cout << "\nEnter first string: ";                         // 171: Prompt for first string
                cin.getline(str1, 100);                                  // 172: Read first string
                cout << "Enter second string: ";                          // 173: Prompt for second string
                cin.getline(str2, 100);                                  // 174: Read second string
                
                int comparison = compareStrings(str1, str2);             // 176: Call comparison function
                cout << "\nComparison result: ";                          // 177: Display result header
                if (comparison == 0) {                                    // 178: Check if strings are equal
                    cout << "Strings are equal" << endl;                  // 179: Display equal message
                } else if (comparison < 0) {                              // 180: Check if first string is smaller
                    cout << "First string is lexicographically smaller" << endl; // 181: Display smaller message
                } else {                                                  // 182: Else first string is larger
                    cout << "First string is lexicographically larger" << endl;  // 183: Display larger message
                }                                                         // 184: End of comparison result display
                break;                                                    // 185: Exit case 3
            }                                                             // 186: End of case 3
            
            case 4: {                                                     // 188: Handle option 4 - length calculation
                cout << "\nEnter a string: ";                             // 189: Prompt for string input
                cin.getline(str1, 100);                                  // 190: Read string
                
                int length = calculateLength(str1);                      // 192: Call length calculation function
                cout << "\nString: \"" << str1 << "\"" << endl;            // 193: Display original string
                cout << "Length: " << length << " characters" << endl;    // 194: Display calculated length
                break;                                                    // 195: Exit case 4
            }                                                             // 196: End of case 4
            
            case 5: {                                                     // 198: Handle option 5 - uppercase conversion
                cout << "\nEnter a string: ";                             // 199: Prompt for string input
                cin.getline(str1, 100);                                  // 200: Read string
                
                cout << "\nOriginal string: \"" << str1 << "\"" << endl;  // 202: Display original string
                toUppercase(str1);                                        // 203: Call uppercase conversion function
                cout << "Uppercase string: \"" << str1 << "\"" << endl;   // 204: Display converted string
                break;                                                    // 205: Exit case 5
            }                                                             // 206: End of case 5
            
            case 6: {                                                     // 208: Handle option 6 - string reversal
                cout << "\nEnter a string: ";                             // 209: Prompt for string input
                cin.getline(str1, 100);                                  // 210: Read string
                
                cout << "\nOriginal string: \"" << str1 << "\"" << endl;  // 212: Display original string
                reverseString(str1);                                      // 213: Call string reversal function
                cout << "Reversed string: \"" << str1 << "\"" << endl;    // 214: Display reversed string
                break;                                                    // 215: Exit case 6
            }                                                             // 216: End of case 6
            
            case 0:                                                       // 218: Handle option 0 - exit
                cout << "\nExiting program. Thank you!" << endl;          // 219: Display exit message
                break;                                                    // 220: Exit case 0
                
            default:                                                      // 222: Handle invalid input
                cout << "\nInvalid choice! Please enter a number between 0-6." << endl; // 223: Display error message
                break;                                                    // 224: Exit default case
        }                                                                 // 225: End of switch statement
        
    } while (choice != 0);                                               // 227: Continue loop until user chooses exit
    
    return 0;                                                             // 229: Return 0 to indicate successful execution
}
