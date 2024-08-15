#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers and fill the array
void generateRandomNumbers(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Generating random numbers between 0 and 99
    }
}

// Function to find the largest and second largest numbers using call by reference
void findLargestAndSecondLargest(int *arr, int n, int *largest, int *secondLargest) {
    if (n < 2) {
        printf("Array needs to have at least two elements.\n");
        return;
    }

    if (arr[0] > arr[1]) {
        *largest = arr[0];
        *secondLargest = arr[1];
    } else {
        *largest = arr[1];
        *secondLargest = arr[0];
    }

    for(int i = 2; i < n; i++) {
        if (arr[i] > *largest) {
            *secondLargest = *largest;
            *largest = arr[i];
        } else if (arr[i] > *secondLargest && arr[i] != *largest) {
            *secondLargest = arr[i];
        }
    }
}

int main() {
    int n;

   

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("Array needs to have at least two elements.\n");
        return 1;
    }

    int arr[n];

    // Generate random numbers
    generateRandomNumbers(arr, n);

    // Print the array
    printf("Generated array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int largest, secondLargest;

    // Find the largest and second largest number
    findLargestAndSecondLargest(arr, n, &largest, &secondLargest);

    printf("The largest number is: %d\n", largest);
    printf("The second largest number is: %d\n", secondLargest);

    return 0;
}
