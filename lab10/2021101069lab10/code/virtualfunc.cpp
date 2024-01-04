#include<iostream>

using namespace std;

class vfunc_
{
	public:
		int a;
		void normalfunc()
		{
			cout<<"normalfunc is running"<<endl;
		}
		virtual void vfunc()
		{
			cout<<"vfunc is running"<<endl;
		}
};

typedef void(vfunc_::*pointer)(void);

int main()
{
	vfunc_ text;
	int* pclass= reinterpret_cast<int*>(&text);
	int* pvtable= reinterpret_cast<int*>(*pclass);
	int* vfuncaddr= reinterpret_cast<int*>(*pvtable);
	int* pclassparam= &text.a;
	pointer pfunc1= &vfunc_::normalfunc;
	cout<<"pclassaddr :"<<pclass<<endl;
	cout<<"pvtableaddr :"<<pvtable<<endl;
	cout<<"vfuncaddr :"<<vfuncaddr<<endl;
	cout<<"pclassparamaddr :"<<pclassparam<<endl;
	cout<<"pnormalfuncaddr :"<<(void*)pfunc1<<endl;
	cout<<"class :"<<sizeof(vfunc_)<<endl;
	return 0;
}