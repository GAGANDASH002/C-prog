#include <stdio.h>
#include <stdlib.h>

// Function to check if a number is prime
int is_prime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i*i  <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to calculate the sum of prime elements in an array
int sum_of_primes(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (is_prime(arr[i])) {
            sum += arr[i];
        }
    }
    return sum;
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int primeSum = sum_of_primes(arr, n);
    printf("Sum of prime elements: %d\n", primeSum);

    // Deallocate the dynamically allocated memory
    free(arr);

    return 0;
}