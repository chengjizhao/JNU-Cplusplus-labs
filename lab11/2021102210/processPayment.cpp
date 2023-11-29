#include <iostream>
#include <memory>

using namespace std ;

class PaymentStrategy
{
    public:
    virtual void pay(float a){cout << "never chose the way "<< endl ;}
};

class CreditCardPayment : public PaymentStrategy
{
    public:
    virtual void pay(float a)override
    {
        cout << "信用卡支付：" << a << endl ;
        price=a;
    }
    private:
    float price ;
};

class AlipayPayment : public PaymentStrategy
{
    public:
    virtual void pay(float a)override
    {
        cout << "支付宝支付：" << a << endl ;
        price=a;
    }
    private:
    float price ;
};

class  WechatPayment : public PaymentStrategy
{
    public:
    virtual void pay(float a)override
    {
        cout << "微信支付：" << a << endl ;
        price=a;
    }
    private:
    float price ;
};

class  PaymentProcessor
{
    public:
    PaymentProcessor(PaymentStrategy *paymentstrategy) :paymentStrategy(paymentstrategy){}
    void processPayment(float a)
    {
        if(paymentStrategy!=nullptr)
        {
            return paymentStrategy->pay(a);
        }
    }
    private:
    unique_ptr<PaymentStrategy> paymentStrategy {nullptr};
};

int main()
{
    PaymentProcessor paymentprocessor1(new CreditCardPayment) ;
    paymentprocessor1.processPayment(10);
    PaymentProcessor paymentprocessor2(new AlipayPayment) ;
    paymentprocessor2.processPayment(10);
    PaymentProcessor paymentprocessor3(new WechatPayment) ;
    paymentprocessor3.processPayment(10);
    PaymentProcessor paymentprocessor4(new PaymentStrategy) ;
    paymentprocessor4.processPayment(10);
}

