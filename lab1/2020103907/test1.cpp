#include <stdio.h>
int main()
{
    int *x=NULL;
    *x=1;//解引用空指针，本质上是解引用访问的页面没有分配或者没有权限访问
    return 0;
}
