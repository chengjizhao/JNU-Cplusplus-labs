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
    void(verify::*pr)()=&verify::out_pr;//���� "verify::out_pr" (������ ��������:13) ���ɷ���
    (func.*pr)();
    func.out_pu();
    return 0;
}