#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
 char *x="test";//x是一个指针，存放在栈区，"test"是一个常量，编译器认为常量字符串是只读的
strcpy(x,"qwe");//对其进行赋值，语句非法，产生 segmentation fault
 return 0;
}
//修改：把char *x="test"改成char *str = new char[20]即x是一个指针，存放在栈区，指向堆区的一块20个字节的区域的首地址