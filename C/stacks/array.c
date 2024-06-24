#include <stdio.h>
#include <stdlib.h>

int stack[10], top = -1;

void push(int item)
{

    if (top == 9)
    {
        printf("overflow");
    }
    else
    {
        top++;
        stack[top] = item;
        
    }
}

void pop()
{
    if (top == -1)
    {
        printf("underflow");
    }
    else
    {
        int data;
        data = stack[top];
        top--;
        printf("popped value is %d\n", data);
    }
}

void isempty(int top)
{
    if (top == -1)
    {
        printf("stack is empty\n");
    }
    else
    {
        printf("the list is not empty\n");
    }
}
void isfull(int top)
{
    if (top == 9)
    {
        printf("the stack is full\n");
    }
    else
    {
        printf("the stack is not full\n");
    }
}
void traverse()
{
    printf("stack is\n");
    for (int i = 0; i <= top;  i--)
    {
        
        printf("%d\n", stack[i]);
        
    }
}
int main()
{
    int top,choice, value;
    do
    {
        printf("Menu\n");
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. check if empty\n");
        printf("4. traverse the stack\n");
        printf("5. check if full\n");
        printf("enter ur  choice\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("enter value to push\n");
            scanf("%d", &value);
            push(value);
            break;

        case 2:
            pop(top);
            break;

        case 3:
            isempty(top);
            break;

        case 4:
            traverse(top);
            break;
        }
    } while (choice != 6);
    return 0;
}