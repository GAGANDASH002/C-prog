#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct person
struct person {
    int id;
    char name[50];
    int age;
    int height; // in inches
    int weight; // in pounds
};

// Function prototypes (declarations)
struct person* readData(const char *filename, int *n);
void createMinHeap(struct person arr[], int n);
void createMaxHeap(struct person arr[], int n);
void minHeapify(struct person arr[], int n, int i);
void maxHeapify(struct person arr[], int n, int i);
void displayWeightOfYoungest(struct person arr[], int n);
void insertMinHeap(struct person arr[], int *n, struct person newPerson);
void deleteOldestPerson(struct person arr[], int *n);

int main() {
    int option;
    int n = 0;
    struct person *persons = NULL;

    while (1) {
        printf("\nMAIN MENU (HEAP)\n");
        printf("1. Read Data\n");
        printf("2. Create a Min-heap based on the age\n");
        printf("3. Create a Max-heap based on the weight\n");
        printf("4. Display weight of the youngest person\n");
        printf("5. Insert a new person into the Min-heap\n");
        printf("6. Delete the oldest person\n");
        printf("7. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                persons = readData("inHeap.txt", &n);
                if (persons != NULL) {
                    printf("Data read successfully.\n");
                }
                break;
            case 2:
                if (persons != NULL) {
                    createMinHeap(persons, n);
                    printf("Min-heap created based on age.\n");
                } else {
                    printf("Please read data first.\n");
                }
                break;
            case 3:
                if (persons != NULL) {
                    createMaxHeap(persons, n);
                    printf("Max-heap created based on weight.\n");
                } else {
                    printf("Please read data first.\n");
                }
                break;
            case 4:
                if (persons != NULL) {
                    displayWeightOfYoungest(persons, n);
                } else {
                    printf("Please read data first.\n");
                }
                break;
            case 5: {
                if (persons != NULL) {
                    struct person newPerson;
                    printf("Enter Id: ");
                    scanf("%d", &newPerson.id);
                    printf("Enter Name: ");
                    scanf("%s", newPerson.name);
                    printf("Enter Age: ");
                    scanf("%d", &newPerson.age);
                    printf("Enter Height: ");
                    scanf("%d", &newPerson.height);
                    printf("Enter Weight: ");
                    scanf("%d", &newPerson.weight);
                    insertMinHeap(persons, &n, newPerson);
                } else {
                    printf("Please read data first.\n");
                }
                break;
            }
            case 6:
                if (persons != NULL) {
                    deleteOldestPerson(persons, &n);
                } else {
                    printf("Please read data first.\n");
                }
                break;
            case 7:
                free(persons);
                exit(0);
        }
    }
    return 0;
}

// Function to read data from file
struct person* readData(const char *filename, int *n) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file.\n");
        return NULL;
    }

    fscanf(file, "%d", n);
    struct person *arr = (struct person*)malloc((*n) * sizeof(struct person));

    for (int i = 0; i < *n; i++) {
        fscanf(file, "%d %s %d %d %d", &arr[i].id, arr[i].name, &arr[i].age, &arr[i].height, &arr[i].weight);
    }

    fclose(file);
    return arr;
}

// Function to create a Min-Heap based on age
void createMinHeap(struct person arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(arr, n, i);
    }
}

// Function to heapify a subtree with root at index i (Min-Heap)
void minHeapify(struct person arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].age < arr[smallest].age)
        smallest = left;

    if (right < n && arr[right].age < arr[smallest].age)
        smallest = right;

    if (smallest != i) {
        struct person temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;

        minHeapify(arr, n, smallest);
    }
}

// Function to create a Max-Heap based on weight
void createMaxHeap(struct person arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

// Function to heapify a subtree with root at index i (Max-Heap)
void maxHeapify(struct person arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].weight > arr[largest].weight)
        largest = left;

    if (right < n && arr[right].weight > arr[largest].weight)
        largest = right;

    if (largest != i) {
        struct person temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        maxHeapify(arr, n, largest);
    }
}

// Function to display the weight of the youngest person
void displayWeightOfYoungest(struct person arr[], int n) {
    printf("Weight of youngest student: %.2f kg\n", arr[0].weight * 0.453592); // convert pounds to kg
}

// Function to insert a new person into the Min-Heap
void insertMinHeap(struct person arr[], int *n, struct person newPerson) {
    *n = *n + 1;
    arr = realloc(arr, (*n) * sizeof(struct person));
    int i = *n - 1;
    arr[i] = newPerson;

    while (i != 0 && arr[(i - 1) / 2].age > arr[i].age) {
        struct person temp = arr[i];
        arr[i] = arr[(i - 1) / 2];
        arr[(i - 1) / 2] = temp;

        i = (i - 1) / 2;
    }
}

// Function to delete the oldest person
void deleteOldestPerson(struct person arr[], int *n) {
    if (*n == 0) {
        printf("Heap is empty.\n");
        return;
    }

    arr[0] = arr[*n - 1];
    *n = *n - 1;
    minHeapify(arr, *n, 0);
    arr = realloc(arr, (*n) * sizeof(struct person));
}
