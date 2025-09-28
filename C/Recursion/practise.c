#include <stdio.h>
#include <stdlib.h>

// void fun0()
// {
//     printf("HAPPY BIRTHDAY\n");
// }

// void fun(int n)
// {
//     if (n > 0)
//     {
//         printf("%d days left for birthday\n", n);
//         fun(n - 1);
//     }
//     else
//         fun0();

//     printf("done");
// }

void printNumbers(int n)
{
    if (n == 0)
        return;
        
    printNumbers(n - 1);
    if (n % 2 == 0)
    {
        printf("%d ", n);
    }
}

int main()
{
    // fun(5);
    printNumbers(10);
    return 0;
}