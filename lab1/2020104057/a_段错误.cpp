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
	//��ָ��ת��Ϊ��ƥ������ͣ������Ƕ�ָ��ķǷ�����ת����Ҳ�ᷢ��segmentation fault
	
	a = &x;
	free(a);
	//segmentation fault��ʹ�õ�ָ��ָ���ַ���ͷţ�Ұָ�룩
	
	a = NULL;
	//����ָ���ַ����Ϊ�գ���ָ�룩

	strcpy(p,"hello world");
	//ʹ�����鳬���˶��巶Χ

	return 0;

}
