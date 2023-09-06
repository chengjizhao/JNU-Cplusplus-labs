#include <stdio.h>
void main()
{
 int *ptr=(int*)0x4000;
 *ptr=0;
}
//访问无法被操作系统访问的内存，这可能导致程序意外崩溃，产生segmentation fault