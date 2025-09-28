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
    // if (qu->head == qu->tail)
    if (qu->head == -1)
        return 1;
    return 0;
}

int isFull(struct queue *qu)
{
    // if ((qu->tail + 1) % qu->size == qu->head)
    if ((qu->head == qu->tail + 1) || (qu->head == 0 && qu->tail == qu->size - 1))
        return 1;
    return 0;
}

void enqueue(struct queue *qu)
{
    printf("\n");
    if (isFull(qu))
    {
        printf("\nQueue Overflow!\n ");
    }
    else
    {
        if (qu->head == -1)
            qu->head = 0;

        int val;
        printf("Enter the number to enqueue: ");
        scanf("%d", &val);

        qu->tail = (qu->tail + 1) % qu->size;
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
        a = qu->array[qu->head];
        if (qu->head == qu->tail)
        {
            qu->head = -1;
            qu->tail = -1;
        }
        else
        {
            qu->head = (qu->head + 1) % qu->size;
        }
    }
    return a;
}

void display(struct queue *qu)
{
    int i;
    if (isEmpty(qu))
    {
        printf("\nQueue Underflow!\n ");
    }
    else
    {
        for (i = qu->head; i != qu->tail; i = (i + 1) % qu->size)
        {
            printf("%d-", qu->array[i]);
        }
        printf("%d-", qu->array[i]);
    }
}
int main()
{
    struct queue *qu;
    qu->tail = -1;
    qu->head = -1;
    qu->size = 6;
    qu->array = (int *)malloc(qu->size * sizeof(int));

    while (1)
    {
        printf("\n1.Enqueue | 2.Dequeue | 3.Display | 4.Exit\n");
        int choice;
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue(qu);
            break;
        case 2:
            dequeue(qu);
            break;
        case 3:
            display(qu);
            break;
        case 4:
            exit(0);
        default:
            printf("Enter a valid choice!\n");
        }
    }
}