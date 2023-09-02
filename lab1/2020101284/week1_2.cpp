#include <iostream>
using namespace std;
int main()
{
	int arr[9];
	for (int i = 0; i <= 9; i++) //在循环访问中数组越界；改正方法：把i <= 9 改为 i<= 8
	{
		arr[i] = i;
		cout << arr[i] << endl;
	}
	system("pause");
	return 0;
}