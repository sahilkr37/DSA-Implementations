#include <stdio.h>

int main()
{
    int arr[] = {3, 8, 9, 11};
    int arr2[] = {2, 3, 7, 10};
    int size1 = 4, size2 = 4;

    int ans[8];

    int i = 0, j = 0, n = 0;
    while (i < size1 && j < size2)
    {
        if (arr[i] < arr2[j])
        {
            ans[n++] = arr[i++];
        }
        else
        {
            ans[n++] = arr2[j++];
        }
    }

    for (int m = i; m < size1; m++)
        ans[n++] = arr[m];

    for (int m = j; m < size2; m++)
        ans[n++] = arr[m];

    for (i = 0; i < 8; i++)
        printf("%d ", ans[i]);
}