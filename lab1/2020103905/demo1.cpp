#include<stdio.h>
int main()
{
    int *p=NULL; //定义空指针
    *p=5; //访问空指针导致提示segmentation fault
    return 0;
}