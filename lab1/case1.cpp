#include<stdio.h>
int main()
{
char test[1];
printf("%c",test[4396777]);//数组越界或者内存地址不存在导致段错误
return 0;                   //应检查数组下标表达式的取值是否在合法范围内
}