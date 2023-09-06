#include <iostream>

int main()
{
	int i,a[10] = {0};
	for (i=0; i<=10; i++)
	{
	   a[i] = i;
	}
	//给数组赋值操作越过了内存的边界；解决方法：把i<=10改成i<10 
	return 0; 
}
