#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void findLargest(int arr[], int n, int *largest) {
    *largest = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > *largest) {
            *largest = arr[i];
        }
    }
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    

    // Generate n random numbers and store them in the array
    printf("Random numbers generated: ");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Random number between 0 and 99
        printf("%d ", arr[i]);
    }
    printf("\n");

    int largest;
    // Call the function to find the largest number
    findLargest(arr, n, &largest);

    printf("The largest number is: %d\n", largest);

    return 0;
}
