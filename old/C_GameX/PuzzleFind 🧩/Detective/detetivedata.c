#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024
#define ENCRYPTION_KEY 123
#define FILENAME_ENCRYPTED "encrypted_file.dat"
#define FILENAME_DECRYPTED "decrypted_file.txt"
#define FILENAME_REVERSED "encoded_file.dat"

void handleError(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

size_t readFile(const char *filename, char *buffer) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) handleError("Error opening file for reading");

    fseek(file, 0, SEEK_END);
    size_t fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    if (fileSize > MAX_FILE_SIZE) {
        fclose(file);
        fprintf(stderr, "File size exceeds buffer limit.\n");
        exit(EXIT_FAILURE);
    }

    fread(buffer, 1, fileSize, file);
    fclose(file);
    return fileSize;
}

void writeFile(const char *filename, const char *content) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) handleError("Error opening file for writing");

    fwrite(content, sizeof(char), strlen(content), file);
    fclose(file);
}

void encryptDecrypt(const char *input, char *output, size_t length, int key) {
    for (size_t i = 0; i < length; i++) {
        output[i] = input[i] ^ key;
    }
}

void reverseString(char *str, size_t length) {
    for (size_t i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

void solveEncryptionPuzzle() {
    printf("Puzzle 1: Decrypt the encrypted file to reveal the secret message.\n");

    char encryptedData[MAX_FILE_SIZE];
    size_t encryptedSize = readFile(FILENAME_ENCRYPTED, encryptedData);

    char decryptedData[MAX_FILE_SIZE];
    encryptDecrypt(encryptedData, decryptedData, encryptedSize, ENCRYPTION_KEY);

    writeFile(FILENAME_DECRYPTED, decryptedData);
    printf("The decrypted message has been written to '%s'.\n", FILENAME_DECRYPTED);
}

void solveReversalPuzzle() {
    printf("Puzzle 2: The secret data is hidden in a reversed string. Solve it.\n");

    char encodedData[MAX_FILE_SIZE];
    size_t encodedSize = readFile(FILENAME_REVERSED, encodedData);

    reverseString(encodedData, encodedSize);
    printf("The decoded secret message: %s\n", encodedData);
}

int main() {
    printf("Welcome, Data Detective! Solve the puzzles to uncover the hidden secrets.\n");

    solveEncryptionPuzzle();
    solveReversalPuzzle();

    return 0;
}
