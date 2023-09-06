#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char* ptr = "test";
    strcpy(ptr, "TEST");//访问只读的内存地址
    /*
   ptr是一个指向字符数组的指针，它被初始化为字符串"test"的地址。
   当我们尝试使用strcpy函数将"TEST"复制到ptr指向的内存时，由于
   该内存区域是只读的，程序会触发段错误。在C语言中，字符串常量
   （如"test"）通常存储在只读内存区域，这是为了确保它们不会被
   意外修改。
   */
    return 0;
}