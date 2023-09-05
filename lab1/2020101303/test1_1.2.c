//纠正
#include <stdio.h>
char str[]="hello world";//定义一个全局的字符数组，内容为hello world
int main()
{
    printf("%s\n",str);
    str[0]='H';//该定义方式定义的字符串保存在全局数据区或栈区，可以进行更改
    printf("%s\n",str);
    return 0;
}