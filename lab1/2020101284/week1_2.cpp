#include <iostream>
using namespace std;
int main()
{
	int arr[9];
	for (int i = 0; i <= 9; i++) //��ѭ������������Խ�磻������������i <= 9 ��Ϊ i<= 8
	{
		arr[i] = i;
		cout << arr[i] << endl;
	}
	system("pause");
	return 0;
}