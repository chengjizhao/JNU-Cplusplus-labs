#include<iostream>
using namespace std;

class base
{
	public:
		int a;
		void funca()
		{
			cout<<"funca is running"<<endl;
		}
		virtual void funcb()
		{
			cout<<"virtual funcb is running"<<endl;
		}
};

class subbase :public base
{
	public:
		int b;
		void funcc()
		{
			cout<<"funcc is running"<<endl;
		}
};

typedef void(subbase::*pointer)(void);

int main()
{
	subbase text;
	intptr_t* pclass = (intptr_t*)(&text);
	intptr_t* pvtable = (intptr_t*)(*pclass);
	intptr_t vfuncb = *pvtable;
	
	int* pparam1 = &text.a;
	int* pparam2 = &text.b;
	pointer pfunc1 = &subbase::funca;
	pointer pfunc2 = &subbase::funcc;
	
	cout <<"class addr :" <<pclass <<endl;
	cout <<"vtable addr :"<<pvtable<<endl;
	cout <<"vfuncb addr :"<<(void*)vfuncb<<endl;
	cout <<"base param addr :"<<pparam1<<endl;
	cout <<"subbase param addr :"<<pparam2<<endl;
	cout <<"base normal func addr :"<<(void*)pfunc1<<endl;
	cout <<"subbase normal func addr :"<<(void*)pfunc2<<endl;
	cout <<"subbase class size :"<<sizeof(subbase)<<endl;
	
	return 0;
}