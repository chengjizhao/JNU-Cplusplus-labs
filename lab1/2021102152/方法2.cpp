#include <stdio.h>
#include <stdlib.h>
int main()
{
     int *x=NULL; //定义空指针
    *x=1; //访问空指针产生segmentation fault
    return 0;
}
//修改：int *x=NULL改为int *x,i=1;*x=1改为x=&i；即定义指针变量x,整型变量i，x指向i；