
#include<stdio.h>
void main()
{
    char *p;
    p++;
    printf("%c",*p);//指针p并未初始化，为一个空指针，访问空指针地址不存在造成segmentation fault
}