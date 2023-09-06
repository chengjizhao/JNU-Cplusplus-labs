//在scanf里面不小心把&i写成了i,而我们刚开始初始化了i为0,这样我们是试图向内存地址0存放了一个值
#include <stdio.h>
int main(){
   int i=0;
   scanf("%d",i);
   printf("%d\n",i);
   return 0;
}
//修改：把scanf里的i改成&i