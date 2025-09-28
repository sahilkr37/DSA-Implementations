#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int array[], int size)
{
    int indexOfMin;

    for (int i = 0; i < size - 1; i++)
    {
        indexOfMin = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[indexOfMin])
            {
                indexOfMin = j;
            }
        }
        swap(&array[i], &array[indexOfMin]);
    }
}

void print(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d-", array[i]);
    }
}
int main()
{
    int size = 5;
    int array[] = {22, 7, 91, 77, 33};
    selectionSort(array, size);
    print(array, size);
}