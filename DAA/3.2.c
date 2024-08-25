#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

int partition(int arr[], int low, int high, int *compCount) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        (*compCount)++;
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quickSort(int arr[], int low, int high, int *compCount) {
    if (low < high) {
        int pi = partition(arr, low, high, compCount);
        quickSort(arr, low, pi - 1, compCount);
        quickSort(arr, pi + 1, high, compCount);
    }
}

int* readFile(const char *filename, int *size) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    int *arr = (int *)malloc(500 * sizeof(int));
    int value, count = 0;

    while (fscanf(file, "%d", &value) != EOF && count < 500) {
        arr[count++] = value;
    }

    fclose(file);
    *size = count;
    return arr;
}

void writeFile(const char *filename, int arr[], int size) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file %s\n", filename);
        return;
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%d ", arr[i]);
    }

    fclose(file);
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int choice, n, comparisons;
    int *arr;
    char inputFileName[100], outputFileName[100];
    clock_t start, end;

    while (1) {
        printf("MAIN MENU (QUICK SORT)\n");
        printf("1. Ascending Data\n");
        printf("2. Descending Data\n");
        printf("3. Random Data\n");
        printf("4. ERROR (EXIT)\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        comparisons = 0;

        switch (choice) {
            case 1:
                strcpy(inputFileName, "inAsce.dat");
                strcpy(outputFileName, "outQuickAsce.dat");
                break;
            case 2:
                strcpy(inputFileName, "inDesc.dat");
                strcpy(outputFileName, "outQuickDesc.dat");
                break;
            case 3:
                strcpy(inputFileName, "inRand.dat");
                strcpy(outputFileName, "outQuickRand.dat");
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid option. Try again.\n");
                continue;
        }

        arr = readFile(inputFileName, &n);
        if (arr == NULL) {
            continue;
        }

        printf("Before Sorting: ");
        printArray(arr, n);

        start = clock();
        quickSort(arr, 0, n - 1, &comparisons);
        end = clock();

        writeFile(outputFileName, arr, n);

        printf("After Sorting: ");
        printArray(arr, n);
        printf("Number of Comparisons: %d\n", comparisons);
        printf("Execution Time: %ld microseconds\n", (end - start) * 1000000 / CLOCKS_PER_SEC);

        if (comparisons == n * (n - 1) / 2) {
            printf("Worst-case partitioning.\n");
        } else if (comparisons == n * log2(n)) {
            printf("Best-case partitioning.\n");
        } else {
            printf("Average-case partitioning.\n");
        }

        free(arr);
    }

    return 0;
}
