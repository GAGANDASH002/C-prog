#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* createNode(int data)
 {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL)
        {
        printf("Memory allocation failed - No Inputs ");
        exit(1);
       }

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void displayList(struct Node* head)
 {
    struct Node* current = head;

    while (current != NULL)
        {
        printf("%d -> ", current->data);
        current = current->next;
        }
    printf("NULL\n");
} 

struct Node* insertAtBeginning(struct Node* head, int data)
 {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    
    return newNode;
}

struct Node* insertAtEnd(struct Node* head, int data)
{
    struct Node* newNode = createNode(data);

    if (head == NULL)
        {
        return newNode;
        }

    struct Node* current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

struct Node* insertAtPosition(struct Node* head, int data, int position)
 {
    if (position < 1)
        {
        printf("Invalid position!\n");
        return head;
        }
    if (position == 1 || head == NULL)
    {
        return insertAtBeginning(head, data);
    }
    struct Node* newNode = createNode(data);
    struct Node* current = head;
    for (int i = 1; i < position - 1; i++)
    {
        if (current->next == NULL)
         {
            printf("Invalid position!\n");
            return head;
         }
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

struct Node* deleteAtPosition(struct Node* head, int position)
 {
    if (position < 1 || head == NULL)
        {
        printf("Invalid position!\n");
        return head;
        }
    if (position == 1)
     {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
     }

    struct Node* current = head;
    for (int i = 1; i < position - 1; i++)
        {
        if (current->next == NULL)
        {
            printf("Invalid position!\n");
            return head;
        }
        current = current->next;
    }
    if (current->next == NULL)
    {
        printf("Invalid position!\n");
        return head;
    }
    struct Node* temp = current->next;
    current->next = temp->next;
    free(temp);
    
    return head;
}

int main()
 {
    struct Node* head = NULL;
    int choice, data, position;

    do {
        printf("\nMenu:\n");
        printf("1. Create a linked list\n");
        printf("2. Insert an element at the beginning\n");
        printf("3. Insert an element at the end\n");
        printf("4. Insert an element at a specific position\n");
        printf("5. Delete an element from a specific position\n");
        printf("6. Display the linked list\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of nodes: ");
                scanf("%d", &data);
                for (int i = 0; i < data; i++) {
                    printf("Enter data for node %d: ", i + 1);
                    scanf("%d", &position);
                    head = insertAtEnd(head, position);
                }
                break;
            case 2:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 3:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 4:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                head = insertAtPosition(head, data, position);
                break;
            case 5:
                printf("Enter position to delete from: ");
                scanf("%d", &position);
                head = deleteAtPosition(head, position);
                break;
            case 6:
                printf("Linked List: ");
                displayList(head);
                break;
            case 7:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Wrong Choice ");
                break;
        }
    } while (choice != 7);

    return 0;
}