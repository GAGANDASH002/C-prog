#include <stdio.h>
#include <stdlib.h>

int queue[5], front = -1, rear = -1;

void enqueue(int val)
{
    if (rear == -1 && front == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = val;
    }
    else if ((rear + 1) % 5 == front)
    {
        printf("OVERFLOW!!!!!\n");
    }
    else
    {
        rear = (rear + 1) % 5;
        queue[rear] = val;
    }
}

int dequeue()
{
    int item;
    if (front == -1 && rear == -1)
    {
        printf("UNDERFLOW!!!!\n");
    }
    else if (front == rear)
    {
        printf("dequeued element is%d\n", queue[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        
        item = queue[front];
        printf("the dequeued item is%d\n",item);
        front = (front + 1) % 5;
    }
}
void isempty()
{
    if (front == -1 && rear == -1)
    {
        printf("UNDERFLOW!!!!\n");
    }
    else
    {
        printf("queue is not empty\n");
    }
}
void isfull()
{
    if ((rear + 1) % 5 == front)
    {
        printf("OVERFLOW!!!!!\n");
    }
    else
    {
        printf("bohut jagah hai\n");
    }
}
void traverse()
{
    for(int i=front;i<=rear;i++)
    {
        printf("%d->",queue[i]);
    }
}
int main()
{
    int choice, value;
    do
    {
        printf("MENU\n");
        printf("1.ENQUEUE\n");
        printf("2.DEQUEUE\n");
        printf("3.ISEMPTY\n");
        printf("4.ISFULL\n");
        printf("5.TRAVERSAL\n");
        printf("enter ur choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter the value to be inserted\n");
            scanf("%d", &value);
            enqueue(value);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            isempty();
            break;

        case 4:
            isfull();
            break;
        
        case 5:
            traverse();
            break;
        }
    } while (choice != 6);
}
