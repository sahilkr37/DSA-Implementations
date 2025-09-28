// Program to search a key in a BST
/*
     30
     /\
  20    40
  /\    /\
 10 25 35 50

*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
} *root = NULL;

int search(struct node *temp, int key)
{
    while (temp != NULL)
    {
        if (key == temp->data)
            return 1;

        else if (key > temp->data)
        {
            temp = temp->next;
        }
        else if (key < temp->data)
        {
            temp = temp->prev;
        }
    }
    return 0;
}

// Searching in BST using Recursion
struct node *searchUsingRecursion(struct node *temp, int key)
{
    if (temp == NULL)
        return NULL;

    if (key == temp->data)
        return temp;

    else if (key > temp->data)
        return searchUsingRecursion(temp->next, key);

    else
        return searchUsingRecursion(temp->prev, key);
}

void insert(int key)
{
    struct node *t = root;
    struct node *r = NULL, *p;
    if (root == NULL)
    {
        p = (struct node *)malloc(sizeof(struct node));
        p->data = key;
        p->prev = p->next = NULL;
        root = p;
        return;
    }

    while (t != NULL)
    {
        r = t;
        if (key < t->data)
            t = t->prev;
        else if (key > t->data)
            t = t->next;
        else
            return;
    }

    p = (struct node *)malloc(sizeof(struct node));
    p->data = key;
    p->prev = p->next = NULL;
    if (key < r->data)
        r->prev = p;
    else
        r->next = p;
}

struct node *recursiveInsert(struct node *p, int key)
{
    struct node *t = NULL;
    if (p == NULL)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = key;
        t->prev = NULL;
        t->next = NULL;
        return t;
    }
    else if (key < p->data)
    {
        p->prev = recursiveInsert(p->prev, key);
    }
    else if (key > p->data)
    {
        p->next = recursiveInsert(p->next, key);
    }

    return p;
}

void inorderTraversal(struct node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->prev);
        printf("%d ", root->data);
        inorderTraversal(root->next);
    }
}

int main()
{
    struct node *temp;
    // root = recursiveInsert(root, 30);
    // recursiveInsert(root, 20);
    insert(30);
    insert(20);

    inorderTraversal(root);
    if (search(root, 30))
        printf("Found");
    else
        printf("Not found");

    return 0;
}