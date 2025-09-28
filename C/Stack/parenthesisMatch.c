#include <stdio.h>
#include <stdlib.h>

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

void push(struct stack *st, int num)
{
    if (isFull(st))
        printf("\nStack overflow\n");

    else
    {
        st->Top++;
        st->array[st->Top] = num;
    }
}

int pop(struct stack *st)
{
    if (isEmpty(st))
        printf("\nStack is empty\n");

    else
    {
        // printf("\nPopped item is:%d", st->array[st->Top]);
        st->array[st->Top--];
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

void stackTop(struct stack *st)
{
    printf("The top most element of the stack is: %d\n", st->array[st->Top]);
}

void stackBottom(struct stack *st)
{
    printf("The Bottom most element of the stack is: %d\n", st->array[0]);
}

int parenthesisMatch(char *exp)
{
    struct stack *sp;
    sp->size = 100;
    sp->Top = -1;
    sp->array = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(sp))
                return 0;
            else if (exp[i] == ')' && sp->array[sp->Top] == '(' || exp[i] == '}' && sp->array[sp->Top] == '{' || exp[i] == ']' && sp->array[sp->Top] == '[')
                pop(sp);
            else
                return 0;
        }
    }

    if (isEmpty(sp))
        return 1;
    else
        return 0;
}
int main()
{

    char *exp = "(7-11+{23-8*2}-[33+1)";
    if (parenthesisMatch(exp))
        printf("Balanced Expression");
    else
        printf("Unbalanced Expression");

    return 0;
}