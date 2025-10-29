#include <iostream>
using namespace std;

void showAddresses(char* str) {
    cout << "\n=== CHARACTER MEMORY ADDRESSES ===" << endl;
    cout << "Index\tChar\tAddress" << endl;
    cout << "-----\t----\t-------" << endl;
    
    for (int i = 0; str[i] != '\0'; i++) {
        cout << i << "\t'" << str[i] << "'\t" << (void*)&str[i] << endl;
    }
    cout << "Note: Addresses are consecutive, showing contiguous memory storage." << endl;
}

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

int calculateLength(char* str) {
    char* ptr = str;
    
    while (*ptr != '\0') {
        ptr++;
    }
    
    return ptr - str;
}

void toUppercase(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
}

void reverseString(char* str) {
    int len = calculateLength(str);
    
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

void insertString(char* mainStr, char* insertStr, int pos, char* result) {
    int i = 0, j = 0, k = 0;
    
    while (i < pos && mainStr[i] != '\0') {
        result[k++] = mainStr[i++];
    }
    
    while (insertStr[j] != '\0') {
        result[k++] = insertStr[j++];
    }
    
    while (mainStr[i] != '\0') {
        result[k++] = mainStr[i++];
    }
    
    result[k] = '\0';
}

int main() {
    int choice;
    char str1[100], str2[100], result[200];
    
    do {
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
        
        switch (choice) {
            case 1: {
                cout << "\nEnter a string: ";
                cin.getline(str1, 100);
                showAddresses(str1);
                break;
            }
            
            case 2: {
                cout << "\nEnter first string: ";
                cin.getline(str1, 100);
                cout << "Enter second string: ";
                cin.getline(str2, 100);
                
                concatenateStrings(str1, str2, result);
                cout << "\nConcatenated string: \"" << result << "\"" << endl;
                cout << "First string: \"" << str1 << "\"" << endl;
                cout << "Second string: \"" << str2 << "\"" << endl;
                break;
            }
            
            case 3: {
                cout << "\nEnter first string: ";
                cin.getline(str1, 100);
                cout << "Enter second string: ";
                cin.getline(str2, 100);
                
                int comparison = compareStrings(str1, str2);
                cout << "\nComparison result: ";
                if (comparison == 0) {
                    cout << "Strings are equal" << endl;
                } else if (comparison < 0) {
                    cout << "First string is lexicographically smaller" << endl;
                } else {
                    cout << "First string is lexicographically larger" << endl;
                }
                break;
            }
            
            case 4: {
                cout << "\nEnter a string: ";
                cin.getline(str1, 100);
                
                int length = calculateLength(str1);
                cout << "\nString: \"" << str1 << "\"" << endl;
                cout << "Length: " << length << " characters" << endl;
                break;
            }
            
            case 5: {
                cout << "\nEnter a string: ";
                cin.getline(str1, 100);
                
                cout << "\nOriginal string: \"" << str1 << "\"" << endl;
                toUppercase(str1);
                cout << "Uppercase string: \"" << str1 << "\"" << endl;
                break;
            }
            
            case 6: {
                cout << "\nEnter a string: ";
                cin.getline(str1, 100);
                
                cout << "\nOriginal string: \"" << str1 << "\"" << endl;
                reverseString(str1);
                cout << "Reversed string: \"" << str1 << "\"" << endl;
                break;
            }
            
            case 0:
                cout << "\nExiting program. Thank you!" << endl;
                break;
                
            default:
                cout << "\nInvalid choice! Please enter a number between 0-6." << endl;
                break;
        }
        
    } while (choice != 0);
    
    return 0;
}
