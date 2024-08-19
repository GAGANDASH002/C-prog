#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}   

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    FILE *sourceFile = fopen(argv[1], "r");
    FILE *destFile = fopen(argv[2], "w");

    if (sourceFile == NULL) {
        printf("Error: Could not open source file %s\n", argv[1]);
        return 1;
    }

    if (destFile == NULL) {
        printf("Error: Could not open destination file %s\n", argv[2]);
        fclose(sourceFile);
        return 1;
    }

    int num1, num2;
    while (fscanf(sourceFile, "%d %d", &num1, &num2) == 2) {
        int result = gcd(num1, num2);
        fprintf(destFile, "The GCD of %d and %d is %d\n", num1, num2, result);
    }

    fclose(sourceFile);
    fclose(destFile);

    printf("GCD calculations are stored in %s\n", argv[2]);

    return 0;
}