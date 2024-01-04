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
    test.func1(5);
    return 0;
}

