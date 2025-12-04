#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to count all characters

int countCharacters(string filename) {
    ifstream fin(filename);      // open the file in read mode
    if (!fin) return -1; 
    char ch;
    int count = 0;
    while (fin.get(ch)) {        // .get() reads every single char including spaces and newlines
        count++;
    }
    fin.close();
    return count;
}

// Function to count words

int countWords(string filename) {
    ifstream fin(filename);
    if (!fin) return -1;
    string word;
    int count = 0;
    while (fin >> word) {        // >> operator automatically skips whitespaces, isolating words
        count++;
    }
    fin.close();
    return count;
}

// Function to count lines

int countLines(string filename) {
    ifstream fin(filename);
    if (!fin) return -1;
    string line;
    int count = 0;
    while (getline(fin, line)) { // getline reads text until it hits a newline character
        count++;
    }
    fin.close();
    return count;
}

int main() {
    string filename = "input.txt"; 

    // Create a dummy file for testing automatically
    ofstream temp(filename);     // open file for writing (creates it if it doesn't exist)
    temp << "Hello world\nThis is a test file\nGood luck"; // writing sample data
    temp.close();

    cout << " analyzing file: " << filename << endl;
    
    int chars = countCharacters(filename);
    int words = countWords(filename);
    int lines = countLines(filename);

    cout << "Number of Characters: " << chars << endl;
    cout << "Number of Words: " << words << endl;
    cout << "Number of Lines: " << lines << endl;

    return 0;
}