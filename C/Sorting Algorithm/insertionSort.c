#include <stdio.h>

void insertionSort(int array[], int size)
{
    int key;
    int j;
    for (int i = 1; i < size; i++)
    {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
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
    insertionSort(array, size);
    print(array, size);
}