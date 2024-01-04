#include<iostream>//使用dan
using namespace std;

class base
{
	public:
        static base&getInstence(){
            static base instence;
            return instence;
        }
		int a;
		void funca()
		{
			cout<<"funca is running"<<endl;
		}
		virtual void funcb()
		{
			cout<<"virtual funcb is running"<<endl;
		}
        private:
        base(){}
        ~base(){}
        base(const base&)= delete;
        base& operator = (const base&) = delete;
};

typedef void(base::*pointer)(void);

int main()
{
    base& text = base::getInstence();

	intptr_t* pclass = (intptr_t*)(&text);
	intptr_t* pvtable = (intptr_t*)(*pclass);
	intptr_t vfuncb = *pvtable;
	
	int* pparam1 = &text.a;

	pointer pfunc1 = &base::funca;

	
	cout <<"class addr :" <<pclass <<endl;
	cout <<"vtable addr :"<<pvtable<<endl;
	cout <<"vfuncb addr :"<<(void*)vfuncb<<endl;
	cout <<"base param addr :"<<pparam1<<endl;
	cout <<"base normal func addr :"<<(void*)pfunc1<<endl;

	
	return 0;
}