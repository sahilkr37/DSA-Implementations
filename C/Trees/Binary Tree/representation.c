#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
}

void preorderTraversal(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}
void postorderTraversal(struct node *root)
{
    if (root != NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

void inorderTraversal(struct node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}
int main()
{
    struct node *p1 = createNode(2);
    struct node *p2 = createNode(1);
    struct node *p3 = createNode(4);
    struct node *p4 = createNode(11);
    struct node *p5 = createNode(12);

    struct node *p6 = createNode(3);

    p1->left = p2;
    p1->right = p3;

    p2->left = p4;
    p2->right = p5;

    p3->left = NULL;
    p3->right = p6;

    // preorderTraversal(p1);
    // postorderTraversal(p1);
    inorderTraversal(p1);
}