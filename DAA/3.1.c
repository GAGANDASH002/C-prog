#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void merge(int arr[], int st, int mid, int end, int *comparisons) {
    int i = st, j = mid + 1, k = st;
    int b[500]; 

    while (i <= mid && j <= end) {
        (*comparisons)++;
        if (arr[i] < arr[j]) {
            b[k++] = arr[i++];
        } else {
            b[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        b[k++] = arr[i++];
    }

    while (j <= end) {
        b[k++] = arr[j++];
    }

    for (i = st; i < k; i++) {
        arr[i] = b[i];
    }
}

void mergeSort(int arr[], int st, int end, int *comparisons) {
    if (st < end) {
        int mid = (st + end) / 2;
        mergeSort(arr, st, mid, comparisons);
        mergeSort(arr, mid + 1, end, comparisons);
        merge(arr, st, mid, end, comparisons);
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
        printf("MAIN MENU (MERGE SORT)\n");
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
                strcpy(outputFileName, "outMergeAsce.dat");
                break;
            case 2:
                strcpy(inputFileName, "inDesc.dat");
                strcpy(outputFileName, "outMergeDesc.dat");
                break;
            case 3:
                strcpy(inputFileName, "inRand.dat");
                strcpy(outputFileName, "outMergeRand.dat");
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
        mergeSort(arr, 0, n - 1, &comparisons);
        end = clock();

        writeFile(outputFileName, arr, n);

        printf("After Sorting: ");
        printArray(arr, n);
        printf("Number of Comparisons: %d\n", comparisons);
        printf("Execution Time: %ld microseconds\n", (end - start) * 1000000 / CLOCKS_PER_SEC);

        free(arr);
    }

    return 0;
}
