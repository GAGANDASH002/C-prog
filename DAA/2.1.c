#include <stdio.h>
#include <stdlib.h>

void decimalToBinary(int num, FILE *outputFile) {
    if (num > 1) {
        decimalToBinary(num / 2, outputFile);
    }
    fprintf(outputFile, "%d", num % 2);
}

void processNumbers(FILE *inputFile, FILE *outputFile, int n) {
    int num;
    for (int i = 0; i < n; i++) {
        if (fscanf(inputFile, "%d", &num) != 1) {
            printf("Error reading number from file or not enough numbers in the file.\n");
            return;
        }
        decimalToBinary(num, outputFile);
        fprintf(outputFile, "\n");
    }
}

int main() {
    char inputFileName[100], outputFileName[100];
    int n;

    printf("Enter the name of the input file: ");
    scanf("%s", inputFileName);

    printf("Enter the name of the output file: ");
    scanf("%s", outputFileName);

    printf("Enter the number of decimal numbers to process: ");
    scanf("%d", &n);

    FILE *inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE *outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        fclose(inputFile);
        return 1;
    }

    processNumbers(inputFile, outputFile, n);

    fclose(inputFile);
    fclose(outputFile);

    printf("Processing completed. Binary numbers have been written to %s.\n", outputFileName);

    return 0;
}
