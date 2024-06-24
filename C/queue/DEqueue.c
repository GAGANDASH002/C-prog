#include <stdio.h>
#include <stdlib.h>

struct DEqueue
{
    int front;
    int rear;
    int size;
    int *arr;
};

/*is full condition*/
void isFULL(struct DEqueue *q)
{
    if (q->rear == q->size - 1)
    {
        printf("are nahi jagah hai\n");
    }
}
/*is empty condition*/
void isEMPTY(struct DEqueue *q)
{
    if (q->front == q->rear==-1)
    {
        printf("khali h saale\n");
    };
}
/*insertion from rear*/
void *enqueueR(struct DEqueue *q, int val)
{

    if (q->rear == q->size - 1)
    {
        printf("are nahi jagah hai\n");
    }

    else if (q->front == -1 && q->rear == -1)
    {
        q->front = 0;
        q->rear = 0;
        q->arr[q->rear] = val;
    }
    else
    {
        q->rear++;
        q->arr[q->rear] = val;
    }
}
/*insertion from front*/
void enqueueF(struct DEqueue *q, int val)
{
    if (q->front == 0 && q->rear==q->size-1)
    {
        printf("are nahi jagah hai\n");
    }
    else if (q->front == -1)
    {
        q->front++;
        q->arr[q->front] = val;
    }

    else
    {
        q->front--;
        q->arr[q->front] = val;
    }
}

/*deletion at front end*/
int dequeueF(struct DEqueue *q)
{

    if (q->front == q->rear)
    {
        printf("dequeued element is %d\n", q->front);
        q->front = q->rear = -1;
    }
    else if (q->front == -1 && q->rear == -1)
    {
        printf("UNDERFLOW\n");
    }
    else
    {
        int val = q->arr[q->front];
        q->front++;

        return val;
    }
}
/*deletion at rear end*/
int dequeueR(struct DEqueue *q)
{
    if (q->front == q->rear)
    {
        printf("dequeued element is %d\n", q->front);
        q->front = q->rear = -1;
    }
    else if (q->front == -1 && q->rear == -1)
    {
        printf("UNDERFLOW\n");
    }

    else
    {

        int val = q->arr[q->rear];
        q->rear--;
        return val;
    }
}
// Displaying the DEQueue element
void Display(struct DEqueue *q)
{
    int i = q->front;
    while (i <= q->rear)
    {
        printf("Element:%d\n", q->arr[i]);
        i++;
    }
}
int main()
{
    struct DEqueue *q = (struct DEqueue *)malloc(sizeof(struct DEqueue));
    q->size = 5;
    q->front = q->rear = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    enqueueF(q, 45);
    enqueueR(q, 15);
    enqueueR(q, 19);
    enqueueR(q, 25);
    enqueueR(q, 95);

    Display(q);
    printf("Element is DeQueued at the front:%d\n", dequeueF(q));
    Display(q);
    printf("Element is DeQueued at the rear:%d\n", dequeueR(q));
    Display(q);
    printf("Element is DeQueued at the front:%d\n", dequeueF(q));
    Display(q);
    enqueueF(q, 55);
    Display(q);

    return 0;
}
