#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char *ptr="data";
    sprintf(ptr,"DATA");//在使用一些写函数内存的函数时，长度指定不正确或者这些函数并不能指定函数长度
    return 0;
}//访问只读内存地址，产生了读写越界