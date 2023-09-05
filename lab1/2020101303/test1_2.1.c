//把一个整数以字符串形式输出
#include <stdio.h>
int main()
{
    int a=1;
    printf("%s\n",a);//printf把一个整数以字符串形式输出时，该整数被当成地址并从其开始打印字符，如果该整数代表的地址不存在或不可访问，则会出现Segmentation fault
    return 0;
}