#include <stdio.h>
void main()
{
 int *ptr;
*ptr=10;
}
//使用未经初始化的指针，使程序引用无效或未分配的内存，从而引发segmentation fault。