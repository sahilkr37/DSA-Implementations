#include <stdio.h>
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int partition(int arr[], int low, int high)
{
    int i = low, j = high, pivot = arr[low];
    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
            i++;
        while (arr[j] > pivot && j >= low + 1)
            j--;

        if (i < j)
            swap(&arr[i], &arr[j]);
    }
    swap(&arr[low], &arr[j]);

    return j;
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}
int main()
{
    int arr[] = {4, 6, 2, 5, 7, 9, 1, 3};
    int n = 8;

    quickSort(arr, 0, 7);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}