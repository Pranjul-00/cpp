#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string sourceFile, destFile;
    
    cout << "=== FILE COPY WITH WHITESPACE REMOVAL ===" << endl;
    cout << "\nEnter source filename: ";
    cin >> sourceFile;
    
    cout << "Enter destination filename: ";
    cin >> destFile;
    
    ifstream source(sourceFile);
    if (!source.is_open()) {
        cout << "Error: Cannot open source file '" << sourceFile << "' for reading." << endl;
        cout << "Please check if the file exists and you have read permissions." << endl;
        return 1;
    }
    
    ofstream dest(destFile);
    if (!dest.is_open()) {
        cout << "Error: Cannot open destination file '" << destFile << "' for writing." << endl;
        cout << "Please check if you have write permissions in the directory." << endl;
        source.close();
        return 1;
    }
    
    cout << "\nCopying from '" << sourceFile << "' to '" << destFile << "' (removing whitespace)..." << endl;
    
    char ch;
    int totalChars = 0, copiedChars = 0, removedChars = 0;
    
    while (source.get(ch)) {
        totalChars++;
        
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r') {
            removedChars++;
        } else {
            dest.put(ch);
            copiedChars++;
        }
    }
    
    source.close();
    dest.close();
    
    cout << "\n=== COPY STATISTICS ===" << endl;
    cout << "Total characters read: " << totalChars << endl;
    cout << "Characters copied: " << copiedChars << endl;
    cout << "Whitespace characters removed: " << removedChars << endl;
    cout << "\nFile copy completed successfully!" << endl;
    cout << "Output saved to: " << destFile << endl;
    
    return 0;
}
