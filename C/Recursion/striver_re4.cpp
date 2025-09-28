// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void arrReverse(int arr[], int n)
{
    int temp;
    for (int i = 0, j = n - 1; i <= j; i++, j--)
    {
        swap(arr[i], arr[j]);
    }
}

void arrReverseUsingRecursion(int i, int arr[], int n)
{
    if (i >= n / 2)
        return swap(arr[i], arr[n - i - 1]);
    arrReverseUsingRecursion(i + 1, arr, n);
}

bool checkPalindrome(int i, string s)
{
    if (i >= s.size() / 2)
        return true;

    if (s[i] != s[s.size() - i - 1])
        return false;
    checkPalindrome(i + 1, s);
}

int main()
{

    int arr[] = {2, 4, 3, 2, 1};
    int n = 5;
    arrReverse(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    arrReverseUsingRecursion(0, arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << checkPalindrome(0, "madam");

    return 0;
}