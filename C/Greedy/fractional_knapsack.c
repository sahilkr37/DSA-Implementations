#include <stdio.h>
#include <stdlib.h>


void swap(double *arr, int i, int j)
{
    double temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// A function to implement bubble sort
void bubbleSort(double arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr, j, j + 1);
}

int main()
{
    double profit[] = {10, 5, 15, 7, 6, 18, 3};
    double weight[] = {2, 3, 5, 7, 1, 4, 1};
    int capacity = 15;

    double ratio[20];

    for (int i = 0; i < 7; i++)
        ratio[i] = profit[i] / weight[i];

    bubbleSort(ratio, 7);

    for (int i = 0; i < 7; i++)
        printf("%lf ", ratio[i]);

    // fractionalKnapsack(profit, weight, ratio, capacity);

    float currentWeight = 0;
    float totalValue = 0;

    for (int i = 6; i >= 0;i--)
    {
        if(currentWeight+ratio[i]<=capacity)
        {
            currentWeight += ratio[i];
            totalValue += profit[i];
        }
        else{
            
        }
    }

        return 0;
}