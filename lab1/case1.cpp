#include<stdio.h>
int main()
{
char test[1];
printf("%c",test[4396777]);//数组越界或者内存地址不存在导致段错误
return 0;
}