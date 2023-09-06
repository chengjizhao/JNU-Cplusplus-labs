#include <stdio.h>

int main()
{
    int* ptr = NULL;
    *ptr = 10;//访问空指针，发生段错误
    return 0;
}