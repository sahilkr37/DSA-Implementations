#include <stdio.h>
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void adaptiveBubbleSort(int arr[], int size)
{
    int isSorted;
    for (int i = 0; i < size; i++)
    {
        printf("Pass number: %d\n", i);
        isSorted = 1;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                isSorted = 0;
            }
        }
        if (isSorted)
            break;
    }
}

int main()
{
    int size = 6;
    int array[6] = {1, 2, 3, 4, 5, 6};
    adaptiveBubbleSort(array, size);
    printf("The sorted elements are : \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d-", array[i]);
    }

    return 0;
}