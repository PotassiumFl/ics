#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void show_bits(char *p, size_t len)
{
    printf("0b");
    for (char *i = p + len - 1; i >= p; i--)
    {
        for (int j = 128; j >= 1; j /= 2)
            if ((*i) & j)
                printf("1");
            else
                printf("0");
    }
    printf("\n");
}

char *longestCommonSubstring(char *str1, char *str2)
{
    int mat[100][100] = {0};
    int len1 = strlen(str1), len2 = strlen(str2);
    int max_len = 0, max_end = 0;
    for (int i = 0; i < len1; i++)
    {
        for (int j = 0; j < len2; j++)
        {
            if (str1[i] == str2[j])
            {
                if (i == 0 || j == 0)
                {
                    mat[i][j] = 1;
                }
                else
                {
                    mat[i][j] = mat[i - 1][j - 1] + 1;
                }
                if (mat[i][j] > max_len)
                {
                    max_len = mat[i][j];
                    max_end = i;
                }
            }
        }
    }
    char *lcs_str = (char *)malloc((max_len + 1) * sizeof(char));
    strncpy(lcs_str, str1 + max_end - max_len + 1, max_len);
    lcs_str[max_len] = '\0';
    return lcs_str;
}

int main()
{
    float i1 = 0;
    // 1001101001111111011000101_2 1.001101001111111011000101*2^24
    // s=0 E=24 exp=151=0b10010111 frac=0b00110100111111101100010(1)
    // 0b01001011100110100111111101100010 0x4b9a7f62
    char *p1 = (char *)&i1;
    *p1 = *p1 | 0x62;
    p1++;
    *p1 = *p1 | 0x7f;
    p1++;
    *p1 = *p1 | 0x9a;
    p1++;
    *p1 = *p1 | 0x4b;
    printf("%f\n", i1);
    show_bits((char *)&i1, sizeof(float));

    float i2 = 0;
    // -1001101001111111011000101_2 -1.001101001111111011000101*2^24
    // s=1 E=24 exp=151=0b10010111 frac=0b00110100111111101100010(1)
    // 0b11001011100110100111111101100010 0xcb9a7f62
    char *p2 = (char *)&i2;
    *p2 = *p2 | 0x62;
    p2++;
    *p2 = *p2 | 0x7f;
    p2++;
    *p2 = *p2 | 0x9a;
    p2++;
    *p2 = *p2 | 0xcb;
    printf("%f\n", i2);
    show_bits((char *)&i2, sizeof(float));

    float i3 = -0.0625;
    // -0.0001_2 -1*2^(-4)
    // s=1 E=-4 exp=123=0b01111011 frac=0
    // 0b10111101100000000000000000000000 0xbd800000
    char *p3 = (char *)&i3;
    *p3 = *p3 | 0x00;
    p3++;
    *p3 = *p3 | 0x00;
    p3++;
    *p3 = *p3 | 0x80;
    p3++;
    *p3 = *p3 | 0xbd;
    printf("%f\n", i3);
    show_bits((char *)&i3, sizeof(float));

    float i4 = 0;
    // s=0 exp=11111111 frac=0
    // 0b01111111100000000000000000000000 0x7f800000
    char *p4 = (char *)&i4;
    *p4 = *p4 | 0x00;
    p4++;
    *p4 = *p4 | 0x00;
    p4++;
    *p4 = *p4 | 0x80;
    p4++;
    *p4 = *p4 | 0x7f;
    printf("%f\n", i4);
    show_bits((char *)&i4, sizeof(float));

    float i5 = 0;
    // s=0 exp=11111111 frac!=0
    // 0b01111111100000000000000000000000 0x7f800001
    char *p5 = (char *)&i5;
    *p5 = *p5 | 0x01;
    p5++;
    *p5 = *p5 | 0x00;
    p5++;
    *p5 = *p5 | 0x80;
    p5++;
    *p5 = *p5 | 0x7f;
    printf("%f\n", i5);
    show_bits((char *)&i5, sizeof(float));

    int ix = -10;
    float fx = (float)ix;
    int absx = (ix >= 0) ? ix : (-1 * ix);
    printf("%d\n", ix);
    show_bits((char *)&ix, sizeof(int));
    printf("%f\n", fx);
    show_bits((char *)&fx, sizeof(float));
    printf("%d\n", absx);
    show_bits((char *)&absx, sizeof(int));

    char *p6 = (char *)&absx;
    char *p7 = (char *)&fx;
    int len = sizeof(int);
    char a1[len * 8 + 1], a2[len * 8 + 1];
    int a = 0, b = 0;
    for (char *i = p6 + len - 1; i >= p6; i--)
    {
        for (int j = 128; j >= 1; j /= 2)
        {
            a1[a] = ((*i) & j) ? '1' : '0';
            a++;
        }
    }
    a1[a] = 0;
    for (char *i = p7 + len - 1; i >= p7; i--)
    {
        for (int j = 128; j >= 1; j /= 2)
        {
            a2[b] = ((*i) & j) ? '1' : '0';
            b++;
        }
    }
    a2[b] = 0;
    char *string = longestCommonSubstring(a1, a2);
    printf("最大公共子串为%s", string);

    return 0;
}