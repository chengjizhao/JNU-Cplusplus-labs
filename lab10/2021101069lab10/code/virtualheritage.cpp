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

class subbase : public base
{
	public:
		int b;
		void funcc()
		{
			cout<<"funcc is running"<<endl;
		}
		virtual void funcd()
		{
			cout<<"virtual funcd is running"<<endl;
		}
};

typedef void(base::*pointer1)(void);
typedef void(subbase::*pointer2)(void);

int main()
{
	subbase text;
	
	intptr_t* pclass = (intptr_t*)(&text);
	intptr_t* pvtable = (intptr_t*)(*pclass);
	intptr_t pvfunc1 = *pvtable;
	intptr_t pvfunc2 = *(pvtable+1);
	
	int* pparam1 = &text.a;
	int* pparam2 = &text.b;
	
	pointer2 pfunc1 = &subbase::funca;
	pointer2 pfunc2 = &subbase::funcc;
	
	cout << " pclassaddr : "<<pclass <<endl;
	cout << " pvtableaddr : "<< pvtable << endl;
	cout << "pvfunc1addr : "<<(void*)pvfunc1<<endl;
	cout << "pvfunc2addr : "<<(void*)pvfunc2<<endl;
	cout << "ppara1addr : "<<pparam1 <<endl;
	cout << "pparam2addr : "<<pparam2 <<endl;
	cout << "pbasefunc : "<< (void*)pfunc1 <<endl;
	cout << "psubbasefunc "<<(void*)pfunc2 <<endl;
	cout << "subbase : "<< sizeof (subbase)<<endl;
	
	
	text.funca();
	text.funcb();
	text.funcc();
	text.funcd();
	
	return 0;
}