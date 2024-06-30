#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;

} *top;

void push(int info)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = info;

    newnode->next = top;
    top = newnode;
}

void pop()
{
    if (top == NULL)
    {
        printf("underflow");
    }

    else
    {
        struct node *temp = top;
        top = top->next;
        printf("poppeed value is %d", temp->data);
        free(temp);
    }
}

struct node *display()
{
    struct node *curr = top;
    while (curr->next != NULL)
    {
        printf("%d->", curr->data);
        curr = curr->next;
    }
    printf("%d->\n", curr->data);
}

struct node *isempty()
{
    if (top == NULL)
    {
        printf("the stack is empty\n");
    }
    else
    {
        printf("the stack is not empty\n");
    }
}

int main()
{
    int choice, val;
    do
    {

        printf("1.PUSH\n");
        printf("2.POP\n");
        printf("3. DISPLAY\n");
        printf("4.ISEMPTY\n");
      
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("enter the value of the node\n");
            scanf("%d", &val);
            push(val);
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            isempty();
        }
    } while (choice != 5);
    return 0;
}