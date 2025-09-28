#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int *array;
    int size;
    int head;
    int tail;
};

int isEmpty(struct queue *qu)
{
    if (qu->head == qu->tail)
        return 1;
    return 0;
}

int isFull(struct queue *qu)
{
    if (qu->tail == qu->size - 1)
        return 1;
    return 0;
}

void enqueue(struct queue *qu, int val)
{
    printf("\n");
    if (isFull(qu))
    {
        printf("\nQueue Overflow!\n ");
    }
    else
    {
        qu->tail++;
        qu->array[qu->tail] = val;
    }
}

int dequeue(struct queue *qu)
{
    int a = -1;
    if (isEmpty(qu))
    {
        printf("\nQueue Underflow!\n ");
    }
    else
    {
        qu->head++;
        a = (qu->array[qu->head]);
    }
    return a;
}

void display(struct queue *qu)
{
    if (isEmpty(qu))
    {
        printf("\nQueue Underflow!\n ");
    }
    else
    {
        for (int i = qu->head + 1; i <= qu->tail; i++)
        {
            printf("%d-", qu->array[i]);
        }
    }
}
int main()
{
    struct queue *qu;
    qu->tail = -1;
    qu->head = -1;
    qu->size = 10;
    qu->array = (int *)malloc(qu->size * sizeof(int));
    enqueue(qu, 12);
    enqueue(qu, 24);

    display(qu);
    dequeue(qu);
    dequeue(qu);
    dequeue(qu);
    display(qu);
}