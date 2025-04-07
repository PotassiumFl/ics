#include <stdio.h>

char array_store(unsigned int index, char val)
{
    char a[10];
    char b = a[index];
    a[index] = val;
    return b;
}

int main()
{
    char b[30] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for (int i = 0; i < 30; i++)
    {
        char c = array_store(i % 10, b[i]);
        printf("%c", c);
    }
}