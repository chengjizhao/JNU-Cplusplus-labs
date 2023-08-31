#include <stdio.h>

int main()//给未指定位置的空间赋值，解决方法：int *p = 0x23,给p创建一块空间存储数据
{
    int *p ;
    *p = 12;
    return 0;
   
}
