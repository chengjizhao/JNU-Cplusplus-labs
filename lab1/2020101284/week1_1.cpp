#include <iostream>
using namespace std;
int main()
{
	int* p;
	*p = 11; // ָ��δ��ʼ���͸�ָ���ַָ����ڴ渳ֵ������������������һ��int���͵�a�����磺int a��Ȼ���a�ĵ�ַ��p��p = &a;
	cout << *p << endl;
	system("pause");
	return 0;
}