/*
 * PRACTICAL 3: ALPHABET FREQUENCY COUNTER
 * ======================================
 *
 * PURPOSE: Count the frequency of each alphabet character from command line arguments
 *          and display the results in a tabular format.
 *
 * IMPLEMENTATION NOTES:
 * - No external libraries included. Uses forward-declared C runtime functions.
 *
 * USAGE: program.exe "Hello World" "Programming"
 */

extern "C" int printf(const char*, ...);

int main(int argc, char* argv[]) {
    int count[26] = {0};

    if (argc < 2) {
        printf("Usage: %s <text1> <text2> ...\n", argv[0]);
        printf("Please provide text as command line arguments.\n");
        printf("Example: %s \"Hello World\" \"Programming\"\n", argv[0]);
        return 1;
    }

    printf("Processing command line arguments:\n");

    for (int i = 1; i < argc; i++) {
        char* str = argv[i];
        printf("Argument %d: \"%s\"\n", i, str);

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

    printf("\n=== ALPHABET FREQUENCY TABLE ===\n");
    printf("Alphabet\tOccurrences\n");
    printf("--------\t-----------\n");

    bool foundAny = false;
    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            printf("%c\t\t%d\n", (char)('A' + i), count[i]);
            foundAny = true;
        }
    }

    if (!foundAny) {
        printf("No alphabetic characters found in the input.\n");
    }

    return 0;
}
