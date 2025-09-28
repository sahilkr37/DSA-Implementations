// Program to remove duplicates from an array
#include <stdio.h>
// int count = 0;

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d", array[i]);
    }
}

void removeDuplicates(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (array[i] == array[j])
            {
                for (int k = j; k < size - 1; k++)
                {
                    array[k] = array[k + 1];
                }
                size = size - 1;
            }
        }
    }
}

int main()
{
    int size;
    printf("Enter size: ");
    scanf("%d", &size);

    printf("Enter elements of array: ");
    int array[size];
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }

    printArray(array, size);
    printf("\n");

    removeDuplicates(array, size);
    printArray(array, size);
}