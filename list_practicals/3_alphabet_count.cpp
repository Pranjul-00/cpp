#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    int count[26] = {0}; // Array to store count of each alphabet
    
    if (argc < 2) {
        cout << "Please provide text as command line arguments." << endl;
        return 1;
    }
    
    // Process each command line argument
    for (int i = 1; i < argc; i++) {
        char* str = argv[i];
        int j = 0;
        while (str[j] != '\0') {
            char ch = str[j];
            if (ch >= 'a' && ch <= 'z') {
                count[ch - 'a']++;
            } else if (ch >= 'A' && ch <= 'Z') {
                count[ch - 'A']++;
            }
            j++;
        }
    }
    
    // Print the table
    cout << "Alphabet\tOccurrences" << endl;
    cout << "--------\t-----------" << endl;
    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            cout << (char)('A' + i) << "\t\t" << count[i] << endl;
        }
    }
    
    return 0;
}
