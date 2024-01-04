#include<iostream>
using namespace std;
    struct Test
    {  private:
        int func(int x)
        {
        cout<<"success"<<endl;
        cout<<x<<endl;
        return x;
        }
        public:
        void func1(int n)
        {
            func(n);
        }
    
    }
 ;   
int main()
{
    Test test;
    //定义函数指针并尝试调用私有成员函数
   int (Test::*p)(int)=&test.func; //尝试通过函数指针调用私有成员函数
    //(obj.*functionPtr)(); // 这行代码会导致编译错误，无法访问私有成员函数
    return 0;
}
