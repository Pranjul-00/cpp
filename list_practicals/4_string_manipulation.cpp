/*
 * PRACTICAL 4: COMPREHENSIVE STRING MANIPULATION MENU
 * ==================================================
 *
 * PURPOSE: Demonstrate various string operations through a menu-driven program
 *          including address display, concatenation, comparison, length calculation,
 *          case conversion, reversal, and string insertion.
 *
 * INPUT: User choice and corresponding string inputs
 * OUTPUT: Results of various string operations
 */

#include <iostream>
using namespace std;

// Function to display memory address of each character in a string
// Purpose: Demonstrates how strings are stored in memory as character arrays
// Parameter: str - pointer to the string whose addresses are to be displayed
void showAddresses(char* str) {                                          // Function definition with char pointer parameter
    cout << "\n=== CHARACTER MEMORY ADDRESSES ===" << endl;
    cout << "Index\tChar\tAddress" << endl;
    cout << "-----\t----\t-------" << endl;
    
    for (int i = 0; str[i] != '\0'; i++) {                               // Loop through each character until null terminator
        cout << i << "\t'" << str[i] << "'\t" << (void*)&str[i] << endl;
    }                                                                     // End of for loop
    cout << "Note: Addresses are consecutive, showing contiguous memory storage." << endl;
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
void toUppercase(char* str) {                                            // Function definition with char pointer
    for (int i = 0; str[i] != '\0'; i++) {                               // Loop through each character
        // Check if character is lowercase letter
        if (str[i] >= 'a' && str[i] <= 'z') {                            // Check if character is lowercase
            str[i] = str[i] - 32;                                         // Convert to uppercase (subtract ASCII difference)
        }                                                                 // End of lowercase check
        // Non-lowercase characters remain unchanged
    }                                                                     // End of conversion loop
}

// Function to reverse a string in-place (without strrev)
// Purpose: Reverses the order of characters in the string
// Parameter: str - string to be reversed (modified in-place)
// Algorithm: Swap characters from both ends moving towards center
void reverseString(char* str) {                                          // Function definition with char pointer
    int len = calculateLength(str);                                       // Get string length using our custom function
    
    // Swap characters from start and end, moving towards center
    for (int i = 0; i < len / 2; i++) {                                  // Loop from start to middle of string
        char temp = str[i];                                               // Store character from start in temporary variable
        str[i] = str[len - 1 - i];                                       // Move character from end to start position
        str[len - 1 - i] = temp;                                         // Move stored character to end position
    }                                                                     // End of swapping loop
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
int main() {                                                             // Main function definition
    int choice;                                                           // Variable to store user menu choice
    char str1[100], str2[100], result[200];                              // Character arrays for string storage
    
    do {                                                                  // Start of menu loop
        cout << "\n=== STRING MANIPULATION MENU ===" << endl;
        cout << "1. Show Memory Addresses of Characters" << endl;
        cout << "2. Concatenate Two Strings" << endl;
        cout << "3. Compare Two Strings" << endl;
        cout << "4. Calculate String Length" << endl;
        cout << "5. Convert to Uppercase" << endl;
        cout << "6. Reverse String" << endl;
        cout << "0. Exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore(10000, '\n');
        
        switch (choice) {                                                 // Start switch statement for menu handling
            case 1: {                                                     // Handle option 1 - show addresses
                cout << "\nEnter a string: ";
                cin.getline(str1, 100);
                showAddresses(str1);                                      // Call function to display addresses
                break;                                                    // Exit case 1
            }                                                             // End of case 1
            
            case 2: {                                                     // Handle option 2 - concatenation
                cout << "\nEnter first string: ";
                cin.getline(str1, 100);
                cout << "Enter second string: ";
                cin.getline(str2, 100);
                
                concatenateStrings(str1, str2, result);                  // Call concatenation function
                cout << "\nConcatenated string: \"" << result << "\"" << endl;
                cout << "First string: \"" << str1 << "\"" << endl;
                cout << "Second string: \"" << str2 << "\"" << endl;
                break;                                                    // Exit case 2
            }                                                             // End of case 2
            
            case 3: {                                                     // Handle option 3 - comparison
                cout << "\nEnter first string: ";
                cin.getline(str1, 100);
                cout << "Enter second string: ";
                cin.getline(str2, 100);
                
                int comparison = compareStrings(str1, str2);             // Call comparison function
                cout << "\nComparison result: ";
                if (comparison == 0) {
                    cout << "Strings are equal" << endl;
                } else if (comparison < 0) {
                    cout << "First string is lexicographically smaller" << endl;
                } else {
                    cout << "First string is lexicographically larger" << endl;
                }
                break;                                                    // Exit case 3
            }                                                             // End of case 3
            
            case 4: {                                                     // Handle option 4 - length calculation
                cout << "\nEnter a string: ";
                cin.getline(str1, 100);
                
                int length = calculateLength(str1);                      // Call length calculation function
                cout << "\nString: \"" << str1 << "\"" << endl;
                cout << "Length: " << length << " characters" << endl;
                break;                                                    // Exit case 4
            }                                                             // End of case 4
            
            case 5: {                                                     // Handle option 5 - uppercase conversion
                cout << "\nEnter a string: ";
                cin.getline(str1, 100);
                
                cout << "\nOriginal string: \"" << str1 << "\"" << endl;
                toUppercase(str1);                                        // Call uppercase conversion function
                cout << "Uppercase string: \"" << str1 << "\"" << endl;
                break;                                                    // Exit case 5
            }                                                             // End of case 5
            
            case 6: {                                                     // Handle option 6 - string reversal
                cout << "\nEnter a string: ";
                cin.getline(str1, 100);
                
                cout << "\nOriginal string: \"" << str1 << "\"" << endl;
                reverseString(str1);                                      // Call string reversal function
                cout << "Reversed string: \"" << str1 << "\"" << endl;
                break;                                                    // Exit case 6
            }                                                             // End of case 6
            
            case 0:                                                       // Handle option 0 - exit
                cout << "\nExiting program. Thank you!" << endl;
                break;                                                    // Exit case 0
                
            default:                                                      // Handle invalid input
                cout << "\nInvalid choice! Please enter a number between 0-6." << endl;
                break;                                                    // Exit default case
        }                                                                 // End of switch statement
        
    } while (choice != 0);                                               // Continue loop until user chooses exit
    
    return 0;                                                             // Return 0 to indicate successful execution
}
