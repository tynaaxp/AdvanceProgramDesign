#include <stdio.h>

int main() {
    FILE *inputFile, *outputFile;
    char ch;
    
    // Open the input file for reading and output file for writing
    inputFile = fopen("AHPA #5 - clearMessage.txt", "r");
    outputFile = fopen("secretMessage.txt", "w");
    
    if (inputFile == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    
    // Read each character from the file
    while ((ch = fgetc(inputFile)) != EOF) {
        // Check if the character is an alphabetic letter
        if (ch >= 'a' && ch <= 'z') {
            // Shift the character by 3 positions (wrap around if necessary)
            ch = ((ch - 'a' + 3) % 26) + 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            // Shift uppercase characters by 3 positions
            ch = ((ch - 'A' + 3) % 26) + 'A';
        }
        // Write the encrypted character to the output file
        fputc(ch, outputFile);
    }
    
    // Close both files
    fclose(inputFile);
    fclose(outputFile);
    
    printf("Message encrypted and saved to 'secretMessage.txt'.\n");
    
    return 0;
}