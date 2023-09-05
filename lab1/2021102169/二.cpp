#include<stdio.h>
int main()
{
    int a;
    scanf("%d",a);   //&a写成了a,将a改为&a即可正常运行
    printf("%d\n",a);
    return 0;
}