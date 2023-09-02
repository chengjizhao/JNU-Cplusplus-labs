#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *ptr=NULL;//定义了不存在的指针
    *ptr=10;
    return 0;
}//访问了不存在的内存地址，导致出现异常