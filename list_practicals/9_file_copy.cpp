#include <iostream>
#include <fstream>
using namespace std;

int main() {
    char sourceFile[100], destFile[100];
    
    cout << "Enter source file name: ";
    cin >> sourceFile;
    cout << "Enter destination file name: ";
    cin >> destFile;
    
    ifstream source(sourceFile);
    if (!source) {
        cout << "Error: Cannot open source file!" << endl;
        return 1;
    }
    
    ofstream dest(destFile);
    if (!dest) {
        cout << "Error: Cannot create destination file!" << endl;
        source.close();
        return 1;
    }
    
    char ch;
    while (source.get(ch)) {
        // Skip whitespace characters (space, tab, newline, etc.)
        if (ch != ' ' && ch != '\t' && ch != '\n' && ch != '\r') {
            dest.put(ch);
        }
    }
    
    source.close();
    dest.close();
    
    cout << "File copied successfully with whitespaces removed!" << endl;
    
    return 0;
}
