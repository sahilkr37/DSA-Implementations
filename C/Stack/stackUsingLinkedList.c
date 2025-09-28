#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct stack
{
    struct node *Top;
};
// **Function for creating number of nodes**

// struct node *createNode(int size)
// {
//     struct node *head;
//     int i = 0;

//     int num;

//     struct node *lastNode = (struct node *)malloc(sizeof(struct node));
//     head = lastNode;

//     printf("Enter Data:");
//     scanf("%d", &num);
//     lastNode->data = num;
//     lastNode->next = NULL;

//     struct node *temp = lastNode;
//     while (i < size - 1)
//     {

//         struct node *newNode = (struct node *)malloc(sizeof(struct node));

//         printf("Enter Data:");
//         scanf("%d", &num);

//         newNode->data = num;
//         newNode->next = temp;
//         head = newNode;

//         temp = newNode;
//         i++;
//     }

//     return head;
// }

void display(struct stack *st)
{
    struct node *temp = st->Top;
    while (temp != NULL)
    {
        printf("|%d->|\n", temp->data);
        temp = temp->next;
    }
}

int isEmpty(struct stack *st)
{
    if (st->Top == NULL)
        return 1;
    return 0;
}

int isFull(struct stack *st)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL) // Memory can"t be allocated dynamically
        return 1;
    return 0;
}

void push(struct stack *st)
{
    if (isFull(st))
        printf("Stack Overflow");
    else
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));

        int num;
        printf("\nEnter the element to push into stack : ");
        scanf("%d", &num);
        newNode->data = num;

        if (isEmpty(st))
        {
            st->Top = newNode;
            newNode->next = NULL;
        }
        else
        {
            newNode->next = st->Top;
            st->Top = newNode;
        }
    }
}

void pop(struct stack *st)
{
    if (isEmpty(st))
        printf("Stack underflow");
    else
    {
        struct node *temp;
        temp = st->Top;
        st->Top = temp->next;
        int num = temp->data;
        free(temp);
        printf("Popped data is: %d\n", num);
    }
}

int main()
{
    struct stack *st;
    // push(st);
    // push(st);
    // push(st);
    // push(st);
    // push(st);
    // display(st);
    // pop(st);
    // display(st);

    while (1)
    {
        printf("1.Push 2.Pop 3.Display 4.Exit");
        printf("\nEnter choice:  ");
        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push(st);
            break;
        case 2:
            pop(st);
            break;
        case 3:
            display(st);
            break;
        case 4:
            exit(0);

        default:
            printf("Enter valid choice!\n");
            break;
        }
    }
}
