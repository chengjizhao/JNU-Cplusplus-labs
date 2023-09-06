#include<stdio.h>
int main()
{
    int*p;
    printf("%d\n",*p);//引用空指针会汇报segmentation fault
    return 0;
}