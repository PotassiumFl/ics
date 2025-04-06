#include <stdio.h>

int main()
{
    int n = 1024;
    long int a[n][n];
    long int i = 1;
    long int *p = &a[0][0];
    while (i <= n * n)
    {
        *(p + i - 1) = i;
        i++;
    }
    printf("%ld", a[n - 1][n - 1]);
    return 0;
}