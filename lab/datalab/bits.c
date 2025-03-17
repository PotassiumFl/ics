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

int conditional(int x, int y, int z)
{
    int n = ~!!x + 1;
    int p = ~n;
    return (n | z) & p | (~n ^ y) & n;
}

int isLessOrEqual(int x, int y)
{
    return !!((x >> 31) & !(y >> 31)) | !!(~(~x + 1 + y) >> 31) & !!((x >> 31) ^ !(y >> 31));
}

int logicalNeg(int x)
{
    int y = 0;
    int z = 1;
    int n = ~!!x + 1;
    int p = ~n;
    return (n | z) & p | (~n ^ y) & n;
}

int main()
{
    int x = 0;
    int y = 1;
    int z = 2;
    int n = !!x ? y : z;
    printf("%d", n);
}