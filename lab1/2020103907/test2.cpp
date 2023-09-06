#include <stdio.h>
char*str="hello";
int main()
{
    printf ("%s\n",str);
    *str='1';//读写没有权限的位置：写只读数据str是一个全局变量，一个指向只读数据hello的指针，因为指向数据存放在只读数据区
    return 0;
}