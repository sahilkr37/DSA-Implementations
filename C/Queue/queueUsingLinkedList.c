#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct queue
{
    struct node *head;
    struct node *tail;
};

void enqueue(struct queue *qu)
{
    int value;
    printf("\nEnter value: ");
    scanf("%d", &value);

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    if (qu->head == NULL && qu->tail == NULL)
    {
        qu->head = newNode;
        qu->tail = newNode;
    }
    else
    {
        qu->tail->next = newNode;
        qu->tail = newNode;
    }
}

void dequeue(struct queue *qu)
{
    if (qu->head == NULL)
    {
        printf("Queue Underflow!");
    }
    else
    {
        struct node *temp = qu->head;
        qu->head = qu->head->next;
        free(temp);
    }
}

void display(struct queue *qu)
{
    struct node *temp = qu->head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

int main()
{
    struct queue *qu;
    qu->head = NULL;
    qu->tail = NULL;

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