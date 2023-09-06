#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char *str="fault"; //编译器认为常量字符串是只读的
    *str='a'; //向只读内存中写入数据。所以这行语句非法，从而提示segmentation fault
    return 0;

}