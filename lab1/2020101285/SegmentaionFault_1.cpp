#include<stdio.h>
#include<stdlib.h>
int main()
{

    main(); //栈溢出导致的段错误
    /*
    当程序递归调用main函数时，每次调用都会在栈上
    分配内存空间以保存局部变量、返回地址和函数参数。
    当递归调用层数过多时，栈空间会被耗尽，导致栈溢出，
    从而引发段错误。
    */
    return 0;
}