#include <stdio.h>
#include <stdlib.h>

// Define the structure for items
struct ITEM
{
    int item_id;
    int item_profit;
    int item_weight;
    double profit_weight_ratio;
};

// Function to calculate the profit-to-weight ratio for each item
void calculateProfitWeightRatio(struct ITEM items[], int n)
{
    for (int i = 0; i < n; i++)
    {
        items[i].profit_weight_ratio = (double)items[i].item_profit / items[i].item_weight;
    }
}

// Function to maintain the max-heap property based on profit/weight ratio
void heapify(struct ITEM arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].profit_weight_ratio > arr[largest].profit_weight_ratio)
        largest = left;

    if (right < n && arr[right].profit_weight_ratio > arr[largest].profit_weight_ratio)
        largest = right;

    if (largest != i)
    {
        struct ITEM temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

// Function to perform heap sort on the items based on profit/weight ratio
void heapSort(struct ITEM arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    
    for (int i = n - 1; i > 0; i--)
    {   
        struct ITEM temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

// Function to perform the fractional knapsack algorithm
double fractionalKnapsack(struct ITEM items[], int n, int capacity)
{
    double total_profit = 0.0;
    int current_weight = 0;

    for (int i = 0; i < n; i++)
    {
        if (current_weight + items[i].item_weight <= capacity)
        {
            current_weight += items[i].item_weight;
            total_profit += items[i].item_profit;
        }
        else
        {
            int remaining_capacity = capacity - current_weight;
            total_profit += items[i].profit_weight_ratio * remaining_capacity;
            break;
        }
    }

    return total_profit;
}

// Main function
int main()
{
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct ITEM items[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter the profit and weight of item no %d: ", i + 1);
        scanf("%d %d", &items[i].item_profit, &items[i].item_weight);
        items[i].item_id = i + 1;
    }

    printf("Enter the capacity of knapsack: ");
    scanf("%d", &capacity);

    // Calculate profit/weight ratio for each item
    calculateProfitWeightRatio(items, n);

    // Sort items based on profit/weight ratio using heap sort
    heapSort(items, n);

    // Find the maximum profit using the fractional knapsack algorithm
    double max_profit = fractionalKnapsack(items, n, capacity);

    printf("Maximum profit: %.2f\n", max_profit);

    return 0;
}
