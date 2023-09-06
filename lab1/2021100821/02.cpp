#include <stdio.h>
int main()
{
    int a[9];
   printf("%d",a[10000]);//发生数组越界，超出程序的访问范围。应该将a[10000]改成数组下标正确的元素。
return 0;
}
