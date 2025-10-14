/*
 * PRACTICAL 9: STREAM FILTER (WHITESPACE REMOVAL)
 * ==============================================
 *
 * PURPOSE: Read from standard input and write to standard output while removing all
 *          whitespace characters (spaces, tabs, newlines, carriage returns).
 *
 * USAGE EXAMPLES:
 * - Using redirection:   program.exe < input.txt > output.txt
 * - Using pipes:         type input.txt | program.exe > output.txt
 */

#include <iostream>
using namespace std;

int main() {                                                             // Main function definition
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long totalChars = 0, copiedChars = 0, removedChars = 0;

    cout << "Filtering stdin to stdout (whitespace will be removed)..." << endl;

    int ch;
    while ((ch = cin.get()) != EOF) {
        totalChars++;
        if (ch != ' ' && ch != '\t' && ch != '\n' && ch != '\r') {
            cout.put(static_cast<char>(ch));
            copiedChars++;
        } else {
            removedChars++;
        }
    }

    cout << "\n\n=== SUMMARY ===" << endl;
    cout << "Total characters read: " << totalChars << endl;
    cout << "Characters written (non-whitespace): " << copiedChars << endl;
    cout << "Whitespace characters removed: " << removedChars << endl;

    return 0;                                                            // Return 0 to indicate successful execution
}
