#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int Top;
    char *array; // Pointer that will help in making array dynamically
};

void display(struct stack *st)
{
    for (int i = st->Top; i >= 0; i--)
    {
        printf("\n| %d | ", st->array[i]);
    }
}

int isFull(struct stack *st)
{
    return (st->Top == st->size - 1);
}

int isEmpty(struct stack *ptr)
{
    return (ptr->Top == -1);
}

void push(struct stack *st, char num)
{
    if (isFull(st))
        printf("\nStack overflow\n");

    else
    {
        st->Top++;
        st->array[st->Top] = num;
    }
}

char pop(struct stack *st)
{
    if (isEmpty(st))
    {
        printf("\nStack is empty\n");
        return -1;
    }

    else
    {
        // printf("\nPopped item is:%d", st->array[st->Top]);
        char val = st->array[st->Top];
        st->Top--;
        return val;
    }
}

void peak(struct stack *st, int index)
{
    if (index > st->Top + 1)
    {
        printf("\nInvalid index!\n");
    }
    else
    {
        printf("\n%d\n", st->array[st->Top - index + 1]);
    }
}

int stackTop(struct stack *st)
{
    // printf("The top most element of the stack is: %d\n", st->array[st->Top]);
    return st->array[st->Top];
}

void stackBottom(struct stack *st)
{
    printf("The Bottom most element of the stack is: %d\n", st->array[0]);
}

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return 1;
    else
        return 0;
}
int precedence(char ch)
{
    if (ch == '*' || ch == '/')
        return 3;
    else if (ch == '+' || ch == '-')
        return 2;
    return 0;
}
char *infixToPostfix(char *infix)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->Top = -1;
    sp->array = (char *)malloc(sp->size * sizeof(char));

    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(stackTop(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}
int main()
{

    char *infix = "p-q-r/a";
    printf("%s", infixToPostfix(infix));

    return 0;
}