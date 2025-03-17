#include <stdio.h>

int main()
{
    char a = 'a';
    short b = 1;
    int c = 1;
    long d = 1;
    char *pa = &a;
    short *pb = &b;
    int *pc = &c;
    long *pd = &d;
    printf("%p", pa);
    printf("%p", pb);
}