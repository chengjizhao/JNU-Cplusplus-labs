#include <stdio.h>
int main(){
   int i=1;
   scanf("%d",i);//把&i写成了i,而我们刚开始初始化了i为0,意味着试图向内存地址0存放一个值
   printf("%d\n",i);
   return 0;
}