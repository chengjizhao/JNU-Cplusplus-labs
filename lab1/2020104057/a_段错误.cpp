#include <stdio.h>
#include <iostream>
#include <string>

int test()
{
	int x = 100;
	return &x;
}

int main(viod)
{
	int *a; 
	int x=1;
	char p;
	char data[] = {1,2,3,4,5,6};
	int *q;

	q=data;	
	//将指针转换为不匹配的类型，属于是对指针的非法类型转换，也会发生segmentation fault
	
	a = &x;
	free(a);
	//segmentation fault：使用的指针指针地址被释放（野指针）
	
	a = NULL;
	//或者指针地址设置为空（空指针）

	strcpy(p,"hello world");
	//使用数组超出了定义范围

	return 0;

}
