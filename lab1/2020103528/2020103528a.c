#include<stdio.h>
int main(void)
{
    *ptr=NULL;//该指针为空指针，向空指针幅值造成了该指针指向错位的位置，只需赋予指针变量*ptr正确的值使其指向真实确切的地址，就可以纠正该段错误
    *ptr=0;
}