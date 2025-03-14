#include <stdio.h>

int bitXor(int x, int y)
{
    return ~(~x & ~y) & (~(x & y));
}

int tmin()
{
    int x = 1;
    return x << 31;
}

int isTmax(int x)
{
    return ~x >> 31 & !(~(x << 1 | 1));
}

int allOddBits(int x)
{
    int y = ~x;
    return !((y & 0b1010101) & (y >> 8 & 0b1010101) & (y >> 16 & 0b1010101) & (y >> 24 & 0b1010101));
}

int negate(int x)
{
    return ~x + 1;
}

int isAsciDigit(int x)
{
    return x >> 5 & x >> 4 & (x >> 3 & (!(x & 0b110)) | (~x >> 3));
}

int main()
{
    int x = 0;
    int y = 1;
    int z = 2;
    int n = !!x ? y : z;
    printf("%d", n);
}