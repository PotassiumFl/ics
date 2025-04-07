#include <stdio.h>

int main()
{
    struct s1
    {
        char name;
        short code;
        int value;
    } s1 = {0, 10, 100};

    struct s2
    {
        short code;
        int value;
        char name;
    } s2 = {10, 100, 0};

    struct s3
    {
        int value;
        char name;
        short code;
    } s3 = {100, 0, 10};

    printf("%d,%d,%d\n", sizeof(s1), sizeof(s2), sizeof(s3));
    printf("%p,%p,%p,%p\n", &s1, &s1.name, &s1.code, &s1.value);
    printf("%p,%p,%p,%p\n", &s2, &s2.code, &s2.value, &s2.name);
    printf("%p,%p,%p,%p\n", &s3, &s3.value, &s3.name, &s3.code);
}