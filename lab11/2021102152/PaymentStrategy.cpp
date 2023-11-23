#include<iostream>
#include<string>
using namespace std;
class PaymentStrategy
{
    public:
    virtual void pay(float amount) = 0;
};
//信用卡支付
class CreditCardPayment : public PaymentStrategy
{
    public:
    void pay(float amount) 
    {
        cout << "Pay with CreditCard: " << amount << endl;
    }
};
//支付宝支付
class AlipayPayment : public PaymentStrategy
{
    public:
    void pay(float amount)  
    {
        cout << "Paid by Alipay: " << amount << endl;
    }
};
//微信支付
class WechatPayment: public PaymentStrategy
{
    public:
    void pay(float amount) 
    {
        cout << "Paid by Wechat: " << amount << endl;
    }
};
class PaymentProcessor
{

    public:
    PaymentProcessor(PaymentStrategy* payment_StrategyType):
    payment_Strategy(payment_StrategyType){}

    void processPayment(float amount)
    {
        payment_Strategy->pay(amount);
    }

    void changePayment(PaymentStrategy* payment_StrategyType)
    {
        payment_Strategy = payment_StrategyType;
        cout << "PaymentStrategy changed " << endl;
    }
    private:
    PaymentStrategy* payment_Strategy;
};
int main()
{
    PaymentStrategy* x  = new CreditCardPayment;
    PaymentStrategy* y  = new AlipayPayment;
    PaymentStrategy* z  = new WechatPayment;
    PaymentProcessor processor(x);
    
    processor.processPayment(1);
    processor.changePayment(y);
    processor.processPayment(2);
    processor.changePayment(z);
    processor.processPayment(3);
    delete x;
    return 0;
}