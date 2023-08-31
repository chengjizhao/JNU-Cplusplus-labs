#include <stdio.h>

int *func()
{
    int n = 1;
    return &n;   
}

int main()
{
    int *p = func() ;
    int n = *p; //指针所指向的内容已被系统回收，解决方法：在int n前面加上static
    printf("%d",n);
    return 0;
}

