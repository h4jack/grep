#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to highlight matching words
void highlight(char* line, char* search) {
    char* match = strstr(line, search);
    if (match != NULL) {
        printf("%s", line);
    }
}

int main(int argc, char* argv[]) {
    // Define variables for options and default values
    int showLineNumbers = 0;  // -n
    int stripWhitespace = 0;  // -s
    int excludeLines = 0;     // -e

    // Check if the correct number of arguments is provided
    if (argc < 3) {
        printf("Usage: %s <filename> <search_string> [-n] [-s] [-e]\n", argv[0]);
        return 1;
    }

    // Variables to store filename and search string
    char *filename = NULL;
    char *search_text = NULL;

    // Parse command line options
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            for (int j = 1; j < strlen(argv[i]); j++) {
                if (argv[i][j] == 'n') {
                    showLineNumbers = 1;
                } else if (argv[i][j] == 's') {
                    stripWhitespace = 1;
                } else if (argv[i][j] == 'e') {
                    excludeLines = 1;
                } else {
                    printf("Error: Unknown option '%c'\n", argv[i][j]);
                    return 1;
                }
            }
        } else {
            if (filename == NULL) {
                filename = argv[i];
            } else if (search_text == NULL) {
                search_text = argv[i];
            } else {
                printf("Error: Unexpected argument '%s'\n", argv[i]);
                return 1;
            }
        }
    }

    // Check if filename and search text are provided
    if (filename == NULL || search_text == NULL) {
        printf("Error: Both filename and search text are required.\n");
        return 1;
    }

    // Open the file
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File '%s' not found.\n", filename);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    int line_no = 0;

    // Read lines from the file
    while (fgets(line, sizeof(line), file)) {
        line_no++;

        // Check if the search string is present
        if (strstr(line, search_text) != NULL) {
            int matchFound = 0;
            // Check options for each line
            if (!excludeLines) {
                if (showLineNumbers) {
                    printf("%d : ", line_no);
                }
                if (stripWhitespace) {
                    // Strip leading and trailing spaces
                    char *stripped_line = line;
                    char *end = stripped_line + strlen(stripped_line) - 1;
                    while (end >= stripped_line && (*end == '\n' || *end == '\r' || *end == ' ' || *end == '\t')) {
                        *end-- = '\0';
                    }
                    while (*stripped_line && (*stripped_line == ' ' || *stripped_line == '\t')) {
                        ++stripped_line;
                    }
                    printf("%s\n", stripped_line);
                    continue; // Skip to the next line
                }else{
                    printf("%s", line);
                }
                matchFound = 1;
            }
            if (excludeLines && !matchFound) {
                continue; // Skip to the next line
            }
        } else if (excludeLines) {
            // Print lines that don't contain the search string
            if (showLineNumbers) {
                printf("%d : ", line_no);
            }
            if (stripWhitespace) {
                // Strip leading and trailing spaces
                char *stripped_line = line;
                char *end = stripped_line + strlen(stripped_line) - 1;
                while (end >= stripped_line && (*end == '\n' || *end == '\r' || *end == ' ' || *end == '\t')) {
                    *end-- = '\0';
                }
                while (*stripped_line && (*stripped_line == ' ' || *stripped_line == '\t')) {
                    ++stripped_line;
                }
                printf("%s\n", stripped_line);
                continue; // Skip to the next line
            }else{
                printf("%s", line);
            }
        }
    }

    // Close the file
    fclose(file);
    return 0;
}
