#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
int countElements(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}
int searchElement(struct Node* head, int target) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == target) {
            return 1; 
        }
        current = current->next;
    }
    return 0; 
}
void printReverse(struct Node* head) {
    if (head == NULL) {
        return;
    }
    printReverse(head->next);
    printf("%d -> ", head->data);
}
int main() {
    struct Node* head = NULL;
    int n, element, choice, result;
    printf("Enter the number of elements in the SLL: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &element);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = element;
        newNode->next = head;
        head = newNode;
    }
    do {
        printf("\nMenu:\n");
        printf("1. Count the number of elements in the SLL\n");
        printf("2. Search for an element in the SLL\n");
        printf("3. Print the SLL in reverse order\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Number of elements in the SLL: %d\n", countElements(head));
                break;
            case 2:
                printf("Enter the element to search: ");
                scanf("%d", &element);
                result = searchElement(head, element);
                if (result) {
                    printf("Element found in the SLL.\n");
                } else {
                    printf("Element not found in the SLL.\n");
                }
                break;
            case 3:
                printf("SLL in reverse order: ");
                printReverse(head);
                printf("\n");
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}