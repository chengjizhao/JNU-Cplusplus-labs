//方法二：超出数组边界
#include <stdio.h>  
int main()
{
	int a[5]={1,2,3,4,5};
	int over=10;
	printf("%d\n",a[over]); // 这将导致段错误，因为我们试图访问数组范围之外的索引  
	return 0;
}