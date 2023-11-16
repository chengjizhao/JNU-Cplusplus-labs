#include<iostream>
using namespace std;

class base1
{
	public:
		int a ;
		void funca()
		{
			cout<<"funca is running"<<endl;
		}
};

class base2
{
	public:
		int b;
		void funcb()
		{
			cout<<"funcb is running"<<endl;
		}
};

class subbase : public base1,public base2
{
	public:
		int c;
		void funcc()
		{
			cout<<"funcc is running"<<endl;
		}
};

typedef void(subbase::*pointer)(void);

int main()
{
	subbase text;
	int* pclass = reinterpret_cast<int*>(&text);
	int* pparam1 = &text.a;
	int* pparam2 = &text.b;
	int* pparam3 = &text.c;
	pointer pfunc1 = &subbase::funca;
	pointer pfunc2 = &subbase::funcb;
	pointer pfunc3 = &subbase::funcc;
	
	cout << "classaddr : " << pclass <<endl;
	cout << "param1 : "<<pparam1<<endl;
	cout << "param2 : "<<pparam2<<endl;
	cout << "param3 : "<<pparam3 <<endl;
	cout << "func1addr : "<<(void*)pfunc1 <<endl;
	cout << "func2addr : "<<(void*)pfunc2<<endl;
	cout << "func3addr : "<<(void*)pfunc3 <<endl;
	cout << "subbase :" <<sizeof (subbase)<<endl;
	
	return 0;
}