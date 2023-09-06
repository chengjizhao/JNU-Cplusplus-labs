#include<stdio.h>
int main(int argc,char*argv[])
{int*ptr=(int*)0;
*ptr=100;
return 0;
}//访问系统保护的内存地址,即ptr被锁定就不能被修改了
//解决方法：把*ptr改为变量ptr