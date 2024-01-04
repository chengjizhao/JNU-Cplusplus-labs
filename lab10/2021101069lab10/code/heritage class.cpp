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
};

class subbase : public base
{
	public:
		int b;
		void funcb()
		{
			cout<<"funcb is running"<<endl;
		}
};

typedef void(subbase::*pointer2)(void);
typedef void(base::*pointer1)(void);


int main()
{
	base text1;
	subbase text2;
	int* pbaseclass = reinterpret_cast<int*>(&text1);
	int* psubbaseclass = reinterpret_cast<int*>(&text2);
	int* pbaseparam = &text1.a;
	int* psubparam = &text2.b;
	pointer1 pfunca = &base::funca;
	pointer2 pfuncb = &subbase::funcb;
	
	cout<<"baseclassaddr :"<<pbaseclass<<endl;
	cout<<"subbaseclass :"<<psubbaseclass<<endl;
	cout<<"baseparam :"<<pbaseparam<<endl;
	cout<<"subparam :"<<psubparam<<endl;
	cout<<"funaaddr :"<<(void*)pfunca<<endl;
	cout<<"funcbaddr :"<<(void*)pfuncb<<endl;
	cout<<"base :" <<sizeof(base)<<endl;
	cout<<"subbase :"<<sizeof(subbase)<<endl;
	return 0;
}