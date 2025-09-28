#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *head;

int insertAtBeginning()
{
    int num;
    printf("Enter Number to insert: ");
    scanf("%d", &num);
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = num;

    if (head == NULL)
    {
        head = newNode;
        newNode->prev = NULL;
        newNode->next = NULL;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        newNode->prev = NULL;
    }
}

void displayList()
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp = head;
    while (temp->next != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);

    printf("In previous Order\n");
    while (temp->prev != NULL)
    {
        printf("%d<-", temp->data);
        temp = temp->prev;
    }
    printf("%d\n", temp->data);
}

int main()
{
    int choice;
    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));

    head = first;
    first->data = 23;
    first->prev = NULL;
    first->next = second;

    second->data = 34;
    second->prev = first;
    second->next = third;

    third->data = 60;
    third->prev = second;
    third->next = NULL;

    do
    {
        printf("\n1.Insert At Beginning\n2.Display List\n3.Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertAtBeginning();
            break;
        case 2:
            displayList();
        default:
            printf("Enter a valid choice");
        }

    } while (choice != 3);

    return 0;
}