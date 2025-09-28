#include <iostream>
#include <vector>
using namespace std;

void merge(int *arr, int low, int mid, int high)
{
    int left = low;
    int right = mid + 1;
    vector<int> temp;

    while (left <= mid && right <= high) 
    {
        if (arr[left] < arr[right])
            temp.push_back(arr[left++]);
        else
            temp.push_back(arr[right++]);
    }

    for (int i = left; i <= mid; i++)
        temp.push_back(arr[i]);

    for (int i = right; i <= high; i++)
        temp.push_back(arr[i]);

    for (int i = low; i <= high; i++)
        arr[i] = temp[i - low];
}

void mergeSort(int *arr, int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int main()
{
    int arr[] = {3, 2, 4, 1, 3};

    mergeSort(arr, 0, sizeof(arr) - 1);

    for (int i = 0; i < sizeof(arr); i++)
        cout << arr[i] << " ";

    return 0;
}
