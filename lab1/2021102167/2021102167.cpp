#include <stdio.h>

int main()
{
	int *p=NULL;
	printf("%d\n",*p);//因为内存低地址为代码段，访问出错 
	
	return 0;
	
	
}


int main()
{
	int i=0;
	scanf("%d",i);
	printf("%d\n",i);//往内存地址0中存放一个值， 
	return 0;
	
 } 
