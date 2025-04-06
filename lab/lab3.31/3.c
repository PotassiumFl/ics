#include <stdio.h>

void fill(int *a, int m, int n, int x, int mm, int nn)
{
    for (int i = 0; i < nn; i++)
        *(a + i) = x + i;

    for (int i = 1; i < mm; i++)
        *(a + mm - 1 + n * i) = *(a + mm - 1 + n * (i - 1)) + 1;

    for (int i = 1; i < nn; i++)
        *(a + (mm - 1) * n + nn - 1 - i) = *(a + (mm - 1) * n + nn - i) + 1;

    for (int i = 2; i < nn; i++)
        *(a + n * (mm - i)) = *(a + n * (mm - i + 1)) + 1;

    if (mm > 2 && nn > 2)
    {
        fill(a + n + 1, m, n, *(a + n) + 1, mm - 2, nn - 2);
    }
    return;
}

void getPosition(int *a, int m, int n, int x)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (*(a + n * i + j) == x)
            {
                printf("i=%d,j=%d\n", i, j);
                return;
            }
        }
    }
    printf("no %d", x);
}

int main()
{
    long a[10];
    long b[10][100];

    printf("%x\n", (a + 2) - a);
    printf("%d\n", (b + 3) - b);

    short c[100] = {0x0f0f};
    short *x = c + 1000;
    printf("%p\n", x);
    printf("%hd\n", *x);

    int m = 6, n = 6;
    int d[m][n];
    fill(&d[0][0], m, n, 0, m, n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", d[i][j]);
        }
        printf("\n");
    }
    getPosition(&d[0][0], m, n, 4);
}