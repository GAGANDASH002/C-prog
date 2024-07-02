/*circular queue operations using array*/

#include <stdio.h>
#include <stdlib.h>

int queue[5];
int front = -1, rear = -1;

void enqueue(int data)
{
    rear = rear + 1;
    if (rear == 4 || front == -1)
    {
        rear = 0;
        front = 0;
        queue[rear] = data;
    }
}

int main()
{
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
}