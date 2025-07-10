#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10];
    a[0] = 182;
    a[1] = 1;
    a[2] = 14;
    a[3] = 11;
    a[4] = 200;

    for (int i = 0;i < 5;i ++)
    {
        printf("\nvalor de a[%i]=%i", i,a[i]);
    }

    return 0;
}
