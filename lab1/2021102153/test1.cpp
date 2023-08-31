#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
 char *s="yyc";//char *s就是定义一个指针。这个指针指向字符串常量的第一个元素。
 strcpy(s,"YYE");//YYE复制到ss中去
}//访问只读内存地址出现错误解决办法s没有空间,   应该用malloc分配空间s = malloc(3);
