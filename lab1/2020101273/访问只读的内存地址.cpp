%访问只读的内存地址
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
    char *ptr = "test";
    strcpy(ptr, "TEST");
}
%原因：在上面的程序当中，str是一个全局变量，一个指向只读数据hello world的指针，因为指向的数据存放在只读数据区
%使用gdb调试程序，在编译阶段加上-g参数
%gcc -g segment3.c -o segment3