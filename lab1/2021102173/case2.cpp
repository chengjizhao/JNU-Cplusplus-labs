#include<stdio.h> 
int main() 
{ 
int a=100; 
printf("%s\n",a);//把整数当作字符串打印的时候整数被当成了地址，如果该地址不存在或不可访问，则会导致段错误 
return 0;        //打印时应按照正确的格式打印
} 