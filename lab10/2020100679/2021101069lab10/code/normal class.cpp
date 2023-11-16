#include<iostream>
using namespace std;

class Normal_class
{
	public:
		int a;
		void func()
		{
			cout<<"func is running"<<endl;
		}
};

typedef void(Normal_class::*pointer)(void);

int main()
{
	Normal_class text;
	int* pclass = reinterpret_cast<int*>(&text);
	int* pparam = &text.a;
	
	pointer pfunc = &Normal_class::func;
	
	cout<<"this is classaddr : "<<pclass<<endl;
	cout<<"this is paramaddr : "<<pparam<<endl;
	cout<<"this is funcaddr : "<<(void*)pfunc<<endl;
	cout<<sizeof(text)<<endl;
	return 0;
}