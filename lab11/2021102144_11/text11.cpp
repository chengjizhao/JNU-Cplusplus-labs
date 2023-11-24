#include<iostream>
using namespace std;
class Pay
{
    public:
    virtual void pay()=0;
};
class Cardpay:public Pay
{
    public:
    virtual void pay()
    {
        cout<<"cardpay"<<endl;
    }
};
class Zpay:public Pay
{
    public:
    virtual void pay()
    {
        cout<<"zpay"<<endl;
    }
};
class Wechatpay:public Pay
{
    public:
    virtual void pay()
    {
        cout<<"wechatpay"<<endl;
    }
};
class PaymentStrategy
{
    public:
    PaymentStrategy(Pay* a):p(a){}
    void setStrategy(Pay*a)
    {
       p=a;
    }
    void showStrategy()
    {
        this->p->pay();
    }
    private:
    Pay* p;
};
int main()
{
    Cardpay cp;
    Zpay zp;
    Wechatpay wp;
    PaymentStrategy pas(&cp);
    pas.showStrategy();
    pas.setStrategy(&zp);
    pas.showStrategy();
    return 0;
}