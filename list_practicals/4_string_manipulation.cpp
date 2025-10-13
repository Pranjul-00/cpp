#include <iostream>
using namespace std;

// Function to show address of each character
void showAddresses(char* str) {
    cout << "Character addresses:" << endl;
    for (int i = 0; str[i] != '\0'; i++) {
        cout << "str[" << i << "] = '" << str[i] << "' at address: " << (void*)&str[i] << endl;
    }
}

// Function to concatenate two strings
void concatenateStrings(char* str1, char* str2, char* result) {
    int i = 0, j = 0;
    while (str1[i] != '\0') {
        result[j++] = str1[i++];
    }
    i = 0;
    while (str2[i] != '\0') {
        result[j++] = str2[i++];
    }
    result[j] = '\0';
}

// Function to compare two strings
int compareStrings(char* str1, char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] < str2[i]) return -1;
        if (str1[i] > str2[i]) return 1;
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0') return 0;
    return (str1[i] == '\0') ? -1 : 1;
}

// Function to calculate length using pointers
int calculateLength(char* str) {
    char* ptr = str;
    while (*ptr != '\0') {
        ptr++;
    }
    return ptr - str;
}

// Function to convert lowercase to uppercase
void toUppercase(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
}

// Function to reverse string
void reverseString(char* str) {
    int len = calculateLength(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

// Function to insert string at position
void insertString(char* mainStr, char* insertStr, int pos, char* result) {
    int i = 0, j = 0, k = 0;
    
    // Copy characters before position
    while (i < pos && mainStr[i] != '\0') {
        result[k++] = mainStr[i++];
    }
    
    // Insert the string
    while (insertStr[j] != '\0') {
        result[k++] = insertStr[j++];
    }
    
    // Copy remaining characters
    while (mainStr[i] != '\0') {
        result[k++] = mainStr[i++];
    }
    result[k] = '\0';
}

int main() {
    char str1[100], str2[100], result[200];
    int choice, pos;
    
    while (true) {
        cout << "\n--- String Manipulation Menu ---" << endl;
        cout << "1. Show address of each character" << endl;
        cout << "2. Concatenate two strings" << endl;
        cout << "3. Compare two strings" << endl;
        cout << "4. Calculate length of string" << endl;
        cout << "5. Convert to uppercase" << endl;
        cout << "6. Reverse string" << endl;
        cout << "7. Insert string at position" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear input buffer
        
        switch (choice) {
            case 1:
                cout << "Enter string: ";
                cin.getline(str1, 100);
                showAddresses(str1);
                break;
                
            case 2:
                cout << "Enter first string: ";
                cin.getline(str1, 100);
                cout << "Enter second string: ";
                cin.getline(str2, 100);
                concatenateStrings(str1, str2, result);
                cout << "Concatenated string: " << result << endl;
                break;
                
            case 3:
                cout << "Enter first string: ";
                cin.getline(str1, 100);
                cout << "Enter second string: ";
                cin.getline(str2, 100);
                int cmp = compareStrings(str1, str2);
                if (cmp == 0) cout << "Strings are equal" << endl;
                else if (cmp < 0) cout << "First string is smaller" << endl;
                else cout << "First string is larger" << endl;
                break;
                
            case 4:
                cout << "Enter string: ";
                cin.getline(str1, 100);
                cout << "Length: " << calculateLength(str1) << endl;
                break;
                
            case 5:
                cout << "Enter string: ";
                cin.getline(str1, 100);
                toUppercase(str1);
                cout << "Uppercase string: " << str1 << endl;
                break;
                
            case 6:
                cout << "Enter string: ";
                cin.getline(str1, 100);
                reverseString(str1);
                cout << "Reversed string: " << str1 << endl;
                break;
                
            case 7:
                cout << "Enter main string: ";
                cin.getline(str1, 100);
                cout << "Enter string to insert: ";
                cin.getline(str2, 100);
                cout << "Enter position: ";
                cin >> pos;
                insertString(str1, str2, pos, result);
                cout << "Result: " << result << endl;
                break;
                
            case 8:
                return 0;
                
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    
    return 0;
}
