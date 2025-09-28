#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *temp)
{
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node *insertAtBeginning(struct Node *head, int data)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }

    return head;
}

struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    struct Node *temp = head;
    for (int i = 0; i < index - 1; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
} 

struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = NULL;

    return head;
}

struct node *deleteFirst(struct Node *head)
{
    struct Node *temp = head;
    head = head->next;
    free(temp);

    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    // Allocate memory for nodes in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second node
    head->data = 11;
    head->next = second;

    // Link second and third node
    second->data = 22;
    second->next = third;

    // Terminate the list at the third node
    third->data = 33;
    third->next = NULL;

    /****Traversal and Insertion****/

    // Linked list Traversal
    linkedListTraversal(head);

    // Insertat beginning
    head = insertAtBeginning(head, 1);
    linkedListTraversal(head);

    // Insert at given index
    head = insertAtIndex(head, 25, 3);
    linkedListTraversal(head);

    // Insert at end
    head = insertAtEnd(head, 44);
    linkedListTraversal(head);

    /****Deletion****/

    head = deleteFirst(head);
    linkedListTraversal(head);
}