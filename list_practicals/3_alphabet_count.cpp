#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    int count[26] = {0};

    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <text1> <text2> ..." << endl;
        cout << "Please provide text as command line arguments." << endl;
        cout << "Example: " << argv[0] << " \"Hello World\" \"Programming\"" << endl;
        return 1;
    }

    cout << "Processing command line arguments:" << endl;

    for (int i = 1; i < argc; i++) {
        char* str = argv[i];
        cout << "Argument " << i << ": \"" << str << "\"" << endl;

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

    cout << "\n=== ALPHABET FREQUENCY TABLE ===" << endl;
    cout << "Alphabet\tOccurrences" << endl;
    cout << "--------\t-----------" << endl;

    bool foundAny = false;
    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            cout << (char)('A' + i) << "\t\t" << count[i] << endl;
            foundAny = true;
        }
    }

    if (!foundAny) {
        cout << "No alphabetic characters found in the input." << endl;
    }

    return 0;
}
