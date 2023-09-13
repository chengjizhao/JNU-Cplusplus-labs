#include <stdio.h>

int main()
{
    int arr[5];
    arr[10]=10;//这将导致段错误，因为访问了越界的数组元素
    return 0;
}