// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

void sumParameter(int i, int sum)
{
    if (i < 1)
    {
        cout << sum;
        return;
    }
    sum += i;
    i--;
    sumParameter(i, sum);
}

int sumFunctional(int n)
{
    if (n == 0)
        return 0;

    return n + sumFunctional(n - 1);
}

int factorial(int n)
{
    if (n == 1)
        return 1;

    return n * factorial(n - 1);
}

int main()
{

    sumParameter(3, 0);
    cout << "\n"
         << sumFunctional(5) << endl;
    cout << factorial(5);
    return 0;
}