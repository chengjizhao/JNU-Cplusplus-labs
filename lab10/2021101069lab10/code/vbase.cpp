#include<iostream>
using namespace std;

class base
{
	public:
		int a ;
};

class grandbase1 : virtual public base
{
	public:
		int b;
};

class grandbase2 : virtual public base
{
	public :
		int c;
};

class subbase : public grandbase1,public grandbase2
{
	public :
		int d; 
};

typedef void (subbase::*pointer)(void);

int main()
{
	subbase text;
	int* pclass = reinterpret_cast<int*>(&text);
	int* pparam1 =&text.grandbase1::a;
	int* pparam2 = &text.grandbase2::a;
	int* pparam3= &text.subbase::d;
	
	cout<<"classaddr :"<<pclass<<endl;
	cout<<"grand base1 addr : "<<pparam1<<endl;
	cout<<"grand base2 addr : "<<pparam2<<endl;
	cout << "subbase addr :"<<pparam3 <<endl;
	
	cout<<"size :"<<sizeof(subbase)<<endl;
	
	return 0;
}