#include <stdio.h>

int main()
{
    int la[5];
    *(la + 1) = 2;
    printf("%d\n", *(la + 1));

    int i = 1;
    *(la + i) = 2;
    printf("%d", *(la + i));
}