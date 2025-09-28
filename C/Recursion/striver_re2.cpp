// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
void print1(int i, int n)
{
    if (i > n)
        return;

    cout << i << " ";
    print1(++i, n);
}

void print1_backtracking(int i, int n)
{
    if (n < i)
        return;

    print1_backtracking(i, n - 1);
    cout << n << " ";
}

void print2(int i, int n)
{
    if (n < i)
        return;
    cout << n << " ";

    print2(i, --n);
}

void print2_backtracking(int i, int n)
{
    if (i > n)
        return;

    print2_backtracking(i + 1, n);
    cout << i << " ";
}

int main()
{

    print1(1, 5);
    cout << endl;
    print2(1, 5);

    cout << "\n \nBy backtracking:\n";
    print1_backtracking(1, 5);
    cout << endl;
    print2_backtracking(1, 5); 
    return 0;
}