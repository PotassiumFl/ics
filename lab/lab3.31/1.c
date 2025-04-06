#include <stdio.h>

void test(int i)
{
    int a[10];
    if (i > 10)
    {
        return;
    }
    else
    {
        a[i] = i;
        printf("%p\n", a);
        for (int j = 0; j <= 10; j++)
        {
            printf("%d\n", a[j]);
        }
        printf("\n");
        test(i + 1);
    }
}

int main()
{
    test(0);
    return 0;
}