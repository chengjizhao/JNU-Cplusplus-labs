#include<iostream>
using namespace std;

class verify
{
    public:
    void out_pu()
    {
        cout<<"public.out_pu"<<endl;

    }
    private:
    void out_pr()
    {
        cout<<"private.out_Pr"<<endl;
    }
};
int main()
{
    verify func;
    void(verify::*pr)()=&verify::out_pr;//函数 "verify::out_pr" (已声明 所在行数:13) 不可访问
    (func.*pr)();
    func.out_pu();
    return 0;
}