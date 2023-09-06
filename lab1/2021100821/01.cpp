#include<stdio.h>
char*str="hello world";
int main()
{
    printf("%s\n",str);
    *str='1';//str是一个全局变量，是一个只指向只读数据 hello wrold 的指针，无法对它进行写操作。
    return 0;
}
