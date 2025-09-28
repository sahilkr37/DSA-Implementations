#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int Top;
    int *array; // Pointer that will help in making array dynamically
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
        printf("\nPopped item is:%d", st->array[st->Top]);
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

int main()
{
    struct stack *st;
    st->size = 5;
    st->Top = -1;
    st->array = (int *)malloc(st->size * (sizeof(int))); // Alloting memory in heap

    // Pushing Element Manually
    //  st->array[0] = 4;
    //  st->Top++;
    //  st->array[1] = 4;
    //  st->Top++;
    //  st->array[2] = 4;
    //  st->Top++;
    //  st->array[3] = 4;
    //  st->Top++;
    //  st->array[4] = 4;
    //  st->Top++;

    // if (isEmpty(st))
    //     printf("Stack underflow");

    // if (isFull(st))
    //     printf("Stack overflow");

    push(st, 11);
    push(st, 12);
    push(st, 13);
    push(st, 14);
    push(st, 15);

    display(st);
    // push(st, 68);

    // pop(st);
    // display(st);

    peak(st, 3);
    stackTop(st);
    stackBottom(st);

    return 0;
}