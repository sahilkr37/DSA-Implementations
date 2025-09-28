#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;
    int size;
    printf("Enter size:\n");
    scanf("%d", &size);

    ptr = (int *)malloc(size * sizeof(int));

    if (ptr == NULL)
        printf("Memory not allocated");
    else
        printf("Memory successfully allocated using malloc");

    for (int i = 0; i < size; i++)
    {
        ptr[i] = i;
    }

    printf("Elements of array are:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d", ptr[i]);
    }
    return 0;
}