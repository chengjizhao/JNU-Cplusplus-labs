#include <iostream>
using namespace std;
class Pay
{
public:
    virtual void pay() = 0;
};

class Cardpay : public Pay
{
public:
    virtual void pay()
    {
        cout << "cardpay" << endl;
    }
};

class Zpay : public Pay
{
public:
    virtual void pay()
    {
        cout << "zpay" << endl;
    }
};
class Wechatpay : public Pay
{
public:
    virtual void pay()
    {
        cout << "wechatpay" << endl;
    }
};
class PaymentProcessor
{
public:
    void PaymentStrategy(Pay *a)
    {
        p = a;
    }
    void setStrategy(Pay *a)
    {
        p = a;
    }
    void showStrategy()
    {
        this->p->pay();
    }

private:
    Pay *p;
};
int main()
{
    Cardpay cp;
    Zpay zp;
    Wechatpay wp;
    PaymentProcessor pas;
    pas.PaymentStrategy(&wp); // 保存当前支付方式
    pas.showStrategy();
    pas.setStrategy(&zp); // 改变支付方式
    pas.showStrategy();
    return 0;
}