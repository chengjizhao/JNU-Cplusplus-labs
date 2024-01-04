#include <stdlib.h>
#include <iostream>

using namespace std;

class Father
{
	virtual void FatherFun1() {cout << "FatherFun1" <<endl;}
	virtual void FatherFun2() {cout << "FatherFun2" <<endl;}
	virtual void FatherFun3() {cout << "FatherFun3" <<endl;}
};

class Son : public Father
{
	virtual void SonFun1() {cout << "SonFun1" <<endl;}
	virtual void SonFun2() {cout << "SonFun2" <<endl;}
	virtual void FatherFun3() {cout << "SonFun3" <<endl;}
};

typedef void (*Fun)(void);

int main()
{
	Father father;
	cout << "类对象地址：" << &father << endl;
	cout << "虚函数表地址: " << (int*)*(int*)&father << endl;
	cout << "虚函数FatherFun1地址:" <<(int*)*(int*)&father << endl;
	cout << "虚函数FatherFun2地址:" <<(int*)*(int*)&father + 1 << endl;
	cout << "虚函数FatherFun3地址:" <<(int*)*(int*)&father + 2 << endl;
	//cout << "虚函数sonFun1地址：" <<(int*)*(int*)&father + 3 << endl;
	//cout << "虚函数sonFun2地址：" <<(int*)*(int*)&father + 4 << endl;
	//cout << "虚函数sonFun3地址：" <<(int*)*(int*)&father + 5 << endl;
	Fun fun = (Fun)*(int*)*(int*)&father;
	fun();
	fun = (Fun)*((int*)*(int*)(&father) + 1);
	fun();
	fun = (Fun)*((int*)*(int*)(&father) + 2);
	fun();
	//fun = (Fun)*((int*)*(int*)(&father) + 3);
	//fun();
	//fun = (Fun)*((int*)*(int*)(&father) + 4);
	//fun();
	//fun = (Fun)*((int*)*(int*)(&father) + 5);
	//fun();

	cout << "----------------测试子类------------------" << endl;

	Son son;
	cout << "类对象地址：" << &son << endl;
	cout << "虚函数表地址: " << (int*)*(int*)&son << endl;
	cout << "虚函数继承FatherFun1地址:" <<(int*)*(int*)&son << endl;
	cout << "虚函数继承FatherFun2地址:" <<(int*)*(int*)&son + 1 << endl;
	cout << "虚函数继承FatherFun3地址:" <<(int*)*(int*)&son + 2 << endl;
	cout << "虚函数sonFun1地址:" <<(int*)*(int*)&son + 3 << endl;
	cout << "虚函数sonFun2地址:" <<(int*)*(int*)&son + 4 << endl;
	fun = (Fun)*(int*)*(int*)&son;
	fun();
	fun = (Fun)*((int*)*(int*)(&son) + 1);
	fun();
	fun = (Fun)*((int*)*(int*)(&son) + 2);
	fun();
	fun = (Fun)*((int*)*(int*)(&son) + 3);
	fun();
	fun = (Fun)*((int*)*(int*)(&son) + 4);
	fun();


	system("pause");
}
