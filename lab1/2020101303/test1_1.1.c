//对只读数据区的内容进行写操作
#include <stdio.h>
char *str={"hello world"};//定义一个全局的字符串指针，指针的内容为hello world
int main()
{
    printf("%s\n",str);
    str[0]='H';//字符串指针指向的内容存放在只读数据区，不可进行更改
    printf("%s\n",*str);
    return 0;
}