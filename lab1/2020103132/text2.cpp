#include<stdio.h>
#include<stdlib.h>
void main()
{
    int *ptr=(int *)0;
    *ptr=100;//访问系统保护的内存地址，因此产生了段错误
}

