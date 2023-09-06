#include<stdio.h>
#include<stdlib.h>
void main()
{
    int *ptr=NULL;//*ptr为空指针
    *ptr=0;//访问不存在的内存地址，因而出现段错误
}
//解决方法：为*ptr赋值一个存在内存地址即可