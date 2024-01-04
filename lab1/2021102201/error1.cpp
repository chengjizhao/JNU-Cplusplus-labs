#include <stdio.h>

int main()
{
    int a[3] = {1, 2, 3};
    for (int i = 0; i < 3; i++)
   {
        printf("%d\n", a[i]);
    }
   //数组a只包含3个整数，如果for循环中i=3，则会超出数组范围，导致段错误
    return 0;
}