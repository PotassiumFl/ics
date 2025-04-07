#include <stdio.h>

int myfunc(unsigned int len)
{
    int sum = 0;
    for (int i = 1; i <= len; i++)
    {
        sum += i * i;
    }
    return sum;
}

int main()
{
    int (*pfunc1)(unsigned int);
    int (*pfunc2)(unsigned int);
    pfunc1 = myfunc;
    pfunc2 = &myfunc;
    printf("%d,%d,%d,%d", pfunc1(10), (*pfunc1)(10), pfunc2(10), (*pfunc2)(10));
}