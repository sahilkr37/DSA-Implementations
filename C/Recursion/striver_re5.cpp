// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int count = 0;
int fibonacci(int n)
{
    count++;
    if (n <= 1)
        return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{

    cout << fibonacci(10) << endl;
    cout << count; // O(2^n) exponential
    return 0;
}