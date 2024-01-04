#include <stdio.h>

int main()
{
    int* ptr = NULL;
    printf("%d\n", *ptr);
    //无法通过空指针来访问内存，这样会导致段错误 
    return 0;
}