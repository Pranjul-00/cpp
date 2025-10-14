/*
 * PRACTICAL 9: FILE COPY WITH WHITESPACE REMOVAL
 * ==============================================
 *
 * PURPOSE: Copy contents from one file to another while removing all whitespace
 *          characters (spaces, tabs, newlines, carriage returns).
 *
 * IMPLEMENTATION NOTES:
 * - No headers are included. Minimal C runtime prototypes are forward-declared
 *   and used for console and file I/O.
 */

extern "C" int printf(const char*, ...);
extern "C" int scanf(const char*, ...);
typedef struct _FILE FILE;  // Opaque forward declaration
extern "C" FILE* fopen(const char*, const char*);
extern "C" int fclose(FILE*);
extern "C" int fputc(int, FILE*);
extern "C" int fgetc(FILE*);

int main() {                                                             // Main function definition
    char sourceFile[260], destFile[260];                                 // Buffers to store file names
    
    printf("=== FILE COPY PROGRAM ===\n");
    printf("This program copies content from source file to destination file\n");
    printf("while removing all whitespace characters (spaces, tabs, newlines).\n");
    
    printf("\nEnter source file name (with extension): ");
    if (scanf("%259s", sourceFile) != 1) { printf("Invalid input.\n"); return 1; }
    printf("Enter destination file name (with extension): ");
    if (scanf("%259s", destFile) != 1) { printf("Invalid input.\n"); return 1; }
    
    FILE* source = fopen(sourceFile, "rb");
    if (!source) {
        printf("\nError: Could not open source file '%s'\n", sourceFile);
        printf("Please check if the file exists and you have read permissions.\n");
        return 1;
    }
    
    FILE* destination = fopen(destFile, "wb");
    if (!destination) {
        printf("\nError: Could not create/open destination file '%s'\n", destFile);
        printf("Please check if you have write permissions in the directory.\n");
        fclose(source);
        return 1;
    }
    
    printf("\nFiles opened successfully!\n");
    printf("Copying content from '%s' to '%s'...\n", sourceFile, destFile);
    printf("Removing whitespace characters during copy process.\n");
    
    int ch;                                                              // Use int for fgetc return
    int totalChars = 0, copiedChars = 0, removedChars = 0;               // Counters for statistics
    
    while ((ch = fgetc(source)) != -1) {                                 // Read each character until EOF
        totalChars++;
        if (ch != ' ' && ch != '\t' && ch != '\n' && ch != '\r') {
            fputc(ch, destination);
            copiedChars++;
        } else {
            removedChars++;
        }
    }
    
    fclose(source);
    fclose(destination);
    
    printf("\n=== FILE COPY COMPLETED ===\n");
    printf("Source file: %s\n", sourceFile);
    printf("Destination file: %s\n", destFile);
    printf("Total characters read: %d\n", totalChars);
    printf("Characters copied: %d\n", copiedChars);
    printf("Whitespace characters removed: %d\n", removedChars);
    printf("Copy operation completed successfully!\n");
    
    return 0;                                                            // Return 0 to indicate successful execution
}
