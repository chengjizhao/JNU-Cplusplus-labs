#include <iostream>
using namespace std;
int main()
{
	int* p;
	*p = 11; // 指针未初始化就给指针地址指向的内存赋值；改正方法：新增加一个int类型的a，例如：int a；然后把a的地址给p：p = &a;
	cout << *p << endl;
	system("pause");
	return 0;
}