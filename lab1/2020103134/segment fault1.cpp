#include <stdio.h>
int main()
{
    int i=1,*j;
    *j=i;  //段错误理由：没有对指针变量j初始化（指向一个有效的内存空间）就对j赋值造成指针的误用
    return 0;
}
//修正：应该初始化指针变量j使其指向一个有效的地址